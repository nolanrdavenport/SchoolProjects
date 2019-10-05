/*
		This class will represent an entry in the phone book. It contains the name, phone number and e-mail address

		This class will contain three std::string values for name, phone number and e-mail address
*/

#include "phoneBookEntry.h"

phoneBookEntry::phoneBookEntry() {}

phoneBookEntry::phoneBookEntry(const std::string& name, const std::string& number) {}

phoneBookEntry::phoneBookEntry(const std::string& name, const std::string& number, const std::string& email) {}

phoneBookEntry::phoneBookEntry(const phoneBookEntry& from) {} //Copy Construtor

std::string phoneBookEntry::name() const {}

std::string phoneBookEntry::phoneNumber() const {}

std::string phoneBookEntry::email() const {}

void phoneBookEntry::phoneNumber(const std::string& newNumber) {}

void phoneBookEntry::email(const std::string& newEmail) {}
