#include "ASTNode.h"
#include <iostream>

ASTNode::ASTNode(std::string op_val) :  left(NULL), right(NULL), op(op_val), type("z"), entryPt(NULL) {}
ASTNode::ASTNode(std::string op_val, std::string type_val) :  left(NULL), right(NULL), op(op_val), type(type_val), entryPt(NULL) {}
ASTNode::ASTNode(ASTNode* left_val, ASTNode* right_val, std::string op_val, std::string type_val, table* symbolPt) : left(left_val), right(right_val), op(op_val), type(type_val), entryPt(symbolPt) {}

ASTNode::~ASTNode() {
    if(left != NULL) {delete left;}
    if(right != NULL) {delete right;}
}

void ASTNode::print() {
	if(type == "READ" or type == "WRITE") {
		std::cout << type << " ";
		ASTNode* tmp = right;
		while(tmp != NULL) {
			std::cout << tmp->op << "(" << tmp->type << ") ";
			tmp = tmp->right;
		}
		return;
	}

	if(left == NULL and right == NULL) {
		std::cout << op << "(" << type << ")";
		return;
	}
	left->print();
	std::cout << op << "(" << type << ")";
	right->print();

	return;
}
