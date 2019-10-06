/*
	This is the phoneBook and contains phoneBookEntry values. You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook
*/
#include "phoneBook.h"
#include <iostream>
#include <vector>
phoneBook::phoneBook() {}

using namespace std;

void phoneBook::insert(const phoneBookEntry& entry) {
	int sameName = containsName(entry.name());
	cout << sameName << endl;
	if (sameName >= 0) {
		entries.at(sameName) = entry;
	}
	else {
		entries.push_back(entry);
	}
}

void phoneBook::insert(const std::string& name, const std::string& number, const std::string& email) {
	phoneBookEntry tempEntry(name, number, email);
	int sameName = containsName(tempEntry.name());
	if (sameName >= 0) {
		entries.at(sameName) = tempEntry;
	}
	else {
		entries.push_back(tempEntry);
	}
}

void phoneBook::insert(const std::string& name, const std::string& number) {
	phoneBookEntry tempEntry(name, number);
	int sameName = containsName(tempEntry.name());
	if (sameName >= 0) {
		entries.at(sameName) = tempEntry;
	}
	else {
		entries.push_back(tempEntry);
	}
}

bool phoneBook::erase(std::string name) { 

}

bool phoneBook::find(std::string name) { return false; }

void phoneBook::print() const {}

void phoneBook::print(std::ostream& out) const {}

void phoneBook::debug(std::ostream& out) const {}

std::size_t phoneBook::size() const { return 10; }

typedef std::vector<phoneBookEntry> phoneBookEntryList;
typedef phoneBook::phoneBookEntryList::iterator iterator;
typedef phoneBook::phoneBookEntryList::const_iterator const_iterator;

//phoneBook::iterator phoneBook::begin() {}

//phoneBook::iterator phoneBook::end() {}

int phoneBook::containsName(string nameIn) {
	for (int i = 0; i < entries.size(); i++) {
		if (entries.at(i).name() == nameIn) {
			return i;
		}
	}

	return -1;
}