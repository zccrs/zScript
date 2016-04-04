%{
#include "global.h"

/// enable debug
#define YYDEBUG 1

#include "lex.yy.cpp"

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);
%}

/// enable debug
%debug
/// enable locations
%locations

%union{
    Global::ZVariant *value;
    Global::IdentifierValue *identifier;
    Global::NodeValue *node;
};

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE

/// data type
%token <value> VARIANT

/// identifier
%token <identifier> IDENTIFIER

///   ==/=== !=/!==   <= >= &&  ||   ++      --
%token  EQ     NEQ    LE GE AND OR ADDSELF SUBSELF
///     /=  *=  +=  -=   %=    &=    |=   ^=
%token  DEQ MEQ AEQ SEQ MODEQ ANDEQ OREQ XOREQ

%left ','
%right '=' DEQ MEQ AEQ SEQ MODEQ ANDEQ OREQ XOREQ
%left '?' ':'
%left AND OR
%left '&' '|' '^'
%left EQ NEQ
%left '>' '<' GE LE
%left '-' '+'
%left '*' '/' '%'
%right UMINUS ADDSELF SUBSELF '!' '~'
%left '(' ')'

%type <identifier> statement
%type <value> start assign expression

%%

start:      {$$ = Q_NULLPTR;}
            | start ';'
            | start assign ';' {
                $$ = $2;
                std::cout << "(" << $$->typeName() << "," << $$->toString().toStdString() << ")" << std::endl;
            }
            ;

assign:     expression {$$ = $1;}
            | statement {$$ = $1->value;}
            | statement '=' expression {
                *$1->value = *$3;
                $$ = $1->value;
            }
            | IDENTIFIER '=' expression {
                if(!Global::identifiersHash.contains($1->name)) {
                    std::cerr << $1->name.toStdString() << " is undefined!" << std::endl;
                    delete $1;
                    YYERROR;
                }

                *$1->value = *$3;
                $$ = $1->value;
            }
            ;

statement:  VAR IDENTIFIER {
                if(Global::identifiersHash.contains($2->name)) {
                    std::cerr << $2->name.constData() << " is defined!" << std::endl;
                    YYERROR;
                } else {
                    $2->value = new Global::ZVariant;
                    Global::identifiersHash[$2->name] = $2;
                }

                $$ = $2;
            }
            | FUNCTION IDENTIFIER '(' ')' '{' '}' {
                zInfo << "function name: " << $2->name;
            }
            ;

expression: VARIANT
            | IDENTIFIER {
                if(!Global::identifiersHash.contains($1->name)) {
                    std::cerr << $1->name.toStdString() << " is undefined!" << std::endl;
                    delete $1;
                    YYERROR;
                }
                $$ = $1->value;
            }
            | expression '+' expression {
                $$ = new Global::ZVariant(*$1 + *$3);
            }
            | expression '-' expression {
                $$ = new Global::ZVariant(*$1 - *$3);
            }
            | expression '*' expression {
                $$ = new Global::ZVariant(*$1 * *$3);
            }
            | expression '/' expression {
                $$ = new Global::ZVariant(*$1 / *$3);
            }
            | expression AEQ expression {
                *$1 += *$3;
                $$ = $1;
            }
            | expression SEQ expression {
                *$1 -= *$3;
                $$ = $1;
            }
            | expression MEQ expression {
                *$1 *= *$3;
                $$ = $1;
            }
            | expression DEQ expression {
                *$1 /= *$3;
                $$ = $1;
            }
            | expression '&' expression {
                $$ = new Global::ZVariant(*$1 & *$3);
            }
            | expression '|' expression {
                $$ = new Global::ZVariant(*$1 | *$3);
            }
            | expression '^' expression {
                $$ = new Global::ZVariant(*$1 ^ *$3);
            }
            | expression '%' expression {
                $$ = new Global::ZVariant(*$1 % *$3);
            }
            | expression ANDEQ expression {
                *$1 &= *$3;
                $$ = $1;
            }
            | expression OREQ expression {
                *$1 |= *$3;
                $$ = $1;
            }
            | expression XOREQ expression {
                *$1 ^= *$3;
                $$ = $1;
            }
            | expression MODEQ expression {
                *$1 %= *$3;
                $$ = $1;
            }
            | expression EQ expression {
                $$ = new Global::ZVariant(*$1 == *$3);
            }
            | expression NEQ expression {
                $$ = new Global::ZVariant(*$1 != *$3);
            }
            | expression LE expression {
                $$ = new Global::ZVariant(*$1 <= *$3);
            }
            | expression GE expression {
                $$ = new Global::ZVariant(*$1 >= *$3);
            }
            | expression AND expression {
                $$ = new Global::ZVariant(*$1 && *$3);
            }
            | expression OR expression {
                $$ = new Global::ZVariant(*$1 || *$3);
            }
            | ADDSELF expression {
                ++*$2;
                $$ = $2;
            }
            | expression ADDSELF {
                $$ = new Global::ZVariant(*$1);
                (*$1)++;
            }
            | SUBSELF expression {
                --*$2;
                $$ = $2;
            }
            | expression SUBSELF {
                $$ = new Global::ZVariant(*$1);
                (*$1)--;
            }
            | '~' expression { $$ = new Global::ZVariant(~*$2);}
            | '!' expression { $$ = new Global::ZVariant(!*$2);}
            | '-' expression %prec UMINUS { $$ = new Global::ZVariant(-*$2);}
            | '+' expression %prec UMINUS { $$ = new Global::ZVariant(+*$2);}
            | '(' expression ')' { $$ = $2;}
            ;

%%

yyFlexLexer flexLexer;

int main()
{
    yy::parser parser;

    return parser.parse();
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

    return flexLexer.yylex();
}
