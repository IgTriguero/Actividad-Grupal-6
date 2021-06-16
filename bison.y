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
%token<sval> STR
%token<sval> VAR_NAME
%token SUMA RESTA MULT DIV

%token EQUAL FLECHA
%token ABRIR_LLAVE CERRAR_LLAVE ABRIR_PARENTESIS CERRAR_PARENTESIS
%token WHILE FOR CASE LOOP 
%token IF THEN ELSE ELSEIF END WHEN IS OTHERS DOTDOT
%token PROCEDURE RANGE COMMA OF TYPE

%token COMMENT NEWLINE SEMICOLON COLON QUIT
%token TRUE FALSE 

%token MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL DESIGUAL IGUAL
%token DECLINTEGER DECLFLOAT DECLBOOLEAN DECLARRAY DECLSTRING

%left PLUS MINUS
%left MULTIPLY DIVIDE


//NO TERMINALES
%type<st> CONTENT
%type<st> ARIT
%type<st> ARIT2
%type<st> OP_BOOLEANO
%type<st> OP_ARIT
%type<st> BOOL
%type<st> BUCLE
%type<st> BUCLE_CASE
%type<st> SENTENCIA_IF
%type<sval> COMENTARIO
%type<st> PROCLINE
%type<st> DECL
%type<st> NOMBRE_VARIABLE
%type<st> STRING

%start PROCLINE

%%

PROCLINE: 
	PROCEDURE NOMBRE_VARIABLE IS AUXCONTENT END NOMBRE_VARIABLE SEMICOLON {printf(".");}
;

AUXCONTENT: AUXCONTENT CONTENT | ;
//-1 porque newline suma una linea
CONTENT:  
    BUCLE {printf("Contenido: %s\t Linea: %d\n", $1.s, yylineno); if(!$1.a){ ;} else {evalAST(*$1.a, &size);};}
	| BUCLE_CASE {printf("Contenido: %s\t Linea: %d\n", $1.s, yylineno); if(!$1.a){ ;} else {evalAST(*$1.a, &size);};}
	| SENTENCIA_IF {printf("Contenido: %s\t Linea: %d\n", $1.s, yylineno); if(!$1.a){ ;} else {evalAST(*$1.a, &size);};}
	| COMENTARIO {printf("Contenido: %s\t Linea: %d\n", $1, yylineno); }
	| DECL {printf("Contenido: %s\t Linea: %d\n", $1.s, yylineno); if(!$1.a){ ;} else {evalAST(*$1.a, &size);};}
;

DECL: NOMBRE_VARIABLE COLON DECLINTEGER COLON EQUAL NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Integer asignacion variable"} 
	| NOMBRE_VARIABLE COLON DECLINTEGER COLON EQUAL NOMBRE_VARIABLE OP_ARIT NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Integer igual a variable operador variable"}
	| NOMBRE_VARIABLE COLON DECLINTEGER COLON EQUAL NOMBRE_VARIABLE OP_ARIT ARIT SEMICOLON {$$.s = "Declaracion de variable Integer igual a variable operador operacion aritmetica"}
	| NOMBRE_VARIABLE COLON DECLINTEGER COLON EQUAL ARIT OP_ARIT NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Integer igual a operacion aritmetica operador con variable"}
	| NOMBRE_VARIABLE COLON DECLINTEGER COLON EQUAL ARIT SEMICOLON 
	{$$.s = "Declaracion de variable Integer igual a operacion aritmetica"; 
	insertarElemento(tabla, &size, $6.i, "", 0.0, $1.s, &elementosOcupados, "integer" );
	 $$.a = createASTAsignacion($6.a);}

	| NOMBRE_VARIABLE COLON DECLINTEGER SEMICOLON {$$.s = "Declaracion de variable Integer"}

	| NOMBRE_VARIABLE COLON DECLFLOAT COLON EQUAL NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Float asignacion variable"}
	| NOMBRE_VARIABLE COLON DECLFLOAT COLON EQUAL NOMBRE_VARIABLE OP_ARIT NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Float igual a variable operador variable"}
	| NOMBRE_VARIABLE COLON DECLFLOAT COLON EQUAL NOMBRE_VARIABLE OP_ARIT ARIT2 SEMICOLON {$$.s = "Declaracion de variable Float igual a variable operador operacion aritmetica"}
	| NOMBRE_VARIABLE COLON DECLFLOAT COLON EQUAL ARIT2 OP_ARIT NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Float igual a operacion aritmetica operador con variable"} //ignore ARIT OP VAR
	| NOMBRE_VARIABLE COLON DECLFLOAT COLON EQUAL ARIT2 SEMICOLON 
	{$$.s = "Declaracion de variable Float igual a operacion aritmetica";
	insertarElemento(tabla, &size, 0, "", $6.f, $1.s, &elementosOcupados, "float" );
	$$.a = createASTAsignacion($6.a);}
	| NOMBRE_VARIABLE COLON DECLFLOAT SEMICOLON {$$.s = "Declaracion de variable Float"}

	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Boolean igual a variable"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL NOMBRE_VARIABLE OP_BOOLEANO NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Boolean igual"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL NOMBRE_VARIABLE OP_BOOLEANO ENTERO SEMICOLON {$$.s = "Declaracion de variable Boolean igual a variable operador booleano con entero"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL NOMBRE_VARIABLE OP_BOOLEANO FLOAT SEMICOLON {$$.s = "Declaracion de variable Boolean igual a variable operador booleano con float"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL ENTERO OP_BOOLEANO NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Boolean igual a entero operando con variable"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL FLOAT OP_BOOLEANO NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion de variable Boolean igual a float operando con variable"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL BOOL SEMICOLON {$$.s = "Declaracion de variable Boolean igual a operacion booleana"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL BOOLEAN SEMICOLON {$$.s = "Declaracion de variable Boolean igual a resultado booleano"}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN SEMICOLON {$$.s = "Declaracion de variable Boolean igual a resultado booleano"}

	| NOMBRE_VARIABLE COLON DECLSTRING COLON EQUAL NOMBRE_VARIABLE SEMICOLON {$$.s = "Declaracion con string1";}
	| NOMBRE_VARIABLE COLON DECLSTRING COLON EQUAL STRING SEMICOLON 
	{$$.s = "Declaracion con string";
	insertarElemento(tabla, &size, 0, $6.s, 0.0, $1.s, &elementosOcupados, "string" );
	$$.a = createASTAsignacion($6.a);
	}
	| NOMBRE_VARIABLE COLON DECLSTRING SEMICOLON {$$.s = "Declaracion de variable String";}

	| NOMBRE_VARIABLE COLON EQUAL NOMBRE_VARIABLE SEMICOLON {$$.s = "Variable igual a Variable"} 
	| NOMBRE_VARIABLE COLON EQUAL NOMBRE_VARIABLE OP_ARIT NOMBRE_VARIABLE SEMICOLON {$$.s = "Variable igual a Variable operacion con Variable"}
	| NOMBRE_VARIABLE COLON EQUAL NOMBRE_VARIABLE OP_ARIT ARIT SEMICOLON {$$.s = "Variable igual a Variable operacion con operacion aritmetica";}
	| NOMBRE_VARIABLE COLON EQUAL NOMBRE_VARIABLE OP_ARIT ARIT2 SEMICOLON {$$.s = "Variable igual a Variable operacion con operacion aritmetica float"}
	| NOMBRE_VARIABLE COLON EQUAL ARIT OP_ARIT NOMBRE_VARIABLE SEMICOLON {$$.s = "Variable igual a operacion aritmetica operacion con Variable"}
	| NOMBRE_VARIABLE COLON EQUAL ARIT2 OP_ARIT NOMBRE_VARIABLE SEMICOLON {$$.s = "Variable igual a operacion aritmetica float operacion con Variable"}
	| NOMBRE_VARIABLE COLON EQUAL ARIT SEMICOLON {$$.s = "Variable igual a operacion aritmetica"}
	| NOMBRE_VARIABLE COLON EQUAL ARIT2 SEMICOLON {$$.s = "Variable igual a operacion aritmetica float"}
	| NOMBRE_VARIABLE COLON EQUAL NOMBRE_VARIABLE OP_BOOLEANO NOMBRE_VARIABLE SEMICOLON {$$.s = "Variable igual a Variable operador booleano Variable"}
	| NOMBRE_VARIABLE COLON EQUAL NOMBRE_VARIABLE OP_BOOLEANO ENTERO SEMICOLON {$$.s = "Variable igual a Variable operador booleano entero"}
	| NOMBRE_VARIABLE COLON EQUAL NOMBRE_VARIABLE OP_BOOLEANO FLOAT SEMICOLON {$$.s = "Variable igual a Variable operador booleano float"}
	| NOMBRE_VARIABLE COLON EQUAL ENTERO OP_BOOLEANO NOMBRE_VARIABLE SEMICOLON {$$.s = "Variable igual a entero operador booleano Variable"}
	| NOMBRE_VARIABLE COLON EQUAL FLOAT OP_BOOLEANO NOMBRE_VARIABLE SEMICOLON {$$.s = "Variable igual a float operador booleano Variable"}
	| NOMBRE_VARIABLE COLON EQUAL BOOL SEMICOLON {$$.s = "Variable igual a operacion booleana"}
	| NOMBRE_VARIABLE COLON EQUAL BOOLEAN SEMICOLON {$$.s = "Variable igual a condicion booleana"}
	| NOMBRE_VARIABLE COLON EQUAL STRING SEMICOLON {$$.s = "Variable igual a string"}

	| TYPE NOMBRE_VARIABLE IS RANGE ENTERO DOTDOT ENTERO SEMICOLON {$$.s = "Tipo Variable en rango entero"}
	| TYPE NOMBRE_VARIABLE IS DECLARRAY ABRIR_PARENTESIS ENTERO DOTDOT ENTERO CERRAR_PARENTESIS OF NOMBRE_VARIABLE SEMICOLON {$$.s = "Tipo Variable declaraccion array entero de Variable"}
	| NOMBRE_VARIABLE COLON NOMBRE_VARIABLE COLON EQUAL ABRIR_PARENTESIS ENTERO AUXINT CERRAR_PARENTESIS SEMICOLON {}

;
AUXINT: COMMA ENTERO {}
	| {}
;

OP_ARIT:
	SUMA {$$.operador = "+";}
	| RESTA {$$.operador = "-";}
	| MULT {$$.operador = "*";}
	| DIV {$$.operador = "/";}
;

ARIT: 
	ARIT SUMA ARIT 									{$$.i = $1.i + $3.i; $$.a = createAST("+",$1.a,$3.a);}
	| ARIT RESTA ARIT 								{$$.i = $1.i - $3.i; $$.a = createAST("-",$1.a,$3.a);}
	| ARIT MULT ARIT 									{$$.i = $1.i * $3.i; $$.a = createAST("*",$1.a,$3.a);}
	| ARIT DIV ARIT 									{$$.i = $1.i / $3.i; $$.a = createAST("/",$1.a,$3.a);}
	| ABRIR_PARENTESIS ARIT CERRAR_PARENTESIS 	{$$.i = $2.i;}
	| ENTERO 										{$$.i = $1; $$.a = createNum($1);}
;

ARIT2: 
	ARIT2 SUMA ARIT2 									{$$.f = $1.f + $3.f; $$.a = createAST("+",$1.a,$3.a);}
	| ARIT2 RESTA ARIT2 								{$$.f = $1.f - $3.f; $$.a = createAST("-",$1.a,$3.a);}
	| ARIT2 MULT ARIT2 									{$$.f = $1.f * $3.f; $$.a = createAST("*",$1.a,$3.a);}
	| ARIT2 DIV ARIT2 									{$$.f = $1.f / $3.f; $$.a = createAST("/",$1.a,$3.a);}
	| ABRIR_PARENTESIS ARIT2 CERRAR_PARENTESIS 	{$$.f = $2.f;}
	| FLOAT 									{$$.f = $1; $$.a = createNum($1);}
;

OP_BOOLEANO: IGUAL  	{$$.s = "IGUAL";$$.operador = "+";}
    | DESIGUAL   			{$$.s = "DESIGUAL";$$.operador = "!=";}
    | MENOR  				{$$.s = "MENOR";$$.operador = "<";}
    | MAYOR  				{$$.s = "MAYOR";$$.operador = ">";} //cambiarlo por st.algo 
    | MENOR_IGUAL  			{$$.s = "MENOR IGUAL";$$.operador = "<=";}
    | MAYOR_IGUAL 			{$$.s = "MAYOR IGUAL";$$.operador = ">=";}
;

BOOL: ENTERO OP_BOOLEANO ENTERO 			{$$.s = "ENTERO OP BOOL ENTERO";}
	| ENTERO OP_BOOLEANO FLOAT 			{$$.s = "ENTERO OP BOOL FLOAT";}
	| FLOAT OP_BOOLEANO ENTERO 			{$$.s = "FLOAT OP BOOL ENTERO";}
	| FLOAT OP_BOOLEANO FLOAT 			{$$.s = "FLOAT OP BOOL FLOAT";} //entero fuera
	| NOMBRE_VARIABLE OP_BOOLEANO ENTERO 			{$$.s = "ENTERO OP BOOL ENTERO";}
	| ENTERO OP_BOOLEANO NOMBRE_VARIABLE 			{$$.s = "ENTERO OP BOOL ENTERO";}
	| NOMBRE_VARIABLE OP_BOOLEANO FLOAT 			{$$.s = "FLOAT OP BOOL FLOAT";}
	| FLOAT OP_BOOLEANO NOMBRE_VARIABLE 			{$$.s = "FLOAT OP BOOL FLOAT";}
	| ABRIR_PARENTESIS BOOL CERRAR_PARENTESIS 	{$$.s = "PARENTESIS BOOL PARENTESIS";}
;
BOOLEAN: TRUE | FALSE;

BUCLE: WHILE BOOL LOOP  	{$$.s = "WHILE BOOL LOOP";}
	| FOR BOOL LOOP  	{$$.s = "FOR BOOL LOOP";}
	| END LOOP SEMICOLON  	{$$.s = "END LOOP SEMICOLON";}
;

BUCLE_CASE: CASE BOOL IS	{$$.s = "CASE BOOL IS";}
	| WHEN ENTERO FLECHA	{$$.s = "WHEN ENTERO FLECHA";}
	| WHEN FLOAT FLECHA		{$$.s = "WHEN FLOAT FLECHA";}
	//| WHEN STRING FLECHA	{$$.s = "WHEN STRING FLECHA";}
	| WHEN OTHERS FLECHA	{$$.s = "WHEN OTHERS FLECHA";}
	| END CASE SEMICOLON	{$$.s = "END CASE SEMICOLON";}
;

SENTENCIA_IF: IF BOOL THEN	{$$.s = "IF BOOL THEN";}
	| ELSE  				{$$.s = "ELSE";}
    | ELSEIF BOOL THEN  	{$$.s = "ELSEIF BOOL THEN";}
	| END IF SEMICOLON 		{$$.s = "END IF SEMICOLON";}
;
NOMBRE_VARIABLE:
	VAR_NAME {$$.s = $1; $$.a = createSTR($1);}
;
STRING:
	STR {$$.s = $1; $$.a = createSTR($1);}
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

