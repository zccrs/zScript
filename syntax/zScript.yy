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
            | start statement ';' {

            }
            | start expression ';' {
                $$ = $2;
                std::cout << "(" << $$->typeName() << "," << $$->toString().toStdString() << ")" << std::endl;
            }
            | start conditional {

            }
            ;

statement:  VAR define {
                if(Global::identifiersHash.contains($2->name)) {
                    std::cerr << $2->name.constData() << " is defined!" << std::endl;
                    YYERROR;
                } else {
                    $2->value = new Global::ZVariant;
                    Global::identifiersHash[$2->name] = $2;
                }

                $$ = $2;
            }
            | FUNCTION IDENTIFIER '(' define ')' '{' start '}' {
                zInfo << "function name: " << $2->name;
            }
            ;

define:     IDENTIFIER
            | define ',' define
            | IDENTIFIER '=' expression
            ;

expression:    lvalue | rvalue;

lvalue:     IDENTIFIER
            | lvalue '=' expression
            | variant '[' expression ']'
            | lvalue AEQ expression {
                *$1 += *$3;
                $$ = $1;
            }
            | lvalue SEQ expression {
                *$1 -= *$3;
                $$ = $1;
            }
            | lvalue MEQ expression {
                *$1 *= *$3;
                $$ = $1;
            }
            | lvalue DEQ expression {
                *$1 /= *$3;
                $$ = $1;
            }
            | lvalue ANDEQ expression {
                *$1 &= *$3;
                $$ = $1;
            }
            | lvalue OREQ expression {
                *$1 |= *$3;
                $$ = $1;
            }
            | lvalue XOREQ expression {
                *$1 ^= *$3;
                $$ = $1;
            }
            | lvalue MODEQ expression {
                *$1 %= *$3;
                $$ = $1;
            }
            | ADDSELF lvalue {
                ++*$2;
                $$ = $2;
            }
            | SUBSELF lvalue {
                --*$2;
                $$ = $2;
            }
            | lvalue ADDSELF {
                $$ = new Global::ZVariant(*$1);
                (*$1)++;
            }
            | lvalue SUBSELF {
                $$ = new Global::ZVariant(*$1);
                (*$1)--;
            }
            ;

rvalue:
            | CONSTANT
            | NEW IDENTIFIER
            | expression '(' arguments ')'
            | expression '.' IDENTIFIER
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
            | '~' expression { $$ = new Global::ZVariant(~*$2);}
            | '!' expression { $$ = new Global::ZVariant(!*$2);}
            | '-' expression %prec UMINUS { $$ = new Global::ZVariant(-*$2);}
            | '+' expression %prec UMINUS { $$ = new Global::ZVariant(+*$2);}
            | '(' expression ')' { $$ = $2;}
            ;

arguments:  expression | arguments ',' expression;

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
