%{
#include "zScript.tab.hpp"
#include "global.h"

using namespace yy;

YYSTYPE *yylval = Q_NULLPTR;

#define TOKEN_PREFIX parser::token
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*
string (\'(.|\\\\.)*\'|\"(.|\\\\.)*\")
number [1-9][0-9]*
real ({number}|0)\.[0-9]*[1-9]
operator ([-+*/=!<>,;{}\(\)\[\]]|!=|!==|==|===|<=|>=|&&|\|\|)
note \/\/.*
ignore [ \t\r\n]

%option noyywrap

%%
{note}
{ignore}


"var"       { return TOKEN_PREFIX::VAR;}
"function"  { return TOKEN_PREFIX::FUNCTION;}
"new"       { return TOKEN_PREFIX::NEW;}
"delete"    { return TOKEN_PREFIX::DELETE;}
"throw"     { return TOKEN_PREFIX::THROW;}
"if"        { return TOKEN_PREFIX::IF;}
"else"      { return TOKEN_PREFIX::ELSE;}
"while"     { return TOKEN_PREFIX::WHILE;}

"true" {
    yylval->value = true;

    return TOKEN_PREFIX::VARIANT;
}

"false" {
    yylval->value = false;

    return TOKEN_PREFIX::VARIANT;
}

{operator} {
    return yytext[0];
}

{identifier} {
    yylval->name = QByteArray(yytext);

    return TOKEN_PREFIX::IDENTIFIER;
}

{string} {
    yylval->value = QString(yytext);

    return TOKEN_PREFIX::VARIANT;
}

{number} {
    yylval->value = atoi(yytext);

    return TOKEN_PREFIX::VARIANT;
}

{real} {
    yylval->value = atof(yytext);

    return TOKEN_PREFIX::VARIANT;
}
%%
