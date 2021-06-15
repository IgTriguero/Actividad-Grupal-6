/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <values.h>

extern int yylex();
extern int yyparse();
extern int yylineno;
extern FILE* yyin;
extern FILE *yyout;

void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

char* ast_text = "ast.txt";

/* nodes in the abstract syntax tree */
struct ast {
	char*  nodetype;
	struct ast *l;
	struct ast *r;
};
struct boo {
 char* nodetype;
 struct ast *l;
 struct ast *r;
};

struct flow {
	char* nodetype; /* type I or W */
	struct ast *cond; /* condition */
};

struct asign {
 	char* nodetype;
 	struct ast *as;
};

struct numval {
	char* nodetype;
	double number;
};

struct strval {
	char* nodetype;
	char* str;
};

//struct tabla de simbolos
struct symb{    
	char* vname;    
	int vvali;   
	float vvalf;
	char* vvals;
	char* type; 
};


//Variables globales
int line_num = 1;

int size = 52;

int elementosOcupados = 0;

int numnodo = 0;

struct ast nodos[52];

struct symb tabla[52];

void write_file(char *filename, char *content);

void insertarElemento(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, int *elementosOcupados, char* type );
int buscarValor(struct symb *tabla, char *nombre, char *tipo, int *size);

// tabla simbolos
void iniArrayTabla(struct symb *tabla, int inicio, int fin);

// nodos
void iniArrayNodos(struct ast *nodos, int inicio, int fin);

// funciones ast
struct ast *createAST(char* nodetype, struct ast *l, struct ast *r);
struct ast *createBOO(char* nodetype, struct ast *l, struct ast *r);
struct ast *createFlow(struct ast *cond);
struct ast *createFlow2(struct ast *cond);
struct ast *createNum(double d);
struct ast *createSTR(char* s);
struct ast *createBOOVAR(char* s);
struct ast *createASTAsignacion(struct ast *op);

void evalAST(struct ast a, int* size);
void printAST(struct ast nodos[], int i, int encontrado, int salida);


#line 171 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENTERO = 258,
    FLOAT = 259,
    STR = 260,
    VAR_NAME = 261,
    SUMA = 262,
    RESTA = 263,
    MULT = 264,
    DIV = 265,
    EQUAL = 266,
    FLECHA = 267,
    ABRIR_LLAVE = 268,
    CERRAR_LLAVE = 269,
    ABRIR_PARENTESIS = 270,
    CERRAR_PARENTESIS = 271,
    WHILE = 272,
    FOR = 273,
    CASE = 274,
    LOOP = 275,
    IF = 276,
    THEN = 277,
    ELSE = 278,
    ELSEIF = 279,
    END = 280,
    WHEN = 281,
    IS = 282,
    OTHERS = 283,
    DOTDOT = 284,
    PROCEDURE = 285,
    RANGE = 286,
    COMMA = 287,
    OF = 288,
    TYPE = 289,
    COMMENT = 290,
    NEWLINE = 291,
    SEMICOLON = 292,
    COLON = 293,
    QUIT = 294,
    TRUE = 295,
    FALSE = 296,
    MENOR = 297,
    MAYOR = 298,
    MENOR_IGUAL = 299,
    MAYOR_IGUAL = 300,
    DESIGUAL = 301,
    IGUAL = 302,
    DECLINTEGER = 303,
    DECLFLOAT = 304,
    DECLBOOLEAN = 305,
    DECLARRAY = 306,
    DECLSTRING = 307,
    PLUS = 308,
    MINUS = 309,
    MULTIPLY = 310,
    DIVIDE = 311
  };
#endif
/* Tokens.  */
#define ENTERO 258
#define FLOAT 259
#define STR 260
#define VAR_NAME 261
#define SUMA 262
#define RESTA 263
#define MULT 264
#define DIV 265
#define EQUAL 266
#define FLECHA 267
#define ABRIR_LLAVE 268
#define CERRAR_LLAVE 269
#define ABRIR_PARENTESIS 270
#define CERRAR_PARENTESIS 271
#define WHILE 272
#define FOR 273
#define CASE 274
#define LOOP 275
#define IF 276
#define THEN 277
#define ELSE 278
#define ELSEIF 279
#define END 280
#define WHEN 281
#define IS 282
#define OTHERS 283
#define DOTDOT 284
#define PROCEDURE 285
#define RANGE 286
#define COMMA 287
#define OF 288
#define TYPE 289
#define COMMENT 290
#define NEWLINE 291
#define SEMICOLON 292
#define COLON 293
#define QUIT 294
#define TRUE 295
#define FALSE 296
#define MENOR 297
#define MAYOR 298
#define MENOR_IGUAL 299
#define MAYOR_IGUAL 300
#define DESIGUAL 301
#define IGUAL 302
#define DECLINTEGER 303
#define DECLFLOAT 304
#define DECLBOOLEAN 305
#define DECLARRAY 306
#define DECLSTRING 307
#define PLUS 308
#define MINUS 309
#define MULTIPLY 310
#define DIVIDE 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 103 "bison.y"

	int eval;
	float fval;
	char* sval;

	struct atributos{
		int i;
		float f;
		int i2;
		float f2;
		char* operador;
		char* s;
		char *temp1;
		char *temp2;
		char *temp3;
		char* type;
		struct ast *a;
	}st;

#line 355 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

#define YYUNDEFTOK  2
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   167,   167,   170,   170,   173,   174,   175,   176,   177,
     180,   181,   182,   183,   184,   189,   191,   192,   193,   194,
     195,   199,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   212,   217,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   236,
     237,   238,   244,   245,   249,   250,   251,   252,   256,   257,
     258,   259,   260,   261,   265,   266,   267,   268,   269,   270,
     273,   274,   275,   276,   277,   278,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   291,   291,   293,   294,   295,
     298,   299,   300,   302,   303,   306,   307,   308,   309,   312,
     315,   318
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "FLOAT", "STR", "VAR_NAME",
  "SUMA", "RESTA", "MULT", "DIV", "EQUAL", "FLECHA", "ABRIR_LLAVE",
  "CERRAR_LLAVE", "ABRIR_PARENTESIS", "CERRAR_PARENTESIS", "WHILE", "FOR",
  "CASE", "LOOP", "IF", "THEN", "ELSE", "ELSEIF", "END", "WHEN", "IS",
  "OTHERS", "DOTDOT", "PROCEDURE", "RANGE", "COMMA", "OF", "TYPE",
  "COMMENT", "NEWLINE", "SEMICOLON", "COLON", "QUIT", "TRUE", "FALSE",
  "MENOR", "MAYOR", "MENOR_IGUAL", "MAYOR_IGUAL", "DESIGUAL", "IGUAL",
  "DECLINTEGER", "DECLFLOAT", "DECLBOOLEAN", "DECLARRAY", "DECLSTRING",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "$accept", "PROCLINE",
  "AUXCONTENT", "CONTENT", "DECL", "AUXINT", "OP_ARIT", "ARIT", "ARIT2",
  "OP_BOOLEANO", "BOOL", "BOOLEAN", "BUCLE", "BUCLE_CASE", "SENTENCIA_IF",
  "NOMBRE_VARIABLE", "STRING", "COMENTARIO", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,    18,    42,   -89,    20,   -89,   -89,   200,    92,    92,
      92,    92,   -89,    92,    19,    41,    18,   -89,   -89,   -89,
     -89,   -89,   -89,   -12,   -89,   221,   221,    92,    37,   221,
      46,    72,    86,   102,    99,   107,   115,   132,   139,   159,
     164,   173,    22,   -89,   -89,   -89,   -89,   -89,   -89,   225,
     270,   191,   -89,    26,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -24,    98,    38,    77,   130,
     153,   176,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   212,   205,   221,   221,   -89,   183,   -89,   -89,    13,
      27,   179,   195,     9,   196,   -89,   226,   -89,   229,   -89,
     231,   -89,   248,   249,   228,   233,   225,   270,   221,   221,
     242,   246,    28,    28,    28,    28,   -89,    18,   141,   141,
     141,   141,   -89,    18,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   207,   274,   -89,   224,   117,    79,   256,   260,   276,
     254,   250,   251,    28,    28,    28,    28,   -89,   141,   141,
     141,   141,   -89,   -89,    28,   186,   186,   186,   186,   252,
     -89,   141,   262,   262,   262,   262,   253,   114,   118,   133,
     255,   257,   258,   259,   140,   151,   155,   165,   221,   221,
     261,   263,   201,   264,   282,   265,   283,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    18,   -89,
     224,   -89,    18,   -89,   117,   225,   270,   -89,   -89,   -89,
     278,   -89,   267,   -89,   275,   266,   171,   268,   269,   175,
     271,   272,   273,   277,   279,   280,   290,   281,   285,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   284,    18,   -89,   286,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    99,     0,     1,     4,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,   101,     3,     9,
       5,     6,     7,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    71,    70,     0,
       0,     0,    87,     0,    88,    90,    95,    97,    94,    89,
      98,     2,    91,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    81,    78,    79,    83,    84,    80,
      82,     0,     0,    63,    69,   100,     0,    85,    86,     0,
       0,     0,     0,     0,     0,    15,     0,    21,     0,    30,
       0,    32,     0,     0,     0,     0,     0,     0,    63,    69,
       0,     0,    54,    55,    56,    57,    39,     0,    54,    55,
      56,    57,    40,     0,    46,    47,    54,    55,    56,    57,
      33,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,    68,    63,     0,    58,    59,    60,    61,     0,
      69,     0,    64,    65,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,    37,
      38,    35,    36,    34,    42,    43,    41,    14,     0,    10,
       0,    20,     0,    16,     0,     0,     0,    28,    29,    22,
       0,    31,    53,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      12,    11,    19,    18,    17,    26,    27,    24,    25,    23,
      52,     0,     0,    51,     0,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,   -89,   -88,   -34,   -58,   -25,
       1,   168,   -89,   -89,   -89,    -1,   170,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    18,    19,   227,   117,   110,   111,    49,
      51,    92,    20,    21,    22,    29,    94,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,    50,   123,     1,    53,   131,    23,    81,    90,    28,
      30,    31,    32,    37,    33,    41,   126,   127,   128,   129,
     112,   113,   114,   115,     3,     3,    42,    82,     3,    79,
      80,   153,    89,    66,   118,   119,   120,   121,    34,    35,
      36,    71,     5,   154,    38,    39,   130,     6,    74,    77,
     116,    43,    44,    45,    46,    47,    48,    52,   106,   107,
     162,   163,   164,   165,   122,    93,    54,    91,   132,    40,
      67,    68,    69,   169,    70,    95,    96,   176,   155,   156,
     157,   158,   178,   179,    50,     3,   198,   200,   202,   204,
     162,   163,   164,   165,    27,    25,    26,   168,     3,    55,
     174,    83,    84,    85,     3,   141,   142,    27,    56,   155,
     156,   157,   158,    86,    97,    98,   159,   153,   160,    87,
      88,   160,   166,     3,    57,   143,   144,   145,   146,   167,
     170,   173,   161,   175,   177,   182,    58,   180,    87,    88,
     148,   149,   150,   151,    59,   160,   219,   112,   113,   114,
     115,    62,    60,   205,   206,   191,   161,   210,   126,   127,
     128,   129,   118,   119,   120,   121,   216,    99,   100,    61,
     192,    63,   126,   127,   128,   129,    64,   197,   143,   144,
     145,   146,   148,   149,   150,   151,   108,   109,   199,     3,
     101,   102,   201,   143,   144,   145,   146,   215,    86,   217,
      65,   218,   203,   220,   221,   222,     3,    78,   230,   225,
     153,   160,   233,     3,   103,   104,   124,     8,     9,    10,
     105,    11,   167,    12,    13,    14,    15,   153,    72,    73,
       3,     3,   125,   133,    16,    17,   140,   134,   209,   154,
     135,   244,   136,    43,    44,    45,    46,    47,    48,   143,
     144,   145,   146,   148,   149,   150,   151,   139,   147,   137,
     138,    85,   152,    43,    44,    45,    46,    47,    48,   148,
     149,   150,   151,    75,    76,   184,     3,   171,   172,   185,
       3,   223,   224,   186,     3,   212,   214,   187,   188,   189,
     190,   228,   193,   240,   194,   195,   196,   241,   207,   226,
     208,   211,   213,   229,   181,   231,   232,   183,   234,   235,
     236,     0,     0,     0,   237,     0,   238,   239,   242,     0,
       0,   243,     0,   245
};

static const yytype_int16 yycheck[] =
{
       1,    26,    90,    30,    29,    93,     7,    31,    66,     8,
       9,    10,    11,    14,    13,    16,     7,     8,     9,    10,
       7,     8,     9,    10,     6,     6,    38,    51,     6,     3,
       4,     3,    66,    11,     7,     8,     9,    10,    19,    20,
      21,    42,     0,    15,     3,     4,    37,    27,    49,    50,
      37,    42,    43,    44,    45,    46,    47,    20,    83,    84,
     118,   119,   120,   121,    37,    66,    20,    66,    93,    28,
      48,    49,    50,   131,    52,    37,    38,   135,   112,   113,
     114,   115,     3,     4,   109,     6,   174,   175,   176,   177,
     148,   149,   150,   151,    15,     3,     4,   131,     6,    27,
     134,     3,     4,     5,     6,   106,   107,    15,    22,   143,
     144,   145,   146,    15,    37,    38,   117,     3,     4,    40,
      41,     4,   123,     6,    22,     7,     8,     9,    10,    15,
     131,   132,    15,   134,   135,   136,    37,   136,    40,    41,
       7,     8,     9,    10,    37,     4,   204,     7,     8,     9,
      10,    12,    37,   178,   179,    37,    15,   182,     7,     8,
       9,    10,     7,     8,     9,    10,   200,    37,    38,    37,
      37,    12,     7,     8,     9,    10,    12,    37,     7,     8,
       9,    10,     7,     8,     9,    10,     3,     4,    37,     6,
      37,    38,    37,     7,     8,     9,    10,   198,    15,   200,
      27,   202,    37,   204,   205,   206,     6,    16,    37,   210,
       3,     4,    37,     6,    38,     3,    37,    17,    18,    19,
      15,    21,    15,    23,    24,    25,    26,     3,     3,     4,
       6,     6,    37,    37,    34,    35,     3,    11,    37,    15,
      11,   242,    11,    42,    43,    44,    45,    46,    47,     7,
       8,     9,    10,     7,     8,     9,    10,    29,    16,    11,
      11,     5,    16,    42,    43,    44,    45,    46,    47,     7,
       8,     9,    10,     3,     4,    15,     6,     3,     4,     3,
       6,     3,     4,    29,     6,     3,     3,    37,    37,    37,
      37,    16,    37,     3,    37,    37,    37,    16,    37,    32,
      37,    37,    37,    37,   136,    37,    37,   137,    37,    37,
      37,    -1,    -1,    -1,    37,    -1,    37,    37,    33,    -1,
      -1,    37,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    58,     6,    72,     0,    27,    59,    17,    18,
      19,    21,    23,    24,    25,    26,    34,    35,    60,    61,
      69,    70,    71,    72,    74,     3,     4,    15,    67,    72,
      67,    67,    67,    67,    19,    20,    21,    72,     3,     4,
      28,    72,    38,    42,    43,    44,    45,    46,    47,    66,
      66,    67,    20,    66,    20,    27,    22,    22,    37,    37,
      37,    37,    12,    12,    12,    27,    11,    48,    49,    50,
      52,    72,     3,     4,    72,     3,     4,    72,    16,     3,
       4,    31,    51,     3,     4,     5,    15,    40,    41,    64,
      65,    67,    68,    72,    73,    37,    38,    37,    38,    37,
      38,    37,    38,    38,     3,    15,    66,    66,     3,     4,
      64,    65,     7,     8,     9,    10,    37,    63,     7,     8,
       9,    10,    37,    63,    37,    37,     7,     8,     9,    10,
      37,    63,    66,    37,    11,    11,    11,    11,    11,    29,
       3,    72,    72,     7,     8,     9,    10,    16,     7,     8,
       9,    10,    16,     3,    15,    64,    64,    64,    64,    72,
       4,    15,    65,    65,    65,    65,    72,    15,    64,    65,
      72,     3,     4,    72,    64,    72,    65,    72,     3,     4,
      67,    68,    72,    73,    15,     3,    29,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    63,    37,
      63,    37,    63,    37,    63,    66,    66,    37,    37,    37,
      66,    37,     3,    37,     3,    72,    64,    72,    72,    65,
      72,    72,    72,     3,     4,    72,    32,    62,    16,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
       3,    16,    33,    37,    72,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    64,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    71,    71,    72,
      73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     1,     1,     1,     1,     1,
       7,     9,     9,     9,     7,     4,     7,     9,     9,     9,
       7,     4,     7,     9,     9,     9,     9,     9,     7,     7,
       4,     7,     4,     5,     7,     7,     7,     7,     7,     5,
       5,     7,     7,     7,     7,     7,     5,     5,     5,     8,
      12,    10,     2,     0,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 167 "bison.y"
                                                                              {printf(".");}
#line 1818 "y.tab.c"
    break;

  case 5:
#line 173 "bison.y"
          {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {evalAST(*(yyvsp[0].st).a, &size);};}
#line 1824 "y.tab.c"
    break;

  case 6:
#line 174 "bison.y"
                     {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {evalAST(*(yyvsp[0].st).a, &size);};}
#line 1830 "y.tab.c"
    break;

  case 7:
#line 175 "bison.y"
                       {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {evalAST(*(yyvsp[0].st).a, &size);};}
#line 1836 "y.tab.c"
    break;

  case 8:
#line 176 "bison.y"
                     {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].sval), yylineno); }
#line 1842 "y.tab.c"
    break;

  case 9:
#line 177 "bison.y"
               {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {evalAST(*(yyvsp[0].st).a, &size);};}
#line 1848 "y.tab.c"
    break;

  case 10:
#line 180 "bison.y"
                                                                              {}
#line 1854 "y.tab.c"
    break;

  case 11:
#line 181 "bison.y"
                                                                                                          {}
#line 1860 "y.tab.c"
    break;

  case 12:
#line 182 "bison.y"
                                                                                               {}
#line 1866 "y.tab.c"
    break;

  case 13:
#line 183 "bison.y"
                                                                                               {}
#line 1872 "y.tab.c"
    break;

  case 14:
#line 185 "bison.y"
        {(yyval.st).s = "Declaracion de variable Integer igual a operacion aritmetica"; 
	insertarElemento(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-6].st).s, &elementosOcupados, "integer" );
	 (yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);}
#line 1880 "y.tab.c"
    break;

  case 15:
#line 189 "bison.y"
                                                      {}
#line 1886 "y.tab.c"
    break;

  case 16:
#line 191 "bison.y"
                                                                                {}
#line 1892 "y.tab.c"
    break;

  case 17:
#line 192 "bison.y"
                                                                                                        {}
#line 1898 "y.tab.c"
    break;

  case 18:
#line 193 "bison.y"
                                                                                              {}
#line 1904 "y.tab.c"
    break;

  case 19:
#line 194 "bison.y"
                                                                                              {}
#line 1910 "y.tab.c"
    break;

  case 20:
#line 196 "bison.y"
        {(yyval.st).s = "Declaracion de variable Float igual a operacion aritmetica";
	insertarElemento(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-6].st).s, &elementosOcupados, "float" );
	(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);}
#line 1918 "y.tab.c"
    break;

  case 21:
#line 199 "bison.y"
                                                    {}
#line 1924 "y.tab.c"
    break;

  case 22:
#line 201 "bison.y"
                                                                                  {}
#line 1930 "y.tab.c"
    break;

  case 23:
#line 202 "bison.y"
                                                                                                              {}
#line 1936 "y.tab.c"
    break;

  case 24:
#line 203 "bison.y"
                                                                                                     {}
#line 1942 "y.tab.c"
    break;

  case 25:
#line 204 "bison.y"
                                                                                                    {}
#line 1948 "y.tab.c"
    break;

  case 26:
#line 205 "bison.y"
                                                                                                     {}
#line 1954 "y.tab.c"
    break;

  case 27:
#line 206 "bison.y"
                                                                                                    {}
#line 1960 "y.tab.c"
    break;

  case 28:
#line 207 "bison.y"
                                                                       {}
#line 1966 "y.tab.c"
    break;

  case 29:
#line 208 "bison.y"
                                                                          {}
#line 1972 "y.tab.c"
    break;

  case 30:
#line 209 "bison.y"
                                                      {}
#line 1978 "y.tab.c"
    break;

  case 31:
#line 213 "bison.y"
        {(yyval.st).s = "Declaracion con string";
	insertarElemento(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-6].st).s, &elementosOcupados, "string" );
	(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);
	}
#line 1987 "y.tab.c"
    break;

  case 32:
#line 217 "bison.y"
                                                     {(yyval.st).s = "Declaracion de variable String";}
#line 1993 "y.tab.c"
    break;

  case 33:
#line 219 "bison.y"
                                                                {}
#line 1999 "y.tab.c"
    break;

  case 34:
#line 220 "bison.y"
                                                                                        {}
#line 2005 "y.tab.c"
    break;

  case 35:
#line 221 "bison.y"
                                                                             {(yyval.st).s = "Variable igual a Variable operacion con operacion aritmetica";}
#line 2011 "y.tab.c"
    break;

  case 36:
#line 222 "bison.y"
                                                                              {}
#line 2017 "y.tab.c"
    break;

  case 37:
#line 223 "bison.y"
                                                                             {}
#line 2023 "y.tab.c"
    break;

  case 38:
#line 224 "bison.y"
                                                                              {}
#line 2029 "y.tab.c"
    break;

  case 39:
#line 225 "bison.y"
                                                     {}
#line 2035 "y.tab.c"
    break;

  case 40:
#line 226 "bison.y"
                                                      {}
#line 2041 "y.tab.c"
    break;

  case 41:
#line 227 "bison.y"
                                                                                            {}
#line 2047 "y.tab.c"
    break;

  case 42:
#line 228 "bison.y"
                                                                                   {}
#line 2053 "y.tab.c"
    break;

  case 43:
#line 229 "bison.y"
                                                                                  {}
#line 2059 "y.tab.c"
    break;

  case 44:
#line 230 "bison.y"
                                                                                   {}
#line 2065 "y.tab.c"
    break;

  case 45:
#line 231 "bison.y"
                                                                                  {}
#line 2071 "y.tab.c"
    break;

  case 46:
#line 232 "bison.y"
                                                     {}
#line 2077 "y.tab.c"
    break;

  case 47:
#line 233 "bison.y"
                                                        {}
#line 2083 "y.tab.c"
    break;

  case 48:
#line 234 "bison.y"
                                                       {}
#line 2089 "y.tab.c"
    break;

  case 49:
#line 236 "bison.y"
                                                                       {}
#line 2095 "y.tab.c"
    break;

  case 50:
#line 237 "bison.y"
                                                                                                                                 {}
#line 2101 "y.tab.c"
    break;

  case 51:
#line 238 "bison.y"
                                                                                                                       {}
#line 2107 "y.tab.c"
    break;

  case 52:
#line 244 "bison.y"
                     {}
#line 2113 "y.tab.c"
    break;

  case 53:
#line 245 "bison.y"
          {}
#line 2119 "y.tab.c"
    break;

  case 54:
#line 249 "bison.y"
             {(yyval.st).operador = "+";}
#line 2125 "y.tab.c"
    break;

  case 55:
#line 250 "bison.y"
                {(yyval.st).operador = "-";}
#line 2131 "y.tab.c"
    break;

  case 56:
#line 251 "bison.y"
               {(yyval.st).operador = "*";}
#line 2137 "y.tab.c"
    break;

  case 57:
#line 252 "bison.y"
              {(yyval.st).operador = "/";}
#line 2143 "y.tab.c"
    break;

  case 58:
#line 256 "bison.y"
                                                                                        {(yyval.st).i = (yyvsp[-2].st).i + (yyvsp[0].st).i; (yyval.st).a = createAST("+",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2149 "y.tab.c"
    break;

  case 59:
#line 257 "bison.y"
                                                                                        {(yyval.st).i = (yyvsp[-2].st).i - (yyvsp[0].st).i; (yyval.st).a = createAST("-",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2155 "y.tab.c"
    break;

  case 60:
#line 258 "bison.y"
                                                                                                {(yyval.st).i = (yyvsp[-2].st).i * (yyvsp[0].st).i; (yyval.st).a = createAST("*",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2161 "y.tab.c"
    break;

  case 61:
#line 259 "bison.y"
                                                                                                {(yyval.st).i = (yyvsp[-2].st).i / (yyvsp[0].st).i; (yyval.st).a = createAST("/",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2167 "y.tab.c"
    break;

  case 62:
#line 260 "bison.y"
                                                        {(yyval.st).i = (yyvsp[-1].st).i;}
#line 2173 "y.tab.c"
    break;

  case 63:
#line 261 "bison.y"
                                                                                                {(yyval.st).i = (yyvsp[0].eval); (yyval.st).a = createNum((yyvsp[0].eval));}
#line 2179 "y.tab.c"
    break;

  case 64:
#line 265 "bison.y"
                                                                                                {(yyval.st).f = (yyvsp[-2].st).f + (yyvsp[0].st).f; (yyval.st).a = createAST("+",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2185 "y.tab.c"
    break;

  case 65:
#line 266 "bison.y"
                                                                                        {(yyval.st).f = (yyvsp[-2].st).f - (yyvsp[0].st).f; (yyval.st).a = createAST("-",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2191 "y.tab.c"
    break;

  case 66:
#line 267 "bison.y"
                                                                                                {(yyval.st).f = (yyvsp[-2].st).f * (yyvsp[0].st).f; (yyval.st).a = createAST("*",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2197 "y.tab.c"
    break;

  case 67:
#line 268 "bison.y"
                                                                                                {(yyval.st).f = (yyvsp[-2].st).f / (yyvsp[0].st).f; (yyval.st).a = createAST("/",(yyvsp[-2].st).a,(yyvsp[0].st).a);}
#line 2203 "y.tab.c"
    break;

  case 68:
#line 269 "bison.y"
                                                        {(yyval.st).f = (yyvsp[-1].st).f;}
#line 2209 "y.tab.c"
    break;

  case 69:
#line 270 "bison.y"
                                                                                        {(yyval.st).f = (yyvsp[0].fval); (yyval.st).a = createNum((yyvsp[0].fval));}
#line 2215 "y.tab.c"
    break;

  case 70:
#line 273 "bison.y"
                        {(yyval.st).s = "IGUAL";(yyval.st).operador = "+";}
#line 2221 "y.tab.c"
    break;

  case 71:
#line 274 "bison.y"
                                        {(yyval.st).s = "DESIGUAL";(yyval.st).operador = "!=";}
#line 2227 "y.tab.c"
    break;

  case 72:
#line 275 "bison.y"
                                        {(yyval.st).s = "MENOR";(yyval.st).operador = "<";}
#line 2233 "y.tab.c"
    break;

  case 73:
#line 276 "bison.y"
                                        {(yyval.st).s = "MAYOR";(yyval.st).operador = ">";}
#line 2239 "y.tab.c"
    break;

  case 74:
#line 277 "bison.y"
                                        {(yyval.st).s = "MENOR IGUAL";(yyval.st).operador = "<=";}
#line 2245 "y.tab.c"
    break;

  case 75:
#line 278 "bison.y"
                                        {(yyval.st).s = "MAYOR IGUAL";(yyval.st).operador = ">=";}
#line 2251 "y.tab.c"
    break;

  case 76:
#line 281 "bison.y"
                                                        {(yyval.st).s = "ENTERO OP BOOL ENTERO";}
#line 2257 "y.tab.c"
    break;

  case 77:
#line 282 "bison.y"
                                                        {(yyval.st).s = "ENTERO OP BOOL FLOAT";}
#line 2263 "y.tab.c"
    break;

  case 78:
#line 283 "bison.y"
                                                        {(yyval.st).s = "FLOAT OP BOOL ENTERO";}
#line 2269 "y.tab.c"
    break;

  case 79:
#line 284 "bison.y"
                                                        {(yyval.st).s = "FLOAT OP BOOL FLOAT";}
#line 2275 "y.tab.c"
    break;

  case 80:
#line 285 "bison.y"
                                                                {(yyval.st).s = "ENTERO OP BOOL ENTERO";}
#line 2281 "y.tab.c"
    break;

  case 81:
#line 286 "bison.y"
                                                                {(yyval.st).s = "ENTERO OP BOOL ENTERO";}
#line 2287 "y.tab.c"
    break;

  case 82:
#line 287 "bison.y"
                                                                {(yyval.st).s = "FLOAT OP BOOL FLOAT";}
#line 2293 "y.tab.c"
    break;

  case 83:
#line 288 "bison.y"
                                                                {(yyval.st).s = "FLOAT OP BOOL FLOAT";}
#line 2299 "y.tab.c"
    break;

  case 84:
#line 289 "bison.y"
                                                        {(yyval.st).s = "PARENTESIS BOOL PARENTESIS";}
#line 2305 "y.tab.c"
    break;

  case 87:
#line 293 "bison.y"
                                {(yyval.st).s = "WHILE BOOL LOOP";}
#line 2311 "y.tab.c"
    break;

  case 88:
#line 294 "bison.y"
                                {(yyval.st).s = "FOR BOOL LOOP";}
#line 2317 "y.tab.c"
    break;

  case 89:
#line 295 "bison.y"
                                {(yyval.st).s = "END LOOP SEMICOLON";}
#line 2323 "y.tab.c"
    break;

  case 90:
#line 298 "bison.y"
                                {(yyval.st).s = "CASE BOOL IS";}
#line 2329 "y.tab.c"
    break;

  case 91:
#line 299 "bison.y"
                                {(yyval.st).s = "WHEN ENTERO FLECHA";}
#line 2335 "y.tab.c"
    break;

  case 92:
#line 300 "bison.y"
                                        {(yyval.st).s = "WHEN FLOAT FLECHA";}
#line 2341 "y.tab.c"
    break;

  case 93:
#line 302 "bison.y"
                                {(yyval.st).s = "WHEN OTHERS FLECHA";}
#line 2347 "y.tab.c"
    break;

  case 94:
#line 303 "bison.y"
                                {(yyval.st).s = "END CASE SEMICOLON";}
#line 2353 "y.tab.c"
    break;

  case 95:
#line 306 "bison.y"
                                {(yyval.st).s = "IF BOOL THEN";}
#line 2359 "y.tab.c"
    break;

  case 96:
#line 307 "bison.y"
                                                {(yyval.st).s = "ELSE";}
#line 2365 "y.tab.c"
    break;

  case 97:
#line 308 "bison.y"
                                {(yyval.st).s = "ELSEIF BOOL THEN";}
#line 2371 "y.tab.c"
    break;

  case 98:
#line 309 "bison.y"
                                        {(yyval.st).s = "END IF SEMICOLON";}
#line 2377 "y.tab.c"
    break;

  case 99:
#line 312 "bison.y"
                 {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2383 "y.tab.c"
    break;

  case 100:
#line 315 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2389 "y.tab.c"
    break;

  case 101:
#line 318 "bison.y"
                                {(yyval.sval) = "COMENTARIO";}
#line 2395 "y.tab.c"
    break;


#line 2399 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 321 "bison.y"

//FUNCIONES 

void iniArrayTabla(struct symb *tabla, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        tabla[i].vname = "._empty";
    }
	
}

void iniArrayNodos(struct ast *nodos, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        nodos[i].nodetype = "._empty";
    }
}




//FUNCIONES DEL AST

struct ast *createFlow(struct ast *cond){

struct flow *a = malloc(sizeof(struct flow));

if(!a) {
yyerror("out of space");
exit(0);
}

a->nodetype = "IF";
a->cond = cond;

return (struct ast *)a;
}

struct ast *createFlow2(struct ast *cond){

struct flow *a = malloc(sizeof(struct flow));

if(!a) {
yyerror("out of space");
exit(0);
}

a->nodetype = "WHILE";
a->cond = cond;

return (struct ast *)a;
}

struct ast *createASTAsignacion(struct ast *op){

	struct asign *a = malloc(sizeof(struct asign));
	if(!a) {
		yyerror("out of space");
		exit(0);
	}
	a->nodetype = "=";
	a->as = op;

	return (struct ast *)a;
}

struct ast *createAST(char* nodetype, struct ast *l, struct ast *r)
{
 struct ast *a = malloc(sizeof(struct ast));

 if(!a) {
 yyerror("out of space");
 exit(0);
 }
 a->nodetype = nodetype;
 a->l = l;
 a->r = r;
 return a;
}

struct ast *createBOO(char* nodetype, struct ast *l, struct ast *r) {

 struct boo *a = malloc(sizeof(struct boo));

 if(!a) {
 yyerror("out of space");
 exit(0);
 }
 a->nodetype = nodetype;
 a->l = l;
 a->r = r;
 return (struct ast *)a;
}

struct ast *createNum(double d)
{
 	struct numval *a = malloc(sizeof(struct numval));
  	if(!a) {
 		yyerror("out of space");
 		exit(0);
 	}
 	a->nodetype = "Constante";
 	a->number = d;
 	return (struct ast *)a;
}

struct ast *createSTR(char* s)
{
 	struct strval *a = malloc(sizeof(struct strval));
  	if(!a) {
 		yyerror("out of space");
 		exit(0);
 	}
 	a->nodetype = "String";
 	a->str = s;
 	return (struct ast *)a;
}

struct ast *createBOOVAR(char* s)
{
 	struct strval *a = malloc(sizeof(struct strval));
  	if(!a) {
 		yyerror("out of space");
 		exit(0);
 	}
 	a->nodetype = "Boolean_var";
 	a->str = s;
 	return (struct ast *)a;
}


void evalAST(struct ast a, int* size){
	
	int i = 0;
	int encontrado = 0;
	while (i < *size && encontrado == 0){
		if((strcmp(nodos[i].nodetype, "._empty") == 0) && (strcmp(a.nodetype, "String") != 0) && (strcmp(a.nodetype, "Constante") != 0) ){
			nodos[i] = a;
			numnodo = numnodo +1;
			encontrado = 1;
		}else{
			i++;
		}
	}
}


void printAST(struct ast nodos[], int i, int encontrado, int salida){
	struct ast temp[52];
	iniArrayNodos(temp,0,52);

	while(encontrado == 0 && salida == 0){
		if(strcmp(nodos[i].nodetype, "._empty") == 0){
			encontrado = 1;
			salida=1;
		}else{
			if(strcmp(nodos[i].nodetype, "IF") == 0){
				write_file(ast_text, "\n");
				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].l;
				printAST(temp,0,0,0);

			}else if(strcmp(nodos[i].nodetype, "WHILE") == 0){
					write_file(ast_text, "\n");
					write_file(ast_text, nodos[i].nodetype);
					write_file(ast_text, "\n");
					temp[0] = *nodos[i].l;
					printAST(temp,0,0,0);

			}else if((strcmp(nodos[i].nodetype, ">") == 0) || (strcmp(nodos[i].nodetype, "<") == 0) || (strcmp(nodos[i].nodetype, ">=") == 0) ||
						 (strcmp(nodos[i].nodetype, "<=") == 0) ||  (strcmp(nodos[i].nodetype, "!=") == 0) || (strcmp(nodos[i].nodetype, "==") == 0)){

				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].l; 
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].r; 
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");
				salida = 1;
				

			}else if(strcmp(nodos[i].nodetype, "=") == 0){
				write_file(ast_text, "\n");
				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				if((strcmp(nodos[i].l->nodetype, "+") == 0)||(strcmp(nodos[i].l->nodetype, "-") == 0)||(strcmp(nodos[i].l->nodetype, "/") == 0)||
				(strcmp(nodos[i].l->nodetype, "*") == 0)){

					temp[0] = *nodos[i].l;
					printAST(temp,0,0,0);


				}else{
					temp[0] = *nodos[i].l; 
					printAST(temp,0,0,0);

				}


			}else if((strcmp(nodos[i].nodetype, "+") == 0)||(strcmp(nodos[i].nodetype, "-") == 0)||(strcmp(nodos[i].nodetype, "/") == 0)||
				(strcmp(nodos[i].nodetype, "*") == 0)){

				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].l;
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");
				temp[0] = *nodos[i].r;
				printAST(temp,0,0,0);
				write_file(ast_text, "\n");

			}else if(strcmp(nodos[i].nodetype, "String") == 0){

				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				salida = 1;

			}else if(strcmp(nodos[i].nodetype, "Constante") == 0){
				write_file(ast_text, nodos[i].nodetype);
				write_file(ast_text, "\n");
				salida = 1;
				encontrado = 1;
			}			

		}
		i++;
	}
}

//FUNCIONES TABLA AUXILIAR DE SIMBOLOS
int buscarValor(struct symb *tabla, char *nombre, char *tipo, int *size) {
    int i = 0;
    int status = -1;
    while (i < *size && status == -1) {
        if (strcmp(tabla[i].vname, nombre) == 0 && (strcmp(tabla[i].type, tipo) == 0 )) {
            status = i;
        }else if(strcmp(tabla[i].vname, nombre) == 0){ 
        	status = i;
        }else {
            i++;
        }
    }
    return status;
}


void insertarElemento(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, int *elementosOcupados, char* type ) {
	int status = 0;
	
    status = buscarValor(tabla, variable, type, size);

    if(status != -1){
    	if (strcmp(type, "integer") == 0){
	        		tabla[status].vname = variable;
	        		tabla[status].vvali = valor;
	        		tabla[status].type = type;
	            } else if (strcmp(type, "float") == 0) {
	                tabla[status].vname = variable;
	                tabla[status].vvalf = fvalor;
	                tabla[status].type = type;
	            } else if (strcmp(type, "string") == 0) {
	                tabla[status].vname = variable;
	                tabla[status].vvals = svalor;
	                tabla[status].type = type;
	            }        	
    }else{

	    int i = 0;
	    int encontrado = 0;

	    while (i < *size && encontrado == 0) {

	        if (strcmp(tabla[i].vname, "._empty") == 0) {
	        	if (strcmp(type, "integer") == 0){
	        		tabla[i].vname = variable;
	        		tabla[i].vvali = valor;
	        		tabla[i].type = type;
	        		*elementosOcupados = *elementosOcupados + 1;
	        		encontrado = 1;
	            } else if (strcmp(type, "float") == 0) {
	                tabla[i].vname = variable;
	                tabla[i].vvalf = fvalor;
	                tabla[i].type = type;
	                *elementosOcupados = *elementosOcupados + 1;
	                encontrado = 1;
	            } else if (strcmp(type, "string") == 0) {
	                tabla[i].vname = variable;
	                tabla[i].vvals = svalor;
	                tabla[i].type = type;
	                *elementosOcupados = *elementosOcupados + 1;
	                encontrado = 1;
	            }        	
	            
	            *elementosOcupados = *elementosOcupados + 1;
	            encontrado = 1;
	        } else {
	            i++;
	        }
	    }
    }
     
}



//FUNCIONES AUXILIARES

void write_file(char *filename, char *content) {
    FILE *file;
    file = fopen(filename, "a");
    fprintf(file, "%s", content);
    fclose(file);
}

//FUNCIONES 
int main(int argc, char *argv[]) {

	iniArrayTabla(tabla, 0, size);
	iniArrayNodos(nodos, 0, size);

	if(argc == 1){
		yyparse();
	} 

	if(argc == 3){
		yyin = fopen(argv[1], "rt");
		yyout = fopen(argv[2], "wt" );
		yyparse();


		printf("\nTabla de simbolos:");
		for(int b = 0; b < 52; b++){
			if(strcmp(tabla[b].vname, "._empty") == 0){
				break;
			}
			printf("\n");		
			printf("Nombre %s ",tabla[b].vname);
			printf("INT %i ",tabla[b].vvali);
			printf("FLOAT %f ",tabla[b].vvalf);
			printf("STRING %s ",tabla[b].vvals);
			printf("TIPO %s ",tabla[b].type);
			printf("\n");

		}	

		printAST(nodos,0,0,0);
	}

	
	
}

