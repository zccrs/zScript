%{
#include <stdio.h>
#include <ctype.h>

#define YYSTYPE TreeNode*

#include "global.h"
#include "lex.yy.c"
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

start:      {$$ = NULL;}
            | start statement ';' {free($$);}
            ;

statement:  VAR IDENTIFIER '=' expression {
                $2->value = $4->value;
                printf("%s = %d\n", $2->name, $2->value);
                free($4);
                $$ = $2;
            }
            ;

expression: expression '+' NUMBER {
                printf("%d + %d = ", $1->value, $3->value);
                $1->value = $1->value + $3->value;
                printf("%d\n", $1->value);
                $$ = $1;
                free($3);
            }
          | expression '-' NUMBER {
                printf("%d - %d = ", $1->value, $3->value);
                $1->value = $1->value - $3->value;
                printf("%d\n", $1->value);
                $$ = $1;
                free($3);
            }
          | NUMBER
          ;

%%

int main()
{
    return yyparse();
}

int yyerror(char * s)
{
    printf("Syntax error: %s\n", s);

    return 0;
}
