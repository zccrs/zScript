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
#line 1 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:404

#include "zcode.h"
#define protected public
#include "lex.yy.cpp"
#undef protected

/// enable debug
#define YYDEBUG 1

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location);

enum ValueType {
    Variant,
    Constant
};

Z_USE_NAMESPACE


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
#line 83 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                  error(yystack_[0].location, *(yystack_[0].value.msg));
                  delete (yystack_[0].value.msg);
                  YYABORT;
            }
#line 638 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 5:
#line 90 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)));

                delete (yystack_[1].value.identifier);
            }
#line 648 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 8:
#line 97 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 658 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 9:
#line 102 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, ZCodeExecuter::currentCodeExecuter->createConstantByValue(ZVariant(INT32_MAX)));
            }
#line 666 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 10:
#line 105 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 675 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 11:
#line 109 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);

                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                        && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);
            }
#line 687 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 12:
#line 116 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 判断是否是以break结尾
                bool isBreak = !((yystack_[1].value.count) & 0x8000);
                auto type = ZCodeExecuter::CodeBlock::Type(ZCodeExecuter::CodeBlock::LoopStructure | ZCodeExecuter::CodeBlock::Switch | ZCodeExecuter::CodeBlock::Normal);
                ZCodeExecuter::CodeBlock *block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(type, ZCodeExecuter::currentCodeExecuter->getCodeBlock());
                /// break的个数
                qint16 break_count = ((yystack_[1].value.count) & 0x7fff) - !isBreak;

                while ((--break_count) > 0) {
                    if (!block_while) {
                        error(yystack_[1].location, ("\"break\" Can't be used here"));
                        YYABORT;
                    }

                    block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(type, block_while->parent);
                }

                if (!block_while) {
                    error(yystack_[1].location, ("Can't be used here"));
                    YYABORT;
                }

                if (isBreak) {
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->breakIndex);
                } else {
                    /// break_count小于0时说明只存在coutinue语句，因此需要从当前code block查找
                    block_while = ZCodeExecuter::currentCodeExecuter->getCodeBlockByType(ZCodeExecuter::CodeBlock::LoopStructure,
                                                                                         break_count < 0 ? ZCodeExecuter::currentCodeExecuter->getCodeBlock()
                                                                                                         : block_while->parent);

                    if (!block_while) {
                        error(yystack_[1].location, "\"continue\" Can't be used here");
                        YYABORT;
                    }

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Goto, block_while->toLoopStructureCodeBlock()->continueIndex);
                }
            }
#line 730 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 13:
#line 154 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {}
#line 736 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 15:
#line 156 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// For While If Switch-case 语句本身已经添加了对应的CodeBlock，此处的CodeBlock应当不做任何实际作用，也不应该占用break语句
                if (ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::Normal
                        || ZCodeExecuter::currentCodeExecuter->getCodeBlock()->type == ZCodeExecuter::CodeBlock::Function) {
                    ZCodeExecuter::currentCodeExecuter->beginCodeBlock();
                } else {
                    ZCodeExecuter::currentCodeExecuter->beginCodeBlock();
                    ZCodeExecuter::currentCodeExecuter->getCodeBlock()->breakIndex.reset();
                }
            }
#line 751 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 16:
#line 165 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if (auto break_index = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->breakIndex.data()) {
                    *break_index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();
                }

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
#line 763 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 19:
#line 176 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 769 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 20:
#line 177 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 775 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 21:
#line 181 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0x8001;}
#line 781 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 22:
#line 182 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (0x8000 | ((yystack_[2].value.count) + 1));}
#line 787 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 23:
#line 183 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[0].value.count);}
#line 793 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 24:
#line 186 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Switch, ZSharedVariantPointer(new ZSharedVariant()));
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::Switch);
            }
#line 804 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 25:
#line 194 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->breakIndex.data() = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

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
#line 834 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 26:
#line 221 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.caseKey) = new QPair<ZSharedVariantPointer*, quint16>((yystack_[1].value.value), ZCodeExecuter::currentCodeExecuter->getCodeList().count());
            }
#line 842 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 27:
#line 226 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = new QVector<QPair<ZSharedVariantPointer*, quint16>>();
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 853 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 28:
#line 232 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 储存code的开始index
                (yystack_[1].value.count) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();
            }
#line 862 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 29:
#line 235 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[4].value.cases);
                (yylhs.value.cases)->append(QPair<ZSharedVariantPointer*, quint16>(Q_NULLPTR, (yystack_[3].value.count)));
            }
#line 871 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 30:
#line 239 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.cases) = (yystack_[2].value.cases);
                (yylhs.value.cases)->append(*(yystack_[1].value.caseKey));

                delete (yystack_[1].value.caseKey);
            }
#line 882 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 31:
#line 247 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                *ZCodeExecuter::currentCodeExecuter->getGotoLabel(*(yystack_[1].value.identifier)) = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                delete (yystack_[1].value.identifier);
            }
#line 892 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 32:
#line 262 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::beginCodeExecuter()->beginCodeBlock(ZCodeExecuter::CodeBlock::Function);

                if((yystack_[1].value.parameterList)) {
                    for(QByteArray *id : *(yystack_[1].value.parameterList)) {
                        ZCodeExecuter::currentCodeExecuter->getParameterList() << ZCodeExecuter::currentCodeExecuter->addIdentifier(*id);
                        delete id;
                    }

                    delete (yystack_[1].value.parameterList);
                }
            }
#line 909 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 33:
#line 273 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
                ZCodeExecuter *executer = ZCodeExecuter::endCodeExecuter();

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createFunction(executer));
            }
#line 920 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 34:
#line 281 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("", ZVariant::Undefined));
            }
#line 928 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 36:
#line 285 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[0].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToTuple);
            }
#line 937 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 37:
#line 291 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.parameterList) = Q_NULLPTR;}
#line 943 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 38:
#line 292 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = new QVarLengthArray<QByteArray*, 10>();
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 952 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 39:
#line 296 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.parameterList) = (yystack_[2].value.parameterList);
                (yylhs.value.parameterList)->append((yystack_[0].value.identifier));
            }
#line 961 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 40:
#line 302 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[0].value.identifier));
                delete (yystack_[0].value.identifier);
            }
#line 970 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 41:
#line 306 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->addIdentifier(*(yystack_[2].value.identifier));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[2].value.identifier)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::RightAssign);

                delete (yystack_[2].value.identifier);
            }
#line 982 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 43:
#line 317 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 988 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 44:
#line 318 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 994 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 45:
#line 321 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 2;}
#line 1000 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 46:
#line 322 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = (yystack_[2].value.count) + 1;}
#line 1006 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 49:
#line 327 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1014 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 50:
#line 330 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::currentCodeExecuter->getIdentifier(*(yystack_[0].value.identifier)));

                delete (yystack_[0].value.identifier);
            }
#line 1026 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 51:
#line 337 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZSharedVariantPointer(new ZSharedVariant()));
            }
#line 1036 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 52:
#line 342 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Get);
            }
#line 1047 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 53:
#line 348 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LeftAssign);
            }
#line 1057 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 54:
#line 353 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Children);
            }
#line 1067 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 55:
#line 358 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AddAssign);
            }
#line 1077 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 56:
#line 363 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::SubAssign);
            }
#line 1087 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 57:
#line 368 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::MulAssign);
            }
#line 1097 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 58:
#line 373 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::DivAssign);
            }
#line 1107 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 59:
#line 378 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::AndAssign);
            }
#line 1117 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 60:
#line 383 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::OrAssign);
            }
#line 1127 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 61:
#line 388 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::XorAssign);
            }
#line 1137 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 62:
#line 393 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::ModAssign);
            }
#line 1147 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 63:
#line 398 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LOrAssign);
            }
#line 1157 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 64:
#line 403 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::LAndAssign);
            }
#line 1167 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 65:
#line 408 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixAddSelf);
            }
#line 1177 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 66:
#line 413 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PrefixSubSelf);
            }
#line 1187 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 67:
#line 420 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(QByteArray(), ZVariant::Undefined));
            }
#line 1195 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 68:
#line 423 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Int));

                delete (yystack_[0].value.identifier);
            }
#line 1205 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 69:
#line 428 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::String));

                delete (yystack_[0].value.identifier);
            }
#line 1215 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 70:
#line 433 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Double));

                delete (yystack_[0].value.identifier);
            }
#line 1225 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 71:
#line 438 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = new ZSharedVariantPointer(ZCodeExecuter::createConstant(*(yystack_[0].value.identifier), ZVariant::Bool));

                delete (yystack_[0].value.identifier);
            }
#line 1235 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 72:
#line 444 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Constant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, *(yystack_[0].value.value));

                delete (yystack_[0].value.value);
            }
#line 1247 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 73:
#line 451 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1258 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 74:
#line 457 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("1", ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1269 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 75:
#line 463 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant("0", ZVariant::Int));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::JoinToList);
            }
#line 1280 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 76:
#line 469 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// TODO
                (yylhs.value.valueType) = ValueType::Constant;
            }
#line 1289 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 77:
#line 473 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                    (yylhs.value.valueType) = ValueType::Variant;

                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, ZCodeExecuter::createConstant(QByteArray::number((yystack_[1].value.count)), ZVariant::Int));
                    ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Call);
            }
#line 1300 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 78:
#line 479 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1321 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 79:
#line 495 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1342 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 80:
#line 511 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1363 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 81:
#line 527 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1384 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 82:
#line 543 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1405 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 83:
#line 559 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1426 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 84:
#line 575 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1447 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 85:
#line 591 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1468 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 86:
#line 607 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1489 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 87:
#line 623 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1510 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 88:
#line 639 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1531 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 89:
#line 655 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1552 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 90:
#line 671 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1574 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 91:
#line 688 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1596 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 92:
#line 705 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1617 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 93:
#line 721 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1638 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 94:
#line 737 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1659 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 95:
#line 753 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1680 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 96:
#line 769 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1698 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 97:
#line 782 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1716 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 98:
#line 795 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1734 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 99:
#line 808 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
#line 1752 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 100:
#line 821 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixAddSelf);
            }
#line 1762 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 101:
#line 826 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PostfixSubSelf);
            }
#line 1772 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 102:
#line 831 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;

                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Append);
            }
#line 1782 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 103:
#line 836 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1790 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 104:
#line 839 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    { (yylhs.value.valueType) = (yystack_[1].value.valueType);}
#line 1796 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 105:
#line 840 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.valueType) = ValueType::Variant;
            }
#line 1804 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 106:
#line 845 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 0;}
#line 1810 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 107:
#line 846 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {(yylhs.value.count) = 1;}
#line 1816 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 109:
#line 850 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, new ZSharedVariant(QString(*(yystack_[2].value.identifier))));

                delete (yystack_[2].value.identifier);

                (yylhs.value.count) = 1;
            }
#line 1828 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 110:
#line 857 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, new ZSharedVariant(QString(*(yystack_[2].value.identifier))));

                delete (yystack_[2].value.identifier);

                (yylhs.value.count) = (yystack_[4].value.count) + 1;
            }
#line 1840 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 111:
#line 866 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, new ZSharedVariant(0));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::InitObjectProperty);
            }
#line 1849 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 112:
#line 870 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Push, new ZSharedVariant((yystack_[1].value.count)));
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::InitObjectProperty);
            }
#line 1858 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 113:
#line 876 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                (yylhs.value.value) = Q_NULLPTR;

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::If);
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1872 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 114:
#line 885 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::While);
            }
#line 1880 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 115:
#line 887 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 存储if语句判断为假时要跳转到的指令位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1891 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 116:
#line 893 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                if(ZCodeExecuter::currentCodeExecuter->getCodeList().count() > 1
                            && ZCodeExecuter::currentCodeExecuter->getCodeList().last()->action != ZCode::PopAll)
                        ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::PopAll);

                ZCodeExecuter::currentCodeExecuter->beginCodeBlock(ZCodeExecuter::CodeBlock::NormalFor);
            }
#line 1903 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 117:
#line 899 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::If, ZCodeExecuter::currentCodeExecuter->createConstant("", ZVariant::Undefined));

                /// 记录for循环的if指令在codeList中的index，方便修改if指令为假时要跳转到的指令位置
                ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeList().count() - 1;

                /// 开启使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(true);
            }
#line 1917 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 118:
#line 907 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 关闭使用临时列表储存code
                ZCodeExecuter::currentCodeExecuter->setEnableTmpCodeList(false);

                int ifInstructionIndex = ZCodeExecuter::currentCodeExecuter->getCodeBlock()->toLoopStructureCodeBlock()->ifInstructionIndex;

                /// 将if语句的ValueCode的值传递到下一层，方便更改if语句判断为假时的跳转位置
                (yylhs.value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().value(ifInstructionIndex)->toValueCode()->value;
            }
#line 1931 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 123:
#line 926 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
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
                    *ZCodeExecuter::currentCodeExecuter->getCodeBlock()->breakIndex.data() = codeList.count();
                }

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// index为if判断结果为假时要跳转到的位置
                *(yystack_[1].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
                (yylhs.value.value) = (yystack_[1].value.value);

                ZCodeExecuter::currentCodeExecuter->endCodeBlock();
            }
#line 1973 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 126:
#line 968 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                /// 如果if判断为真时会执行此goto指令，让其跳转到else代码块后面的语句
                ZCodeExecuter::currentCodeExecuter->appendCode(ZCode::Action::Goto,
                                             ZCodeExecuter::createConstant("", ZVariant::Undefined));

                int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                /// 更改if判断为假时跳转到的位置
                *(yystack_[0].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);

                (yystack_[0].value.value) = &ZCodeExecuter::currentCodeExecuter->getCodeList().last()->toValueCode()->value;
            }
#line 1990 "zScript.tab.cpp" // lalr1.cc:859
    break;

  case 127:
#line 979 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:859
    {
                 int index = ZCodeExecuter::currentCodeExecuter->getCodeList().count();

                 /// index为if为真时跳转到的位置
                *(yystack_[2].value.value) = ZCodeExecuter::createConstant(QByteArray::number(index), ZVariant::Int);
            }
#line 2001 "zScript.tab.cpp" // lalr1.cc:859
    break;


#line 2005 "zScript.tab.cpp" // lalr1.cc:859
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


  const signed char parser::yypact_ninf_ = -122;

  const signed char parser::yytable_ninf_ = -67;

  const short int
  parser::yypact_[] =
  {
     -30,  -122,   228,  -122,     2,     4,   -52,  -122,   -47,  -122,
       7,    46,  -122,  -122,   -44,   -25,  -122,  -122,  -122,  -122,
      46,    46,   -14,  -122,    46,    46,    46,    46,   395,   456,
    -122,  -122,  -122,   -19,    -3,   -39,  -122,  -122,  -122,    -3,
       3,   666,   667,  -122,  -122,  -122,   372,    43,  -122,  -122,
       8,    12,  -122,    46,    -9,    46,    -3,  -122,    14,   714,
     916,    46,  -122,   780,   830,   873,    11,  -122,   -45,   -58,
     -58,   -58,   -58,  -122,   -37,   618,   -41,   -40,   480,   -30,
       0,  -122,  -122,    53,  -122,    46,    21,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    54,    46,    46,  -122,  -122,
    -122,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,  -122,  -122,   372,    46,     2,   529,
      46,   780,    23,    -3,  -122,    46,    46,   548,    46,    56,
    -122,  -122,  -122,    57,  -122,  -122,   372,  -122,  -122,    33,
     372,   -15,   715,    46,   -22,   -22,   -22,   -22,   149,   149,
     828,   828,    73,    73,    73,   149,   149,   200,   200,   -58,
     -58,   -58,  -122,   762,    14,   714,     5,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   892,   780,
    -122,   780,  -122,  -122,   597,    46,  -122,   780,   780,  -122,
     780,    28,  -122,    13,    20,    32,  -122,    42,  -122,   372,
     666,  -122,  -122,  -122,   780,    46,    46,   -30,  -122,  -122,
    -122,  -122,  -122,   666,   780,   298,   372,  -122,  -122,  -122,
      46,    24,  -122
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     4,     0,     1,     0,     0,     0,   114,     0,    67,
       0,    34,    19,    21,     0,    50,    68,    69,    71,    70,
       0,     0,     0,    14,     0,     0,     0,     0,     0,    37,
      15,    51,     3,    23,     0,     0,    13,     7,   103,     0,
      10,     0,    47,    72,    48,   105,     0,   125,   126,     6,
      40,    49,    76,     0,     0,   121,     0,    50,    36,    35,
      47,     0,    31,     0,    47,    47,     0,   111,     0,    98,
      99,    97,    96,    75,     0,     0,    50,     0,     0,     2,
       0,    18,    12,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     8,   100,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,     0,     0,     0,     0,
       0,   119,   122,     0,     5,     0,     0,     0,     0,     0,
     112,    73,    74,     0,    32,   104,    16,    20,    22,     0,
       0,     0,    47,     0,    88,    90,    89,    91,    92,    93,
      94,    95,    82,    83,    84,    86,    87,    79,    78,    80,
      81,    85,    52,     0,   108,   107,     0,   102,    58,    57,
      55,    56,    62,    59,    60,    61,    64,    63,    47,    53,
     127,    41,    42,   113,     0,     0,   116,    46,    45,    24,
     109,     0,    39,     0,     0,     0,    27,     0,    25,     0,
       0,    54,    77,   115,   120,     0,     0,     2,    17,    26,
      28,    30,    11,     0,   110,     0,     0,   117,    33,    29,
     121,     0,   118
  };

  const signed char
  parser::yypgoto_[] =
  {
    -122,   -78,   -20,  -122,  -122,  -122,   -18,  -122,  -122,  -122,
    -122,   -46,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   -24,
    -122,   -26,    64,    -2,   -38,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -121,  -122,  -122,  -122,  -122
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     2,    32,    86,    79,   204,    82,    33,    34,    35,
      36,   150,   151,   226,    37,    38,   203,    39,    77,    51,
      40,    58,    41,    60,    43,    44,   176,    68,    45,    46,
      54,   215,   230,   132,   133,    47,    48,    49,   126
  };

  const short int
  parser::yytable_[] =
  {
      42,   146,    74,   149,   207,   139,    66,    91,    92,   -38,
     143,   105,   106,   135,   107,   147,   148,     1,    64,    65,
      53,    84,    50,   108,    52,    55,   124,    56,    61,    62,
     140,    80,   -38,   144,   141,    83,    98,    99,   134,   100,
     101,   102,   103,   104,    42,     9,    81,   105,   106,     4,
     107,     5,   125,    85,    16,    17,    18,    19,     9,   127,
     208,    67,   128,   130,   135,   138,    57,    16,    17,    18,
      19,   149,   153,   195,   172,    59,   201,   202,   212,    20,
      21,   174,   216,   152,    63,    63,   219,   217,    69,    70,
      71,    72,    75,    78,    22,   218,   220,   232,    87,    88,
      89,    90,    91,    92,   192,   209,   190,    24,    25,   231,
       0,   205,     0,    26,    27,   196,    28,   129,    29,   131,
     188,     0,    31,     0,    42,   137,     0,     0,     0,     0,
     206,    98,    99,     0,   100,   101,   102,   103,   104,   225,
       0,     0,   105,   106,    42,   107,     0,     0,    42,    63,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,     0,
     173,   175,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,    63,   189,     0,   221,
       0,   191,   222,     0,   194,     0,     0,     0,     0,   197,
     198,     0,   200,     0,     0,   227,   229,    42,     0,     0,
     100,   101,   102,   103,   104,     0,     0,   210,   105,   106,
       0,   107,     0,    42,    42,     0,     0,     0,     3,     0,
       0,     4,     0,     5,     0,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,   214,
       0,    20,    21,   102,   103,   104,     0,     0,     0,   105,
     106,     0,   107,     0,     0,     0,    22,    23,     0,   223,
     224,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,     0,     0,   131,    26,    27,     0,    28,     0,
      29,     4,    30,     5,    31,     0,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,     0,     0,     0,     0,    26,    27,     0,    28,     0,
      29,     0,    30,   228,    31,     4,     0,     5,     0,     0,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
       0,     0,    15,    16,    17,    18,    19,     0,     4,     0,
       5,     0,     0,     0,     0,    20,    21,     9,     0,     0,
       0,     0,     0,     0,     0,    57,    16,    17,    18,    19,
      22,    23,     0,     0,     0,     0,     0,     0,    20,    21,
       0,     0,     0,    24,    25,     0,     0,     0,     0,    26,
      27,     0,    28,    22,    29,     0,    30,     0,    31,     0,
       0,     0,     0,     0,     0,     0,    24,    25,     0,     4,
       0,     5,    26,    27,     0,    28,    73,    29,     9,     0,
       0,    31,     0,     0,     0,     0,    76,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,    26,    27,     0,    28,     0,    29,     0,
       0,     0,    31,     0,     0,    95,    96,    97,    98,    99,
       0,   100,   101,   102,   103,   104,     0,     0,     0,   105,
     106,     0,   107,   145,    87,    88,    89,    90,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,    93,
      94,     0,     0,     0,    95,    96,    97,    98,    99,     0,
     100,   101,   102,   103,   104,     0,     0,     0,   105,   106,
       0,   107,   193,    95,    96,    97,    98,    99,     0,   100,
     101,   102,   103,   104,     0,     0,     0,   105,   106,     0,
     107,   199,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,    93,
      94,     0,    95,    96,    97,    98,    99,     0,   100,   101,
     102,   103,   104,     0,     0,     0,   105,   106,   136,   107,
     213,     0,     0,    95,    96,    97,    98,    99,     0,   100,
     101,   102,   103,   104,     0,     0,     0,   105,   106,   142,
     107,    87,    88,    89,    90,    91,    92,    93,    94,     0,
     109,   110,   111,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,     0,    81,     0,   122,   123,     0,
       0,    95,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,     0,     0,     0,   105,   106,     0,   107,    87,
      88,    89,    90,    91,    92,    93,    94,     0,   109,   110,
     111,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,   136,   -44,   -44,     0,     0,    95,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
       0,     0,     0,   105,   106,     0,   107,    87,    88,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,    95,    96,    97,
      98,    99,     0,   100,   101,   102,   103,   104,     0,     0,
       0,   105,   106,   211,   107,    95,    96,    97,    98,    99,
       0,   100,   101,   102,   103,   104,     0,     0,     0,   105,
     106,     0,   107,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,   -65,   -65,   111,     0,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,     0,     0,   -65,
     -65,   -65,     0,    95,    96,    97,    98,    99,     0,   100,
     101,   102,   103,   104,     0,     0,     0,   105,   106,     0,
     107,   -65,     0,   -65,     0,   -65,   -66,   -66,   111,     0,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
       0,     0,   -66,   -66,   -66,   109,   110,   111,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
       0,     0,   -43,   -43,   -66,     0,   -66,     0,   -66,   109,
     110,   111,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,   123
  };

  const short int
  parser::yycheck_[] =
  {
       2,    79,    28,    18,    19,    50,    20,    29,    30,    50,
      50,    69,    70,    50,    72,    15,    16,    47,    20,    21,
      72,    39,    20,    41,    20,    72,    46,    20,    72,    54,
      75,    50,    73,    73,    71,    74,    58,    59,    56,    61,
      62,    63,    64,    65,    46,    12,    49,    69,    70,     3,
      72,     5,     9,    50,    21,    22,    23,    24,    12,    51,
      75,    75,    50,    72,    50,    54,    20,    21,    22,    23,
      24,    18,    51,    50,    20,    11,    20,    20,    73,    33,
      34,   107,    54,    85,    20,    21,    54,    74,    24,    25,
      26,    27,    28,    29,    48,    75,    54,    73,    25,    26,
      27,    28,    29,    30,   128,   151,   126,    61,    62,   230,
      -1,   149,    -1,    67,    68,   133,    70,    53,    72,    55,
     122,    -1,    76,    -1,   126,    61,    -1,    -1,    -1,    -1,
     150,    58,    59,    -1,    61,    62,    63,    64,    65,   217,
      -1,    -1,    69,    70,   146,    72,    -1,    -1,   150,    85,
      -1,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
     106,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    -1,   209,
      -1,   127,   210,    -1,   130,    -1,    -1,    -1,    -1,   135,
     136,    -1,   138,    -1,    -1,   223,   226,   209,    -1,    -1,
      61,    62,    63,    64,    65,    -1,    -1,   153,    69,    70,
      -1,    72,    -1,   225,   226,    -1,    -1,    -1,     0,    -1,
      -1,     3,    -1,     5,    -1,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,   195,
      -1,    33,    34,    63,    64,    65,    -1,    -1,    -1,    69,
      70,    -1,    72,    -1,    -1,    -1,    48,    49,    -1,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,   230,    67,    68,    -1,    70,    -1,
      72,     3,    74,     5,    76,    -1,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    -1,
      72,    -1,    74,    75,    76,     3,    -1,     5,    -1,    -1,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    20,    21,    22,    23,    24,    -1,     3,    -1,
       5,    -1,    -1,    -1,    -1,    33,    34,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    48,    72,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,     3,
      -1,     5,    67,    68,    -1,    70,    71,    72,    12,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      70,    -1,    72,    73,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    -1,    -1,    -1,    69,    70,
      -1,    72,    73,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    -1,
      72,    73,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    -1,    -1,    -1,    69,    70,    50,    72,
      73,    -1,    -1,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    71,
      72,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    49,    -1,    50,    51,    -1,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      64,    65,    -1,    -1,    -1,    69,    70,    -1,    72,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    33,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    50,    50,    51,    -1,    -1,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      -1,    -1,    -1,    69,    70,    -1,    72,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    69,    70,    71,    72,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    -1,    -1,    -1,    69,
      70,    -1,    72,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    49,
      50,    51,    -1,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    69,    70,    -1,
      72,    71,    -1,    73,    -1,    75,    33,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    50,    51,    71,    -1,    73,    -1,    75,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    51
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    47,    78,     0,     3,     5,     8,    10,    11,    12,
      13,    14,    15,    16,    17,    20,    21,    22,    23,    24,
      33,    34,    48,    49,    61,    62,    67,    68,    70,    72,
      74,    76,    79,    84,    85,    86,    87,    91,    92,    94,
      97,    99,   100,   101,   102,   105,   106,   112,   113,   114,
      20,    96,    20,    72,   107,    72,    20,    20,    98,    99,
     100,    72,    54,    99,   100,   100,    20,    75,   104,    99,
      99,    99,    99,    71,    98,    99,    20,    95,    99,    81,
      50,    49,    83,    74,    83,    50,    80,    25,    26,    27,
      28,    29,    30,    31,    32,    55,    56,    57,    58,    59,
      61,    62,    63,    64,    65,    69,    70,    72,    83,    33,
      34,    35,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    50,    51,    79,     9,   115,    51,    50,    99,
      72,    99,   110,   111,    83,    50,    50,    99,    54,    50,
      75,    71,    71,    50,    73,    73,    78,    15,    16,    18,
      88,    89,   100,    51,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    20,    99,    98,    99,   103,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,    99,
      79,    99,    96,    73,    99,    50,    83,    99,    99,    73,
      99,    20,    20,    93,    82,   101,    79,    19,    75,    88,
      99,    71,    73,    73,    99,   108,    54,    74,    75,    54,
      54,    79,    83,    99,    99,    78,    90,    83,    75,    79,
     109,   111,    73
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    77,    78,    78,    78,    79,    79,    79,    79,    79,
      80,    79,    79,    79,    79,    81,    82,    79,    83,    84,
      84,    85,    85,    85,    86,    87,    88,    89,    90,    89,
      89,    91,    93,    92,    94,    94,    94,    95,    95,    95,
      96,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   106,   107,   106,   108,   109,   106,   110,
     110,   111,   111,   112,   113,   114,   115,   114
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     3,     1,     1,     2,     2,
       0,     5,     2,     1,     1,     0,     0,     5,     1,     1,
       3,     1,     3,     1,     4,     4,     3,     2,     0,     5,
       3,     2,     0,     7,     1,     2,     2,     0,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     2,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     3,     1,     3,     1,     0,     1,     1,     3,
       5,     2,     3,     4,     0,     5,     0,     0,    10,     1,
       3,     0,     1,     2,     2,     1,     0,     3
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
  "ORASSIGN", "XORASSIGN", "LANDASSIGN", "LORASSIGN", "ERROR",
  "NEW_OBJ_BEGIN", "';'", "','", "'='", "COMMA", "'?'", "':'", "'&'",
  "'|'", "'^'", "'>'", "'<'", "LTGT", "'-'", "'+'", "'*'", "'/'", "'%'",
  "UMINUS", "'!'", "'~'", "'.'", "'['", "']'", "'('", "')'", "'{'", "'}'",
  "'_'", "$accept", "start", "code", "$@1", "$@2", "$@3", "ends", "break",
  "loopEnds", "switch_head", "switch", "case", "cases", "$@4",
  "goto_label", "function", "$@5", "return", "parameter", "define",
  "tuple_lval", "tuple_exp", "expression", "lvalue", "const", "rvalue",
  "arguments", "object_pro", "object", "branch_head", "$@6", "$@7", "$@8",
  "for_exps", "for_exp", "branch_body", "branch_else", "conditional",
  "$@9", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,    82,    82,    82,    83,    90,    95,    96,    97,   102,
     105,   105,   116,   154,   155,   156,   165,   156,   174,   176,
     177,   181,   182,   183,   186,   194,   221,   226,   232,   232,
     239,   247,   262,   262,   281,   284,   285,   291,   292,   296,
     302,   306,   313,   317,   318,   321,   322,   325,   325,   327,
     330,   337,   342,   348,   353,   358,   363,   368,   373,   378,
     383,   388,   393,   398,   403,   408,   413,   420,   423,   428,
     433,   438,   444,   451,   457,   463,   469,   473,   479,   495,
     511,   527,   543,   559,   575,   591,   607,   623,   639,   655,
     671,   688,   705,   721,   737,   753,   769,   782,   795,   808,
     821,   826,   831,   836,   839,   840,   845,   846,   847,   850,
     857,   866,   870,   876,   885,   885,   893,   899,   893,   923,
     923,   924,   924,   926,   965,   967,   968,   968
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
      72,    73,    63,    62,    50,    61,    69,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    49,
      59,    51,    58,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    57,    76,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,    56,    75,    68,     2,     2,     2,
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
      45,    46,    47,    48,    52,    60,    66
    };
    const unsigned int user_token_number_max_ = 306;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // yy
#line 2737 "zScript.tab.cpp" // lalr1.cc:1167
#line 985 "/mnt/c/Users/zccrs/projects/zScript/syntax/zScript.yy" // lalr1.cc:1168


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
}

int yylex(yy::parser::semantic_type *lval, yy::parser::location_type *location)
{
    if (tokenQueue.isEmpty()) {
        yylval = lval;
        yyloc = location;

        return ZCodeExecuter::yyFlexLexer->yylex();
    } else {
        *lval = tokenValQueue.dequeue();
        *location = tokenLocQueue.dequeue();

        return tokenQueue.dequeue();
    }
}
