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

#line 189 "y.tab.h"

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
