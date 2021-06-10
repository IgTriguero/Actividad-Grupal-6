#!/bin/bash
rm ast.txt
rm output.txt
bison -dy bison.y
flex flex.l
gcc lex.yy.c y.tab.c -o "ejecutable"
./ejecutable "$1" "$2" 
