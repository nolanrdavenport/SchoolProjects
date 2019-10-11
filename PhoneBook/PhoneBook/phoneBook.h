#pragma once
#include <string>
#include <vector>
#include "phoneBookEntry.h"

/*
	This is the phoneBook and contains phoneBookEntry values. You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook.
*/
class phoneBook {
public:
	phoneBook();
	void insert(const phoneBookEntry& entry);
	void insert(const std::string& name, const std::string& number, const std::string& email);
	void insert(const std::string& name, const std::string& number);
	bool erase(std::string name);
	bool find(std::string name);
	void print() const;
	void print(std::ostream& out) const;
	void debug(std::ostream& out) const;
	std::size_t size() const;
	typedef std::vector<phoneBookEntry> phoneBookEntryList;
	typedef phoneBookEntryList::iterator iterator;
	typedef phoneBookEntryList::const_iterator const_iterator;
	iterator itr;
	iterator b;
	iterator e;
	void recalculateIteratorEnds();
	iterator begin();
	iterator end();
	int containsName(std::string nameIn);
private:
	phoneBookEntryList entries;
};
