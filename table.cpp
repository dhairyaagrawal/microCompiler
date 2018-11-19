/*
 * table.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: Dhairya
 */

#include <iostream>
#include <sstream>
#include "table.h"

table::table() {pos = 0; title = "";}
table::table(std::string head) : entries(), pos(0), title(head) {}
table::~table() {}

void table::add(table_entry newEntry) {
	for (std::vector<table_entry>::iterator it = entries.begin(); it != entries.end(); ++it) {
		if (newEntry.name == (*it).name) {
			std::cout << "Declaration error " + newEntry.name << std::endl;
			std::exit(1);
		}
	}
	entries.push_back(newEntry);
	return;
}

void table::print_table() {
	std::cout << title << std::endl;
	for (std::vector<table_entry>::iterator it = entries.begin(); it != entries.end(); ++it) {
		if ((*it).type == "STRING") {
			std::cout << "name " << (*it).name << " type STRING value" << (*it).type << std::endl;
		}
		else {
			std::cout << "name " << (*it).name << " type " << (*it).type << std::endl;
		}
	}
	return;
}

std::string table::search(std::string name) {
	for (std::vector<table_entry>::iterator it = entries.begin(); it != entries.end(); ++it) {
		if ((*it).name == name) {
			return (*it).type;
		}
	}
	return "";
}

std::string table::index(std::string name) {
	int count = 0;
	for (std::vector<table_entry>::iterator it = entries.begin(); it != entries.end(); ++it) {
		count++;
		if ((*it).name == name) {
			std::stringstream ss;
			count = table::pos - count;
			if(count >= 0) {
				count++;
			}
			ss << count;
			return "$" +ss.str();
		}
	}
	return "";
}
