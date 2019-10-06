/*
		Command that prints the phoneBook when the command is executed by the menu
*/
#include "printCommand.h"
printCommand::printCommand(phoneBook& bookIn, std::istream& in, std::ostream& out) : bookCommand(in, out), book(bookIn) {

}
void printCommand::execute() {

}