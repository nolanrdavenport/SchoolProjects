/*
	This command will add a new entry if the passed in name is not already in the phoneBook. Otherwise it will update and existing phoneBookEntry
*/
#include "addUpdateCommand.h"

using namespace std;

addUpdateCommand::addUpdateCommand(phoneBook& bookIn, std::istream& in, std::ostream& out) : bookCommand(in, out), book(bookIn){
	// any other code you may need
}

void addUpdateCommand::execute() {
	string newName = prompt("Enter name to add/update");
	string newNumber = prompt("Enter phone number");
	string newEmail = prompt("Enter e-mail address");

	bool hasEntry = book.find(newName);

	if (hasEntry) {
		display("Updating phone book entry for " + newName);
	}
	else {
		display("Adding phone book entry for " + newName);
	}

	book.insert(newName, newNumber, newEmail);
}