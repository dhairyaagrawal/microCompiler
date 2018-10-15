#include "ASTNode.h"
#include <iostream>

ASTNode::ASTNode(std::string op_val) :  left(nullptr), right(nullptr), op(op_val), type("z"), entryPt(nullptr) {}

ASTNode::ASTNode(ASTNode* left_val, ASTNode* right_val, std::string op_val, std::string type_val, table_entry* symbolPt) : left(left_val), right(right_val), op(op_val), type(type_val), entryPt(symbolPt) {}

ASTNode::~ASTNode() {
    delete left;
    delete right;
}

void ASTNode::print() {
	if(type == "READ" or type == "WRITE") {
		std::cout << type << " ";
		ASTNode* tmp = this;
		while(tmp != nullptr) {
			std::cout << tmp->op << ",";
			tmp = tmp->right;
		}
		return;
	}

	if(left == nullptr and right == nullptr) {
		std::cout << op;
		return;
	}
	left->print();
	std::cout << op;
	right->print();

	return;
}
