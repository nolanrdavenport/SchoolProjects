/*
		Removes the specified phoneBookEntry (if it exists)

		Notes:
		You need the same constructor signature you used in the addUpdateCommand class. You will need to override the execute member function and prompt for name of the phoneBookEntry to be erased. 
		See the sample output below for examples of the prompts and error messages required for this application. 
		You will delegate the actual erase to the phoneBook class. 
		Note that all input and output performed by eraseCommand should be performed using the helper functions you wrote for the bookCommand class.

		Here is sample output from the eraseCommand for an entry that exists:
			C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\eraseCommandOutput.png

		Here is sample output from the eraseCommand for an entry that does NOT exist
			C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\eraseCommandOutputNone.png



*/
#pragma once
#include "bookCommand.h"
#include "phoneBook.h"
class eraseCommand : bookCommand {
public:
	eraseCommand(phoneBook& bookIn, std::istream& in, std::ostream& out);
	void execute(); 
private:
	phoneBook& book;

};