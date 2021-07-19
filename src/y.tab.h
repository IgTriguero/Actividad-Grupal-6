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
    MAS = 258,
    MENOS = 259,
    POR = 260,
    DIV = 261,
    PAR_I = 262,
    PAR_D = 263,
    IF = 264,
    THEN = 265,
    MAYOR_Q = 266,
    MENOR_Q = 267,
    ELSE = 268,
    PROCEDURE = 269,
    IS = 270,
    END = 271,
    BEGINN = 272,
    DOSPUNTOS = 273,
    INTEGER = 274,
    FLOAT = 275,
    STRING = 276,
    BOOLEAN = 277,
    IDENTIFICADORSIMB = 278,
    PIZQ_COM = 279,
    DOSPUNTOS_IGUAL = 280,
    PDECH_COM = 281,
    PUTLINE = 282,
    ENDIF = 283,
    TRUE = 284,
    FALSE = 285,
    COMENTARIO = 286,
    WHILE = 287,
    LOOP = 288,
    ENDLOOP = 289,
    IGUAL = 290,
    FOR = 291,
    IN = 292,
    RANGO = 293,
    FUNCION = 294,
    RETURN = 295,
    PUNTO_COMA = 296,
    NUMENTERO = 297,
    NUMREAL = 298,
    IDENTIFICADOR = 299
  };
#endif
/* Tokens.  */
#define MAS 258
#define MENOS 259
#define POR 260
#define DIV 261
#define PAR_I 262
#define PAR_D 263
#define IF 264
#define THEN 265
#define MAYOR_Q 266
#define MENOR_Q 267
#define ELSE 268
#define PROCEDURE 269
#define IS 270
#define END 271
#define BEGINN 272
#define DOSPUNTOS 273
#define INTEGER 274
#define FLOAT 275
#define STRING 276
#define BOOLEAN 277
#define IDENTIFICADORSIMB 278
#define PIZQ_COM 279
#define DOSPUNTOS_IGUAL 280
#define PDECH_COM 281
#define PUTLINE 282
#define ENDIF 283
#define TRUE 284
#define FALSE 285
#define COMENTARIO 286
#define WHILE 287
#define LOOP 288
#define ENDLOOP 289
#define IGUAL 290
#define FOR 291
#define IN 292
#define RANGO 293
#define FUNCION 294
#define RETURN 295
#define PUNTO_COMA 296
#define NUMENTERO 297
#define NUMREAL 298
#define IDENTIFICADOR 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 85 "./src/bison.y"

        int number;
        double numberf;
        char *string;
	struct {
     		char *tipo;
    		int valor;
    		double valord;
    		char *texto;
 		int booleanCond;
		struct ast *a;
		struct flow *f;
		struct fncall *fun;
  		} snum;

#line 161 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
