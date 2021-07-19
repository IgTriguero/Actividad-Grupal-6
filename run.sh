#!/bin/bash
rm ./salida/*.txt
flex ./src/flex.l
bison -dy ./src/bison.y
mv lex.yy.c ./src
mv y.tab.c ./src
mv y.tab.h ./src
gcc ./src/lex.yy.c ./src/y.tab.c -lm -o ./exec/ejecutable
./exec/ejecutable $1 > ./salida/output.txt
mv salidaAda.txt ./salida