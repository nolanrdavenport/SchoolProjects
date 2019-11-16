/*  notes
	-Stuff being stored in the binary tree will have to overload the operator<< operator for print()
	-
*/
#pragma once
// forward declaration of the template class binarySearchTree
template<class T>
class binarySearchTree;

// treeNode class
template <class T>
class treeNode {
	friend class binarySearchTree<DataType>;
	// the rest of the treeNode class declaration goes here
};

// binarySearchTree class
template <class T>
class binarySearchTree {
public:
	bool empty() const; // will return true if the binary tree is empty
	std::size_t size() const; // returns the number of items in the binary tree
	void print() const; // displays the contents of the binary tree in order by key (inorder traversal) - print line by line
	void debug(std::ostream& out) const; // displays contesnts for debugging purposes
	bool find(const T& searchItem, void (*foundNode)(const T&));
	bool erase(const T& deleteItem); // will remove specified item from the binary tree - true if found - false if not found
	void insert(const T& newItem); // insert the item into the binary tree. If the entry already exists it should be replaced by a new one.
	void insert(const T& newItem, void (*duplicateItemFound)(T& existingItem, const T& newItem));
};