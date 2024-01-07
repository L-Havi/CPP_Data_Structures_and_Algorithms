#pragma once

//Header file for DoublyLinkedListOperations.cpp

class doublyLinkedList
{
private:
	struct node
	{
		node *prev;
		int data;
		node *next;
	} *p;

public:
	doublyLinkedList();
	void append(int number);
	void addAtBeginning(int number);
	void addAfter(int location, int number);
	void display();
	int count();
	void deleteElement(int number);
	virtual ~doublyLinkedList();
};

void doublyLinkedListOperationsMenu();