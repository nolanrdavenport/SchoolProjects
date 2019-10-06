/*
	Notes:
	Your main will need to create the phoneBook and menuList objects. It will also have to create the addUpdateCommand, eraseCommand, and printCommand objects. 
	Using these you can create the menuItem objects for each of the commands, add them to the menuList and start the menu.

	Here is a summary of the three required menuItem objects:
		C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\menuItems.png
	
	Here is the output from the addUpdateCommand for a valid add:
		C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\addUpdateCGood.png
	
	no global variables

	COMPLETE-	First create the phoneBookEntry class and make sure that is working. You may have to create some test code to make sure it is working. 
				Try out the various constructors (including the copy constructor), and the accessors and mutators

	Next get the phoneBook working. Start with the constructors and then add the debug support. Next start doing the various insert operations, the erase operation, the find operation, and the print operations. 
	Don't try and do this all at once.

	For the menu you can start by getting the menu to work with just the default quit command.

	Next you can implement the add/update command and get that working.

	After that is working you can add the print support.

	Finish by adding the erase.


*/
#include <iostream>
#include "phoneBookEntry.h"
#include "phoneBook.h"
using namespace std;

int main() {
	//TODO: Start working on the menu
	cout << "Hello, world!" << endl;
	phoneBook book;

	phoneBookEntry e1("bill","1-800","bill@mail.com");
	phoneBookEntry e2("bob","281","bob@mail.com");
	phoneBookEntry e3("bob","999","pSlayer@gmail.com");
	
	book.insert(e1);
	book.insert(e2);

	return 0;
}