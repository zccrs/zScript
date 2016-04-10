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

Global::Code *currentCode = Q_NULLPTR;
Global::Code *rootCode = Q_NULLPTR;


#line 56 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 70 "zScript.tab.cpp" // lalr1.cc:412


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
#line 156 "zScript.tab.cpp" // lalr1.cc:479

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
  case 4:
#line 65 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                currentCode->nodeList << (yystack_[1].value.node);
            }
#line 598 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 68 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                //currentCode->nodeList << $2;
            }
#line 606 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 74 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
            }
#line 614 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 79 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(currentCode->identifiersHash.contains(*(yystack_[0].value.identifier))) {
                    zError << *(yystack_[0].value.identifier) << "is defined!";
                    YYERROR;
                }

                currentCode->identifiersHash[*(yystack_[0].value.identifier)] = new Global::ZVariant;
                delete (yystack_[0].value.identifier);
            }
#line 628 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 93 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::Variant);
                (yylhs.value.node)->name = *(yystack_[0].value.identifier);
                delete (yystack_[0].value.identifier);
            }
#line 638 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 98 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 648 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 14:
#line 103 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = (yystack_[3].value.node);
                /// TODO
            }
#line 657 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 107 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::Add, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 668 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 113 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::Sub, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 679 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 119 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::Mul, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 690 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 125 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::Div, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 701 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 131 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::And, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 712 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 137 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::Or, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 723 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 143 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::Xor, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 734 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 149 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *child_node = new Global::Node(Global::Node::Mod, (yystack_[2].value.node), (yystack_[0].value.node));

                (yylhs.value.node) = new Global::Node(Global::Node::Assign, (yystack_[2].value.node), child_node);
                (yylhs.value.node)->value = (yystack_[2].value.node)->value;
            }
#line 745 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 155 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::PrefixAddSelf, Q_NULLPTR, (yystack_[0].value.node));
                (yylhs.value.node)->value = (yystack_[0].value.node)->value;
            }
#line 754 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 159 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::PrefixSubSelf, Q_NULLPTR, (yystack_[0].value.node));
                (yylhs.value.node)->value = (yystack_[0].value.node)->value;
            }
#line 763 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 163 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::PostfixAddSelf, (yystack_[1].value.node), Q_NULLPTR);
                (yylhs.value.node)->value = (yystack_[1].value.node)->value;
            }
#line 772 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 167 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::PostfixSubSelf, (yystack_[1].value.node), Q_NULLPTR);
                (yylhs.value.node)->value = (yystack_[1].value.node)->value;
            }
#line 781 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 173 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::Constant);
                (yylhs.value.node)->value = new Global::ZVariant;
            }
#line 790 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 177 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new Global::Node(Global::Node::Constant);
                (yylhs.value.node)->value = (yystack_[0].value.value);
            }
#line 799 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 181 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.node) = Q_NULLPTR;
            }
#line 808 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 185 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.node) = Q_NULLPTR;
            }
#line 817 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 189 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                Global::Node *propertyName = new Global::Node(Global::Node::Constant);

                propertyName->value = new Global::ZVariant(QString(*(yystack_[0].value.identifier)));
                (yylhs.value.node) = new Global::Node(Global::Node::Get, (yystack_[2].value.node), propertyName);
                (yylhs.value.node)->value = new Global::ZVariant();
            }
#line 829 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 196 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value + *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Add, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 844 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 206 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value - *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Sub, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 859 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 216 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value * *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Mul, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 874 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 226 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value / *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Div, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 889 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 236 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value & *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::And, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 904 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 246 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value | *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Or, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 919 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 256 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value ^ *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Xor, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 934 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 266 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value % *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Mod, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 949 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 276 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value == *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::EQ, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 964 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 286 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value != *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::NEQ, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 979 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 296 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value <= *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::LE, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 994 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 306 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value >= *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::GE, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 1009 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 316 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value && *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::LAnd, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 1024 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 326 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.node)->nodeType == Global::Node::Constant
                            && (yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[2].value.node);
                        (yylhs.value.node)->value = new Global::ZVariant(*(yystack_[2].value.node)->value || *(yystack_[0].value.node)->value);
                        delete (yystack_[0].value.node);
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::LOr, (yystack_[2].value.node), (yystack_[0].value.node));
                    }
            }
#line 1039 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 336 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[0].value.node);
                        *(yylhs.value.node)->value = ~*(yystack_[0].value.node)->value;
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Contrary, Q_NULLPTR, (yystack_[0].value.node));
                    }
                }
#line 1052 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 344 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[0].value.node);
                        *(yylhs.value.node)->value = !*(yystack_[0].value.node)->value;
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Not, Q_NULLPTR, (yystack_[0].value.node));
                    }
                }
#line 1065 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 352 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[0].value.node);
                        *(yylhs.value.node)->value = -*(yystack_[0].value.node)->value;
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Minus, Q_NULLPTR, (yystack_[0].value.node));
                    }
                }
#line 1078 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 360 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.node)->nodeType == Global::Node::Constant) {
                        (yylhs.value.node) = (yystack_[0].value.node);
                        *(yylhs.value.node)->value = +*(yystack_[0].value.node)->value;
                    } else {
                        (yylhs.value.node) = new Global::Node(Global::Node::Abs, Q_NULLPTR, (yystack_[0].value.node));
                    }
                }
#line 1091 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 368 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.node) = (yystack_[1].value.node);}
#line 1097 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1101 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -63;

  const signed char parser::yytable_ninf_ = -25;

  const short int
  parser::yypact_[] =
  {
     -63,   178,   -63,     1,     3,     8,   -26,   -25,   -24,   -63,
     -63,   225,   225,   225,   225,   225,   225,   225,    -4,   261,
     301,   -63,   209,    39,   -63,    26,    10,   -63,   225,   225,
     225,   683,   766,   780,   -34,   -34,   -34,   -34,   300,   -63,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   -63,   225,    54,   -63,   -63,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   -63,
     339,   194,     1,     1,   378,   417,   456,   818,   -63,    43,
      43,   783,   783,   715,   715,   731,   731,   731,   240,   240,
     -34,   -34,   -34,   683,   -22,   495,   -63,   683,   683,   683,
     683,   683,   683,   683,   683,   683,    60,   -63,   -63,   527,
      39,   -63,    -6,   -63,   -63,   225,   225,   225,   -63,   -63,
     -63,   111,   -63,    17,   566,   605,   683,   -63,   -63,   225,
     -63,   127,   644,   -63,   -63
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,    27,     1,     0,     0,     0,     0,     0,     0,    28,
      12,    27,    27,    27,    27,    27,    27,    27,     0,     0,
      10,    11,    27,     5,     8,     6,     0,    29,    27,    27,
      27,     0,    10,    10,    48,    49,    47,    46,     0,     3,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,     4,    27,     0,    25,    26,
      27,    27,    27,    27,    27,    27,    27,    27,    27,     2,
       0,    27,     0,     0,     0,     0,     0,    10,    50,    40,
      41,    42,    43,    44,    45,    36,    37,    38,    33,    32,
      34,    35,    39,    51,     0,     0,    31,    18,    17,    15,
      16,    22,    19,    20,    21,    13,    27,    58,     2,     0,
      59,     9,     0,    53,    54,    27,    27,    27,    30,    14,
      57,    27,    61,     0,     0,     0,    52,    60,     2,    27,
      56,    27,     0,     7,    55
  };

  const signed char
  parser::yypgoto_[] =
  {
     -63,   -62,   -63,   -60,   -11,    -3,   -63,   -63,   -63,     4
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,    18,    25,    19,    20,    21,    94,    22,    23
  };

  const short int
  parser::yytable_[] =
  {
      31,    31,    34,    35,    36,    37,    38,   106,    32,    33,
     117,    70,   111,   112,    24,    54,    26,    74,    75,    76,
      56,    27,    57,    28,    29,    30,    72,    77,   118,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,   123,    95,   121,    39,    71,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    72,    73,
     109,    42,    43,     3,     4,     5,   131,    96,     6,   128,
       7,     8,     9,    10,     0,   110,     0,     0,     0,     0,
       0,     0,    11,    12,    49,    50,    51,    52,    53,     0,
       0,     0,    54,     0,     0,     0,     0,    56,     0,    57,
       0,    13,    14,     0,   124,   125,   126,    15,    16,    17,
       0,     0,     0,   120,     3,     4,     5,     0,   132,     6,
       0,     7,     8,     9,    10,     0,     0,     0,     0,     0,
       3,     4,     5,    11,    12,     6,     0,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,    13,    14,     0,     0,     0,     0,    15,    16,
      17,     0,     0,     0,   127,     0,     0,     0,    13,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     2,     0,
     133,     3,     4,     5,     0,     0,     6,     0,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     5,
      11,    12,     6,     0,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     5,     0,    11,    12,     0,    13,
      14,     9,    10,     0,     0,    15,    16,    17,     0,     0,
       5,    11,    12,     0,     0,    13,    14,     9,    10,     0,
       0,    15,    16,    17,     0,     0,   108,    11,    12,     0,
      13,    14,     0,     0,     0,     0,    15,    16,    17,     0,
       0,    69,     0,     0,     0,     0,    13,    14,     0,     0,
       0,     0,    15,    16,    17,    40,     0,    41,     0,    42,
      43,    44,    45,    51,    52,    53,     0,     0,     0,    54,
       0,     0,     0,     0,    56,     0,    57,    46,    47,    48,
       0,     0,    49,    50,    51,    52,    53,     0,     0,     0,
      54,     0,    55,     0,    40,    56,    41,    57,    42,    43,
      44,    45,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,     0,    46,    47,    48,     0,
       0,    49,    50,    51,    52,    53,     0,     0,     0,    54,
      78,     0,     0,    40,    56,    41,    57,    42,    43,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    47,    48,     0,     0,
      49,    50,    51,    52,    53,     0,     0,     0,    54,     0,
     107,     0,    40,    56,    41,    57,    42,    43,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,    49,
      50,    51,    52,    53,     0,     0,     0,    54,   113,     0,
       0,    40,    56,    41,    57,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,    48,     0,     0,    49,    50,
      51,    52,    53,     0,     0,     0,    54,   114,     0,     0,
      40,    56,    41,    57,    42,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    47,    48,     0,     0,    49,    50,    51,
      52,    53,     0,     0,     0,    54,     0,   115,     0,    40,
      56,    41,    57,    42,    43,    44,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,    48,     0,     0,    49,    50,    51,    52,
      53,    40,     0,    41,    54,    42,    43,    44,    45,    56,
     119,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,    48,     0,     0,    49,    50,
      51,    52,    53,     0,     0,     0,    54,     0,   122,     0,
      40,    56,    41,    57,    42,    43,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,    47,    48,     0,     0,    49,    50,    51,
      52,    53,     0,     0,     0,    54,     0,   129,     0,    40,
      56,    41,    57,    42,    43,    44,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,    48,     0,     0,    49,    50,    51,    52,
      53,     0,     0,     0,    54,   130,     0,     0,    40,    56,
      41,    57,    42,    43,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    48,     0,     0,    49,    50,    51,    52,    53,
       0,     0,     0,    54,   134,     0,     0,    40,    56,    41,
      57,    42,    43,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      47,    48,     0,     0,    49,    50,    51,    52,    53,    40,
       0,    41,    54,    42,    43,     0,     0,    56,     0,    57,
       0,     0,     0,     0,     0,    40,     0,    41,     0,    42,
      43,    46,    47,    48,     0,     0,    49,    50,    51,    52,
      53,     0,     0,     0,    54,     0,     0,     0,     0,    56,
       0,    57,    49,    50,    51,    52,    53,     0,     0,     0,
      54,     0,     0,     0,     0,    56,     0,    57,    58,    59,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
       0,   -23,    58,    59,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,     0,   -24,   -23,   -23,     0,     0,
       0,   -23,     0,     0,    49,    50,    51,    52,    53,     0,
     -24,   -24,    54,     0,     0,   -24,     0,    56,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,     0,   116
  };

  const short int
  parser::yycheck_[] =
  {
      11,    12,    13,    14,    15,    16,    17,    69,    11,    12,
      32,    22,    72,    73,    13,    49,    13,    28,    29,    30,
      54,    13,    56,    49,    49,    49,    32,    30,    50,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    50,    56,   108,    51,     9,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    32,    49,
      71,    18,    19,     3,     4,     5,   128,    13,     8,    52,
      10,    11,    12,    13,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    23,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    56,
      -1,    41,    42,    -1,   115,   116,   117,    47,    48,    49,
      -1,    -1,    -1,    53,     3,     4,     5,    -1,   129,     8,
      -1,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    22,    23,     8,    -1,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    -1,    41,    42,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    41,    42,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,     0,    -1,
      53,     3,     4,     5,    -1,    -1,     8,    -1,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      22,    23,     8,    -1,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,     5,    -1,    22,    23,    -1,    41,
      42,    12,    13,    -1,    -1,    47,    48,    49,    -1,    -1,
       5,    22,    23,    -1,    -1,    41,    42,    12,    13,    -1,
      -1,    47,    48,    49,    -1,    -1,    52,    22,    23,    -1,
      41,    42,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    47,    48,    49,    14,    -1,    16,    -1,    18,
      19,    20,    21,    43,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    56,    36,    37,    38,
      -1,    -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    -1,    51,    -1,    14,    54,    16,    56,    18,    19,
      20,    21,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    36,    37,    38,    -1,
      -1,    41,    42,    43,    44,    45,    -1,    -1,    -1,    49,
      50,    -1,    -1,    14,    54,    16,    56,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      51,    -1,    14,    54,    16,    56,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    -1,    -1,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    49,    50,    -1,
      -1,    14,    54,    16,    56,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    50,    -1,    -1,
      14,    54,    16,    56,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    51,    -1,    14,
      54,    16,    56,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    14,    -1,    16,    49,    18,    19,    20,    21,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    49,    -1,    51,    -1,
      14,    54,    16,    56,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    -1,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    51,    -1,    14,
      54,    16,    56,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    50,    -1,    -1,    14,    54,
      16,    56,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    -1,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    49,    50,    -1,    -1,    14,    54,    16,
      56,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    -1,    41,    42,    43,    44,    45,    14,
      -1,    16,    49,    18,    19,    -1,    -1,    54,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    16,    -1,    18,
      19,    36,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    54,
      -1,    56,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    54,    -1,    56,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    50,    51,    -1,    -1,
      -1,    55,    -1,    -1,    41,    42,    43,    44,    45,    -1,
      50,    51,    49,    -1,    -1,    55,    -1,    54,    -1,    56,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    -1,    35
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    58,     0,     3,     4,     5,     8,    10,    11,    12,
      13,    22,    23,    41,    42,    47,    48,    49,    59,    61,
      62,    63,    65,    66,    13,    60,    13,    13,    49,    49,
      49,    61,    62,    62,    61,    61,    61,    61,    61,    51,
      14,    16,    18,    19,    20,    21,    36,    37,    38,    41,
      42,    43,    44,    45,    49,    51,    54,    56,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    33,    52,
      61,     9,    32,    49,    61,    61,    61,    62,    50,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    64,    61,    13,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    58,    51,    52,    61,
      66,    60,    60,    50,    50,    51,    35,    32,    50,    55,
      53,    58,    51,    50,    61,    61,    61,    53,    52,    51,
      50,    58,    61,    53,    50
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    57,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    66
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     3,     3,     2,     2,     8,     1,     3,
       1,     1,     1,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     0,     1,     2,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     1,     3,     4,     4,     8,     6,     4,     3,     3,
       5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "CONSTANT", "IDENTIFIER", "EQ",
  "STEQ", "NEQ", "STNEQ", "LE", "GE", "LAND", "LOR", "ADDSELF", "SUBSELF",
  "DEQ", "MEQ", "AEQ", "SEQ", "MODEQ", "ANDEQ", "OREQ", "XOREQ", "','",
  "'='", "'?'", "':'", "'&'", "'|'", "'^'", "'>'", "'<'", "'-'", "'+'",
  "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'", "'('", "')'", "';'", "'{'",
  "'}'", "'['", "']'", "'.'", "$accept", "start", "statement", "define",
  "expression", "lvalue", "rvalue", "arguments", "branch_head",
  "conditional", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    63,    63,    64,    65,    68,    73,    74,    79,    88,
      91,    91,    93,    98,   103,   107,   113,   119,   125,   131,
     137,   143,   149,   155,   159,   163,   167,   173,   177,   181,
     185,   189,   196,   206,   216,   226,   236,   246,   256,   266,
     276,   286,   296,   306,   316,   326,   336,   344,   352,   360,
     368,   371,   371,   373,   374,   375,   376,   378,   379,   380,
     381,   382
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
       2,     2,     2,    47,     2,     2,     2,    45,    36,     2,
      49,    50,    43,    42,    32,    41,    56,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    51,
      40,    33,    39,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    37,    53,    48,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    46
    };
    const unsigned int user_token_number_max_ = 287;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 1658 "zScript.tab.cpp" // lalr1.cc:1167
#line 385 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


yyFlexLexer *flexLexer;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    rootCode = new Global::Code();
    currentCode = rootCode;

    rootCode->identifiersHash["console"] = new Global::ZVariant(new Global::ZConsole);

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

int yyFlexLexer::yywrap()
{
    zDebug << "finished!";

    rootCode->exec();

    return 1;
}
