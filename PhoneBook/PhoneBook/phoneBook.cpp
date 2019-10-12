/*
	This is the phoneBook and contains phoneBookEntry values. You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook.
*/
#include "phoneBook.h"
#include <iostream>
#include <vector>

phoneBook::phoneBook() {}

/*
	Allows for the use of iterators in constant functions.
*/
void phoneBook::recalculateIteratorEnds() {
	b = begin();
	e = end();
}

/*
	Adds a new entry to the entries vector by sending in a phoneBookEntry object reference as the parameter.
*/
void phoneBook::insert(const phoneBookEntry &entry) {
	int sameName = containsName(entry.name());
	if (sameName >= 0) {
		entries.at(sameName) = entry;
	}
	else {
		entries.push_back(entry);
	}

	recalculateIteratorEnds();
}

/*
	Adds a new entry to the entries vector by creating a new phoneBookEntry object using the name, number and email string references sent in as paramters.
*/
void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email) {
	phoneBookEntry tempEntry(name, number, email);
	int sameName = containsName(tempEntry.name());
	if (sameName >= 0) {
		entries.at(sameName) = tempEntry;
	}
	else {
		entries.push_back(tempEntry);
	}

	recalculateIteratorEnds();
}

/*
	Adds a new entry to the entries vector by creating a new phoneBookEntry object using the name and number string references sent in as paramters.
*/
void phoneBook::insert(const std::string& name, const std::string& number) {
	phoneBookEntry tempEntry(name, number);
	int sameName = containsName(tempEntry.name());
	if (sameName >= 0) {
		entries.at(sameName) = tempEntry;
	}
	else {
		entries.push_back(tempEntry);
	}

	recalculateIteratorEnds();
}

/*
	Erases an entry based on its name from the entries vector.
	Returns true if an entry was erased, and false if an entry was not erased.
*/
bool phoneBook::erase(std::string name) {
	for (itr = begin(); itr != end(); itr++) {
		if ((*itr).name() == name) {
			entries.erase(itr);
			recalculateIteratorEnds();
			return true;
		}
	}
	recalculateIteratorEnds();
	return false;
}

/*
	Finds whether or not there exists an entry with a name that matches the one sent in as a parameter.
	Returns true if there does exist an entry with a name that matches the one sent in as a parameter, and false if not.
*/
bool phoneBook::find(std::string name) {
	for (itr = begin(); itr != end(); itr++) {
		if ((*itr).name() == name) {
			return true;
		}
	}
	return false;
}

/*
	Prints the contents of the entries vector in a structured manner. Uses cout as the output stream.
*/
void phoneBook::print() const {
	std::cout << "Name:                          Phone Number:   E-Mail:" << std::endl;
	iterator itr;
	for (itr = b; itr != e; itr++) {
		std::string name = "                               ";
		for (unsigned int i = 0; i < (*itr).name().size(); i++) {
			name[i] = (*itr).name()[i];
		}
		std::string number = "                ";
		for (unsigned int i = 0; i < (*itr).phoneNumber().size(); i++) {
			number[i] = (*itr).phoneNumber()[i];
		}
		std::string email = (*itr).email();

		std::cout << name << number << email << std::endl;
	}
}

/*
	Prints the contents of the entries vector in a structured manner. Uses ostream parameter as the output stream.
*/
void phoneBook::print(std::ostream& out) const {
	out << "Name:                          Phone Number:   E-Mail:" << std::endl;
	iterator itr;
	for (itr = b; itr != e; itr++) {
		std::string name = "                               ";
		for (unsigned int i = 0; i < (*itr).name().size(); i++) {
			name[i] = (*itr).name()[i];
		}
		std::string number = "                ";
		for (unsigned int i = 0; i < (*itr).phoneNumber().size(); i++) {
			number[i] = (*itr).phoneNumber()[i];
		}
		std::string email = (*itr).email();

		out << name << number << email << std::endl;
	}
}

/*
	Prints the entries vector for debug purposes.
*/
void phoneBook::debug(std::ostream& out) const {
	iterator itr;
	for (itr = b; itr != e; itr++) {
		out << (*itr).name() << " | " << (*itr).phoneNumber() << " | " << (*itr).email() << std::endl;
	}
}

/*
	Returns the size of the entries vector.
*/
std::size_t phoneBook::size() const {
	return entries.size();
}

/*
	Returns the begin iterator from the entries vector.
*/
phoneBook::iterator phoneBook::begin() {
	return entries.begin();
}

/*
	Returns the end iterator from the entries vector.
*/
phoneBook::iterator phoneBook::end() {
	return entries.end();
}

/*
	Returns the index of the entry that has the same name as the parameter. Returns -1 if there is no name that is equal to the parameter.
*/
int phoneBook::containsName(std::string nameIn) {
	for (itr = begin(); itr != end(); itr++) {
		if ((*itr).name() == nameIn) {
			return itr - begin();
		}
	}

	return -1;
}