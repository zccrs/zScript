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
%type <value> assign expression

%%

start:
            | start ';'
            | start assign ';'
            ;

assign:     statement '=' expression {
                $1->value = *$3;
                $$ = $3;

                zInfo << $1->name << "=" << *$$;
            }
            | IDENTIFIER '=' expression {
                if(!Global::identifiersHash.contains($1->name)) {
                    std::cerr << $1->name.toStdString() << " is undefined!" << std::endl;
                    delete $1;
                    YYERROR;
                }

                $1->value = *$3;
                $$ = $3;

                zInfo << $1->name << "=" << *$$;
            }

statement:  VAR IDENTIFIER {
                if(Global::identifiersHash.contains($2->name)) {
                    std::cerr << $2->name.constData() << " is defined!" << std::endl;
                    YYERROR;
                } else {
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
                *$$ = $1->value;
            }
            | expression '+' expression {
                *$$ = *$1 + *$3;
            }
            | expression '-' expression {
                *$$ = *$1 - *$3;
            }
            | expression '*' expression {
                *$$ = *$1 * *$3;
            }
            | expression '/' expression {
                *$$ = *$1 / *$3;
            }
            | expression AEQ expression {
                *$$ = *$1 += *$3;
            }
            | expression SEQ expression {
                *$$ = *$1 -= *$3;
            }
            | expression MEQ expression {
                *$$ = *$1 *= *$3;
            }
            | expression DEQ expression {
                *$$ = *$1 /= *$3;
            }
            | expression '&' expression {
                *$$ = *$1 & *$3;
            }
            | expression '|' expression {
                *$$ = *$1 | *$3;
            }
            | expression '^' expression {
                *$$ = *$1 ^ *$3;
            }
            | expression '%' expression {
                *$$ = *$1 % *$3;
            }
            | expression ANDEQ expression {
                *$$ = *$1 &= *$3;
            }
            | expression OREQ expression {
                *$$ = *$1 |= *$3;
            }
            | expression XOREQ expression {
                *$$ = *$1 ^= *$3;
            }
            | expression MODEQ expression {
                *$$ = *$1 %= *$3;
            }
            | expression EQ expression {
                *$$ = *$1 == *$3;
            }
            | expression NEQ expression {
                *$$ = *$1 != *$3;
            }
            | expression LE expression {
                *$$ = *$1 <= *$3;
            }
            | expression GE expression {
                *$$ = *$1 >= *$3;
            }
            | expression AND expression {
                *$$ = *$1 && *$3;
            }
            | expression OR expression {
                *$$ = *$1 || *$3;
            }
            | ADDSELF expression {
                *$$ = ++ *$2;
            }
            | expression ADDSELF {
                *$$ = *$1++;
            }
            | SUBSELF expression {
                *$$ = -- *$2;
            }
            | expression SUBSELF {
                *$$ = *$1--;
            }
            | '-' expression %prec UMINUS { *$$ = 0 - *$2;}
            | '+' expression %prec UMINUS { *$$ = *$2;}
            | '(' expression ')' { *$$ = *$2;}
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
