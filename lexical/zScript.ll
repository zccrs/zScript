%{
#include "zScript.tab.hpp"
#include "zglobal.h"
#include "ztool.h"

#include <QByteArray>
#include <QDebug>

#include <iostream>

yy::parser::semantic_type *yylval = Q_NULLPTR;
yy::parser::location_type *yyloc = Q_NULLPTR;

int lineCount = 1;
int currentColumn = 0;

#define TOKEN_PREFIX yy::parser::token
#define RECORD_TOKEN_LOC \
    yyloc->begin.line = lineCount;\
    yyloc->begin.column = currentColumn;\
    yyloc->end.line = lineCount;\
    yyloc->end.column = strlen(yytext) + currentColumn;\
    currentColumn = yyloc->end.column;
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*
number [0-9]+
real ({number}|0)\.[0-9]+
operator [-+*/=!<>,;{}\(\)\[\]&\|\^%~.?:@_]
ignore [ \t\r]

%%
{ignore}

\n {
    ++lineCount;
    currentColumn = 0;
}

"var"           { RECORD_TOKEN_LOC; return TOKEN_PREFIX::VAR;}
"function"      { RECORD_TOKEN_LOC; return TOKEN_PREFIX::FUNCTION;}
"new"           { RECORD_TOKEN_LOC; return TOKEN_PREFIX::NEW;}
"delete"        { RECORD_TOKEN_LOC; return TOKEN_PREFIX::DELETE;}
"throw"         { RECORD_TOKEN_LOC; return TOKEN_PREFIX::THROW;}
"if"            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::IF;}
"else"          { RECORD_TOKEN_LOC; return TOKEN_PREFIX::ELSE;}
"while"         { RECORD_TOKEN_LOC; return TOKEN_PREFIX::WHILE;}
"for"           { RECORD_TOKEN_LOC; return TOKEN_PREFIX::FOR;}
"undefined"     { RECORD_TOKEN_LOC; return TOKEN_PREFIX::UNDEFINED;}
"goto"          { RECORD_TOKEN_LOC; return TOKEN_PREFIX::GOTO;}
"return"        { RECORD_TOKEN_LOC; return TOKEN_PREFIX::RETURN;}
"break"         { RECORD_TOKEN_LOC; return TOKEN_PREFIX::BREAK;}
"continue"      { RECORD_TOKEN_LOC; return TOKEN_PREFIX::CONTINUE;}
"switch"        { RECORD_TOKEN_LOC; return TOKEN_PREFIX::SWITCH;}
"case"          { RECORD_TOKEN_LOC; return TOKEN_PREFIX::CASE;}
"default"       { RECORD_TOKEN_LOC; return TOKEN_PREFIX::DEFAULT;}
"=="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::EQ;}
"==="           { RECORD_TOKEN_LOC; return TOKEN_PREFIX::STEQ;}
"!="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::NEQ;}
"!=="           { RECORD_TOKEN_LOC; return TOKEN_PREFIX::STNEQ;}
"<="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::LE;}
">="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::GE;}
"&="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::ANDASSIGN;}
"|="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::ORASSIGN;}
"^="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::XORASSIGN;}
"%="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::MODASSIGN;}
"+="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::ADDASSIGN;}
"-="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::SUBASSIGN;}
"*="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::MULASSIGN;}
"/="            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::DIVASSIGN;}
"++"            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::ADDSELF;}
"--"            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::SUBSELF;}
"&&"            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::LAND;}
"||"            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::LOR;}
"&&="           { RECORD_TOKEN_LOC; return TOKEN_PREFIX::LANDASSIGN;}
"||="           { RECORD_TOKEN_LOC; return TOKEN_PREFIX::LORASSIGN;}
"<<"            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::LL;}
">>"            { RECORD_TOKEN_LOC; return TOKEN_PREFIX::GG;}

"true" {
    RECORD_TOKEN_LOC;

    yylval->identifier = new QByteArray("true");

    return TOKEN_PREFIX::BOOL;
}

"false" {
    RECORD_TOKEN_LOC;

    yylval->identifier = new QByteArray("false");

    return TOKEN_PREFIX::BOOL;
}

{operator} {
    RECORD_TOKEN_LOC;

    return yytext[0];
}

{identifier} {
    RECORD_TOKEN_LOC;

    yylval->identifier = new QByteArray(yytext);

    return TOKEN_PREFIX::IDENTIFIER;
}

(r\"|r\') {
    RECORD_TOKEN_LOC;

    yylval->identifier = new QByteArray();

    QByteArray &str = *yylval->identifier;

    while(!yyin.eof() && !yyin.fail()) {
        char ch = yyin.get();

        if(ch == yytext[1])
            break;

        str.append(ch);
    }

    return TOKEN_PREFIX::STRING;
}

['"] {
    RECORD_TOKEN_LOC;

    yylval->identifier = new QByteArray();

    QByteArray &str = *yylval->identifier;

    while(!yyin.eof() && !yyin.fail()) {
        char ch = yyin.get();

        if(ch == yytext[0])
            break;

        str.append(ch);
    }

    str = ZTool::stringEscapeHandler(str);

    return TOKEN_PREFIX::STRING;
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
    RECORD_TOKEN_LOC;

    yylval->identifier = new QByteArray(yytext);

    return TOKEN_PREFIX::INT;
}

{real} {
    RECORD_TOKEN_LOC;

    yylval->identifier = new QByteArray(yytext);

    return TOKEN_PREFIX::DOUBLE;
}
%%
