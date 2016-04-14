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


#line 75 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 89 "zScript.tab.cpp" // lalr1.cc:412


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
#line 175 "zScript.tab.cpp" // lalr1.cc:479

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
#line 78 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::codeList << createCode(Global::ZCode::PopAll);
            }
#line 617 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 81 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::codeList << createCode(Global::ZCode::PopAll);
            }
#line 625 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 84 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //currentCode->nodeList << $2;
            }
#line 633 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 90 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
            }
#line 641 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 95 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                undefinedIdentifier->remove(*(yystack_[0].value.identifier));

                delete (yystack_[0].value.identifier);
            }
#line 651 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 105 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::Push, getIdentifierAddress(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 663 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 112 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::Assign);
            }
#line 673 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 117 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 682 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 121 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::AndAssign);
            }
#line 692 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 126 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::SubAssign);
            }
#line 702 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 131 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::MulAssign);
            }
#line 712 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 136 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::DivAssign);
            }
#line 722 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 141 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::AndAssign);
            }
#line 732 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 146 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::OrAssign);
            }
#line 742 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 151 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::XorAssign);
            }
#line 752 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 156 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::ModAssign);
            }
#line 762 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 161 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PrefixAddSelf);
            }
#line 772 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 166 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PrefixSubSelf);
            }
#line 782 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 171 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PostfixAddSelf);
            }
#line 792 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 176 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                Global::codeList << createCode(Global::ZCode::PostfixSubSelf);
            }
#line 802 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 183 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(QByteArray(), Global::ZVariant::Null));
            }
#line 812 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 188 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 824 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 195 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 836 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 202 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 848 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 209 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                Global::codeList << createCode(Global::ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 860 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 216 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 869 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 220 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    Global::codeList << createCode(Global::ZCode::Call);
            }
#line 879 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 225 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    Global::codeList << createCode(Global::ZCode::Get, getConstantAddress(*(yystack_[0].value.identifier), Global::ZVariant::String));
            }
#line 889 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 230 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target + *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Add);
                    }
            }
#line 910 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 246 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target - *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Sub);
                    }
            }
#line 931 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 262 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target * *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Mul);
                    }
            }
#line 952 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 278 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target / *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Div);
                    }
            }
#line 973 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 294 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target & *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::And);
                    }
            }
#line 994 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 310 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target | *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Or);
                    }
            }
#line 1015 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 326 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target ^ *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Xor);
                    }
            }
#line 1036 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 342 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target % *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Mod);
                    }
            }
#line 1057 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 358 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target == *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::EQ);
                    }
            }
#line 1078 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 374 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target != *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::NEQ);
                    }
            }
#line 1099 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 390 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target <= *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::LE);
                    }
            }
#line 1120 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 406 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target >= *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::GE);
                    }
            }
#line 1141 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 422 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target && *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::LAnd);
                    }
            }
#line 1162 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 438 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        Global::ZCode *pre_code = Global::codeList.takeLast();
                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(*pre_code->target || *last_code->target);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::LOr);
                    }
            }
#line 1183 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 454 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(~ *last_code->target);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Contrary);
                    }
                }
#line 1201 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 467 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(! *last_code->target);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Not);
                    }
                }
#line 1219 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 480 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(- *last_code->target);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Minus);
                    }
                }
#line 1237 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 493 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        Global::ZCode *last_code = Global::codeList.last();

                        last_code->target = getConstantAddressByValue(+ *last_code->target);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        Global::codeList << createCode(Global::ZCode::Abs);
                    }
                }
#line 1255 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 506 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1261 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1265 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -66;

  const signed char parser::yytable_ninf_ = -25;

  const short int
  parser::yypact_[] =
  {
     -66,   222,   -66,     2,     4,     9,   -29,   -28,   -27,   -66,
     -66,   -66,   -66,   -66,   288,   288,   288,   288,   288,   288,
     288,    -7,   303,   343,   -66,   266,    39,   -66,    23,     7,
     -66,   288,   288,   288,   725,   808,   822,   -37,   -37,   -37,
     -37,   342,   -66,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   -66,   288,
      51,   -66,   -66,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   -66,   381,   244,     2,     2,   420,   459,   498,
     170,   -66,    40,    40,    93,    93,   757,   757,   773,   773,
     773,   101,   101,   -37,   -37,   -37,   725,   -25,   537,   -66,
     725,   725,   725,   725,   725,   725,   725,   725,   725,    64,
     -66,   -66,   569,    39,   -66,    -9,   -66,   -66,   288,   288,
     288,   -66,   -66,   -66,   118,   -66,    10,   608,   647,   725,
     -66,   -66,   288,   -66,   168,   686,   -66,   -66
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,    27,     1,     0,     0,     0,     0,     0,     0,    12,
      28,    29,    31,    30,    27,    27,    27,    27,    27,    27,
      27,     0,     0,    10,    11,    27,     5,     8,     6,     0,
      32,    27,    27,    27,     0,    10,    10,    51,    52,    50,
      49,     0,     3,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,     4,    27,
       0,    25,    26,    27,    27,    27,    27,    27,    27,    27,
      27,    27,     2,     0,    27,     0,     0,     0,     0,     0,
      10,    53,    43,    44,    45,    46,    47,    48,    39,    40,
      41,    36,    35,    37,    38,    42,    54,     0,     0,    34,
      18,    17,    15,    16,    22,    19,    20,    21,    13,    27,
      61,     2,     0,    62,     9,     0,    56,    57,    27,    27,
      27,    33,    14,    60,    27,    64,     0,     0,     0,    55,
      63,     2,    27,    59,    27,     0,     7,    58
  };

  const signed char
  parser::yypgoto_[] =
  {
     -66,   -65,   -66,   -63,   -14,    -6,   -66,   -66,   -66,   -10
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    21,    28,    22,    23,    24,    97,    25,    26
  };

  const short int
  parser::yytable_[] =
  {
      34,    34,    37,    38,    39,    40,    41,   109,    35,    36,
     120,    73,   114,   115,    27,    57,    29,    77,    78,    79,
      59,    30,    60,    31,    32,    33,    75,    80,   121,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   126,    98,   124,    42,    74,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    75,    76,
     112,    45,    46,    99,   113,   131,   134,     3,     4,     5,
       0,     0,     6,     0,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,    52,    53,    54,    55,    56,    14,
      15,     0,    57,     0,     0,     0,     0,    59,     0,    60,
       0,     0,     0,     0,   127,   128,   129,     0,    16,    17,
       0,     0,     0,     0,    18,    19,    20,     0,   135,     0,
     123,     3,     4,     5,     0,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,     0,     0,    52,    53,    54,
      55,    56,     0,    14,    15,    57,     0,    54,    55,    56,
      59,     0,    60,    57,     0,     0,     0,     0,    59,     0,
      60,     0,    16,    17,     0,     0,     0,     0,    18,    19,
      20,     3,     4,     5,   130,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,     0,   119,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,    19,
      20,     0,     2,     0,   136,     3,     4,     5,     0,     0,
       6,     0,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     5,
       0,     0,     6,     0,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,    16,    17,     0,    14,
      15,     5,    18,    19,    20,     0,     0,     0,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,    16,    17,
       0,    14,    15,     5,    18,    19,    20,     0,     0,   111,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
      16,    17,     0,    14,    15,     0,    18,    19,    20,     0,
      43,    72,    44,     0,    45,    46,    47,    48,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,    19,
      20,     0,    49,    50,    51,     0,     0,    52,    53,    54,
      55,    56,     0,     0,     0,    57,     0,    58,     0,    43,
      59,    44,    60,    45,    46,    47,    48,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
       0,    49,    50,    51,     0,     0,    52,    53,    54,    55,
      56,     0,     0,     0,    57,    81,     0,     0,    43,    59,
      44,    60,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,    50,    51,     0,     0,    52,    53,    54,    55,    56,
       0,     0,     0,    57,     0,   110,     0,    43,    59,    44,
      60,    45,    46,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      50,    51,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,    57,   116,     0,     0,    43,    59,    44,    60,
      45,    46,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      51,     0,     0,    52,    53,    54,    55,    56,     0,     0,
       0,    57,   117,     0,     0,    43,    59,    44,    60,    45,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,    51,
       0,     0,    52,    53,    54,    55,    56,     0,     0,     0,
      57,     0,   118,     0,    43,    59,    44,    60,    45,    46,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    50,    51,     0,
       0,    52,    53,    54,    55,    56,    43,     0,    44,    57,
      45,    46,    47,    48,    59,   122,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
      51,     0,     0,    52,    53,    54,    55,    56,     0,     0,
       0,    57,     0,   125,     0,    43,    59,    44,    60,    45,
      46,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,    51,
       0,     0,    52,    53,    54,    55,    56,     0,     0,     0,
      57,     0,   132,     0,    43,    59,    44,    60,    45,    46,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    50,    51,     0,
       0,    52,    53,    54,    55,    56,     0,     0,     0,    57,
     133,     0,     0,    43,    59,    44,    60,    45,    46,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,    50,    51,     0,     0,
      52,    53,    54,    55,    56,     0,     0,     0,    57,   137,
       0,     0,    43,    59,    44,    60,    45,    46,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    51,     0,     0,    52,
      53,    54,    55,    56,    43,     0,    44,    57,    45,    46,
       0,     0,    59,     0,    60,     0,     0,     0,     0,     0,
      43,     0,    44,     0,    45,    46,    49,    50,    51,     0,
       0,    52,    53,    54,    55,    56,     0,     0,     0,    57,
       0,     0,     0,     0,    59,     0,    60,    52,    53,    54,
      55,    56,     0,     0,     0,    57,     0,     0,     0,     0,
      59,     0,    60,    61,    62,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   -23,    61,    62,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,
     -24,   -23,   -23,     0,     0,     0,   -23,     0,     0,     0,
       0,     0,     0,     0,     0,   -24,   -24,     0,     0,     0,
     -24
  };

  const short int
  parser::yycheck_[] =
  {
      14,    15,    16,    17,    18,    19,    20,    72,    14,    15,
      35,    25,    75,    76,    12,    52,    12,    31,    32,    33,
      57,    12,    59,    52,    52,    52,    35,    33,    53,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    53,    59,   111,    54,     9,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    35,    52,
      74,    21,    22,    12,    74,    55,   131,     3,     4,     5,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    44,    45,    46,    47,    48,    25,
      26,    -1,    52,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    -1,    -1,   118,   119,   120,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    -1,   132,    -1,
      56,     3,     4,     5,    -1,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    44,    45,    46,
      47,    48,    -1,    25,    26,    52,    -1,    46,    47,    48,
      57,    -1,    59,    52,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,     3,     4,     5,    56,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    38,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,     0,    -1,    56,     3,     4,     5,    -1,    -1,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,     5,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    25,
      26,     5,    50,    51,    52,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    25,    26,     5,    50,    51,    52,    -1,    -1,    55,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    25,    26,    -1,    50,    51,    52,    -1,
      17,    55,    19,    -1,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    -1,    39,    40,    41,    -1,    -1,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    54,    -1,    17,
      57,    19,    59,    21,    22,    23,    24,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      -1,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    52,    53,    -1,    -1,    17,    57,
      19,    59,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    52,    -1,    54,    -1,    17,    57,    19,
      59,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    -1,    -1,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    52,    53,    -1,    -1,    17,    57,    19,    59,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    52,    53,    -1,    -1,    17,    57,    19,    59,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      52,    -1,    54,    -1,    17,    57,    19,    59,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    17,    -1,    19,    52,
      21,    22,    23,    24,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,
      -1,    52,    -1,    54,    -1,    17,    57,    19,    59,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      52,    -1,    54,    -1,    17,    57,    19,    59,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,    52,
      53,    -1,    -1,    17,    57,    19,    59,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    52,    53,
      -1,    -1,    17,    57,    19,    59,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    17,    -1,    19,    52,    21,    22,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    -1,    21,    22,    39,    40,    41,    -1,
      -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    57,    -1,    59,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      57,    -1,    59,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    53,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,
      58
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    61,     0,     3,     4,     5,     8,    10,    11,    12,
      13,    14,    15,    16,    25,    26,    44,    45,    50,    51,
      52,    62,    64,    65,    66,    68,    69,    12,    63,    12,
      12,    52,    52,    52,    64,    65,    65,    64,    64,    64,
      64,    64,    54,    17,    19,    21,    22,    23,    24,    39,
      40,    41,    44,    45,    46,    47,    48,    52,    54,    57,
      59,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    36,    55,    64,     9,    35,    52,    64,    64,    64,
      65,    53,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    67,    64,    12,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    61,
      54,    55,    64,    69,    63,    63,    53,    53,    54,    38,
      35,    53,    58,    56,    61,    54,    53,    64,    64,    64,
      56,    55,    54,    53,    61,    64,    56,    53
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    60,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    69,    69,    69
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     3,     3,     2,     2,     8,     1,     3,
       1,     1,     1,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     0,     1,     1,
       1,     1,     2,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     1,     3,     4,     4,     8,     6,
       4,     3,     3,     5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "IDENTIFIER", "INT", "STRING",
  "BOOL", "DOUBLE", "EQ", "STEQ", "NEQ", "STNEQ", "LE", "GE", "LAND",
  "LOR", "ADDSELF", "SUBSELF", "DEQ", "MEQ", "AEQ", "SEQ", "MODEQ",
  "ANDEQ", "OREQ", "XOREQ", "','", "'='", "'?'", "':'", "'&'", "'|'",
  "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'", "'%'", "UMINUS", "'!'",
  "'~'", "'('", "')'", "';'", "'{'", "'}'", "'['", "']'", "'.'", "$accept",
  "start", "statement", "define", "expression", "lvalue", "rvalue",
  "arguments", "branch_head", "conditional", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    77,    77,    78,    81,    84,    89,    90,    95,   100,
     103,   103,   105,   112,   117,   121,   126,   131,   136,   141,
     146,   151,   156,   161,   166,   171,   176,   183,   188,   195,
     202,   209,   216,   220,   225,   230,   246,   262,   278,   294,
     310,   326,   342,   358,   374,   390,   406,   422,   438,   454,
     467,   480,   493,   506,   509,   510,   524,   525,   526,   527,
     529,   530,   531,   532,   533
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
       2,     2,     2,    50,     2,     2,     2,    48,    39,     2,
      52,    53,    46,    45,    35,    44,    59,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    38,    54,
      43,    36,    42,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,    40,    56,    51,     2,     2,     2,
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
      49
    };
    const unsigned int user_token_number_max_ = 290;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1829 "zScript.tab.cpp" // lalr1.cc:1167
#line 536 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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

    int i = 0;

    QString code_count = QString::number(Global::codeList.count());

    for(const Global::ZCode *code : Global::codeList) {
        qDebug().noquote() << QString::asprintf(QString("%%1d:").arg(code_count.size()).toLatin1().constData(), ++i) << *code;
    }

    return 0;
}
