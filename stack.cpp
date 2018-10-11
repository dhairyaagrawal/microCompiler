/*
 * stack.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: Dhairya
 */

#include "stack.h"

stack::stack() : tables(), tableCt(0) {}
stack::~stack() {
	for(int i = 0; i < tableCt; i++) {
		delete tables[i];
	}
	tableCt = 0;
}

void stack::push(table* currTable) {
	tables[tableCt++] = currTable;
	return;
}

table* stack::pop() {
	if(tableCt != 0) {
		table* toRet = tables[--tableCt];
		return toRet;
	} else {
		return NULL;
	}
}
