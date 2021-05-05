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
    EQUAL = 261,
    SUMA = 262,
    RESTA = 263,
    MULT = 264,
    DIV = 265,
    ABRIR_LLAVE = 266,
    CERRAR_LLAVE = 267,
    ABRIR_PARENTESIS = 268,
    CERRAR_PARENTESIS = 269,
    WHILE = 270,
    FOR = 271,
    CASE = 272,
    LOOP = 273,
    IF = 274,
    THEN = 275,
    ELSE = 276,
    ELSEIF = 277,
    END = 278,
    COMMENT = 279,
    NEWLINE = 280,
    SEMICOLON = 281,
    QUIT = 282,
    TRUE = 283,
    FALSE = 284,
    MENOR = 285,
    MAYOR = 286,
    MENOR_IGUAL = 287,
    MAYOR_IGUAL = 288,
    DESIGUAL = 289,
    IGUAL = 290,
    PLUS = 291,
    MINUS = 292,
    MULTIPLY = 293,
    DIVIDE = 294
  };
#endif
/* Tokens.  */
#define ENTERO 258
#define FLOAT 259
#define NOMBRE_VARIABLE 260
#define EQUAL 261
#define SUMA 262
#define RESTA 263
#define MULT 264
#define DIV 265
#define ABRIR_LLAVE 266
#define CERRAR_LLAVE 267
#define ABRIR_PARENTESIS 268
#define CERRAR_PARENTESIS 269
#define WHILE 270
#define FOR 271
#define CASE 272
#define LOOP 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ELSEIF 277
#define END 278
#define COMMENT 279
#define NEWLINE 280
#define SEMICOLON 281
#define QUIT 282
#define TRUE 283
#define FALSE 284
#define MENOR 285
#define MAYOR 286
#define MENOR_IGUAL 287
#define MAYOR_IGUAL 288
#define DESIGUAL 289
#define IGUAL 290
#define PLUS 291
#define MINUS 292
#define MULTIPLY 293
#define DIVIDE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "src/bison.y"

	int eval;
	float fval;
	char* sval;


#line 142 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
