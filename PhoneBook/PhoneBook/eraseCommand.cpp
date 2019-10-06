/*
		Removes the specified phoneBookEntry (if it exists)
*/
#include "eraseCommand.h"
eraseCommand::eraseCommand(phoneBook& bookIn, std::istream& in, std::ostream& out) : bookCommand(in, out), book(bookIn) {
	
}
void eraseCommand::execute() {
	
}