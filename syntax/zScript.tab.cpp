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
  case 5:
#line 71 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 598 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 78 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 608 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 83 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
#line 616 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 86 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 625 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 90 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);

                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 637 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 97 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::CodeBlock *block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(ZCodeExecuter::CodeBlock::LoopStructure, ZCodeExecuter::currentCodeExecuter->getCodeBlock());
                quint16 tmp = ((yystack_[1].value.count) & 0x7fff);

                while(--tmp) {
                    if(!block_while) {
                        zError << "\"containue\" Cannot be used here";
                        break;
                        YYABORT;
                    }

                    block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(ZCodeExecuter::CodeBlock::LoopStructure, block_while->parent);
                }

                if(!block_while) {
                    zError << "\"containue\" Cannot be used here";
                    break;
                    YYABORT;
                }

                /// 判断是否是以break结尾
                bool isBreak = !((yystack_[1].value.count) & 0x8000);

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto,
                                                               isBreak ? block_while->toForCodeBlock()->breakIndex
                                                                       : block_while->toForCodeBlock()->containueIndex);
            }
#line 669 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 124 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {}
#line 675 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 131 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 681 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 132 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 136 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0x8001;}
#line 693 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 137 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (0x8000 | ((yystack_[2].value.count) + 1));}
#line 699 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 138 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[0].value.count);}
#line 705 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 147 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete (yystack_[1].value.identifier);
            }
#line 715 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 162 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::beginCodeExecuter()->beginCodeBlock();

                if((yystack_[1].value.parameterList)) {
                    for(QByteArray *id : *(yystack_[1].value.parameterList)) {
                        ZCodeExecuter::currentCodeExecuter->getParameterList() << ZCodeExecuter::currentCodeExecuter->addIdentifier(*id);
                        delete id;
                    }

                    delete (yystack_[1].value.parameterList);
                }
            }
#line 732 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 173 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
#line 743 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 181 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
#line 751 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 185 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 760 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 191 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.parameterList) = Q_NULLPTR;}
#line 766 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 192 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = new QVarLengthArray<QByteArray*, 10>();
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 775 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 196 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = (yystack_[2].value.parameterList);
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 784 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 202 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[0].value.identifier));
                delete (yystack_[0].value.identifier);
            }
#line 793 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 206 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[2].value.identifier)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 805 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 216 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 811 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 217 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 817 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 220 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 823 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 221 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 829 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 226 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 837 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 229 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 849 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 236 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
#line 859 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 241 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 869 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 246 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Children);
            }
#line 879 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 251 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
#line 890 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 257 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
#line 900 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 262 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
#line 910 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 267 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
#line 920 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 272 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
#line 930 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 277 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
#line 940 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 282 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
#line 950 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 287 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
#line 960 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 292 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
#line 970 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 297 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
#line 980 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 302 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
#line 990 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 307 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
#line 1000 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 312 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
#line 1010 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 319 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
#line 1020 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 324 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 1032 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 331 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 1044 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 338 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 1056 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 345 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 1068 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 352 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1079 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 358 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("1", ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1090 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 364 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 1099 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 368 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
#line 1110 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 374 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Add);
                    }
            }
#line 1131 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 390 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Sub);
                    }
            }
#line 1152 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 406 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mul);
                    }
            }
#line 1173 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 422 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Div);
                    }
            }
#line 1194 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 438 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::And);
                    }
            }
#line 1215 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 454 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Or);
                    }
            }
#line 1236 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 470 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Xor);
                    }
            }
#line 1257 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 486 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mod);
                    }
            }
#line 1278 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 502 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value > *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Greater);
                    }
            }
#line 1299 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 518 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value < *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Less);
                    }
            }
#line 1320 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 534 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::EQ);
                    }
            }
#line 1341 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 550 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::NEQ);
                    }
            }
#line 1362 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 566 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STEQ);
                    }
            }
#line 1384 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 583 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STNEQ);
                    }
            }
#line 1406 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 600 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LE);
                    }
            }
#line 1427 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 616 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::GE);
                    }
            }
#line 1448 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 632 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAnd);
                    }
            }
#line 1469 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 648 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOr);
                    }
            }
#line 1490 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 664 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(~ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Contrary);
                    }
                }
#line 1508 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 677 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(! *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Not);
                    }
                }
#line 1526 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 690 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(- *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Minus);
                    }
                }
#line 1544 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 703 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        *last_code->value = ZCodeExecuter::createConstantByValue(+ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Abs);
                    }
                }
#line 1562 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 716 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
#line 1572 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 721 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
#line 1582 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 726 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Append);
            }
#line 1592 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 731 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1600 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 734 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1606 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 737 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1612 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 738 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 1618 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 742 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1632 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 751 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
#line 1640 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 753 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1651 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 104:
#line 759 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            }
#line 1663 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 765 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if指令在codeList中的index，方便修改if指令为假时要跳转到的指令位置
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toForCodeBlock()->ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;

                /// 开启使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(true);
            }
#line 1677 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 773 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 关闭使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(false);

                int ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toForCodeBlock()->ifInstructionIndex;

                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().value(ifInstructionIndex)->toValueCode()->value;
            }
#line 1691 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 110:
#line 792 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->isLoopStructure()) {
                    QList<ZCode*> &codeList = ZCodeExecuter::currentCodeExecuter->getCodeList();

                    /// 如果是普通的for循环结构
                    if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::NormalFor) {
                        QList<ZCode*> &tmpCodeList = ZCodeExecuter::currentCodeExecuter->getTmpCodeList();

                        /// 记录在for循环中执行containue语句时要跳转到的目标位置
                        *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toForCodeBlock()->containueIndex.data() = codeList.count();

                        /// 将for循环的第三个表达式的指令从临时列表添加到codeList
                        while(!tmpCodeList.isEmpty()) {
                            codeList << tmpCodeList.takeAt(0);
                        }

                        /// 清空栈
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
                    }

                    int index = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->beginCodeIndex;

                    /// 产生循环
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstant(QByteArray::number(index), ZVariant::Int));

                    /// 保存执行break语句时跳转到的位置
                    *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toForCodeBlock()->breakIndex.data() = codeList.count();
                }

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// index为if判断结果为假时要跳转到的位置
                *(yystack_[1].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
                (yylhs.value.value) = (yystack_[1].value.value);

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
#line 1733 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 115:
#line 835 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *(yystack_[0].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                (yystack_[0].value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1750 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 116:
#line 846 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *(yystack_[2].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
#line 1761 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1765 "zScript.tab.cpp" // lalr1.cc:859
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


  const short int parser::yypact_ninf_ = -134;

  const signed char parser::yytable_ninf_ = -62;

  const short int
  parser::yypact_[] =
  {
    -134,   200,  -134,   -12,    -6,   -49,  -134,   -47,  -134,     8,
      23,  -134,  -134,   -30,   -20,  -134,  -134,  -134,  -134,    23,
      23,  -134,    23,    23,    23,    23,    23,   496,  -134,  -134,
    -134,  -134,   -10,   -41,  -134,  -134,  -134,   -41,    -9,   547,
     148,  -134,   409,     0,   -24,  -134,    -8,     2,  -134,    23,
     -21,    23,   -41,  -134,     3,   771,   818,    23,  -134,   863,
     918,   935,   -55,   -55,   -55,   -55,   -32,   725,   -37,   -36,
     595,   265,     1,  -134,  -134,  -134,  -134,    23,     5,    23,
      23,    23,    23,    23,    23,    23,    23,    32,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
    -134,  -134,  -134,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,  -134,  -134,  -134,  -134,
    -134,   474,    23,   -12,   613,    23,   863,   -41,  -134,    23,
      23,   660,  -134,  -134,    35,  -134,  -134,  -134,  -134,  -134,
     726,    23,    49,    49,    49,    49,   167,   167,   880,   880,
    -134,   525,   525,   525,   167,   167,   -38,   -38,   -55,   -55,
     -55,   817,     3,   771,   -13,   863,   863,   863,   863,   863,
     863,   863,   863,   863,   863,   863,   772,   863,  -134,   863,
    -134,  -134,   678,  -134,   863,   863,     7,  -134,    12,   547,
    -134,  -134,  -134,    23,    40,  -134,  -134,   547,    11,   -14,
     337,  -134,   474,    20,  -134,  -134,    23,  -134,   474,    10,
    -134,  -134
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,   102,     0,    62,     0,
      29,    18,    20,     0,    45,    63,    64,    66,    65,     0,
       0,    14,     0,     0,     0,     0,     0,    32,     4,     2,
      46,     3,    22,     0,    13,     7,    96,     0,    10,     0,
      42,    43,     0,   114,   115,     6,    35,    44,    69,     0,
       0,   108,     0,    45,    31,    30,    42,     0,    26,     0,
      42,    42,    91,    92,    90,    89,     0,     0,    45,     0,
       0,     0,     0,    16,    17,    12,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       8,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,   110,   112,   111,
     113,     0,     0,     0,     0,     0,   109,     0,     5,     0,
       0,     0,    67,    68,     0,    27,    97,    15,    19,    21,
      42,     0,    81,    83,    82,    84,    85,    86,    87,    88,
      49,    75,    76,    77,    79,    80,    72,    71,    73,    74,
      78,     0,   100,    99,     0,    95,    53,    52,    50,    51,
      57,    54,    55,    56,    59,    58,    42,    47,   116,    36,
      37,   101,     0,   104,    41,    40,     0,    34,     0,     0,
      48,    70,   103,     0,     0,     2,    11,     0,     0,     0,
       0,   105,     0,     0,    23,    28,   108,    24,     0,     0,
      25,   106
  };

  const short int
  parser::yypgoto_[] =
  {
    -134,   -26,   -40,  -134,   -31,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,   -63,  -134,   -25,    42,    -1,  -134,
    -134,  -134,  -134,  -134,  -134,  -133,  -134,  -134,  -134,  -134
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,    31,    78,    75,    32,    33,    34,   199,    35,
      36,   188,    37,    69,    47,    38,    54,    39,    56,    41,
     164,    42,    50,   193,   206,   127,    43,    44,    45,   121
  };

  const short int
  parser::yytable_[] =
  {
      40,    66,   117,    71,   203,    73,    76,    46,   100,   118,
     -33,   134,    98,    48,    99,   129,   138,   139,    60,    61,
      49,   128,    51,    95,    96,    97,     3,    52,     4,    98,
      74,    99,    58,   -33,   135,     8,   132,    72,    77,    57,
     122,    40,    53,    15,    16,    17,    18,   120,   125,   123,
     129,   150,    55,   141,   187,    19,    20,   191,   198,   204,
     180,    59,    59,   202,    62,    63,    64,    65,    67,    70,
      40,   119,   208,   209,   162,     0,   140,    83,    84,   194,
     211,   178,    22,    23,   195,     0,     0,     0,    24,    25,
      26,   124,    27,   126,     0,     0,   183,    30,     0,   131,
       0,     0,     0,     0,     0,    91,    92,     0,    93,    94,
      95,    96,    97,   176,     0,     0,    98,     0,    99,    59,
      40,   142,   143,   144,   145,   146,   147,   148,   149,     0,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   163,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    59,   177,   196,     0,
       0,     0,   207,     0,   179,     0,   201,   182,   210,   200,
       0,   184,   185,     0,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   189,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,   114,   115,     0,     0,    40,
       2,    40,     0,     3,     0,     4,     0,    40,     5,     0,
       6,     7,     8,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,     0,     0,    93,    94,    95,    96,
      97,     0,    19,    20,    98,   197,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,    24,    25,    26,     3,    27,
       4,    28,    29,     5,    30,     6,     7,     8,     9,    10,
      11,    12,    13,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
      24,    25,    26,     0,    27,     0,    28,    29,   137,    30,
       3,     0,     4,     0,     0,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,     0,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,    24,    25,    26,     0,    27,     0,    28,    29,
     205,    30,     3,     0,     4,     0,     0,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,     0,    14,    15,
      16,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
       0,     0,     0,     0,    24,    25,    26,     3,    27,     4,
     116,    29,     5,    30,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,    18,     0,     3,
       0,     4,     0,     0,     0,     0,    19,    20,     8,     0,
       0,     0,     0,     0,     0,    68,    15,    16,    17,    18,
      21,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,     0,    22,    23,     0,     0,     0,     0,    24,
      25,    26,     0,    27,     0,     0,    29,     0,    30,    79,
      80,    81,    82,    83,    84,    22,    23,     0,     0,     0,
       0,    24,    25,    26,     0,    27,     0,     0,     0,     0,
      30,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,    91,    92,     0,    93,    94,    95,    96,    97,     0,
       0,     0,    98,    73,    99,     0,     0,    87,     0,     0,
      88,    89,    90,    91,    92,     0,    93,    94,    95,    96,
      97,     0,     0,     0,    98,     0,    99,     0,    74,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,    89,
      90,    91,    92,     0,    93,    94,    95,    96,    97,     0,
       0,     0,    98,    87,    99,   136,    88,    89,    90,    91,
      92,     0,    93,    94,    95,    96,    97,     0,     0,     0,
      98,     0,    99,   181,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,    88,    89,    90,    91,    92,     0,    93,
      94,    95,    96,    97,     0,     0,     0,    98,    87,    99,
     186,    88,    89,    90,    91,    92,     0,    93,    94,    95,
      96,    97,     0,     0,     0,    98,     0,    99,   192,    79,
      80,    81,    82,    83,    84,    85,    86,     0,   101,   102,
     103,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   130,   -39,   115,    87,     0,     0,    88,    89,
      90,    91,    92,     0,    93,    94,    95,    96,    97,     0,
       0,     0,    98,   133,    99,    79,    80,    81,    82,    83,
      84,    85,    86,     0,   101,   102,   103,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   130,   -38,
     -38,    87,     0,     0,    88,    89,    90,    91,    92,     0,
      93,    94,    95,    96,    97,     0,     0,     0,    98,     0,
      99,    79,    80,    81,    82,    83,    84,    85,    86,     0,
     101,   102,   103,     0,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,   115,    87,     0,     0,
      88,    89,    90,    91,    92,     0,    93,    94,    95,    96,
      97,     0,     0,     0,    98,   190,    99,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
       0,     0,     0,    87,     0,     0,    88,    89,    90,    91,
      92,     0,    93,    94,    95,    96,    97,     0,     0,     0,
      98,     0,    99,    88,    89,    90,    91,    92,     0,    93,
      94,    95,    96,    97,     0,     0,     0,    98,     0,    99,
     -60,   -60,   103,     0,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -61,   -61,   103,
       0,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,     0,     0,   -60,     0,   -60,   -60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -61,     0,   -61,   -61
  };

  const short int
  parser::yycheck_[] =
  {
       1,    26,    42,    29,    18,    46,    37,    19,    39,     9,
      47,    47,    67,    19,    69,    47,    15,    16,    19,    20,
      69,    52,    69,    61,    62,    63,     3,    19,     5,    67,
      71,    69,    52,    70,    70,    12,    68,    47,    47,    69,
      48,    42,    19,    20,    21,    22,    23,    71,    69,    47,
      47,    19,    10,    48,    19,    32,    33,    70,    18,    73,
     123,    19,    20,    52,    22,    23,    24,    25,    26,    27,
      71,    71,    52,   206,    99,    -1,    77,    28,    29,    72,
      70,   121,    59,    60,    72,    -1,    -1,    -1,    65,    66,
      67,    49,    69,    51,    -1,    -1,   127,    74,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    59,    60,
      61,    62,    63,   114,    -1,    -1,    67,    -1,    69,    77,
     121,    79,    80,    81,    82,    83,    84,    85,    86,    -1,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    -1,    -1,    -1,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   189,    -1,
      -1,    -1,   202,    -1,   122,    -1,   197,   125,   208,   195,
      -1,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,   141,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    48,    -1,    -1,   200,
       0,   202,    -1,     3,    -1,     5,    -1,   208,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23,    -1,    -1,    59,    60,    61,    62,
      63,    -1,    32,    33,    67,   193,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,     3,    69,
       5,    71,    72,     8,    74,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    69,    -1,    71,    72,    73,    74,
       3,    -1,     5,    -1,    -1,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    69,    -1,    71,    72,
      73,    74,     3,    -1,     5,    -1,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    65,    66,    67,     3,    69,     5,
      71,    72,     8,    74,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    -1,     3,
      -1,     5,    -1,    -1,    -1,    -1,    32,    33,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,
      66,    67,    -1,    69,    -1,    -1,    72,    -1,    74,    24,
      25,    26,    27,    28,    29,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,
      74,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    56,    57,    -1,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    46,    69,    -1,    -1,    50,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    -1,    69,    -1,    71,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    50,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    50,    69,    70,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    69,    70,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      50,    -1,    -1,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    50,    69,
      70,    53,    54,    55,    56,    57,    -1,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    67,    -1,    69,    70,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    47,    47,    48,    50,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    67,    68,    69,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    47,    47,
      48,    50,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    67,    -1,
      69,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    50,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    69,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    -1,    69,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    68,    -1,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    71
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    76,     0,     3,     5,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    19,    20,    21,    22,    23,    32,
      33,    46,    59,    60,    65,    66,    67,    69,    71,    72,
      74,    77,    80,    81,    82,    84,    85,    87,    90,    92,
      93,    94,    96,   101,   102,   103,    19,    89,    19,    69,
      97,    69,    19,    19,    91,    92,    93,    69,    52,    92,
      93,    93,    92,    92,    92,    92,    91,    92,    19,    88,
      92,    76,    47,    46,    71,    79,    79,    47,    78,    24,
      25,    26,    27,    28,    29,    30,    31,    50,    53,    54,
      55,    56,    57,    59,    60,    61,    62,    63,    67,    69,
      79,    32,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    47,    48,    71,    77,     9,    71,
      71,   104,    48,    47,    92,    69,    92,   100,    79,    47,
      47,    92,    68,    68,    47,    70,    70,    73,    15,    16,
      93,    48,    92,    92,    92,    92,    92,    92,    92,    92,
      19,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    91,    92,    95,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    92,    77,    92,
      89,    70,    92,    79,    92,    92,    70,    19,    86,    92,
      68,    70,    70,    98,    72,    72,    79,    92,    18,    83,
      76,    79,    52,    18,    73,    73,    99,    77,    52,   100,
      77,    70
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    75,    76,    76,    76,    77,    77,    77,    77,    77,
      78,    77,    77,    77,    77,    77,    79,    79,    80,    80,
      81,    81,    81,    82,    83,    83,    84,    86,    85,    87,
      87,    87,    88,    88,    88,    89,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      95,    96,    97,    96,    98,    99,    96,    96,   100,   100,
     101,   101,   102,   102,   103,   104,   103
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     3,     1,     1,     2,     2,
       0,     5,     2,     1,     1,     3,     1,     1,     1,     3,
       1,     3,     1,     7,     3,     4,     2,     0,     7,     1,
       2,     2,     0,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     3,     3,     2,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     2,     3,     1,     3,     0,     1,
       1,     4,     0,     5,     0,     0,    10,     2,     0,     1,
       2,     2,     2,     2,     1,     0,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "UNDEFINED", "GOTO", "RETURN",
  "BREAK", "CONTAINUE", "SWITCH", "CASE", "IDENTIFIER", "INT", "STRING",
  "BOOL", "DOUBLE", "EQ", "STEQ", "NEQ", "STNEQ", "LE", "GE", "LAND",
  "LOR", "ADDSELF", "SUBSELF", "LL", "GG", "DIVASSIGN", "MULASSIGN",
  "ADDASSIGN", "SUBASSIGN", "MODASSIGN", "ANDASSIGN", "ORASSIGN",
  "XORASSIGN", "LANDASSIGN", "LORASSIGN", "';'", "','", "'='", "COMMA",
  "'.'", "'?'", "':'", "'&'", "'|'", "'^'", "'>'", "'<'", "LTGT", "'-'",
  "'+'", "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'", "'['", "']'", "'('",
  "')'", "'\\n'", "'{'", "'}'", "'_'", "$accept", "start", "code", "$@1",
  "ends", "break", "loopEnds", "switch", "case", "goto_label", "function",
  "$@2", "return", "parameter", "define", "tuple_lval", "tuple_exp",
  "expression", "lvalue", "rvalue", "arguments", "branch_head", "$@3",
  "$@4", "$@5", "for_exp", "branch_body", "branch_else", "conditional",
  "$@6", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    69,    69,    69,    69,    71,    76,    77,    78,    83,
      86,    86,    97,   124,   125,   126,   129,   129,   131,   132,
     136,   137,   138,   141,   143,   144,   147,   162,   162,   181,
     184,   185,   191,   192,   196,   202,   206,   213,   216,   217,
     220,   221,   224,   224,   226,   229,   236,   241,   246,   251,
     257,   262,   267,   272,   277,   282,   287,   292,   297,   302,
     307,   312,   319,   324,   331,   338,   345,   352,   358,   364,
     368,   374,   390,   406,   422,   438,   454,   470,   486,   502,
     518,   534,   550,   566,   583,   600,   616,   632,   648,   664,
     677,   690,   703,   716,   721,   726,   731,   734,   737,   738,
     739,   742,   751,   751,   759,   765,   759,   787,   790,   790,
     792,   829,   832,   832,   834,   835,   835
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
      71,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,     2,     2,    63,    53,     2,
      69,    70,    61,    60,    47,    59,    50,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    46,
      57,    48,    56,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    55,    74,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    54,    73,    66,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    49,    58,    64
    };
    const unsigned int user_token_number_max_ = 303;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2403 "zScript.tab.cpp" // lalr1.cc:1167
#line 852 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


void yy::parser::error(const location_type& loc, const std::string& msg)
{
    std::cerr << "from " << loc.begin.line << " line, " << loc.begin.column << " column "
              << "to " << loc.end.line << " line, " << loc.end.column << " column, " << msg << std::endl;

    quick_exit(-1);
}

int yyFlexLexer::yywrap()
{
    if(!ZCodeExecuter::yywrap) {
        ZCodeExecuter::yywrap = true;

        return 0;
    }

    return 1;
}

#undef yyFlexLexer

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return ZCodeExecuter::yyFlexLexer->yylex();
}
