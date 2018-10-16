#ifndef IRNODE_H_
#define IRNODE_H_

#include <string>

class IRNode {
public:
    IRNode(std::string,std::string,std::string,std::string);
    virtual ~IRNode();

    std::string op;
    std::string src1;
    std::string src2;
    std::string dest;
};

#endif /* IRNODE_H_ */
