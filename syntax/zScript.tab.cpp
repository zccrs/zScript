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
#line 70 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 598 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 77 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 608 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 82 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
#line 616 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 85 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Join);
            }
#line 625 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 89 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);

                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 637 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 96 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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

  case 15:
#line 127 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 675 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 128 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 681 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 132 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0x8001;}
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 133 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (0x8000 | ((yystack_[2].value.count) + 1));}
#line 693 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 134 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[0].value.count);}
#line 699 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 139 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete (yystack_[1].value.identifier);
            }
#line 709 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 154 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 726 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 165 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
#line 737 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 173 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
#line 745 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 177 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Join);
            }
#line 754 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 183 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.parameterList) = Q_NULLPTR;}
#line 760 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 184 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = new QVarLengthArray<QByteArray*, 10>();
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 769 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 188 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = (yystack_[2].value.parameterList);
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 778 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 194 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[0].value.identifier));
                delete (yystack_[0].value.identifier);
            }
#line 787 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 198 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[2].value.identifier)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 799 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 208 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 805 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 209 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 811 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 212 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 817 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 213 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 823 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 218 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 831 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 221 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 843 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 228 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
#line 853 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 233 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 863 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 238 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 872 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 242 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
#line 883 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 248 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
#line 893 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 253 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
#line 903 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 258 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
#line 913 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 263 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
#line 923 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 268 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
#line 933 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 273 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
#line 943 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 278 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
#line 953 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 283 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
#line 963 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 288 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
#line 973 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 293 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
#line 983 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 298 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
#line 993 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 303 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
#line 1003 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 310 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
#line 1013 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 315 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 1025 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 322 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 1037 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 329 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 1049 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 336 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 1061 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 343 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 1070 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 347 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
#line 1081 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 353 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1102 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 369 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1123 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 385 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1144 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 401 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1165 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 417 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1186 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 433 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1207 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 449 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1228 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 465 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1249 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 481 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1270 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 497 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1291 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 513 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1312 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 529 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1333 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 545 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1355 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 562 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1377 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 579 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1398 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 595 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1419 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 611 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1440 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 627 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1461 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 643 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1479 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 656 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1497 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 669 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1515 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 682 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1533 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 695 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
#line 1543 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 700 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
#line 1553 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 705 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1561 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 708 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1567 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 711 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1573 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 712 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 1579 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 716 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1593 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 725 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
#line 1601 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 727 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1612 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 733 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            }
#line 1624 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 739 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if指令在codeList中的index，方便修改if指令为假时要跳转到的指令位置
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toForCodeBlock()->ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;

                /// 开启使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(true);
            }
#line 1638 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 747 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 关闭使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(false);

                int ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toForCodeBlock()->ifInstructionIndex;

                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().value(ifInstructionIndex)->toValueCode()->value;
            }
#line 1652 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 766 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1694 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 809 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *(yystack_[0].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                (yystack_[0].value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1711 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 820 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *(yystack_[2].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
#line 1722 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1726 "zScript.tab.cpp" // lalr1.cc:859
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


  const short int parser::yypact_ninf_ = -130;

  const signed char parser::yytable_ninf_ = -58;

  const short int
  parser::yypact_[] =
  {
    -130,   178,  -130,   -11,    -8,   -53,  -130,   -51,  -130,     2,
      25,  -130,  -130,   -28,  -130,  -130,  -130,  -130,    25,    25,
    -130,    25,    25,    25,    25,   452,  -130,  -130,  -130,  -130,
     -22,   -35,  -130,  -130,   -35,   -21,   550,   501,  -130,   372,
      -6,   -43,  -130,   -20,   -14,  -130,    25,   -25,    25,   -35,
    -130,    -3,   599,   251,  -130,   795,   861,   903,   -56,   -56,
     -56,   -56,   -39,   -38,   648,   238,     0,  -130,  -130,  -130,
    -130,    25,     4,    25,    25,    25,    25,    25,    25,    25,
      25,    32,    25,    25,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,  -130,  -130,  -130,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,  -130,
    -130,  -130,  -130,  -130,   432,    25,   -11,   697,    25,   795,
     -35,  -130,    25,    25,    33,  -130,  -130,  -130,  -130,  -130,
     600,    25,    46,    46,    46,    46,   -23,   -23,   811,   811,
    -130,   860,   860,   860,   -23,   -23,   106,   106,   -56,   -56,
     -56,    -3,   599,   -13,   500,   795,   795,   795,   795,   795,
     795,   795,   795,   795,   795,   649,   795,  -130,   795,  -130,
    -130,   746,  -130,   795,   795,  -130,   -16,   550,  -130,  -130,
    -130,    25,  -130,  -130,   550,   305,  -130,  -130,    25,   -12,
    -130
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,    95,     0,    58,     0,
      25,    15,    17,    41,    59,    60,    62,    61,     0,     0,
      13,     0,     0,     0,     0,    28,     4,     2,    42,     3,
      19,     0,     7,    89,     0,    10,     0,    38,    39,     0,
     107,   108,     6,    31,    40,    63,     0,     0,   101,     0,
      41,    27,    26,    38,    22,     0,    38,    38,    85,    86,
      84,    83,    41,     0,     0,     0,     0,    20,    21,    12,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     8,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     103,   105,   104,   106,     0,     0,     0,     0,     0,   102,
       0,     5,     0,     0,     0,    23,    90,    14,    16,    18,
      38,     0,    75,    77,    76,    78,    79,    80,    81,    82,
      45,    69,    70,    71,    73,    74,    66,    65,    67,    68,
      72,    93,    92,     0,     0,    49,    48,    46,    47,    53,
      50,    51,    52,    55,    54,    38,    43,   109,    32,    33,
      94,     0,    97,    37,    36,    30,     0,     0,    64,    44,
      96,     0,     2,    11,     0,     0,    98,    24,   101,     0,
      99
  };

  const short int
  parser::yypgoto_[] =
  {
    -130,   -26,   -37,  -130,  -130,  -130,   -24,  -130,  -130,  -130,
    -130,  -130,   -59,  -130,   -34,    44,    -1,  -130,  -130,  -130,
    -130,  -130,  -130,  -129,  -130,  -130,  -130,  -130
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,    29,    72,    30,    31,    69,    32,    33,   176,
      34,    63,    44,    35,    51,    36,    53,    38,   153,    39,
      47,   181,   188,   120,    40,    41,    42,   114
  };

  const short int
  parser::yytable_[] =
  {
      37,    65,   110,   111,   -29,   124,    43,    67,    92,    45,
      70,    46,    94,    48,    93,   128,   129,    56,    57,    49,
      54,    66,    71,   113,   115,   121,   -29,   125,     3,   116,
       4,    68,    87,    88,    89,    90,    91,     8,    37,   118,
     122,    92,    50,    14,    15,    16,    17,    93,   131,   140,
     175,   182,   178,   190,    52,    18,    19,   169,   151,   189,
     112,     0,    55,    55,    37,    58,    59,    60,    61,    64,
     130,     0,    77,    78,     0,     0,     0,   167,     0,     0,
      21,    22,     0,     0,     0,     0,    23,    24,     0,    25,
     117,     0,   119,     0,    28,     0,   172,     0,    85,    86,
       0,    87,    88,    89,    90,    91,   165,     0,     0,     0,
      92,     0,     0,    37,     0,    55,    93,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   152,   154,     0,     0,
       0,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,    55,   166,   183,     0,     0,   185,     0,     0,   168,
     186,     0,   171,    89,    90,    91,   173,   174,     0,     0,
      92,     0,     0,     0,     0,   177,    93,     0,     2,     0,
       0,     3,     0,     4,    37,     0,     5,     0,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,   184,     0,     0,     0,     0,
       0,     0,   119,    21,    22,     0,     0,     0,     0,    23,
      24,     3,    25,     4,    26,    27,     5,    28,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    21,    22,   108,     0,     0,     0,    23,
      24,     0,    25,     0,    26,    27,   127,    28,     3,     0,
       4,     0,     0,     5,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,    23,    24,     0,    25,
       0,    26,    27,   187,    28,     3,     0,     4,     0,     0,
       5,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,    23,    24,     3,    25,     4,   109,    27,
       5,    28,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     3,     0,     4,     0,     0,
       0,     0,    18,    19,     8,     0,     0,     0,     0,    62,
      14,    15,    16,    17,    20,     0,     0,     0,     0,     0,
       0,     0,    18,    19,     0,     0,     0,    21,    22,     0,
       0,     0,     0,    23,    24,     0,    25,     0,     0,    27,
       0,    28,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,    23,    24,     0,    25,     0,     0,     0,
       0,    28,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,    81,     0,     0,    82,
      83,    84,    85,    86,     0,    87,    88,    89,    90,    91,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
      93,   179,    73,    74,    75,    76,    77,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,     0,    81,     0,     0,    82,
      83,    84,    85,    86,     0,    87,    88,    89,    90,    91,
       0,     0,     0,     0,    92,     0,    68,     0,     0,     0,
      93,    73,    74,    75,    76,    77,    78,    79,    80,     0,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   123,   -35,   108,    81,     0,     0,    82,    83,
      84,    85,    86,     0,    87,    88,    89,    90,    91,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,    93,
      73,    74,    75,    76,    77,    78,    79,    80,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   -34,   -34,    81,     0,     0,    82,    83,    84,
      85,    86,     0,    87,    88,    89,    90,    91,     0,     0,
       0,     0,    92,   126,     0,     0,     0,     0,    93,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,    82,    83,    84,    85,
      86,     0,    87,    88,    89,    90,    91,     0,     0,     0,
       0,    92,   170,     0,     0,     0,     0,    93,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,    82,    83,    84,    85,    86,
       0,    87,    88,    89,    90,    91,     0,     0,     0,     0,
      92,   180,     0,     0,     0,     0,    93,    73,    74,    75,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
       0,    81,     0,     0,    82,    83,    84,    85,    86,     0,
      87,    88,    89,    90,    91,     0,     0,     0,     0,    92,
      82,    83,    84,    85,    86,    93,    87,    88,    89,    90,
      91,     0,     0,     0,     0,    92,     0,     0,     0,     0,
       0,    93,    73,    74,    75,    76,    77,    78,     0,     0,
       0,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,     0,     0,     0,     0,
       0,     0,    85,    86,     0,    87,    88,    89,    90,    91,
       0,     0,     0,     0,    92,     0,   -56,   -56,     0,     0,
      93,     0,   -56,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -57,   -57,
       0,     0,     0,     0,   -57
  };

  const short int
  parser::yycheck_[] =
  {
       1,    27,    39,     9,    43,    43,    17,    42,    64,    17,
      34,    64,    36,    64,    70,    15,    16,    18,    19,    17,
      48,    43,    43,    66,    44,    49,    65,    65,     3,    43,
       5,    66,    55,    56,    57,    58,    59,    12,    39,    64,
      43,    64,    17,    18,    19,    20,    21,    70,    44,    17,
      17,    67,    65,    65,    10,    30,    31,   116,    92,   188,
      66,    -1,    18,    19,    65,    21,    22,    23,    24,    25,
      71,    -1,    26,    27,    -1,    -1,    -1,   114,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,
      46,    -1,    48,    -1,    69,    -1,   120,    -1,    52,    53,
      -1,    55,    56,    57,    58,    59,   107,    -1,    -1,    -1,
      64,    -1,    -1,   114,    -1,    71,    70,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   177,    -1,    -1,   182,    -1,    -1,   115,
     184,    -1,   118,    57,    58,    59,   122,   123,    -1,    -1,
      64,    -1,    -1,    -1,    -1,   131,    70,    -1,     0,    -1,
      -1,     3,    -1,     5,   185,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,   188,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,     3,    64,     5,    66,    67,     8,    69,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    55,    56,    44,    -1,    -1,    -1,    61,
      62,    -1,    64,    -1,    66,    67,    68,    69,     3,    -1,
       5,    -1,    -1,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    64,
      -1,    66,    67,    68,    69,     3,    -1,     5,    -1,    -1,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    61,    62,     3,    64,     5,    66,    67,
       8,    69,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,     3,    -1,     5,    -1,    -1,
      -1,    -1,    30,    31,    12,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    -1,    -1,    67,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    61,    62,    -1,    64,    -1,    -1,    -1,
      -1,    69,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    44,    46,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,
      70,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    43,    43,    44,    46,    -1,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    70,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    46,    -1,    -1,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    70,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    70,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      64,    65,    -1,    -1,    -1,    -1,    70,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      49,    50,    51,    52,    53,    70,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    70,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    -1,    65,    66,    -1,    -1,
      70,    -1,    71,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    -1,    -1,    -1,    71
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    73,     0,     3,     5,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    30,    31,
      42,    55,    56,    61,    62,    64,    66,    67,    69,    74,
      76,    77,    79,    80,    82,    85,    87,    88,    89,    91,
      96,    97,    98,    17,    84,    17,    64,    92,    64,    17,
      17,    86,    87,    88,    48,    87,    88,    88,    87,    87,
      87,    87,    17,    83,    87,    73,    43,    42,    66,    78,
      78,    43,    75,    22,    23,    24,    25,    26,    27,    28,
      29,    46,    49,    50,    51,    52,    53,    55,    56,    57,
      58,    59,    64,    70,    78,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    43,    44,    66,
      74,     9,    66,    66,    99,    44,    43,    87,    64,    87,
      95,    78,    43,    43,    43,    65,    65,    68,    15,    16,
      88,    44,    87,    87,    87,    87,    87,    87,    87,    87,
      17,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    86,    87,    90,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    87,    74,    87,    84,
      65,    87,    78,    87,    87,    17,    81,    87,    65,    71,
      65,    93,    67,    78,    87,    73,    78,    68,    94,    95,
      65
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    72,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    74,    74,    74,    74,    76,    76,    77,    77,    77,
      78,    78,    79,    81,    80,    82,    82,    82,    83,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    91,    92,    91,    93,    94,    91,
      91,    95,    95,    96,    96,    97,    97,    98,    99,    98
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     3,     1,     1,     2,     2,
       0,     5,     2,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     2,     0,     7,     1,     2,     2,     0,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       2,     1,     1,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     2,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     1,
       3,     0,     1,     1,     4,     0,     5,     0,     0,    10,
       2,     0,     1,     2,     2,     2,     2,     1,     0,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "UNDEFINED", "GOTO", "RETURN",
  "BREAK", "CONTAINUE", "IDENTIFIER", "INT", "STRING", "BOOL", "DOUBLE",
  "EQ", "STEQ", "NEQ", "STNEQ", "LE", "GE", "LAND", "LOR", "ADDSELF",
  "SUBSELF", "DIVASSIGN", "MULASSIGN", "ADDASSIGN", "SUBASSIGN",
  "MODASSIGN", "ANDASSIGN", "ORASSIGN", "XORASSIGN", "LANDASSIGN",
  "LORASSIGN", "';'", "','", "'='", "COMMA", "'.'", "'?'", "':'", "'&'",
  "'|'", "'^'", "'>'", "'<'", "LTGT", "'-'", "'+'", "'*'", "'/'", "'%'",
  "UMINUS", "'!'", "'~'", "PROMOTION", "'('", "')'", "'\\n'", "'{'", "'}'",
  "'_'", "'['", "']'", "$accept", "start", "code", "$@1", "break",
  "loopEnds", "ends", "goto_label", "function", "$@2", "return",
  "parameter", "define", "tuple_lval", "tuple_exp", "expression", "lvalue",
  "rvalue", "arguments", "branch_head", "$@3", "$@4", "$@5", "for_exp",
  "branch_body", "branch_else", "conditional", "$@6", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    68,    68,    68,    68,    70,    75,    76,    77,    82,
      85,    85,    96,   123,   124,   127,   128,   132,   133,   134,
     137,   137,   139,   154,   154,   173,   176,   177,   183,   184,
     188,   194,   198,   205,   208,   209,   212,   213,   216,   216,
     218,   221,   228,   233,   238,   242,   248,   253,   258,   263,
     268,   273,   278,   283,   288,   293,   298,   303,   310,   315,
     322,   329,   336,   343,   347,   353,   369,   385,   401,   417,
     433,   449,   465,   481,   497,   513,   529,   545,   562,   579,
     595,   611,   627,   643,   656,   669,   682,   695,   700,   705,
     708,   711,   712,   713,   716,   725,   725,   733,   739,   733,
     761,   764,   764,   766,   803,   806,   806,   808,   809,   809
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
      66,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    59,    49,     2,
      64,    65,    57,    56,    43,    55,    46,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    42,
      53,    44,    52,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    51,    69,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    50,    68,    62,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    45,    54,    60,
      63
    };
    const unsigned int user_token_number_max_ = 300;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2348 "zScript.tab.cpp" // lalr1.cc:1167
#line 826 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
