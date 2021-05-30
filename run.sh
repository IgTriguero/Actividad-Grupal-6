#!/bin/bash
bison -dy "./src/bison.y"
flex "./src/flex.l" 
mv "./lex.yy.c" "./otros/" 
mv "./y.tab.c" "./otros/" 
mv "./y.tab.h" "./otros/" 
gcc "./otros/lex.yy.c" "./otros/y.tab.c" -o "./ejecutable" 
mv "./ejecutable" "./otros/" 
./otros/ejecutable