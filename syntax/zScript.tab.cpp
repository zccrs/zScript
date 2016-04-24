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
#line 76 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 598 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 83 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 608 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 88 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
#line 616 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 91 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 625 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 95 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);

                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 637 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 102 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 判断是否是以break结尾
                bool isBreak = !((yystack_[1].value.count) & 0x8000);

                ZCodeExecuter::CodeBlock::Type type = ZCodeExecuter::CodeBlock::LoopStructure;

                if(isBreak)
                    type = ZCodeExecuter::CodeBlock::Type(type | ZCodeExecuter::CodeBlock::Switch);

                ZCodeExecuter::CodeBlock *block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(type, ZCodeExecuter::currentCodeExecuter->getCodeBlock());

                quint16 tmp = ((yystack_[1].value.count) & 0x7fff);

                while(--tmp) {
                    if(!block_while) {
                        zError << "\"" + QString(isBreak ? "break" : "containue") + "\" Cannot be used here";
                        break;
                        YYABORT;
                    }

                    block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(type, block_while->parent);
                }

                if(!block_while) {
                    zError << "\"" + QString(isBreak ? "break" : "containue") + "\" Cannot be used here";
                    YYABORT;
                }

                if(isBreak) {
                    if(block_while->isLoopStructure()) {
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toLoopStructureCodeBlock()->breakIndex);
                    } else {
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toSwitchCodeBlock()->breakIndex);
                    }
                } else {
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toLoopStructureCodeBlock()->containueIndex);
                }

            }
#line 681 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 141 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {}
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 148 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 693 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 149 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 699 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 153 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0x8001;}
#line 705 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 154 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (0x8000 | ((yystack_[2].value.count) + 1));}
#line 711 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 155 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[0].value.count);}
#line 717 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 158 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Switch, ZSharedVariantPointer(new ZSharedVariant()));
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::Switch);
            }
#line 728 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 167 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toSwitchCodeBlock()->breakIndex.data() = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                QHash<ZVariant, int> hashSwitch;

                hashSwitch.reserve((yystack_[1].value.cases)->size());

                for(const QPair<ZSharedVariantPointer*, quint16> &c : *(yystack_[1].value.cases)) {
                    if(c.first) {
                        hashSwitch[*c.first->constData()] = c.second;
                    } else {
                        hashSwitch[ZVariant()] = c.second;
                    }
                }

                *(yystack_[3].value.value)->data() = QVariant::fromValue(hashSwitch);

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
#line 752 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 188 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.caseKey) = new QPair<ZSharedVariantPointer*, quint16>((yystack_[1].value.value), ZCodeExecuter::currentCodeExecuter->getCodeList().count());
            }
#line 760 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 194 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.cases) = new QVector<QPair<ZSharedVariantPointer*, quint16>>();}
#line 766 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 195 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = new QVector<QPair<ZSharedVariantPointer*, quint16>>();
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 777 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 201 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 储存code的开始index
                (yystack_[1].value.count) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();
            }
#line 786 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 204 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[4].value.cases);
                (yylhs.value.cases)->append(QPair<ZSharedVariantPointer*, quint16>(Q_NULLPTR, (yystack_[3].value.count)));
            }
#line 795 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 208 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[2].value.cases);
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 806 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 217 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete (yystack_[1].value.identifier);
            }
#line 816 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 232 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 833 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 243 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
#line 844 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 251 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
#line 852 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 255 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 861 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 261 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.parameterList) = Q_NULLPTR;}
#line 867 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 262 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = new QVarLengthArray<QByteArray*, 10>();
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 876 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 266 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = (yystack_[2].value.parameterList);
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 885 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 272 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[0].value.identifier));
                delete (yystack_[0].value.identifier);
            }
#line 894 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 276 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[2].value.identifier)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 906 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 286 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 912 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 287 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 918 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 290 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 924 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 291 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 930 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 296 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 938 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 299 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 950 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 306 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
#line 960 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 311 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 970 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 316 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Children);
            }
#line 980 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 321 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
#line 991 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 327 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
#line 1001 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 332 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
#line 1011 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 337 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
#line 1021 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 342 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
#line 1031 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 347 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
#line 1041 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 352 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
#line 1051 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 357 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
#line 1061 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 362 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
#line 1071 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 367 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
#line 1081 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 372 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
#line 1091 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 377 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
#line 1101 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 382 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
#line 1111 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 389 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
#line 1119 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 392 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 1129 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 397 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 1139 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 402 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 1149 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 407 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 1159 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 413 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, *(yystack_[0].value.value));

                delete (yystack_[0].value.value);
            }
#line 1171 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 420 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1182 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 426 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("1", ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1193 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 432 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 1202 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 436 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
#line 1213 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 442 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1234 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 458 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1255 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 474 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1276 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 490 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1297 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 506 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1318 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 522 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1339 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 538 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1360 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 554 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1381 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 570 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1402 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 586 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1423 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 602 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1444 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 618 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1465 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 634 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1487 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 651 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1509 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 668 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1530 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 684 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1551 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 700 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1572 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 716 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1593 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 732 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1611 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 745 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1629 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 100:
#line 758 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1647 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 771 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1665 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 784 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
#line 1675 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 789 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
#line 1685 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 104:
#line 794 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Append);
            }
#line 1695 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 799 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1703 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 802 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1709 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 805 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1715 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 806 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 1721 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 110:
#line 810 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1735 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 111:
#line 819 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
#line 1743 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 112:
#line 821 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1754 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 113:
#line 827 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            }
#line 1766 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 114:
#line 833 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if指令在codeList中的index，方便修改if指令为假时要跳转到的指令位置
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;

                /// 开启使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(true);
            }
#line 1780 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 115:
#line 841 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 关闭使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(false);

                int ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex;

                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().value(ifInstructionIndex)->toValueCode()->value;
            }
#line 1794 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 119:
#line 860 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->isLoopStructure()) {
                    QList<ZCode*> &codeList = ZCodeExecuter::currentCodeExecuter->getCodeList();

                    /// 如果是普通的for循环结构
                    if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::NormalFor) {
                        QList<ZCode*> &tmpCodeList = ZCodeExecuter::currentCodeExecuter->getTmpCodeList();

                        /// 记录在for循环中执行containue语句时要跳转到的目标位置
                        *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->containueIndex.data() = codeList.count();

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
                    *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->breakIndex.data() = codeList.count();
                }

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// index为if判断结果为假时要跳转到的位置
                *(yystack_[1].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
                (yylhs.value.value) = (yystack_[1].value.value);

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
#line 1836 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 124:
#line 903 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *(yystack_[0].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                (yystack_[0].value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1853 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 125:
#line 914 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *(yystack_[2].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
#line 1864 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1868 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -110;

  const signed char parser::yytable_ninf_ = -70;

  const short int
  parser::yypact_[] =
  {
    -110,    34,  -110,     0,     5,   -37,  -110,   -30,  -110,    21,
     551,  -110,  -110,   -18,    10,  -110,  -110,  -110,  -110,   551,
     551,  -110,   551,   551,   551,   551,   551,   574,  -110,  -110,
    -110,  -110,    12,   -43,   -61,  -110,  -110,  -110,   -43,    16,
     625,    93,  -110,  -110,   360,    -7,   -19,  -110,    17,    26,
    -110,   551,     6,   551,   -43,  -110,    31,   849,   896,   551,
    -110,   941,   996,  1013,   -42,   -42,   -42,   -42,   -38,   803,
     -41,   -39,   673,   214,    20,  -110,  -110,  -110,  -110,   -10,
    -110,   551,    35,   551,   551,   551,   551,   551,   551,   551,
     551,    71,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,  -110,  -110,  -110,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
    -110,  -110,  -110,  -110,  -110,   492,   551,     0,   691,   551,
     941,   -43,  -110,   551,   551,   738,  -110,  -110,    72,  -110,
    -110,  -110,  -110,  -110,   182,  -110,   426,   -13,   804,   551,
     394,   394,   394,   394,   -47,   -47,   958,   958,  -110,   603,
     603,   603,   -47,   -47,     7,     7,   -42,   -42,   -42,   895,
      31,   849,    22,   941,   941,   941,   941,   941,   941,   941,
     941,   941,   941,   941,   850,   941,  -110,   941,  -110,  -110,
     756,  -110,   941,   941,  -110,  -110,    23,    44,  -110,  -110,
      45,  -110,  -110,   426,   625,  -110,  -110,  -110,   551,  -110,
    -110,  -110,  -110,  -110,   625,   287,   492,  -110,  -110,  -110,
     551,    28,  -110
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,   111,     0,    70,     0,
      37,    18,    20,     0,    53,    71,    72,    74,    73,     0,
       0,    14,     0,     0,     0,     0,     0,    40,     4,     2,
      54,     3,    22,     0,     0,    13,     7,   105,     0,    10,
       0,    50,    75,    51,     0,   123,   124,     6,    43,    52,
      78,     0,     0,   117,     0,    53,    39,    38,    50,     0,
      34,     0,    50,    50,   100,   101,    99,    98,     0,     0,
      53,     0,     0,     0,     0,    16,    17,    12,    24,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     8,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,   119,   121,   120,   122,     0,     0,     0,     0,     0,
     118,     0,     5,     0,     0,     0,    76,    77,     0,    35,
     106,    15,    19,    21,     0,    28,     0,     0,    50,     0,
      90,    92,    91,    93,    94,    95,    96,    97,    57,    84,
      85,    86,    88,    89,    81,    80,    82,    83,    87,     0,
     109,   108,     0,   104,    61,    60,    58,    59,    65,    62,
      63,    64,    67,    66,    50,    55,   125,    44,    45,   110,
       0,   113,    49,    48,    23,    42,     0,     0,    27,    29,
       0,    33,    25,     0,     0,    56,    79,   112,     0,     2,
      26,    30,    32,    11,     0,     0,     0,   114,    36,    31,
     117,     0,   115
  };

  const signed char
  parser::yypgoto_[] =
  {
    -110,   -26,   -17,  -110,   -16,  -110,  -110,  -110,  -110,   -44,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,   -22,  -110,   -25,
      63,    -1,   -34,  -110,  -110,  -110,  -110,  -110,  -110,  -109,
    -110,  -110,  -110,  -110
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,    31,    82,    77,    32,    33,    34,    35,   146,
     147,   216,    36,    37,   196,    38,    71,    49,    39,    56,
      40,    58,    42,    43,   172,    44,    52,   208,   220,   131,
      45,    46,    47,   125
  };

  const short int
  parser::yytable_[] =
  {
      41,    68,   122,    73,    75,   144,   200,   -41,   144,   138,
     133,    78,    79,    97,    98,    99,   100,   101,    62,    63,
      48,   102,    80,   103,   104,    50,   102,   121,   103,    76,
     -41,   136,   139,    51,     2,   142,   143,     3,   132,     4,
      53,    54,     5,    41,     6,     7,     8,     9,    10,    11,
      12,    13,    59,   124,    14,    15,    16,    17,    18,   201,
      74,   202,   145,    60,    81,   123,   126,    19,    20,    99,
     100,   101,    41,    57,   127,   102,   129,   103,   170,   133,
     148,    21,    61,    61,   149,    64,    65,    66,    67,    69,
      72,   158,   195,   206,    22,    23,   209,   210,   211,   222,
      24,    25,    26,   203,    27,   188,    28,    29,   186,    30,
     197,   221,     0,     0,   128,   191,   130,   184,     0,     0,
       0,     0,   135,     0,    41,     0,   105,   106,   107,   199,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   118,   119,     0,    61,    41,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   171,     0,     0,     0,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,    61,   185,   215,     0,     0,   212,     0,   213,   187,
       0,     0,   190,     0,     8,     0,   192,   193,   217,   219,
       0,     0,    41,    15,    16,    17,    18,     0,     0,     0,
       0,     0,   204,     0,    41,    41,     0,     3,     0,     4,
       0,     0,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   214,     0,     0,    22,    23,     0,     0,     0,     0,
      24,    25,    26,   130,    27,     0,    28,    29,   141,    30,
       3,     0,     4,     0,     0,     5,     0,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,    24,    25,    26,     0,    27,     0,    28,
      29,   218,    30,     3,     0,     4,     0,     0,     5,     0,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,     0,    87,    88,     0,    24,    25,    26,     3,
      27,     4,   120,    29,     5,    30,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,    14,    15,    16,    17,
      18,    95,    96,     0,    97,    98,    99,   100,   101,    19,
      20,     0,   102,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,    24,    25,    26,     3,    27,     4,   198,    29,
       5,    30,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    15,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,     3,     0,     4,     0,    24,    25,
      26,     0,    27,     8,     0,    29,     0,    30,     0,     0,
       0,    55,    15,    16,    17,    18,     0,     3,     0,     4,
       0,     0,     0,     0,    19,    20,     8,     0,     0,     0,
       0,     0,     0,     0,    70,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,    22,    23,     0,     0,     0,     0,    24,    25,    26,
       0,    27,     0,     0,     0,     0,    30,     0,    83,    84,
      85,    86,    87,    88,    22,    23,     0,     0,     0,     0,
      24,    25,    26,     0,    27,     0,     0,     0,     0,    30,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
      95,    96,     0,    97,    98,    99,   100,   101,     0,     0,
       0,   102,    75,   103,     0,     0,    91,     0,     0,    92,
      93,    94,    95,    96,     0,    97,    98,    99,   100,   101,
       0,     0,     0,   102,     0,   103,     0,    76,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,    92,    93,    94,
      95,    96,     0,    97,    98,    99,   100,   101,     0,     0,
       0,   102,    91,   103,   140,    92,    93,    94,    95,    96,
       0,    97,    98,    99,   100,   101,     0,     0,     0,   102,
       0,   103,   189,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,    92,    93,    94,    95,    96,     0,    97,    98,
      99,   100,   101,     0,     0,     0,   102,    91,   103,   194,
      92,    93,    94,    95,    96,     0,    97,    98,    99,   100,
     101,     0,     0,     0,   102,     0,   103,   207,    83,    84,
      85,    86,    87,    88,    89,    90,     0,   105,   106,   107,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   134,   -47,   119,    91,     0,     0,    92,    93,    94,
      95,    96,     0,    97,    98,    99,   100,   101,     0,     0,
       0,   102,   137,   103,    83,    84,    85,    86,    87,    88,
      89,    90,     0,   105,   106,   107,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   134,   -46,   -46,
      91,     0,     0,    92,    93,    94,    95,    96,     0,    97,
      98,    99,   100,   101,     0,     0,     0,   102,     0,   103,
      83,    84,    85,    86,    87,    88,    89,    90,     0,   105,
     106,   107,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     0,     0,   119,    91,     0,     0,    92,
      93,    94,    95,    96,     0,    97,    98,    99,   100,   101,
       0,     0,     0,   102,   205,   103,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,     0,
       0,     0,    91,     0,     0,    92,    93,    94,    95,    96,
       0,    97,    98,    99,   100,   101,     0,     0,     0,   102,
       0,   103,    92,    93,    94,    95,    96,     0,    97,    98,
      99,   100,   101,     0,     0,     0,   102,     0,   103,   -68,
     -68,   107,     0,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -69,   -69,   107,     0,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,   -68,     0,   -68,   -68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -69,     0,   -69,   -69
  };

  const short int
  parser::yycheck_[] =
  {
       1,    26,     9,    29,    47,    18,    19,    48,    18,    48,
      48,    72,    73,    60,    61,    62,    63,    64,    19,    20,
      20,    68,    38,    70,    40,    20,    68,    44,    70,    72,
      71,    69,    71,    70,     0,    15,    16,     3,    54,     5,
      70,    20,     8,    44,    10,    11,    12,    13,    14,    15,
      16,    17,    70,    72,    20,    21,    22,    23,    24,    72,
      48,    74,    72,    53,    48,    72,    49,    33,    34,    62,
      63,    64,    73,    10,    48,    68,    70,    70,   103,    48,
      81,    47,    19,    20,    49,    22,    23,    24,    25,    26,
      27,    20,    20,    71,    60,    61,    73,    53,    53,    71,
      66,    67,    68,   147,    70,   127,    72,    73,   125,    75,
     144,   220,    -1,    -1,    51,   131,    53,   118,    -1,    -1,
      -1,    -1,    59,    -1,   125,    -1,    33,    34,    35,   146,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    -1,    81,   146,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   209,    -1,    -1,   203,    -1,   204,   126,
      -1,    -1,   129,    -1,    12,    -1,   133,   134,   214,   216,
      -1,    -1,   203,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,   149,    -1,   215,   216,    -1,     3,    -1,     5,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   208,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,   220,    70,    -1,    72,    73,    74,    75,
       3,    -1,     5,    -1,    -1,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    66,    67,    68,    -1,    70,    -1,    72,
      73,    74,    75,     3,    -1,     5,    -1,    -1,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    -1,    29,    30,    -1,    66,    67,    68,     3,
      70,     5,    72,    73,     8,    75,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    21,    22,    23,
      24,    57,    58,    -1,    60,    61,    62,    63,    64,    33,
      34,    -1,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    68,     3,    70,     5,    72,    73,
       8,    75,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,     3,    -1,     5,    -1,    66,    67,
      68,    -1,    70,    12,    -1,    73,    -1,    75,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    -1,     3,    -1,     5,
      -1,    -1,    -1,    -1,    33,    34,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    70,    -1,    -1,    -1,    -1,    75,    -1,    25,    26,
      27,    28,    29,    30,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    70,    -1,    -1,    -1,    -1,    75,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    47,    70,    -1,    -1,    51,    -1,    -1,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    68,    -1,    70,    -1,    72,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    51,    -1,    -1,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    51,    70,    71,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    68,
      -1,    70,    71,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    51,
      -1,    -1,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    51,    70,    71,
      54,    55,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    -1,    70,    71,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    48,    48,    49,    51,    -1,    -1,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    33,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    48,    48,    49,
      51,    -1,    -1,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    -1,    70,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    49,    51,    -1,    -1,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    68,    69,    70,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    51,    -1,    -1,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    68,
      -1,    70,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    -1,    70,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    33,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    77,     0,     3,     5,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    20,    21,    22,    23,    24,    33,
      34,    47,    60,    61,    66,    67,    68,    70,    72,    73,
      75,    78,    81,    82,    83,    84,    88,    89,    91,    94,
      96,    97,    98,    99,   101,   106,   107,   108,    20,    93,
      20,    70,   102,    70,    20,    20,    95,    96,    97,    70,
      53,    96,    97,    97,    96,    96,    96,    96,    95,    96,
      20,    92,    96,    77,    48,    47,    72,    80,    72,    73,
      80,    48,    79,    25,    26,    27,    28,    29,    30,    31,
      32,    51,    54,    55,    56,    57,    58,    60,    61,    62,
      63,    64,    68,    70,    80,    33,    34,    35,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    48,    49,
      72,    78,     9,    72,    72,   109,    49,    48,    96,    70,
      96,   105,    80,    48,    48,    96,    69,    69,    48,    71,
      71,    74,    15,    16,    18,    72,    85,    86,    97,    49,
      96,    96,    96,    96,    96,    96,    96,    96,    20,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      95,    96,   100,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    96,    78,    96,    93,    71,
      96,    80,    96,    96,    71,    20,    90,    98,    72,    78,
      19,    72,    74,    85,    96,    69,    71,    71,   103,    73,
      53,    53,    78,    80,    96,    77,    87,    80,    74,    78,
     104,   105,    71
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    76,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    78,    78,    78,    78,    78,    80,    80,    81,    81,
      82,    82,    82,    83,    83,    84,    85,    85,    86,    86,
      87,    86,    86,    86,    88,    90,    89,    91,    91,    91,
      92,    92,    92,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   100,
     101,   102,   101,   103,   104,   101,   101,   105,   105,   106,
     106,   107,   107,   108,   109,   108
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     3,     1,     1,     2,     2,
       0,     5,     2,     1,     1,     3,     1,     1,     1,     3,
       1,     3,     1,     4,     2,     4,     3,     2,     1,     2,
       0,     5,     3,     2,     2,     0,     7,     1,     2,     2,
       0,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     1,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     3,     1,     3,     0,     1,     1,
       4,     0,     5,     0,     0,    10,     2,     0,     1,     2,
       2,     2,     2,     1,     0,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "UNDEFINED", "GOTO", "RETURN",
  "BREAK", "CONTAINUE", "SWITCH", "CASE", "DEFAULT", "IDENTIFIER", "INT",
  "STRING", "BOOL", "DOUBLE", "EQ", "STEQ", "NEQ", "STNEQ", "LE", "GE",
  "LAND", "LOR", "ADDSELF", "SUBSELF", "LL", "GG", "DIVASSIGN",
  "MULASSIGN", "ADDASSIGN", "SUBASSIGN", "MODASSIGN", "ANDASSIGN",
  "ORASSIGN", "XORASSIGN", "LANDASSIGN", "LORASSIGN", "';'", "','", "'='",
  "COMMA", "'.'", "'?'", "':'", "'&'", "'|'", "'^'", "'>'", "'<'", "LTGT",
  "'-'", "'+'", "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'", "'['", "']'",
  "'('", "')'", "'\\n'", "'{'", "'}'", "'_'", "$accept", "start", "code",
  "$@1", "ends", "break", "loopEnds", "switch_head", "switch", "case",
  "cases", "$@2", "goto_label", "function", "$@3", "return", "parameter",
  "define", "tuple_lval", "tuple_exp", "expression", "lvalue", "const",
  "rvalue", "arguments", "branch_head", "$@4", "$@5", "$@6", "for_exp",
  "branch_body", "branch_else", "conditional", "$@7", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,    74,    74,    74,    74,    76,    81,    82,    83,    88,
      91,    91,   102,   141,   142,   143,   146,   146,   148,   149,
     153,   154,   155,   158,   164,   167,   188,   191,   194,   195,
     201,   201,   208,   214,   217,   232,   232,   251,   254,   255,
     261,   262,   266,   272,   276,   283,   286,   287,   290,   291,
     294,   294,   296,   299,   306,   311,   316,   321,   327,   332,
     337,   342,   347,   352,   357,   362,   367,   372,   377,   382,
     389,   392,   397,   402,   407,   413,   420,   426,   432,   436,
     442,   458,   474,   490,   506,   522,   538,   554,   570,   586,
     602,   618,   634,   651,   668,   684,   700,   716,   732,   745,
     758,   771,   784,   789,   794,   799,   802,   805,   806,   807,
     810,   819,   819,   827,   833,   827,   855,   858,   858,   860,
     897,   900,   900,   902,   903,   903
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
      72,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,     2,     2,    64,    54,     2,
      70,    71,    62,    61,    48,    60,    51,    63,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
      58,    49,    57,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    56,    75,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    55,    74,    67,     2,     2,     2,
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
      45,    46,    50,    59,    65
    };
    const unsigned int user_token_number_max_ = 304;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2530 "zScript.tab.cpp" // lalr1.cc:1167
#line 920 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
