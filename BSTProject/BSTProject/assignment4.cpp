#include "binarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

//for testing functions that take in function pointers
void found(const string& value) {
	cout << value << " was found in the tree" << endl;
}

void duplicatedItemFound(string& existingItem, const string& newItem) {
	cout << existingItem << " was duplicated" << endl;
}

int main() {
	binarySearchTree<string> testTree;
	
	testTree.insert("nolan");
	testTree.insert("sandra");
	testTree.insert("thomas");
	testTree.insert("alex");
	testTree.insert("lizzy");
	testTree.print();
	
	cout << endl; 
	binarySearchTree<string> copyTestTree(testTree);

	copyTestTree.print();


	return 0;
}