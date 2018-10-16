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

class table {
public:
	table(std::string);
	virtual ~table();
	void print_table();
	void add(table_entry*);
	std::string search(std::string);

	table_entry* entries[1000];
	int entryCt;
	std::string title;
};

#endif /* TABLE_H_ */
