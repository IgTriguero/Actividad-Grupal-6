%{
#include <stdio.h>
#include "y.tab.h"

%}

%option noyywrap
%option yylineno

bool (bool|boolean)
false (false|FALSE)
true (true|TRUE)

variable_name ([a-zA-Z|0-9|_|])+
string ([a-zA-Z])+
fnum ([0-9])+[\,|\.]([0-9])+
enum ([0-9])+

procedure (procedure|procedure)
range (range|RANGE)
while (while|WHILE)
for (for|FOR)
case (case|CASE)
when (when|WHEN)
is (is|IS)
others (others|OTHERS)
end (end|END)
loop (loop|LOOP)
of (of|OF)
type (type|TYPE)

and (and|AND)
or (or|OR)

if (if|IF)
else (else|ELSE)
elseif (elseif|ELSEIF)
then (then|THEN)


%%

[ \t]	;
\n		{}
{procedure} {return PROCEDURE;}
{while} {return WHILE;}
{for}   {return FOR;}
"Integer" {return DECLINTEGER;}
"Float" {return DECLFLOAT;}
"Boolean" {return DECLBOOLEAN;}
"array" {return DECLARRAY;}
"String" {return DECLSTRING;}
{case}  {return CASE;}
{range} {return RANGE;}
{when}  {return WHEN;}
{is}  {return IS;}
{others}  {return OTHERS;}
{end}   {return END;}
{loop}  {return LOOP;}
{then}  {return THEN;}
{if}    {return IF;}
{else}  {return ELSE;}
{elseif}    {return ELSEIF;}
{true}  {return TRUE;} 
{false} {return FALSE;}
{of}  {return OF;} 
{type} {return TYPE;}
{fnum}	{yylval.fval = atof(yytext); return FLOAT;}
{enum}	{yylval.eval = atoi(yytext); return ENTERO;}
\".+\" {yylval.sval = strdup(yytext); return STR;}
{variable_name}  {yylval.sval = strdup(yytext); return VAR_NAME;}
"{"		{return ABRIR_LLAVE;}
"}"		{return CERRAR_LLAVE;}
"+"		{return SUMA;}
"-"		{return RESTA;}
"*"		{return MULT;}
"/"		{return DIV;}
"("		{return ABRIR_PARENTESIS;}
")"		{return CERRAR_PARENTESIS;}
"<"		{return MENOR;}
">"		{return MAYOR;}
"="		{return EQUAL;}
">="    {return MAYOR_IGUAL;}
"<="    {return MENOR_IGUAL;}
"!="    {return DESIGUAL;}
"=="    {return IGUAL;}
":"     {return COLON;}
";"     {return SEMICOLON;}
"=>"    {return FLECHA;}
".."    {return DOTDOT;}
","     {return COMMA;}
"--".*	{return COMMENT;}

%%
