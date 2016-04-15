%{
#include "zcode.h"
#include "base.h"

/// enable debug
#define YYDEBUG 1

#include "lex.yy.cpp"

#include <QCoreApplication>
#include <QtConcurrent/QtConcurrentRun>

#include <fstream>

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

inline ZVariant *getIdentifierAddress(const QByteArray &name);
inline ZVariant *getConstantAddress(const QByteArray &value, ZVariant::Type type);
inline ZVariant *getConstantAddressByValue(const ZVariant &value);
inline ZCode *createCode(const ZCode::Action &action, ZVariant *val = Q_NULLPTR);

struct Scope{
    Scope *parent = Q_NULLPTR;
    QHash<QByteArray, ZVariant*> identifiers;
};

enum ValueType {
    Variant,
    Constant
};

Scope *createScope(Scope *parent = Q_NULLPTR);

Scope *currentScope = Q_NULLPTR;
QSet<const QByteArray> *undefinedIdentifier = Q_NULLPTR;
QList<Scope*> *scopeList = Q_NULLPTR;
QHash<const QByteArray, ZVariant*> *stringConstantHash = Q_NULLPTR;
QHash<const QByteArray, ZVariant*> *numberConstantHash = Q_NULLPTR;
ZVariant constTrue(true);
ZVariant constFalse(false);
ZVariant constUndefined;

Z_USE_NAMESPACE

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
                if(ZCode::codeList.count() > 1 && ZCode::codeList.last()->action != ZCode::PopAll)
                    ZCode::codeList << createCode(ZCode::PopAll);
            }
            | start statement ';' {
                if(ZCode::codeList.count() > 1 && ZCode::codeList.last()->action != ZCode::PopAll)
                    ZCode::codeList << createCode(ZCode::PopAll);
            }
            | start expression ';' {
                if(ZCode::codeList.count() > 1 && ZCode::codeList.last()->action != ZCode::PopAll)
                    ZCode::codeList << createCode(ZCode::PopAll);
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
                    currentScope->identifiers[*$1] = new ZVariant(constUndefined);
                }

                delete $1;
            }
            | define ',' define
            ;

expression: lvalue | rvalue;

lvalue:     IDENTIFIER {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::Push, getIdentifierAddress(*$1));

                delete $1;
            }
            | lvalue '=' expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::Assign);
            }
            | expression '[' expression ']' {
                $$ = ValueType::Variant;
                /// TODO
            }
            | lvalue AEQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::AndAssign);
            }
            | lvalue SEQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::SubAssign);
            }
            | lvalue MEQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::MulAssign);
            }
            | lvalue DEQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::DivAssign);
            }
            | lvalue ANDEQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::AndAssign);
            }
            | lvalue OREQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::OrAssign);
            }
            | lvalue XOREQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::XorAssign);
            }
            | lvalue MODEQ expression {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::ModAssign);
            }
            | ADDSELF lvalue {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PrefixAddSelf);
            }
            | SUBSELF lvalue {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PrefixSubSelf);
            }
            | lvalue ADDSELF {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PostfixAddSelf);
            }
            | lvalue SUBSELF {
                $$ = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PostfixSubSelf);
            }
            ;

rvalue:     UNDEFINED {
                $$ = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(QByteArray(), ZVariant::Null));
            }
            | INT {
                $$ = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*$1, ZVariant::Int));

                delete $1;
            }
            | STRING {
                $$ = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*$1, ZVariant::String));

                delete $1;
            }
            | DOUBLE {
                $$ = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*$1, ZVariant::Double));

                delete $1;
            }
            | BOOL {
                $$ = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*$1, ZVariant::Bool));

                delete $1;
            }
            | NEW IDENTIFIER {
                /// TODO
                $$ = ValueType::Constant;
            }
            | expression '(' arguments ')' {
                    $$ = ValueType::Variant;

                    ZCode::codeList << createCode(ZCode::Push, getConstantAddress(QByteArray::number($3), ZVariant::Int));
                    ZCode::codeList << createCode(ZCode::Call);
            }
            | expression '.' IDENTIFIER {
                    $$ = ValueType::Variant;

                    ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*$3, ZVariant::String));
                    ZCode::codeList << createCode(ZCode::Get);
            }
            | expression '+' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Add);
                    }
            }
            | expression '-' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Sub);
                    }
            }
            | expression '*' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Mul);
                    }
            }
            | expression '/' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Div);
                    }
            }
            | expression '&' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::And);
                    }
            }
            | expression '|' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Or);
                    }
            }
            | expression '^' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Xor);
                    }
            }
            | expression '%' expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Mod);
                    }
            }
            | expression EQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::EQ);
                    }
            }
            | expression NEQ expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::NEQ);
                    }
            }
            | expression LE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::LE);
                    }
            }
            | expression GE expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::GE);
                    }
            }
            | expression LAND expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::LAnd);
                    }
            }
            | expression LOR expression {
                    if($1 == ValueType::Constant && $3 == ValueType::Constant) {
                        $$ = $1;

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::LOr);
                    }
            }
            | '~' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(~ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Contrary);
                    }
                }
            | '!' expression {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(! *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Not);
                    }
                }
            | '-' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(- *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Minus);
                    }
                }
            | '+' expression %prec UMINUS {
                    if($2 == ValueType::Constant) {
                        $$ = $2;

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(+ *last_code->value);
                    } else {
                        $$ = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Abs);
                    }
                }
            | '(' expression ')' { $$ = $2;}
            ;

arguments:  expression {$$ = 1;}
            | arguments ',' expression {$$ = $1 + 1;}/* {
                    if($1->nodeType == Node::Constant
                            && $3->nodeType == Node::Constant) {
                        $$ = new Node(Node::Constant);
                        QList<ZVariant> value;
                        value << *$1->value << *$3->value;
                        $$->value = new ZVariant(value);
                    } else {
                        $$ = new Node(Node::Comma, $1, $3);
                        $$->value = new ZVariant();
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
    stringConstantHash = new QHash<const QByteArray, ZVariant*>();
    numberConstantHash = new QHash<const QByteArray, ZVariant*>();
    currentScope = createScope();

    if(argc > 1) {
        freopen(argv[1], "r", stdin);
    }

    Base::initGlobalIdentifier();

    flexLexer = new yyFlexLexer();

    yy::parser parser;

    parser.set_debug_level(QByteArray(getenv("DEBUG_PARSE_LEVEL")).toInt());

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

ZVariant *getIdentifierAddress(const QByteArray &name)
{
    Scope *scope = currentScope;
    ZVariant *val = Q_NULLPTR;

    while(scope) {
        val = scope->identifiers.value(name);

        if(val)
            return val;

        scope = currentScope->parent;
    }

    if(!val) {
        val = ZCode::globalIdentifierHash.value(name);

        if(!val) {
            *undefinedIdentifier << name;

            val = new ZVariant(constUndefined);
        }
    }

    return val;
}

ZVariant *getConstantAddress(const QByteArray &value, ZVariant::Type type)
{
    switch(type) {
    case ZVariant::Int: {
        ZVariant *val = numberConstantHash->value(value);

        if(!val) {
            (*numberConstantHash)[value] = val;
        }

        val = new ZVariant(value.toInt());

        return val;
    }
    case ZVariant::Double: {
        ZVariant *val = numberConstantHash->value(value);

        if(!val) {
            (*numberConstantHash)[value] = val;
        }

        val = new ZVariant(value.toDouble());

        return val;
    }
    case ZVariant::String: {
        ZVariant *val = stringConstantHash->value(value);

        if(!val) {
            (*stringConstantHash)[value] = val;
        }

        val = new ZVariant(QString(value));

        return val;
    }
    case ZVariant::Bool:
        if((bool)value.toInt())
            return &constFalse;
        else
            return &constTrue;
    default:
        return &constUndefined;
    }
}

ZVariant *getConstantAddressByValue(const ZVariant &value)
{
    return getConstantAddress(value.toString().toLatin1(), value.type());
}

ZCode *createCode(const ZCode::Action &action, ZVariant *val)
{
    if(action == ZCode::Push) {
        ValueCode *code = new ValueCode;

        code->action = action;
        code->value = val;

        return code;
    }

    ZCode *code = new ZCode;

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

    qApp->exit();

    quick_exit(ZCode::exec());
}
