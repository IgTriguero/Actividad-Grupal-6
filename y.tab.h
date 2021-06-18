/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 191 "y.tab.h"

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
