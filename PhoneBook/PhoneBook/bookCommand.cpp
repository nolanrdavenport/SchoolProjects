/*
		This is a subclass of the command class. It will implement some helper functions needed by the add/update, and erase commands
*/
#include "bookCommand.h"

bookCommand::bookCommand(std::istream& in, std::ostream& out) : in(in), out(out){}