// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 1 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:404

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


#line 79 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 93 "zScript.tab.cpp" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 179 "zScript.tab.cpp" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 83 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {YYABORT;zDebug << "quit";}
#line 619 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 85 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //Global::ZCode::codeList << createCode(Global::ZCode::PopAll);
            }
#line 627 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 88 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::ZCode::codeList << createCode(Global::ZCode::PopAll);
            }
#line 635 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 91 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //currentCode->nodeList << $2;
            }
#line 643 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 97 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
            }
#line 651 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 102 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(undefinedIdentifier->contains(*(yystack_[0].value.identifier))) {
                    undefinedIdentifier->remove(*(yystack_[0].value.identifier));
                } else {
                    currentScope->identifiers[*(yystack_[0].value.identifier)] = new Global::ZVariant(constUndefined);
                }

                delete (yystack_[0].value.identifier);
            }
#line 665 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 116 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getIdentifierAddress(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 677 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 123 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::Assign);
            }
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 128 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 696 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 132 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::AndAssign);
            }
#line 706 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 137 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::SubAssign);
            }
#line 716 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 142 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::MulAssign);
            }
#line 726 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 147 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::DivAssign);
            }
#line 736 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 152 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::AndAssign);
            }
#line 746 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 157 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::OrAssign);
            }
#line 756 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 162 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::XorAssign);
            }
#line 766 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 167 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::ModAssign);
            }
#line 776 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 172 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PrefixAddSelf);
            }
#line 786 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 177 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PrefixSubSelf);
            }
#line 796 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 182 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PostfixAddSelf);
            }
#line 806 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 187 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::ZCode::codeList << createCode(Global::ZCode::PostfixSubSelf);
            }
#line 816 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 194 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(QByteArray(), Global::ZVariant::Null));
            }
#line 826 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 199 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 838 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 206 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 850 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 213 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 862 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 220 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::ZCode::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 874 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 227 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 883 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 231 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    Global::ZCode::codeList << createCode(Global::ZCode::Call);
            }
#line 893 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 236 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    Global::ZCode::codeList << createCode(Global::ZCode::Get, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::String));
            }
#line 903 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 241 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Add);
                    }
            }
#line 924 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 257 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Sub);
                    }
            }
#line 945 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 273 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Mul);
                    }
            }
#line 966 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 289 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Div);
                    }
            }
#line 987 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 305 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::And);
                    }
            }
#line 1008 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 321 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Or);
                    }
            }
#line 1029 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 337 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Xor);
                    }
            }
#line 1050 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 353 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Mod);
                    }
            }
#line 1071 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 369 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::EQ);
                    }
            }
#line 1092 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 385 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::NEQ);
                    }
            }
#line 1113 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 401 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::LE);
                    }
            }
#line 1134 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 417 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::GE);
                    }
            }
#line 1155 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 433 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::LAnd);
                    }
            }
#line 1176 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 449 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ValueCode *pre_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.takeLast());
                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::LOr);
                    }
            }
#line 1197 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 465 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(~ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Contrary);
                    }
                }
#line 1215 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 478 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(! *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Not);
                    }
                }
#line 1233 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 491 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(- *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Minus);
                    }
                }
#line 1251 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 504 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ValueCode *last_code = static_cast<Global::ValueCode*>(Global::ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(+ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::ZCode::codeList << createCode(Global::ZCode::Abs);
                    }
                }
#line 1269 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 517 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1275 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1279 "zScript.tab.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -68;

  const signed char parser::yytable_ninf_ = -27;

  const short int
  parser::yypact_[] =
  {
       8,   -68,    64,   -68,    10,    34,    35,     5,     6,    11,
     -68,   -68,   -68,   -68,   -68,   -68,   311,   311,   311,   311,
     311,   311,   311,   -68,    15,   347,   174,   -68,   295,    56,
     -68,    37,    18,   -68,   311,   311,   311,   769,   852,   866,
      36,    36,    36,    36,   386,   -68,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   -68,   311,    69,   -68,   -68,   311,   311,   311,   311,
     311,   311,   311,   311,   311,     8,   425,   250,    10,    10,
     464,   503,   542,   119,   -68,    39,    39,   -33,   -33,   801,
     801,   817,   817,   817,    54,    54,    36,    36,    36,   769,
     -30,   581,   -68,   769,   769,   769,   769,   769,   769,   769,
     769,   769,   117,   -68,     8,   613,    56,   -68,   -10,   -68,
     -68,   311,   311,   311,   -68,   -68,   -68,   172,   -68,    27,
     652,   691,   769,   -68,     8,   311,   -68,   227,   730,   -68,
     -68
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     3,     0,     1,     0,     0,     0,     0,     0,     0,
      29,    14,    30,    31,    33,    32,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,    12,    13,     0,     7,
      10,     8,     0,    34,     0,     0,     0,     0,    12,    12,
      53,    54,    52,    51,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,    27,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,    12,    55,    45,    46,    47,    48,    49,
      50,    41,    42,    43,    38,    37,    39,    40,    44,    56,
       0,     0,    36,    20,    19,    17,    18,    24,    21,    22,
      23,    15,     0,    63,     2,     0,    64,    11,     0,    58,
      59,     0,     0,     0,    35,    16,    62,     0,    66,     0,
       0,     0,    57,    65,     2,     0,    61,     0,     0,     9,
      60
  };

  const signed char
  parser::yypgoto_[] =
  {
     -68,   -67,   -68,   -56,   -16,    -7,   -68,   -68,   -68,    17
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,    24,    31,    25,    26,    27,   100,    28,    29
  };

  const short int
  parser::yytable_[] =
  {
      37,    37,    40,    41,    42,    43,    44,   123,   112,    38,
      39,     1,    76,    55,    56,    57,    58,    59,    80,    81,
      82,    60,   117,   118,    30,   124,    62,    78,    63,    83,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   129,   101,   127,    32,    33,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    34,
      35,   115,    48,    49,     3,    36,    77,   137,     4,     5,
       6,    45,    79,     7,    78,     8,     9,    10,    11,    12,
      13,    14,    15,   102,   134,    55,    56,    57,    58,    59,
      60,    16,    17,    60,   116,    62,     0,    63,    62,     0,
      63,     0,    57,    58,    59,   130,   131,   132,    60,     0,
      18,    19,     0,    62,     0,    63,    20,    21,    22,   138,
      23,     4,     5,     6,     0,     0,     7,     0,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,    74,     0,   122,
       0,     0,     0,    18,    19,     0,     0,     0,     0,    20,
      21,    22,     0,    23,     0,   126,     4,     5,     6,     0,
       0,     7,     0,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    74,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,    20,    21,    22,     0,    23,     0,
     133,     4,     5,     6,     0,     0,     7,     0,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     6,     0,     0,     7,
       0,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    18,    19,     0,     0,    16,    17,    20,
      21,    22,     0,    23,     0,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,     0,     0,
       0,     6,    20,    21,    22,     0,     0,   114,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     6,     0,     0,
       0,     0,    16,    17,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    18,    19,     0,     0,     0,     0,    20,    21,    22,
       0,     0,    75,     0,     0,     0,     0,    18,    19,     0,
       0,     0,     0,    20,    21,    22,    46,     0,    47,     0,
      48,    49,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    53,
      54,     0,     0,    55,    56,    57,    58,    59,     0,     0,
       0,    60,     0,    61,     0,    46,    62,    47,    63,    48,
      49,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    53,    54,
       0,     0,    55,    56,    57,    58,    59,     0,     0,     0,
      60,    84,     0,     0,    46,    62,    47,    63,    48,    49,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    53,    54,     0,
       0,    55,    56,    57,    58,    59,     0,     0,     0,    60,
       0,   113,     0,    46,    62,    47,    63,    48,    49,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,     0,     0,
      55,    56,    57,    58,    59,     0,     0,     0,    60,   119,
       0,     0,    46,    62,    47,    63,    48,    49,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,     0,    55,
      56,    57,    58,    59,     0,     0,     0,    60,   120,     0,
       0,    46,    62,    47,    63,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     0,     0,    55,    56,
      57,    58,    59,     0,     0,     0,    60,     0,   121,     0,
      46,    62,    47,    63,    48,    49,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     0,    55,    56,    57,
      58,    59,    46,     0,    47,    60,    48,    49,    50,    51,
      62,   125,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,     0,     0,    55,
      56,    57,    58,    59,     0,     0,     0,    60,     0,   128,
       0,    46,    62,    47,    63,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    53,    54,     0,     0,    55,    56,
      57,    58,    59,     0,     0,     0,    60,     0,   135,     0,
      46,    62,    47,    63,    48,    49,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,    54,     0,     0,    55,    56,    57,
      58,    59,     0,     0,     0,    60,   136,     0,     0,    46,
      62,    47,    63,    48,    49,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,     0,    55,    56,    57,    58,
      59,     0,     0,     0,    60,   140,     0,     0,    46,    62,
      47,    63,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,     0,     0,    55,    56,    57,    58,    59,
      46,     0,    47,    60,    48,    49,     0,     0,    62,     0,
      63,     0,     0,     0,     0,     0,    46,     0,    47,     0,
      48,    49,    52,    53,    54,     0,     0,    55,    56,    57,
      58,    59,     0,     0,     0,    60,     0,     0,     0,     0,
      62,     0,    63,    55,    56,    57,    58,    59,     0,     0,
       0,    60,     0,     0,     0,     0,    62,     0,    63,    64,
      65,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,     0,   -25,    64,    65,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -25,   -25,     0,
       0,     0,   -25,     0,     0,     0,     0,     0,     0,     0,
       0,   -26,   -26,     0,     0,     0,   -26
  };

  const short int
  parser::yycheck_[] =
  {
      16,    17,    18,    19,    20,    21,    22,    37,    75,    16,
      17,     3,    28,    46,    47,    48,    49,    50,    34,    35,
      36,    54,    78,    79,    14,    55,    59,    37,    61,    36,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    55,    62,   114,    14,    14,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    54,
      54,    77,    23,    24,     0,    54,    10,   134,     4,     5,
       6,    56,    54,     9,    37,    11,    12,    13,    14,    15,
      16,    17,    18,    14,    57,    46,    47,    48,    49,    50,
      54,    27,    28,    54,    77,    59,    -1,    61,    59,    -1,
      61,    -1,    48,    49,    50,   121,   122,   123,    54,    -1,
      46,    47,    -1,    59,    -1,    61,    52,    53,    54,   135,
      56,     4,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    38,    -1,    40,
      -1,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    54,    -1,    56,    -1,    58,     4,     5,     6,    -1,
      -1,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    -1,    56,    -1,
      58,     4,     5,     6,    -1,    -1,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,     6,    -1,    -1,     9,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    27,    28,    52,
      53,    54,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    -1,
      -1,     6,    52,    53,    54,    -1,    -1,    57,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    27,    28,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    46,    47,    -1,    -1,    -1,    -1,    52,    53,    54,
      -1,    -1,    57,    -1,    -1,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    52,    53,    54,    19,    -1,    21,    -1,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    56,    -1,    19,    59,    21,    61,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      54,    55,    -1,    -1,    19,    59,    21,    61,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    -1,    -1,    54,
      -1,    56,    -1,    19,    59,    21,    61,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    54,    55,
      -1,    -1,    19,    59,    21,    61,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    54,    55,    -1,
      -1,    19,    59,    21,    61,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      19,    59,    21,    61,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    19,    -1,    21,    54,    23,    24,    25,    26,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    54,    -1,    56,
      -1,    19,    59,    21,    61,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    54,    -1,    56,    -1,
      19,    59,    21,    61,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    55,    -1,    -1,    19,
      59,    21,    61,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    54,    55,    -1,    -1,    19,    59,
      21,    61,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    -1,    -1,    46,    47,    48,    49,    50,
      19,    -1,    21,    54,    23,    24,    -1,    -1,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,
      23,    24,    41,    42,    43,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      59,    -1,    61,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    59,    -1,    61,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    -1,    40,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    55,    56,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,    63,     0,     4,     5,     6,     9,    11,    12,
      13,    14,    15,    16,    17,    18,    27,    28,    46,    47,
      52,    53,    54,    56,    64,    66,    67,    68,    70,    71,
      14,    65,    14,    14,    54,    54,    54,    66,    67,    67,
      66,    66,    66,    66,    66,    56,    19,    21,    23,    24,
      25,    26,    41,    42,    43,    46,    47,    48,    49,    50,
      54,    56,    59,    61,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    38,    57,    66,    10,    37,    54,
      66,    66,    66,    67,    55,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      69,    66,    14,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    63,    56,    57,    66,    71,    65,    65,    55,
      55,    56,    40,    37,    55,    60,    58,    63,    56,    55,
      66,    66,    66,    58,    57,    56,    55,    63,    66,    58,
      55
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    62,    63,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    71,    71,    71,    71,    71
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     2,     3,     3,     2,     2,     8,
       1,     3,     1,     1,     1,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     1,     3,     4,     4,
       8,     6,     4,     3,     3,     5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "QUIT", "VAR", "FUNCTION", "NEW",
  "DELETE", "THROW", "IF", "ELSE", "WHILE", "FOR", "UNDEFINED",
  "IDENTIFIER", "INT", "STRING", "BOOL", "DOUBLE", "EQ", "STEQ", "NEQ",
  "STNEQ", "LE", "GE", "LAND", "LOR", "ADDSELF", "SUBSELF", "DEQ", "MEQ",
  "AEQ", "SEQ", "MODEQ", "ANDEQ", "OREQ", "XOREQ", "','", "'='", "'?'",
  "':'", "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "UMINUS", "'!'", "'~'", "'('", "')'", "';'", "'{'", "'}'", "'['",
  "']'", "'.'", "$accept", "start", "statement", "define", "expression",
  "lvalue", "rvalue", "arguments", "branch_head", "conditional", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    83,    83,    83,    84,    85,    88,    91,    96,    97,
     102,   111,   114,   114,   116,   123,   128,   132,   137,   142,
     147,   152,   157,   162,   167,   172,   177,   182,   187,   194,
     199,   206,   213,   220,   227,   231,   236,   241,   257,   273,
     289,   305,   321,   337,   353,   369,   385,   401,   417,   433,
     449,   465,   478,   491,   504,   517,   520,   521,   535,   536,
     537,   538,   540,   541,   542,   543,   544
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    50,    41,     2,
      54,    55,    48,    47,    37,    46,    61,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    56,
      45,    38,    44,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    42,    58,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    51
    };
    const unsigned int user_token_number_max_ = 292;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1854 "zScript.tab.cpp" // lalr1.cc:1167
#line 547 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
    if(quit)
        return yy::parser::token::yytokentype::QUIT;

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
