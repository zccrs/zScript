%{
#include "zScript.tab.hpp"
#include "global.h"

yy::parser::semantic_type *yylval = Q_NULLPTR;
yy::parser::location_type *yyloc = Q_NULLPTR;

#define TOKEN_PREFIX yy::parser::token
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
    yylval->value = new Global::ZVariant(true);

    return TOKEN_PREFIX::VARIANT;
}

"false" {
    yylval->value = new Global::ZVariant(false);

    return TOKEN_PREFIX::VARIANT;
}

[\r\n] {
    while(yyin.rdbuf()->in_avail() && !yyin.eof() && !yyin.fail()) {
        char ch = yyin.peek();

        if(ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            yyin.get();
            continue;
        } else if(ch == ',' || ch == '}' || ch == ')' || ch == ']') {
            break;
        } else {
            return ';';
        }
    }

    if(!yyin.rdbuf()->in_avail() || yyin.eof())
        return ';';
}

{operator} {
    return yytext[0];
}

{identifier} {
    QByteArray name(yytext);

    if(Global::identifiersHash.contains(name)) {
        yylval->identifier = Global::identifiersHash.value(name);
    } else {
        yylval->identifier = new Global::IdentifierValue;
        yylval->identifier->name = name;
    }

    return TOKEN_PREFIX::IDENTIFIER;
}

['"] {
    QByteArray str;

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

    yylval->value = new Global::ZVariant(QString::fromLocal8Bit(str));

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
    yylval->value = new Global::ZVariant(atoi(yytext));

    return TOKEN_PREFIX::VARIANT;
}

{real} {
    yylval->value = new Global::ZVariant(atof(yytext));

    return TOKEN_PREFIX::VARIANT;
}
%%
