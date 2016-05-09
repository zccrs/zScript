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
#line 80 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                  error(yystack_[0].location, *(yystack_[0].value.msg));
                  delete (yystack_[0].value.msg);
                  YYABORT;
            }
#line 636 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 87 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 646 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 94 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 656 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 99 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
#line 664 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 102 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 673 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 106 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);

                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 685 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 113 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 729 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 152 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {}
#line 735 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 17:
#line 159 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 741 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 18:
#line 160 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 747 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 164 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0x8001;}
#line 753 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 165 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (0x8000 | ((yystack_[2].value.count) + 1));}
#line 759 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 166 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[0].value.count);}
#line 765 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 169 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Switch, ZSharedVariantPointer(new ZSharedVariant()));
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::Switch);
            }
#line 776 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 177 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 806 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 204 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.caseKey) = new QPair<ZSharedVariantPointer*, quint16>((yystack_[1].value.value), ZCodeExecuter::currentCodeExecuter->getCodeList().count());
            }
#line 814 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 209 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = new QVector<QPair<ZSharedVariantPointer*, quint16>>();
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 825 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 215 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 储存code的开始index
                (yystack_[1].value.count) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();
            }
#line 834 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 218 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[4].value.cases);
                (yylhs.value.cases)->append(QPair<ZSharedVariantPointer*, quint16>(Q_NULLPTR, (yystack_[3].value.count)));
            }
#line 843 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 222 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[2].value.cases);
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 854 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 230 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete (yystack_[1].value.identifier);
            }
#line 864 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 245 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 881 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 256 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
#line 892 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 264 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
#line 900 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 268 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 909 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 35:
#line 274 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.parameterList) = Q_NULLPTR;}
#line 915 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 275 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = new QVarLengthArray<QByteArray*, 10>();
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 924 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 279 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = (yystack_[2].value.parameterList);
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 933 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 285 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[0].value.identifier));
                delete (yystack_[0].value.identifier);
            }
#line 942 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 289 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[2].value.identifier)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 954 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 299 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 960 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 42:
#line 300 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 966 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 303 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 972 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 304 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 978 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 47:
#line 309 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 986 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 48:
#line 312 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 998 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 319 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
#line 1008 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 324 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 1018 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 329 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Children);
            }
#line 1028 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 334 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
#line 1039 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 340 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
#line 1049 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 345 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
#line 1059 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 350 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
#line 1069 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 355 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
#line 1079 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 360 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
#line 1089 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 365 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
#line 1099 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 370 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
#line 1109 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 375 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
#line 1119 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 380 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
#line 1129 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 385 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
#line 1139 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 390 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
#line 1149 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 395 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
#line 1159 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 402 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
#line 1167 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 405 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 1177 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 410 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 1187 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 415 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 1197 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 420 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 1207 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 426 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, *(yystack_[0].value.value));

                delete (yystack_[0].value.value);
            }
#line 1219 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 433 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1230 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 439 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("1", ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1241 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 445 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 1250 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 449 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
#line 1261 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 455 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1282 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 471 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1303 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 487 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1324 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 503 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1345 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 519 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1366 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 535 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1387 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 551 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1408 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 567 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1429 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 583 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1450 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 599 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1471 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 615 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1492 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 631 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1513 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 647 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1535 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 664 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1557 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 681 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1578 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 697 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1599 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 713 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1620 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 729 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1641 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 745 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1659 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 758 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1677 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 771 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1695 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 784 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1713 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 797 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
#line 1723 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 802 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
#line 1733 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 807 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Append);
            }
#line 1743 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 100:
#line 812 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1751 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 815 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1757 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 818 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1763 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 819 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 1769 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 823 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1783 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 832 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
#line 1791 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 834 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1802 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 108:
#line 840 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            }
#line 1814 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 846 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if指令在codeList中的index，方便修改if指令为假时要跳转到的指令位置
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;

                /// 开启使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(true);
            }
#line 1828 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 110:
#line 854 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 关闭使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(false);

                int ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex;

                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().value(ifInstructionIndex)->toValueCode()->value;
            }
#line 1842 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 113:
#line 872 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1884 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 116:
#line 914 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *(yystack_[0].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                (yystack_[0].value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1901 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 117:
#line 925 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *(yystack_[2].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
#line 1912 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 1916 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -101;

  const signed char parser::yytable_ninf_ = -65;

  const short int
  parser::yypact_[] =
  {
     -41,  -101,   204,  -101,    -5,    -4,   -50,  -101,   -48,  -101,
       4,     5,  -101,  -101,   -34,   -13,  -101,  -101,  -101,  -101,
       5,     5,  -101,     5,     5,     5,     5,     5,    28,   -41,
    -101,  -101,    -6,    -1,   -28,  -101,  -101,  -101,    -1,     8,
     622,   623,  -101,  -101,   419,    37,  -101,  -101,     9,    11,
    -101,     5,    -8,     5,    -1,  -101,    15,   669,   906,     5,
    -101,   763,   825,   866,   -64,   -64,   -64,   -64,   -35,   575,
     -40,   -38,   443,   273,    -3,  -101,  -101,    47,  -101,     5,
      18,     5,     5,     5,     5,     5,     5,     5,     5,    50,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,  -101,  -101,  -101,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,  -101,  -101,
     419,     5,    -5,   491,     5,   763,    -1,  -101,     5,     5,
     509,  -101,  -101,    67,  -101,  -101,  -101,  -101,  -101,    32,
     419,   -16,   717,     5,   646,   646,   646,   646,    59,    59,
     780,   780,  -101,   827,   827,   827,    59,    59,    29,    29,
     -64,   -64,   -64,   716,    15,   669,    16,   763,   763,   763,
     763,   763,   763,   763,   763,   763,   763,   763,   884,   763,
    -101,   763,  -101,  -101,   557,  -101,   763,   763,  -101,  -101,
      31,    48,  -101,    51,  -101,   419,   622,  -101,  -101,  -101,
       5,   -41,  -101,  -101,  -101,  -101,   622,   346,   419,  -101,
    -101,  -101,     5,    19,  -101
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     4,     0,     1,     0,     0,     0,   106,     0,    65,
       0,    32,    17,    19,     0,    48,    66,    67,    69,    68,
       0,     0,    14,     0,     0,     0,     0,     0,    35,     2,
      49,     3,    21,     0,     0,    13,     7,   100,     0,    10,
       0,    45,    70,    46,     0,   115,   116,     6,    38,    47,
      73,     0,     0,   111,     0,    48,    34,    33,    45,     0,
      29,     0,    45,    45,    95,    96,    94,    93,     0,     0,
      48,     0,     0,     0,     0,    16,    12,     0,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,     8,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,     0,   112,     0,     5,     0,     0,
       0,    71,    72,     0,    30,   101,    15,    18,    20,     0,
       0,     0,    45,     0,    85,    87,    86,    88,    89,    90,
      91,    92,    52,    79,    80,    81,    83,    84,    76,    75,
      77,    78,    82,     0,   104,   103,     0,    99,    56,    55,
      53,    54,    60,    57,    58,    59,    62,    61,    45,    50,
     117,    39,    40,   105,     0,   108,    44,    43,    22,    37,
       0,     0,    25,     0,    23,     0,     0,    51,    74,   107,
       0,     2,    24,    26,    28,    11,     0,     0,     0,   109,
      31,    27,   111,     0,   110
  };

  const signed char
  parser::yypgoto_[] =
  {
    -101,   -25,   -14,  -101,   -18,  -101,  -101,  -101,  -101,   -31,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,   -21,  -101,   -26,
      58,    -2,   -32,  -101,  -101,  -101,  -101,  -101,  -101,  -100,
    -101,  -101,  -101,  -101
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,    31,    80,    76,    32,    33,    34,    35,   140,
     141,   208,    36,    37,   190,    38,    71,    49,    39,    56,
      40,    58,    42,    43,   166,    44,    52,   200,   212,   126,
      45,    46,    47,   120
  };

  const short int
  parser::yytable_[] =
  {
      41,    68,   139,   193,    73,   100,     1,   101,     4,   -36,
       5,   133,   137,   138,   128,    48,    50,     9,    62,    63,
      78,    51,   102,    53,    54,    55,    16,    17,    18,    19,
     118,     4,   -36,     5,   134,   131,   127,    59,    20,    21,
       9,    60,    41,    74,     9,    77,   119,    75,    70,    16,
      17,    18,    19,    16,    17,    18,    19,    79,   194,   121,
     122,    20,    21,   124,   128,   139,    23,    24,   143,    57,
     152,    41,    25,    26,    27,   164,    28,   142,    61,    61,
      30,    64,    65,    66,    67,    69,    72,   189,   198,    23,
      24,   214,    97,    98,    99,    25,    26,    27,   100,    28,
     101,   182,   202,    30,   201,   203,   180,   191,   185,   123,
     195,   125,   213,     0,   178,     0,     0,   130,    41,     0,
      95,    96,    97,    98,    99,     0,   192,     0,   100,     0,
     101,     0,     0,     0,     0,     0,     0,    61,    41,   144,
     145,   146,   147,   148,   149,   150,   151,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   165,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    61,   179,   207,     0,   205,   181,
       0,   204,   184,     0,     0,     0,   186,   187,   209,     0,
       0,     0,     0,    41,   211,     0,     0,     0,     0,     0,
       0,   196,     0,     0,     3,    41,    41,     4,     0,     5,
       0,     0,     6,     0,     7,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,   206,     0,
       0,     0,     0,     0,     0,    23,    24,     0,     0,     0,
     125,    25,    26,    27,     0,    28,     4,    29,     5,    30,
       0,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,     0,     0,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,     0,     0,     0,     0,
      25,    26,    27,     0,    28,     0,    29,   136,    30,     4,
       0,     5,     0,     0,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,     0,     0,    15,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,     0,
       0,     0,     0,    25,    26,    27,     0,    28,     0,    29,
     210,    30,     4,     0,     5,     0,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,     0,     0,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
      23,    24,     0,     0,     0,     0,    25,    26,    27,     0,
      28,     0,    29,     0,    30,    89,     0,     0,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,     0,
       0,     0,   100,     0,   101,   135,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,     0,    89,     0,     0,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,     0,     0,     0,
     100,    89,   101,   183,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,     0,     0,     0,   100,     0,
     101,   188,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    89,
       0,     0,    90,    91,    92,    93,    94,     0,    95,    96,
      97,    98,    99,     0,   129,     0,   100,    89,   101,   199,
      90,    91,    92,    93,    94,     0,    95,    96,    97,    98,
      99,     0,     0,     0,   100,   132,   101,    81,    82,    83,
      84,    85,    86,    87,    88,     0,   103,   104,   105,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      75,     0,   116,   117,    89,    85,    86,    90,    91,    92,
      93,    94,     0,    95,    96,    97,    98,    99,     0,     0,
       0,   100,     0,   101,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,    93,    94,     0,    95,    96,    97,
      98,    99,     0,     0,     0,   100,     0,   101,   129,     0,
       0,    89,     0,     0,    90,    91,    92,    93,    94,     0,
      95,    96,    97,    98,    99,     0,     0,     0,   100,     0,
     101,    81,    82,    83,    84,    85,    86,    87,    88,     0,
     103,   104,   105,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,   -42,   117,    89,     0,
       0,    90,    91,    92,    93,    94,     0,    95,    96,    97,
      98,    99,     0,     0,     0,   100,   197,   101,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,    89,     0,     0,    90,    91,
      92,    93,    94,     0,    95,    96,    97,    98,    99,     0,
       0,     0,   100,     0,   101,    90,    91,    92,    93,    94,
       0,    95,    96,    97,    98,    99,     0,     0,     0,   100,
       0,   101,    81,    82,    83,    84,    85,    86,   -63,   -63,
     105,     0,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,     0,   -63,   -63,   -63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,    95,    96,
      97,    98,    99,     0,     0,   -63,   100,   -63,   101,   -64,
     -64,   105,     0,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,     0,   -64,   -64,   -64,   103,   104,   105,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,   -41,   -41,     0,   -64,     0,   -64,   103,
     104,   105,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,   117
  };

  const short int
  parser::yycheck_[] =
  {
       2,    27,    18,    19,    29,    69,    47,    71,     3,    49,
       5,    49,    15,    16,    49,    20,    20,    12,    20,    21,
      38,    71,    40,    71,    20,    20,    21,    22,    23,    24,
      44,     3,    72,     5,    72,    70,    54,    71,    33,    34,
      12,    54,    44,    49,    12,    73,     9,    48,    20,    21,
      22,    23,    24,    21,    22,    23,    24,    49,    74,    50,
      49,    33,    34,    71,    49,    18,    61,    62,    50,    11,
      20,    73,    67,    68,    69,   101,    71,    79,    20,    21,
      75,    23,    24,    25,    26,    27,    28,    20,    72,    61,
      62,    72,    63,    64,    65,    67,    68,    69,    69,    71,
      71,   122,    54,    75,    73,    54,   120,   139,   126,    51,
     141,    53,   212,    -1,   116,    -1,    -1,    59,   120,    -1,
      61,    62,    63,    64,    65,    -1,   140,    -1,    69,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    79,   140,    81,
      82,    83,    84,    85,    86,    87,    88,    -1,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   201,    -1,   196,   121,
      -1,   195,   124,    -1,    -1,    -1,   128,   129,   206,    -1,
      -1,    -1,    -1,   195,   208,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,     0,   207,   208,     3,    -1,     5,
      -1,    -1,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
     212,    67,    68,    69,    -1,    71,     3,    73,     5,    75,
      -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    -1,    71,    -1,    73,    74,    75,     3,
      -1,     5,    -1,    -1,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    -1,    71,    -1,    73,
      74,    75,     3,    -1,     5,    -1,    -1,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    -1,
      71,    -1,    73,    -1,    75,    52,    -1,    -1,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    -1,    71,    72,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    52,    -1,    -1,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    -1,    -1,    -1,
      69,    52,    71,    72,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    69,    -1,
      71,    72,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    52,
      -1,    -1,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    -1,    49,    -1,    69,    52,    71,    72,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    69,    70,    71,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    33,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      48,    -1,    49,    50,    52,    29,    30,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    -1,    71,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    58,    59,    -1,    61,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    -1,    71,    49,    -1,
      -1,    52,    -1,    -1,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    69,    -1,
      71,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    49,    50,    52,    -1,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    71,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    -1,    71,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      -1,    71,    25,    26,    27,    28,    29,    30,    33,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    70,    69,    72,    71,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    49,    50,    -1,    70,    -1,    72,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    47,    77,     0,     3,     5,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    20,    21,    22,    23,    24,
      33,    34,    48,    61,    62,    67,    68,    69,    71,    73,
      75,    78,    81,    82,    83,    84,    88,    89,    91,    94,
      96,    97,    98,    99,   101,   106,   107,   108,    20,    93,
      20,    71,   102,    71,    20,    20,    95,    96,    97,    71,
      54,    96,    97,    97,    96,    96,    96,    96,    95,    96,
      20,    92,    96,    77,    49,    48,    80,    73,    80,    49,
      79,    25,    26,    27,    28,    29,    30,    31,    32,    52,
      55,    56,    57,    58,    59,    61,    62,    63,    64,    65,
      69,    71,    80,    33,    34,    35,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    49,    50,    78,     9,
     109,    50,    49,    96,    71,    96,   105,    80,    49,    49,
      96,    70,    70,    49,    72,    72,    74,    15,    16,    18,
      85,    86,    97,    50,    96,    96,    96,    96,    96,    96,
      96,    96,    20,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    95,    96,   100,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    96,
      78,    96,    93,    72,    96,    80,    96,    96,    72,    20,
      90,    98,    78,    19,    74,    85,    96,    70,    72,    72,
     103,    73,    54,    54,    78,    80,    96,    77,    87,    80,
      74,    78,   104,   105,    72
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    76,    77,    77,    77,    78,    78,    78,    78,    78,
      79,    78,    78,    78,    78,    78,    80,    81,    81,    82,
      82,    82,    83,    84,    85,    86,    87,    86,    86,    88,
      90,    89,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   101,   102,   101,   103,   104,
     101,   105,   105,   106,   107,   108,   109,   108
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     3,     1,     1,     2,     2,
       0,     5,     2,     1,     1,     3,     1,     1,     3,     1,
       3,     1,     4,     4,     3,     2,     0,     5,     3,     2,
       0,     7,     1,     2,     2,     0,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     2,     1,     1,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     3,
       1,     3,     0,     1,     1,     4,     0,     5,     0,     0,
      10,     0,     1,     2,     2,     1,     0,     3
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
  "ORASSIGN", "XORASSIGN", "LANDASSIGN", "LORASSIGN", "ERROR", "';'",
  "','", "'='", "COMMA", "'.'", "'?'", "':'", "'&'", "'|'", "'^'", "'>'",
  "'<'", "LTGT", "'-'", "'+'", "'*'", "'/'", "'%'", "UMINUS", "'!'", "'~'",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "'_'", "$accept", "start",
  "code", "$@1", "ends", "break", "loopEnds", "switch_head", "switch",
  "case", "cases", "$@2", "goto_label", "function", "$@3", "return",
  "parameter", "define", "tuple_lval", "tuple_exp", "expression", "lvalue",
  "const", "rvalue", "arguments", "branch_head", "$@4", "$@5", "$@6",
  "for_exp", "branch_body", "branch_else", "conditional", "$@7", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    79,    79,    79,    80,    87,    92,    93,    94,    99,
     102,   102,   113,   152,   153,   154,   157,   159,   160,   164,
     165,   166,   169,   177,   204,   209,   215,   215,   222,   230,
     245,   245,   264,   267,   268,   274,   275,   279,   285,   289,
     296,   299,   300,   303,   304,   307,   307,   309,   312,   319,
     324,   329,   334,   340,   345,   350,   355,   360,   365,   370,
     375,   380,   385,   390,   395,   402,   405,   410,   415,   420,
     426,   433,   439,   445,   449,   455,   471,   487,   503,   519,
     535,   551,   567,   583,   599,   615,   631,   647,   664,   681,
     697,   713,   729,   745,   758,   771,   784,   797,   802,   807,
     812,   815,   818,   819,   820,   823,   832,   832,   840,   846,
     840,   870,   870,   872,   911,   913,   914,   914
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
       2,     2,     2,    67,     2,     2,     2,    65,    55,     2,
      71,    72,    63,    62,    49,    61,    52,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    48,
      59,    50,    58,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    57,    75,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    56,    74,    68,     2,     2,     2,
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
      45,    46,    47,    51,    60,    66
    };
    const unsigned int user_token_number_max_ = 305;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2635 "zScript.tab.cpp" // lalr1.cc:1167
#line 931 "/home/zhang/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
