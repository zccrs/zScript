%{
#include <stdio.h>
#include <ctype.h>
#include "global.h"

#define YYSTYPE TreeNode

int yylex(TreeNode *lval);

#include "lex.yy.cpp"
%}

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE

/// data type
%token NUMBER STRING

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
            | start statement ';'
            ;

statement:  VAR IDENTIFIER '=' expression {
                $2.value = $4.value;
                $$ = $2;

                zStandardPrint << $$.name.toStdString() << "=" << $$.value << std::endl;
            }
            ;

expression: expression '+' NUMBER {
                $1.value = $1.value + $3.value;
                $$ = $1;
            }
          | expression '-' NUMBER {
                $1.value = $1.value - $3.value;
                $$ = $1;
            }
          | NUMBER
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
