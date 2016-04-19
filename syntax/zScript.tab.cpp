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
#line 63 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->appendCode(ZCode::Goto, ZCodeParse::currentCodeParse->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 598 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 68 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 607 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 72 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 616 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 76 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 625 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 80 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //currentCode->nodeList << $2;
            }
#line 633 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 86 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeParse::currentCodeParse->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeParse::currentCodeParse->getCodeList().count() - 1;

                delete (yystack_[1].value.identifier);
            }
#line 643 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 91 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
            }
#line 651 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 96 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->addIdentifier(*(yystack_[0].value.identifier));

                delete (yystack_[0].value.identifier);
            }
#line 661 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 101 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*(yystack_[2].value.identifier)));
                ZCodeParse::currentCodeParse->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 673 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 111 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = 2;}
#line 679 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 112 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.argsCount) = (yystack_[2].value.argsCount) + 1;
            }
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 117 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = 2;}
#line 693 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 118 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.argsCount) = (yystack_[2].value.argsCount) + 1;
            }
#line 701 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 124 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 713 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 131 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LeftAssign);
            }
#line 723 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 136 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 732 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 140 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AddAssign);
            }
#line 742 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 145 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::SubAssign);
            }
#line 752 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 150 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::MulAssign);
            }
#line 762 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 155 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::DivAssign);
            }
#line 772 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 160 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AndAssign);
            }
#line 782 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 165 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::OrAssign);
            }
#line 792 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 170 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::XorAssign);
            }
#line 802 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 175 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::ModAssign);
            }
#line 812 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 180 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LOrAssign);
            }
#line 822 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 185 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LAndAssign);
            }
#line 832 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 190 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixAddSelf);
            }
#line 842 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 195 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixSubSelf);
            }
#line 852 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 200 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[0].value.argsCount)), ZVariant::Int));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Join);
            }
#line 863 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 208 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray(), ZVariant::Null));
            }
#line 873 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 213 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 885 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 220 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 897 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 227 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 909 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 234 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 921 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 241 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 930 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 245 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[1].value.argsCount)), ZVariant::Int));
                    ZCodeParse::currentCodeParse->appendCode(ZCode::Call);
            }
#line 941 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 251 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));
                    ZCodeParse::currentCodeParse->appendCode(ZCode::Get);
            }
#line 952 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 257 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 973 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 273 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 994 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 289 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1015 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 305 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1036 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 321 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1057 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 337 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1078 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 353 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1099 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 369 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1120 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 385 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1141 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 401 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1162 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 417 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1184 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 434 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1206 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 451 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1227 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 467 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1248 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 483 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1269 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 499 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1290 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 515 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1308 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 528 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1326 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 541 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1344 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 554 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1362 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 567 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1368 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 568 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixAddSelf);
            }
#line 1378 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 573 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixSubSelf);
            }
#line 1388 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 578 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[0].value.argsCount)), ZVariant::Int));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Join);
            }
#line 1399 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 586 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.argsCount) = 0;}
#line 1405 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 587 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.argsCount) = 1;
            }
#line 1413 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1417 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -80;

  const signed char parser::yytable_ninf_ = -35;

  const short int
  parser::yypact_[] =
  {
     -80,    79,   -80,    -6,    -4,    -1,   -37,   -33,   -30,   -80,
      10,   -31,   -80,   -80,   -80,   -80,   352,   352,   352,   352,
     352,   352,   352,   -80,   -29,   -11,   -10,   415,   200,   -80,
     305,    22,    -8,    17,   -22,   -80,   352,   352,   352,     0,
     -80,   -80,   855,   985,   999,    83,    83,    83,    83,   459,
     -80,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,    59,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   -80,   352,   -80,   -80,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   352,   352,   352,   -80,   503,
     281,   352,    -6,    -6,   547,   591,   635,   141,   -80,   -80,
     -12,   899,   949,   855,   949,   855,   932,   932,   914,   914,
     899,   -80,   325,   325,   325,    58,    58,    83,    83,    83,
     855,    15,   370,   899,   899,   899,   899,   899,   899,   899,
     899,   899,   899,   -12,   899,   139,   -80,   -80,   679,    22,
     899,   -80,   -32,   -80,   -80,   352,   352,   -80,   -80,   -80,
     198,   -80,    16,   723,   767,   -80,   -80,   352,   -80,   257,
     811,   -80,   -80
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     0,     0,     0,    36,
       0,    20,    37,    38,    40,    39,     0,     0,     0,     0,
       0,     0,     0,     4,     0,    35,    67,     0,    18,    19,
       0,     7,    11,     8,     0,    41,     0,     0,     0,     0,
       9,    20,     0,    18,    18,    62,    63,    61,    60,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     6,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     3,    64,
      15,    17,    52,    54,    53,    55,    56,    57,    58,    59,
      16,    43,    48,    49,    50,    45,    44,    46,    47,    51,
      69,     0,     0,    26,    25,    23,    24,    30,    27,    28,
      29,    32,    31,    14,    21,     0,    75,     2,     0,    76,
      12,    13,     0,    70,    71,     0,     0,    42,    22,    74,
       0,    78,     0,     0,     0,    77,     2,     0,    73,     0,
       0,    10,    72
  };

  const signed char
  parser::yypgoto_[] =
  {
     -80,   -79,   -80,   -75,   -80,   -80,   -16,    -5,   -80,   -80,
     -80,    -2
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    24,    33,    25,    26,    27,    28,    29,   121,
      30,    31
  };

  const short int
  parser::yytable_[] =
  {
      42,    42,    45,    46,    47,    48,    49,    92,    32,   135,
      34,    43,    44,    35,    89,    74,    75,   141,   142,    36,
      94,    95,    96,    37,    39,   152,    38,    40,    51,    52,
      50,    90,    91,    97,    93,    42,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   100,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    92,   122,   150,    98,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      42,   134,   147,   111,   138,   140,   156,   159,    54,     2,
      56,   133,     3,     4,     5,     0,     0,     6,   139,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,    54,     0,    56,    16,    17,    68,    69,
      70,     0,     0,     0,    71,     0,     0,     0,     0,     0,
      73,     0,     0,     0,     0,     0,     0,    18,    19,   153,
     154,     0,     0,    20,    21,    22,     0,     0,    23,    71,
       0,   160,     3,     4,     5,    73,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,    18,    19,     0,
       0,     0,     0,    20,    21,    22,     0,     0,    23,   146,
     149,     3,     4,     5,     0,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,    18,    19,     0,     0,
       0,     0,    20,    21,    22,     0,     0,    23,     0,   155,
       3,     4,     5,     0,     0,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,     5,     0,     0,     6,
       0,     7,     8,     9,     0,    41,    12,    13,    14,    15,
       0,     0,     0,     0,     0,    18,    19,     0,    16,    17,
       5,    20,    21,    22,     0,     0,    23,     9,   161,    41,
      12,    13,    14,    15,     0,     0,     0,     0,     0,    18,
      19,     0,    16,    17,     0,    20,    21,    22,     0,     0,
       0,   137,     0,     0,    53,    54,    55,    56,    57,    58,
       0,     0,     0,    18,    19,     0,     0,     5,     0,    20,
      21,    22,     0,     0,     9,    88,    41,    12,    13,    14,
      15,     0,     0,    66,    67,    68,    69,    70,     0,    16,
      17,    71,     0,     0,     0,     0,     0,    73,     0,    53,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
      18,    19,     0,     0,     0,     0,    20,    21,    22,    61,
       0,     0,    62,    63,    64,    65,     0,     0,    66,    67,
      68,    69,    70,     0,     0,     0,    71,     0,     0,     0,
       0,     0,    73,   148,    53,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
      65,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    71,     0,     0,    72,     0,     0,    73,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,    64,    65,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    71,    99,     0,     0,     0,
       0,    73,    53,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,    62,    63,    64,    65,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    71,
       0,     0,   136,     0,     0,    73,    53,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,    62,
      63,    64,    65,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    71,   143,     0,     0,     0,     0,    73,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,    62,    63,    64,    65,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    71,   144,     0,
       0,     0,     0,    73,    53,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
      65,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    71,     0,     0,   145,     0,     0,    73,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,    62,    63,    64,    65,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    71,     0,     0,   151,     0,
       0,    73,    53,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,    62,    63,    64,    65,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,    71,
       0,     0,   157,     0,     0,    73,    53,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,    62,
      63,    64,    65,     0,     0,    66,    67,    68,    69,    70,
       0,     0,     0,    71,   158,     0,     0,     0,     0,    73,
      53,    54,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,    62,    63,    64,    65,     0,     0,    66,
      67,    68,    69,    70,     0,     0,     0,    71,   162,     0,
       0,     0,     0,    73,    53,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    62,    63,    64,
      65,     0,     0,    66,    67,    68,    69,    70,     0,     0,
       0,    71,     0,     0,     0,     0,     0,    73,    53,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,     0,
       0,    62,    63,    64,    65,     0,     0,    66,    67,    68,
      69,    70,    54,     0,    56,    71,     0,    63,    64,    65,
       0,    73,    66,    67,    68,    69,    70,     0,     0,    54,
      71,    56,    57,    58,     0,     0,    73,     0,     0,     0,
      66,    67,    68,    69,    70,     0,     0,     0,    71,     0,
       0,     0,     0,     0,    73,     0,     0,    66,    67,    68,
      69,    70,     0,     0,     0,    71,     0,     0,     0,     0,
       0,    73,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,     0,   -34,
       0,     0,   -33,   -33,   -33,     0,     0,     0,   -33,     0,
       0,     0,     0,     0,     0,     0,   -34,   -34,   -34,     0,
       0,     0,   -34
  };

  const short int
  parser::yycheck_[] =
  {
      16,    17,    18,    19,    20,    21,    22,    39,    14,    88,
      14,    16,    17,    14,    30,    27,    28,    92,    93,    56,
      36,    37,    38,    56,    14,    57,    56,    58,    39,    39,
      59,     9,    40,    38,    56,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    51,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    39,    73,   137,    59,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    57,    14,    90,    91,    60,   156,    20,     0,
      22,    86,     3,     4,     5,    -1,    -1,     8,    90,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    22,    27,    28,    50,    51,
      52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,   145,
     146,    -1,    -1,    54,    55,    56,    -1,    -1,    59,    56,
      -1,   157,     3,     4,     5,    62,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,    -1,    -1,    54,    55,    56,    -1,    -1,    59,    58,
      61,     3,     4,     5,    -1,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    54,    55,    56,    -1,    -1,    59,    -1,    61,
       3,     4,     5,    -1,    -1,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,     5,    -1,    -1,     8,
      -1,    10,    11,    12,    -1,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    27,    28,
       5,    54,    55,    56,    -1,    -1,    59,    12,    61,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    27,    28,    -1,    54,    55,    56,    -1,    -1,
      -1,    60,    -1,    -1,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    48,    49,    -1,    -1,     5,    -1,    54,
      55,    56,    -1,    -1,    12,    60,    14,    15,    16,    17,
      18,    -1,    -1,    48,    49,    50,    51,    52,    -1,    27,
      28,    56,    -1,    -1,    -1,    -1,    -1,    62,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      48,    49,    -1,    -1,    -1,    -1,    54,    55,    56,    39,
      -1,    -1,    42,    43,    44,    45,    -1,    -1,    48,    49,
      50,    51,    52,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    62,    63,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,    44,
      45,    -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    42,    43,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,
      -1,    62,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
      43,    44,    45,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    62,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    43,    44,    45,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    62,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,    44,
      45,    -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    42,    43,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    48,    49,    50,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
      43,    44,    45,    -1,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    62,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    43,    44,    45,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    62,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,    44,
      45,    -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    42,    43,    44,    45,    -1,    -1,    48,    49,    50,
      51,    52,    20,    -1,    22,    56,    -1,    43,    44,    45,
      -1,    62,    48,    49,    50,    51,    52,    -1,    -1,    20,
      56,    22,    23,    24,    -1,    -1,    62,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    62,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    40,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    -1,    57,    58,    59,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    -1,
      -1,    -1,    63
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    65,     0,     3,     4,     5,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    27,    28,    48,    49,
      54,    55,    56,    59,    66,    68,    69,    70,    71,    72,
      74,    75,    14,    67,    14,    14,    56,    56,    56,    14,
      58,    14,    70,    71,    71,    70,    70,    70,    70,    70,
      59,    39,    39,    19,    20,    21,    22,    23,    24,    25,
      26,    39,    42,    43,    44,    45,    48,    49,    50,    51,
      52,    56,    59,    62,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    60,    70,
       9,    40,    39,    56,    70,    70,    70,    71,    59,    57,
      71,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    14,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    73,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    71,    70,    65,    59,    60,    70,    75,
      70,    67,    67,    57,    57,    59,    58,    57,    63,    61,
      65,    59,    57,    70,    70,    61,    60,    59,    57,    65,
      70,    61,    57
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    64,    65,    65,    65,    65,    65,    65,    66,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    75,    75,    75
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     4,     2,     3,     3,     2,     2,     2,
       8,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     3,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     2,     2,     1,     0,     1,
       4,     4,     8,     6,     4,     3,     3,     5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "UNDEFINED", "GOTO", "IDENTIFIER",
  "INT", "STRING", "BOOL", "DOUBLE", "EQ", "STEQ", "NEQ", "STNEQ", "LE",
  "GE", "LAND", "LOR", "ADDSELF", "SUBSELF", "DIVASSIGN", "MULASSIGN",
  "ADDASSIGN", "SUBASSIGN", "MODASSIGN", "ANDASSIGN", "ORASSIGN",
  "XORASSIGN", "LANDASSIGN", "LORASSIGN", "','", "'='", "COMMA", "'.'",
  "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "UMINUS", "'!'", "'~'", "'('", "')'", "':'", "';'", "'{'", "'}'", "'['",
  "']'", "$accept", "start", "statement", "define", "group_lval",
  "group_exp", "expression", "lvalue", "rvalue", "arguments",
  "branch_head", "conditional", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    62,    62,    63,    68,    72,    76,    80,    85,    86,
      91,    96,   101,   108,   111,   112,   117,   118,   122,   122,
     124,   131,   136,   140,   145,   150,   155,   160,   165,   170,
     175,   180,   185,   190,   195,   200,   208,   213,   220,   227,
     234,   241,   245,   251,   257,   273,   289,   305,   321,   337,
     353,   369,   385,   401,   417,   434,   451,   467,   483,   499,
     515,   528,   541,   554,   567,   568,   573,   578,   586,   587,
     592,   593,   594,   595,   597,   598,   599,   600,   601
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
      56,    57,    50,    49,    39,    48,    42,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    59,
      47,    40,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,    44,    61,    55,     2,     2,     2,
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
      35,    36,    37,    38,    41,    53
    };
    const unsigned int user_token_number_max_ = 295;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2033 "zScript.tab.cpp" // lalr1.cc:1167
#line 603 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
