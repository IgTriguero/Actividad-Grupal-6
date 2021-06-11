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
    NOMBRE_VARIABLE = 260,
    SUMA = 261,
    RESTA = 262,
    MULT = 263,
    DIV = 264,
    EQUAL = 265,
    FLECHA = 266,
    ABRIR_LLAVE = 267,
    CERRAR_LLAVE = 268,
    ABRIR_PARENTESIS = 269,
    CERRAR_PARENTESIS = 270,
    WHILE = 271,
    FOR = 272,
    CASE = 273,
    LOOP = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    ELSEIF = 278,
    END = 279,
    WHEN = 280,
    IS = 281,
    OTHERS = 282,
    PROCEDURE = 283,
    COMMENT = 284,
    NEWLINE = 285,
    SEMICOLON = 286,
    QUIT = 287,
    TRUE = 288,
    FALSE = 289,
    MENOR = 290,
    MAYOR = 291,
    MENOR_IGUAL = 292,
    MAYOR_IGUAL = 293,
    DESIGUAL = 294,
    IGUAL = 295,
    PLUS = 296,
    MINUS = 297,
    MULTIPLY = 298,
    DIVIDE = 299
  };
#endif
/* Tokens.  */
#define ENTERO 258
#define FLOAT 259
#define NOMBRE_VARIABLE 260
#define SUMA 261
#define RESTA 262
#define MULT 263
#define DIV 264
#define EQUAL 265
#define FLECHA 266
#define ABRIR_LLAVE 267
#define CERRAR_LLAVE 268
#define ABRIR_PARENTESIS 269
#define CERRAR_PARENTESIS 270
#define WHILE 271
#define FOR 272
#define CASE 273
#define LOOP 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ELSEIF 278
#define END 279
#define WHEN 280
#define IS 281
#define OTHERS 282
#define PROCEDURE 283
#define COMMENT 284
#define NEWLINE 285
#define SEMICOLON 286
#define QUIT 287
#define TRUE 288
#define FALSE 289
#define MENOR 290
#define MAYOR 291
#define MENOR_IGUAL 292
#define MAYOR_IGUAL 293
#define DESIGUAL 294
#define IGUAL 295
#define PLUS 296
#define MINUS 297
#define MULTIPLY 298
#define DIVIDE 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "bison.y"

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

#line 165 "y.tab.h"

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
