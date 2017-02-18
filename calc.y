%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(const char* s);
void yy_scan_string(const char* s);
%}
%token <d> NUMBER
%type <d> expression
%union {
  double d;
}
%left '+' '-'
%left '*' '/'
%%
start : expression { printf("%f\n", $1); }
;
expression : expression '+' expression { $$ = $1 + $3; }
           | expression '-' expression { $$ = $1 - $3; }
           | expression '*' expression { $$ = $1 * $3; }
           | expression '/' expression { $$ = $1 / $3; }
           | '(' expression ')' { $$ = $2; }
           | '-' expression { $$ = -$2; }
           | NUMBER { $$ = $1; }
           ;
%%
int main(int argc, char* argv[]) {
  if(argc < 2) {
    return EXIT_FAILURE;
  } else {
    yy_scan_string(argv[1]);
    yyparse();
    return EXIT_SUCCESS;
  }
}

int yyerror(const char* s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}
