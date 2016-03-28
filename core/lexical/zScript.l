%{
#include "zScript.tab.h"
#include "global.h"
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*
string (\'(.|\\\\.)*\'|\"(.|\\\\.)*\")
number [1-9][0-9]*
operator ([-+*/=!<>,;{}\(\)\[\]]|!=|!==|==|===|<=|>=|&&|\|\|)
note \/\/.*
ignore [ \t\r\n]

%option noyywrap

%%
{note} {
    printf("note: \"%s\"\n", yytext);
}
{string} {
    printf("string: \"%s\"\n", yytext);
    return STRING;
}

"var"       { return VAR;}
"function"  { return FUNCTION;}
"new"       { return NEW;}
"delete"    { return DELETE;}
"throw"     { return THROW;}
"if"        { return IF;}
"else"      { return ELSE;}
"while"     { return WHILE;}

terminal {
    printf("terminal: %s\n", yytext);
}

{operator} {
    //printf("operator: \"%s\"\n", yytext);

    return yytext[0];
}

{identifier} {
    yylval =  (TreeNode*)malloc(sizeof(TreeNode));
    yylval->name = malloc(strlen(yytext));
    yylval->name = strcpy(yylval->name, yytext);
    //printf("identifier: \"%s\"\n", yytext);
    yylval->value = -1;

    return IDENTIFIER;
}
{number} {
    //printf("number: %s\n", yytext);
    yylval =  (TreeNode*)malloc(sizeof(TreeNode));
    yylval->value = atoi(yytext);
    yylval->name = NULL;

    return NUMBER;
}
{ignore}
%%
