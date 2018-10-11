/*
 * table.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: Dhairya
 */

#include <iostream>
#include "table.h"

table::table(std::string head) : entries(), entryCt(0), title(head) {}
table::~table() {
	for(int i = 0; i < entryCt; i++) {
		delete entries[i];
	}
	entryCt = 0;
	title = "";
}

void table::add(table_entry* newEntry) {
	entries[entryCt++] = newEntry;
	return;
}

void table::print_table() {
	std::cout << title << std::endl;
	for(int i = 0; i < entryCt; i++) {
		if(entries[i]->type == "STRING") {
			std::cout << "name " << entries[i]->name << " type STRING value " << entries[i]->value << std::endl;
		} else {
			std::cout << "name " << entries[i]->name << " type " << entries[i]->type << std::endl;
		}
	}
	return;
}
