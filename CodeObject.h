#ifndef CODEOBJECT_H_
#define CODEOBJECT_H_

#include <string>
#include <list>
//#include <vector>
#include "IRNode.h"

class CodeObject {
public:
    CodeObject();
    CodeObject(std::string,std::string);
    virtual ~CodeObject();
    virtual void print();

    std::list<IRNode> IRseq;
    std::string result;
    std::string type;
    static int resultCt;
	static int ifCt;
	static int whileCt;
	//static std::vector<std::string> labels;
};

#endif /* CODEOBJECT_H_ */
