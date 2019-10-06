/*
		Removes the specified phoneBookEntry (if it exists)
*/
#include "eraseCommand.h"

using namespace std;

eraseCommand::eraseCommand(phoneBook& bookIn, std::istream& in, std::ostream& out) : bookCommand(in, out), book(bookIn) {
	
}
void eraseCommand::execute() {
	string nameToErase = prompt("Enter name to erase");
	bool erased = book.erase(nameToErase);
	if (erased) {
		display("Phone book entry " + nameToErase + " was erased");
	}
	else {
		display("Phone book entry " + nameToErase + " was not erased");
	}
	
}