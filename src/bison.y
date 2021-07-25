%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>    
#include <string.h>
#include <math.h>
#include "symtab.h"
#include "AST.h"

extern FILE *yyin;
extern FILE *yyout;

int globalError =0;
int globalContadorNum =0;
int globalContadorOper =0;
int globalBoolCond = 0;
char globalSignCond;
char *globalTipo;


//-----NUMEROS-----

add_SymNum ( char *sym_name, int sym_val, char *sym_type ) {  
symrec *s;
   s = getsymNum (sym_name,sym_val);
   if (s == 0){
        s = putsymNum (sym_name,sym_val, sym_type);
        printf( "%s no esta definida, es %d. (tipo=%s)\n", sym_name, sym_val, sym_type );
   }else {
          printf( "%s ya esta definida, es %d. (tipo=%s)\n", sym_name, sym_val, sym_type );
   }
}

Update_SymNum( char *sym_name, int sym_val ){ 
symrec *act;

  if ( getsymNum( sym_name, sym_val ) == 0 ) {
     printf( "%s no esta en la lista, es %d\n", sym_name, sym_val );
  }else{
     act = updatesymNum( sym_name, sym_val); 
     printf( "%s se actualiza a: %d\n", act->name, act->num );
  }
}

//-----TEXTOS-----

add_SymText ( char *sym_name, char *sym_text, char *sym_type ) {  
symrec *s;
   s = getsymText (sym_name,sym_text);
   if (s == 0){
        s = putsymText (sym_name,sym_text, sym_type);
        printf( "%s no esta definida, es %s. (tipo=%s) \n", sym_name, sym_text, sym_type );
   }else {
          printf( "%s ya esta definida, es %s. (tipo=%s) \n", sym_name, sym_text, sym_type );
   }
}

Update_SymText( char *sym_name, char *sym_text  ){ 
symrec *act;

  if ( getsymText( sym_name, sym_text ) == 0 ) {
     printf( "%s no esta en la lista, es %d\n", sym_name, sym_text );
  }else{
     act = updatesymText( sym_name, sym_text); 
     printf( "%s se actualiza a: %s\n", act->name, act->text );
  }
}




%}

%token MAS MENOS POR DIV PAR_I PAR_D IF THEN MAYOR_Q MENOR_Q ELSE  PROCEDURE IS END BEGINN DOSPUNTOS INTEGER FLOAT STRING BOOLEAN IDENTIFICADORSIMB PIZQ_COM DOSPUNTOS_IGUAL PDECH_COM PUTLINE ENDIF TRUE FALSE COMENTARIO WHILE LOOP ENDLOOP IGUAL FOR IN RANGO FUNCION RETURN PUNTO_COMA

%left MAS MENOS
%left POR DIV

%token <number> NUMENTERO
%token <numberf> NUMREAL
%token <string> IDENTIFICADOR

%type<snum> bucle_while sentencia_if nombreF declaracion calc expr Fun funcion

%union {
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
}


%start comp

%%

comp: cuerpo {
	printf("TODO OK\n"); 
}
;

cuerpo: initproc sentencias endproc
;


initproc: PROCEDURE nombreI IS {printf("Inicio -> procedure\n");}
;

endproc: END nombreF PUNTO_COMA {printf("Final -> end\n");}
;

nombreI: IDENTIFICADOR {
	add_SymText ( "Nombre", $1, "string" );}
;


nombreF: IDENTIFICADOR {

	if (strcmp($1, getvalsymText("Nombre")) == 0) {
		printf("CORRECTO - Coinciden los nombres\n");
	} else {
		printf("ERROR - No es igual el nombre del inicio y el del final\n");
	}
}
;

sentencias: declaraciones  comienzo  sentencia {}
;


comienzo: BEGINN {printf("begin\n");}
;


declaraciones: declaraciones  declaracion
	| declaracion 
;

declaracion: IDENTIFICADOR DOSPUNTOS tipo PUNTO_COMA { 
	printf("Se declara la variable: %s \n", $1);
	$$.texto = $1; add_SymText ( $$.texto, $$.texto, globalTipo);
}
;


tipo: INTEGER {
			globalTipo= "entero";
			printf("Declaracion -> int\n");
		}
      |FLOAT {
			globalTipo= "float";
			printf("Declaracion -> float\n");
		}
      |STRING {
			globalTipo= "string";
			printf("Declaracion -> string\n");
		}
      |BOOLEAN {
			globalTipo= "boolean";
			printf("Declaracion -> bool\n");
		}	
;

sentencia: sentencia  expr 
	| expr
;

expr: IDENTIFICADOR  DOSPUNTOS_IGUAL calc PUNTO_COMA {
	if (globalBoolCond == 0) {
		globalBoolCond =0;
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper($3.a);
 		fprintf(yyout, ".text\n");
		textOper($3.a);
 		fprintf(yyout, "..............................................\n");
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;


	}


	printf("Condicion: %d \n", $$.booleanCond);


	$$.texto= $1;

	if (globalError ==0) { //No hay errores
		if (getvalsymText($$.texto) == 0 ) {
			printf("ERROR - No se ha declarado la variable: %s \n", $$.texto);

		} else {
			printf("CORRECTO - Se ha declarado la variable: %s \n", $$.texto);
	 		add_SymNum($1, eval($3.a), globalTipo);
			Update_SymNum( $1, eval($3.a) ); 
			printf("RESULTADO - De %s: %4.4g\n", $1, eval($3.a));


		}
	} else { 
		globalError =0;
	}
		

      }
      | sentencia_if {
	//fprintf(yyout, "Sentencia IF\n");
	globalContadorNum = 0;
	//printf("IFFFFFO\n");
	//textOper($1.a);

	}

      |PUTLINE PIZQ_COM IDENTIFICADOR PDECH_COM PUNTO_COMA {printf("Put_Line\n");}
      |IDENTIFICADOR DOSPUNTOS_IGUAL factor PUNTO_COMA {printf("Asignacion\n");}
      |COMENTARIO {printf("Comentario\n");}
      |bucle_while { printf("Bucle WHILE\n");   //printf("WHILE - %4.4g\n", eval($1.f));
	}
      |bucle_for {printf("Bucle FOR\n");}
      |funcion {printf("FUNCION\n");}
;


sentencia_if: IF calc THEN  sentencia  ENDIF PUNTO_COMA {
		//$$.f = newflow('I', $2.f , $5.f, NULL); 
 		//fprintf(yyout, "IFFFFFFFFF\n");
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper($2.a);
 		fprintf(yyout, ".text\n");
		textIf(globalSignCond,$2.f);
 		fprintf(yyout, "..............................................\n");
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;

	}

	| IF calc THEN  sentencia  ELSE  sentencia  ENDIF PUNTO_COMA { 
		//$$.f = newflow('I', $2.f, $5.f, $9.f); 
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper($2.a);
 		fprintf(yyout, ".text\n");
		textIf(globalSignCond,$2.f);
 		fprintf(yyout, "..............................................\n");
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;
	}
;

/*ARBOL*/
calc:  calc MAS calc { 
		printf("Suma\n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores //comprobación de tipos
			if (($1.tipo == "entero") && ($3.tipo == "entero")) {
				$$.a = newast('+', $1.a,$3.a); 
				evalprint($$.a);
				globalTipo = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);
				printf("Suma (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "real") && ($3.tipo == "real")){
				$$.a = newast('+', $1.a,$3.a); 
				evalprint($$.a);
				globalTipo = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);
				printf("Suma (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "string")){
				$$.a = newast('+', $1.a,$3.a); 
				evalprint($$.a);
				globalTipo = $3.tipo;
				contadorOperadores(globalContadorOper, $$.a);
				printf("Suma (tipo=%s)\n", $$.tipo);
			} 
			else if (($3.tipo == "string")){
				$$.a = newast('+', $1.a,$3.a); 
				evalprint($$.a);
				globalTipo = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);
				printf("Suma (tipo=%s)\n", $$.tipo);
			}
			else if (($3.tipo == "string") && ($1.tipo == "string")){
				$$.a = newast('+', $1.a,$3.a); 
				evalprint($$.a);
				globalTipo = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);
				printf("Suma (tipo=%s)\n", $$.tipo);
			}

		} else {
			printf("HAY ERRORES NO SE REALIZA LA SUMA\n");

		}

	}
	|  calc MENOS calc { 
		printf("Resta\n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores
			if (($1.tipo == "entero") && ($3.tipo == "entero")) {
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Resta (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "real") && ($3.tipo == "real")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Resta (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "string")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Resta (tipo=%s)\n", $$.tipo);
			} 
			else if (($3.tipo == "string")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Resta (tipo=%s)\n", $$.tipo);
			}
			else if (($3.tipo == "string") && ($1.tipo == "string")){
				$$.a = newast('-', $1.a,$3.a); 
				evalprint($$.a);
				globalTipo = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);

				printf("Resta (tipo=%s)\n", $$.tipo);


			}
		}  else {
			printf("HAY ERRORES NO SE REALIZA LA RESTA\n");

		}

	}
	|  calc POR calc { 
		printf("Multiplicacion\n");
		globalContadorOper = globalContadorOper + 1;

		if (globalError ==0) { //No hay errores
			if (($1.tipo == "entero") && ($3.tipo == "entero")) {
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Mult (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "real") && ($3.tipo == "real")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Mult (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "string")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Mult (tipo=%s)\n", $$.tipo);


			} 
			else if (($3.tipo == "string")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Mult (tipo=%s)\n", $$.tipo);
			}
			else if (($3.tipo == "string") && ($1.tipo == "string")){
				$$.a = newast('*', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				globalTipo = $1.tipo;
				printf("Mult (tipo=%s)\n", $$.tipo);


			}
		} else {
			printf("HAY ERRORES NO SE REALIZA LA MULTIPLICACION\n");

		}

	}

	|   calc DIV calc {
		printf("Division\n");
		globalContadorOper = globalContadorOper + 1;

		if ($3.valor == 0) { //No se puede dividir entre 0
			globalError =1;
		}

		if (globalError ==0) { //No hay errores
			if (($1.tipo == "entero") && ($3.tipo == "entero")) {
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Div (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "real") && ($3.tipo == "real")){
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Div (tipo=%s)\n", $$.tipo);
			} 
			else if (($1.tipo == "string")){
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Div (tipo=%s)\n", $$.tipo);


			} 
			else if (($3.tipo == "string")){
				$$.a = newast('/', $1.a,$3.a);
				evalprint($$.a);
				contadorOperadores(globalContadorOper, $$.a);

				printf("Div (tipo=%s)\n", $$.tipo);

			}
			else if (($3.tipo == "string") && ($1.tipo == "string")){
				$$.a = newast('/', $1.a,$3.a); 
				evalprint($$.a);
				globalTipo = $1.tipo;
				contadorOperadores(globalContadorOper, $$.a);

				//printf("Div (tipo=%s)\n", $$.tipo);
			}
		}else {
			printf("HAY ERRORES NO SE REALIZA LA DIVISION\n");
		}

	}


	| calc MAYOR_Q calc {
		//printf("**Condicion MAYORQ\n");
		globalBoolCond = 1;

		if ($1.valor > $3.valor) {
			$$.booleanCond =1;
			$$.f = $$.booleanCond ;
			globalSignCond = '>';

			printf("CORRECTO - Es mayor\n");


		
		} else {
			$$.booleanCond =0;
			$$.f = $$.booleanCond;
			globalSignCond = '>';

			printf("ERROR - No es mayor\n");

		
		}

	} 
	| calc MENOR_Q calc {
		printf("**Condicion MENORQ\n");
		globalBoolCond = 1;

			if ($1.valor < $3.valor) {
				$$.booleanCond =1;
				$$.f = $$.booleanCond;
				globalSignCond = '<';


				printf("CORRECTO - Es menor\n");

		
			} else {
				$$.booleanCond =0;
				$$.f = $$.booleanCond;
				globalSignCond = '<';

				printf("ERROR - No es menor\n");

			}


	}
	| calc IGUAL calc {
		printf("**Condicion IGUALQ\n");
		globalBoolCond = 1;

		if ($1.valor == $3.valor) {
			printf("CORRECTO - Es igual\n");
			$$.booleanCond = 1;
			$$.f = $$.booleanCond;
			globalSignCond = '=';

		
		} else {
			printf("ERROR - No es igual\n");
			$$.booleanCond = 0;
			$$.f = $$.booleanCond;
			globalSignCond = '=';
		
		}

	}

	| NUMENTERO { $$.a = newnum($1);
		$$.valor = $1;
		$$.tipo = "entero";
		globalContadorNum = globalContadorNum +1;
		contadorNumeros(globalContadorNum, $$.valor );
	}

	| NUMREAL {
		$$.a= newnum($1);
		$$.valord = $1; $$.tipo = "real";


	}
	| IDENTIFICADOR {
		printf("variable\n");
		$$.tipo = "string";

		if (getvalsymText($1) == 0 ) {
			globalError = 1;
			printf("ERROR - Variable no existe: %s \n", $1);

		} else {
			globalError = 0;
			$$.valor = getvalsymNum($1);
			$$.a= newnum($$.valor);
			globalContadorNum = globalContadorNum +1;
			contadorNumeros(globalContadorNum, $$.valor );

			printf("CORRECTO - Variable si existe: %s \n", $1);		
		}
	}
;


funcion: FUNCION nombreFuncion PAR_I declaraciones PAR_D RETURN tipo IS  BEGINN  sentencia  Fun  END PUNTO_COMA {
	//$$.fun = newfunc($4.fun, $11.fun);
}
;

nombreFuncion: IDENTIFICADOR {
	if (getvalsymNum($1) == 0 ) {
		add_SymNum($1, 1 , "string");
		printf("CORRECTO - No existe ninguna función con ese nombre\n");		
	} else {
		printf("ERROR - Existe ya una funcion con ese nombre\n");		
	}
	//fprintf(yyout, "Nombre funcion\n");
}  
;

Fun: RETURN IDENTIFICADOR {

	if (getvalsymText($2) == 0 ) {
		printf("ERROR - No se ha declarado la variable: %s \n", $2);
	} else {
		printf("Tiene al menos un return\n");
		if (strcmp(globalTipo, gettypesymText($2)) == 0) {
			printf("CORRECTO - Coincide el tipo de return\n");		
		} else {
			printf("ERROR - No coincide el tipo de return\n");		
		}
	}
} 
;



factor: NUMENTERO //{fprintf(yyout, "  factor--> NUMENTERO(%d)\n", $1);}
	| NUMREAL //{fprintf(yyout, "  factor--> NUMREAL(%f)\n"), $1;}
	|IDENTIFICADOR //{fprintf(yyout, "  factor --> variable(%s)\n", $1);}
	|TRUE //{fprintf(yyout, "  factor --> True\n");}
	|FALSE //{fprintf(yyout, "  factor --> False\n");}
;


bucle_while: WHILE calc LOOP  sentencia  ENDLOOP PUNTO_COMA { 
		//$$.f = newflow('W', $2.f, $4.f, NULL);  
 		//fprintf(yyout, "WHILEEEEEE\n");
		printf("while\n");
 		fprintf(yyout, "..............................................\n");
 		fprintf(yyout, ".data\n");
		dataOper($2.f);
 		fprintf(yyout, ".text\n");
		textWhile(globalSignCond, $$.f);
		globalContadorNum =0;
		globalContadorOper =0;
		globalBoolCond =0;

 		fprintf(yyout, "..............................................\n");

}
;

bucle_for: FOR factor IN rangos LOOP  sentencia  ENDLOOP PUNTO_COMA
;

rangos: factor RANGO factor //{fprintf(yyout, "Variable\n");}
;


%%
int main(int argc, char *argv[]) {

if (argc == 1) {
	yyparse();
}
if (argc == 2) {
	yyout = fopen( "./salidaAda.txt", "wt" );

	yyin = fopen(argv[1], "rt");

	yyparse();
}

return 0;
}


yyerror()
{ 
} 
