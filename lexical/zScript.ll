%{
#include "zScript.tab.hpp"
#include "global.h"

using namespace yy;

YYSTYPE *yylval = Q_NULLPTR;

#define TOKEN_PREFIX parser::token
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*
number [1-9][0-9]*
real ({number}|0)\.[0-9]+
operator [-+*/=!<>,;{}\(\)\[\]&\|\^%~]
ignore [ \t]

%option noyywrap

%%
{ignore}

"var"           { return TOKEN_PREFIX::VAR;}
"function"      { return TOKEN_PREFIX::FUNCTION;}
"new"           { return TOKEN_PREFIX::NEW;}
"delete"        { return TOKEN_PREFIX::DELETE;}
"throw"         { return TOKEN_PREFIX::THROW;}
"if"            { return TOKEN_PREFIX::IF;}
"else"          { return TOKEN_PREFIX::ELSE;}
"while"         { return TOKEN_PREFIX::WHILE;}
("=="|"===")    { return TOKEN_PREFIX::EQ;}
("!="|"!==")    { return TOKEN_PREFIX::NEQ;}
"<="            { return TOKEN_PREFIX::LE;}
">="            { return TOKEN_PREFIX::GE;}
"&="            { return TOKEN_PREFIX::ANDEQ;}
"|="            { return TOKEN_PREFIX::OREQ;}
"^="            { return TOKEN_PREFIX::XOREQ;}
"%="            { return TOKEN_PREFIX::MODEQ;}
"+="            { return TOKEN_PREFIX::AEQ;}
"-="            { return TOKEN_PREFIX::SEQ;}
"*="            { return TOKEN_PREFIX::MEQ;}
"/="            { return TOKEN_PREFIX::DEQ;}
"++"            { return TOKEN_PREFIX::ADDSELF;}
"--"            { return TOKEN_PREFIX::SUBSELF;}
"&&"            { return TOKEN_PREFIX::AND;}
"||"            { return TOKEN_PREFIX::OR;}

"true" {
    yylval->value = true;

    return TOKEN_PREFIX::VARIANT;
}

"false" {
    yylval->value = false;

    return TOKEN_PREFIX::VARIANT;
}

[\r\n] {
    return ';';
}

{operator} {
    return yytext[0];
}

{identifier} {
    yylval->name = QByteArray(yytext);

    return TOKEN_PREFIX::IDENTIFIER;
}

['"] {
    QString str;

    while(!yyin.eof() && !yyin.fail()) {
        char ch = yyin.get();

        if(ch == yytext[0] || ch == '\n' || ch == '\r')
            break;

        if(ch == '\\') {
            if(yyin.eof() || yyin.fail())
                break;

            char next_ch = yyin.get();

            str.append(next_ch);
        } else {
            str.append(ch);
        }
    }


    yylval->value = str;

    return TOKEN_PREFIX::VARIANT;
}

"//" {
    while(!yyin.eof() && !yyin.fail()) {
        char ch = yyin.get();

        if(ch == '\n' || ch == '\r')
            break;

        if(ch == '\\') {
            if(yyin.eof() || yyin.fail())
                break;

            yyin.get();
        }
    }
}

"/*" {
    while(!yyin.eof() && !yyin.fail()) {
        char ch = yyin.get();

        if(ch == '*') {
            if(yyin.eof() || yyin.fail())
                break;

            char ch_next = yyin.get();

            if(ch_next == '/')
                break;
        }
    }
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
