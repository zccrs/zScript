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

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


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
#line 78 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 636 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 7:
#line 85 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 646 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 90 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
#line 654 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 93 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 663 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 97 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);

                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 675 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 104 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
                        zError << "\"" + QString(isBreak ? "break" : "continue") + "\" Cannot be used here";
                        break;
                        YYABORT;
                    }

                    block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(type, block_while->parent);
                }

                if(!block_while) {
                    zError << "\"" + QString(isBreak ? "break" : "continue") + "\" Cannot be used here";
                    YYABORT;
                }

                if(isBreak) {
                    if(block_while->isLoopStructure()) {
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toLoopStructureCodeBlock()->breakIndex);
                    } else {
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toSwitchCodeBlock()->breakIndex);
                    }
                } else {
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toLoopStructureCodeBlock()->continueIndex);
                }

            }
#line 719 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 143 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {}
#line 725 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 150 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 731 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 151 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 737 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 155 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0x8001;}
#line 743 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 156 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (0x8000 | ((yystack_[2].value.count) + 1));}
#line 749 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 157 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[0].value.count);}
#line 755 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 160 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Switch, ZSharedVariantPointer(new ZSharedVariant()));
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::Switch);
            }
#line 766 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 168 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toSwitchCodeBlock()->breakIndex.data() = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                QHash<ZVariant, int> hashSwitch;

                hashSwitch.reserve((yystack_[1].value.cases)->size());

                bool existDefault = false;

                for(const QPair<ZSharedVariantPointer*, quint16> &c : *(yystack_[1].value.cases)) {
                    if(c.first) {
                        hashSwitch[*c.first->constData()] = c.second;
                    } else {
                        hashSwitch[ZVariant()] = c.second;
                        existDefault = true;
                    }
                }

                if(!existDefault)
                    hashSwitch[ZVariant()] = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                *(yystack_[3].value.value)->data() = QVariant::fromValue(hashSwitch);

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
#line 796 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 195 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.caseKey) = new QPair<ZSharedVariantPointer*, quint16>((yystack_[1].value.value), ZCodeExecuter::currentCodeExecuter->getCodeList().count());
            }
#line 804 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 200 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = new QVector<QPair<ZSharedVariantPointer*, quint16>>();
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 815 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 206 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 储存code的开始index
                (yystack_[1].value.count) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();
            }
#line 824 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 209 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[4].value.cases);
                (yylhs.value.cases)->append(QPair<ZSharedVariantPointer*, quint16>(Q_NULLPTR, (yystack_[3].value.count)));
            }
#line 833 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 213 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[2].value.cases);
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 844 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 221 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete (yystack_[1].value.identifier);
            }
#line 854 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 236 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 871 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 247 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
#line 882 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 255 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
#line 890 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 259 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 899 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 265 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.parameterList) = Q_NULLPTR;}
#line 905 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 266 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = new QVarLengthArray<QByteArray*, 10>();
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 914 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 270 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = (yystack_[2].value.parameterList);
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 923 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 276 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[0].value.identifier));
                delete (yystack_[0].value.identifier);
            }
#line 932 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 280 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[2].value.identifier)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 944 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 290 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 950 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 291 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 956 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 294 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 962 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 295 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 968 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 300 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 976 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 303 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 988 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 310 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
#line 998 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 315 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 1008 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 320 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Children);
            }
#line 1018 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 325 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
#line 1029 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 331 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
#line 1039 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 336 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
#line 1049 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 341 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
#line 1059 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 346 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
#line 1069 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 351 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
#line 1079 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 356 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
#line 1089 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 361 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
#line 1099 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 366 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
#line 1109 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 371 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
#line 1119 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 376 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
#line 1129 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 381 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
#line 1139 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 386 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
#line 1149 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 393 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
#line 1157 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 396 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 1167 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 401 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 1177 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 406 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 1187 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 411 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 1197 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 417 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, *(yystack_[0].value.value));

                delete (yystack_[0].value.value);
            }
#line 1209 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 424 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1220 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 430 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("1", ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1231 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 436 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 1240 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 440 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
#line 1251 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 446 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value + *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Add);
                    }
            }
#line 1272 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 462 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value - *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Sub);
                    }
            }
#line 1293 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 478 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value * *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mul);
                    }
            }
#line 1314 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 494 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value / *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Div);
                    }
            }
#line 1335 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 510 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value & *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::And);
                    }
            }
#line 1356 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 526 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value | *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Or);
                    }
            }
#line 1377 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 542 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value ^ *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Xor);
                    }
            }
#line 1398 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 558 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value % *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Mod);
                    }
            }
#line 1419 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 574 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value > *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Greater);
                    }
            }
#line 1440 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 590 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value < *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Less);
                    }
            }
#line 1461 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 606 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value == *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::EQ);
                    }
            }
#line 1482 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 622 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value != *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::NEQ);
                    }
            }
#line 1503 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 638 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(last_code->value->type() == pre_code->value->type()
                                                                     && *last_code->value == *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STEQ);
                    }
            }
#line 1525 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 655 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(last_code->value->type() == pre_code->value->type()
                                                                     && *last_code->value != *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::STNEQ);
                    }
            }
#line 1547 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 672 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value <= *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LE);
                    }
            }
#line 1568 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 688 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value >= *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::GE);
                    }
            }
#line 1589 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 704 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value && *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAnd);
                    }
            }
#line 1610 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 720 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[2].value.valueType) == ValueType::Constant && (yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[2].value.valueType);

                        ValueCode *pre_code = ZCodeExecuter::currentCodeExecuter->getCodeList().takeLast()->toValueCode();
                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(*last_code->value || *pre_code->value);

                        delete pre_code;
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOr);
                    }
            }
#line 1631 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 736 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(~ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Contrary);
                    }
                }
#line 1649 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 749 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(! *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Not);
                    }
                }
#line 1667 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 762 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(- *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Minus);
                    }
                }
#line 1685 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 775 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    if((yystack_[0].value.valueType) == ValueType::Constant) {
                        (yylhs.value.valueType) = (yystack_[0].value.valueType);

                        ValueCode *last_code = ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode();

                        last_code->value = ZCodeExecuter::createConstantByValue(+ *last_code->value);
                    } else {
                        (yylhs.value.valueType) = ValueType::Variant;

                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Abs);
                    }
                }
#line 1703 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 788 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
#line 1713 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 793 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
#line 1723 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 798 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Append);
            }
#line 1733 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 803 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1741 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 100:
#line 806 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1747 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 809 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1753 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 810 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 1759 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 104:
#line 814 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1773 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 823 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
#line 1781 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 825 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1792 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 831 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            }
#line 1804 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 837 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if指令在codeList中的index，方便修改if指令为假时要跳转到的指令位置
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;

                /// 开启使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(true);
            }
#line 1818 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 845 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 关闭使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(false);

                int ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex;

                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().value(ifInstructionIndex)->toValueCode()->value;
            }
#line 1832 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 112:
#line 863 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->isLoopStructure()) {
                    QList<ZCode*> &codeList = ZCodeExecuter::currentCodeExecuter->getCodeList();

                    /// 如果是普通的for循环结构
                    if(ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::NormalFor) {
                        QList<ZCode*> &tmpCodeList = ZCodeExecuter::currentCodeExecuter->getTmpCodeList();

                        /// 记录在for循环中执行continue语句时要跳转到的目标位置
                        *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->continueIndex.data() = codeList.count();

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
#line 1874 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 115:
#line 905 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *(yystack_[0].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                (yystack_[0].value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1891 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 116:
#line 916 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *(yystack_[2].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
#line 1902 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1906 "zScript.tab.cpp" // lalr1.cc:859
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
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -120;

  const signed char parser::yytable_ninf_ = -64;

  const short int
  parser::yypact_[] =
  {
    -120,   199,  -120,     7,    14,   -49,  -120,   -35,  -120,    17,
      28,  -120,  -120,   -32,   -14,  -120,  -120,  -120,  -120,    28,
      28,  -120,    28,    28,    28,    28,    28,   472,  -120,  -120,
    -120,    -7,    -4,   -28,  -120,  -120,  -120,    -4,    -3,   669,
     716,  -120,  -120,   413,    37,  -120,  -120,    -2,     5,  -120,
      28,   -15,    28,    -4,  -120,     6,   715,   935,    28,  -120,
     807,   862,   879,   -58,   -58,   -58,   -58,   -37,   623,   -43,
     -42,   493,   269,     1,  -120,  -120,    38,  -120,    28,     9,
      28,    28,    28,    28,    28,    28,    28,    28,    39,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,  -120,  -120,  -120,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,  -120,  -120,   413,
      28,     7,   540,    28,   807,    -4,  -120,    28,    28,   558,
    -120,  -120,    40,  -120,  -120,  -120,  -120,  -120,     2,   413,
     -16,   762,    28,   167,   167,   167,   167,     4,     4,   824,
     824,  -120,   440,   440,   440,     4,     4,   -55,   -55,   -58,
     -58,   -58,   761,     6,   715,    -8,   807,   807,   807,   807,
     807,   807,   807,   807,   807,   807,   807,   918,   807,  -120,
     807,  -120,  -120,   605,  -120,   807,   807,  -120,  -120,     8,
      20,  -120,    23,  -120,   413,   669,  -120,  -120,  -120,    28,
    -120,  -120,  -120,  -120,  -120,   669,   341,   413,  -120,  -120,
    -120,    28,    16,  -120
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     0,     1,     0,     0,     0,   105,     0,    64,     0,
      31,    16,    18,     0,    47,    65,    66,    68,    67,     0,
       0,    13,     0,     0,     0,     0,     0,    34,     2,    48,
       3,    20,     0,     0,    12,     6,    99,     0,     9,     0,
      44,    69,    45,     0,   114,   115,     5,    37,    46,    72,
       0,     0,   110,     0,    47,    33,    32,    44,     0,    28,
       0,    44,    44,    94,    95,    93,    92,     0,     0,    47,
       0,     0,     0,     0,    15,    11,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     7,    96,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,     0,   111,     0,     4,     0,     0,     0,
      70,    71,     0,    29,   100,    14,    17,    19,     0,     0,
       0,    44,     0,    84,    86,    85,    87,    88,    89,    90,
      91,    51,    78,    79,    80,    82,    83,    75,    74,    76,
      77,    81,     0,   103,   102,     0,    98,    55,    54,    52,
      53,    59,    56,    57,    58,    61,    60,    44,    49,   116,
      38,    39,   104,     0,   107,    43,    42,    21,    36,     0,
       0,    24,     0,    22,     0,     0,    50,    73,   106,     0,
       2,    23,    25,    27,    10,     0,     0,     0,   108,    30,
      26,   110,     0,   109
  };

  const signed char
  parser::yypgoto_[] =
  {
    -120,   -24,   -13,  -120,   -17,  -120,  -120,  -120,  -120,   -70,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,   -31,  -120,   -25,
      59,    -1,   -47,  -120,  -120,  -120,  -120,  -120,  -120,  -119,
    -120,  -120,  -120,  -120
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,    30,    79,    75,    31,    32,    33,    34,   139,
     140,   207,    35,    36,   189,    37,    70,    48,    38,    55,
      39,    57,    41,    42,   165,    43,    51,   199,   211,   125,
      44,    45,    46,   119
  };

  const short int
  parser::yytable_[] =
  {
      40,    67,   138,   192,    72,   -35,   132,    96,    97,    98,
      99,   127,   100,    99,     8,   100,   136,   137,    61,    62,
      77,    50,   101,    15,    16,    17,    18,    47,   -35,   133,
     117,     3,   130,     4,    49,    52,   126,    53,    58,    59,
       8,    73,    40,    74,    76,    78,   118,   120,    54,    15,
      16,    17,    18,   121,   127,   123,   138,   193,   142,   151,
     188,    19,    20,   197,    94,    95,    96,    97,    98,    56,
     194,    40,    99,   201,   100,   163,   202,   141,    60,    60,
     200,    63,    64,    65,    66,    68,    71,   213,    22,    23,
     181,   190,   212,     0,    24,    25,    26,     0,    27,     0,
       0,     0,    29,     0,     0,     0,   179,     0,   184,   122,
       0,   124,     0,     0,   177,     0,     0,   129,    40,     0,
       0,     0,     0,     0,     0,     0,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    40,   143,
     144,   145,   146,   147,   148,   149,   150,     0,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   164,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,    60,   178,   206,     0,   204,   180,
       0,   203,   183,     0,     0,     0,   185,   186,   208,     0,
       0,     0,     0,    40,   210,     0,    84,    85,     0,     2,
       0,   195,     3,     0,     4,    40,    40,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,    14,
      15,    16,    17,    18,    92,    93,     0,    94,    95,    96,
      97,    98,    19,    20,     0,    99,     0,   100,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,    22,
      23,     0,     0,     0,     0,    24,    25,    26,     0,    27,
     124,    28,     3,    29,     4,     0,     0,     5,     0,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,    24,    25,    26,     0,    27,
       0,    28,   135,    29,     3,     0,     4,     0,     0,     5,
       0,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    23,     0,     0,     0,     0,    24,    25,    26,
       0,    27,     0,    28,   209,    29,     3,     0,     4,     0,
       0,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,    14,    15,    16,    17,    18,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,     0,     0,    22,    23,     3,     0,     4,     0,    24,
      25,    26,     0,    27,     8,    28,     0,    29,     0,     0,
       0,     0,    69,    15,    16,    17,    18,    92,    93,     0,
      94,    95,    96,    97,    98,    19,    20,     0,    99,     0,
     100,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,     0,     0,    24,    25,
      26,     0,    27,     0,    88,     0,    29,    89,    90,    91,
      92,    93,     0,    94,    95,    96,    97,    98,     0,     0,
       0,    99,     0,   100,   134,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,    89,    90,    91,    92,    93,     0,
      94,    95,    96,    97,    98,     0,     0,     0,    99,    88,
     100,   182,    89,    90,    91,    92,    93,     0,    94,    95,
      96,    97,    98,     0,     0,     0,    99,     0,   100,   187,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,    89,
      90,    91,    92,    93,     0,    94,    95,    96,    97,    98,
       0,   128,     0,    99,    88,   100,   198,    89,    90,    91,
      92,    93,     0,    94,    95,    96,    97,    98,     0,     0,
       0,    99,   131,   100,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,     0,     0,     0,
      88,     0,     0,    89,    90,    91,    92,    93,     0,    94,
      95,    96,    97,    98,     0,     0,     0,    99,     0,   100,
      80,    81,    82,    83,    84,    85,    86,    87,     0,   102,
     103,   104,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   128,   115,   116,    88,     0,     0,    89,
      90,    91,    92,    93,     0,    94,    95,    96,    97,    98,
       0,     0,     0,    99,     0,   100,    80,    81,    82,    83,
      84,    85,    86,    87,     0,   102,   103,   104,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
     -41,   116,    88,     0,     0,    89,    90,    91,    92,    93,
       0,    94,    95,    96,    97,    98,     0,     0,     0,    99,
     196,   100,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,     0,     0,     0,    88,     0,
       0,    89,    90,    91,    92,    93,     0,    94,    95,    96,
      97,    98,     0,     0,     0,    99,     0,   100,    89,    90,
      91,    92,    93,     0,    94,    95,    96,    97,    98,     0,
       0,     0,    99,     0,   100,   -62,   -62,   104,     0,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -63,   -63,   104,     0,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,     0,
       0,   -62,     0,   -62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -63,     0,
     -63,   102,   103,   104,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,   -40,   -40,   102,   103,
     104,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,   116
  };

  const short int
  parser::yycheck_[] =
  {
       1,    26,    18,    19,    28,    48,    48,    62,    63,    64,
      68,    48,    70,    68,    12,    70,    15,    16,    19,    20,
      37,    70,    39,    21,    22,    23,    24,    20,    71,    71,
      43,     3,    69,     5,    20,    70,    53,    20,    70,    53,
      12,    48,    43,    47,    72,    48,     9,    49,    20,    21,
      22,    23,    24,    48,    48,    70,    18,    73,    49,    20,
      20,    33,    34,    71,    60,    61,    62,    63,    64,    10,
     140,    72,    68,    53,    70,   100,    53,    78,    19,    20,
      72,    22,    23,    24,    25,    26,    27,    71,    60,    61,
     121,   138,   211,    -1,    66,    67,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    -1,    -1,   119,    -1,   125,    50,
      -1,    52,    -1,    -1,   115,    -1,    -1,    58,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,   139,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   200,    -1,   195,   120,
      -1,   194,   123,    -1,    -1,    -1,   127,   128,   205,    -1,
      -1,    -1,    -1,   194,   207,    -1,    29,    30,    -1,     0,
      -1,   142,     3,    -1,     5,   206,   207,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    57,    58,    -1,    60,    61,    62,
      63,    64,    33,    34,    -1,    68,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,
     211,    72,     3,    74,     5,    -1,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    70,
      -1,    72,    73,    74,     3,    -1,     5,    -1,    -1,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    70,    -1,    72,    73,    74,     3,    -1,     5,    -1,
      -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    -1,    -1,    60,    61,     3,    -1,     5,    -1,    66,
      67,    68,    -1,    70,    12,    72,    -1,    74,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    57,    58,    -1,
      60,    61,    62,    63,    64,    33,    34,    -1,    68,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    70,    -1,    51,    -1,    74,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    -1,    70,    71,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    51,    -1,    -1,    54,    55,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    68,    51,
      70,    71,    54,    55,    56,    57,    58,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    68,    -1,    70,    71,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    51,    -1,    -1,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      -1,    48,    -1,    68,    51,    70,    71,    54,    55,    56,
      57,    58,    -1,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    70,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      51,    -1,    -1,    54,    55,    56,    57,    58,    -1,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    -1,    70,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    48,    48,    49,    51,    -1,    -1,    54,
      55,    56,    57,    58,    -1,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    68,    -1,    70,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    51,    -1,    -1,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    68,
      69,    70,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    51,    -1,
      -1,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    68,    -1,    70,    54,    55,
      56,    57,    58,    -1,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    68,    -1,    70,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    33,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    33,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    33,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    49
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    76,     0,     3,     5,     8,    10,    11,    12,    13,
      14,    15,    16,    17,    20,    21,    22,    23,    24,    33,
      34,    47,    60,    61,    66,    67,    68,    70,    72,    74,
      77,    80,    81,    82,    83,    87,    88,    90,    93,    95,
      96,    97,    98,   100,   105,   106,   107,    20,    92,    20,
      70,   101,    70,    20,    20,    94,    95,    96,    70,    53,
      95,    96,    96,    95,    95,    95,    95,    94,    95,    20,
      91,    95,    76,    48,    47,    79,    72,    79,    48,    78,
      25,    26,    27,    28,    29,    30,    31,    32,    51,    54,
      55,    56,    57,    58,    60,    61,    62,    63,    64,    68,
      70,    79,    33,    34,    35,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    48,    49,    77,     9,   108,
      49,    48,    95,    70,    95,   104,    79,    48,    48,    95,
      69,    69,    48,    71,    71,    73,    15,    16,    18,    84,
      85,    96,    49,    95,    95,    95,    95,    95,    95,    95,
      95,    20,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    94,    95,    99,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    95,    77,
      95,    92,    71,    95,    79,    95,    95,    71,    20,    89,
      97,    77,    19,    73,    84,    95,    69,    71,    71,   102,
      72,    53,    53,    77,    79,    95,    76,    86,    79,    73,
      77,   103,   104,    71
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    75,    76,    76,    77,    77,    77,    77,    77,    78,
      77,    77,    77,    77,    77,    79,    80,    80,    81,    81,
      81,    82,    83,    84,    85,    86,    85,    85,    87,    89,
      88,    90,    90,    90,    91,    91,    91,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    97,    97,    97,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,   100,   101,   100,   102,   103,   100,
     104,   104,   105,   106,   107,   108,   107
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     3,     1,     1,     2,     2,     0,
       5,     2,     1,     1,     3,     1,     1,     3,     1,     3,
       1,     4,     4,     3,     2,     0,     5,     3,     2,     0,
       7,     1,     2,     2,     0,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     2,     1,     1,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     3,     1,
       3,     0,     1,     1,     4,     0,     5,     0,     0,    10,
       0,     1,     2,     2,     1,     0,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VAR", "FUNCTION", "NEW", "DELETE",
  "THROW", "IF", "ELSE", "WHILE", "FOR", "UNDEFINED", "GOTO", "RETURN",
  "BREAK", "CONTINUE", "SWITCH", "CASE", "DEFAULT", "IDENTIFIER", "INT",
  "STRING", "BOOL", "DOUBLE", "EQ", "STEQ", "NEQ", "STNEQ", "LE", "GE",
  "LAND", "LOR", "ADDSELF", "SUBSELF", "LL", "GG", "DIVASSIGN",
  "MULASSIGN", "ADDASSIGN", "SUBASSIGN", "MODASSIGN", "ANDASSIGN",
  "ORASSIGN", "XORASSIGN", "LANDASSIGN", "LORASSIGN", "';'", "','", "'='",
  "COMMA", "'.'", "'?'", "':'", "'&'", "'|'", "'^'", "'>'", "'<'", "LTGT",
  "'-'", "'+'", "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "'_'", "$accept", "start", "code", "$@1",
  "ends", "break", "loopEnds", "switch_head", "switch", "case", "cases",
  "$@2", "goto_label", "function", "$@3", "return", "parameter", "define",
  "tuple_lval", "tuple_exp", "expression", "lvalue", "const", "rvalue",
  "arguments", "branch_head", "$@4", "$@5", "$@6", "for_exp",
  "branch_body", "branch_else", "conditional", "$@7", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    76,    76,    76,    78,    83,    84,    85,    90,    93,
      93,   104,   143,   144,   145,   148,   150,   151,   155,   156,
     157,   160,   168,   195,   200,   206,   206,   213,   221,   236,
     236,   255,   258,   259,   265,   266,   270,   276,   280,   287,
     290,   291,   294,   295,   298,   298,   300,   303,   310,   315,
     320,   325,   331,   336,   341,   346,   351,   356,   361,   366,
     371,   376,   381,   386,   393,   396,   401,   406,   411,   417,
     424,   430,   436,   440,   446,   462,   478,   494,   510,   526,
     542,   558,   574,   590,   606,   622,   638,   655,   672,   688,
     704,   720,   736,   749,   762,   775,   788,   793,   798,   803,
     806,   809,   810,   811,   814,   823,   823,   831,   837,   831,
     861,   861,   863,   902,   904,   905,   905
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
       2,     2,     2,    66,     2,     2,     2,    64,    54,     2,
      70,    71,    62,    61,    48,    60,    51,    63,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
      58,    49,    57,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    56,    74,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    55,    73,    67,     2,     2,     2,
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
#line 2631 "zScript.tab.cpp" // lalr1.cc:1167
#line 922 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


int yyFlexLexer::yywrap()
{
    return 1;
}

#undef yyFlexLexer

void yy::parser::error(const location_type& loc, const std::string& msg)
{
    char lineStr[1000];

    ZCodeExecuter::yyFlexLexer->yyin.seekg(-(int)loc.end.column - 1, std::ios::cur);
    ZCodeExecuter::yyFlexLexer->yyin.getline(lineStr, 1000);

    std::cerr << lineStr << std::endl;

    for (uint i = 0; i < loc.begin.column; ++i)
        std::cerr << " ";

    for (uint i = loc.begin.column; i < loc.end.column ; ++i)
        std::cerr << "^";

    std::cerr << std::endl;
    std::cerr << "from " << loc.begin.line << " line " << loc.begin.column << " column, "
              << "to " << loc.end.line << " line " << loc.end.column << " column, " << msg << std::endl;

    quick_exit(-1);
}

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    yylval = lval;
    yyloc = location;

    return ZCodeExecuter::yyFlexLexer->yylex();
}
