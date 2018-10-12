#include "iostream"
#include "microParser.hpp"
#include "stack.h"
#include "table.h"

extern int yyparse();
extern int yylex();
extern FILE * yyin;
extern char * yytext;
extern int yylineno;

extern stack* myStack;

int main (int argc, char * argv[]) {
  int flag;
  //stack myStack;

  yyin = fopen(argv[1], "r");
  flag = yyparse();
  fclose(yyin);
  for(int i = 0; i < myStack->tableCt; i++){
    myStack->tables[i]->print_table();
    if (i != myStack->tableCt - 1) {std::cout << std::endl;}
  }



  return 0;
}
