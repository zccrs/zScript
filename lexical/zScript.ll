%{
#include "zScript.tab.hpp"
#include "zglobal.h"
#include "ztool.h"

#include <QByteArray>
#include <QDebug>

#include <iostream>

yy::parser::semantic_type *yylval = Q_NULLPTR;
yy::parser::location_type *yyloc = Q_NULLPTR;

#define TOKEN_PREFIX yy::parser::token
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*
number [0-9]+
real ({number}|0)\.[0-9]+
operator [-+*/=!<>,;{}\(\)\[\]&\|\^%~.?:@_]
ignore [ \t]

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
"for"           { return TOKEN_PREFIX::FOR;}
"undefined"     { return TOKEN_PREFIX::UNDEFINED;}
"goto"          { return TOKEN_PREFIX::GOTO;}
"return"        { return TOKEN_PREFIX::RETURN;}
"break"         { return TOKEN_PREFIX::BREAK;}
"containue"     { return TOKEN_PREFIX::CONTAINUE;}
"=="            { return TOKEN_PREFIX::EQ;}
"==="           { return TOKEN_PREFIX::STEQ;}
"!="            { return TOKEN_PREFIX::NEQ;}
"!=="           { return TOKEN_PREFIX::STNEQ;}
"<="            { return TOKEN_PREFIX::LE;}
">="            { return TOKEN_PREFIX::GE;}
"&="            { return TOKEN_PREFIX::ANDASSIGN;}
"|="            { return TOKEN_PREFIX::ORASSIGN;}
"^="            { return TOKEN_PREFIX::XORASSIGN;}
"%="            { return TOKEN_PREFIX::MODASSIGN;}
"+="            { return TOKEN_PREFIX::ADDASSIGN;}
"-="            { return TOKEN_PREFIX::SUBASSIGN;}
"*="            { return TOKEN_PREFIX::MULASSIGN;}
"/="            { return TOKEN_PREFIX::DIVASSIGN;}
"++"            { return TOKEN_PREFIX::ADDSELF;}
"--"            { return TOKEN_PREFIX::SUBSELF;}
"&&"            { return TOKEN_PREFIX::LAND;}
"||"            { return TOKEN_PREFIX::LOR;}
"&&="           { return TOKEN_PREFIX::LANDASSIGN;}
"||="           { return TOKEN_PREFIX::LORASSIGN;}
"<<"            { return TOKEN_PREFIX::LL;}
">>"            { return TOKEN_PREFIX::GG;}

"true" {
    yylval->identifier = new QByteArray("true");

    return TOKEN_PREFIX::BOOL;
}

"false" {
    yylval->identifier = new QByteArray("false");

    return TOKEN_PREFIX::BOOL;
}

(\n|\r|\r\n) {
//    while(/*yyin.rdbuf()->in_avail() && */!yyin.eof() && !yyin.fail()) {
//        char ch = yyin.peek();

//        if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
//            yyin.get();
//            continue;
//        } else if(ch == ',' || ch == '{' || ch == '}'
//                  || ch == '(' || ch == ')'
//                  || ch == '[' || ch == ']') {
//            break;
//        } else {
//            return ';';
//        }
//    }

//    if(/*!yyin.rdbuf()->in_avail() || */yyin.eof())
//        return ';';
        return '\n';
}

{operator} {
    return yytext[0];
}

{identifier} {
    yylval->identifier = new QByteArray(yytext);

    return TOKEN_PREFIX::IDENTIFIER;
}

(r\"|r\') {
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
    yylval->identifier = new QByteArray(yytext);

    return TOKEN_PREFIX::INT;
}

{real} {
    yylval->identifier = new QByteArray(yytext);

    return TOKEN_PREFIX::DOUBLE;
}
%%
