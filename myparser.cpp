#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <list>
#include <vector>
#include <deque>
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
std::vector<std::string> labels;
std::deque<std::string> args;
int pop_count = 0;

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
  table globalTable = myStack->tables[0]; //global scope variables only for step4
  for(int i = 0; i < globalTable.entries.size(); i++) {
	  if(globalTable.entries[i].type == "INT" || globalTable.entries[i].type == "FLOAT") {
		  assembly.push_back("var " + globalTable.entries[i].name);
		  //std::cout << "var " << globalTable.entries[i]->name << std::endl;
	  } else if(globalTable.entries[i].type == "STRING") {
		  assembly.push_back("str " + globalTable.entries[i].name + " " + globalTable.entries[i].value);
		  //std::cout << "str " << globalTable.entries[i]->name << " " << globalTable.entries[i]->value << std::endl;
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
		assembly.push_back("sys readr " + ircode.dest);
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
	} else if(ircode.op == "LABEL") {
		assembly.push_back("label " + ircode.dest);
	} else if(ircode.op == "JUMP") {
		assembly.push_back("jmp " + ircode.dest);
	} else if(ircode.op == "GTI") {
		assembly.push_back("cmpi " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jle " + ircode.dest);
	} else if(ircode.op == "GTF") {
		assembly.push_back("cmpr " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jle " + ircode.dest);
	} else if(ircode.op == "GEI") {
		assembly.push_back("cmpi " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jlt " + ircode.dest);
	} else if(ircode.op == "GEF") {
		assembly.push_back("cmpr " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jlt " + ircode.dest);
	} else if(ircode.op == "LTI") {
		assembly.push_back("cmpi " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jge " + ircode.dest);
	} else if(ircode.op == "LTF") {
		assembly.push_back("cmpr " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jge " + ircode.dest);
	} else if(ircode.op == "LEI") {
		assembly.push_back("cmpi " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jgt " + ircode.dest);
	} else if(ircode.op == "LEF") {
		assembly.push_back("cmpr " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jgt " + ircode.dest);
	} else if(ircode.op == "NEI") {
		assembly.push_back("cmpi " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jeq " + ircode.dest);
	} else if(ircode.op == "NEF") {
		assembly.push_back("cmpr " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jeq " + ircode.dest);
	} else if(ircode.op == "EQI") {
		assembly.push_back("cmpi " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jne " + ircode.dest);
	} else if(ircode.op == "EQF") {
		assembly.push_back("cmpr " + ircode.src1 + " " + ircode.src2);
		assembly.push_back("jne " + ircode.dest);
	}

	return;
}

CodeObject* parseAST(ASTNode* root) {
	//POST-ORDER WALK: left, right, root
	CodeObject* left = NULL;
	CodeObject* right = NULL;

  std::cout << root->op << std::endl;

  if(root->type == "PUSHREGS") {
    CodeObject* tmp = new CodeObject();
    tmp->IRseq.push_back(IRNode("PUSH", "", "", ""));
    tmp->IRseq.push_back(IRNode("PUSHREGS", "", "", ""));
    while(!args.empty()) {
      tmp->IRseq.push_back(IRNode("PUSHREG", "", "", args.front()));
      args.pop_front();
    }
    return tmp;
  }
  if(root->type == "ARG") {
    CodeObject* tmp = new CodeObject();
    right = parseAST(root->right);
    tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);
    args.push_back(right->result);
    pop_count++;
    //tmp->IRseq.push_back(IRNode("PUSH", "", "", right->result));
    return tmp;
  }
  if(root->type == "FUNC") {
    CodeObject* tmp = new CodeObject();
    tmp->IRseq.push_back(IRNode("LABEL", "", "", "FUNC_" + root->op));
    return tmp;
  }
  if(root->op == "POP") {
    CodeObject* tmp = new CodeObject();
    left = parseAST(root->left);
    right = parseAST(root->right);

    tmp->IRseq.push_back(IRNode("FUNC", "", "", "FUNC_" + right->result));
    while(pop_count != 0) {
      tmp->IRseq.push_back(IRNode("POP", "", "", ""));
      pop_count--;
    }
    tmp->IRseq.push_back(IRNode("POPREGS", "", "", ""));

    std::ostringstream os;
    os << CodeObject::resultCt++;
    tmp->result = "r"+ os.str();
    tmp->IRseq.push_back(IRNode("RTV", tmp->result, left->result, ""));
    return tmp;
  }
  if(root->type == "LINK") {
    CodeObject* tmp = new CodeObject();
    tmp->IRseq.push_back(IRNode("LINK", "", "", root->op));
    return tmp;
  }
  if(root->type == "END") {
    CodeObject* tmp = new CodeObject();
    tmp->IRseq.push_back(IRNode("END_RETURN", "", "", ""));
    return tmp;
  }
  if(root->type == "RETURN") {
    CodeObject* tmp = new CodeObject();
    right = parseAST(root->right);
    tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);
    std::string value;
    if(root->op == "6") {
      value = "0";
      tmp->IRseq.push_back(IRNode("END_RETURN", "", "", ""));
    }
    else {
      value = root->op;
      tmp->IRseq.push_back(IRNode("RETURN", right->result, "", value));
      tmp->IRseq.push_back(IRNode("END_RETURN", "", "", ""));
    }
    return tmp;
  }
	if(root->type == "IF") {
		CodeObject* tmp = new CodeObject();
		std::string cond;
		left = parseAST(root->left);
		right = parseAST(root->right);
		if (root->op == ">") { if(root->left->type == "INT") {cond = "GTI";} else if(root->left->type == "FLOAT") {cond = "GTF";} }
		else if (root->op == ">=") { if(root->left->type == "INT") {cond = "GEI";} else if(root->left->type == "FLOAT") {cond = "GEF";} }
		else if (root->op == "<") { if(root->left->type == "INT") {cond = "LTI";} else if(root->left->type == "FLOAT") {cond = "LTF";} }
		else if (root->op == "<=") { if(root->left->type == "INT") {cond = "LEI";} else if(root->left->type == "FLOAT") {cond = "LEF";} }
		else if (root->op == "!=") { if(root->left->type == "INT") {cond = "NEI";} else if(root->left->type == "FLOAT") {cond = "NEF";} }
		else if (root->op == "=") { if(root->left->type == "INT") {cond = "EQI";} else if(root->left->type == "FLOAT") {cond = "EQF";} }
		else { cond = "Error"; };

    std::ostringstream os;
		os << CodeObject::resultCt++;
		std::string strtmp = "r"+ os.str();

		tmp->IRseq.splice(tmp->IRseq.end(), left->IRseq);
		tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);

		std::ostringstream ostmp;
		ostmp << CodeObject::ifCt++;
		labels.push_back("ELSE_" + ostmp.str());
        tmp->IRseq.push_back(IRNode("STOREI", right->result, "", strtmp));
		tmp->IRseq.push_back(IRNode(cond, left->result, strtmp, "ELSE_" + ostmp.str()));
		return tmp;
	}
	if (root->type == "ENDIF") {
		CodeObject* tmp = new CodeObject();
		tmp->IRseq.push_back(IRNode("LABEL", "", "", labels.back()));
		labels.pop_back();
		return tmp;
	}
	if (root->type == "ELSE") {
		CodeObject* tmp = new CodeObject();
		std::ostringstream os;
		os << CodeObject::ifCt++;
		tmp->IRseq.push_back(IRNode("JUMP", "", "", "END_IF_ELSE" + os.str()));
		tmp->IRseq.push_back(IRNode("LABEL", "", "", labels.back()));
		labels.pop_back();
		labels.push_back("END_IF_ELSE" + os.str());
		return tmp;
	}
	if (root->type == "WHILE") {
		CodeObject* tmp = new CodeObject();
        left = parseAST(root->left);
        right = parseAST(root->right);

		std::string cond;
		std::ostringstream os;
		os << CodeObject::whileCt++;

		std::ostringstream ostmp;
		ostmp << CodeObject::resultCt++;
		std::string strtmp = "r"+ ostmp.str();
		tmp->IRseq.push_back(IRNode("STOREI", right->result, "", strtmp));
		tmp->IRseq.push_back(IRNode("LABEL", "", "", "WHILE_START_"+ os.str()));

    if (root->op == ">") { if(root->left->type == "INT") {cond = "GTI";} else if(root->left->type == "FLOAT") {cond = "GTF";} }
		else if (root->op == ">=") { if(root->left->type == "INT") {cond = "GEI";} else if(root->left->type == "FLOAT") {cond = "GEF";} }
		else if (root->op == "<") { if(root->left->type == "INT") {cond = "LTI";} else if(root->left->type == "FLOAT") {cond = "LTF";} }
		else if (root->op == "<=") { if(root->left->type == "INT") {cond = "LEI";} else if(root->left->type == "FLOAT") {cond = "LEF";} }
		else if (root->op == "!=") { if(root->left->type == "INT") {cond = "NEI";} else if(root->left->type == "FLOAT") {cond = "NEF";} }
		else if (root->op == "=") { if(root->left->type == "INT") {cond = "EQI";} else if(root->left->type == "FLOAT") {cond = "EQF";} }
		else { cond = "Error"; };
		tmp->IRseq.splice(tmp->IRseq.end(), left->IRseq);
		tmp->IRseq.splice(tmp->IRseq.end(), right->IRseq);

		std::ostringstream ostr;
		ostr << CodeObject::whileCt++;

		tmp->IRseq.push_back(IRNode(cond, left->result, strtmp, "WHILE_END_" + ostr.str()));
		labels.push_back("WHILE_END_" + ostr.str());
		labels.push_back("WHILE_START_" + os.str());
		return tmp;
	}
	if (root->type == "ENDWHILE") {
		CodeObject* tmp = new CodeObject();
		tmp->IRseq.push_back(IRNode("JUMP", "", "", labels.back()));
		labels.pop_back();
		tmp->IRseq.push_back(IRNode("LABEL", "", "", labels.back()));
		labels.pop_back();
		return tmp;
	}

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

		std::ostringstream os;
		os << CodeObject::resultCt++;
		std::string tmpresult = "r"+ os.str();
		if(tmp->type == "INT") {
			tmp->IRseq.push_back(IRNode("STOREI",right->result, "", tmpresult));
			tmp->IRseq.push_back(IRNode("STOREI",tmpresult, "", tmp->result));
		} else if(tmp->type == "FLOAT") {
			tmp->IRseq.push_back(IRNode("STOREF",right->result, "", tmpresult));
			tmp->IRseq.push_back(IRNode("STOREF",tmpresult, "", tmp->result));
		}
		return tmp;
	}
	return NULL;
}


//To Delete list<A*> *listA
//while(!listA->empty()) delete listA->front(), listA->pop_front();
//{myStack->push(currTable); os.str(""); os << scope++; currTable = table("Symbol table BLOCK " + os.str());}
