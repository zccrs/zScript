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
inline Global::ZVariant *getConstantAddress(const QByteArray &value, Global::ZVariant::Type type);
inline Global::ZVariant *getConstantAddressByValue(const Global::ZVariant &value);
inline Global::ZCode *createCode(const Global::ZCode::Action &action, Global::ZVariant *val = Q_NULLPTR);

struct Scope{
    Scope *parent = Q_NULLPTR;
    QHash<QByteArray, Global::ZVariant*> identifiers;
};

enum ValueType {
    Variant,
    Constant
};

Scope *createScope(Scope *parent = Q_NULLPTR);

Scope *currentScope = Q_NULLPTR;
QSet<const QByteArray> *undefinedIdentifier = Q_NULLPTR;
QList<Scope*> *scopeList = Q_NULLPTR;
QHash<const QByteArray, Global::ZVariant*> *stringConstantHash = Q_NULLPTR;
QHash<const QByteArray, Global::ZVariant*> *numberConstantHash = Q_NULLPTR;
Global::ZVariant constTrue(true);
Global::ZVariant constFalse(false);
Global::ZVariant constUndefined;

%}

/// enable debug
%debug
/// enable locations
%locations

%union{
    int valueType;
    int argsCount;
    QByteArray *identifier;
};

/// keyword
%token VAR FUNCTION NEW DELETE THROW IF ELSE WHILE FOR UNDEFINED

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
%type <argsCount> arguments

%%

start:
            | start ';' {
                if(Global::ZCode::codeList.count() > 1 && Global::ZCode::codeList.last()->action != Global::ZCode::PopAll)
                    Global::ZCode::codeList << createCode(Global::ZCode::PopAll);
            }
            | start statement ';' {
                if(Global::ZCode::codeList.count() > 1 && Global::ZCode::codeList.last()->action != Global::ZCode::PopAll)
                    Global::ZCode::codeList << createCode(Global::ZCode::PopAll);
            }
            | start expression ';' {
                if(Global::ZCode::codeList.count() > 1 && Global::ZCode::codeList.last()->action != Global::ZCode::PopAll)
                    Global::ZCode::codeList << createCode(Global::ZCode::PopAll);
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
                if(undefinedIdentifier->contains(*$1)) {
                    undefinedIdentifier->remove(*$1);
                } else {
                    currentScope->identifiers[*$1] = new Global::ZVariant(constUndefined);
                }

                delete $1;
            }
            | define ',' define
            ;

expression: lvalue | rvalue;

lvalue:     IDENTIFIER {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getIdentifierAddress(*$1));

                delete $1;
            }
            | lvalue '=' expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::Assign);
            }
            | expression '[' expression ']' {
                $$ = ValueType::Variant;
                /// TODO
            }
            | lvalue AEQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::AndAssign);
            }
            | lvalue SEQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::SubAssign);
            }
            | lvalue MEQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::MulAssign);
            }
            | lvalue DEQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::DivAssign);
            }
            | lvalue ANDEQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::AndAssign);
            }
            | lvalue OREQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::OrAssign);
            }
            | lvalue XOREQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::XorAssign);
            }
            | lvalue MODEQ expression {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::ModAssign);
            }
            | ADDSELF lvalue {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PrefixAddSelf);
            }
            | SUBSELF lvalue {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PrefixSubSelf);
            }
            | lvalue ADDSELF {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PostfixAddSelf);
            }
            | lvalue SUBSELF {
                $$ = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PostfixSubSelf);
            }
            ;

rvalue:     UNDEFINED {
                $$ = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(QByteArray(), Global::ZVariant::Null));
            }
            | INT {
                $$ = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::Int));

                delete $1;
            }
            | STRING {
                $$ = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::String));

                delete $1;
            }
            | DOUBLE {
                $$ = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::Double));

                delete $1;
            }
            | BOOL {
                $$ = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$1, Global::ZVariant::Bool));

                delete $1;
            }
            | NEW IDENTIFIER {
                /// TODO
                $$ = ValueType::Constant;
            }
            | expression '(' arguments ')' {
                    $$ = ValueType::Variant;

                    Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(QByteArray::number($3), Global::ZVariant::Int));
                    Global::ZCode::codeList << createCode(Global::ZCode::Call);
            }
            | expression '.' IDENTIFIER {
                    $$ = ValueType::Variant;

                    Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*$3, Global::ZVariant::String));
                    Global::ZCode::codeList << createCode(Global::ZCode::Get);
            }
            | expression '+' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Add);
                    }
            }
            | expression '-' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Sub);
                    }
            }
            | expression '*' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Mul);
                    }
            }
            | expression '/' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Div);
                    }
            }
            | expression '&' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::And);
                    }
            }
            | expression '|' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Or);
                    }
            }
            | expression '^' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Xor);
                    }
            }
            | expression '%' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Mod);
                    }
            }
            | expression EQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::EQ);
                    }
            }
            | expression NEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::NEQ);
                    }
            }
            | expression LE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::LE);
                    }
            }
            | expression GE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::GE);
                    }
            }
            | expression LAND expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::LAnd);
                    }
            }
            | expression LOR expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::LOr);
                    }
            }
            | '~' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(~ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Contrary);
                    }
                }
            | '!' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(! *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Not);
                    }
                }
            | '-' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(- *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Minus);
                    }
                }
            | '+' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(+ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Abs);
                    }
                }
            | '(' expression ')' { $$ = $2;}
            ;

arguments:  expression {$$ = 1;}
            | arguments ',' expression {$$ = $1 + 1;}/* {
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
bool quit = false;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    undefinedIdentifier = new QSet<const QByteArray>();
    scopeList = new QList<Scope*>();
    stringConstantHash = new QHash<const QByteArray, Global::ZVariant*>();
    numberConstantHash = new QHash<const QByteArray, Global::ZVariant*>();
    currentScope = createScope();

    Global::ZVariant *console = new  Global::ZVariant(new Global::ZConsole);
    currentScope->identifiers["console"] = console;

    if(argc > 1) {
        freopen(argv[1], "r", stdin);
    }

    flexLexer = new yyFlexLexer();

    yy::parser parser;

//    parser.set_debug_level(1);

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
    Global::ZVariant *val = Q_NULLPTR;

    while(scope) {
        val = scope->identifiers.value(name);

        if(val)
            return val;

        scope = currentScope->parent;
    }

    if(!val) {
        *undefinedIdentifier << name;

        val = new Global::ZVariant(constUndefined);
    }

    return val;
}

Global::ZVariant *getConstantAddress(const QByteArray &value, Global::ZVariant::Type type)
{
    switch(type) {
    case Global::ZVariant::Int: {
        Global::ZVariant *val = numberConstantHash->value(value);

        if(!val) {
            (*numberConstantHash)[value] = val;
        }

        val = new Global::ZVariant(value.toInt());

        return val;
    }
    case Global::ZVariant::Double: {
        Global::ZVariant *val = numberConstantHash->value(value);

        if(!val) {
            (*numberConstantHash)[value] = val;
        }

        val = new Global::ZVariant(value.toDouble());

        return val;
    }
    case Global::ZVariant::String: {
        Global::ZVariant *val = stringConstantHash->value(value);

        if(!val) {
            (*stringConstantHash)[value] = val;
        }

        val = new Global::ZVariant(QString(value));

        return val;
    }
    case Global::ZVariant::Bool:
        if((bool)value.toInt())
            return &constFalse;
        else
            return &constTrue;
    default:
        return &constUndefined;
    }
}

Global::ZVariant *getConstantAddressByValue(const Global::ZVariant &value)
{
    return getConstantAddress(value.toString().toLatin1(), value.type());
}

Global::ZCode *createCode(const Global::ZCode::Action &action, Global::ZVariant *val)
{
    if(action == Global::ZCode::Push) {
        Global::ValueCode *code = new Global::ValueCode;

        code->action = action;
        code->value = val;

        return code;
    }

    Global::ZCode *code = new Global::ZCode;

    code->action = action;

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
    if(!undefinedIdentifier->isEmpty()) {
        zError << "undefined reference";

        for(const QByteArray &name : *undefinedIdentifier)
            zPrint << name;
    }

    qDeleteAll(*scopeList);

    delete scopeList;
    delete stringConstantHash;
    delete numberConstantHash;
    delete undefinedIdentifier;

    int i = 0;

    QString code_count = QString::number(Global::ZCode::codeList.count());

    for(const Global::ZCode *code : Global::ZCode::codeList) {
        qDebug().noquote() << QString::asprintf(QString("%%1d:").arg(code_count.size()).toLatin1().constData(), ++i) << *code;
    }

    qApp->exit();

    quick_exit(Global::ZCode::exec());
}
