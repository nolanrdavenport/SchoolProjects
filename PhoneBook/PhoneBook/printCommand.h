/*
		Command that prints the phoneBook when the command is executed by the menu

		Notes: 
		The value for std::ostream should be the ostream object saved in the protected state for the bookCommand class.

		Here is the output for the printCommand for a phoneBook with three entries
		C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\printCommandOutput.png
		This is output from the phoneBook print member function that is called by the printCommand. assignment2.cpp
*/
#pragma once
#include "bookCommand.h"
#include "phoneBook.h"
class printCommand : bookCommand {
public:
	printCommand(phoneBook& bookIn, std::istream& in, std::ostream& out);
	void execute();
private:
	phoneBook& book;

};