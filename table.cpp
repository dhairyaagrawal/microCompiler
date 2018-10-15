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
	for(int i = 0; i < entryCt; i++) {
		if(newEntry->name == entries[i]->name) {
			std::cout << "DECLARATION ERROR " + newEntry->name << std::endl;
			exit(1);
		}
	}
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

std::string table::search(std::string name) {
	for(int i = 0; i < entryCt; i++) {
		if(entries[i]->name == name) {
			return entries[i]->type;
		}
	}
	return "";
}
