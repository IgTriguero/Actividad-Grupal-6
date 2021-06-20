%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mips.c"
#include "funcionesBison.c"

extern int yylex();
extern int yyparse();
extern int yylineno;
extern FILE *yyin;
extern FILE *yyout;


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

		char* error;
		int boo;

	}st;
}
//TERMINALES

%token<eval> ENTERO
%token<fval> FLOAT
%token<sval> STR
%token<sval> VAR_NAME
%token TRUE FALSE 
%token SUMA RESTA MULT DIV
%token MENOR MAYOR MENOR_IGUAL MAYOR_IGUAL DESIGUAL IGUAL AND OR

%token PROCEDURE
%token COLON EQUAL SEMICOLON COMMA DOTDOT //simbolos
%token ABRIR_LLAVE CERRAR_LLAVE ABRIR_PARENTESIS CERRAR_PARENTESIS //llaves y parentesis
%token WHILE FOR CASE LOOP //bucle
%token IF THEN ELSE ELSEIF END WHEN IS //ifs
%token RANGE OF TYPE //arrays

%token COMMENT QUIT

%token DECLINTEGER DECLFLOAT DECLBOOLEAN DECLARRAY DECLSTRING //declaraciones

%left PLUS MINUS
%left MULTIPLY DIVIDE


//NO TERMINALES
%type<st> PROCLINE //
%type<st> AUXCONTENT // Recursivo para CONTENT 
%type<st> CONTENT // Todo lo que puede haber dentro de una funcion
%type<st> ALLOPERS // 
%type<st> TYPEDECLARATION //
%type<st> DECL //
%type<st> AUXCOMPLETO
%type<st> AUXINT // COMMA NUMERO RECURSIVO PARA ARRAY
%type<st> OP_ARIT
%type<st> OPERANDO
%type<st> ARIT
%type<st> OP_BOOLEANO // operador booleano
%type<st> ALLBOOL
%type<st> BOOL // operaciones booleanas
%type<st> BOOLEAN_MIX // mix de operaciones booleanas con AND y OR
%type<st> BUCLE
%type<st> SENTENCIA_IF
%type<st> NOMBRE_VARIABLE // nombre de la variable como no terminal
%type<st> STRING //
%type<sval> COMENTARIO //

%start PROCLINE

%%

PROCLINE: 
		PROCEDURE NOMBRE_VARIABLE IS AUXCONTENT END NOMBRE_VARIABLE SEMICOLON {
			if(strcmp($2.s, $6.s) == 0){
				printf("Contenido: Procedure Empieza y termina igual\t Linea: %d\n", yylineno);
			} else {
				yyerrorLine("Procedure empieza y termina diferente", yylineno);
			}
		}
;

AUXCONTENT: 
	AUXCONTENT CONTENT {}
	| {}
;


CONTENT:  
    BUCLE {printf("Contenido: %s\t Linea: %d", $1.s, yylineno); if(!$1.a){ ;} else {evalAST(*$1.a, &size);};}
	| SENTENCIA_IF {printf("Contenido: %s\t Linea: %d", $1.s, yylineno); if(!$1.a){ ;} else {evalAST(*$1.a, &size);};}
	| COMENTARIO {printf("Contenido: %s\t Linea: %d", $1, yylineno); }
	| DECL {printf("Contenido: %s\t Linea: %d", $1.s, yylineno); if(!$1.a){ ;} else {evalAST(*$1.a, &size);};}
;

ALLOPERS: 
	NOMBRE_VARIABLE {
		if(!searchVar(tabla, size, $1.s)) { 
			if(strcmp(getVarType(tabla, size, $1.s), "integer")==0) {
				$$.i = getIntFromTable(tabla, size, $1.s);
				$$.type = "integer";
				$$.a = createASTAsignacion($1.a);
				$$.error = "empty";
			} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0) {
				$$.f = getFloatFromTable(tabla, size, $1.s);
				$$.type = "float";
				$$.a = createASTAsignacion($1.a);
				$$.error = "empty";
			} else {
				$$.error = "Variable de tipo incorrecto";
			}
			
		} else {yyerrorLine("Variable not declared", yylineno);}
	
	}
	| NOMBRE_VARIABLE OP_ARIT NOMBRE_VARIABLE {
		if(!searchVar(tabla, size, $1.s) && !searchVar(tabla, size, $3.s)) { 
			if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp(getVarType(tabla, size, $3.s), "integer")==0) {

				$$.i = operacionEnteros($2.operador, getIntFromTable(tabla, size, $1.s), getIntFromTable(tabla, size, $3.s));
				$$.type = "integer";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp(getVarType(tabla, size, $3.s), "integer")==0) {

				$$.f = operacionFloats($2.operador, getFloatFromTable(tabla, size, $1.s), (float)getIntFromTable(tabla, size, $3.s));
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp(getVarType(tabla, size, $3.s), "float")==0) {
				
				$$.f = operacionFloats($2.operador, (float)getIntFromTable(tabla, size, $1.s), getFloatFromTable(tabla, size, $3.s));
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp(getVarType(tabla, size, $3.s), "float")==0 && strcmp(getVarType(tabla, size, $3.s), "float")==0) {
				
				$$.f = operacionFloats($2.operador, getFloatFromTable(tabla, size, $1.s), getFloatFromTable(tabla, size, $3.s));
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else {
				$$.error = "Variable de tipo incorrecto";
			}
			
		} else {yyerrorLine("Variable not declared", yylineno);}
	}
	| NOMBRE_VARIABLE OP_ARIT ARIT {
		if(!searchVar(tabla, size, $1.s)) { 
			if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp($3.type, "integer")==0) {

				$$.i = operacionEnteros($2.operador, getIntFromTable(tabla, size, $1.s), $3.i);
				$$.type = "integer";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp($3.type, "integer")==0) {

				$$.f = operacionFloats($2.operador, getFloatFromTable(tabla, size, $1.s), (float)$3.i);
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp($3.type, "float")==0) {
				
				$$.f = operacionFloats($2.operador, (float)getIntFromTable(tabla, size, $1.s), $3.f);
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp(getVarType(tabla, size, $3.s), "float")==0 && strcmp($3.type, "float")==0) {
				
				$$.f = operacionFloats($2.operador, getFloatFromTable(tabla, size, $1.s), $3.f);
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else {
				$$.error = "Variable de tipo incorrecto";
			}
			
		} else {yyerrorLine("Variable not declared", yylineno);}
	}
	| ARIT OP_ARIT NOMBRE_VARIABLE {
		if(!searchVar(tabla, size, $3.s)) { 

			if(strcmp($1.type, "integer")==0 && strcmp(getVarType(tabla, size, $3.s), "integer")==0) {

				$$.i = operacionEnteros($2.operador, $1.i, getIntFromTable(tabla, size, $3.s));
				$$.type = "integer";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp($1.type, "float")==0 && strcmp(getVarType(tabla, size, $3.s), "integer")==0) {

				$$.f = operacionFloats($2.operador, $1.f, (float)getIntFromTable(tabla, size, $3.s));
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp($1.type, "integer")==0 && strcmp(getVarType(tabla, size, $3.s), "float")==0) {
				
				$$.f = operacionFloats($2.operador, (float)$1.i, getFloatFromTable(tabla, size, $3.s));
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else if(strcmp($1.type, "float")==0 && strcmp(getVarType(tabla, size, $3.s), "float")==0) {
				
				$$.f = operacionFloats($2.operador, $1.f, getFloatFromTable(tabla, size, $3.s));
				$$.type = "float";
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));
				$$.error = "empty";

			} else {
				$$.error = "Variable de tipo incorrecto";
			}
			
		} else {yyerrorLine("Variable not declared", yylineno);}
	}
	| ARIT {
		if(strcmp($1.type, "integer")==0) {
			$$.i = $1.i;
			$$.type = "integer";
			$$.a = createASTAsignacion($1.a);
			$$.error = "empty";
		} else if(strcmp($1.type, "float")==0) {
			$$.f = $1.f;
			$$.type = "float";
			$$.a = createASTAsignacion($1.a);
			$$.error = "empty";
		} else {
			$$.error = "Variable de tipo incorrecto";
		}
			
	}
;

TYPEDECLARATION: 
	DECLINTEGER {
		$$.type = "integer";
	}
	| DECLFLOAT {
		$$.type = "float";
	}
;

DECL: 
	NOMBRE_VARIABLE COLON TYPEDECLARATION COLON EQUAL ALLOPERS SEMICOLON {
		$$.s = "Declaracion de variable Integer o Float";
		if(strcmp($6.error, "empty")==0){
			$$.error = $6.error;
			if(strcmp($3.type, "integer")==0 && strcmp($6.type, "integer")==0){
				insertarElemento(tabla, &size, $6.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true );
				mipsVar_insert_mips_variable_declaration($3.type, $1.s, $6.i, NULL, -500, false);
				$$.a = $6.a;
			} else if(strcmp($3.type, "float")==0 && strcmp($6.type, "float")==0){
				insertarElemento(tabla, &size, 0, "", $6.f, $1.s, false, &elementosOcupados, "float", true );
				mipsVar_insert_mips_variable_declaration($3.type, $1.s, -500, NULL, $6.f, false);
				$$.a = $6.a;
			} else if(strcmp($3.type, "float")==0 && strcmp($6.type, "integer")==0){
				insertarElemento(tabla, &size, 0, "", (float)$6.i, $1.s, false, &elementosOcupados, "float", true );
				mipsVar_insert_mips_variable_declaration($3.type, $1.s, -500, NULL, $6.f, false);
				$$.a = $6.a;
			} else {
				$$.error = "Error diferente tipo de variable (int, float)";
			}

		} else {
			$$.error = $6.error;
		}
		
	}

	| NOMBRE_VARIABLE COLON TYPEDECLARATION SEMICOLON {
		$$.s = "Declaracion de variable Integer o Float vacia";
		if(strcmp($3.type, "integer")==0){
			if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "integer", false );
			} else {
				$$.error = "Variable already declared";
			}
		} else if(strcmp($3.type, "float")==0){ 
			if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "float", false );
			} else {
				$$.error = "Variable already declared";
			}	
		}
	}


	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL NOMBRE_VARIABLE SEMICOLON {
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s, "boolean")) {
				$$.error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, $1.s, getBooleanFromTable(tabla, size, $6.s), &elementosOcupados, "boolean", true );
				$$.a = createASTAsignacion($6.a);
			} else {$$.error = "Variable declared or wrong type";}
			$$.s = "Declaracion de variable Boolean a operacion booleana";
		}
	| NOMBRE_VARIABLE COLON DECLBOOLEAN COLON EQUAL ALLBOOL SEMICOLON {
			if(strcmp($6.error,"empty") == 0 ){
				if(searchVar(tabla, size, $1.s)) {
					$$.error = "empty";
					insertarElemento(tabla, &size, 0, "", 0.0, $1.s, $6.boo ? true : false, &elementosOcupados, "boolean", true );
					mipsVar_insert_mips_variable_declaration("boolean", $1.s, -500, NULL, -500, $6.boo == 1);
					$$.a = createASTAsignacion($6.a);
				} else {$$.error = "Variable declared or wrong type";}
			} else {
				$$.error = $6.error;
			}
			
			$$.s = "Declaracion de variable Boolean a operacion booleana";
		}

	| NOMBRE_VARIABLE COLON EQUAL  AUXCOMPLETO  SEMICOLON	{
		$$.s = "asignación de variable a cualquier cosa";
		if(strcmp($4.error,"empty") == 0 ) {
			$$.error = $4.error;
			if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp($4.type, "integer")==0) {
				
				insertarElemento(tabla, &size, $4.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true );
				mipsIns_asign_val_to_var($1.s, "integer", $4.i, 0.0, NULL, false);
				$$.a = createASTAsignacion($4.a);

			} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp($4.type, "integer")==0) {

				insertarElemento(tabla, &size, 0, "", (float)$4.i, $1.s, false, &elementosOcupados, "float", true );
				mipsIns_asign_val_to_var($1.s, "float", 0, (float)$4.i, NULL, false);
				$$.a = createASTAsignacion($4.a);

			} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp($4.type, "float")==0) {

				insertarElemento(tabla, &size, 0, "", $4.f, $1.s, false, &elementosOcupados, "float", true );
				mipsIns_asign_val_to_var($1.s, "float", 0, $4.f, NULL, false);
				$$.a = createASTAsignacion($4.a);

			} else if(strcmp(getVarType(tabla, size, $1.s), "boolean")==0 && strcmp($4.type, "boolean")==0) {

				insertarElemento(tabla, &size, 0, "", 0.0, $1.s, $4.boo ? true : false, &elementosOcupados, "boolean", true );
				mipsIns_asign_val_to_var($1.s, "boolean", 0, 0.0, NULL, $4.boo == 1);
				$$.a = createASTAsignacion($4.a);

			} else if(strcmp(getVarType(tabla, size, $1.s), "string")==0 && strcmp($4.type, "string")==0) {

				insertarElemento(tabla, &size, 0, $4.s, 0.0, $1.s, false, &elementosOcupados, "string", true );
				mipsIns_asign_val_to_var($1.s, "boolean", 0, 0.0, $4.s, false);
				$$.a = createASTAsignacion($4.a);

			} else if(strcmp($4.type, "var")==0) {

				if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp($4.type, "integer")==0) {

					insertarElemento(tabla, &size, $4.i, "", 0.0, $1.s, false, &elementosOcupados, "integer", true );
					mipsIns_asign_val_to_var($1.s, "integer", $4.i, 0.0, NULL, false);
					$$.a = createASTAsignacion($4.a);

				} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp($4.type, "integer")==0) {

					insertarElemento(tabla, &size, 0, "", (float)$4.i, $1.s, false, &elementosOcupados, "float", true );
					mipsIns_asign_val_to_var($1.s, "float", 0, (float)$4.i, NULL, false);
					$$.a = createASTAsignacion($4.a);

				} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp($4.type, "float")==0) {

					insertarElemento(tabla, &size, 0, "", $4.f, $1.s, false, &elementosOcupados, "float", true );
					mipsIns_asign_val_to_var($1.s, "float", 0, $4.f, NULL, false);
					$$.a = createASTAsignacion($4.a);

				} else if(strcmp(getVarType(tabla, size, $1.s), "boolean")==0 && strcmp($4.type, "boolean")==0) {

					insertarElemento(tabla, &size, 0, "", 0.0, $1.s, $4.boo ? true : false, &elementosOcupados, "boolean", true );
					mipsIns_asign_val_to_var($1.s, "boolean", 0, 0.0, NULL, $4.boo == 1);
					$$.a = createASTAsignacion($4.a);

				} else if(strcmp(getVarType(tabla, size, $1.s), "string")==0 && strcmp($4.type, "string")==0) {

					insertarElemento(tabla, &size, 0, $4.s, 0.0, $1.s, false, &elementosOcupados, "string", true );
					mipsIns_asign_val_to_var($1.s, "boolean", 0, 0.0, $4.s, false);
					$$.a = createASTAsignacion($4.a);

				} else {
					$$.error = "Invalid assignation type";
				}
			} else {
				$$.error = "Invalid assignation type";
			}
		} else {
			$$.error = $4.error;
		}
	}


	| NOMBRE_VARIABLE COLON DECLBOOLEAN SEMICOLON {
			$$.s = "Declaracion de variable Boolean vacia";
			if (searchVar(tabla, size, $1.s)) {
				$$.error = "empty";
				insertarElemento(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "boolean", false );
			} else {
				$$.error = "Variable declared";
			}
		}
	| NOMBRE_VARIABLE COLON DECLSTRING COLON EQUAL NOMBRE_VARIABLE SEMICOLON {
			$$.s = "Declaracion de variable String igual a variable String"; 
			if(searchVar(tabla, size, $1.s) && checkVarAndType(tabla, size, $6.s,"string")) {
				$$.error = "empty";
				insertarElemento(tabla, &size, 0, getStringFromTable(tabla, size, $6.s), 0.0, $1.s, false, &elementosOcupados, "string", true );
				$$.a = createASTAsignacion($6.a);
			} else {
				$$.error = "Variable declared or wrong type";
			}
		}
	| NOMBRE_VARIABLE COLON DECLSTRING COLON EQUAL STRING SEMICOLON {
			$$.s = "Declaracion con string";
			if(searchVar(tabla, size, $1.s)) {
				$$.error = "empty"; 
				insertarElemento(tabla, &size, 0, $6.s, 0.0, $1.s, false, &elementosOcupados, "string", true );
				mipsVar_insert_mips_variable_declaration("string", $1.s, -500, $6.s, -500, false);
				$$.a = createASTAsignacion($6.a);
			} else {
				$$.error = "Variable declared or wrong type";
			}
		}
	| NOMBRE_VARIABLE COLON DECLSTRING SEMICOLON {
			$$.s = "Declaracion de variable String vacia";
			if (searchVar(tabla, size, $1.s)) {
			$$.error = "empty";insertarElemento(tabla, &size, 0, "", 0.0, $1.s, false, &elementosOcupados, "string", false );} else {$$.error = "Variable declared";}
		}

	| TYPE NOMBRE_VARIABLE IS RANGE ENTERO DOTDOT ENTERO SEMICOLON {$$.s = "Tipo Variable en rango entero";}
	| TYPE NOMBRE_VARIABLE IS DECLARRAY ABRIR_PARENTESIS ENTERO DOTDOT ENTERO CERRAR_PARENTESIS OF NOMBRE_VARIABLE SEMICOLON {$$.s = "Tipo Variable declaraccion array entero de Variable";}
	| NOMBRE_VARIABLE COLON NOMBRE_VARIABLE COLON EQUAL ABRIR_PARENTESIS ENTERO AUXINT CERRAR_PARENTESIS SEMICOLON {$$.s = "Declaracion de array";}

;

AUXCOMPLETO: 
	ALLBOOL {$$ = $1;}
	| ALLOPERS {$$ = $1; }
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

OPERANDO:
	ENTERO {$$.i = $1; $$.type = "integer"; $$.error="empty"; $$.a = createNum($1);}
	|	FLOAT {$$.f = $1; $$.type = "float"; $$.error="empty"; $$.a = createNum($1);}
;

ARIT:
	OPERANDO {
		$$.type = $1.type;
		$$.a = $1.a;
		if (strcmp("integer", $1.type) == 0) {$$.i = $1.i;} else {$$.f = $1.f;}
	}
	| ARIT OP_ARIT ARIT {
		if(strcmp($1.type, "float") == 0 && strcmp($3.type, "float") == 0) {
			$$.f = operacionFloats($2.operador, $1.f, $3.f);
			$$.type = "float";
		} else if (strcmp($3.type, "float") == 0) {
			$$.f = operacionFloats($2.operador, (float)$1.i, $3.f);
			$$.type = "float";
		} else if (strcmp($1.type, "float") == 0) {
			$$.f = operacionFloats($2.operador, $1.f, (float)$3.i);
			$$.type = "float";
		} else {
			$$.i = operacionEnteros($2.operador, $1.i, $3.i);
			$$.type = "integer";
		}
		$$.a = createAST($2.operador, $1.a, $3.a);
	}
	| ABRIR_PARENTESIS ARIT CERRAR_PARENTESIS {if(strcmp($2.type, "float") == 0) {$$.f = $2.f;} else {$$.i = $2.i;}}
;

OP_BOOLEANO: IGUAL  	{$$.s = "IGUAL";$$.operador = "==";}
    | DESIGUAL   			{$$.s = "DESIGUAL";$$.operador = "!=";}
    | MENOR  				{$$.s = "MENOR";$$.operador = "<";}
    | MAYOR  				{$$.s = "MAYOR";$$.operador = ">";}
    | MENOR_IGUAL  			{$$.s = "MENOR IGUAL";$$.operador = "<=";}
    | MAYOR_IGUAL 			{$$.s = "MAYOR IGUAL";$$.operador = ">=";}
;

ALLBOOL: 
	BOOLEAN_MIX {$$ = $1; $$.type = "boolean";}
	| BOOL {$$ = $1; $$.type = "boolean";}
;

BOOL:
	ARIT OP_BOOLEANO ARIT 			{
		$$.s = "INT OP BOOL INT";
		$$.error = "empty";
		if(strcmp($1.type, "integer")==0 && strcmp($3.type, "integer")==0){	
			$$.boo = compare($2.operador, (float)$1.i, (float)$3.i);
			$$.a = createAST($2.operador, $1.a, $3.a); 
		} else if(strcmp($3.type, "integer")==0){	
			$$.boo = compare($2.operador, $1.f, (float)$3.i);
			$$.a = createAST($2.operador, $1.a, $3.a); 
		} else if(strcmp($1.type, "integer")==0){	
			$$.boo = compare($2.operador, (float)$1.i, $3.f);
			$$.a = createAST($2.operador, $1.a, $3.a); 
		} else {	
			$$.boo = compare($2.operador, $1.f, $3.f);
			$$.a = createAST($2.operador, $1.a, $3.a); 
		}  
	}

	| NOMBRE_VARIABLE OP_BOOLEANO ARIT 			{

		$$.s = "VAR OP BOOL INT";
		if(!searchVar(tabla, size, $1.s)) { 
			$$.error = "empty";
			if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp($3.type, "integer")==0) {

				$$.boo = compare($2.operador, (float)getIntFromTable(tabla, size, $1.s), (float)$3.i);
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

			} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp($3.type, "integer")==0) {

				$$.boo = compare($2.operador, getFloatFromTable(tabla, size, $1.s), (float)$3.i);
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

			} else if(strcmp(getVarType(tabla, size, $1.s), "integer")==0 && strcmp($3.type, "float")==0) {
				
				$$.boo = compare($2.operador, (float)getIntFromTable(tabla, size, $1.s), $3.f);
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

			} else if(strcmp(getVarType(tabla, size, $1.s), "float")==0 && strcmp($3.type, "float")==0) {
				
				$$.boo = compare($2.operador, getFloatFromTable(tabla, size, $1.s), $3.f);
				$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

			} else {

				$$.error = "Variable de tipo incorrecto";
			}
			
		} else {yyerrorLine("Variable not declared", yylineno);}

		}

	| ARIT OP_BOOLEANO NOMBRE_VARIABLE 			{
			$$.s = "INT OP BOOL VAR";
			if(!searchVar(tabla, size, $3.s)) { 
				$$.error = "empty";
				if(strcmp($1.type, "integer")==0 && strcmp(getVarType(tabla, size, $3.s), "integer")==0) {

					$$.boo = compare($2.operador, (float)$1.i, (float)getIntFromTable(tabla, size, $3.s));
					$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

				} else if(strcmp($1.type, "float")==0 && strcmp(getVarType(tabla, size, $3.s), "integer")==0) {

					$$.boo = compare($2.operador, $1.f, (float)getIntFromTable(tabla, size, $3.s));
					$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

				} else if(strcmp($1.type, "integer")==0 && strcmp(getVarType(tabla, size, $3.s), "float")==0) {
					
					$$.boo = compare($2.operador, (float)$1.i, getFloatFromTable(tabla, size, $3.s));
					$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

				} else if(strcmp($1.type, "float")==0 && strcmp(getVarType(tabla, size, $3.s), "float")==0) {

					$$.boo = compare($2.operador, $1.f, getFloatFromTable(tabla, size, $3.s));
					$$.a = createASTAsignacion(createAST($2.operador, $1.a, $3.a));

				} else {
					$$.error = "Variable de tipo incorrecto";
				}
			
			} else {
				yyerrorLine("Variable not declared", yylineno);
			}
		}

	| NOMBRE_VARIABLE OP_BOOLEANO NOMBRE_VARIABLE 			{
			$$.s = "VAR OP BOOL VAR";
			if(!searchVar(tabla, size, $1.s) && !searchVar(tabla, size, $3.s)) {
				$$.error = "empty";
				if((strcmp("integer", getVarType(tabla, size, $1.s)) == 0) && (strcmp("integer", getVarType(tabla, size, $3.s)) == 0)){
					$$.boo = compare($2.operador,	(float)getIntFromTable(tabla, size, $1.s), (float)getIntFromTable(tabla, size, $3.s));
					$$.a=createAST($2.operador, $1.a, $3.a);
				} else if((strcmp("float", getVarType(tabla, size, $1.s))  == 0) && (strcmp("float", getVarType(tabla, size, $3.s))  == 0)){
					$$.boo = compare($2.operador, getFloatFromTable(tabla, size, $1.s), getFloatFromTable(tabla, size, $3.s));
					$$.a=createAST($2.operador, $1.a, $3.a);
				} else if ((strcmp("integer", getVarType(tabla, size, $1.s))  == 0) && (strcmp("float", getVarType(tabla, size, $3.s))  == 0)) {
					$$.boo = compare($2.operador, (float)getIntFromTable(tabla, size, $1.s), getFloatFromTable(tabla, size, $3.s));
					$$.a=createAST($2.operador, $1.a, $3.a);
				} else if ((strcmp("float", getVarType(tabla, size, $1.s))  == 0) && (strcmp("integer", getVarType(tabla, size, $3.s))  == 0)) {
					$$.boo = compare($2.operador, getFloatFromTable(tabla, size, $1.s), (float)getIntFromTable(tabla, size, $3.s));
					$$.a=createAST($2.operador, $1.a, $3.a);
				} else {
					$$.error = "Esta variable tiene un tipo incorrecto";
				}  
				
			} else {$$.error = "Variable declared or wrong type";}
		}
	| ABRIR_PARENTESIS BOOL CERRAR_PARENTESIS 	{$$.s = "PARENTESIS BOOL PARENTESIS"; $$.boo = $2.boo;}
	| NOMBRE_VARIABLE {
		$$.s = "PARENTESIS BOOL PARENTESIS";
		if(!searchVar(tabla, size, $1.s)){
			if(strcmp("boolean", getVarType(tabla, size, $1.s)) == 0){
				$$.boo = getBooleanFromTable(tabla, size, $1.s);
			} else {
				$$.error = "La variable no es un boolean";
			}
		} else {
			$$.error = "variable no declarada";
		}
	}
	| TRUE {$$.boo=1; $$.a = createBOOLVAR("True");}
	| FALSE {$$.boo=0; $$.a = createBOOLVAR("False");}
;

BOOLEAN_MIX: 
	BOOL AND BOOL {
		$$.s="Expresiones booleanas con AND\n";
		$$.error = "empty";
		if($1.boo == $3.boo){
			$$.boo = 1;
		} else {
			$$.boo = 0;
		}
	}
	| BOOL OR BOOL {
		$$.s="Expresiones booleanas con OR\n";
		$$.error = "empty";
		if($1.boo == 1 || $3.boo == 1){
			$$.boo = 1;
		} else {
			$$.boo = 0;
		}
	}
;

BUCLE: WHILE BOOLEAN_MIX LOOP  	{$$.s = "WHILE BOOL LOOP";}
	| FOR BOOLEAN_MIX LOOP  	{$$.s = "FOR BOOL LOOP";}
	| END LOOP SEMICOLON  	{$$.s = "END LOOP SEMICOLON";}
;

SENTENCIA_IF: IF BOOLEAN_MIX THEN	{
		$$.s = "IF BOOL THEN";
		mipsIns_if($2.boo);
	}
	| ELSE  {
		$$.s = "ELSE";
		mipsIns_else();
		}
    | ELSEIF BOOLEAN_MIX THEN  	{$$.s = "ELSEIF BOOL THEN";}
	| END IF SEMICOLON 		{
		$$.s = "END IF SEMICOLON";
		mipsIns_endIf();
		}
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


int main(int argc, char *argv[])
{
	mipsVar_create_data();
	mipsIns_create_text(); 
	mipsVar_initialize_struct();
	mipsVar_initialize_valorStruct();

    iniArrayTabla(tabla, 0, size);
    iniArrayNodos(nodos, 0, size);

	yyin = fopen(argv[1], "rt");
	yyparse();
	printf("\n");
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
	mipsVar_write_declarations();
	
	concatenateTxt(filename_data, filename_text, "mips.txt");

	remove(filename_data);
	remove(filename_text);
    
}
