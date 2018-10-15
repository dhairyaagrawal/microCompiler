#include "iostream"
#include <string>
#include <list>
#include "stack.h"
#include "table.h"
#include "ASTNode.h"
#include "microParser.hpp"

extern int yyparse();
extern int yylex();
extern FILE * yyin;
extern char * yytext;
extern int yylineno;

extern stack* myStack;
extern std::list<ASTNode*> * listAST;

int main (int argc, char * argv[]) {
  int flag;
  //stack myStack;

  yyin = fopen(argv[1], "r");
  printf("fuck\n");
  flag = yyparse();
  printf("what\n");
  fclose(yyin);
  /*for(int i = 0; i < myStack->tableCt; i++){
    myStack->tables[i]->print_table();
    if (i != myStack->tableCt - 1) {std::cout << std::endl;}
  }*/

  //ASTNode* tmp = listAST->front();
  for(std::list<ASTNode*>::iterator it=listAST->begin();it!=listAST->end();++it)
  {
	  (*it)->print();
	  std::cout << std::endl;
  }
  return 0;
}
