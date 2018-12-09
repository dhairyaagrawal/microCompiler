#ifndef REGISTER_H
#define REGISTER_H

#include <string>
#include "table.h"

class Register{
public:
	Register();
	Register(int, std::string);
	virtual ~Register();

	virtual void isEmpty();
	virtual void isDirty();
	virtual void setDirty();
	virtual void clearDirty()
	virtual void setEmpty();
	virtual void clear();
	virtual int retRegNum();

    //Register * next;
    std::string variable;

private:
    bool dirty;
    bool empty;
    int regNum;
    static int regCount;
};

#endif /* REGISTER_H */
