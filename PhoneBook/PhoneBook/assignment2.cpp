/*
	This is a Phone Book program that stores and allows manipulation of a persons name, number, and email address.
*/
#include <iostream>
#include "phoneBookEntry.h"
#include "phoneBook.h"
#include "menuList.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"

int main() {
	//Creates phone book.
	phoneBook book;

	//Creates commands
	addUpdateCommand addUpdate(book, std::cin, std::cout);
	eraseCommand erase(book, std::cin, std::cout);
	printCommand print(book, std::cin, std::cout);

	//Builds the menuList and menuItems.
	menuList menu("Phone book menu:");
	menuItem addUpdateItem('a', "add/update", addUpdate);
	menuItem eraseItem('e', "erase", erase);
	menuItem printItem('p', "print", print);

	//Adds items to menu.
	menu.add(addUpdateItem);
	menu.add(eraseItem);
	menu.add(printItem);

	//Starts the menu.
	std::cout << "Starting the Phone Book" << std::endl << std::endl;
	menu.start();

	return 0;
}