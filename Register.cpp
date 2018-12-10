#include "Register.h"
#include <iostream>

Register::Register() : empty0(true), empty1(true), empty2(true), empty3(true) {}
//Register::Register(std::string val) :  regNum(++regCount), empty(false), dirty(false), variable(val) {}

Register::~Register() {}

std::string Register::getsetRegNum() {
	if(empty0) {empty0 = false; /*dirty0 = false; variable0 = toStore;*/ return "r0";}
	else if(empty1) {empty1 = false; /*dirty1 = false; variable1 = toStore;*/ return "r1";}
	else if(empty2) {empty2 = false; /*dirty2 = false; variable2 = toStore;*/ return "r2";}
	else if(empty3) {empty3 = false; /*dirty3 = false; variable3 = toStore;*/ return "r3";}
	else {return "full";}
}

void Register::setClean(std::string toClean) {
	if(toClean == "r0") {
		empty0 = true;
	} else if(toClean == "r1") {
		empty1 = true;
	} else if(toClean == "r2") {
		empty2 = true;
	} else if(toClean == "r3") {
		empty3 = true;
	}
}
