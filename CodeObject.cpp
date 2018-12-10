#include "CodeObject.h"
#include <iostream>

int CodeObject::resultCt = 0;
int CodeObject::ifCt = 1;
int CodeObject::whileCt = 1;

//Register CodeObject::regFile();

CodeObject::CodeObject() {}
CodeObject::CodeObject(std::string res, std::string type_val) {
	result = res;
	type = type_val;
}

CodeObject::~CodeObject() {}

void CodeObject::print() {
	for(std::list<IRNode>::iterator it=IRseq.begin();it!=IRseq.end();++it) {
		std::cout << ";" << (*it).op << " " << (*it).src1 << " " << (*it).src2 << " " << (*it).dest << std::endl;
	}
}
