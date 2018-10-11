#include "iostream"
#include "microParser.hpp"
#include "stack.h"

extern int yyparse();
extern int yylex();
extern FILE * yyin;
extern char * yytext;
//extern int yylineno;

extern stack* myStack;

int main (int argc, char * argv[]) {
  int flag;
  //stack myStack;

  yyin = fopen(argv[1], "r");
  flag = yyparse(); 
  fclose(yyin);

  

  return 0;
}
