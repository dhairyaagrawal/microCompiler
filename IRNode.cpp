#include "IRNode.h"

IRNode::IRNode(std::string op_val, std::string source1, std::string source2, std::string dest_val) : op(op_val), src1(source1), src2(source2), dest(dest_val) {}
IRNode::~IRNode() {}
