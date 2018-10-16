#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <list>
#include "stack.h"
#include "table.h"
#include "ASTNode.h"
#include "microParser.hpp"
#include "CodeObject.h"
#include "IRNode.h"

extern int yyparse();
extern int yylex();
extern FILE * yyin;
extern char * yytext;
extern int yylineno;

extern stack* myStack;
extern std::list<ASTNode*> * listAST;

CodeObject* parseAST(ASTNode*);
void generateASM(IRNode&, std::list<std::string>&);

int main (int argc, char * argv[]) {
  int flag;
  CodeObject* total = new CodeObject();

  yyin = fopen(argv[1], "r");
  flag = yyparse();
  fclose(yyin);

  //STEP3 table printing code
  /*for(int i = 0; i < myStack->tableCt; i++){
    myStack->tables[i]->print_table();
    if (i != myStack->tableCt - 1) {std::cout << std::endl;}
  }*/

  for(std::list<ASTNode*>::iterator it=listAST->begin();it!=listAST->end();++it) {
	  //(*it)->print(); //prints AST
	  //std::cout << std::endl;

	  CodeObject* ircode = parseAST(*it);
	  total->IRseq.splice(total->IRseq.end(),ircode->IRseq);
  }
  total->print(); //prints IR

  std::list<std::string> assembly; //stores assembly code as list of lines
  table* globalTable = myStack->tables[0]; //global scope variables only for step4
  for(int i = 0; i < globalTable->entryCt; i++) {
	  if(globalTable->entries[i]->type == "INT" || globalTable->entries[i]->type == "FLOAT") {
		  assembly.push_back("var " + globalTable->entries[i]->name);
		  //std::cout << "var " << globalTable->entries[i]->name << std::endl;
	  } else if(globalTable->entries[i]->type == "STRING") {
		  assembly.push_back("str " + globalTable->entries[i]->name + " " + globalTable->entries[i]->value);
		  //std::cout << "str " << globalTable->entries[i]->name << " " << globalTable->entries[i]->value << std::endl;
	  }
  }

  for(std::list<IRNode>::iterator it=total->IRseq.begin();it!=total->IRseq.end();++it) {
	  generateASM((*it), assembly);
  	  //assembly.splice(assembly.end(),tmpasm);
  }

  for(std::list<std::string>::iterator it=assembly.begin();it!=assembly.end();++it) {
	  std::cout << (*it) << std::endl;
  }
  std::cout << "sys halt" << std::endl;
  return 0;
}

void generateASM(IRNode& ircode, std::list<std::string>& assembly) {
	if(ircode.op == "STOREI" || ircode.op == "STOREF") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
	} else if(ircode.op == "READI") {
		assembly.push_back("sys readi " + ircode.dest);
	} else if(ircode.op == "READF") {
		assembly.push_back("sys readf " + ircode.dest);
	} else if(ircode.op == "WRITEI") {
		assembly.push_back("sys writei " + ircode.src1);
	} else if(ircode.op == "WRITEF") {
		assembly.push_back("sys writer " + ircode.src1);
	} else if(ircode.op == "WRITES") {
		assembly.push_back("sys writes " + ircode.src1);
	} else if(ircode.op == "ADDI") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("addi " + ircode.src2 + " " + ircode.dest);
	} else if(ircode.op == "ADDF") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("addr " + ircode.src2 + " " + ircode.dest);
	} else if(ircode.op == "SUBI") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("subi " + ircode.src2 + " " + ircode.dest);
	} else if(ircode.op == "SUBF") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("subr " + ircode.src2 + " " + ircode.dest);
	} else if(ircode.op == "MULI") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("muli " + ircode.src2 + " " + ircode.dest);
	} else if(ircode.op == "MULF") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("mulr " + ircode.src2 + " " + ircode.dest);
	} else if(ircode.op == "DIVI") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("divi " + ircode.src2 + " " + ircode.dest);
	} else if(ircode.op == "DIVF") {
		assembly.push_back("move " + ircode.src1 + " " + ircode.dest);
		assembly.push_back("divr " + ircode.src2 + " " + ircode.dest);
	}

	return;
}


CodeObject* parseAST(ASTNode* root) {
	//POST-ORDER WALK: left, right, root
	CodeObject* left = NULL;
	CodeObject* right = NULL;

	if(root->type == "READ") {
		CodeObject* tmp = new CodeObject();
		ASTNode* idx = root->right;
		while(idx != NULL) {
			if(idx->type == "INT") {tmp->IRseq.push_back(IRNode("READI", "", "", idx->op));}
			else if(idx->type == "FLOAT") {tmp->IRseq.push_back(IRNode("READF", "", "", idx->op));}
			idx = idx->right;
		}
		return tmp;
	} else if(root->type == "WRITE") {
		CodeObject* tmp = new CodeObject();
		ASTNode* idx = root->right;
		while(idx != NULL) {
			if(idx->type == "INT") {tmp->IRseq.push_back(IRNode("WRITEI", idx->op, "", ""));}
			else if(idx->type == "FLOAT") {tmp->IRseq.push_back(IRNode("WRITEF", idx->op, "", ""));}
			else if(idx->type == "STRING") {tmp->IRseq.push_back(IRNode("WRITES", idx->op, "", ""));}
			idx = idx->right;
		}
		return tmp;
	}


	if(root->left != NULL) {
		left = parseAST(root->left);
	}
	if(root->right != NULL) {
		right = parseAST(root->right);
	}
	//do stuff
	if(root->left == NULL and root->right == NULL) {
		CodeObject* tmp = new CodeObject(root->op, root->type);
		return tmp;
	} else if(root->op == "+") {
		CodeObject* tmp = new CodeObject();
		tmp->IRseq.splice(tmp->IRseq.end(), left->IRseq);
		tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);
		std::ostringstream os;
		os << CodeObject::resultCt++;
		tmp->result = "r"+ os.str();
		tmp->type = left->type;

		if(tmp->type == "INT") {
			tmp->IRseq.push_back(IRNode("ADDI",left->result,right->result,tmp->result));
		} else if(tmp->type == "FLOAT") {
			tmp->IRseq.push_back(IRNode("ADDF",left->result,right->result,tmp->result));
		}
		return tmp;
	} else if(root->op == "-") {
		CodeObject* tmp = new CodeObject();
		tmp->IRseq.splice(tmp->IRseq.end(), left->IRseq);
		tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);
		std::ostringstream os;
		os << CodeObject::resultCt++;
		tmp->result = "r"+ os.str();
		tmp->type = left->type;

		if(tmp->type == "INT") {
			tmp->IRseq.push_back(IRNode("SUBI",left->result,right->result,tmp->result));
		} else if(tmp->type == "FLOAT") {
			tmp->IRseq.push_back(IRNode("SUBF",left->result,right->result,tmp->result));
		}
		return tmp;
	} else if(root->op == "*") {
		CodeObject* tmp = new CodeObject();
		tmp->IRseq.splice(tmp->IRseq.end(), left->IRseq);
		tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);
		std::ostringstream os;
		os << CodeObject::resultCt++;
		tmp->result = "r"+ os.str();
		tmp->type = left->type;

		if(tmp->type == "INT") {
			tmp->IRseq.push_back(IRNode("MULI",left->result,right->result,tmp->result));
		} else if(tmp->type == "FLOAT") {
			tmp->IRseq.push_back(IRNode("MULF",left->result,right->result,tmp->result));
		}
		return tmp;
	} else if(root->op == "/") {
		CodeObject* tmp = new CodeObject();
		tmp->IRseq.splice(tmp->IRseq.end(), left->IRseq);
		tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);
		std::ostringstream os;
		os << CodeObject::resultCt++;
		tmp->result = "r"+ os.str();
		tmp->type = left->type;

		if(tmp->type == "INT") {
			tmp->IRseq.push_back(IRNode("DIVI",left->result,right->result,tmp->result));
		} else if(tmp->type == "FLOAT") {
			tmp->IRseq.push_back(IRNode("DIVF",left->result,right->result,tmp->result));
		}
		return tmp;
	} else if(root->op == ":=") {
		CodeObject* tmp = new CodeObject();
		tmp->IRseq.splice(tmp->IRseq.end(), left->IRseq);
		tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);
		tmp->result = left->result;
		tmp->type = left->type;

		if(tmp->type == "INT") {
			tmp->IRseq.push_back(IRNode("STOREI",right->result, "", tmp->result));
		} else if(tmp->type == "FLOAT") {
			tmp->IRseq.push_back(IRNode("STOREF",right->result, "", tmp->result));
		}
		return tmp;
	}
	return NULL;
}


//To Delete list<A*> *listA
//while(!listA->empty()) delete listA->front(), listA->pop_front();
