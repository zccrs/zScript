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

/// 记录普通的for循环语句的if指令在codeList中的index
int forCycieBeginCodeIndex = -1;

Z_USE_NAMESPACE


#line 57 "zScript.tab.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "zScript.tab.hpp"

// User implementation prologue.

#line 71 "zScript.tab.cpp" // lalr1.cc:412


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
#line 157 "zScript.tab.cpp" // lalr1.cc:479

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
#line 71 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                  if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                          && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                      ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 601 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 78 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 611 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 86 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
#line 619 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 89 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Join);
            }
#line 628 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 93 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 636 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 96 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::CodeBlock *block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(ZCodeExecuter::CodeBlock::LoopStructure);

                if(!block_while) {
                    zError << "\"containue\" Cannot be used here";
                    YYABORT;
                }

                int index = block_while->type == ZCodeExecuter::CodeBlock::NormalFor ? block_while->toNormalFor()->lastExpressionActionIndex : block_while->beginCodeIndex;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstant(QByteArray::number(index), ZVariant::Int));
            }
#line 653 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 114 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete (yystack_[1].value.identifier);
            }
#line 663 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 128 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 680 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 139 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
#line 691 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 147 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
#line 699 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 151 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Join);
            }
#line 708 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 157 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.parameterList) = Q_NULLPTR;}
#line 714 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 158 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = new QVarLengthArray<QByteArray*, 10>();
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 723 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 162 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = (yystack_[2].value.parameterList);
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 732 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 168 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[0].value.identifier));
                delete (yystack_[0].value.identifier);
            }
#line 741 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 172 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[2].value.identifier)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 753 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 182 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 759 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 183 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 765 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 186 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 771 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 187 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 777 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 192 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 785 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 195 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 797 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 202 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
#line 807 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 207 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 817 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 212 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
                /// TODO
            }
#line 826 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 216 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
#line 837 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 222 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
#line 847 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 227 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
#line 857 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 232 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
#line 867 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 237 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
#line 877 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 242 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
#line 887 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 247 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
#line 897 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 252 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
#line 907 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 257 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
#line 917 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 262 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
#line 927 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 267 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
#line 937 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 272 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
#line 947 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 277 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
#line 957 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 284 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
#line 967 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 289 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 979 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 296 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 991 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 303 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 1003 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 310 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 1015 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 317 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 1024 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 321 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
#line 1035 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 327 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value + *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Add);
                    }
            }
#line 1056 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 343 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value - *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Sub);
                    }
            }
#line 1077 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 359 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value * *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mul);
                    }
            }
#line 1098 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 375 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value / *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Div);
                    }
            }
#line 1119 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 391 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value & *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::And);
                    }
            }
#line 1140 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 407 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value | *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Or);
                    }
            }
#line 1161 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 423 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value ^ *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Xor);
                    }
            }
#line 1182 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 439 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value % *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mod);
                    }
            }
#line 1203 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 455 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value > *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Greater);
                    }
            }
#line 1224 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 471 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value < *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Less);
                    }
            }
#line 1245 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 487 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::EQ);
                    }
            }
#line 1266 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 503 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::NEQ);
                    }
            }
#line 1287 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 519 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value == *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STEQ);
                    }
            }
#line 1309 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 536 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(pre_code->value->type() == last_code->value->type()
                                                                     && *pre_code->value != *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STNEQ);
                    }
            }
#line 1331 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 553 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value <= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LE);
                    }
            }
#line 1352 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 569 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value >= *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::GE);
                    }
            }
#line 1373 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 585 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value && *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAnd);
                    }
            }
#line 1394 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 601 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast());
                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(*pre_code->value || *last_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOr);
                    }
            }
#line 1415 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 617 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(~ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Contrary);
                    }
                }
#line 1433 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 630 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(! *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Not);
                    }
                }
#line 1451 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 643 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(- *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Minus);
                    }
                }
#line 1469 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 656 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last());

                        *last_code->value = ZCodeExecuter::createConstantByValue(+ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Abs);
                    }
                }
#line 1487 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 669 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
#line 1497 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 674 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
#line 1507 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 679 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1515 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 682 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1521 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 685 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1527 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 686 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 1533 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 690 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last())->value;
            }
#line 1547 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 699 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
#line 1555 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 701 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last())->value;
            }
#line 1566 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 707 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            }
#line 1578 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 713 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if语句的index
                forCycieBeginCodeIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;
            }
#line 1589 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 718 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                (yylhs.value.value) = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().value(forCycieBeginCodeIndex))->value;

                int currentCodeCount = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 使用lastExpressionActionIndex临时记录表达式3生成指令的个数
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toNormalFor()->lastExpressionActionIndex = currentCodeCount - forCycieBeginCodeIndex;

                if(currentCodeCount > 1 && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 1606 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 738 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->isLoopStructure()) {
                    zDebug << ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type;

                    /// 如果是普通的for循环结构
                    if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::NormalFor) {
                        QList<ZCode*> &codeList = ZCodeExecuter::currentCodeExecuter->getCodeList();
                        int forCycieLastExpressionInstructionsCount = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toNormalFor()->lastExpressionActionIndex;
                        ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toNormalFor()->lastExpressionActionIndex = codeList.count() - forCycieLastExpressionInstructionsCount;

                        /// 将for循环的第三个表达式的指令移动到正确的位置
                        while(--forCycieLastExpressionInstructionsCount) {
                            codeList.move(forCycieBeginCodeIndex + 1, codeList.count() - 1);
                        }
                    }

                    int index = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->beginCodeIndex;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstant(QByteArray::number(index), ZVariant::Int));
                }

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// index为if判断结果为假时要跳转到的位置
                *(yystack_[1].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
                (yylhs.value.value) = (yystack_[1].value.value);

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
#line 1640 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 772 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *(yystack_[0].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                (yystack_[0].value.value) = &static_cast<ValueCode*>(ZCodeExecuter::currentCodeExecuter->getCodeList().last())->value;
            }
#line 1657 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 783 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *(yystack_[2].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
#line 1668 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1672 "zScript.tab.cpp" // lalr1.cc:859
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

  const signed char parser::yytable_ninf_ = -53;

  const short int
  parser::yypact_[] =
  {
     -70,   173,   -70,    -6,    -5,   -59,   -70,   -56,   -70,    -4,
      21,   -39,   -33,   -70,   -70,   -70,   -70,    21,    21,   -70,
      21,    21,    21,    21,   447,   -70,   -70,   -70,   -70,   -70,
     -70,   -39,   -29,   545,   496,   -70,   367,    -7,   -48,   -70,
     -24,   -21,   -70,    21,   -41,    21,   -39,   -70,   -18,   594,
     246,   -70,   -70,   -70,   -70,   839,   905,   947,   -60,   -60,
     -60,   -60,   -36,   -34,   643,   233,   -70,    21,   -16,    21,
      21,    21,    21,    21,    21,    21,    21,    13,    21,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    21,    21,
     -70,   -70,   -70,    21,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,   -70,   -70,   -70,   -70,   -70,
     427,    21,    -6,   692,    21,   545,   -70,    21,    21,    15,
     -70,   -70,   -70,   595,    21,   143,   143,   143,   143,    -9,
      -9,   855,   855,   -70,   904,   904,   904,    -9,    -9,    22,
      22,   -60,   -60,   -60,   -18,   594,   -28,   495,   839,   839,
     839,   839,   839,   839,   839,   839,   839,   839,   644,   839,
     -70,   839,   -70,   -70,   741,   -70,   839,   839,   -70,   -31,
     545,   -70,   -70,   -70,    21,   -70,   -70,   545,   300,   -70,
     -70,    21,   790,   -70
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,    90,     0,    53,     0,
      20,     0,    36,    54,    55,    57,    56,     0,     0,    13,
       0,     0,     0,     0,    23,     4,     2,    37,     3,     7,
      84,     0,    10,     0,    33,    34,     0,   100,   101,     6,
      26,    35,    58,     0,     0,     0,     0,    36,    22,    21,
      33,    15,    16,    12,    17,     0,    33,    33,    80,    81,
      79,    78,    36,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       8,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,    98,    97,    99,
       0,     0,     0,     0,     0,     0,     5,     0,     0,     0,
      18,    85,    14,    33,     0,    70,    72,    71,    73,    74,
      75,    76,    77,    40,    64,    65,    66,    68,    69,    61,
      60,    62,    63,    67,    88,    87,     0,     0,    44,    43,
      41,    42,    48,    45,    46,    47,    50,    49,    33,    38,
     102,    27,    28,    89,     0,    92,    32,    31,    25,     0,
       0,    59,    39,    91,     0,     2,    11,     0,     0,    93,
      19,     0,     0,    94
  };

  const signed char
  parser::yypgoto_[] =
  {
     -70,   -20,   -35,   -70,   -12,   -70,   -70,   -70,   -70,   -70,
     -69,   -70,   -44,    50,    -1,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,    28,    68,    53,    29,    30,   169,    31,    63,
      41,    32,    48,    33,    50,    35,   146,    36,    44,   174,
     181,    37,    38,    39,   110
  };

  const short int
  parser::yytable_[] =
  {
      34,   106,   107,    51,    88,    43,    65,   -24,    45,   119,
      89,    40,    42,    46,    67,    54,    56,    57,   109,    66,
     111,    90,   112,   114,     3,   117,     4,    52,   124,   -24,
     133,   120,   168,     8,   116,    34,   175,   171,    47,    13,
      14,    15,    16,   162,   144,     0,    83,    84,    85,    86,
      87,    17,    18,     0,     0,    88,     0,     0,     0,   108,
      49,    89,     0,     0,    34,     0,   123,    55,    55,     0,
      58,    59,    60,    61,    64,   160,    20,    21,     0,    85,
      86,    87,    22,    23,     0,    24,    88,     0,     0,     0,
      27,     0,    89,   113,     0,   115,     0,     0,     0,     0,
       0,     0,   158,   165,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,    55,     0,   125,
     126,   127,   128,   129,   130,   131,   132,     0,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   145,   147,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,    55,   159,   178,     0,     0,   176,     0,
       0,   161,     0,     0,   164,   179,     0,   166,   167,    73,
      74,     0,     0,     2,   170,     0,     3,    34,     4,     0,
       0,     5,     0,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,    81,    82,     0,    83,    84,
      85,    86,    87,    17,    18,     0,     0,    88,     0,     0,
       0,     0,     0,    89,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,   177,     0,     0,     0,    20,    21,
       0,   182,     0,     0,    22,    23,     3,    24,     4,    25,
      26,     5,    27,     6,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    20,    21,
     104,     0,     0,     0,    22,    23,     0,    24,     0,    25,
      26,   122,    27,     3,     0,     4,     0,     0,     5,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,    21,     0,     0,     0,
       0,    22,    23,     0,    24,     0,    25,    26,   180,    27,
       3,     0,     4,     0,     0,     5,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,     0,     0,     0,    22,    23,
       3,    24,     4,   105,    26,     5,    27,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,    16,     0,
       3,     0,     4,     0,     0,     0,     0,    17,    18,     8,
       0,     0,     0,     0,    62,    13,    14,    15,    16,    19,
       0,     0,     0,     0,     0,     0,     0,    17,    18,     0,
       0,     0,    20,    21,     0,     0,     0,     0,    22,    23,
       0,    24,     0,     0,    26,     0,    27,     0,     0,     0,
       0,     0,    20,    21,     0,     0,     0,     0,    22,    23,
       0,    24,     0,     0,     0,     0,    27,    69,    70,    71,
      72,    73,    74,    75,    76,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,   103,
     104,    77,     0,     0,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,    89,   172,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    77,     0,     0,    78,    79,    80,    81,    82,     0,
      83,    84,    85,    86,    87,     0,     0,     0,     0,    88,
       0,    52,     0,     0,     0,    89,    69,    70,    71,    72,
      73,    74,    75,    76,     0,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   118,   -30,   104,
      77,     0,     0,    78,    79,    80,    81,    82,     0,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,    89,    69,    70,    71,    72,    73,
      74,    75,    76,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   -29,   -29,    77,
       0,     0,    78,    79,    80,    81,    82,     0,    83,    84,
      85,    86,    87,     0,     0,     0,     0,    88,   121,     0,
       0,     0,     0,    89,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,     0,
       0,    78,    79,    80,    81,    82,     0,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    88,   163,     0,     0,
       0,     0,    89,    69,    70,    71,    72,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
      78,    79,    80,    81,    82,     0,    83,    84,    85,    86,
      87,     0,     0,     0,     0,    88,   173,     0,     0,     0,
       0,    89,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,    78,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,   183,     0,     0,     0,     0,
      89,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,     0,     0,    77,     0,     0,    78,    79,
      80,    81,    82,     0,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    88,    78,    79,    80,    81,    82,    89,
      83,    84,    85,    86,    87,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,    89,    69,    70,    71,    72,
      73,    74,     0,     0,     0,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
       0,     0,     0,     0,     0,     0,    81,    82,     0,    83,
      84,    85,    86,    87,     0,     0,     0,     0,    88,     0,
     -51,   -51,     0,     0,    89,     0,   -51,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -52,   -52,     0,     0,     0,     0,   -52
  };

  const short int
  parser::yycheck_[] =
  {
       1,    36,     9,    42,    64,    64,    26,    43,    64,    43,
      70,    17,    17,    17,    43,    48,    17,    18,    66,    31,
      44,    33,    43,    64,     3,    43,     5,    66,    44,    65,
      17,    65,    17,    12,    46,    36,    67,    65,    17,    18,
      19,    20,    21,   112,    88,    -1,    55,    56,    57,    58,
      59,    30,    31,    -1,    -1,    64,    -1,    -1,    -1,    66,
      10,    70,    -1,    -1,    65,    -1,    67,    17,    18,    -1,
      20,    21,    22,    23,    24,   110,    55,    56,    -1,    57,
      58,    59,    61,    62,    -1,    64,    64,    -1,    -1,    -1,
      69,    -1,    70,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   115,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   175,    -1,    -1,   170,    -1,
      -1,   111,    -1,    -1,   114,   177,    -1,   117,   118,    26,
      27,    -1,    -1,     0,   124,    -1,     3,   178,     5,    -1,
      -1,     8,    -1,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    52,    53,    -1,    55,    56,
      57,    58,    59,    30,    31,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   174,    -1,    -1,    -1,    55,    56,
      -1,   181,    -1,    -1,    61,    62,     3,    64,     5,    66,
      67,     8,    69,    10,    11,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    55,    56,
      44,    -1,    -1,    -1,    61,    62,    -1,    64,    -1,    66,
      67,    68,    69,     3,    -1,     5,    -1,    -1,     8,    -1,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      -1,    61,    62,    -1,    64,    -1,    66,    67,    68,    69,
       3,    -1,     5,    -1,    -1,     8,    -1,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    61,    62,
       3,    64,     5,    66,    67,     8,    69,    10,    11,    12,
      13,    14,    -1,    16,    17,    18,    19,    20,    21,    -1,
       3,    -1,     5,    -1,    -1,    -1,    -1,    30,    31,    12,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,    -1,    -1,    67,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    61,    62,
      -1,    64,    -1,    -1,    -1,    -1,    69,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      44,    46,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    -1,    -1,    70,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    43,    43,    44,
      46,    -1,    -1,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    70,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    46,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    70,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    70,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      -1,    70,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,    -1,
      70,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    64,    49,    50,    51,    52,    53,    70,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    70,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,    -1,
      65,    66,    -1,    -1,    70,    -1,    71,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    71
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    73,     0,     3,     5,     8,    10,    11,    12,    13,
      14,    16,    17,    18,    19,    20,    21,    30,    31,    42,
      55,    56,    61,    62,    64,    66,    67,    69,    74,    77,
      78,    80,    83,    85,    86,    87,    89,    93,    94,    95,
      17,    82,    17,    64,    90,    64,    17,    17,    84,    85,
      86,    42,    66,    76,    48,    85,    86,    86,    85,    85,
      85,    85,    17,    81,    85,    73,    76,    43,    75,    22,
      23,    24,    25,    26,    27,    28,    29,    46,    49,    50,
      51,    52,    53,    55,    56,    57,    58,    59,    64,    70,
      76,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    43,    44,    66,    74,     9,    66,    66,
      96,    44,    43,    85,    64,    85,    76,    43,    43,    43,
      65,    65,    68,    86,    44,    85,    85,    85,    85,    85,
      85,    85,    85,    17,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    84,    85,    88,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    85,
      74,    85,    82,    65,    85,    76,    85,    85,    17,    79,
      85,    65,    71,    65,    91,    67,    76,    85,    73,    76,
      68,    92,    85,    65
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    72,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    74,    74,    74,    74,    76,    76,    77,    79,    78,
      80,    80,    80,    81,    81,    81,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    89,
      90,    89,    91,    92,    89,    89,    93,    93,    94,    94,
      95,    96,    95
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     3,     1,     1,     2,     2,
       0,     5,     2,     1,     3,     1,     1,     2,     0,     7,
       1,     2,     2,     0,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     2,     1,     1,     3,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     2,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     1,     3,     0,     1,     1,     4,
       0,     5,     0,     0,    10,     2,     2,     2,     2,     2,
       1,     0,     3
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
  "'_'", "'['", "']'", "$accept", "start", "code", "$@1", "ends",
  "goto_label", "function", "$@2", "return", "parameter", "define",
  "tuple_lval", "tuple_exp", "expression", "lvalue", "rvalue", "arguments",
  "branch_head", "$@3", "$@4", "$@5", "branch_body", "branch_else",
  "conditional", "$@6", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    71,    71,    71,    76,    78,    83,    84,    85,    86,
      89,    89,    96,   108,   109,   112,   112,   114,   128,   128,
     147,   150,   151,   157,   158,   162,   168,   172,   179,   182,
     183,   186,   187,   190,   190,   192,   195,   202,   207,   212,
     216,   222,   227,   232,   237,   242,   247,   252,   257,   262,
     267,   272,   277,   284,   289,   296,   303,   310,   317,   321,
     327,   343,   359,   375,   391,   407,   423,   439,   455,   471,
     487,   503,   519,   536,   553,   569,   585,   601,   617,   630,
     643,   656,   669,   674,   679,   682,   685,   686,   687,   690,
     699,   699,   707,   713,   707,   735,   738,   767,   769,   769,
     771,   772,   772
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
#line 2299 "zScript.tab.cpp" // lalr1.cc:1167
#line 789 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
