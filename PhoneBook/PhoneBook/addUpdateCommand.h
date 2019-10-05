/*
	This command will add a new entry if the passed in name is not already in the phoneBook. Otherwise it will update and existing phoneBookEntry

	Notes:
	The phoneBook reference needs to be saved in a private data member of class addUpdateCommand. For the addUpdateCommand constructor will need to use initialization lists. 
	This will also be true for the eraseCommand and printCommand classes.

	This will also be true for the eraseCommand and printCommand classes.

	First we call the constructor for the bookCommand class we inherit from. We pass it the istream and ostream references passed on our constructor. 
	Next we specify the constructor for our instance variable book which is of type phoneBook &. You many have called the reference something different. 
	Just use the reference name you coded in your addUpdateCommand class.

	You also need to override the execute member function you inherited from command. In the execute you need to user the bookCommand member functions to prompt for the name, phone number and email. 
	You also need to issue the appropriate error messages (again using the member function from bookCommand). 
	See the sample output below for examples of the prompts and error messages required for this application. You will delegate the actual add/update to the phoneBook class. 
	Note that all input and output performed by addUpdateCommand should be performed using the helper functions you wrote for the bookCommand class.

	Here is the sample output from the addUpdateCommand for a valid add:
		C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\addUpdateCommandOutput.png
	NOTE: The data followed by [Enter] is entered by the application users, the rest is displayed by the member functions in the boookCommand class.
*/
#pragma once
#include "bookCommand.h"
#include "phoneBook.h"
class addUpdateCommand : bookCommand {
public:
	addUpdateCommand(phoneBook &bookIn, std::istream &in, std::ostream &out);
	void execute();
private:
	phoneBook &book;
};