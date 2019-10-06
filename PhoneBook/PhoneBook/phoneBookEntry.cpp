/*
		This class will represent an entry in the phone book. It contains the name, phone number and e-mail address

		This class will contain three std::string values for name, phone number and e-mail address
*/

#include "phoneBookEntry.h"
#include <iostream>

phoneBookEntry::phoneBookEntry() {
	this->currName = "";
	this->currNumber = "";
	this->currEmail = "";
}

phoneBookEntry::phoneBookEntry(const std::string& name, const std::string& number) {
	this->currName = name;
	this->currNumber = number;
}

phoneBookEntry::phoneBookEntry(const std::string& name, const std::string& number, const std::string& email) {
	this->currName = name;
	this->currNumber = number;
	this->currEmail = email;
}

phoneBookEntry::phoneBookEntry(const phoneBookEntry& from) {
	this->currName = from.name();
	this->currNumber = from.phoneNumber();
	this->currEmail = from.email();
} //Copy Construtor

std::string phoneBookEntry::name() const { 
	return currName;
}

std::string phoneBookEntry::phoneNumber() const { 
	return currNumber;
}

std::string phoneBookEntry::email() const { 
	return currEmail;
}

void phoneBookEntry::phoneNumber(const std::string& newNumber) { 
	this->currNumber = newNumber;
}

void phoneBookEntry::email(const std::string& newEmail) { 
	this->currEmail = newEmail;
}