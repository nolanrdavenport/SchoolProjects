#include "binarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	binarySearchTree<string> testTree;
	
	testTree.insert("nolan");
	cout << testTree.size() << endl;
	testTree.insert("sandra");
	cout << testTree.size() << endl;
	testTree.insert("thomas");
	cout << testTree.size() << endl;
	testTree.insert("alex");
	cout << testTree.size() << endl;
	testTree.insert("lizzy");
	cout << testTree.size() << endl;
	testTree.erase("nolan");
	cout << testTree.size() << endl;
	testTree.erase("lizzy");
	cout << testTree.size() << endl;
	
	testTree.print();

	return 0;
}