
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

/// if current code block belong be which is true else is false.
int forCycieBeginCodeIndex = 0;

Z_USE_NAMESPACE

%}

/// enable debug
%debug
/// enable locations
%locations

%union{
    int valueType;
    int count;
    QByteArray *identifier;
    ZSharedVariantPointer *value;
};

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE FOR UNDEFINED GOTO

/// identifier
%token <identifier> IDENTIFIER INT STRING BOOL DOUBLE

///     ==  ===    !=  !==  <= >=  &&   ||   ++      --
%token  EQ  STEQ  NEQ STNEQ LE GE LAND LOR ADDSELF SUBSELF
///         /=        *=        +=       -=         %=        &=       |=       ^=        ||=        &&=
%token  DIVASSIGN MULASSIGN ADDASSIGN SUBASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN LANDASSIGN LORASSIGN

%left ';'
%left VAR IF
%left ','
%right '=' DIVASSIGN MULASSIGN ADDASSIGN SUBASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN LANDASSIGN LORASSIGN
%left COMMA
%left '.'
//%right '?' ':'
%left LAND LOR
%left '&' '|' '^'
%left EQ NEQ
%left '>' '<' GE LE
%left '-' '+'
%left '*' '/' '%'
%left UMINUS ADDSELF SUBSELF '!' '~'
%left PROMOTION
%left '(' ')'
%left ':'

%type <valueType> expression lvalue rvalue
%type <count> arguments tuple_exp tuple_lval
%type <value> branch_head branch_body branch_else

%%

start:      | start code | start '\n'

code:       GOTO IDENTIFIER ends {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*$2));

                delete $2;
            }
            | conditional {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
            | goto_label {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
            | expression ends {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
            | ';'
            | '{' start '}'
            ;

ends:       ';'|'\n'

goto_label: IDENTIFIER ':' {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*$1) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete $1;
            }

//statement:  VAR define {

//            }
//            | FUNCTION IDENTIFIER '(' define ')' '{' code '}' {
//                /// TODO
//            }
//            ;

function:   FUNCTION '(' {
                ZCodeExecuter::beginCodeExecuter()->beginCodeBlock();
            } parameter ')' '{' start '}' %prec PROMOTION {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
            ;

parameter:  |define

define:     IDENTIFIER {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*$1);

                delete $1;
            }
            | IDENTIFIER '=' expression {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*$1);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifierAddress(*$1));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete $1;
            }
            | define ',' define
            ;

tuple_lval: lvalue ',' lvalue %prec COMMA {$$ = 2;}
            | tuple_lval ',' lvalue %prec COMMA {
                $$ = $1 + 1;
            }
            ;

tuple_exp:  expression ',' expression {$$ = 2;}
            | tuple_lval ',' expression {$$ = $1 + 1;}
            | tuple_exp ',' expression {
                $$ = $1 + 1;
            }

expression: lvalue | rvalue %prec PROMOTION;

lvalue:     VAR define {
                $$ = ValueType::Variant;
            }
            | IDENTIFIER {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifierAddress(*$1));

                delete $1;
            }
            | lvalue '=' expression {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
            | expression '[' expression ']' {
                $$ = ValueType::Variant;
                /// TODO
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
            | tuple_lval {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number($1), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Join);
            }
            ;

rvalue:     UNDEFINED {
                $$ = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray(), ZVariant::Null));
            }
            | INT {
                $$ = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*$1, ZVariant::Int));

                delete $1;
            }
            | STRING {
                $$ = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*$1, ZVariant::String));

                delete $1;
            }
            | DOUBLE {
                $$ = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*$1, ZVariant::Double));

                delete $1;
            }
            | BOOL {
                $$ = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*$1, ZVariant::Bool));

                delete $1;
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

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Add);
                    }
            }
            | expression '-' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Sub);
                    }
            }
            | expression '*' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mul);
                    }
            }
            | expression '/' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Div);
                    }
            }
            | expression '&' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::And);
                    }
            }
            | expression '|' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Or);
                    }
            }
            | expression '^' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Xor);
                    }
            }
            | expression '%' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mod);
                    }
            }
            | expression '>' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value > *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Greater);
                    }
            }
            | expression '<' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value < *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Less);
                    }
            }
            | expression EQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::EQ);
                    }
            }
            | expression NEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::NEQ);
                    }
            }
            | expression STEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STEQ);
                    }
            }
            | expression STNEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STNEQ);
                    }
            }
            | expression LE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LE);
                    }
            }
            | expression GE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::GE);
                    }
            }
            | expression LAND expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAnd);
                    }
            }
            | expression LOR expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOr);
                    }
            }
            | '~' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(~ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Contrary);
                    }
                }
            | '!' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(! *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Not);
                    }
                }
            | '-' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(- *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Minus);
                    }
                }
            | '+' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(+ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Abs);
                    }
                }
            | '(' expression ')' { $$ = $2;}
            | lvalue ADDSELF {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
            | lvalue SUBSELF {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
            | tuple_exp {
                $$ = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number($1), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Join);
            }
            | function {
                $$ = ValueType::Variant;
            }
            ;

arguments:  {$$ = 0;}
            | expression {
                $$ = 1;
            }
            ;

branch_head:IF '(' expression ')' {
                $$ = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                $$ = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last())->value;
            }
            | WHILE {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            } '(' expression ')' {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                $$ = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last())->value;
            }
            | FOR '(' expression ends {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            } expression ends {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                forCycieBeginCodeIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;
            } expression ')' {
                $$ = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().value(forCycieBeginCodeIndex))->value;
            }
            | FOR '(' lvalue ':' expression ')' {
                $$ = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
            | branch_head '\n'
            ;

branch_body :branch_head code {
                if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::While) {
                    int index = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->beginCodeIndex;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstant(QByteArray::number(index), ZVariant::Int));
                }

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                *$1 = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
                $$ = $1;

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
            | branch_body '\n'
            ;
branch_else : branch_body ELSE | branch_else '\n'

conditional:branch_body
            | branch_else {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                *$1 = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                $1 = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last())->value;
            } code {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();
                *$1 = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
%%

void yy::parser::error(const location_type& loc, const std::string& msg)
{
    std::cerr << "from " << loc.begin.line << " line, " << loc.begin.column << " column "
              << "to " << loc.end.line << " line, " << loc.end.column << " column, " << msg << std::endl;

    quick_exit(-1);
}

int yyFlexLexer::yywrap()
{
    if(!ZCodeExecuter::yywrap) {
        ZCodeExecuter::yywrap = true;

        return 0;
    }

    return 1;
}

#undef yyFlexLexer

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return ZCodeExecuter::yyFlexLexer->yylex();
}
