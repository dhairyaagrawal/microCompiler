#include "Register.h"
#include <iostream>

Register::regCount = 0;

Register::Register() :  regNum(++regCount), empty(true), dirty(false), variable("") {}
Register::Register(std::string val) :  regNum(++regCount), empty(false), dirty(false), variable(val) {}

Register::~Register() {}

Register::isEmpty() {return empty;}
Register::isDirty() {return dirty;}
Register::setDirty() {dirty = true;}
Register::setEmpty() {empty = true;}
Register::clear() {dirty = false; empty = true; variable = ""}
Register::clearDirty() {dirty = false;}
Register::retRegNum() {return regNum;}
