/*
		This is a subclass of the command class. It will implement some helper functions needed by the add/update, and erase commands
*/
#include "bookCommand.h"
#include <string>

using namespace std;

bookCommand::bookCommand(std::istream& in, std::ostream& out) : in(in), out(out){

}

void bookCommand::display(std::string str) {
	out << str << endl;
}

std::string bookCommand::prompt(std::string str) {
	out << str << endl;
	string input;
	getline(cin, input);
	return input;
}