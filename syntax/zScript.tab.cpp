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
#line 2 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:404

#include "zcode.h"
#include "lex.yy.cpp"

/// enable debug
#define YYDEBUG 1

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

enum ValueType {
    Variant,
    Constant
};

Z_USE_NAMESPACE


#line 54 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 68 "zScript.tab.cpp" // lalr1.cc:412


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
#line 154 "zScript.tab.cpp" // lalr1.cc:479

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
#line 61 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 597 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 65 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 606 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 69 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 615 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 73 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //currentCode->nodeList << $2;
            }
#line 623 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 79 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
            }
#line 631 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 84 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->addIdentifier(*(yystack_[0].value.identifier));

                delete (yystack_[0].value.identifier);
            }
#line 641 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 89 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*(yystack_[2].value.identifier)));
                ZCodeParse::currentCodeParse->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 653 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 99 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = 2;}
#line 659 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 100 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.argsCount) = (yystack_[2].value.argsCount) + 1;
            }
#line 667 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 105 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = 2;}
#line 673 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 106 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.argsCount) = (yystack_[2].value.argsCount) + 1;
            }
#line 681 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 112 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 693 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 119 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LeftAssign);
            }
#line 703 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 124 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 712 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 128 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AddAssign);
            }
#line 722 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 133 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::SubAssign);
            }
#line 732 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 138 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::MulAssign);
            }
#line 742 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 143 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::DivAssign);
            }
#line 752 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 148 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AndAssign);
            }
#line 762 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 153 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::OrAssign);
            }
#line 772 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 158 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::XorAssign);
            }
#line 782 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 163 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::ModAssign);
            }
#line 792 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 168 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LOrAssign);
            }
#line 802 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 173 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LAndAssign);
            }
#line 812 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 178 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixAddSelf);
            }
#line 822 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 183 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixSubSelf);
            }
#line 832 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 188 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[0].value.argsCount)), ZVariant::Int));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Join);
            }
#line 843 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 196 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray(), ZVariant::Null));
            }
#line 853 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 201 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 865 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 208 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 877 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 215 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 889 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 222 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 901 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 229 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 910 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 233 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[1].value.argsCount)), ZVariant::Int));
                    ZCodeParse::currentCodeParse->appendCode(ZCode::Call);
            }
#line 921 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 239 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));
                    ZCodeParse::currentCodeParse->appendCode(ZCode::Get);
            }
#line 932 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 245 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Add);
                    }
            }
#line 953 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 261 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Sub);
                    }
            }
#line 974 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 277 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Mul);
                    }
            }
#line 995 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 293 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Div);
                    }
            }
#line 1016 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 309 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::And);
                    }
            }
#line 1037 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 325 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Or);
                    }
            }
#line 1058 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 341 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Xor);
                    }
            }
#line 1079 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 357 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Mod);
                    }
            }
#line 1100 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 373 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::EQ);
                    }
            }
#line 1121 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 389 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::NEQ);
                    }
            }
#line 1142 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 405 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::STEQ);
                    }
            }
#line 1164 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 422 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::STNEQ);
                    }
            }
#line 1186 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 439 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::LE);
                    }
            }
#line 1207 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 455 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::GE);
                    }
            }
#line 1228 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 471 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::LAnd);
                    }
            }
#line 1249 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 487 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::LOr);
                    }
            }
#line 1270 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 503 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(~ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Contrary);
                    }
                }
#line 1288 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 516 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(! *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Not);
                    }
                }
#line 1306 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 529 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(- *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Minus);
                    }
                }
#line 1324 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 542 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().last());

                        last_code->value = ZCodeParse::getConstantAddressByValue(+ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeParse::currentCodeParse->appendCode(ZCode::Abs);
                    }
                }
#line 1342 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 555 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1348 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 556 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixAddSelf);
            }
#line 1358 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 561 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixSubSelf);
            }
#line 1368 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 566 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                zDebug << "group_exp" << (yystack_[0].value.argsCount) << "=========================";

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[0].value.argsCount)), ZVariant::Int));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Join);
            }
#line 1381 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 576 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = 0;}
#line 1387 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 577 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.argsCount) = 1;
            }
#line 1395 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1399 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -78;

  const signed char parser::yytable_ninf_ = -33;

  const short int
  parser::yypact_[] =
  {
     -78,    80,   -78,     0,     2,     3,   -39,   -38,   -37,   -78,
     -78,   -78,   -78,   -78,   -78,   298,   298,   298,   298,   298,
     298,   298,   -78,   -35,   -14,   -13,   337,   890,   -78,   282,
      18,   -11,    -9,   -26,   -78,   298,   298,   298,   843,  1025,
    1042,   215,   215,   215,   215,   383,   -78,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   -78,   298,    56,
     -78,   -78,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   -78,   429,   234,   298,     0,     0,
     475,   521,   567,  1079,   -78,   -17,   889,   971,   843,   971,
     843,   987,   987,   935,   935,   889,   951,   951,   951,   137,
     137,   215,   215,   215,   843,    -5,   613,   -78,   889,   889,
     889,   889,   889,   889,   889,   889,   889,   889,   -17,   889,
     136,   -78,   -78,   659,    18,   889,   -78,   -31,   -78,   -78,
     298,   298,   -78,   -78,   -78,   156,   -78,   -28,   705,   751,
     -78,   -78,   298,   -78,   214,   797,   -78,   -78
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     0,     0,     0,    34,
      18,    35,    36,    38,    37,     0,     0,     0,     0,     0,
       0,     0,     3,     0,    33,    65,     0,    16,    17,     0,
       6,     9,     7,     0,    39,     0,     0,     0,     0,    16,
      16,    60,    61,    59,    58,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     5,     0,     0,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    62,    13,    15,    50,    52,    51,
      53,    54,    55,    56,    57,    14,    46,    47,    48,    43,
      42,    44,    45,    49,    67,     0,     0,    41,    24,    23,
      21,    22,    28,    25,    26,    27,    30,    29,    12,    19,
       0,    73,     2,     0,    74,    10,    11,     0,    68,    69,
       0,     0,    40,    20,    72,     0,    76,     0,     0,     0,
      75,     2,     0,    71,     0,     0,     8,    70
  };

  const signed char
  parser::yypgoto_[] =
  {
     -78,   -76,   -78,   -77,   -78,   -78,   -15,    39,   -78,   -78,
     -78,   -16
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    23,    32,    24,    25,    26,    27,    28,   115,
      29,    30
  };

  const short int
  parser::yytable_[] =
  {
      38,    38,    41,    42,    43,    44,    45,    88,   130,    70,
      71,   136,   137,    31,    85,    33,    34,    35,    36,    37,
      90,    91,    92,    46,    47,    48,   147,    86,    87,    88,
      89,   151,    38,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   142,   116,    39,    40,   145,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    38,   129,   117,
     134,   133,   135,     0,     0,   154,    93,     0,     0,     0,
       2,     0,     0,     3,     4,     5,    95,     0,     6,     0,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,   148,   149,     0,    17,    18,
       0,     0,     0,     0,    19,    20,    21,   155,    22,     3,
       4,     5,     0,     0,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,    50,     0,    52,     3,
       4,     5,    15,    16,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,     0,    63,    64,    65,
      19,    20,    21,    66,    22,     0,   144,     0,    68,     0,
      69,     0,     0,     0,    17,    18,     0,     0,     0,     0,
      19,    20,    21,     0,    22,     0,   150,     3,     4,     5,
       0,     0,     6,     0,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    50,     0,    52,     0,     0,     5,
      15,    16,     6,     0,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    17,    18,     0,     0,     0,     0,    19,    20,
      21,    66,    22,     0,   156,     0,    68,     0,    69,     0,
       0,     0,    17,    18,     0,     0,     0,     5,    19,    20,
      21,     0,     0,   132,     9,    10,    11,    12,    13,    14,
       0,     0,     0,     5,     0,     0,     0,     0,    15,    16,
       9,    10,    11,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    15,    16,     0,     0,     0,     0,
      17,    18,     0,     0,     0,     0,    19,    20,    21,     0,
       0,    84,     0,     0,     0,     0,    17,    18,     0,     0,
       0,     0,    19,    20,    21,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
      58,    59,    60,     0,     0,    61,    62,    63,    64,    65,
       0,     0,     0,    66,     0,    67,     0,     0,    68,     0,
      69,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,    58,    59,    60,     0,
       0,    61,    62,    63,    64,    65,     0,     0,     0,    66,
      94,     0,     0,     0,    68,     0,    69,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,    58,    59,    60,     0,     0,    61,    62,    63,
      64,    65,     0,     0,     0,    66,     0,   131,     0,     0,
      68,     0,    69,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,    58,    59,
      60,     0,     0,    61,    62,    63,    64,    65,     0,     0,
       0,    66,   138,     0,     0,     0,    68,     0,    69,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,    58,    59,    60,     0,     0,    61,
      62,    63,    64,    65,     0,     0,     0,    66,   139,     0,
       0,     0,    68,     0,    69,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
      58,    59,    60,     0,     0,    61,    62,    63,    64,    65,
       0,     0,     0,    66,     0,   140,     0,     0,    68,     0,
      69,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,    58,    59,    60,     0,
       0,    61,    62,    63,    64,    65,     0,     0,     0,    66,
       0,     0,     0,     0,    68,   143,    69,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
       0,     0,    58,    59,    60,     0,     0,    61,    62,    63,
      64,    65,     0,     0,     0,    66,     0,   146,     0,     0,
      68,     0,    69,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,    58,    59,
      60,     0,     0,    61,    62,    63,    64,    65,     0,     0,
       0,    66,     0,   152,     0,     0,    68,     0,    69,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,    58,    59,    60,     0,     0,    61,
      62,    63,    64,    65,     0,     0,     0,    66,   153,     0,
       0,     0,    68,     0,    69,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
      58,    59,    60,     0,     0,    61,    62,    63,    64,    65,
       0,     0,     0,    66,   157,     0,     0,     0,    68,     0,
      69,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,    58,    59,    60,     0,
       0,    61,    62,    63,    64,    65,     0,     0,     0,    66,
       0,     0,     0,     0,    68,     0,    69,    49,    50,    51,
      52,    53,    54,    55,    56,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,    58,    59,    60,     0,     0,    61,    62,    63,
      64,    65,     0,     0,     0,    66,     0,     0,     0,     0,
      68,     0,    69,    49,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      50,    51,    52,    53,    54,     0,     0,     0,    58,    59,
      60,     0,     0,    61,    62,    63,    64,    65,     0,     0,
      50,    66,    52,    53,    54,     0,    68,     0,    69,    61,
      62,    63,    64,    65,     0,     0,    50,    66,    52,     0,
       0,     0,    68,     0,    69,     0,     0,     0,     0,    61,
      62,    63,    64,    65,     0,     0,     0,    66,     0,     0,
       0,     0,    68,     0,    69,    61,    62,    63,    64,    65,
       0,     0,     0,    66,     0,     0,     0,     0,    68,     0,
      69,    70,    71,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,     0,   -31,     0,     0,   -31,    70,    71,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   -32,   -31,   -31,   -32,     0,     0,   -31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -32,
     -32,     0,     0,     0,   -32,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,   141
  };

  const short int
  parser::yycheck_[] =
  {
      15,    16,    17,    18,    19,    20,    21,    38,    84,    26,
      27,    88,    89,    13,    29,    13,    13,    56,    56,    56,
      35,    36,    37,    58,    38,    38,    57,     9,    39,    38,
      56,    59,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    57,    68,    15,    16,   132,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    13,
      86,    86,    87,    -1,    -1,   151,    37,    -1,    -1,    -1,
       0,    -1,    -1,     3,     4,     5,    47,    -1,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,   140,   141,    -1,    48,    49,
      -1,    -1,    -1,    -1,    54,    55,    56,   152,    58,     3,
       4,     5,    -1,    -1,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    19,    -1,    21,     3,
       4,     5,    26,    27,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    48,    49,    -1,    50,    51,    52,
      54,    55,    56,    56,    58,    -1,    60,    -1,    61,    -1,
      63,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,
      54,    55,    56,    -1,    58,    -1,    60,     3,     4,     5,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    19,    -1,    21,    -1,    -1,     5,
      26,    27,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    48,    49,    -1,    -1,    -1,    -1,    54,    55,
      56,    56,    58,    -1,    60,    -1,    61,    -1,    63,    -1,
      -1,    -1,    48,    49,    -1,    -1,    -1,     5,    54,    55,
      56,    -1,    -1,    59,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    26,    27,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    54,    55,    56,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    -1,    58,    -1,    -1,    61,    -1,
      63,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      57,    -1,    -1,    -1,    61,    -1,    63,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    -1,    58,    -1,    -1,
      61,    -1,    63,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    61,    -1,    63,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    57,    -1,
      -1,    -1,    61,    -1,    63,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    -1,    58,    -1,    -1,    61,    -1,
      63,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    61,    62,    63,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    -1,    58,    -1,    -1,
      61,    -1,    63,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    -1,    58,    -1,    -1,    61,    -1,    63,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    57,    -1,
      -1,    -1,    61,    -1,    63,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      43,    44,    45,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      63,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    61,    -1,    63,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    43,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      61,    -1,    63,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    43,    44,
      45,    -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      19,    56,    21,    22,    23,    -1,    61,    -1,    63,    48,
      49,    50,    51,    52,    -1,    -1,    19,    56,    21,    -1,
      -1,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    61,    -1,    63,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,    -1,
      63,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    -1,    42,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    39,    57,    58,    42,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    -1,    -1,    -1,    62,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    65,     0,     3,     4,     5,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    26,    27,    48,    49,    54,
      55,    56,    58,    66,    68,    69,    70,    71,    72,    74,
      75,    13,    67,    13,    13,    56,    56,    56,    70,    71,
      71,    70,    70,    70,    70,    70,    58,    38,    38,    18,
      19,    20,    21,    22,    23,    24,    25,    38,    43,    44,
      45,    48,    49,    50,    51,    52,    56,    58,    61,    63,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    59,    70,     9,    39,    38,    56,
      70,    70,    70,    71,    57,    71,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    73,    70,    13,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    71,    70,
      65,    58,    59,    70,    75,    70,    67,    67,    57,    57,
      58,    42,    57,    62,    60,    65,    58,    57,    70,    70,
      60,    59,    58,    57,    65,    70,    60,    57
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    64,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      74,    74,    75,    75,    75,    75,    75
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     3,     3,     2,     2,     8,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     2,     2,     1,     0,     1,     4,     4,
       8,     6,     4,     3,     3,     5,     4
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
  "XORASSIGN", "LANDASSIGN", "LORASSIGN", "','", "'='", "COMMA", "'?'",
  "':'", "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "UMINUS", "'!'", "'~'", "'('", "')'", "';'", "'{'", "'}'", "'['",
  "']'", "'.'", "$accept", "start", "statement", "define", "group_lval",
  "group_exp", "expression", "lvalue", "rvalue", "arguments",
  "branch_head", "conditional", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    60,    60,    61,    65,    69,    73,    78,    79,    84,
      89,    96,    99,   100,   105,   106,   110,   110,   112,   119,
     124,   128,   133,   138,   143,   148,   153,   158,   163,   168,
     173,   178,   183,   188,   196,   201,   208,   215,   222,   229,
     233,   239,   245,   261,   277,   293,   309,   325,   341,   357,
     373,   389,   405,   422,   439,   455,   471,   487,   503,   516,
     529,   542,   555,   556,   561,   566,   576,   577,   582,   583,
     584,   585,   587,   588,   589,   590,   591
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
       2,     2,     2,    54,     2,     2,     2,    52,    43,     2,
      56,    57,    50,    49,    38,    48,    63,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    58,
      47,    39,    46,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,    44,    60,    55,     2,     2,     2,
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
      35,    36,    37,    40,    53
    };
    const unsigned int user_token_number_max_ = 294;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2024 "zScript.tab.cpp" // lalr1.cc:1167
#line 593 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


void yy::parser::error(const location_type& loc, const std::string& msg)
{
    std::cerr << "from " << loc.begin.line << " line, " << loc.begin.column << " column "
              << "to " << loc.end.line << " line, " << loc.end.column << " column, " << msg << std::endl;

    quick_exit(-1);
}

int yyFlexLexer::yywrap()
{
    if(!ZCodeParse::yywrap) {
        ZCodeParse::yywrap = true;

        return 0;
    }

    return 1;
}

#undef yyFlexLexer

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return ZCodeParse::currentCodeParse->yyFlexLexer()->yylex();
}
