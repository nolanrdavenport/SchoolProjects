/*
	This is a subclass of the command class. It will implement some helper functions needed by the add/update, and erase commands.
*/
#include "bookCommand.h"
#include <string>

/*
	Sets up the bookCommand class by taking in the istream and ostream objects and setting them to the in and out variables.
*/
bookCommand::bookCommand(std::istream &inStream, std::ostream &outStream) : in(inStream), out(outStream) {}

/*
	Displays the string that is passed in the parameter.
*/
void bookCommand::display(std::string str) {
	out << str << std::endl;
}

/*
	Takes in a string which is output to the screen, prompting the user to input a string. That inputted string is then returned.
*/
std::string bookCommand::prompt(std::string str) {
	out << str << std::endl;
	std::string input;
	getline(in, input);
	return input;
}