/*
	This is the phoneBook and contains phoneBookEntry values. You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook.
*/
#include "phoneBook.h"
#include <iostream>
#include <vector>

phoneBook::phoneBook() {}

/*
	Adds a new entry to the entries vector by sending in a phoneBookEntry object reference as the parameter.
*/
void phoneBook::insert(const phoneBookEntry &entry) {
	linkedList<phoneBookEntry>::iterator sameName = containsName(entry.name());
	if (sameName == entries.end()) {
		entries.insert(entry);
	}
	else {
		(*sameName).email(entry.email());
		(*sameName).phoneNumber(entry.phoneNumber());
	}
}

/*
	Adds a new entry to the entries vector by creating a new phoneBookEntry object using the name, number and email string references sent in as paramters.
*/
void phoneBook::insert(const std::string &name, const std::string &number, const std::string &email) {
	linkedList<phoneBookEntry>::iterator sameName = containsName(name);
	if (sameName == entries.end()) {
		entries.insert(phoneBookEntry(name, number, email));
	}
	else {
		(*sameName).email(email);
		(*sameName).phoneNumber(number);
	}
}

/*
	Adds a new entry to the entries vector by creating a new phoneBookEntry object using the name and number string references sent in as paramters.
*/
void phoneBook::insert(const std::string& name, const std::string& number) {
	linkedList<phoneBookEntry>::iterator sameName = containsName(name);
	if (sameName == entries.end()) {
		entries.insert(phoneBookEntry(name, number));
	}
	else {
		(*sameName).phoneNumber(number);
	}
}

/*
	Erases an entry based on its name from the entries vector.
	Returns true if an entry was erased, and false if an entry was not erased.
*/
bool phoneBook::erase(std::string name) {
	linkedList<phoneBookEntry>::iterator sameName = containsName(name);
	if (sameName == entries.end()) {
		return false;
	}
	else {
		entries.erase(sameName);
		return true;
	}
}

/*
	Finds whether or not there exists an entry with a name that matches the one sent in as a parameter.
	Returns true if there does exist an entry with a name that matches the one sent in as a parameter, and false if not.
*/
bool phoneBook::find(std::string name) {
	linkedList<phoneBookEntry>::iterator sameName = containsName(name);
	if (sameName == entries.end()) {
		return false;
	}
	else {
		return true;
	}
}

/*
	Prints the contents of the entries vector in a structured manner. Uses cout as the output stream.
*/
void phoneBook::print() const {
	std::cout << "Name:                          Phone Number:   E-Mail:" << std::endl;
	for (linkedList<phoneBookEntry>::iterator iter = entries.begin(); iter != entries.end(); iter++) {
		std::string name = "                               ";
		for (unsigned int i = 0; i < (*iter).name().size(); i++) {
			name[i] = (*iter).name()[i];
		}
		std::string number = "                ";
		for (unsigned int i = 0; i < (*iter).phoneNumber().size(); i++) {
			number[i] = (*iter).phoneNumber()[i];
		}
		std::string email = (*iter).email();

		std::cout << name << number << email << std::endl;
	}
}

/*
	Prints the contents of the entries vector in a structured manner. Uses ostream parameter as the output stream.
*/
void phoneBook::print(std::ostream& out) const {
	out << "Name:                          Phone Number:   E-Mail:" << std::endl;
	for (linkedList<phoneBookEntry>::iterator iter = entries.begin(); iter != entries.end(); iter++) {
		std::string name = "                               ";
		for (unsigned int i = 0; i < (*iter).name().size(); i++) {
			name[i] = (*iter).name()[i];
		}
		std::string number = "                ";
		for (unsigned int i = 0; i < (*iter).phoneNumber().size(); i++) {
			number[i] = (*iter).phoneNumber()[i];
		}
		std::string email = (*iter).email();

		out << name << number << email << std::endl;
	}
}

/*
	Prints the entries vector for debug purposes.
*/
void phoneBook::debug(std::ostream& out) const {
	entries.debug(out);
}

/*
	Returns the size of the entries vector.
*/
std::size_t phoneBook::size() const {
	return entries.size();
}

/*
	Returns the index of the entry that has the same name as the parameter. Returns -1 if there is no name that is equal to the parameter.
*/
linkedList<phoneBookEntry>::iterator phoneBook::containsName(std::string nameIn) {
	for (linkedList<phoneBookEntry>::iterator iter = entries.begin(); iter != entries.end(); iter++) {
		if ((*iter).name() == nameIn) {
			return entries.find(*iter);
		}
	}
	return entries.end();
}