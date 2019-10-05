/*
		This class will represent an entry in the phone book. It contains the name, phone number and e-mail address

		Notes:

		This class will contain three std::string values for name, phone number and e-mail address

		cannot change the name member data
*/
#pragma once

#include <string>

class phoneBookEntry{
public: 
	phoneBookEntry();
	phoneBookEntry(const std::string& name, const std::string& number);\
	phoneBookEntry(const std::string& name, const std::string& number, const std::string& email);
	phoneBookEntry(const phoneBookEntry& from); //Copy Construtor
	std::string name() const;
	std::string phoneNumber() const;
	std::string email() const;
	void phoneNumber(const std::string& newNumber);
	void email(const std::string& newEmail);
};