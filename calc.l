%{
#include <stdlib.h>
#include <stdio.h>
#include "calc.tab.h"
%}
int [0-9]+
float (\.{int})|({int}(\.{int}?)?)
%%
[ \t]*    { ; }
[-+*/()]  { return *yytext; }
{float}   { yylval.d = atof(yytext);
            return NUMBER; }
\n        { return 0; }
%%
int yywrap() {
  return 1;
}
