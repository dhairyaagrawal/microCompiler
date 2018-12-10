#ifndef REGISTER_H_
#define REGISTER_H_

#include <string>

class Register {
public:
	Register();
	virtual ~Register();

	virtual std::string getsetRegNum();
	virtual void setClean(std::string);

private:
    bool empty0;
    bool empty1;
    bool empty2;
    bool empty3;
};

#endif /* REGISTER_H_ */
