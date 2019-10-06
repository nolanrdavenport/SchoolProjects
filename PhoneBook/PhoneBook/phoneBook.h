/*
	This is the phoneBook and contains phoneBookEntry values. You can add, update, and remove entries from the phoneBook and you can print the contents of the phoneBook

	Notes:
	COMPLETE-	The insert operations will add the phoneBookEntry to the collection if it does not already exist. The new entry will be added to the bottom of the vector. 
				If the entry already exists (the name is already in the phone book), the existing entry must be updated.

	COMPLETE-	The first version of the insert takes an existing phoneBookEntry and add it to the vector. 
				For the 2nd and 3rd versions of the insert your insert member functions will have to create the phoneBookEntry that is to be added to the collection. 
				These can be temporary phoneBookEntry objects (the copy constructor will be called when the actual entry is added to the vector).

	COMPLETE -	If the entry (name) already exists in the vector you should update the phoneNumber and email for the existing entry.

	The erase operation will remove the phone book entry with the associated name from the collection.
	Your erase function will need to find the entry to be erased. Lets say it is at index i. If there is an entry at i+1 it will need to be moved to entry i. 
	If there is an entry at index i+2 it will need to be moved to entry i+1. This will continue until there are no more entries in the vector. 
	The last entry in the vector will then be deleted (since a copy was put into the entry above it).
	The erase member function must return true if the entry was erased and false if it was not erased (because it doesn't exist).

	The find member function will determine if there is a phoneBookEntrywith the specified name in the collection. It will return true if it is found and false if it is not found.

	The two print functions will print out the contents of the phoneBook. One will output to cout and the other will output to the passed in ostream object (passed by reference).
	For the print member functions you must output all of the data left justified in the following format (this is for a phoneBook with three entries): 
		C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\printFormat.png
	Note that the Name: column is 31 characters wide, and the Phone Number: column is 16 characters wide. 
	The E-Mail: column should not have a predetermined wide as it is at then end of the output. Note that your column titles and column widths MUST look like this.

	You should also have a debug member function. It should output the contents of the vector. You can output any additional information you would find helpful in debugging.

	The size member function will return the currently number of entries in the phoneBook.

	We want to make use of iterators. The vector class already has support for iterators, so we are going to leverage that to implement out iterator. 
	The iterator support will allow us to use the range based for loop with our phoneBook class.
	The begin member function needs to call the vector's begin member function, and the end member function needs to call the vector's end member function.
	Note that the typedef statements are inside of the phoneBook class declaration. 
	If you make use of them outside of the class definition you will have to use the syntax phoneBook::iterator (as an example) to get access to them.
	This will be required if you implement begin or end in your phoneBook.cpp file:
		C:\Users\guzzo\Desktop\1st Semester Coursework\CS 2337\project 2\pics\iteratorIssue.png

*/
#pragma once

#include <string>
#include <vector>
#include "phoneBookEntry.h"

class phoneBook {
public:
	phoneBook();
	void insert(const phoneBookEntry& entry);
	void insert(const std::string& name, const std::string& number, const std::string& email);
	void insert(const std::string& name, const std::string& number);
	bool erase(std::string name);
	bool find(std::string name);
	void print() const;
	void print(std::ostream& out) const;
	void debug(std::ostream& out) const;
	std::size_t size() const;
	typedef std::vector<phoneBookEntry> phoneBookEntryList;
	typedef phoneBookEntryList::iterator iterator;
	typedef phoneBookEntryList::const_iterator const_iterator;
	iterator begin();
	iterator end();

	int containsName(std::string nameIn);
private:
	std::vector<phoneBookEntry> entries;
};
