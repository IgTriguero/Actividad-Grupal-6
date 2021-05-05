%{

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int eval;
	float fval;
	char* sval;

}
//TERMINALES

%token<eval> ENTERO
%token<fval> FLOAT
%token<sval> NOMBRE_VARIABLE

%token EQUAL FLECHA
%token SUMA RESTA MULT DIV
%token ABRIR_LLAVE CERRAR_LLAVE ABRIR_PARENTESIS CERRAR_PARENTESIS
%token WHILE FOR CASE LOOP
%token IF THEN ELSE ELSEIF END WHEN IS OTHERS

%token COMMENT NEWLINE SEMICOLON QUIT
%token TRUE FALSE

%token MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL DESIGUAL IGUAL

%left PLUS MINUS
%left MULTIPLY DIVIDE


//NO TERMINALES
%type<sval> line
%type<sval> OPERADOR_ARITMETICO
%type<sval> ARIT
%type<sval> OPERADOR_BOOLEANO
%type<sval> BOOL
%type<sval> BUCLE_WHILE
%type<sval> BUCLE_FOR
%type<sval> BUCLE_CASE
%type<sval> SENTENCIA_IF
%type<sval> COMENTARIO

%start statement

%%
statement:
    | statement line
;

line:  
	NEWLINE {printf("New Line");}
	| ARIT NEWLINE { printf("%s\n", $1); }
	| BOOL NEWLINE {printf("%s\n", $1);} 
    | BUCLE_WHILE NEWLINE {printf("%s\n", $1);}
	| BUCLE_FOR NEWLINE {printf("%s\n", $1);}
	| BUCLE_CASE NEWLINE {printf("%s\n", $1);}
	| SENTENCIA_IF NEWLINE {printf("%s\n", $1);}
	| COMENTARIO NEWLINE {printf("%s\n", $1);}
;

OPERADOR_ARITMETICO: SUMA 	{$$ = "SUMA";}
    | RESTA 				{$$ = "RESTA";}
    | MULT 					{$$ = "MULT";}
    | DIV 					{$$ = "DIV";}
;

ARIT: ARIT OPERADOR_ARITMETICO ARIT 			{$$ = "OPERACION ARITMETICA";}
	| ABRIR_PARENTESIS ARIT CERRAR_PARENTESIS 	{$$ = "PARENTESIS ARIT PARENTESIS";}
	| FLOAT 									{$$ = "FLOAT";}
	| ENTERO 									{$$ = "ENTERO";}
;

OPERADOR_BOOLEANO: IGUAL  	{$$ = "IGUAL";}
    | DESIGUAL   			{$$ = "DESIGUAL";}
    | MENOR  				{$$ = "MENOR";}
    | MAYOR  				{$$ = "MAYOR";}
    | MENOR_IGUAL  			{$$ = "MENOR IGUAL";}
    | MAYOR_IGUAL 			{$$ = "MAYOR IGUAL";}
;

BOOL: ENTERO OPERADOR_BOOLEANO ENTERO 			{$$ = "ENTERO OP BOOL ENTERO";}
	| ENTERO OPERADOR_BOOLEANO FLOAT 			{$$ = "ENTERO OP BOOL FLOAT";}
	| FLOAT OPERADOR_BOOLEANO ENTERO 			{$$ = "FLOAT OP BOOL ENTERO";}
	| FLOAT OPERADOR_BOOLEANO FLOAT 			{$$ = "FLOAT OP BOOL FLOAT";}
	| ABRIR_PARENTESIS BOOL CERRAR_PARENTESIS 	{$$ = "PARENTESIS BOOL PARENTESIS";}
;

BUCLE_WHILE: WHILE BOOL LOOP  	{$$ = "WHILE BOOL LOOP";}
	| END LOOP SEMICOLON  		{$$ = "END LOOP SEMICOLON";}
;

BUCLE_FOR: FOR BOOL LOOP  	{$$ = "FOR BOOL LOOP";}
	| END LOOP SEMICOLON  	{$$ = "END LOOP SEMICOLON";}
;

BUCLE_CASE: CASE BOOL IS	{$$ = "CASE BOOL IS";}
	| WHEN ENTERO FLECHA	{$$ = "WHEN ENTERO FLECHA";}
	| WHEN FLOAT FLECHA	{$$ = "WHEN FLOAT FLECHA";}
	//| WHEN STRING FLECHA	{$$ = "WHEN STRING FLECHA";}
	| WHEN OTHERS FLECHA	{$$ = "WHEN OTHERS FLECHA";}
	| END CASE SEMICOLON	{$$ = "END CASE SEMICOLON";}
;

SENTENCIA_IF: IF BOOL THEN	{$$ = "IF BOOL THEN";}
	| ELSE  				{$$ = "ELSE";}
    | ELSEIF BOOL THEN  	{$$ = "ELSEIF BOOL THEN";}
	| END IF SEMICOLON 		{$$ = "END IF SEMICOLON";}
;

COMENTARIO: COMMENT		{$$ = "COMENTARIO";}
;

%%

int main()
{ return yyparse();
}


void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}