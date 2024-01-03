#pragma once

//Header file for LinkedListOperations.cpp

class linkList
{
private:
	struct node
	{
		int data;
		node *link;
	} *p;

public:
	linkList();
	void append(int number);
	void addAtBeginning(int number);
	void addAfter(int location, int number);
	void reverse();
	void display();
	int count();
	void deleteElement(int number);
	~linkList();
};

void linkedListOperationsMenu();