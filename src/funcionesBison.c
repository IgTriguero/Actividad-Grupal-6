#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
	bool vbool;
	bool assigned;
};



//Variables globales
int line_num = 1;

int size = 52;

int elementosOcupados = 0;

int numnodo = 0;

struct ast nodos[52];

struct symb tabla[52];

// tabla simbolos
void iniArrayTabla(struct symb *tabla, int inicio, int fin); //

// nodos
void iniArrayNodos(struct ast *nodos, int inicio, int fin); //

// funciones ast
struct ast *createAST(char* nodetype, struct ast *l, struct ast *r);//
struct ast *createBOO(char* nodetype, struct ast *l, struct ast *r);//
struct ast *createFlow(struct ast *cond);//
struct ast *createFlow2(struct ast *cond);//
struct ast *createNum(double d);//
struct ast *createSTR(char* s);//
struct ast *createBOOLVAR(char* s);//
struct ast *createASTAsignacion(struct ast *op);//

//funciones tabla
void insertarElemento(struct symb *tabla, int *size, int valor, char* svalor, float fvalor, char *variable, bool bvalor, int *elementosOcupados, char* type, bool assigned );//
int buscarValor(struct symb *tabla, char *nombre, char *tipo, int *size);//
int getIntFromTable(struct symb *tabla, int size, char* name);//
float getFloatFromTable(struct symb *tabla, int size, char* name);//
char* getStringFromTable(struct symb *tabla, int size, char* name);//
bool getBooleanFromTable(struct symb *tabla, int size, char* name);//
int operacionEnteros(char* operator, int left, int right);
float operacionFloats(char* operator, float left, float right);


bool checkVarAndType(struct symb *tabla, int size, char* name, char* type);//
bool searchVar(struct symb *tabla, int size, char* name);//
char* getVarType(struct symb *tabla, int size, char* name);//
int compare(char* operator, float left, float right);//


void evalAST(struct ast a, int* size);//
void printAST(struct ast nodos[], int i, int encontrado, int salida);//

void yyerror (char const *s) {
	printf("Error:\t %s\t\n", s);
}

void yyerrorLine (char const *s, int lineno) {
	printf("Error:\t %s\t Line: %d\n", s, lineno);
}


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
struct ast *createFlow(struct ast *cond) {

    struct flow *a = malloc(sizeof(struct flow));

    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }

    a->nodetype = "IF";
    a->cond = cond;

    return (struct ast *)a;
}

struct ast *createFlow2(struct ast *cond) {

    struct flow *a = malloc(sizeof(struct flow));

    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }

    a->nodetype = "WHILE";
    a->cond = cond;

    return (struct ast *)a;
}

struct ast *createASTAsignacion(struct ast *op)
{

    struct asign *a = malloc(sizeof(struct asign));
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "=";
    a->as = op;

    return (struct ast *)a;
}

struct ast *createAST(char *nodetype, struct ast *l, struct ast *r)
{
    struct ast *a = malloc(sizeof(struct ast));

    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

struct ast *createBOO(char *nodetype, struct ast *l, struct ast *r)
{

    struct boo *a = malloc(sizeof(struct boo));

    if (!a)
    {
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
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "Constante";
    a->number = d;
    return (struct ast *)a;
}

struct ast *createSTR(char *s)
{
    struct strval *a = malloc(sizeof(struct strval));
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "String";
    a->str = s;
    return (struct ast *)a;
}

struct ast *createBOOLVAR(char *s)
{
    struct strval *a = malloc(sizeof(struct strval));
    if (!a)
    {
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = "Boolean_var";
    a->str = s;
    return (struct ast *)a;
}

void evalAST(struct ast a, int *size)
{

    int i = 0;
    int encontrado = 0;
    while (i < *size && encontrado == 0)
    {
        if ((strcmp(nodos[i].nodetype, "._empty") == 0) && (strcmp(a.nodetype, "String") != 0) && (strcmp(a.nodetype, "Constante") != 0))
        {
            nodos[i] = a;
            numnodo = numnodo + 1;
            encontrado = 1;
        }
        else
        {
            i++;
        }
    }
}

void printAST(struct ast nodos[], int i, int encontrado, int salida)
{
    struct ast temp[52];
    iniArrayNodos(temp, 0, 52);

    while (encontrado == 0 && salida == 0)
    {
        if (strcmp(nodos[i].nodetype, "._empty") == 0)
        {
            encontrado = 1;
            salida = 1;
        }
        else
        {
            if (strcmp(nodos[i].nodetype, "IF") == 0)
            {
                write_file(ast_text, "\n");
                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
            }
            else if (strcmp(nodos[i].nodetype, "WHILE") == 0)
            {
                write_file(ast_text, "\n");
                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
            }
            else if ((strcmp(nodos[i].nodetype, ">") == 0) || (strcmp(nodos[i].nodetype, "<") == 0) || (strcmp(nodos[i].nodetype, ">=") == 0) ||
                     (strcmp(nodos[i].nodetype, "<=") == 0) || (strcmp(nodos[i].nodetype, "!=") == 0) || (strcmp(nodos[i].nodetype, "==") == 0))
            {

                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].r;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
                salida = 1;
            }
            else if (strcmp(nodos[i].nodetype, "=") == 0)
            {
                write_file(ast_text, "\n");
                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                if ((strcmp(nodos[i].l->nodetype, "+") == 0) || (strcmp(nodos[i].l->nodetype, "-") == 0) || (strcmp(nodos[i].l->nodetype, "/") == 0) ||
                    (strcmp(nodos[i].l->nodetype, "*") == 0))
                {

                    temp[0] = *nodos[i].l;
                    printAST(temp, 0, 0, 0);
                }
                else
                {
                    temp[0] = *nodos[i].l;
                    printAST(temp, 0, 0, 0);
                }
            }
            else if ((strcmp(nodos[i].nodetype, "+") == 0) || (strcmp(nodos[i].nodetype, "-") == 0) || (strcmp(nodos[i].nodetype, "/") == 0) ||
                     (strcmp(nodos[i].nodetype, "*") == 0))
            {

                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].l;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
                temp[0] = *nodos[i].r;
                printAST(temp, 0, 0, 0);
                write_file(ast_text, "\n");
            }
            else if (strcmp(nodos[i].nodetype, "String") == 0)
            {

                write_file(ast_text, nodos[i].nodetype);
                write_file(ast_text, "\n");
                salida = 1;
            }
            else if (strcmp(nodos[i].nodetype, "Constante") == 0)
            {
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
int buscarValor(struct symb *tabla, char *nombre, char *tipo, int *size)
{
    int i = 0;
    int status = -1;
    while (i < *size && status == -1)
    {
        if (strcmp(tabla[i].vname, nombre) == 0 && (strcmp(tabla[i].type, tipo) == 0))
        {
            status = i;
        }
        else if (strcmp(tabla[i].vname, nombre) == 0)
        {
            status = i;
        }
        else
        {
            i++;
        }
    }
    return status;
}

void insertarElemento(struct symb *tabla, int *size, int valor, char *svalor, float fvalor, char *variable, bool bvalor, int *elementosOcupados, char *type, bool assigned)
{
    int elementIndex = 0;

    elementIndex = buscarValor(tabla, variable, type, size);

    if (elementIndex != -1)
    {
        if (strcmp(type, "integer") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vvali = valor;
            tabla[elementIndex].type = type;
        }
        else if (strcmp(type, "float") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vvalf = fvalor;
            tabla[elementIndex].type = type;
        }
        else if (strcmp(type, "string") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vvals = svalor;
            tabla[elementIndex].type = type;
        }
        else if (strcmp(type, "boolean") == 0)
        {
            tabla[elementIndex].vname = variable;
            tabla[elementIndex].vbool = bvalor;
            tabla[elementIndex].type = type;
        }
        tabla[elementIndex].assigned = assigned;
    }
    else
    {
        int i = 0;
        int encontrado = 0;

        while (i < *size && encontrado == 0)
        {

            if (strcmp(tabla[i].vname, "._empty") == 0)
            {
                if (strcmp(type, "integer") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vvali = valor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                else if (strcmp(type, "float") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vvalf = fvalor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                else if (strcmp(type, "string") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vvals = svalor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                else if (strcmp(type, "boolean") == 0)
                {
                    tabla[i].vname = variable;
                    tabla[i].vbool = bvalor;
                    tabla[i].type = type;
                    *elementosOcupados = *elementosOcupados + 1;
                    encontrado = 1;
                }
                tabla[i].assigned = assigned;
                *elementosOcupados = *elementosOcupados + 1;
                encontrado = 1;
            }
            else
            {
                i++;
            }
        }
    }
}

int compare(char *operator, float left, float right)
{
    if (strcmp(operator, ">") == 0)
    {
        return left > right ? 1 : 0;
    }
    else if (strcmp(operator, "<") == 0)
    {
        return left < right ? 1 : 0;
    }
    else if (strcmp(operator, ">=") == 0)
    {
        return left >= right ? 1 : 0;
    }
    else if (strcmp(operator, "<=") == 0)
    {
        return left <= right ? 1 : 0;
    }
    else if (strcmp(operator, "==") == 0)
    {
        return left == right ? 1 : 0;
    }
    else if (strcmp(operator, "!=") == 0)
    {
        return left != right ? 1 : 0;
    }
}

char *getVarType(struct symb *tabla, int size, char *name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, "._empty") == 0)
        {
            continue;
        }
        else if (strcmp(tabla[i].vname, name) == 0)
        {
            return tabla[i].type;
        }
    }
}

bool searchVar(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, "._empty") == 0)
        {
            continue;
        }
        else if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    if (elementIndex != -1)
    {
        return false;
    }

    return true;
}

bool checkVarAndType(struct symb *tabla, int size, char *name, char *type)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, "._empty") == 0)
        {
            continue;
        }
        else if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    if (elementIndex == -1)
    {
        return false;
    }

    if (strcmp(tabla[elementIndex].type, type) != 0)
    {
        return false;
    }

    return true;
}

int getIntFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vvali;
}

float getFloatFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vvalf;
}

char *getStringFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vvals;
}

bool getBooleanFromTable(struct symb *tabla, int size, char *name)
{
    int elementIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(tabla[i].vname, name) == 0)
        {
            elementIndex = i;
            break;
        }
    }

    return tabla[elementIndex].vbool;
}

int operacionEnteros(char* operator, int left, int right){
	if(strcmp(operator, "+")==0){
		return left + right;
	} else if(strcmp(operator, "-")==0){
		return left - right;
	} else if(strcmp(operator, "*")==0){
		return left * right;
	} else if(strcmp(operator, "/")==0){
		return left / right;
	} else {
		return -500;
	}
}

float operacionFloats(char* operator, float left, float right){
	if(strcmp(operator, "+")==0){
		return left + right;
	} else if(strcmp(operator, "-")==0){
		return left - right;
	} else if(strcmp(operator, "*")==0){
		return left * right;
	} else if(strcmp(operator, "/")==0){
		return left / right;
	} else {
		return -500;
	}
}