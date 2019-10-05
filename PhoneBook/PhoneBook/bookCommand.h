/*
		This is a subclass of the command class. It will implement some helper functions needed by the add/update, and erase commands

		Notes:

		You will not be implementing the execute pure virtual function, so the new class bookCommand will also be an abstract class.

		The bookCommand class should have two protected data members. One is a reference to std::istream, and the second one is a reference to std::ostream. 
		See demo classes incrementCommand and decrementCommand to see how to do this using a reference to an int.

		Your constructor should save these parameters (all passed by reference) in the protected data members in your class (for the std::istream and std::ostream references).

		When you code the bookCommand constructor you will need to use an initialization list. Assume the following are defined in your bookCommand.h file:

		Here is the constructor in the .cpp file (the initialization list would be used even if the constructor is inlined):
			C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\bookCommand1.png

		The in(inStream) syntax is showing the actual parameter (inStream) being used to construct the std::istream &in object.

		You should also have two protected member functions.
		One will display a passed in std::string to the std::ostream that was passed to you on the constructor. 
		This function does not return a value, it takes one parameter of type std::string and display it to the std::ostream protected reference.
		The second member function will be passed in a std::string that will be written to the std::ostream passed to your constructor. This is a prompt to the user. 
		It will then read in a std::string from the std::istream passed to your constructor and return the read in std::string to the caller. 
		Note that the input you are reading in may contain embedded spaces. For this reason you should (must) use getline to read in the input values.

		These two helper function will be used by the addUpdateCommand, eraseCommand, and printCommand subclasses of bookCommand.

		You need to create three subclasses of your new abstract class bookCommand. They will make use of the two protected member functions you created for the bookCommand class. 
		The subclasses will also have access to the std::istream and std::ostream objects references that are protected data members in the bookCommand class. 
		You should use public inheritance for the subclasses of bookCommand.
*/
#pragma once

#include "command.h"
#include <iostream>

class bookCommand : public command {
public:
	bookCommand(std::istream& in, std::ostream& out);
protected:
	std::istream& in;
	std::ostream& out;
};
