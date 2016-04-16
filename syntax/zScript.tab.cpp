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


#line 82 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 96 "zScript.tab.cpp" // lalr1.cc:412


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
#line 182 "zScript.tab.cpp" // lalr1.cc:479

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
#line 87 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCode::codeList.count() > 1 && ZCode::codeList.last()->action != ZCode::PopAll)
                    ZCode::codeList << createCode(ZCode::PopAll);
            }
#line 625 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 91 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCode::codeList.count() > 1 && ZCode::codeList.last()->action != ZCode::PopAll)
                    ZCode::codeList << createCode(ZCode::PopAll);
            }
#line 634 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 95 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCode::codeList.count() > 1 && ZCode::codeList.last()->action != ZCode::PopAll)
                    ZCode::codeList << createCode(ZCode::PopAll);
            }
#line 643 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 99 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //currentCode->nodeList << $2;
            }
#line 651 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 105 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
            }
#line 659 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 110 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(undefinedIdentifier->contains(*(yystack_[0].value.identifier))) {
                    undefinedIdentifier->remove(*(yystack_[0].value.identifier));
                } else {
                    currentScope->identifiers[*(yystack_[0].value.identifier)] = new ZVariant(constUndefined);
                }

                delete (yystack_[0].value.identifier);
            }
#line 673 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 119 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(undefinedIdentifier->contains(*(yystack_[2].value.identifier))) {
                    undefinedIdentifier->remove(*(yystack_[2].value.identifier));
                } else {
                    currentScope->identifiers[*(yystack_[2].value.identifier)] = new ZVariant(constUndefined);
                }

                ZCode::codeList << createCode(ZCode::Push, getIdentifierAddress(*(yystack_[2].value.identifier)));
                ZCode::codeList << createCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 690 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 136 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::Push, getIdentifierAddress(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 702 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 143 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::LeftAssign);
            }
#line 712 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 148 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 721 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 152 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::AddAssign);
            }
#line 731 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 157 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::SubAssign);
            }
#line 741 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 162 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::MulAssign);
            }
#line 751 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 167 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::DivAssign);
            }
#line 761 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 172 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::AndAssign);
            }
#line 771 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 177 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::OrAssign);
            }
#line 781 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 182 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::XorAssign);
            }
#line 791 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 187 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::ModAssign);
            }
#line 801 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 192 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::LOrAssign);
            }
#line 811 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 197 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::LAndAssign);
            }
#line 821 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 202 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PrefixAddSelf);
            }
#line 831 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 207 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PrefixSubSelf);
            }
#line 841 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 214 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(QByteArray(), ZVariant::Null));
            }
#line 851 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 219 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 863 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 226 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 875 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 233 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 887 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 240 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 899 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 247 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 908 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 251 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCode::codeList << createCode(ZCode::Push, getConstantAddress(QByteArray::number((yystack_[1].value.argsCount)), ZVariant::Int));
                    ZCode::codeList << createCode(ZCode::Call);
            }
#line 919 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 257 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCode::codeList << createCode(ZCode::Push, getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));
                    ZCode::codeList << createCode(ZCode::Get);
            }
#line 930 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 263 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Add);
                    }
            }
#line 951 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 279 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Sub);
                    }
            }
#line 972 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 295 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Mul);
                    }
            }
#line 993 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 311 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Div);
                    }
            }
#line 1014 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 327 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::And);
                    }
            }
#line 1035 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 343 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Or);
                    }
            }
#line 1056 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 359 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Xor);
                    }
            }
#line 1077 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 375 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Mod);
                    }
            }
#line 1098 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 391 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::EQ);
                    }
            }
#line 1119 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 407 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::NEQ);
                    }
            }
#line 1140 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 423 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::LE);
                    }
            }
#line 1161 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 439 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::GE);
                    }
            }
#line 1182 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 455 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::LAnd);
                    }
            }
#line 1203 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 471 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCode::codeList.takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::LOr);
                    }
            }
#line 1224 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 487 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(~ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Contrary);
                    }
                }
#line 1242 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 500 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(! *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Not);
                    }
                }
#line 1260 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 513 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(- *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Minus);
                    }
                }
#line 1278 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 526 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCode::codeList.last());

                        last_code->value = getConstantAddressByValue(+ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCode::codeList << createCode(ZCode::Abs);
                    }
                }
#line 1296 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 539 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1302 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 540 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PostfixAddSelf);
            }
#line 1312 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 545 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCode::codeList << createCode(ZCode::PostfixSubSelf);
            }
#line 1322 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 552 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = 1;}
#line 1328 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 553 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = (yystack_[2].value.argsCount) + 1;}
#line 1334 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1338 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -70;

  const signed char parser::yytable_ninf_ = -29;

  const short int
  parser::yypact_[] =
  {
     -70,    69,   -70,     3,     8,     9,   -32,   -31,   -30,   -70,
     -70,   -70,   -70,   -70,   -70,   292,   292,   292,   292,   292,
     292,   292,   -70,   -10,   330,   331,   -70,   276,    17,    22,
      10,     7,   -70,   292,   292,   292,   774,   861,   897,   -45,
     -45,   -45,   -45,   371,   -70,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     -70,   292,    54,   -70,   -70,   292,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   -70,   412,   229,   292,
       3,     3,   453,   494,   535,   933,   -70,    43,    43,    59,
      59,   808,   808,   824,   824,   824,   138,   138,   -45,   -45,
     -45,   774,   -27,   576,   -70,   774,   774,   774,   774,   774,
     774,   774,   774,   774,   774,   774,   124,   -70,   -70,   610,
      17,   774,   -70,   -11,   -70,   -70,   292,   292,   292,   -70,
     -70,   -70,   149,   -70,    13,   651,   692,   774,   -70,   -70,
     292,   -70,   206,   733,   -70,   -70
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     0,     0,     0,    29,
      14,    30,    31,    33,    32,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,    12,    13,     0,     6,     9,
       7,     0,    34,     0,     0,     0,     0,    12,    12,    53,
      54,    52,    51,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    55,    45,    46,    47,
      48,    49,    50,    41,    42,    43,    38,    37,    39,    40,
      44,    58,     0,     0,    36,    20,    19,    17,    18,    24,
      21,    22,    23,    26,    25,    15,     0,    65,     2,     0,
      66,    10,    11,     0,    60,    61,     0,     0,     0,    35,
      16,    64,     0,    68,     0,     0,     0,    59,    67,     2,
       0,    63,     0,     0,     8,    62
  };

  const signed char
  parser::yypgoto_[] =
  {
     -70,   -69,   -70,   -67,   -15,    -7,   -70,   -70,   -70,    -3
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    23,    30,    24,    25,    26,   102,    27,    28
  };

  const short int
  parser::yytable_[] =
  {
      36,    36,    39,    40,    41,    42,    43,   116,    37,    38,
      59,   128,    77,   122,   123,    61,    29,    62,    82,    83,
      84,    31,    32,    33,    34,    35,    78,    80,    85,   129,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   134,   103,    44,    80,   132,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    79,    81,   119,   121,    47,    48,   104,     0,     2,
     142,   139,     3,     4,     5,   120,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
      54,    55,    56,    57,    58,    15,    16,     0,    59,     0,
       0,     0,     0,    61,     0,    62,    54,    55,    56,    57,
      58,   135,   136,   137,    59,     0,    17,    18,     0,    61,
       0,    62,    19,    20,    21,   143,    22,     3,     4,     5,
       0,     0,     6,     0,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,     3,     4,     5,     0,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,    17,    18,     0,     0,    15,    16,    19,    20,    21,
       0,    22,     0,   131,     0,     0,     0,    56,    57,    58,
       0,     0,     0,    59,     0,     0,    17,    18,    61,     0,
      62,     0,    19,    20,    21,     0,    22,     0,   138,     3,
       4,     5,     0,     0,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,     5,     0,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,    17,    18,    15,    16,     0,     0,    19,
      20,    21,     0,    22,     0,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     5,    19,    20,    21,     0,     0,   118,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     5,     0,     0,
       0,     0,    15,    16,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
       0,     0,     0,    17,    18,     0,     0,     0,     0,    19,
      20,    21,     0,     0,    76,     0,     0,     0,     0,    17,
      18,     0,     0,     0,     0,    19,    20,    21,    45,     0,
      46,     0,    47,    48,    49,    50,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      75,     0,    51,    52,    53,     0,     0,    54,    55,    56,
      57,    58,     0,     0,     0,    59,     0,    60,     0,    45,
      61,    46,    62,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,    53,     0,     0,    54,    55,
      56,    57,    58,     0,     0,     0,    59,    86,     0,     0,
      45,    61,    46,    62,    47,    48,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,     0,     0,    54,
      55,    56,    57,    58,     0,     0,     0,    59,     0,   117,
       0,    45,    61,    46,    62,    47,    48,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,    53,     0,     0,
      54,    55,    56,    57,    58,     0,     0,     0,    59,   124,
       0,     0,    45,    61,    46,    62,    47,    48,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,     0,
       0,    54,    55,    56,    57,    58,     0,     0,     0,    59,
     125,     0,     0,    45,    61,    46,    62,    47,    48,    49,
      50,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    52,    53,
       0,     0,    54,    55,    56,    57,    58,     0,     0,     0,
      59,     0,   126,     0,    45,    61,    46,    62,    47,    48,
      49,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    52,
      53,     0,     0,    54,    55,    56,    57,    58,    45,     0,
      46,    59,    47,    48,    49,    50,    61,   130,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    53,     0,     0,    54,    55,    56,
      57,    58,     0,     0,     0,    59,     0,   133,     0,    45,
      61,    46,    62,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    52,    53,     0,     0,    54,    55,
      56,    57,    58,     0,     0,     0,    59,     0,   140,     0,
      45,    61,    46,    62,    47,    48,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    52,    53,     0,     0,    54,
      55,    56,    57,    58,     0,     0,     0,    59,   141,     0,
       0,    45,    61,    46,    62,    47,    48,    49,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    52,    53,     0,     0,
      54,    55,    56,    57,    58,     0,     0,     0,    59,   145,
       0,     0,    45,    61,    46,    62,    47,    48,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,     0,
       0,    54,    55,    56,    57,    58,    45,     0,    46,    59,
      47,    48,     0,     0,    61,     0,    62,     0,     0,     0,
       0,     0,    45,     0,    46,     0,    47,    48,     0,     0,
      51,    52,    53,     0,     0,    54,    55,    56,    57,    58,
       0,     0,     0,    59,     0,     0,     0,     0,    61,     0,
      62,    54,    55,    56,    57,    58,     0,     0,     0,    59,
       0,     0,     0,     0,    61,     0,    62,    63,    64,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,     0,   -27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -27,   -27,     0,
       0,     0,   -27,    63,    64,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -28,   -28,     0,     0,     0,   -28,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,    75,     0,   127
  };

  const short int
  parser::yycheck_[] =
  {
      15,    16,    17,    18,    19,    20,    21,    76,    15,    16,
      55,    38,    27,    80,    81,    60,    13,    62,    33,    34,
      35,    13,    13,    55,    55,    55,     9,    38,    35,    56,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    56,    61,    57,    38,   118,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    39,    55,    78,    79,    22,    23,    13,    -1,     0,
     139,    58,     3,     4,     5,    78,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    26,    27,    -1,    55,    -1,
      -1,    -1,    -1,    60,    -1,    62,    47,    48,    49,    50,
      51,   126,   127,   128,    55,    -1,    47,    48,    -1,    60,
      -1,    62,    53,    54,    55,   140,    57,     3,     4,     5,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,     3,     4,     5,    -1,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    26,    27,    53,    54,    55,
      -1,    57,    -1,    59,    -1,    -1,    -1,    49,    50,    51,
      -1,    -1,    -1,    55,    -1,    -1,    47,    48,    60,    -1,
      62,    -1,    53,    54,    55,    -1,    57,    -1,    59,     3,
       4,     5,    -1,    -1,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,     5,    -1,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    26,    27,    -1,    -1,    53,
      54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,     5,    53,    54,    55,    -1,    -1,    58,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    26,    27,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    18,    -1,
      20,    -1,    22,    23,    24,    25,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      39,    -1,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    -1,    57,    -1,    18,
      60,    20,    62,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    56,    -1,    -1,
      18,    60,    20,    62,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    55,    -1,    57,
      -1,    18,    60,    20,    62,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    55,    56,
      -1,    -1,    18,    60,    20,    62,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    -1,    -1,    -1,    55,
      56,    -1,    -1,    18,    60,    20,    62,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      55,    -1,    57,    -1,    18,    60,    20,    62,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    -1,    -1,    47,    48,    49,    50,    51,    18,    -1,
      20,    55,    22,    23,    24,    25,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    -1,    57,    -1,    18,
      60,    20,    62,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    -1,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    -1,    57,    -1,
      18,    60,    20,    62,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    55,    56,    -1,
      -1,    18,    60,    20,    62,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    55,    56,
      -1,    -1,    18,    60,    20,    62,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,    47,    48,    49,    50,    51,    18,    -1,    20,    55,
      22,    23,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    -1,    22,    23,    -1,    -1,
      42,    43,    44,    -1,    -1,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      62,    47,    48,    49,    50,    51,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    -1,    62,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,
      -1,    -1,    61,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    61,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    41
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    64,     0,     3,     4,     5,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    26,    27,    47,    48,    53,
      54,    55,    57,    65,    67,    68,    69,    71,    72,    13,
      66,    13,    13,    55,    55,    55,    67,    68,    68,    67,
      67,    67,    67,    67,    57,    18,    20,    22,    23,    24,
      25,    42,    43,    44,    47,    48,    49,    50,    51,    55,
      57,    60,    62,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    39,    58,    67,     9,    39,
      38,    55,    67,    67,    67,    68,    56,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    70,    67,    13,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    64,    57,    58,    67,
      72,    67,    66,    66,    56,    56,    57,    41,    38,    56,
      61,    59,    64,    57,    56,    67,    67,    67,    59,    58,
      57,    56,    64,    67,    59,    56
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    63,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    72,    72,    72,    72,    72
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     3,     3,     2,     2,     8,     1,
       3,     3,     1,     1,     1,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     2,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     2,     2,     1,     3,
       4,     4,     8,     6,     4,     3,     3,     5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "UNDEFINED", "IDENTIFIER", "INT",
  "STRING", "BOOL", "DOUBLE", "EQ", "STEQ", "NEQ", "STNEQ", "LE", "GE",
  "LAND", "LOR", "ADDSELF", "SUBSELF", "DIVASSIGN", "MULASSIGN",
  "ADDASSIGN", "SUBASSIGN", "MODASSIGN", "ANDASSIGN", "ORASSIGN",
  "XORASSIGN", "LANDASSIGN", "LORASSIGN", "','", "'='", "'?'", "':'",
  "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "UMINUS", "'!'", "'~'", "'('", "')'", "';'", "'{'", "'}'", "'['", "']'",
  "'.'", "$accept", "start", "statement", "define", "expression", "lvalue",
  "rvalue", "arguments", "branch_head", "conditional", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    86,    86,    87,    91,    95,    99,   104,   105,   110,
     119,   131,   134,   134,   136,   143,   148,   152,   157,   162,
     167,   172,   177,   182,   187,   192,   197,   202,   207,   214,
     219,   226,   233,   240,   247,   251,   257,   263,   279,   295,
     311,   327,   343,   359,   375,   391,   407,   423,   439,   455,
     471,   487,   500,   513,   526,   539,   540,   545,   552,   553,
     567,   568,   569,   570,   572,   573,   574,   575,   576
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
       2,     2,     2,    53,     2,     2,     2,    51,    42,     2,
      55,    56,    49,    48,    38,    47,    62,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    57,
      46,    39,    45,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    43,    59,    54,     2,     2,     2,
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
      35,    36,    37,    52
    };
    const unsigned int user_token_number_max_ = 293;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1924 "zScript.tab.cpp" // lalr1.cc:1167
#line 579 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
            return &constTrue;
        else
            return &constFalse;
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
