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

%union{
    int valueType;
    int argsCount;
    QByteArray *identifier;
};

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE FOR UNDEFINED

/// identifier
%token <identifier> IDENTIFIER INT STRING BOOL DOUBLE

///     ==  ===    !=  !==  <= >= &&   ||   ++      --
%token  EQ  STEQ  NEQ STNEQ LE GE LAND LOR ADDSELF SUBSELF
///         /=        *=        +=       -=         %=        &=       |=       ^=        ||=        &&=
%token  DIVASSIGN MULASSIGN ADDASSIGN SUBASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN LANDASSIGN LORASSIGN

%left ','
%right '=' DIVASSIGN MULASSIGN ADDASSIGN SUBASSIGN MODASSIGN ANDASSIGN ORASSIGN XORASSIGN LANDASSIGN LORASSIGN
%left '?' ':'
%left LAND LOR
%left '&' '|' '^'
%left EQ NEQ
%left '>' '<' GE LE
%left '-' '+'
%left '*' '/' '%'
%right UMINUS ADDSELF SUBSELF '!' '~'
%left '(' ')'

%type <valueType> expression lvalue rvalue
%type <argsCount> arguments

%%

start:
            | start ';' {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
            | start statement ';' {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
            | start expression ';' {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
            | start conditional {
                //currentCode->nodeList << $2;
            }
            ;

statement:  VAR define
            | FUNCTION IDENTIFIER '(' define ')' '{' start '}' {
                /// TODO
            }
            ;

define:     IDENTIFIER {
                ZCodeParse::currentCodeParse->addIdentifier(*$1);

                delete $1;
            }
            | IDENTIFIER '=' expression {
                ZCodeParse::currentCodeParse->addIdentifier(*$1);
                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*$1));
                ZCodeParse::currentCodeParse->appendCode(ZCode::RightAssign);

                delete $1;
            }
            | define ',' define
            ;

expression: lvalue | rvalue;

lvalue:     IDENTIFIER {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*$1));

                delete $1;
            }
            | lvalue '=' expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LeftAssign);
            }
            | expression '[' expression ']' {
                $$ = ValueType::Variant;
                /// TODO
            }
            | lvalue ADDASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AddAssign);
            }
            | lvalue SUBASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::SubAssign);
            }
            | lvalue MULASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::MulAssign);
            }
            | lvalue DIVASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::DivAssign);
            }
            | lvalue ANDASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AndAssign);
            }
            | lvalue ORASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::OrAssign);
            }
            | lvalue XORASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::XorAssign);
            }
            | lvalue MODASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::ModAssign);
            }
            | lvalue LORASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LOrAssign);
            }
            | lvalue LANDASSIGN expression {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LAndAssign);
            }
            | ADDSELF lvalue {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixAddSelf);
            }
            | SUBSELF lvalue {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixSubSelf);
            }
            ;

rvalue:     UNDEFINED {
                $$ = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray(), ZVariant::Null));
            }
            | INT {
                $$ = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*$1, ZVariant::Int));

                delete $1;
            }
            | STRING {
                $$ = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*$1, ZVariant::String));

                delete $1;
            }
            | DOUBLE {
                $$ = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*$1, ZVariant::Double));

                delete $1;
            }
            | BOOL {
                $$ = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*$1, ZVariant::Bool));

                delete $1;
            }
            | NEW IDENTIFIER {
                /// TODO
                $$ = ValueType::Constant;
            }
            | expression '(' arguments ')' {
                    $$ = ValueType::Variant;

                    ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number($3), ZVariant::Int));
                    ZCodeParse::currentCodeParse->appendCode(ZCode::Call);
            }
            | expression '.' IDENTIFIER {
                    $$ = ValueType::Variant;

                    ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*$3, ZVariant::String));
                    ZCodeParse::currentCodeParse->appendCode(ZCode::Get);
            }
            | expression '+' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Add);
                    }
            }
            | expression '-' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Sub);
                    }
            }
            | expression '*' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Mul);
                    }
            }
            | expression '/' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Div);
                    }
            }
            | expression '&' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::And);
                    }
            }
            | expression '|' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Or);
                    }
            }
            | expression '^' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Xor);
                    }
            }
            | expression '%' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Mod);
                    }
            }
            | expression EQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::EQ);
                    }
            }
            | expression NEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::NEQ);
                    }
            }
            | expression STEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::STEQ);
                    }
            }
            | expression STNEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::STNEQ);
                    }
            }
            | expression LE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::LE);
                    }
            }
            | expression GE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::GE);
                    }
            }
            | expression LAND expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::LAnd);
                    }
            }
            | expression LOR expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::LOr);
                    }
            }
            | '~' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(~ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Contrary);
                    }
                }
            | '!' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(! *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Not);
                    }
                }
            | '-' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(- *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Minus);
                    }
                }
            | '+' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(+ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Abs);
                    }
                }
            | '(' expression ')' { $$ = $2;}
            | lvalue ADDSELF {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixAddSelf);
            }
            | lvalue SUBSELF {
                $$ = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixSubSelf);
            }
            ;

arguments:  expression {$$ = 1;}
            | arguments ',' expression {$$ = $1 + 1;}/* {
                    if($1->nodeType == Node::Constant
                            && $3->nodeType == Node::Constant) {
                        $$ = new Node(Node::Constant);
                        QList<ZVariant> value;
                        value << *$1->value << *$3->value;
                        $$->value = new ZVariant(value);
                    } else {
                        $$ = new Node(Node::Comma, $1, $3);
                        $$->value = new ZVariant();
                    }
            }*/
            ;

branch_head:IF '(' expression ')'
            | WHILE '(' expression ')'
            | FOR '(' expression ';' expression ';' expression ')'
            | FOR '(' lvalue ':' expression ')';

conditional:branch_head '{' start '}'
            | branch_head expression ';'
            | conditional ELSE conditional
            | conditional ELSE '{' start '}'
            | conditional ELSE expression ';'
            ;

%%

void yy::parser::error(const location_type& loc, const std::string& msg)
{
    std::cerr << "from " << loc.begin.line << " line, " << loc.begin.column << " column "
              << "to " << loc.end.line << " line, " << loc.end.column << " column, " << msg << std::endl;
}

int yyFlexLexer::yywrap()
{
    if(!ZCodeParse::yywrap) {
        ZCodeParse::yywrap = true;

        return 0;
    }

    return 1;
}

#undef yyFlexLexer

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return ZCodeParse::currentCodeParse->yyFlexLexer()->yylex();
}
