/*
 * orderedLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include <cstddef>

#include "linkedList.h"

template<class DataType>
class orderedLinkedList
{
public:
	typedef linkedList<DataType>              unorderedLinkedList;
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t 					      difference_type;
	typedef std::size_t						      size_type;
	typedef typename unorderedLinkedList::iterator  iterator;
	typedef const iterator	  	               const_iterator;
private:
	linkedList<DataType> list;
public:
	// default constructor
	orderedLinkedList() {}
	// copy constructor
	orderedLinkedList(const orderedLinkedList& other) {
		for (iterator iter = other.begin(); iter != other.end(); iter++) {
			list.push_back(iter.current->data());
		}
	}
	// assignment operator
	const orderedLinkedList& operator=(const orderedLinkedList& other) {
		for (unsigned int i = 0; i < list.listSize; i++) {
			list.pop_front();
		}
		list.listSize = 0;
		for (iterator iter = other.begin(); iter != other.end(); iter++) {
			list.push_back(iter.current->data());
		}
		return *this;
	}
	// destructor
	virtual ~orderedLinkedList() {
		
	}
	// iterators
	iterator begin()
	{
		return list.begin();
	}

	iterator end()
	{
		return list.end();
	}

	const_iterator begin() const
	{
		return list.begin();
	}

	const_iterator end() const
	{
		return list.end();
	}

	// number of items in the list
	virtual std::size_t size() const {
		return list.size();
	}
	// is the list empty (true) or does it have entries (false)
	virtual bool empty() const {
		return list.empty();
	}
	// print the items in the list
	virtual void print() const {
		list.print();
	}
	// display the contents of the list to the ostream&
	virtual void print(std::ostream& out) const {
		list.print(out);
	}
	// display debug information on the passed in ostream
	virtual void debug(std::ostream& out) const {
		list.debug(out);
	}
	// find the element and return an interator for it
	virtual iterator find(const DataType& existingItem) {
		return list.find(existingItem);
	}
	// remove the node equal to currentItem
	virtual bool erase(const DataType& currentItem) {
		return list.erase(currentItem);
	}
	// remove the node by address existingNode
	virtual iterator erase(iterator iter) {
		return list.erase(iter);
	}

	// insert the new item into the list (in sorted order)
	// a duplicate entry will be ignored
	virtual void insert(const DataType& newItem);
	// get the last entry
	iterator back()
	{
		return list.back();
	}

	const_iterator back() const
	{
		return list.back();
	}
};

// Your implementation code goes here
template <class DataType>
void orderedLinkedList<DataType>::insert(const DataType& newItem) {
	//check duplicate
	bool dupe = false;
	for (iterator iter = list.begin(); iter != list.end(); iter++) {
		if (*iter == newItem) {
			dupe = true;
		}
	}
	if (!dupe && list.size() == 0) {
		list.push_front(newItem);
	}
	else if (!dupe) {
		for (iterator iter = list.begin(); iter != list.end(); iter++) {
			if (newItem < (*iter)) {
				list.insert_before(iter, newItem);
				break;
			}
			if (iter == list.back()) {
				list.insert_after(iter, newItem);
				break;
			}
		}
	}
}
#endif /* ORDEREDLINKEDLIST_H_ */
