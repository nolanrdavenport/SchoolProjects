/*  notes
	-Stuff being stored in the binary tree will have to overload the operator<< operator for print()
	-
*/
#pragma once
#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <vector>
// forward declaration of the template class binarySearchTree
template<class T>
class binarySearchTree;

// treeNode class
template <class T>
class treeNode {
	friend class binarySearchTree<T>;
private:
	T value;
public:
	treeNode<T>* leftChild = nullptr;
	treeNode<T>* rightChild = nullptr;
	treeNode(T data) {
		value = data;
	}

	T getValue() {
		return value;
	}

	void setValue(T data) {
		value = data;
	}
};

// binarySearchTree class
template <class T>
class binarySearchTree {
private:
	void deleteAll() {
		deleteAll(root);
		root = nullptr;
	}
	void deleteAll(treeNode<T>* node);
public:
	treeNode<T>* root = nullptr;

	T getRootValue() {
		return root->getValue();
	}

	size_t treeSize = 0;
	//Constructor
	binarySearchTree();

	//Destructor
	virtual ~binarySearchTree() {
		deleteAll();
	}

	//Copy Constructor
	binarySearchTree(const binarySearchTree& other);


	//Assignment Operator
	const binarySearchTree& operator=(const binarySearchTree& other) {
		//TODO: Implement the assignment operator
	}

	// will return true if the binary tree is empty
	bool empty() const {
		if (root == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	//Returns the number of items in the binary tree
	size_t size() const {
		return treeSize;
	}


	//Prints the whole tree using in order traversal
	void print() const;

	// void debug(std::ostream& out) const; // displays contesnts for debugging purposes

	bool find(const T& searchItem, void (*foundNode)(const T&));

	bool erase(const T& deleteItem); // will remove specified item from the binary tree - true if found - false if not found

	void insert(const T& newItem); // insert the item into the binary tree. If the entry already exists it should be replaced by a new one.

	void insert(const T& newItem, void (*duplicateItemFound)(T& existingItem, const T& newItem));

	void traverse(void(*itemFound)(const T& foundItem)) const; // will do an in order traversal of the binary tree. For every item found, it will call the item Found function and pass it a const reference to the found item. 
};

template<class T>
void binarySearchTree<T>::deleteAll(treeNode<T>* node) {
	if (node != nullptr) {
		// delete all nodes to the left
		deleteAll(node->leftChild);
		node->leftChild == nullptr;

		// delete all nodes to the right
		deleteAll(node->rightChild);
		node->rightChild == nullptr;

		// delete node
		delete node;
		treeSize--;
	}
}

template<class T>
void binarySearchTree<T>::print() const{
	struct temp {
		static void inOrderTraversal(treeNode<T>* node) {
			if (node == nullptr) {
				return;
			}
			inOrderTraversal(node->leftChild);
			std::cout << node->getValue() << std::endl;
			inOrderTraversal(node->rightChild);
		}
	};
	temp::inOrderTraversal(root);
}

template<class T>
bool binarySearchTree<T>::find(const T& searchItem, void (*foundNode)(const T&)) {
	treeNode<T>* curr = root;
	while (curr != nullptr) {
		if (searchItem == curr->getValue()) {
			foundNode(curr->getValue());
			return true;
		}
		else if (searchItem < curr->getValue()) {
			curr = curr->leftChild;
		}
		else {
			curr = curr->rightChild;
		}
	}
	return false;
}

template<class T>
bool binarySearchTree<T>::erase(const T& deleteItem) {
	treeNode<T>* parent = nullptr;
	treeNode<T>* curr = root;
	while (curr != nullptr) {
		if (deleteItem == curr->getValue()) {
			if (curr->leftChild == nullptr && curr->rightChild == nullptr) { // remove leaf node
				if (curr == root) {
					curr->leftChild = nullptr;
					curr->rightChild = nullptr;
				}
				else if (parent->leftChild == curr) {
					parent->leftChild = nullptr;
				}
				else {
					parent->rightChild = nullptr;
				}
				delete curr;
				treeSize--;
			}
			else if (curr->leftChild != nullptr && curr->rightChild == nullptr) { // remove node with only left child
				if (curr == root) { // node is root
					root == curr->leftChild;
				}
				else if (parent->leftChild == curr) {
					parent->leftChild = curr->leftChild;
				}
				else {
					parent->rightChild = curr->leftChild;
				}
				delete curr;
				treeSize--;
			}
			else if (curr->leftChild == nullptr && curr->rightChild != nullptr) { // remove node with only right child
				if (curr == root) { // node is root
					root == curr->rightChild;
				}
				else if (parent->leftChild == curr) {
					parent->leftChild = curr->rightChild;
				}
				else {
					parent->rightChild = curr->rightChild;
				}
				delete curr;
				treeSize--;
			}
			else { // remove node with two children
				treeNode<T>* successor = curr->rightChild;
				while (successor->leftChild != nullptr) {
					successor = successor->leftChild;
				}
				T successorData = successor->getValue();
				erase(successor->getValue());
				curr->setValue(successorData);
			}
			return true;
		}
		else if (deleteItem < curr->getValue()) {
			parent = curr;
			curr = curr->leftChild;
		}
		else {
			parent = curr;
			curr = curr->rightChild;
		}
	}

	return false;
}

template <class T>
void binarySearchTree<T>::insert(const T& newItem) {
	if (root == nullptr) {
		root = new treeNode<T>(newItem);
		treeSize++;
	}
	else {
		treeNode<T>* curr = root;
		while (curr != nullptr) {
			if (newItem < curr->getValue()) {
				if (curr->leftChild == nullptr) {
					curr->leftChild = new treeNode<T>(newItem);
					curr = nullptr;
					treeSize++;
				}
				else {
					curr = curr->leftChild;
				}
			}
			else if (newItem > curr->getValue()){
				if (curr->rightChild == nullptr) {
					curr->rightChild = new treeNode<T>(newItem);
					curr = nullptr;
					treeSize++;
				}
				else {
					curr = curr->rightChild;
				}
			}
			else {
				curr->setValue(newItem);
				curr = nullptr;
			}
		}
	}
}

template <class T>
void binarySearchTree<T>::insert(const T& newItem, void (*duplicateItemFound)(T& existingItem, const T& newItem)) {
	if (root == nullptr) {
		root == new treeNode<T>(newItem);
	}
	else {
		treeNode<T>* curr = root;
		while (curr != nullptr) {
			if (newItem < curr->getValue()) {
				if (curr->leftChild == nullptr) {
					curr->leftChild = new treeNode<T>(newItem);
					curr = nullptr;
					treeSize++;
				}
				else {
					curr = curr->leftChild;
				}
			}
			else if (newItem > curr->getValue()) {
				if (curr->rightChild == nullptr) {
					curr->rightChild = new treeNode<T>(newItem);
					curr = nullptr;
					treeSize++;
				}
				else {
					curr = curr->rightChild;
				}
			}
			else {
				T val = curr->getValue();
				curr = nullptr;
				duplicateItemFound(val, newItem);
			}
		}
	}
}

template <class T>
void binarySearchTree<T>::traverse(void(*itemFound)(const T& foundItem)) const {
	//This is a workaround so that I can recursively traverse without having a method that takes in the node 
	struct temp {
		static void inOrderTraversal(treeNode<T>* node) {
			if (node == nullptr) {
				return;
			}
			inOrderTraversal(node->leftChild);
			itemFound(node->getValue());
			inOrderTraversal(node->rightChild);
		}
	};
	temp::inOrderTraversal(root);
}

template<class T>
binarySearchTree<T>::binarySearchTree(const binarySearchTree& other) {
	struct temp {
		static void preOrderTraversal(treeNode<T>* node) {
			if (node == nullptr) {
				return;
			}

			insert(node->getValue());
			preOrderTraversal(node->leftChild);
			preOrderTraversal(node->rightChild);
		}
	};
	treeNode<T>* otherRoot = other.root;
	temp::preOrderTraversal(otherRoot);
}

