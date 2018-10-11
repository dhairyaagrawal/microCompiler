/*
 * table_entry.h
 *
 *  Created on: Oct 5, 2018
 *      Author: Dhairya
 */

#ifndef TABLE_ENTRY_H_
#define TABLE_ENTRY_H_

#include <string>

class table_entry {
public:
	table_entry(std::string, std::string, std::string);
	virtual ~table_entry();

	std::string type;
	std::string name;
	std::string value;
};

#endif /* TABLE_ENTRY_H_ */
