#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <string>
#include "table.h"

class ASTNode {
public:
    ASTNode(std::string);
    ASTNode(std::string, std::string);
    ASTNode(ASTNode*, ASTNode*, std::string, std::string, table*);
    virtual ~ASTNode();
    virtual void print();

    ASTNode * left;
    ASTNode * right;
    std::string op;
    std::string type;
    table* entryPt;
};

#endif /* ASTNODE_H_ */
