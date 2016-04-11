%{
#include "global.h"

/// enable debug
#define YYDEBUG 1

#include "lex.yy.cpp"

#include <QCoreApplication>
#include <QtConcurrent/QtConcurrentRun>

#include <fstream>

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

Global::Code *currentCode = Q_NULLPTR;
Global::Code *rootCode = Q_NULLPTR;

%}

/// enable debug
%debug
/// enable locations
%locations

%union{
    Global::ZVariant *value;
    QByteArray *identifier;
    Global::Node *node;
};

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE FOR

/// data type
%token <value> CONSTANT

/// identifier
%token <identifier> IDENTIFIER

///     ==  ===    !=  !==  <= >= &&   ||   ++      --
%token  EQ  STEQ  NEQ STNEQ LE GE LAND LOR ADDSELF SUBSELF
///     /=  *=  +=  -=   %=    &=    |=   ^=
%token  DEQ MEQ AEQ SEQ MODEQ ANDEQ OREQ XOREQ

%left ','
%right '=' DEQ MEQ AEQ SEQ MODEQ ANDEQ OREQ XOREQ
%left '?' ':'
%left LAND LOR
%left '&' '|' '^'
%left EQ NEQ
%left '>' '<' GE LE
%left '-' '+'
%left '*' '/' '%'
%right UMINUS ADDSELF SUBSELF '!' '~'
%left '(' ')'

%type <node> expression lvalue rvalue arguments

%%

start:
            | start statement ';'
            | start expression ';' {
                currentCode->nodeList << $2;
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
                if(currentCode->constData()->identifiersHash.contains(*$1)) {
                    zError << *$1 << "is defined!";
                    YYERROR;
                }

                currentCode->data->identifiersHash[*$1] = new Global::ZVariant;
                delete $1;
            }
            | define ',' define
            ;

expression: lvalue | rvalue;

lvalue:     IDENTIFIER {
                $$ = new Global::Node(Global::Node::Variant);
                $$->name = *$1;
                delete $1;
            }
            | lvalue '=' expression {
                $$ = new Global::Node(Global::Node::Assign, $1, $3);

                $$->value = $1->value;
            }
            | expression '[' expression ']' {
                $$ = $1;
                /// TODO
            }
            | lvalue AEQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::Add, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | lvalue SEQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::Sub, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | lvalue MEQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::Mul, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | lvalue DEQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::Div, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | lvalue ANDEQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::And, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | lvalue OREQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::Or, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | lvalue XOREQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::Xor, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | lvalue MODEQ expression {
                Global::Node *child_node = new Global::Node(Global::Node::Mod, $1, $3);

                $$ = new Global::Node(Global::Node::Assign, $1, child_node);
                $$->value = $1->value;
            }
            | ADDSELF lvalue {
                $$ = new Global::Node(Global::Node::PrefixAddSelf, Q_NULLPTR, $2);
                $$->value = $2->value;
            }
            | SUBSELF lvalue {
                $$ = new Global::Node(Global::Node::PrefixSubSelf, Q_NULLPTR, $2);
                $$->value = $2->value;
            }
            | lvalue ADDSELF {
                $$ = new Global::Node(Global::Node::PostfixAddSelf, $1, Q_NULLPTR);
                $$->value = $1->value;
            }
            | lvalue SUBSELF {
                $$ = new Global::Node(Global::Node::PostfixSubSelf, $1, Q_NULLPTR);
                $$->value = $1->value;
            }
            ;

rvalue:     {
                $$ = new Global::Node(Global::Node::Constant);
                $$->value = new Global::ZVariant;
            }
            | CONSTANT {
                $$ = new Global::Node(Global::Node::Constant);
                $$->value = $1;
            }
            | NEW IDENTIFIER {
                /// TODO
                $$ = Q_NULLPTR;
            }
            | expression '(' arguments ')' {
                /// TODO

                Global::Node *right_node = $3;

                if($3->nodeType != Global::Node::Comma) {
                    Global::Node *left = new Global::Node(Global::Node::Constant);

                    left->value = new Global::ZVariant(QList<Global::ZVariant>());

                    right_node = new Global::Node(Global::Node::Comma, left, $3);
                    right_node->value = new Global::ZVariant();
                }
                $$ = new Global::Node(Global::Node::Call, $1, right_node);
                $$->value = new Global::ZVariant();
            }
            | expression '.' IDENTIFIER {
                Global::Node *propertyName = new Global::Node(Global::Node::Constant);

                propertyName->value = new Global::ZVariant(QString(*$3));
                $$ = new Global::Node(Global::Node::Get, $1, propertyName);
                $$->value = new Global::ZVariant();
            }
            | expression '+' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value + *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::Add, $1, $3);
                    }
            }
            | expression '-' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value - *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::Sub, $1, $3);
                    }
            }
            | expression '*' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value * *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::Mul, $1, $3);
                    }
            }
            | expression '/' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value / *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::Div, $1, $3);
                    }
            }
            | expression '&' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value & *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::And, $1, $3);
                    }
            }
            | expression '|' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value | *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::Or, $1, $3);
                    }
            }
            | expression '^' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value ^ *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::Xor, $1, $3);
                    }
            }
            | expression '%' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value % *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::Mod, $1, $3);
                    }
            }
            | expression EQ expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value == *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::EQ, $1, $3);
                    }
            }
            | expression NEQ expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value != *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::NEQ, $1, $3);
                    }
            }
            | expression LE expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value <= *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::LE, $1, $3);
                    }
            }
            | expression GE expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value >= *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::GE, $1, $3);
                    }
            }
            | expression LAND expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value && *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::LAnd, $1, $3);
                    }
            }
            | expression LOR expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = $1;
                        $$->value = new Global::ZVariant(*$1->value || *$3->value);
                        delete $3;
                    } else {
                        $$ = new Global::Node(Global::Node::LOr, $1, $3);
                    }
            }
            | '~' expression {
                    if($2->nodeType == Global::Node::Constant) {
                        $$ = $2;
                        *$$->value = ~*$2->value;
                    } else {
                        $$ = new Global::Node(Global::Node::Contrary, Q_NULLPTR, $2);
                    }
                }
            | '!' expression {
                    if($2->nodeType == Global::Node::Constant) {
                        $$ = $2;
                        *$$->value = !*$2->value;
                    } else {
                        $$ = new Global::Node(Global::Node::Not, Q_NULLPTR, $2);
                    }
                }
            | '-' expression %prec UMINUS {
                    if($2->nodeType == Global::Node::Constant) {
                        $$ = $2;
                        *$$->value = -*$2->value;
                    } else {
                        $$ = new Global::Node(Global::Node::Minus, Q_NULLPTR, $2);
                    }
                }
            | '+' expression %prec UMINUS {
                    if($2->nodeType == Global::Node::Constant) {
                        $$ = $2;
                        *$$->value = +*$2->value;
                    } else {
                        $$ = new Global::Node(Global::Node::Abs, Q_NULLPTR, $2);
                    }
                }
            | '(' expression ')' { $$ = $2;}
            ;

arguments:  expression
            | arguments ',' expression {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = new Global::Node(Global::Node::Constant);
                        QList<Global::ZVariant> value;
                        value << *$1->value << *$3->value;
                        $$->value = new Global::ZVariant(value);
                    } else {
                        $$ = new Global::Node(Global::Node::Comma, $1, $3);
                        $$->value = new Global::ZVariant();
                    }
            }
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

yyFlexLexer *flexLexer;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    rootCode = new Global::Code();
    currentCode = rootCode;

    rootCode->data->identifiersHash["console"] = new Global::ZVariant(new Global::ZConsole);

    if(argc > 1) {
        freopen(argv[1], "r", stdin);
    }

    flexLexer = new yyFlexLexer();

    yy::parser parser;

    QtConcurrent::run(QThreadPool::globalInstance(), &parser, &yy::parser::parse);

    return a.exec();
}

void yy::parser::error(const location_type& loc, const std::string& msg)
{
    std::cerr << "from " << loc.begin.line << " line, " << loc.begin.column << " column "
              << "to " << loc.end.line << " line, " << loc.end.column << " column, " << msg << std::endl;
}

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return flexLexer->yylex();
}

int yyFlexLexer::yywrap()
{
    rootCode->exec();

    return 1;
}
