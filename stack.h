/*
 * stack.h
 *
 *  Created on: Oct 5, 2018
 *      Author: Dhairya
 */

#ifndef STACK_H_
#define STACK_H_

#include "table.h"

class stack {
public:
	stack();
	virtual ~stack();
	void push(table);
	table pop();

	table tables[1000];
	int tableCt;
};

#endif /* STACK_H_ */
