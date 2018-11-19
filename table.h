/*
 * table.h
 *
 *  Created on: Oct 5, 2018
 *      Author: Dhairya
 */

#ifndef TABLE_H_
#define TABLE_H_

#include "table_entry.h"
#include <string>
#include <vector>

class table {
public:
	table();
	table(std::string);
	virtual ~table();
	void print_table();
	void add(table_entry);
	std::string search(std::string);
	std::string index(std::string);
	std::string search_Stack(std::string name);

	std::vector<table_entry> entries;
	int pos;
	std::string title;
};

#endif /* TABLE_H_ */
