
%{
#include "zcode.h"
#include "lex.yy.cpp"

/// enable debug
#define YYDEBUG 1

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

enum ValueType {
    Variant,
    Constant
};

Z_USE_NAMESPACE

%}

/// enable debug
%debug
/// enable locations
%locations
/// 开启后，当调用yyerror时,它请求详细的错误消息字符串
%error-verbose

%union{
    int valueType;
    quint16 count;
    QByteArray *identifier;
    ZSharedVariantPointer *value;
    QVarLengthArray<QByteArray*, 10> *parameterList;
    QPair<ZSharedVariantPointer*, quint16> *caseKey;
    QVector<QPair<ZSharedVariantPointer*, quint16>> *cases;
    std::string *msg;
};

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE FOR UNDEFINED GOTO RETURN BREAK CONTINUE SWITCH CASE
%token <count> DEFAULT

/// identifier
%token <identifier> IDENTIFIER INT STRING BOOL DOUBLE

///     ==  ===    !=  !==  <= >=  &&   ||   ++      --    << >>
%token  EQ  STEQ  NEQ STNEQ LE GE LAND LOR ADDSELF SUBSELF LL GG
///         /=        *=        +=       -=         %=        &=       |=       ^=        ||=        &&=
%token  DIVASSIGN MULASSIGN ADDASSIGN SUBASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN LANDASSIGN LORASSIGN

%token <msg> ERROR

%left ';'
%left VAR IF
%left ','
%right '=' DIVASSIGN MULASSIGN ADDASSIGN SUBASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN LANDASSIGN LORASSIGN
%left COMMA
%left '.'
%right '?' ':'
%left LAND LOR
%left '&' '|' '^'
%left EQ NEQ STEQ STNEQ
%left '>' '<' GE LE LTGT
%left '-' '+'
%left '*' '/' '%'
%left UMINUS ADDSELF SUBSELF '!' '~'
//%left PROMOTION
%left '[' ']'
%left '(' ')'

%type <valueType> expression lvalue rvalue
%type <count> arguments tuple_exp tuple_lval break loopEnds
%type <value> branch_head branch_body branch_else const switch_head
%type <parameterList> parameter
%type <cases> cases
%type <caseKey> case

%%

start:      | start code
            | ERROR {
                  error(@1, *$1);
                  delete $1;
                  YYABORT;
            }
            ;

code:       GOTO IDENTIFIER ends {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*$2));

                delete $2;
            }
            | conditional
            | goto_label
            | expression ends {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
            | return ends {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
            | tuple_lval {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number($1), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
            '=' expression ends {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);

                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
            | loopEnds ends {
                /// 判断是否是以break结尾
                bool isBreak = !($1 & 0x8000);

                ZCodeExecuter::CodeBlock::Type type = ZCodeExecuter::CodeBlock::LoopStructure;

                if(isBreak)
                    type = ZCodeExecuter::CodeBlock::Type(type | ZCodeExecuter::CodeBlock::Switch);

                ZCodeExecuter::CodeBlock *block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(type, ZCodeExecuter::currentCodeExecuter->getCodeBlock());

                quint16 tmp = ($1 & 0x7fff);

                while(--tmp) {
                    if(!block_while) {
                        zError << "\"" + QString(isBreak ? "break" : "continue") + "\" Cannot be used here";
                        break;
                        YYABORT;
                    }

                    block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(type, block_while->parent);
                }

                if(!block_while) {
                    zError << "\"" + QString(isBreak ? "break" : "continue") + "\" Cannot be used here";
                    YYABORT;
                }

                if(isBreak) {
                    if(block_while->isLoopStructure()) {
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toLoopStructureCodeBlock()->breakIndex);
                    } else {
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toSwitchCodeBlock()->breakIndex);
                    }
                } else {
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toLoopStructureCodeBlock()->continueIndex);
                }

            }
            | switch {}
            | ';'
            | '{' start '}'
            ;

ends:       ';';

break:      BREAK {$$ = 1;}
            | break ',' BREAK {$$ = $1 + 1;}
            ;

/// 循环结构的结束语句, $$的二进制首位为1代表是continue结尾的语句，否则代码break结尾的语句
loopEnds:   CONTINUE {$$ = 0x8001;}
            | break ',' CONTINUE {$$ = (0x8000 | ($1 + 1));}
            | break {$$ = $1;}
            ;

switch_head:SWITCH '(' expression ')' {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Switch, ZSharedVariantPointer(new ZSharedVariant()));
                $$ = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::Switch);
            }
            ;

switch:     switch_head '{' cases '}' {
                *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toSwitchCodeBlock()->breakIndex.data() = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                QHash<ZVariant, int> hashSwitch;

                hashSwitch.reserve($3->size());

                bool existDefault = false;

                for(const QPair<ZSharedVariantPointer*, quint16> &c : *$3) {
                    if(c.first) {
                        hashSwitch[*c.first->constData()] = c.second;
                    } else {
                        hashSwitch[ZVariant()] = c.second;
                        existDefault = true;
                    }
                }

                if(!existDefault)
                    hashSwitch[ZVariant()] = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                *$1->data() = QVariant::fromValue(hashSwitch);

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
            ;

case:       CASE const ':' {
                $$ = new QPair<ZSharedVariantPointer*, quint16>($2, ZCodeExecuter::currentCodeExecuter->getCodeList().count());
            }
            ;

cases:      case code {
                $$ = new QVector<QPair<ZSharedVariantPointer*, quint16>>();
                $$->append(*$1);

                delete $1;
            }
            | cases DEFAULT ':' {
                /// 储存code的开始index
                $2 = ZCodeExecuter::currentCodeExecuter->getCodeList().count();
            } code {
                $$ = $1;
                $$->append(QPair<ZSharedVariantPointer*, quint16>(Q_NULLPTR, $2));
            }
            | cases case code {
                $$ = $1;
                $$->append(*$2);

                delete $2;
            }
            ;

goto_label: IDENTIFIER ':' {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*$1) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete $1;
            }
            ;

//statement:  VAR define {

//            }
//            | FUNCTION IDENTIFIER '(' define ')' '{' code '}' {
//                /// TODO
//            }
//            ;

function:   '(' parameter ')' {
                ZCodeExecuter::beginCodeExecuter()->beginCodeBlock();

                if($2) {
                    for(QByteArray *id : *$2) {
                        ZCodeExecuter::currentCodeExecuter->getParameterList() << ZCodeExecuter::currentCodeExecuter->addIdentifier(*id);
                        delete id;
                    }

                    delete $2;
                }
            } '{' start '}'  {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
            ;

return:     RETURN {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
            | RETURN expression
            | RETURN tuple_exp {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number($2), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
            ;

parameter:  {$$ = Q_NULLPTR;}
            | IDENTIFIER {
                $$ = new QVarLengthArray<QByteArray*, 10>();
                $$->append($1);
            }
            | parameter ',' IDENTIFIER {
                $$ = $1;
                $$->append($3);
            }
            ;

define:     IDENTIFIER {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*$1);
                delete $1;
            }
            | IDENTIFIER '=' expression {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*$1);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*$1));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete $1;
            }
            | define ',' define
            ;

tuple_lval: lvalue ',' lvalue %prec COMMA {$$ = 2;}
            | tuple_lval ',' lvalue {$$ = $1 + 1;}
            ;

tuple_exp:  expression ',' expression %prec COMMA {$$ = 2;}
            | tuple_exp ',' expression {$$ = $1 + 1;}
            ;

expression: lvalue | rvalue;

lvalue:     VAR define {
                $$ = ValueType::Variant;
            }
            | IDENTIFIER {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*$1));

                delete $1;
            }
            | '_' {
                $$ = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
            | lvalue '=' expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
            | expression '[' expression ']' {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Children);
            }
            | expression '.' IDENTIFIER {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*$3, ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
            | lvalue ADDASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
            | lvalue SUBASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
            | lvalue MULASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
            | lvalue DIVASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
            | lvalue ANDASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
            | lvalue ORASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
            | lvalue XORASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
            | lvalue MODASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
            | lvalue LORASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
            | lvalue LANDASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
            | ADDSELF lvalue {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
            | SUBSELF lvalue {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
            ;

const:      UNDEFINED {
                $$ = new ZSharedVariantPointer(ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
            | INT {
                $$ = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*$1, ZVariant::Int));

                delete $1;
            }
            | STRING {
                $$ = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*$1, ZVariant::String));

                delete $1;
            }
            | DOUBLE {
                $$ = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*$1, ZVariant::Double));

                delete $1;
            }
            | BOOL {
                $$ = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*$1, ZVariant::Bool));

                delete $1;
            }

rvalue:     const {
                $$ = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, *$1);

                delete $1;
            }
            | '[' tuple_exp ']' {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number($2), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
            | '[' expression ']' {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("1", ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
            | NEW IDENTIFIER {
                /// TODO
                $$ = ValueType::Constant;
            }
            | expression '(' arguments ')' {
                    $$ = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number($3), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
            | expression '+' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value + *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Add);
                    }
            }
            | expression '-' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value - *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Sub);
                    }
            }
            | expression '*' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value * *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mul);
                    }
            }
            | expression '/' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value / *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Div);
                    }
            }
            | expression '&' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value & *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::And);
                    }
            }
            | expression '|' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value | *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Or);
                    }
            }
            | expression '^' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value ^ *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Xor);
                    }
            }
            | expression '%' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value % *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mod);
                    }
            }
            | expression '>' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value > *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Greater);
                    }
            }
            | expression '<' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value < *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Less);
                    }
            }
            | expression EQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value == *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::EQ);
                    }
            }
            | expression NEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value != *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::NEQ);
                    }
            }
            | expression STEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(last_code->value->type() == pre_code->value->type()
                                                                     && *last_code->value == *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STEQ);
                    }
            }
            | expression STNEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(last_code->value->type() == pre_code->value->type()
                                                                     && *last_code->value != *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STNEQ);
                    }
            }
            | expression LE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value <= *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LE);
                    }
            }
            | expression GE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value >= *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::GE);
                    }
            }
            | expression LAND expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value && *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAnd);
                    }
            }
            | expression LOR expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value || *pre_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOr);
                    }
            }
            | '~' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(~ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Contrary);
                    }
                }
            | '!' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(! *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Not);
                    }
                }
            | '-' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(- *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Minus);
                    }
                }
            | '+' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(+ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Abs);
                    }
                }
            | lvalue ADDSELF {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
            | lvalue SUBSELF {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
            | lvalue LL expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Append);
            }
            | function {
                $$ = ValueType::Variant;
            }
            | '(' expression ')' { $$ = $2;}
            ;

arguments:  {$$ = 0;}
            | expression {$$ = 1;}
            | tuple_exp
            ;

branch_head:IF '(' expression ')' {
                $$ = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                $$ = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
            | WHILE {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            } '(' expression ')' {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                $$ = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
            | FOR '(' for_exp ends {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            } expression ends {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if指令在codeList中的index，方便修改if指令为假时要跳转到的指令位置
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;

                /// 开启使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(true);
            } for_exp ')' {
                /// 关闭使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(false);

                int ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex;

                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                $$ = &ZCodeExecuter::currentCodeExecuter->getCodeList().value(ifInstructionIndex)->toValueCode()->value;
            }
//            | FOR '(' lvalue ':' expression ')' {
//                $$ = Q_NULLPTR;

//                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
//            }
            ;

for_exp:    | expression;

branch_body :branch_head code {
                if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->isLoopStructure()) {
                    QList<ZCode*> &codeList = ZCodeExecuter::currentCodeExecuter->getCodeList();

                    /// 如果是普通的for循环结构
                    if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::NormalFor) {
                        QList<ZCode*> &tmpCodeList = ZCodeExecuter::currentCodeExecuter->getTmpCodeList();

                        /// 记录在for循环中执行continue语句时要跳转到的目标位置
                        *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->continueIndex.data() = codeList.count();

                        /// 将for循环的第三个表达式的指令从临时列表添加到codeList
                        while(!tmpCodeList.isEmpty()) {
                            codeList << tmpCodeList.takeAt(0);
                        }

                        /// 清空栈
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
                    }

                    int index = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->beginCodeIndex;

                    /// 产生循环
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstant(QByteArray::number(index), ZVariant::Int));

                    /// 保存执行break语句时跳转到的位置
                    *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->breakIndex.data() = codeList.count();
                }

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// index为if判断结果为假时要跳转到的位置
                *$1 = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
                $$ = $1;

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
            ;

branch_else:branch_body ELSE;

conditional:branch_body
            | branch_else {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *$1 = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                $1 = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            } code {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *$1 = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
%%

int yyFlexLexer::yywrap()
{
    return 1;
}

#undef yyFlexLexer

void yy::parser::error(const location_type& loc, const std::string& msg)
{
    char lineStr[1000];

    ZCodeExecuter::yyFlexLexer->yyin.seekg(-(int)loc.end.column - 1, std::ios::cur);
    ZCodeExecuter::yyFlexLexer->yyin.getline(lineStr, 1000);

    std::cerr << lineStr << std::endl;

    for (uint i = 0; i < loc.begin.column; ++i)
        std::cerr << " ";

    for (uint i = loc.begin.column; i < loc.end.column ; ++i)
        std::cerr << "^";

    std::cerr << std::endl;
    std::cerr << "from " << loc.begin.line << " line " << loc.begin.column << " column, "
              << "to " << loc.end.line << " line " << loc.end.column << " column, " << msg << std::endl;

    quick_exit(-1);
}

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return ZCodeExecuter::yyFlexLexer->yylex();
}
