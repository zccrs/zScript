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

%right ASSIGN
%left PLUS SUB
%left MUL DIV

/// operator
%token PLUS SUB MUL DIV ASSIGN
%token LPAREN RPAREN SEMI LBRACE RBRACE LBRACKET RBRACKET COMMA

%%

start:
            | start ';'
            | start statement ';' {
                zInfo << $2.value;
            }
            ;

statement:  VAR IDENTIFIER '=' expression {
                $2.value = $4.value;
                $$ = $2;

                zInfo << $$.name << "=" << $$.value;
            }
            ;

expression: expression '+' VARIANT {
                $1.value = $1.value + $3.value;
                $$ = $1;
            }
            | expression '-' VARIANT {
                $1.value = $1.value - $3.value;
                $$ = $1;
            }
            | expression '*' VARIANT {
                $1.value = $1.value * $3.value;
                $$ = $1;
            }
            | expression '/' VARIANT {
                $1.value = $1.value / $3.value;
                $$ = $1;
            }
            | VARIANT
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
