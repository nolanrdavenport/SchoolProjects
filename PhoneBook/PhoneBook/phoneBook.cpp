/*
	This is the phoneBook and contains phoneBookEntry values. You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook
*/
#include "phoneBook.h"
#include <vector>
phoneBook::phoneBook() {}

void phoneBook::insert(const phoneBookEntry& entry) {}

void phoneBook::insert(const std::string& name, const std::string& number, const std::string& email) {}

void phoneBook::insert(const std::string& name, const std::string& number) {}

bool phoneBook::erase(std::string name) { return false; }

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