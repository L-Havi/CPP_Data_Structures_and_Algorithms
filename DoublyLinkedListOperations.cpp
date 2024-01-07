/*
 *  Implementation of various Doubly Linked List Operations
 *
 *  These include appending to a doubly linked list, adding an element to the beginning of a doubly linked list & adding an element to a set place in the doubly linked list.
 *  Also, operations for getting the element count of the doubly linked list, deleting an element from the doubly linked list & displaying
 *	the entire doubly linked list are implemented.
 *
 *  The Doubly Linked List in this case is an integer Doubly Linked List
 *
 *	In the linked lists that we have used so far each node provides
 *	information about where is the next node in the list. It has no
 *	knowledge about where the previous node lies in memory. If we are at
 *	say the 15th node in the list, then to reach the 14th node we have to
 *	traverse the list right from the first node. To avoid this we can store in
 *	each node not only the address of next node but also the address of the
 *	previous node in the linked list.
 *
 *  The Doubly linked list is a collection of elements called nodes, each
 * 	of which stores three items of information — an element of the list and
 * 	links to previous and next node.
 */

#include <iostream>

#include "RandomUtils.hpp"
#include "CommonUtils.hpp"
#include "color.hpp"
#include "DoublyLinkedListOperations.hpp"

//Initializes data member
doublyLinkedList::doublyLinkedList()
{
	p = NULL;
}
//Adds a new node at the end of the doubly linked list
void doublyLinkedList::append(int number)
{
	node *r, *q;
	q = p;
	//If the linked list is empty
	if (q == NULL)
	{
		//Create a new node
		q = new node;
		q->prev = NULL;
		q->data = number;
		q->next = NULL;
		p = q;
	}
	else
	{
		//Traverse the linked list till the last node is reached
		while (q->next != NULL)
			q = q->next;
		//Add a new node at the end
		r = new node;
		r->data = number;
		r->next = NULL;
		r->prev = q;
		q->next = r;
	}
}
//Adds a new node at the begining of the linked list
void doublyLinkedList::addAtBeginning(int number)
{
	node *q;
	//Create a new node
	q = new node;
	q->prev = NULL;
	q->data = number;
	q->next = p;
	//Make new node the head node
	p->prev = q;
	p = q;
}
//Adds a new node after the specified number of nodes
void doublyLinkedList::addAfter(int location, int number)
{
	node *q;
	q = p;
	//Skip to desired portion
	for (int i = 0; i < location; i++)
	{
		q = q->next;
		//If end of linked list is encountered
		if (q == NULL)
		{
			std::cout << dye::red("[-]") << "There are less than " << location << " elements!\n";
			return;
		}
	}
	//Insert new node
	q = q->prev;
	node *temp = new node;
	temp->data = number;
	temp->prev = q;
	temp->next = q->next;
	temp->next->prev = temp;
	q->next = temp;
}

//Displays the contents of the linked list
void doublyLinkedList::display()
{
	node *temp = p;

	std::cout << "[";
	//Traverse the entire linked list
	while (temp != NULL)
	{
		std::cout << temp->data;
		temp = temp->next;
		if (temp != NULL)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}
// counts the number of nodes present in the linked list
int doublyLinkedList::count()
{
	int count = 0;
	node *temp = p;

	//Traverse the entire linked list
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
//Deletes the specified node from the doubly linked list
void doublyLinkedList::deleteElement(int number)
{
	node *q = p;

	//Traverse the entire linked list
	while (q != NULL)
	{
		//Ïf node to be deleted is found
		if (q->data == number)
		{
			//If node to be deleted is the first node

				if (q == p)
				{
					p = p->next;
					p->prev = NULL;
				}
				else
				{
					//If node to be deleted is the last node
					if (q->next == NULL)
						q->prev->next = NULL;
					else
						//If node to be deleted is any intermediate node
					{
						q->prev->next = q->next;
						q->next->prev = q->prev;
					}
					delete q;
				}
			//Return back after deletion
			return;
		}
		//Go to next node
		q = q->next;
	}
	std::cout << dye::red("[-]")<< " " << number << " not found!\n";
}
//Deallocates memory
doublyLinkedList :: ~doublyLinkedList()
{
	node *q;
	while (p->next != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
}

void doublyLinkedListOperationsMenu()
{

	int choice;
	int inputValue;
	int locationValue;

	bool menuLoop = true;

	doublyLinkedList dLinkList;
	std::cout << dye::green("[+]") << " Creating an empty Doubly Linked list:\n";
	dLinkList.display();

	while (menuLoop)
	{
		std::cout << "\nChoose your action: \n" << "1. Append to the Doubly Linked List\n"
			<< "2. Append to the beginning of the Doubly Linked List\n" << "3. Append to set location in the Doubly Linked List\n"
			<< "4. Display the Doubly Linked List\n" << "5. Count the elements in the Doubly Linked List\n"
			<< "6. Delete an element from the Doubly Linked List\n" << "7. Exit to Main Menu\n";

		choice = getIntInputFromUser();
		switch (choice)
		{
		case 1:
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]") << " Choose a number value to append to the Doubly Linked List:";
			inputValue = getIntInputFromUser();

			dLinkList.append(inputValue);

			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";
			break;
		case 2:
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]") << " Choose a number value to append to the beginning of the Doubly Linked List:";
			inputValue = getIntInputFromUser();

			dLinkList.addAtBeginning(inputValue);
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";
			break;
		case 3:
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]") << " Choose a location where to append the element to the Doubly Linked List:";
			locationValue = getIntInputFromUser();
			std::cout << dye::yellow("[!]") << " Choose a number value to append to the Doubly Linked List:";
			inputValue = getIntInputFromUser();

			dLinkList.addAfter(locationValue, inputValue);
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";
			break;
		case 4:
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";
			break;
		case 5:
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";

			std::cout << dye::green("[+]") << " Doubly Linked List has " << dLinkList.count() << " Nodes in it.\n";

			break;
		case 6:
			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]") << " Choose a number value to delete from the Doubly Linked List:";
			inputValue = getIntInputFromUser();

			dLinkList.deleteElement(inputValue);

			std::cout << dye::green("[+]") << " Doubly Linked List:\n";
			dLinkList.display();
			std::cout << "\n";

			break;
		case 7:
			menuLoop = false;
			break;
		default:
			std::cout << dye::red("[-]") << " The input value must be an integer between 1-7.";
			break;
		}

	}
	return;
}