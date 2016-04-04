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

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

#line 47 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 61 "zScript.tab.cpp" // lalr1.cc:412


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
#line 147 "zScript.tab.cpp" // lalr1.cc:479

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
  case 2:
#line 54 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.value) = Q_NULLPTR;}
#line 587 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 4:
#line 56 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = (yystack_[1].value.value);
                std::cout << "(" << (yylhs.value.value)->typeName() << "," << (yylhs.value.value)->toString().toStdString() << ")" << std::endl;
            }
#line 596 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 62 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.value) = (yystack_[0].value.value);}
#line 602 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 6:
#line 63 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.identifier)->value = *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.identifier)->value;
            }
#line 611 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 67 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(!Global::identifiersHash.contains((yystack_[2].value.identifier)->name)) {
                    std::cerr << (yystack_[2].value.identifier)->name.toStdString() << " is undefined!" << std::endl;
                    delete (yystack_[2].value.identifier);
                    YYERROR;
                }

                *(yystack_[2].value.identifier)->value = *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.identifier)->value;
            }
#line 626 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 79 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(Global::identifiersHash.contains((yystack_[0].value.identifier)->name)) {
                    std::cerr << (yystack_[0].value.identifier)->name.constData() << " is defined!" << std::endl;
                    YYERROR;
                } else {
                    (yystack_[0].value.identifier)->value = new Global::ZVariant;
                    Global::identifiersHash[(yystack_[0].value.identifier)->name] = (yystack_[0].value.identifier);
                }

                (yylhs.value.identifier) = (yystack_[0].value.identifier);
            }
#line 642 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 90 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                zInfo << "function name: " << (yystack_[4].value.identifier)->name;
            }
#line 650 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 96 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(!Global::identifiersHash.contains((yystack_[0].value.identifier)->name)) {
                    std::cerr << (yystack_[0].value.identifier)->name.toStdString() << " is undefined!" << std::endl;
                    delete (yystack_[0].value.identifier);
                    YYERROR;
                }
                (yylhs.value.value) = (yystack_[0].value.identifier)->value;
            }
#line 663 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 104 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) + *(yystack_[0].value.value));
            }
#line 671 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 107 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) - *(yystack_[0].value.value));
            }
#line 679 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 110 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) * *(yystack_[0].value.value));
            }
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 113 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) / *(yystack_[0].value.value));
            }
#line 695 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 116 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) += *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 704 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 120 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) -= *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 713 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 124 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) *= *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 722 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 128 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) /= *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 731 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 132 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) & *(yystack_[0].value.value));
            }
#line 739 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 135 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) | *(yystack_[0].value.value));
            }
#line 747 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 138 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) ^ *(yystack_[0].value.value));
            }
#line 755 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 141 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) % *(yystack_[0].value.value));
            }
#line 763 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 144 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) &= *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 772 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 148 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) |= *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 781 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 152 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) ^= *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 790 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 156 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *(yystack_[2].value.value) %= *(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[2].value.value);
            }
#line 799 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 160 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) == *(yystack_[0].value.value));
            }
#line 807 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 163 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) != *(yystack_[0].value.value));
            }
#line 815 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 166 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) <= *(yystack_[0].value.value));
            }
#line 823 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 169 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) >= *(yystack_[0].value.value));
            }
#line 831 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 172 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) && *(yystack_[0].value.value));
            }
#line 839 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 175 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new Global::ZVariant(*(yystack_[2].value.value) || *(yystack_[0].value.value));
            }
#line 847 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 178 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ++*(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[0].value.value);
            }
#line 856 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 182 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (*(yystack_[1].value.value))++;
                (yylhs.value.value) = (yystack_[1].value.value);
            }
#line 865 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 186 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                --*(yystack_[0].value.value);
                (yylhs.value.value) = (yystack_[0].value.value);
            }
#line 874 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 190 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (*(yystack_[1].value.value))--;
                (yylhs.value.value) = (yystack_[1].value.value);
            }
#line 883 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 194 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.value) = new Global::ZVariant(~*(yystack_[0].value.value));}
#line 889 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 195 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.value) = new Global::ZVariant(!*(yystack_[0].value.value));}
#line 895 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 196 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.value) = new Global::ZVariant(-*(yystack_[0].value.value));}
#line 901 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 197 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.value) = new Global::ZVariant(+*(yystack_[0].value.value));}
#line 907 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 198 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.value) = (yystack_[1].value.value);}
#line 913 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 917 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -35;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
     -35,     0,   -35,    -5,    -2,   -35,   -17,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,   -35,   -34,   -15,    97,   -35,   -28,
      -3,   -35,   -14,   -14,   -14,   -14,   -14,   -14,    62,   -35,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,   -35,   -35,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,   -26,    97,   -35,    97,   163,
     163,   151,   151,   127,   127,    97,    97,    97,    97,    97,
      97,    97,    97,   135,   135,   135,   -18,   -18,   -14,   -14,
     -14,   -24,   -16,   -35
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     5,     8,     0,
       0,    11,    34,    36,    40,    41,    39,    38,     0,     4,
       0,     0,     0,     0,     0,     0,     0,    35,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,    42,     6,    28,
      29,    30,    31,    32,    33,    19,    18,    16,    17,    27,
      24,    25,    26,    20,    21,    22,    13,    12,    14,    15,
      23,     0,     0,     9
  };

  const signed char
  parser::yypgoto_[] =
  {
     -35,   -35,   -35,   -35,    20
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    15,    16,    17
  };

  const unsigned char
  parser::yytable_[] =
  {
       2,    37,    38,     3,     4,    37,    38,    18,     5,    21,
      19,     5,     6,    20,    29,    30,     7,     8,    55,     7,
       8,    81,    52,    53,    54,    82,     0,    22,    23,    24,
      25,    26,    27,    28,    83,     9,    10,     0,     9,    10,
      56,    11,    12,    13,    11,    12,    13,     0,    14,     0,
      58,    59,    60,    61,    62,    63,    64,     0,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,     0,     0,     0,    47,    48,    49,     0,     0,
      50,    51,    52,    53,    54,     0,     0,     0,     0,    57,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,     0,     0,     0,
      47,    48,    49,     0,     0,    50,    51,    52,    53,    54,
      31,    32,    33,    34,     0,     0,    37,    38,    31,    32,
      33,    34,     0,     0,    37,    38,     0,     0,     0,     0,
      47,    48,    49,     0,     0,    50,    51,    52,    53,    54,
      37,    38,     0,    50,    51,    52,    53,    54,    33,    34,
       0,     0,    37,    38,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    52,    53,    54
  };

  const signed char
  parser::yycheck_[] =
  {
       0,    19,    20,     3,     4,    19,    20,    12,    11,    12,
      12,    11,    12,    30,    48,    30,    19,    20,    46,    19,
      20,    47,    40,    41,    42,    49,    -1,     7,     8,     9,
      10,    11,    12,    13,    50,    38,    39,    -1,    38,    39,
      20,    44,    45,    46,    44,    45,    46,    -1,    48,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    47,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    -1,    38,    39,    40,    41,    42,
      13,    14,    15,    16,    -1,    -1,    19,    20,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    -1,    38,    39,    40,    41,    42,
      19,    20,    -1,    38,    39,    40,    41,    42,    15,    16,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    52,     0,     3,     4,    11,    12,    19,    20,    38,
      39,    44,    45,    46,    48,    53,    54,    55,    12,    12,
      30,    12,    55,    55,    55,    55,    55,    55,    55,    48,
      30,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    33,    34,    35,
      38,    39,    40,    41,    42,    46,    55,    47,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    47,    49,    50
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    51,    52,    52,    52,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     3,     1,     3,     3,     2,     6,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "VARIANT", "IDENTIFIER", "EQ", "NEQ",
  "LE", "GE", "AND", "OR", "ADDSELF", "SUBSELF", "DEQ", "MEQ", "AEQ",
  "SEQ", "MODEQ", "ANDEQ", "OREQ", "XOREQ", "','", "'='", "'?'", "':'",
  "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'", "'*'", "'/'", "'%'",
  "UMINUS", "'!'", "'~'", "'('", "')'", "';'", "'{'", "'}'", "$accept",
  "start", "assign", "statement", "expression", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    54,    54,    55,    56,    62,    63,    67,    79,    90,
      95,    96,   104,   107,   110,   113,   116,   120,   124,   128,
     132,   135,   138,   141,   144,   148,   152,   156,   160,   163,
     166,   169,   172,   175,   178,   182,   186,   190,   194,   195,
     196,   197,   198
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
       2,     2,     2,    44,     2,     2,     2,    42,    33,     2,
      46,    47,    40,    39,    29,    38,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,    48,
      37,    30,    36,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    34,    50,    45,     2,     2,     2,
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
      25,    26,    27,    28,    43
    };
    const unsigned int user_token_number_max_ = 284;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1321 "zScript.tab.cpp" // lalr1.cc:1167
#line 201 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


yyFlexLexer flexLexer;

int main()
{
    yy::parser parser;

    return parser.parse();
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

    return flexLexer.yylex();
}
