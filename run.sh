#!/bin/bash
rm ast.txt
rm output.txt
flex flex.l
bison -dy bison.y
gcc lex.yy.c y.tab.c -o "ejecutable"
./ejecutable "$1" "$2" 
