%{
#include "global.h"

#define YYSTYPE TreeNode

int yylex(TreeNode *lval);

#include "lex.yy.cpp"
%}

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE

/// data type
%token VARIANT

/// identifier
%token IDENTIFIER

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

%%

start:
            | start ';'
            | start statement ';' {
                //zInfo << $2.value;
            }
            ;

statement:  VAR IDENTIFIER '=' expression {
                $2.value = $4.value;
                $$ = $2;

                zInfo << $$.name << "=" << $$.value;
            }
            ;

expression: VARIANT
            | expression '+' expression {
                $$.value = $1.value + $3.value;
            }
            | expression '-' expression {
                $$.value = $1.value - $3.value;
            }
            | expression '*' expression {
                $$.value = $1.value * $3.value;
            }
            | expression '/' expression {
                $$.value = $1.value / $3.value;
            }
            | expression AEQ expression {
                $$.value = $1.value += $3.value;
            }
            | expression SEQ expression {
                $$.value = $1.value -= $3.value;
            }
            | expression MEQ expression {
                $$.value = $1.value *= $3.value;
            }
            | expression DEQ expression {
                $$.value = $1.value /= $3.value;
            }
            | expression '&' expression {
                $$.value = $1.value & $3.value;
            }
            | expression '|' expression {
                $$.value = $1.value | $3.value;
            }
            | expression '^' expression {
                $$.value = $1.value ^ $3.value;
            }
            | expression '%' expression {
                $$.value = $1.value % $3.value;
            }
            | expression ANDEQ expression {
                $$.value = $1.value &= $3.value;
            }
            | expression OREQ expression {
                $$.value = $1.value |= $3.value;
            }
            | expression XOREQ expression {
                $$.value = $1.value ^= $3.value;
            }
            | expression MODEQ expression {
                $$.value = $1.value %= $3.value;
            }
            | expression EQ expression {
                $$.value = $1.value == $3.value;
            }
            | expression NEQ expression {
                $$.value = $1.value != $3.value;
            }
            | expression LE expression {
                $$.value = $1.value <= $3.value;
            }
            | expression GE expression {
                $$.value = $1.value >= $3.value;
            }
            | expression AND expression {
                $$.value = $1.value && $3.value;
            }
            | expression OR expression {
                $$.value = $1.value || $3.value;
            }
            | ADDSELF expression {
                $$.value = ++$2.value;
            }
            | expression ADDSELF {
                $$.value = $1.value++;
            }
            | SUBSELF expression {
                $$.value = --$2.value;
            }
            | expression SUBSELF {
                $$.value = $1.value--;
            }
            | '-' expression %prec UMINUS {$$.value = 0 -$2.value;}
            | '+' expression %prec UMINUS {$$.value = $2.value;}
            | '(' expression ')' {$$.value = $2.value;}
            ;

%%

yyFlexLexer flexLexer;

int main()
{
    yy::parser parser;

    return parser.parse();
}

void yy::parser::error(const std::string& msg)
{
    zStandardPrint << msg << std::endl;
}

int yylex(TreeNode *lval)
{
    yylval = lval;

    return flexLexer.yylex();
}
