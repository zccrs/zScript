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
#line 65 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->appendCode(ZCode::Goto, ZCodeParse::currentCodeParse->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 598 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 70 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 607 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 74 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 616 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 78 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeParse::currentCodeParse->getCodeList().count() > 1 && ZCodeParse::currentCodeParse->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeParse::currentCodeParse->appendCode(ZCode::PopAll);
            }
#line 625 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 82 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //currentCode->nodeList << $2;
            }
#line 633 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 90 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeParse::currentCodeParse->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeParse::currentCodeParse->getCodeList().count() - 1;

                delete (yystack_[1].value.identifier);
            }
#line 643 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 95 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
            }
#line 651 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 100 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->addIdentifier(*(yystack_[0].value.identifier));

                delete (yystack_[0].value.identifier);
            }
#line 661 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 105 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeParse::currentCodeParse->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*(yystack_[2].value.identifier)));
                ZCodeParse::currentCodeParse->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 673 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 115 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 679 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 116 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.count) = (yystack_[2].value.count) + 1;
            }
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 121 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 693 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 122 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 699 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 123 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.count) = (yystack_[2].value.count) + 1;
            }
#line 707 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 129 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::currentCodeParse->getIdentifierAddress(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 719 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 136 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LeftAssign);
            }
#line 729 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 141 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 738 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 145 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Get);
            }
#line 749 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 151 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AddAssign);
            }
#line 759 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 156 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::SubAssign);
            }
#line 769 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 161 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::MulAssign);
            }
#line 779 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 166 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::DivAssign);
            }
#line 789 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 171 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::AndAssign);
            }
#line 799 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 176 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::OrAssign);
            }
#line 809 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 181 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::XorAssign);
            }
#line 819 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 186 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::ModAssign);
            }
#line 829 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 191 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LOrAssign);
            }
#line 839 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 196 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::LAndAssign);
            }
#line 849 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 201 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixAddSelf);
            }
#line 859 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 206 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PrefixSubSelf);
            }
#line 869 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 211 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Join);
            }
#line 880 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 219 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray(), ZVariant::Null));
            }
#line 890 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 224 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 902 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 231 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 914 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 238 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 926 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 245 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 938 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 252 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 947 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 256 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeParse::currentCodeParse->appendCode(ZCode::Call);
            }
#line 958 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 262 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 979 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 278 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1000 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 294 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1021 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 310 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1042 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 326 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1063 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 342 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1084 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 358 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1105 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 374 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1126 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 390 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1147 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 406 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1168 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 422 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1190 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 439 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1212 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 456 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1233 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 472 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1254 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 488 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1275 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 504 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1296 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 520 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1314 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 533 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1332 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 546 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1350 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 559 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1368 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 572 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1374 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 573 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixAddSelf);
            }
#line 1384 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 578 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::PostfixSubSelf);
            }
#line 1394 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 583 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeParse::currentCodeParse->appendCode(ZCode::Push, ZCodeParse::getConstantAddress(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeParse::currentCodeParse->appendCode(ZCode::Join);
            }
#line 1405 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 591 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1411 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 592 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.count) = 1;
            }
#line 1419 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 597 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.count) = ZCodeParse::currentCodeParse->getCodeList().count() - 1;

                ZCodeParse::currentCodeParse->appendCode(ZCode::If, ZCodeParse::currentCodeParse->getConstantAddress("", ZVariant::Undefined));
            }
#line 1429 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 602 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = ZCodeParse::currentCodeParse->getCodeList().count() - 1;}
#line 1435 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 603 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = ZCodeParse::currentCodeParse->getCodeList().count() - 1;}
#line 1441 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 604 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = ZCodeParse::currentCodeParse->getCodeList().count() - 1;}
#line 1447 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 607 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                int fromIndex = ZCodeParse::currentCodeParse->getCodeList().count();
                ZVariant *toIndex = ZCodeParse::currentCodeParse->getConstantAddress(QByteArray::number(fromIndex), ZVariant::Int);

                static_cast<ValueCode*>(ZCodeParse::currentCodeParse->getCodeList().value((yystack_[2].value.count)))->value = toIndex;
            }
#line 1458 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1462 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -82;

  const signed char parser::yytable_ninf_ = -39;

  const short int
  parser::yypact_[] =
  {
     -82,    81,   -82,    -4,     3,     5,   -36,   -30,   -29,   -82,
      17,   -27,   -82,   -82,   -82,   -82,   353,   353,   -82,   353,
     353,   353,   353,   353,   -82,   -82,   -31,    -7,    -6,   438,
     574,   -82,   336,    27,    19,    21,    18,   -82,   353,   353,
     353,   -31,   -82,   -82,   888,   994,  1032,    85,    85,    85,
      85,   483,   -82,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,    65,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   -82,   -82,   -82,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     -82,   528,   288,   353,    -4,    -4,   573,   618,   663,   484,
     -82,   -82,   933,   -14,   933,   376,   888,   376,   888,   174,
     174,   948,   948,   933,   -82,   993,   993,   993,    60,    60,
      85,    85,    85,   888,    16,   392,   933,   933,   933,   933,
     933,   933,   933,   933,   933,   933,   -14,   933,   142,   -82,
     -82,   708,    27,   933,   -82,   -38,   -82,   -82,   353,   353,
     -82,   -82,   -82,   202,   -82,    26,   753,   798,   -82,   -82,
     353,   -82,   262,   843,   -82,   -82
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,     0,     0,     0,    40,
       0,    23,    41,    42,    44,    43,     0,     0,     8,     0,
       0,     0,     0,     0,     9,     4,     0,    39,    70,     0,
      21,    22,     0,     7,    13,    10,     0,    45,     0,     0,
       0,     0,    11,    23,     0,    21,    21,    65,    66,    64,
      63,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     6,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       3,    67,    19,    17,    20,    55,    57,    56,    58,    59,
      60,    61,    62,    18,    26,    51,    52,    53,    48,    47,
      49,    50,    54,    72,     0,     0,    30,    29,    27,    28,
      34,    31,    32,    33,    36,    35,    16,    24,     0,    78,
       2,     0,    79,    14,    15,     0,    73,    74,     0,     0,
      46,    25,    77,     0,    81,     0,     0,     0,    80,     2,
       0,    76,     0,     0,    12,    75
  };

  const signed char
  parser::yypgoto_[] =
  {
     -82,   -81,   -11,   -82,   -69,   -82,   -82,   -16,    -5,   -82,
     -82,   -82,    -2
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    25,    26,    35,    27,    28,    29,    30,    31,
     124,    32,    33
  };

  const short int
  parser::yytable_[] =
  {
      44,    44,    94,    47,    48,    49,    50,    51,    18,   138,
      34,    45,    46,    76,    77,    52,    91,    36,    75,    37,
     155,    38,    96,    97,    98,   144,   145,    39,    40,    24,
     100,    41,    42,    53,    54,    99,    92,   102,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   103,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   125,   153,
      93,    94,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,    44,   137,   150,    95,   141,   143,   162,   114,
      56,     2,    58,   136,     3,     4,     5,   159,     0,     6,
     142,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,    56,     0,    58,    16,    17,
       0,    70,    71,    72,     0,     0,     0,    73,     0,     0,
      18,     0,     0,    74,     0,     0,     0,     0,     0,     0,
      19,    20,   156,   157,     0,     0,    21,    22,    23,     0,
       0,    24,    73,     0,   163,     3,     4,     5,    74,     0,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,    56,     0,    58,    21,    22,    23,
       0,     0,    24,     0,   152,     3,     4,     5,     0,     0,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,    68,    69,    70,    71,    72,     0,    16,
      17,    73,     0,     0,     0,     0,     0,    74,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,    21,    22,    23,
       0,     0,    24,     0,   158,     3,     4,     5,     0,     0,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     5,     0,     0,     6,     0,     7,     8,
       9,    18,    43,    12,    13,    14,    15,     0,     0,     0,
       0,    19,    20,     0,     0,    16,    17,    21,    22,    23,
       0,     0,    24,     0,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     5,     0,    21,    22,    23,     0,     0,     9,   140,
      43,    12,    13,    14,    15,     0,     0,     0,     5,     0,
       0,     0,     0,    16,    17,     9,     0,    43,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,    19,    20,     0,     0,     0,
       0,    21,    22,    23,     0,     0,    56,    90,    58,    59,
      60,     0,    19,    20,     0,     0,     0,     0,    21,    22,
      23,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,    68,    69,    70,    71,    72,
       0,     0,    63,    73,     0,    64,    65,    66,    67,    74,
       0,    68,    69,    70,    71,    72,     0,     0,     0,    73,
       0,     0,     0,     0,     0,    74,   151,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    63,     0,
       0,    64,    65,    66,    67,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    73,     0,     0,    24,     0,
       0,    74,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    63,    88,    89,    64,    65,    66,    67,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      73,   101,     0,   149,     0,     0,    74,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   139,    63,     0,
       0,    64,    65,    66,    67,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    73,     0,     0,     0,     0,
       0,    74,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    63,    88,    89,    64,    65,    66,    67,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      73,   146,     0,     0,     0,     0,    74,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,    64,    65,    66,    67,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    73,   147,     0,     0,     0,
       0,    74,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,    63,     0,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      73,     0,     0,     0,     0,     0,    74,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,    63,     0,
       0,    64,    65,    66,    67,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    73,     0,     0,     0,     0,
       0,    74,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,    63,     0,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      73,     0,     0,     0,     0,     0,    74,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,    64,    65,    66,    67,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    73,   161,     0,     0,     0,
       0,    74,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      73,   165,     0,     0,     0,     0,    74,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,    64,    65,    66,    67,     0,     0,    68,    69,    70,
      71,    72,     0,     0,     0,    73,     0,     0,     0,     0,
       0,    74,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,     0,     0,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      73,     0,    65,    66,    67,     0,    74,    68,    69,    70,
      71,    72,     0,     0,     0,    73,     0,     0,     0,     0,
       0,    74,    55,    56,    57,    58,    59,    60,     0,     0,
       0,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,     0,   -37,     0,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,     0,     0,     0,
      73,     0,   -37,   -37,   -37,     0,    74,     0,   -37,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,     0,   -38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -38,   -38,   -38,     0,     0,     0,   -38
  };

  const short int
  parser::yycheck_[] =
  {
      16,    17,    40,    19,    20,    21,    22,    23,    39,    90,
      14,    16,    17,    27,    28,    26,    32,    14,    29,    14,
      58,    57,    38,    39,    40,    94,    95,    57,    57,    60,
      41,    14,    59,    40,    40,    40,     9,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    53,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   140,
      41,    40,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    58,    57,    92,    93,   159,    14,
      20,     0,    22,    88,     3,     4,     5,    61,    -1,     8,
      92,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    27,    28,
      -1,    51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,
      39,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,   148,   149,    -1,    -1,    55,    56,    57,    -1,
      -1,    60,    57,    -1,   160,     3,     4,     5,    63,    -1,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    20,    -1,    22,    55,    56,    57,
      -1,    -1,    60,    -1,    62,     3,     4,     5,    -1,    -1,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    49,    50,    51,    52,    53,    -1,    27,
      28,    57,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    -1,    60,    -1,    62,     3,     4,     5,    -1,    -1,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,     5,    -1,    -1,     8,    -1,    10,    11,
      12,    39,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    49,    50,    -1,    -1,    27,    28,    55,    56,    57,
      -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,
      -1,     5,    -1,    55,    56,    57,    -1,    -1,    12,    61,
      14,    15,    16,    17,    18,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    27,    28,    12,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      -1,    55,    56,    57,    -1,    -1,    20,    61,    22,    23,
      24,    -1,    49,    50,    -1,    -1,    -1,    -1,    55,    56,
      57,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    40,    57,    -1,    43,    44,    45,    46,    63,
      -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    63,    64,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    40,    40,    41,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    -1,    59,    -1,    -1,    63,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    40,    40,    41,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    -1,    -1,    -1,    -1,    63,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    63,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    63,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    58,    -1,    -1,    -1,    -1,    63,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    43,    44,    45,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    -1,    44,    45,    46,    -1,    63,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    63,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      57,    -1,    58,    59,    60,    -1,    63,    -1,    64,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    -1,    -1,    -1,    64
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    66,     0,     3,     4,     5,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    27,    28,    39,    49,
      50,    55,    56,    57,    60,    67,    68,    70,    71,    72,
      73,    74,    76,    77,    14,    69,    14,    14,    57,    57,
      57,    14,    59,    14,    72,    73,    73,    72,    72,    72,
      72,    72,    67,    40,    40,    19,    20,    21,    22,    23,
      24,    25,    26,    40,    43,    44,    45,    46,    49,    50,
      51,    52,    53,    57,    63,    67,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    40,    41,
      61,    72,     9,    41,    40,    57,    72,    72,    72,    73,
      67,    58,    72,    73,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    14,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    75,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    72,    66,    39,
      61,    72,    77,    72,    69,    69,    58,    58,    39,    59,
      58,    64,    62,    66,    39,    58,    72,    72,    62,    61,
      39,    58,    66,    72,    62,    58
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    65,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    77,
      77,    77
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     4,     2,     3,     3,     2,     1,     1,
       2,     2,     8,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     3,     2,     2,
       1,     0,     1,     4,     4,     8,     6,     4,     3,     3,
       5,     4
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
  "XORASSIGN", "LANDASSIGN", "LORASSIGN", "';'", "','", "'='", "COMMA",
  "'.'", "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "UMINUS", "'!'", "'~'", "'('", "')'", "':'", "'\\n'", "'{'",
  "'}'", "'['", "']'", "$accept", "start", "ends", "statement", "define",
  "tuple_lval", "tuple_exp", "expression", "lvalue", "rvalue", "arguments",
  "branch_head", "conditional", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    64,    64,    65,    70,    74,    78,    82,    87,    87,
      89,    90,    95,   100,   105,   112,   115,   116,   121,   122,
     123,   127,   127,   129,   136,   141,   145,   151,   156,   161,
     166,   171,   176,   181,   186,   191,   196,   201,   206,   211,
     219,   224,   231,   238,   245,   252,   256,   262,   278,   294,
     310,   326,   342,   358,   374,   390,   406,   422,   439,   456,
     472,   488,   504,   520,   533,   546,   559,   572,   573,   578,
     583,   591,   592,   597,   602,   603,   604,   606,   607,   613,
     614,   615
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
      60,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    53,    44,     2,
      57,    58,    51,    50,    40,    49,    43,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    39,
      48,    41,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    45,    62,    56,     2,     2,     2,
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
      35,    36,    37,    38,    42,    54
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
#line 2087 "zScript.tab.cpp" // lalr1.cc:1167
#line 617 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
