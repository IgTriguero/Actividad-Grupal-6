%{

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
// tabla simbolos
void iniArrayTabla(struct symb *tabla, int inicio, int fin);

// nodos
void iniArrayNodos(struct ast *nodos, int inicio, int fin);

// funciones ast
struct ast *newast(char* nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

void eval(struct ast a, int* size);
void printAST(struct ast nodos[], int i, int encontrado, int salida);

%}
%locations

%union {
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
}
//TERMINALES

%token<eval> ENTERO
%token<fval> FLOAT
%token<sval> NOMBRE_VARIABLE
%token<sval> SUMA
%token<sval> RESTA
%token<sval> MULT
%token<sval> DIV

%token EQUAL FLECHA
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
%type<st> ARIT
%type<st> ARIT2
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
//-1 porque newline suma una linea
line:  
	NEWLINE {}
	| ARIT {printf("%d\t%d\n", $1.i, yylineno-1); if(!$1.a){ ;} else {eval(*$1.a, &size);} ;}
	| ARIT2 {printf("%f\t%d\n", $1.f, yylineno-1); }
	| BOOL {printf("%s\t%d\n", $1, yylineno);} 
    | BUCLE_WHILE {printf("%s\t%d\n", $1, yylineno);}
	| BUCLE_FOR {printf("%s\t%d\n", $1, yylineno);}
	| BUCLE_CASE {printf("%s\t%d\n", $1, yylineno);}
	| SENTENCIA_IF {printf("%s\t%d\n", $1, yylineno);}
	| COMENTARIO {printf("%s\t%d\n", $1, yylineno);}
	| {}
;

ARIT: 
	ARIT SUMA ARIT 									{$$.i = $1.i + $3.i; $$.a = newast("+",$1.a,$3.a);}
	| ARIT RESTA ARIT 								{$$.i = $1.i - $3.i; $$.a = newast("-",$1.a,$3.a);}
	| ARIT MULT ARIT 									{$$.i = $1.i * $3.i; $$.a = newast("*",$1.a,$3.a);}
	| ARIT DIV ARIT 									{$$.i = $1.i / $3.i; $$.a = newast("/",$1.a,$3.a);}
	| ABRIR_PARENTESIS ARIT CERRAR_PARENTESIS 	{$$.i = $2.i;}
	| ENTERO 										{$$.i = $1; $$.a = newnum($1);}
;

ARIT2: 
	ARIT2 SUMA ARIT2 									{$$.f = $1.f + $3.f; $$.a = newast("+",$1.a,$3.a);}
	| ARIT2 RESTA ARIT2 								{$$.f = $1.f - $3.f; $$.a = newast("-",$1.a,$3.a);}
	| ARIT2 MULT ARIT2 									{$$.f = $1.f * $3.f; $$.a = newast("*",$1.a,$3.a);}
	| ARIT2 DIV ARIT2 									{$$.f = $1.f / $3.f; $$.a = newast("/",$1.a,$3.a);}
	| ABRIR_PARENTESIS ARIT2 CERRAR_PARENTESIS 	{$$.f = $2.f;}
	| FLOAT 									{$$.f = $1; $$.a = newnum($1);}
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
	| WHEN FLOAT FLECHA		{$$ = "WHEN FLOAT FLECHA";}
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




//FUNCIONES DE AST
struct ast *newast(char* nodetype, struct ast *l, struct ast *r) {
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

struct ast *newnum(double d)
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

void eval(struct ast a, int* size){
	
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
		printAST(nodos,0,0,0);
	}

	
	
}

