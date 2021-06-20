#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

char *filename_data = "data.txt";
char *filename_text = "text.txt";

// mips structs
int st_mipsVarLength = 100;
int st_mipsValoresLength = 100;
int liInsertado = 0;
int ifnumber = 0;
int whilenumber = 0;
int whereami = 0;

struct MipsVariables {
    char *type;
    char *name;
    int memoryPos;
    int intVal;
    char *stVal;
    bool bVal;
    float fval;
};

struct MipsValores {
    int ival;
    float fval;
    bool bval;
    char* sval;
    int memoryPos;
    char *type;
    char *status;
};

struct MipsVariables mipsVariables[100];
struct MipsValores mipsValores[100];

void mipsVar_initialize_struct();
void mipsVar_initialize_valorStruct();
char* getTextFile();
void concatenateTxt(char* filename1, char* filename2, char* filename3);

// file writing
void clear_file(char *filename);
void write_file(char *filename, char *content);
void mipsVar_create_data();
void mipsIns_create_text();
void mipsVar_write_declarations();

// conversion aux functions
char *integer_to_string(int x);
char *float_to_string(float x);
char *bool_to_string(bool x);

// mips vars
void mipsVar_insert_mips_variable_declaration(char *type, char *varname, int val1, char *val2, float val3, bool val4);
void mipsIns_asign_val_to_var(char *varname, char *type, int val1, float val2, char* val3, bool val4);
char *mipsVar_get_variable_type(char *type);

//asign
int mipsVar_get_variable_index(char *variable);
int mipsVar_insert_update_numVar(int *li, char *type,int val1, float val3, char* val4, bool val5);
char *mipsIns_createLi_variable(int li);
void mipsIns_load_instruction_variable(char *filename, int index);
char *mipsVar_assign_memory_pos(int i);
void mipsIns_write_li_instruction(char *filename, char *memory_pos, char *value);

//if
void mipsIns_if(int value);
bool file_exists (char *filename);
// impementations ---------------
void mipsVar_insert_mips_variable_declaration(char *type, char *varname, int val1, char *val2, float val3, bool val4) {
    int i = 0;
    int encontrado = 0;
    while (i < st_mipsVarLength && encontrado == 0) {
        if (strcmp(mipsVariables[i].name, "._empty") == 0) {
            mipsVariables[i].name = varname;
            mipsVariables[i].type = type;
            mipsVariables[i].memoryPos = i;
            mipsVariables[i].intVal = val1;
            mipsVariables[i].stVal = val2;
            mipsVariables[i].fval = val3;
            mipsVariables[i].bVal = val4;
            mipsIns_load_instruction_variable(getTextFile(), i);
            encontrado = 1;
        } else {
            i += 1;
        }
    }
}

void mipsIns_load_instruction_variable(char *filename, int index) {
    write_file(filename, "lw ");
    write_file(filename, mipsVar_assign_memory_pos(mipsVariables[index].memoryPos));
    write_file(filename, ",");
    write_file(filename, mipsVariables[index].name);
    write_file(filename, "\n");
}

char *mipsVar_assign_memory_pos(int i) {
    char *start = "$s";
    char *position = integer_to_string(i);
    char tmp[5000];
    strcpy(tmp, start);
    strcat(tmp, position);
    char *final = tmp;
    return final;
}

char *integer_to_string(int x) {
    char *buffer = malloc(sizeof(char) * sizeof(int) * 4 + 1);
    if (buffer) {
        sprintf(buffer, "%d", x);
    }
    return buffer;
}

char *float_to_string(float x) {
    char *buffer = malloc(sizeof(char) * sizeof(float) * 16 + 1);
    if (buffer) {
        sprintf(buffer, "%f", x);
    }
    return buffer;
}

char *bool_to_string(bool x) {
    return x ? "1" : "0";
}

void mipsIns_asign_val_to_var(char *varname, char *type, int val1, float val2, char* val3, bool val4) {
    int index_1 = mipsVar_get_variable_index(varname);
    if (strcmp(mipsVariables[index_1].type, type) == 0) {
        int index_2 = 0;
        if (strcmp(type, "integer") == 0) {
            index_2 = mipsVar_insert_update_numVar(0, type, val1, 0, "", false);
            mipsIns_write_li_instruction(getTextFile(), mipsIns_createLi_variable(mipsValores[index_2].memoryPos),
                                         integer_to_string(mipsValores[index_2].ival));
        } else if (strcmp(type, "float") == 0) {
            // char* formattedHex;
            // sprintf(formattedHex "%08X" , *(unsigned int*)&val2 );
            index_2 = mipsVar_insert_update_numVar(0, type, 0.0, val2, "", false);
            mipsIns_write_li_instruction(getTextFile(), mipsIns_createLi_variable(mipsValores[index_2].memoryPos),
                                         float_to_string(mipsValores[index_2].fval));
        } else if (strcmp(type, "string") == 0) {
            index_2 = mipsVar_insert_update_numVar(0, type, 0, 0.0, val3, false);
            mipsIns_write_li_instruction(getTextFile(), mipsIns_createLi_variable(mipsValores[index_2].memoryPos),
                                         float_to_string(mipsValores[index_2].fval));
        } else if (strcmp(type, "boolean") == 0) {
            index_2 = mipsVar_insert_update_numVar(0, type, 0, 0.0, "", val4);
            mipsIns_write_li_instruction(getTextFile(), mipsIns_createLi_variable(mipsValores[index_2].memoryPos),
                                         float_to_string(mipsValores[index_2].fval));
        }
        write_file(getTextFile(), "move ");
        write_file(getTextFile(), mipsVar_assign_memory_pos(mipsVariables[index_1].memoryPos));
        write_file(getTextFile(), ", ");
        write_file(getTextFile(), mipsIns_createLi_variable(mipsValores[index_2].memoryPos));
        write_file(getTextFile(), "\n");

    }
}

int mipsVar_get_variable_index(char *variable) {
    int i = 0;
    int index = 0;
    int encontrado = 0;
    while (i < st_mipsVarLength && encontrado == 0) {
        if (strcmp(mipsVariables[i].name, variable) == 0) {
            encontrado = 1;
            index = i;
        } else {
            i++;
        }
    }
    if (encontrado == 0) {
        return -500;
    } else {
        return index;
    }
}

int mipsVar_insert_update_numVar(int *li, char *type, int val1, float val2, char* val3, bool val4) {
    int i = 0;
    int encontrado = 0;
    while (i < st_mipsValoresLength && encontrado == 0) {
        if (mipsValores[i].status == NULL) {

            mipsValores[i].status = "ocupado";
            mipsValores[i].ival = val1;
            mipsValores[i].bval = val4;
            mipsValores[i].sval = val3;
            mipsValores[i].fval = val2;
            mipsValores[i].type = type;
            mipsValores[i].memoryPos = i;
            encontrado = 1;
            liInsertado += 1;
        } else {
            i += 1;
        }
    }
    return i;
}
char *mipsIns_createLi_variable(int li) {
    char *start = "$t";
    char *position = integer_to_string(li);
    char tmp[5000];
    strcpy(tmp, start);
    strcat(tmp, position);
    char *final = tmp;

    return final;
}

void mipsVar_create_data() {
    write_file(filename_data, ".data\n");
}

void mipsIns_create_text() {
    write_file(getTextFile(), ".text");
    write_file(getTextFile(), "\n");
}

void mipsVar_initialize_valorStruct() {
    for (int i = 0; i < st_mipsVarLength; i++) {
        mipsValores[i].memoryPos = 0;
        mipsValores[i].fval = -500;
        mipsValores[i].ival = -500;
        mipsValores[i].bval = false;
        mipsValores[i].status = NULL;
    }
}

void mipsVar_initialize_struct() {
    for (int i = 0; i < st_mipsVarLength; i++) {
        mipsVariables[i].name = "._empty";
        mipsVariables[i].type = "._empty";
        mipsVariables[i].memoryPos = 0;
        mipsVariables[i].intVal = -500;
        mipsVariables[i].stVal = NULL;
        mipsVariables[i].bVal = false;
        mipsVariables[i].fval = -500;
    }
}

void mipsIns_write_li_instruction(char *filename, char *memory_pos, char *value) {
    write_file(filename, "li ");
    write_file(filename, memory_pos);
    write_file(filename, ", ");
    write_file(filename, value);
    write_file(filename, "\n");
}

void mipsVar_write_declarations() {
    int i = 0;
    int fin = 0;
    while (i < st_mipsVarLength && fin == 0) {
        if (strcmp(mipsVariables[i].name, "._empty") == 0) {
            fin = 1;
        } else {
            char *varname = mipsVariables[i].name;
            char *type = mipsVariables[i].type;
            char *mips_type = mipsVar_get_variable_type(type);
            write_file(filename_data, varname);
            write_file(filename_data, ":");
            write_file(filename_data, " ");
            write_file(filename_data, mips_type);

            write_file(filename_data, " ");
            if (strcmp(type, "integer") == 0) {
                if (mipsVariables[i].intVal != -500) {
                    write_file(filename_data, integer_to_string(mipsVariables[i].intVal));
                }
            } else if (strcmp(type, "float") == 0) {
                if (mipsVariables[i].fval != -500) {
                    write_file(filename_data, float_to_string(mipsVariables[i].fval));
                }
            } else if (strcmp(type, "boolean") == 0) {
                    write_file(filename_data, bool_to_string(mipsVariables[i].bVal));

            } else if (strcmp(type, "string") == 0) {
                if (mipsVariables[i].stVal != NULL) {
                    char* aux;
                    aux = mipsVariables[i].stVal;
                    aux[strlen(aux)-1] = '\0';
                    char auxfin[100] = "";
                    strcat(auxfin, "\"\\");
                    strcat(auxfin, aux);
                    strcat(auxfin, "\\\"\"");
                    auxfin[strlen(auxfin)] = '\0';
                    write_file(filename_data, auxfin);
                }
            }
            write_file(filename_data, "\n");
            i += 1;
        }
    }
}

char *mipsVar_get_variable_type(char *type) {
    if (strcmp(type, "integer") == 0) {
        return ".word";
    } else if (strcmp(type, "float") == 0) {
        return ".float";
    } else if (strcmp(type, "char") == 0) {
        return "ascii";
    } else if (strcmp(type, "boolean") == 0) {
        return ".byte";
    } else if (strcmp(type, "double") == 0) {
        return ".double";
    } else if (strcmp(type, "string") == 0) {
        return ".ascii";
    } else {
        return "yes";
    }
}

void mipsIns_if(int value) {
    char* dir = mipsIns_createLi_variable(value);

    mipsIns_write_li_instruction(getTextFile(), dir, integer_to_string(value));
    write_file(getTextFile(), "bnez ");
    write_file(getTextFile(), dir );
    write_file(getTextFile(), ",");
    write_file(getTextFile(), " then");
    write_file(getTextFile(), integer_to_string(ifnumber));
    write_file(getTextFile(), "\n");
    whereami = 1;
}

void mipsIns_else() {



    whereami = 2;

}

void mipsIns_endIf() {
    //concatenate filename con else con then
        
        

    if (file_exists("if_else.txt")){
        concatenateTxt("text.txt", "if_else.txt", "file_aux.txt");
        write_file("file_aux.txt", "\n j endif");
        write_file("file_aux.txt", integer_to_string(ifnumber));
        write_file("file_aux.txt", "\n then");
        write_file("file_aux.txt", integer_to_string(ifnumber));
        write_file("file_aux.txt", ":\n");
        remove("text.txt");
        concatenateTxt("file_aux.txt", "if_then.txt", "text.txt");
        remove("file_aux.txt");
        remove("if_then.txt");
        remove("if_else.txt");
    }else{
        write_file("text.txt", "\n j endif");
        write_file("text.txt", integer_to_string(ifnumber));
        write_file("text.txt", "\n then");
        write_file("text.txt", integer_to_string(ifnumber));
        write_file("text.txt", ":\n");
        concatenateTxt("text.txt", "if_then.txt", "file_aux.txt");
        remove("text.txt");
        rename("file_aux.txt", "text.txt");
        remove("file_aux.txt");
        remove("if_then.txt");
    }
    
    
    whereami = 0;
    write_file(getTextFile(), "\n");
    write_file(getTextFile(), "endif");
    write_file(getTextFile(), integer_to_string(ifnumber));
    write_file(getTextFile(), ":");
    write_file(getTextFile(), "\n");
    write_file(getTextFile(), "\n");
    ifnumber+=1;
}

char* getTextFile() {
    if(whereami == 0){
        return "text.txt";
    } else if(whereami == 1){
        return "if_then.txt";
    } else if(whereami == 2){
        return "if_else.txt";
    }
}

void write_file(char *filename, char *content) {
    FILE *file;
    file = fopen(filename, "a");
    fprintf(file, "%s", content);
    fclose(file);
}

void concatenateTxt(char* filename1, char* filename2, char* filename3) {
    // Open two files to be merged
   FILE *fp1 = fopen(filename1, "r");
   FILE *fp2 = fopen(filename2, "r");
    
   // Open file to store the result
   FILE *fp3 = fopen(filename3, "w");
   char c;

   // Copy contents of first file to file3.txt
   while ((c = fgetc(fp1)) != EOF)
      fputc(c, fp3);

   // Copy contents of second file to file3.txt
   while ((c = fgetc(fp2)) != EOF)
      fputc(c, fp3);

   fclose(fp1);
   fclose(fp2);
   fclose(fp3);
}

bool file_exists (char *filename) {
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
}