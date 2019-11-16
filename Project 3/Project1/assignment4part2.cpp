#include <iostream>
#include "linkedList.h"
#include "orderedLinkedList.h"
#include <string>
using namespace std;

int main() {
	
	orderedLinkedList<int> list;
	list.insert(5);
	list.insert(100);
	list.insert(12);
	list.insert(14);
	list.insert(125);
	list.insert(2);
	list.insert(1);
	list.insert(15);
	list.insert(65);
	list.insert(5);
	list.print();
	return 0;
}