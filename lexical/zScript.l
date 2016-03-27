%{
#include "../syntax/zScript.tab.h"
%}

keyword (var|function|new|delete|throw)
identifier [a-zA-Z_][a-zA-Z0-9_]*
string (\'(.|\\\\.)*\'|\"(.|\\\\.)*\")
number [1-9][0-9]*
operator ([-+*/=!<>]|!=|!==|==|===|<=|>=|&&|\|\|)
note \/\/.*
ignore [,; \t\r\n]

%%
{note} {
    printf("note: \"%s\"\n", yytext);
}
{string} {
    printf("string: \"%s\"\n", yytext);
}
{keyword} {
    printf("keyword: \"%s\"\n", yytext);
}
terminal {
    printf("terminal；%s\n", yytext);
}
{operator} {
    printf("operator: %s\n", yytext);
}
\( {
    printf("%s\n", yytext);
}
\) {
    printf("%s\n", yytext);
}
\[ {
    printf("%s\n", yytext);
}
\] {
    printf("%s\n", yytext);
}
\{ {
    printf("%s\n", yytext);
}
\} {
    printf("%s\n", yytext);
}
{identifier} {
    printf("identifier: \"%s\"\n", yytext);
}
{number} {
    printf("number: %s\n", yytext);
    return NUMBER;
}
{ignore}
%%
