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



/*
void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }
*/

void yyerror (char const *s) {
	printf("\x1b[1;31m");
	printf("%s\t Line %d\n", s, yylineno);
	printf("\x1b[0m");
	// fprintf (stderr, "%s\n", s);
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
	bool vbool;
	bool assigned;
};


//Variables globales
int line_num = 1;

int size = 52;

int elementosOcupados = 0;

int numnodo = 0;

struct ast nodos[52];

struct symb tabla[52];

void write_file(char *filename, char *content);//


// tabla simbolos
void iniArrayTabla(struct symb *tabla, int inicio, int fin); //

// nodos
void iniArrayNodos(struct ast *nodos, int inicio, int fin); //

// funciones ast
struct ast *createAST(char* nodetype, struct ast *l, struct ast *r);//
struct ast *createBOO(char* nodetype, struct ast *l, struct ast *r);//
struct ast *createFlow(struct ast *cond);//
struct ast *createFlow2(struct ast *cond);//
struct ast *createNum(double d);//
struct ast *createSTR(char* s);//
struct ast *createBOOLVAR(char* s);//
struct ast *createASTAsignacion(struct ast *op);//

//funciones tabla
void insertarElemento(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, bool bvalor, int *elementosOcupados, char* type, bool assigned );//
int buscarValor(struct symb *tabla, char *nombre, char *tipo, int *size);//
int retrieveIntFromTable(struct symb *tabla, int size, char* name);//
float retrieveFloatFromTable(struct symb *tabla, int size, char* name);//
char* retrieveStringFromTable(struct symb *tabla, int size, char* name);//
bool retrieveBoolFromTable(struct symb *tabla, int size, char* name);//
int operateInt(char* operator, int left, int right);
float operateFloat(char* operator, float left, float right);


bool checkVarAndType(struct symb *tabla, int size, char* name, char* type);//
bool searchVar(struct symb *tabla, int size, char* name);//
char* getVarType(struct symb *tabla, int size, char* name);//
int compare(char* operator, float left, float right);//


void evalAST(struct ast a, int* size);//
void printAST(struct ast nodos[], int i, int encontrado, int salida);//


#line 199 "y.tab.c"

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
    TRUE = 262,
    FALSE = 263,
    SUMA = 264,
    RESTA = 265,
    MULT = 266,
    DIV = 267,
    MENOR = 268,
    MAYOR = 269,
    MENOR_IGUAL = 270,
    MAYOR_IGUAL = 271,
    DESIGUAL = 272,
    IGUAL = 273,
    AND = 274,
    OR = 275,
    PROCEDURE = 276,
    COLON = 277,
    EQUAL = 278,
    SEMICOLON = 279,
    COMMA = 280,
    DOTDOT = 281,
    ABRIR_LLAVE = 282,
    CERRAR_LLAVE = 283,
    ABRIR_PARENTESIS = 284,
    CERRAR_PARENTESIS = 285,
    WHILE = 286,
    FOR = 287,
    CASE = 288,
    LOOP = 289,
    IF = 290,
    THEN = 291,
    ELSE = 292,
    ELSEIF = 293,
    END = 294,
    WHEN = 295,
    IS = 296,
    RANGE = 297,
    OF = 298,
    TYPE = 299,
    COMMENT = 300,
    QUIT = 301,
    DECLINTEGER = 302,
    DECLFLOAT = 303,
    DECLBOOLEAN = 304,
    DECLARRAY = 305,
    DECLSTRING = 306,
    PLUS = 307,
    MINUS = 308,
    MULTIPLY = 309,
    DIVIDE = 310
  };
#endif
/* Tokens.  */
#define ENTERO 258
#define FLOAT 259
#define STR 260
#define VAR_NAME 261
#define TRUE 262
#define FALSE 263
#define SUMA 264
#define RESTA 265
#define MULT 266
#define DIV 267
#define MENOR 268
#define MAYOR 269
#define MENOR_IGUAL 270
#define MAYOR_IGUAL 271
#define DESIGUAL 272
#define IGUAL 273
#define AND 274
#define OR 275
#define PROCEDURE 276
#define COLON 277
#define EQUAL 278
#define SEMICOLON 279
#define COMMA 280
#define DOTDOT 281
#define ABRIR_LLAVE 282
#define CERRAR_LLAVE 283
#define ABRIR_PARENTESIS 284
#define CERRAR_PARENTESIS 285
#define WHILE 286
#define FOR 287
#define CASE 288
#define LOOP 289
#define IF 290
#define THEN 291
#define ELSE 292
#define ELSEIF 293
#define END 294
#define WHEN 295
#define IS 296
#define RANGE 297
#define OF 298
#define TYPE 299
#define COMMENT 300
#define QUIT 301
#define DECLINTEGER 302
#define DECLFLOAT 303
#define DECLBOOLEAN 304
#define DECLARRAY 305
#define DECLSTRING 306
#define PLUS 307
#define MINUS 308
#define MULTIPLY 309
#define DIVIDE 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 131 "bison.y"

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

		char* error;
		int boo;

	}st;

#line 385 "y.tab.c"

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
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   206,   206,   216,   217,   222,   223,   224,   225,   229,
     248,   284,   320,   357,   376,   379,   385,   408,   428,   436,
     450,   518,   527,   537,   546,   552,   553,   554,   559,   560,
     563,   564,   568,   569,   570,   571,   575,   576,   580,   585,
     601,   604,   605,   606,   607,   608,   609,   613,   614,   618,
     636,   670,   703,   725,   726,   738,   739,   743,   752,   763,
     764,   765,   768,   769,   770,   771,   774,   777,   780
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENTERO", "FLOAT", "STR", "VAR_NAME",
  "TRUE", "FALSE", "SUMA", "RESTA", "MULT", "DIV", "MENOR", "MAYOR",
  "MENOR_IGUAL", "MAYOR_IGUAL", "DESIGUAL", "IGUAL", "AND", "OR",
  "PROCEDURE", "COLON", "EQUAL", "SEMICOLON", "COMMA", "DOTDOT",
  "ABRIR_LLAVE", "CERRAR_LLAVE", "ABRIR_PARENTESIS", "CERRAR_PARENTESIS",
  "WHILE", "FOR", "CASE", "LOOP", "IF", "THEN", "ELSE", "ELSEIF", "END",
  "WHEN", "IS", "RANGE", "OF", "TYPE", "COMMENT", "QUIT", "DECLINTEGER",
  "DECLFLOAT", "DECLBOOLEAN", "DECLARRAY", "DECLSTRING", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "$accept", "PROCLINE", "AUXCONTENT", "CONTENT",
  "ALLOPERS", "TYPEDECLARATION", "DECL", "AUXCOMPLETO", "AUXINT",
  "OP_ARIT", "OPERANDO", "ARIT", "OP_BOOLEANO", "ALLBOOL", "BOOL",
  "BOOLEAN_MIX", "BUCLE", "SENTENCIA_IF", "NOMBRE_VARIABLE", "STRING",
  "COMENTARIO", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-10)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    14,    24,   -77,    -7,   -77,   -77,    30,    19,    19,
      19,   -77,    19,     5,    14,   -77,   -77,   -77,   -77,   -77,
       8,   -77,   -77,   -77,   -77,   -77,    19,   -77,   128,   -11,
       1,   134,    32,    27,    36,    49,    52,    59,    54,    -2,
      76,    47,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,    67,    51,    19,    19,   -77,    51,   -77,   -77,
     -77,   -77,   -77,   -77,   -35,    19,   -77,   -77,    29,   107,
     108,   111,   -77,   -77,    67,    88,    88,   -77,   -77,   -77,
      88,   -77,   117,   106,   -77,   129,   128,   -77,   -11,   -77,
      98,   131,   -77,   132,   -77,   133,   -77,   135,     7,   136,
     154,   -77,    51,    51,    19,    53,    51,   130,   157,   137,
     -77,    88,   -77,   140,   110,   -77,   141,   142,   143,    88,
      88,   158,   144,   166,   -77,   -77,   -77,   -77,   -77,   145,
     -77,   146,   168,   147,   138,   -77,   148,    14,   -77,   149,
     -77
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    66,     0,     1,     4,     0,     0,     0,
       0,    63,     0,     0,     0,    68,     3,     8,     5,     6,
       0,     7,    36,    37,    55,    56,     0,    38,     0,     0,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,    35,    43,    44,    45,    46,
      42,    41,     0,     0,     0,     0,    59,     0,    60,    62,
      64,    61,    65,     2,     0,     0,    14,    15,     0,     0,
       0,     0,    40,    53,     0,    39,    49,    51,    57,    58,
      50,    52,     0,     0,    29,     0,    13,    28,    48,    47,
      54,     0,    21,     0,    24,     0,    17,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    11,    10,     0,    54,    67,     0,     0,     0,    13,
       9,     0,     0,     0,    19,    18,    22,    23,    16,    31,
      25,     0,     0,     0,     0,    30,     0,     0,    27,     0,
      26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   -77,    68,   -77,   -77,   -77,   -77,   -76,
     -77,   -24,   -30,    71,   -23,   109,   -77,   -77,    -1,   -77,
     -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    16,    84,    70,    17,    85,   133,    52,
      27,    28,    53,    87,    29,    89,    18,    19,    31,   117,
      21
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    57,    40,    41,     3,     1,    20,    82,    54,    55,
     102,     3,    37,    38,   103,    83,    42,    43,    44,    45,
       3,    65,    22,    23,     5,     3,    24,    25,    75,    76,
      39,    78,    79,    80,     6,    56,     3,    72,    71,    35,
      36,    86,    88,   102,   103,    66,    67,    68,    26,    69,
      98,    91,    77,    92,    22,    23,    81,     3,   115,     3,
      57,     8,     9,    59,    90,    10,    58,    11,    12,    13,
      22,    23,    60,    61,    14,    15,    62,    73,    75,   111,
      74,    88,   119,    63,    57,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    64,    74,    42,    43,    44,
      45,   110,   112,   114,   116,   120,    72,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    30,    32,    33,
      99,    34,    -9,    46,    47,    48,    49,    50,    51,    93,
      95,    94,    96,    97,   125,   100,   139,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    46,    47,    48,
      49,    50,    51,   101,   104,   105,   106,   109,   107,   121,
     122,   129,   108,   123,   124,   126,   127,   128,   130,   131,
     132,   135,   138,   140,   118,   113,   134,   136,     0,     0,
       0,   137
};

static const yytype_int16 yycheck[] =
{
       1,    31,    26,    26,     6,    21,     7,    42,    19,    20,
      86,     6,    13,    14,    90,    50,     9,    10,    11,    12,
       6,    23,     3,     4,     0,     6,     7,     8,    52,    53,
      22,    54,    55,    57,    41,    34,     6,    30,    39,    34,
      35,    65,    65,   119,   120,    47,    48,    49,    29,    51,
      74,    22,    53,    24,     3,     4,    57,     6,     5,     6,
      90,    31,    32,    36,    65,    35,    34,    37,    38,    39,
       3,     4,    36,    24,    44,    45,    24,    30,   102,   103,
      29,   104,   106,    24,   114,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    41,    29,     9,    10,    11,
      12,   102,   103,   104,   105,   106,    30,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     8,     9,    10,
       3,    12,    24,    13,    14,    15,    16,    17,    18,    22,
      22,    24,    24,    22,    24,    29,   137,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    13,    14,    15,
      16,    17,    18,    24,    23,    23,    23,     3,    23,    29,
       3,     3,    26,    26,    24,    24,    24,    24,    24,     3,
      25,     3,    24,    24,   106,   104,    30,    30,    -1,    -1,
      -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    57,     6,    74,     0,    41,    58,    31,    32,
      35,    37,    38,    39,    44,    45,    59,    62,    72,    73,
      74,    76,     3,     4,     7,     8,    29,    66,    67,    70,
      71,    74,    71,    71,    71,    34,    35,    74,    74,    22,
      67,    70,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    65,    68,    19,    20,    34,    68,    34,    36,
      36,    24,    24,    24,    41,    23,    47,    48,    49,    51,
      61,    74,    30,    30,    29,    67,    67,    74,    70,    70,
      67,    74,    42,    50,    60,    63,    67,    69,    70,    71,
      74,    22,    24,    22,    24,    22,    24,    22,    67,     3,
      29,    24,    65,    65,    23,    23,    23,    23,    26,     3,
      74,    67,    74,    69,    74,     5,    74,    75,    60,    67,
      74,    29,     3,    26,    24,    24,    24,    24,    24,     3,
      24,     3,    25,    64,    30,     3,    30,    43,    24,    74,
      24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    73,    73,    74,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     2,     0,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     1,     1,     7,     4,     7,     7,
       5,     4,     7,     7,     4,     8,    12,    10,     1,     1,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     1,     1
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
#line 206 "bison.y"
                                                                                      {
			if(strcmp((yyvsp[-5].st).s, (yyvsp[-1].st).s) == 0){
				printf("procedure comienza y termina con el mismo nombre\n");
			} else {
				printf("procedure NO comienza y termina con el mismo nombre\n");
			}
		}
#line 1787 "y.tab.c"
    break;

  case 3:
#line 216 "bison.y"
                           {}
#line 1793 "y.tab.c"
    break;

  case 4:
#line 217 "bison.y"
          {}
#line 1799 "y.tab.c"
    break;

  case 5:
#line 222 "bison.y"
          {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {evalAST(*(yyvsp[0].st).a, &size);};}
#line 1805 "y.tab.c"
    break;

  case 6:
#line 223 "bison.y"
                       {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {evalAST(*(yyvsp[0].st).a, &size);};}
#line 1811 "y.tab.c"
    break;

  case 7:
#line 224 "bison.y"
                     {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].sval), yylineno); }
#line 1817 "y.tab.c"
    break;

  case 8:
#line 225 "bison.y"
               {printf("Contenido: %s\t Linea: %d\n", (yyvsp[0].st).s, yylineno); if(!(yyvsp[0].st).a){ ;} else {evalAST(*(yyvsp[0].st).a, &size);};}
#line 1823 "y.tab.c"
    break;

  case 9:
#line 229 "bison.y"
                        {
		if(!searchVar(tabla, size, (yyvsp[0].st).s)) { 
			if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {
				(yyval.st).i = retrieveIntFromTable(tabla, size, (yyvsp[0].st).s);
				(yyval.st).type = "integer";
				(yyval.st).a = createASTAsignacion((yyvsp[0].st).a);
				(yyval.st).error = "empty";
			} else if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				(yyval.st).f = retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s);
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion((yyvsp[0].st).a);
				(yyval.st).error = "empty";
			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	
	}
#line 1847 "y.tab.c"
    break;

  case 10:
#line 248 "bison.y"
                                                  {
		if(!searchVar(tabla, size, (yyvsp[-2].st).s) && !searchVar(tabla, size, (yyvsp[0].st).s)) { 
			if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).i = operateInt((yyvsp[-1].st).operador, retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "integer";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	}
#line 1888 "y.tab.c"
    break;

  case 11:
#line 284 "bison.y"
                                       {
		if(!searchVar(tabla, size, (yyvsp[-2].st).s)) { 
			if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).i = operateInt((yyvsp[-1].st).operador, retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).i);
				(yyval.st).type = "integer";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	}
#line 1929 "y.tab.c"
    break;

  case 12:
#line 320 "bison.y"
                                       {
		if(!searchVar(tabla, size, (yyvsp[0].st).s)) { 

			if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).i = operateInt((yyvsp[-1].st).operador, (yyvsp[-2].st).i, retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "integer";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
				
				(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (yyvsp[-2].st).f, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
				(yyval.st).type = "float";
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));
				(yyval.st).error = "empty";

			} else {
				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}
	}
#line 1971 "y.tab.c"
    break;

  case 13:
#line 357 "bison.y"
               {
		if(strcmp((yyvsp[0].st).type, "integer")==0) {
			(yyval.st).i = (yyvsp[0].st).i;
			(yyval.st).type = "integer";
			(yyval.st).a = createASTAsignacion((yyvsp[0].st).a);
			(yyval.st).error = "empty";
		} else if(strcmp((yyvsp[0].st).type, "float")==0) {
			(yyval.st).f = (yyvsp[0].st).f;
			(yyval.st).type = "float";
			(yyval.st).a = createASTAsignacion((yyvsp[0].st).a);
			(yyval.st).error = "empty";
		} else {
			(yyval.st).error = "Variable de tipo incorrecto";
		}
			
	}
#line 1992 "y.tab.c"
    break;

  case 14:
#line 376 "bison.y"
                    {
		(yyval.st).type = "integer";
	}
#line 2000 "y.tab.c"
    break;

  case 15:
#line 379 "bison.y"
                    {
		(yyval.st).type = "float";
	}
#line 2008 "y.tab.c"
    break;

  case 16:
#line 385 "bison.y"
                                                                             {
		(yyval.st).s = "Declaracion de variable Integer o Float";
		if(strcmp((yyvsp[-1].st).error, "empty")==0){
			(yyval.st).error = (yyvsp[-1].st).error;
			if(strcmp((yyvsp[-4].st).type, "integer")==0 && strcmp((yyvsp[-1].st).type, "integer")==0){
				insertarElemento(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "integer", true );
				(yyval.st).a = (yyvsp[-1].st).a;
			} else if(strcmp((yyvsp[-4].st).type, "float")==0 && strcmp((yyvsp[-1].st).type, "float")==0){
				insertarElemento(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-6].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = (yyvsp[-1].st).a;
			} else if(strcmp((yyvsp[-4].st).type, "float")==0 && strcmp((yyvsp[-1].st).type, "integer")==0){
				insertarElemento(tabla, &size, 0, "", (float)(yyvsp[-1].st).i, (yyvsp[-6].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = (yyvsp[-1].st).a;
			} else {
				(yyval.st).error = "Error diferente tipo de variable (int, float)";
			}

		} else {
			(yyval.st).error = (yyvsp[-1].st).error;
		}
		
	}
#line 2035 "y.tab.c"
    break;

  case 17:
#line 408 "bison.y"
                                                          {
		(yyval.st).s = "Declaracion de variable Integer o Float vacia";
		if(strcmp((yyvsp[-1].st).type, "integer")==0){
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "integer", false );
			} else {
				(yyval.st).error = "Variable already declared";
			}
		} else if(strcmp((yyvsp[-1].st).type, "float")==0){ 
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "float", false );
			} else {
				(yyval.st).error = "Variable already declared";
			}	
		}
	}
#line 2058 "y.tab.c"
    break;

  case 18:
#line 428 "bison.y"
                                                                                  {
			if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s, "boolean")) {
				(yyval.st).error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-6].st).s, retrieveBoolFromTable(tabla, size, (yyvsp[-1].st).s), &elementosOcupados, "boolean", true );
				(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);
			} else {(yyval.st).error = "Variable declared or wrong type";}
			(yyval.st).s = "Declaracion de variable Boolean a operacion booleana";
		}
#line 2071 "y.tab.c"
    break;

  case 19:
#line 436 "bison.y"
                                                                          {
			if(strcmp((yyvsp[-1].st).error,"empty") == 0 ){
				if(searchVar(tabla, size, (yyvsp[-6].st).s)) {
					(yyval.st).error = "empty";
					insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-6].st).s, (yyvsp[-1].st).boo ? true : false, &elementosOcupados, "boolean", true );
					(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);
				} else {(yyval.st).error = "Variable declared or wrong type";}
			} else {
				(yyval.st).error = (yyvsp[-1].st).error;
			}
			
			(yyval.st).s = "Declaracion de variable Boolean a operacion booleana";
		}
#line 2089 "y.tab.c"
    break;

  case 20:
#line 450 "bison.y"
                                                                {
		(yyval.st).s = "asignación de variable a cualquier cosa";
		if(strcmp((yyvsp[-1].st).error,"empty") == 0 ) {
			(yyval.st).error = (yyvsp[-1].st).error;
			if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "integer")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {
				
				insertarElemento(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "integer", true );
				(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {

				insertarElemento(tabla, &size, 0, "", (float)(yyvsp[-1].st).i, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "float")==0) {

				insertarElemento(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
				(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "boolean")==0 && strcmp((yyvsp[-1].st).type, "boolean")==0) {

				insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-4].st).s, (yyvsp[-1].st).boo ? true : false, &elementosOcupados, "boolean", true );
				(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "string")==0 && strcmp((yyvsp[-1].st).type, "string")==0) {

				insertarElemento(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "string", true );
				(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

			} else if(strcmp((yyvsp[-1].st).type, "var")==0) {

				if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "integer")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {

					insertarElemento(tabla, &size, (yyvsp[-1].st).i, "", 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "integer", true );
					(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "integer")==0) {

					insertarElemento(tabla, &size, 0, "", (float)(yyvsp[-1].st).i, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
					(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "float")==0 && strcmp((yyvsp[-1].st).type, "float")==0) {

					insertarElemento(tabla, &size, 0, "", (yyvsp[-1].st).f, (yyvsp[-4].st).s, false, &elementosOcupados, "float", true );
					(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "boolean")==0 && strcmp((yyvsp[-1].st).type, "boolean")==0) {

					insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-4].st).s, (yyvsp[-1].st).boo ? true : false, &elementosOcupados, "boolean", true );
					(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

				} else if(strcmp(getVarType(tabla, size, (yyvsp[-4].st).s), "string")==0 && strcmp((yyvsp[-1].st).type, "string")==0) {

					insertarElemento(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-4].st).s, false, &elementosOcupados, "string", true );
					(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);

				} else {
					(yyval.st).error = "Invalid assignation type";
				}
			} else {
				(yyval.st).error = "Invalid assignation type";
			}
		} else {
			(yyval.st).error = (yyvsp[-1].st).error;
		}
	}
#line 2160 "y.tab.c"
    break;

  case 21:
#line 518 "bison.y"
                                                      {
			(yyval.st).s = "Declaracion de variable Boolean vacia";
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
				(yyval.st).error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "boolean", false );
			} else {
				(yyval.st).error = "Variable declared";
			}
		}
#line 2174 "y.tab.c"
    break;

  case 22:
#line 527 "bison.y"
                                                                                 {
			(yyval.st).s = "Declaracion de variable String igual a variable String"; 
			if(searchVar(tabla, size, (yyvsp[-6].st).s) && checkVarAndType(tabla, size, (yyvsp[-1].st).s,"string")) {
				(yyval.st).error = "empty";
				insertarElemento(tabla, &size, 0, retrieveStringFromTable(tabla, size, (yyvsp[-1].st).s), 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "string", true );
				(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);
			} else {
				(yyval.st).error = "Variable declared or wrong type";
			}
		}
#line 2189 "y.tab.c"
    break;

  case 23:
#line 537 "bison.y"
                                                                        {
			(yyval.st).s = "Declaracion con string";
			if(searchVar(tabla, size, (yyvsp[-6].st).s)) {
				(yyval.st).error = "empty"; 
				insertarElemento(tabla, &size, 0, (yyvsp[-1].st).s, 0.0, (yyvsp[-6].st).s, false, &elementosOcupados, "string", true );(yyval.st).a = createASTAsignacion((yyvsp[-1].st).a);
			} else {
				(yyval.st).error = "Variable declared or wrong type";
			}
		}
#line 2203 "y.tab.c"
    break;

  case 24:
#line 546 "bison.y"
                                                     {
			(yyval.st).s = "Declaracion de variable String vacia";
			if (searchVar(tabla, size, (yyvsp[-3].st).s)) {
			(yyval.st).error = "empty";insertarElemento(tabla, &size, 0, "", 0.0, (yyvsp[-3].st).s, false, &elementosOcupados, "string", false );} else {(yyval.st).error = "Variable declared";}
		}
#line 2213 "y.tab.c"
    break;

  case 25:
#line 552 "bison.y"
                                                                       {(yyval.st).s = "Tipo Variable en rango entero";}
#line 2219 "y.tab.c"
    break;

  case 26:
#line 553 "bison.y"
                                                                                                                                 {(yyval.st).s = "Tipo Variable declaraccion array entero de Variable";}
#line 2225 "y.tab.c"
    break;

  case 27:
#line 554 "bison.y"
                                                                                                                       {(yyval.st).s = "Declaracion de array";}
#line 2231 "y.tab.c"
    break;

  case 28:
#line 559 "bison.y"
                {(yyval.st) = (yyvsp[0].st);}
#line 2237 "y.tab.c"
    break;

  case 29:
#line 560 "bison.y"
                   {(yyval.st) = (yyvsp[0].st); }
#line 2243 "y.tab.c"
    break;

  case 30:
#line 563 "bison.y"
                     {}
#line 2249 "y.tab.c"
    break;

  case 31:
#line 564 "bison.y"
          {}
#line 2255 "y.tab.c"
    break;

  case 32:
#line 568 "bison.y"
             {(yyval.st).operador = "+";}
#line 2261 "y.tab.c"
    break;

  case 33:
#line 569 "bison.y"
                {(yyval.st).operador = "-";}
#line 2267 "y.tab.c"
    break;

  case 34:
#line 570 "bison.y"
               {(yyval.st).operador = "*";}
#line 2273 "y.tab.c"
    break;

  case 35:
#line 571 "bison.y"
              {(yyval.st).operador = "/";}
#line 2279 "y.tab.c"
    break;

  case 36:
#line 575 "bison.y"
               {(yyval.st).i = (yyvsp[0].eval); (yyval.st).type = "integer"; (yyval.st).error="empty"; (yyval.st).a = createNum((yyvsp[0].eval));}
#line 2285 "y.tab.c"
    break;

  case 37:
#line 576 "bison.y"
                      {(yyval.st).f = (yyvsp[0].fval); (yyval.st).type = "float"; (yyval.st).error="empty"; (yyval.st).a = createNum((yyvsp[0].fval));}
#line 2291 "y.tab.c"
    break;

  case 38:
#line 580 "bison.y"
                 {
		(yyval.st).type = (yyvsp[0].st).type;
		(yyval.st).a = (yyvsp[0].st).a;
		if (strcmp("integer", (yyvsp[0].st).type) == 0) {(yyval.st).i = (yyvsp[0].st).i;} else {(yyval.st).f = (yyvsp[0].st).f;}
	}
#line 2301 "y.tab.c"
    break;

  case 39:
#line 585 "bison.y"
                            {
		if(strcmp((yyvsp[-2].st).type, "float") == 0 && strcmp((yyvsp[0].st).type, "float") == 0) {
			(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (yyvsp[0].st).f);
			(yyval.st).type = "float";
		} else if (strcmp((yyvsp[0].st).type, "float") == 0) {
			(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (yyvsp[0].st).f);
			(yyval.st).type = "float";
		} else if (strcmp((yyvsp[-2].st).type, "float") == 0) {
			(yyval.st).f = operateFloat((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)(yyvsp[0].st).i);
			(yyval.st).type = "float";
		} else {
			(yyval.st).i = operateInt((yyvsp[-1].st).operador, (yyvsp[-2].st).i, (yyvsp[0].st).i);
			(yyval.st).type = "integer";
		}
		(yyval.st).a = createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
	}
#line 2322 "y.tab.c"
    break;

  case 40:
#line 601 "bison.y"
                                                  {if(strcmp((yyvsp[-1].st).type, "float") == 0) {(yyval.st).f = (yyvsp[-1].st).f;} else {(yyval.st).i = (yyvsp[-1].st).i;}}
#line 2328 "y.tab.c"
    break;

  case 41:
#line 604 "bison.y"
                        {(yyval.st).s = "IGUAL";(yyval.st).operador = "==";}
#line 2334 "y.tab.c"
    break;

  case 42:
#line 605 "bison.y"
                                        {(yyval.st).s = "DESIGUAL";(yyval.st).operador = "!=";}
#line 2340 "y.tab.c"
    break;

  case 43:
#line 606 "bison.y"
                                        {(yyval.st).s = "MENOR";(yyval.st).operador = "<";}
#line 2346 "y.tab.c"
    break;

  case 44:
#line 607 "bison.y"
                                        {(yyval.st).s = "MAYOR";(yyval.st).operador = ">";}
#line 2352 "y.tab.c"
    break;

  case 45:
#line 608 "bison.y"
                                        {(yyval.st).s = "MENOR IGUAL";(yyval.st).operador = "<=";}
#line 2358 "y.tab.c"
    break;

  case 46:
#line 609 "bison.y"
                                        {(yyval.st).s = "MAYOR IGUAL";(yyval.st).operador = ">=";}
#line 2364 "y.tab.c"
    break;

  case 47:
#line 613 "bison.y"
                    {(yyval.st) = (yyvsp[0].st); (yyval.st).type = "boolean";}
#line 2370 "y.tab.c"
    break;

  case 48:
#line 614 "bison.y"
               {(yyval.st) = (yyvsp[0].st); (yyval.st).type = "boolean";}
#line 2376 "y.tab.c"
    break;

  case 49:
#line 618 "bison.y"
                                                {
		(yyval.st).s = "INT OP BOOL INT";
		(yyval.st).error = "empty";
		if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp((yyvsp[0].st).type, "integer")==0){	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (float)(yyvsp[0].st).i);
			(yyval.st).a = createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		} else if(strcmp((yyvsp[0].st).type, "integer")==0){	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)(yyvsp[0].st).i);
			(yyval.st).a = createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		} else if(strcmp((yyvsp[-2].st).type, "integer")==0){	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (yyvsp[0].st).f);
			(yyval.st).a = createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		} else {	
			(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (yyvsp[0].st).f);
			(yyval.st).a = createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a); 
		}  
	}
#line 2398 "y.tab.c"
    break;

  case 50:
#line 636 "bison.y"
                                                                {

		(yyval.st).s = "VAR OP BOOL INT";
		if(!searchVar(tabla, size, (yyvsp[-2].st).s)) { 
			(yyval.st).error = "empty";
			if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "integer")==0) {

				(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)(yyvsp[0].st).i);
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "integer")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else if(strcmp(getVarType(tabla, size, (yyvsp[-2].st).s), "float")==0 && strcmp((yyvsp[0].st).type, "float")==0) {
				
				(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (yyvsp[0].st).f);
				(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

			} else {

				(yyval.st).error = "Variable de tipo incorrecto";
			}
			
		} else {yyerror("Variable not declared");}

		}
#line 2436 "y.tab.c"
    break;

  case 51:
#line 670 "bison.y"
                                                                {
			(yyval.st).s = "INT OP BOOL VAR";
			if(!searchVar(tabla, size, (yyvsp[0].st).s)) { 
				(yyval.st).error = "empty";
				if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

					(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "integer")==0) {

					(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else if(strcmp((yyvsp[-2].st).type, "integer")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {
					
					(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)(yyvsp[-2].st).i, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else if(strcmp((yyvsp[-2].st).type, "float")==0 && strcmp(getVarType(tabla, size, (yyvsp[0].st).s), "float")==0) {

					(yyval.st).boo = compare((yyvsp[-1].st).operador, (yyvsp[-2].st).f, retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a = createASTAsignacion(createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a));

				} else {
					(yyval.st).error = "Variable de tipo incorrecto";
				}
			
			} else {
				yyerror("Variable not declared");
			}
		}
#line 2473 "y.tab.c"
    break;

  case 52:
#line 703 "bison.y"
                                                                        {
			(yyval.st).s = "VAR OP BOOL VAR";
			if(!searchVar(tabla, size, (yyvsp[-2].st).s) && !searchVar(tabla, size, (yyvsp[0].st).s)) {
				(yyval.st).error = "empty";
				if((strcmp("integer", getVarType(tabla, size, (yyvsp[-2].st).s)) == 0) && (strcmp("integer", getVarType(tabla, size, (yyvsp[0].st).s)) == 0)){
					(yyval.st).boo = compare((yyvsp[-1].st).operador,	(float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else if((strcmp("float", getVarType(tabla, size, (yyvsp[-2].st).s))  == 0) && (strcmp("float", getVarType(tabla, size, (yyvsp[0].st).s))  == 0)){
					(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else if ((strcmp("integer", getVarType(tabla, size, (yyvsp[-2].st).s))  == 0) && (strcmp("float", getVarType(tabla, size, (yyvsp[0].st).s))  == 0)) {
					(yyval.st).boo = compare((yyvsp[-1].st).operador, (float)retrieveIntFromTable(tabla, size, (yyvsp[-2].st).s), retrieveFloatFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else if ((strcmp("float", getVarType(tabla, size, (yyvsp[-2].st).s))  == 0) && (strcmp("integer", getVarType(tabla, size, (yyvsp[0].st).s))  == 0)) {
					(yyval.st).boo = compare((yyvsp[-1].st).operador, retrieveFloatFromTable(tabla, size, (yyvsp[-2].st).s), (float)retrieveIntFromTable(tabla, size, (yyvsp[0].st).s));
					(yyval.st).a=createAST((yyvsp[-1].st).operador, (yyvsp[-2].st).a, (yyvsp[0].st).a);
				} else {
					(yyval.st).error = "Esta variable tiene un tipo incorrecto";
				}  
				
			} else {(yyval.st).error = "Variable declared or wrong type";}
		}
#line 2500 "y.tab.c"
    break;

  case 53:
#line 725 "bison.y"
                                                        {(yyval.st).s = "PARENTESIS BOOL PARENTESIS"; (yyval.st).boo = (yyvsp[-1].st).boo;}
#line 2506 "y.tab.c"
    break;

  case 54:
#line 726 "bison.y"
                          {
		(yyval.st).s = "PARENTESIS BOOL PARENTESIS";
		if(!searchVar(tabla, size, (yyvsp[0].st).s)){
			if(strcmp("boolean", getVarType(tabla, size, (yyvsp[0].st).s)) == 0){
				(yyval.st).boo = retrieveBoolFromTable(tabla, size, (yyvsp[0].st).s);
			} else {
				(yyval.st).error = "La variable no es un boolean";
			}
		} else {
			(yyval.st).error = "variable no declarada";
		}
	}
#line 2523 "y.tab.c"
    break;

  case 55:
#line 738 "bison.y"
               {(yyval.st).boo=1; (yyval.st).a = createBOOLVAR("True");}
#line 2529 "y.tab.c"
    break;

  case 56:
#line 739 "bison.y"
                {(yyval.st).boo=0; (yyval.st).a = createBOOLVAR("False");}
#line 2535 "y.tab.c"
    break;

  case 57:
#line 743 "bison.y"
                      {
		(yyval.st).s="Expresiones booleanas con AND\n";
		(yyval.st).error = "empty";
		if((yyvsp[-2].st).boo == (yyvsp[0].st).boo){
			(yyval.st).boo = 1;
		} else {
			(yyval.st).boo = 0;
		}
	}
#line 2549 "y.tab.c"
    break;

  case 58:
#line 752 "bison.y"
                       {
		(yyval.st).s="Expresiones booleanas con OR\n";
		(yyval.st).error = "empty";
		if((yyvsp[-2].st).boo == 1 || (yyvsp[0].st).boo == 1){
			(yyval.st).boo = 1;
		} else {
			(yyval.st).boo = 0;
		}
	}
#line 2563 "y.tab.c"
    break;

  case 59:
#line 763 "bison.y"
                                {(yyval.st).s = "WHILE BOOL LOOP";}
#line 2569 "y.tab.c"
    break;

  case 60:
#line 764 "bison.y"
                                        {(yyval.st).s = "FOR BOOL LOOP";}
#line 2575 "y.tab.c"
    break;

  case 61:
#line 765 "bison.y"
                                {(yyval.st).s = "END LOOP SEMICOLON";}
#line 2581 "y.tab.c"
    break;

  case 62:
#line 768 "bison.y"
                                        {(yyval.st).s = "IF BOOL THEN";}
#line 2587 "y.tab.c"
    break;

  case 63:
#line 769 "bison.y"
                                                {(yyval.st).s = "ELSE";}
#line 2593 "y.tab.c"
    break;

  case 64:
#line 770 "bison.y"
                                {(yyval.st).s = "ELSEIF BOOL THEN";}
#line 2599 "y.tab.c"
    break;

  case 65:
#line 771 "bison.y"
                                        {(yyval.st).s = "END IF SEMICOLON";}
#line 2605 "y.tab.c"
    break;

  case 66:
#line 774 "bison.y"
                 {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2611 "y.tab.c"
    break;

  case 67:
#line 777 "bison.y"
            {(yyval.st).s = (yyvsp[0].sval); (yyval.st).a = createSTR((yyvsp[0].sval));}
#line 2617 "y.tab.c"
    break;

  case 68:
#line 780 "bison.y"
                                {(yyval.sval) = "COMENTARIO";}
#line 2623 "y.tab.c"
    break;


#line 2627 "y.tab.c"

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
#line 783 "bison.y"

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
struct ast *createFlow(struct ast *cond) {

    struct flow *a = malloc(sizeof(struct flow));

    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }

    a->nodetype = "IF";
    a->cond = cond;

    return (struct ast *)a;
}

struct ast *createFlow2(struct ast *cond) {

    struct flow *a = malloc(sizeof(struct flow));

    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }

    a->nodetype = "WHILE";
    a->cond = cond;

    return (struct ast *)a;
}

struct ast *createASTAsignacion(struct ast *op)
{

    struct asign *a = malloc(sizeof(struct asign));
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "=";
    a->as = op;

    return (struct ast *)a;
}

struct ast *createAST(char *nodetype, struct ast *l, struct ast *r)
{
    struct ast *a = malloc(sizeof(struct ast));

    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

struct ast *createBOO(char *nodetype, struct ast *l, struct ast *r)
{

    struct boo *a = malloc(sizeof(struct boo));

    if (!a)
    {
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
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "Constante";
    a->number = d;
    return (struct ast *)a;
}

struct ast *createSTR(char *s)
{
    struct strval *a = malloc(sizeof(struct strval));
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "String";
    a->str = s;
    return (struct ast *)a;
}

struct ast *createBOOLVAR(char *s)
{
    struct strval *a = malloc(sizeof(struct strval));
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "Boolean_var";
    a->str = s;
    return (struct ast *)a;
}

void evalAST(struct ast a, int *size)
{

    int i = 0;
    int encontrado = 0;
    while (i < *size && encontrado == 0)
    {
        if ((strcmp(nodos[i].nodetype, "._empty") == 0) && (strcmp(a.nodetype, "String") != 0) && (strcmp(a.nodetype, "Constante") != 0))
        {
            nodos[i] = a;
            numnodo = numnodo + 1;
            encontrado = 1;
        }
        else
        {
            i++;
        }
    }
}

void printAST(struct ast nodos[], int i, int encontrado, int salida)
{
    struct ast temp[52];
    iniArrayNodos(temp, 0, 52);

    while (encontrado == 0 && salida == 0)
    {
        if (strcmp(nodos[i].nodetype, "._empty") == 0)
        {
            encontrado = 1;
            salida = 1;
        }
        else
        {
            if (strcmp(nodos[i].nodetype, "IF") == 0)
            {
                write_file(ast_text, "\n");
                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
            }
            else if (strcmp(nodos[i].nodetype, "WHILE") == 0)
            {
                write_file(ast_text, "\n");
                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
            }
            else if ((strcmp(nodos[i].nodetype, ">") == 0) || (strcmp(nodos[i].nodetype, "<") == 0) || (strcmp(nodos[i].nodetype, ">=") == 0) ||
                     (strcmp(nodos[i].nodetype, "<=") == 0) || (strcmp(nodos[i].nodetype, "!=") == 0) || (strcmp(nodos[i].nodetype, "==") == 0))
            {

                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].r;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
                salida = 1;
            }
            else if (strcmp(nodos[i].nodetype, "=") == 0)
            {
                write_file(ast_text, "\n");
                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                if ((strcmp(nodos[i].l->nodetype, "+") == 0) || (strcmp(nodos[i].l->nodetype, "-") == 0) || (strcmp(nodos[i].l->nodetype, "/") == 0) ||
                    (strcmp(nodos[i].l->nodetype, "*") == 0))
                {

                    temp[0] = *nodos[i].l;
                    printAST(temp, 0, 0, 0);
                }
                else
                {
                    temp[0] = *nodos[i].l;
                    printAST(temp, 0, 0, 0);
                }
            }
            else if ((strcmp(nodos[i].nodetype, "+") == 0) || (strcmp(nodos[i].nodetype, "-") == 0) || (strcmp(nodos[i].nodetype, "/") == 0) ||
                     (strcmp(nodos[i].nodetype, "*") == 0))
            {

                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].r;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
            }
            else if (strcmp(nodos[i].nodetype, "String") == 0)
            {

                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                salida = 1;
            }
            else if (strcmp(nodos[i].nodetype, "Constante") == 0)
            {
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
int buscarValor(struct symb *tabla, char *nombre, char *tipo, int *size)
{
    int i = 0;
    int status = -1;
    while (i < *size && status == -1)
    {
        if (strcmp(tabla[i].vname, nombre) == 0 && (strcmp(tabla[i].type, tipo) == 0))
        {
            status = i;
        }
        else if (strcmp(tabla[i].vname, nombre) == 0)
        {
            status = i;
        }
        else
        {
            i++;
        }
    }
    return status;
}

void insertarElemento(struct symb *tabla, int *size, int valor, char *svalor, float fvalor, char *variable, bool bvalor, int *elementosOcupados, char *type, bool assigned)
{
    int elementIndex = 0;

    elementIndex = buscarValor(tabla, variable, type, size);

    if (elementIndex != -1)
    {
        if (strcmp(type, "integer") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vvali = valor;
            tabla[elementIndex].type = type;
        }
        else if (strcmp(type, "float") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vvalf = fvalor;
            tabla[elementIndex].type = type;
        }
        else if (strcmp(type, "string") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vvals = svalor;
            tabla[elementIndex].type = type;
        }
        else if (strcmp(type, "boolean") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vbool = bvalor;
            tabla[elementIndex].type = type;
        }
        tabla[elementIndex].assigned = assigned;
    }
    else
    {
        int i = 0;
        int encontrado = 0;

        while (i < *size && encontrado == 0)
        {

            if (strcmp(tabla[i].vname, "._empty") == 0)
            {
                if (strcmp(type, "integer") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vvali = valor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                else if (strcmp(type, "float") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vvalf = fvalor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                else if (strcmp(type, "string") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vvals = svalor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                else if (strcmp(type, "boolean") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vbool = bvalor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                tabla[i].assigned = assigned;
                *elementosOcupados = *elementosOcupados + 1;
                encontrado = 1;
            }
            else
            {
                i++;
            }
        }
    }
}

int compare(char *operator, float left, float right)
{
    if (strcmp(operator, ">") == 0)
    {
        return left > right ? 1 : 0;
    }
    else if (strcmp(operator, "<") == 0)
    {
        return left < right ? 1 : 0;
    }
    else if (strcmp(operator, ">=") == 0)
    {
        return left >= right ? 1 : 0;
    }
    else if (strcmp(operator, "<=") == 0)
    {
        return left <= right ? 1 : 0;
    }
    else if (strcmp(operator, "==") == 0)
    {
        return left == right ? 1 : 0;
    }
    else if (strcmp(operator, "!=") == 0)
    {
        return left != right ? 1 : 0;
    }
}

char *getVarType(struct symb *tabla, int size, char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, "._empty") == 0)
        {
            continue;
        }
        else if (strcmp(tabla[i].vname, name) == 0)
        {
            return tabla[i].type;
        }
    }
}

bool searchVar(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, "._empty") == 0)
        {
            continue;
        }
        else if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    if (elementIndex != -1)
    {
        return false;
    }

    return true;
}

bool checkVarAndType(struct symb *tabla, int size, char *name, char *type)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, "._empty") == 0)
        {
            continue;
        }
        else if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    if (elementIndex == -1)
    {
        return false;
    }

    if (strcmp(tabla[elementIndex].type, type) != 0)
    {
        return false;
    }

    return true;
}

int retrieveIntFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vvali;
}

float retrieveFloatFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vvalf;
}

char *retrieveStringFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vvals;
}

bool retrieveBoolFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vbool;
}

int operateInt(char* operator, int left, int right){
	if(strcmp(operator, "+")==0){
		return left + right;
	} else if(strcmp(operator, "-")==0){
		return left - right;
	} else if(strcmp(operator, "*")==0){
		return left * right;
	} else if(strcmp(operator, "/")==0){
		return left / right;
	} else {
		return -500;
	}
}

float operateFloat(char* operator, float left, float right){
	if(strcmp(operator, "+")==0){
		return left + right;
	} else if(strcmp(operator, "-")==0){
		return left - right;
	} else if(strcmp(operator, "*")==0){
		return left * right;
	} else if(strcmp(operator, "/")==0){
		return left / right;
	} else {
		return -500;
	}
}

//FUNCIONES AUXILIARES

void write_file(char *filename, char *content)
{
    FILE *file;
    file = fopen(filename, "a");
    fprintf(file, "%s", content);
    fclose(file);
}

//FUNCIONES
int main(int argc, char *argv[])
{

    iniArrayTabla(tabla, 0, size);
    iniArrayNodos(nodos, 0, size);

    if (argc == 1)
    {
        yyparse();
    }

    if (argc == 3)
    {
        yyin = fopen(argv[1], "rt");
        yyout = fopen(argv[2], "wt");
        printf("\n");
        yyparse();

        printf("\nTabla de simbolos:");
        for (int b = 0; b < 52; b++)
        {
            if (strcmp(tabla[b].vname, "._empty") == 0)
            {
                break;
            }
            printf("\n");
            printf("Nombre %s ", tabla[b].vname);
            printf("INT %i ", tabla[b].vvali);
            printf("FLOAT %f ", tabla[b].vvalf);
            printf("STRING %s ", tabla[b].vvals);
            printf("TIPO %s ", tabla[b].type);
            printf("BOOLEAN\t%s\t", tabla[b].vbool ? "true" : "false");
            printf("ASSIGNED\t%s\t", tabla[b].assigned ? "true" : "false");
            printf("\n");
        }

        printAST(nodos, 0, 0, 0);
    }
}
