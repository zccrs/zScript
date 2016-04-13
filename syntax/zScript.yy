%{
#include "global.h"

/// enable debug
#define YYDEBUG 1

#include "lex.yy.cpp"

#include <QCoreApplication>
#include <QtConcurrent/QtConcurrentRun>

#include <fstream>

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

inline Global::ZVariant *getIdentifierAddress(const QByteArray &name);
inline Global::ZVariant *getConstantAddress(const QByteArray &name, Global::ZVariant::Type type);
inline Global::ZVariant *getConstantAddressByValue(const Global::ZVariant &value);
inline Global::ZCode *createCode(const Global::ZCode::Action &action, Global::ZVariant *val = Q_NULLPTR);

struct Scope{
    Scope *parent = Q_NULLPTR;
    QHash<QByteArray, Global::ZVariant**> identifiers;
};

enum ValueType {
    Variant,
    Constant
};

Scope *createScope(Scope *parent = Q_NULLPTR);

Scope *currentScope = Q_NULLPTR;
QSet<const QByteArray> *undefinedIdentifier = Q_NULLPTR;
QList<Scope*> *scopeList = Q_NULLPTR;
QHash<const QByteArray, Global::ZVariant*> *constantHash = Q_NULLPTR;

%}

/// enable debug
%debug
/// enable locations
%locations

%union{
    int valueType;
    QByteArray *identifier;
};

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE FOR

/// identifier
%token <identifier> IDENTIFIER INT STRING BOOL DOUBLE

///     ==  ===    !=  !==  <= >= &&   ||   ++      --
%token  EQ  STEQ  NEQ STNEQ LE GE LAND LOR ADDSELF SUBSELF
///     /=  *=  +=  -=   %=    &=    |=   ^=
%token  DEQ MEQ AEQ SEQ MODEQ ANDEQ OREQ XOREQ

%left ','
%right '=' DEQ MEQ AEQ SEQ MODEQ ANDEQ OREQ XOREQ
%left '?' ':'
%left LAND LOR
%left '&' '|' '^'
%left EQ NEQ
%left '>' '<' GE LE
%left '-' '+'
%left '*' '/' '%'
%right UMINUS ADDSELF SUBSELF '!' '~'
%left '(' ')'

%type <valueType> expression lvalue rvalue

%%

start:
            | start statement ';' {
                Global::codeList << createCode(Global::ZCode::PopAll);
            }
            | start expression ';' {
                Global::codeList << createCode(Global::ZCode::PopAll);
            }
            | start conditional {
                //currentCode->nodeList << $2;
            }
            ;

statement:  VAR define
            | FUNCTION IDENTIFIER '(' define ')' '{' start '}' {
                /// TODO
            }
            ;

define:     IDENTIFIER {
                undefinedIdentifier->remove(*$1);

                delete $1;
            }
            | define ',' define
            ;

expression: lvalue | rvalue;

lvalue:     IDENTIFIER {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::Push, getIdentifierAddress(*$1));

                delete $1;
            }
            | lvalue '=' expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::Assign);
            }
            | expression '[' expression ']' {
                $$ = ValueType::Variant;
                /// TODO
            }
            | lvalue AEQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::AndAssign);
            }
            | lvalue SEQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::SubAssign);
            }
            | lvalue MEQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::MulAssign);
            }
            | lvalue DEQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::DivAssign);
            }
            | lvalue ANDEQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::AndAssign);
            }
            | lvalue OREQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::OrAssign);
            }
            | lvalue XOREQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::XorAssign);
            }
            | lvalue MODEQ expression {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::ModAssign);
            }
            | ADDSELF lvalue {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PrefixAddSelf);
            }
            | SUBSELF lvalue {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PrefixSubSelf);
            }
            | lvalue ADDSELF {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PostfixAddSelf);
            }
            | lvalue SUBSELF {
                $$ = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PostfixSubSelf);
            }
            ;

rvalue:     {
                $$ = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(QByteArray(), Global::ZVariant::Null));
            }
            | INT {
                $$ = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::Int));

                delete $1;
            }
            | STRING {
                $$ = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::String));

                delete $1;
            }
            | DOUBLE {
                $$ = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::Double));

                delete $1;
            }
            | BOOL {
                $$ = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::Bool));

                delete $1;
            }
            | NEW IDENTIFIER {
                /// TODO
                $$ = ValueType::Constant;
            }
            | expression '(' arguments ')' {
                    $$ = ValueType::Variant;

                    Global::codeList << createCode(Global::ZCode::Call);
            }
            | expression '.' IDENTIFIER {
                    $$ = ValueType::Variant;

                    Global::codeList << createCode(Global::ZCode::Get, getConstantAddress(*$3, Global::ZVariant::String));
            }
            | expression '+' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target + *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Add);
                    }
            }
            | expression '-' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target - *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Sub);
                    }
            }
            | expression '*' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target * *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Mul);
                    }
            }
            | expression '/' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target / *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Div);
                    }
            }
            | expression '&' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target & *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::And);
                    }
            }
            | expression '|' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target | *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Or);
                    }
            }
            | expression '^' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target ^ *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Xor);
                    }
            }
            | expression '%' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target % *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Mod);
                    }
            }
            | expression EQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target == *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::EQ);
                    }
            }
            | expression NEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target != *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::NEQ);
                    }
            }
            | expression LE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target <= *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::LE);
                    }
            }
            | expression GE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target >= *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::GE);
                    }
            }
            | expression LAND expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target && *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::LAnd);
                    }
            }
            | expression LOR expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target || *last_code->target);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::LOr);
                    }
            }
            | '~' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(~ *last_code->target);
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Contrary);
                    }
                }
            | '!' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(! *last_code->target);
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Not);
                    }
                }
            | '-' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(- *last_code->target);
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Minus);
                    }
                }
            | '+' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(+ *last_code->target);
                    } else {
                        $$ = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Abs);
                    }
                }
            | '(' expression ')' { $$ = $2;}
            ;

arguments:  expression
            | arguments ',' expression/* {
                    if($1->nodeType == Global::Node::Constant
                            && $3->nodeType == Global::Node::Constant) {
                        $$ = new Global::Node(Global::Node::Constant);
                        QList<Global::ZVariant> value;
                        value << *$1->value << *$3->value;
                        $$->value = new Global::ZVariant(value);
                    } else {
                        $$ = new Global::Node(Global::Node::Comma, $1, $3);
                        $$->value = new Global::ZVariant();
                    }
            }*/
            ;

branch_head:IF '(' expression ')'
            | WHILE '(' expression ')'
            | FOR '(' expression ';' expression ';' expression ')'
            | FOR '(' lvalue ':' expression ')';

conditional:branch_head '{' start '}'
            | branch_head expression ';'
            | conditional ELSE conditional
            | conditional ELSE '{' start '}'
            | conditional ELSE expression ';'
            ;

%%

yyFlexLexer *flexLexer;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    undefinedIdentifier = new QSet<const QByteArray>();
    scopeList = new QList<Scope*>();
    constantHash = new QHash<const QByteArray, Global::ZVariant*>();
    currentScope = createScope();

//    currentScope->identifiers["console"] = &(new Global::ZVariant(new Global::ZConsole));

    if(argc > 1) {
        freopen(argv[1], "r", stdin);
    }

    flexLexer = new yyFlexLexer();

    yy::parser parser;

    QtConcurrent::run(QThreadPool::globalInstance(), &parser, &yy::parser::parse);

    return a.exec();
}

void yy::parser::error(const location_type& loc, const std::string& msg)
{
    std::cerr << "from " << loc.begin.line << " line, " << loc.begin.column << " column "
              << "to " << loc.end.line << " line, " << loc.end.column << " column, " << msg << std::endl;
}

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return flexLexer->yylex();
}

Global::ZVariant *getIdentifierAddress(const QByteArray &name)
{
    Scope *scope = currentScope;
    Global::ZVariant **val = Q_NULLPTR;

    while(scope) {
        val = scope->identifiers.value(name);

        if(val)
            return *val;

        scope = currentScope->parent;
    }

    if(!val) {
        val = new Global::ZVariant*;
    }

    return *val;
}

Global::ZVariant *getConstantAddress(const QByteArray &name, Global::ZVariant::Type type)
{
    Global::ZVariant *val = constantHash->value(name);

    if(!val) {
        switch(type) {
        case Global::ZVariant::Int:
            val = new Global::ZVariant(name.toInt());
            break;
        case Global::ZVariant::Double:
            val = new Global::ZVariant(name.toDouble());
            break;
        case Global::ZVariant::String:
            val = new Global::ZVariant(QString(name));
            break;
        case Global::ZVariant::Bool:
            val = new Global::ZVariant((bool)name.toInt());
            break;
        default:
            val = new Global::ZVariant();
            break;
        }

        (*constantHash)[name] = val;
    }

    return val;
}

Global::ZVariant *getConstantAddressByValue(const Global::ZVariant &value)
{
    return getConstantAddress(value.toString().toLatin1(), value.type());
}

Global::ZCode *createCode(const Global::ZCode::Action &action, Global::ZVariant *val)
{
    Global::ZCode *code = new Global::ZCode;

    code->action = action;
    code->target = val;

    return code;
}

Scope *createScope(Scope *parent)
{
    Scope *scope = new Scope;

    scope->parent = parent;
    scopeList->append(scope);

    return scope;
}

int yyFlexLexer::yywrap()
{
    qDeleteAll(*scopeList);

    delete scopeList;
    delete constantHash;
    delete undefinedIdentifier;

    for(const Global::ZCode *code : Global::codeList) {
        qDebug() << *code;
    }

    return 0;
}
