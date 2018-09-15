#include "stdio.h"
#include "stdlib.h"
#include "microParser.h"

extern int yyparse();
extern int yylex();
extern FILE * yyin;
extern char * yytext;
extern int yylineno;

int main (int argc, char * argv[]) {
  int flag;
  yyin = fopen(argv[1], "r");
  flag = yyparse(); 
  
  if(flag == 0) {
    printf("Accepted\n");
  } else {
    printf("Not Accepted\n");
  }
  return 0;
}
