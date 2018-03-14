#include "lliststr.h"
#include <iostream>
#include <string>

using namespace std;

void checkEmpty(LListStr *list, bool expEmpty) {
	if (list->empty() == expEmpty) {
		cout << "SUCCESS: List is ";
		if (!expEmpty) cout << "not ";
		cout << "empty" << endl;
	}
	else {
		cout << "FAIL: List is ";
		if (expEmpty) cout << "not ";
		cout << "empty" << endl;
	}
}

void checkSize(LListStr *list, int expSize) {
	int size = list->size();
	if (size == expSize) {
		cout << "SUCCESS: List has size " << size << endl;
	}
	else {
		cout << "FAIL: List has size " << size;
		cout << " but expected " << expSize << endl;
	}
}

void checkGet(LListStr *list, int pos, const string &expStr) {
	string str = list->get(pos);
	if (str == expStr) {
		cout << "SUCCESS: String at index " << pos << " is \'" << expStr << "\'" 
		<< endl;
	} 
	else {
		cout << "FAIL: String at index " << pos << " is \'" << str << "\'";
		cout << " but expected \'" << expStr << "\'" << endl;
	}
}

int main() {
	LListStr* list = new LListStr();

	// Check if the list is initially empty.
	checkEmpty(list, true);
	checkSize(list, 0);

	// Insert an item at the head.
	list->insert(0, "CSCI104");

	// Verify the list is not empty
	checkEmpty(list, false);
	checkSize(list, 1);

	// Check if the value is correct.
	checkGet(list, 0, "CSCI104");

	/////////////////////////////////////////////////
	list->insert(0, "hello");

	// Verify the list is not empty
	checkEmpty(list, false);
	checkSize(list, 2);

	// Check if the value is correct.
	checkGet(list, 0, "hello");

	/////////////////////////////////////////
	list->insert(0, "third line");

	// Verify the list is not empty
	checkEmpty(list, false);
	checkSize(list, 3);

	// Check if the value is correct.
	checkGet(list, 0, "third line");

	//////////////////////////////////////////
	// Retrieve size.
	int size = list->size();
	std::cout << "SUCCESS: Expected size is 3 and the real size is " << size 
	<< std::endl;


	// Insert an item in the middle.
	list->insert(1, "insert in middle");


	checkEmpty(list, false);
	checkSize(list, 4);

	// Check if the value is correct.
	checkGet(list, 1, "insert in middle");

	// Retrieve size.
	size = list->size();

	// Insert an item at the end.
	list->insert(size, "insert at end");
	checkEmpty(list, false);
	checkSize(list, 5);

	// Print out current linked list 
	for(int i = 0; i < list->size(); i++)
	{
		std::cout << list->get(i) << " " << std::endl;
	}

	// Check if the value is correct.
	checkGet(list, 4, "insert at end");

	// Check insertion out of bounds.
	list->insert(10, "out of bounds");

	// Create a linked list to check the remove function

	std::cout << std::endl;

	std::cout << "ATTENTION: CHECKING NEW SECTION" << std::endl;

	std::cout << std:: endl;

	LListStr* list2 = new LListStr();

	// Check that the list is empty
	checkEmpty(list2, true);

	// Check that the size is 0
	checkSize(list2, 0);

	// Remove from an empty list
	list2->remove(0);
	list2->remove(1);

	// Set from an empty list
	list2->set(0, "set an empty list");
	checkSize(list2, 0);

	// Get from an empty list
	list2->get(0);
	list2->get(1);
	checkSize(list2, 0);

	// Insert an item at the head
	list2->insert(0, "this is the head");

	// Verify the list is not empty
	checkEmpty(list2, false);
	checkSize(list2, 1);

	// Check if the value is correct.
	checkGet(list2, 0, "this is the head");

	// Insert an item at the head
	list2->insert(0, "inserting");
	checkGet(list2, 0, "inserting");

	// Insert an item at the tail
	list2->insert(2, "blahblahblah");
	checkGet(list2, 2, "blahblahblah");

	// Remove out of bounds
	list2->remove(10);

	// Remove from the head
	list2->remove(0);

	checkEmpty(list2, false);
	checkSize(list2, 2);

	// Check if the value is correct.
	checkGet(list2, 0, "this is the head");

	// Insert an item at the head
	list2->insert(0, "checking");
	checkGet(list2, 0, "checking");

	// Insert an item at the head
	list2->insert(0, "third item");
	checkGet(list2, 0, "third item");

	// Remove from the tail
	list2->remove(3);

	checkSize(list2, 3);

	// Check if the value is correct.
	checkGet(list2, 1, "checking");

	// Insert an item at the head
	list2->insert(0, "omg");
	checkGet(list2, 0, "omg");

	// Remove from the middle
	list2->remove(2);
	checkSize(list2, 3);

	// Check if the value is correct.
	checkGet(list2, 0, "omg");
	checkGet(list2, 2, "this is the head");

	// Checking set out of bounds
	list2->set(20, "outofbounds");

	// Checking set works
	list2->set(0, "reset");
	checkGet(list2, 0, "reset");

	// Get out of bounds
	list2->get(20);

	// empty list
	LListStr* list3 = new LListStr();
	checkSize(list3, 0);

	// list with one element
	LListStr* list4 = new LListStr();
	list4->insert(0, "oneelement");
	checkSize(list4, 1);


	// Clean up memory.
	delete list;
	delete list2;

	// deleting an empty list
	delete list3;

	// deleting a list with one element
	delete list4;
}