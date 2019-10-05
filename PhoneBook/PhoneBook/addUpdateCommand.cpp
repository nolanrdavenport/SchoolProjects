/*
	This command will add a new entry if the passed in name is not already in the phoneBook. Otherwise it will update and existing phoneBookEntry
*/
#include "addUpdateCommand.h"
addUpdateCommand::addUpdateCommand(phoneBook& bookIn, std::istream& in, std::ostream& out) : bookCommand(in, out), book(bookIn){
	// any other code you may need
}

void addUpdateCommand::execute() {}