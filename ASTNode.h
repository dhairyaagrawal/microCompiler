#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <string>
#include "table_entry.h"

class ASTNode {
public:
    ASTNode(std::string);
    ASTNode(ASTNode*, ASTNode*, std::string, std::string, table_entry*);
    virtual ~ASTNode();
    virtual void print();

    ASTNode * left;
    ASTNode * right;
    std::string op;
    std::string type;
    table_entry * entryPt;
};

#endif /* ASTNODE_H_ */
