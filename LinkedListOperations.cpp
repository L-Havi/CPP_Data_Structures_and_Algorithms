/*
 *  Implementation of various Linked List Operations
 *
 *  These include appending to a linked list, adding an element to the beginning of a linked list & adding an element to a set place in the linked list.
 *  Also, operations for getting the element count of the linked list, reversing the linked list, deleting an element from the linked list & displaying 
 *	the entire linked list are implemented.
 * 
 *  The Linked List in this case is an integer Linked List
 *
 * 	While the elements of an array occupy contiguous memory locations,
 * 	those of a linked list are not constrained to be stored in adjacent
 * 	locations. The order of the elements is maintained by explicit links
 *	between them.
 * 
 *  The linked list is a collection of elements called nodes, each
 * 	of which stores two items of information—an element of the list and a
 * 	link.
 */

#include <iostream>

#include "RandomUtils.hpp"
#include "CommonUtils.hpp"
#include "color.hpp"
#include "LinkedListOperations.hpp"


//Initializes a data member of the Linked List
linkList::linkList() 
{
	p = NULL;
}

//Adds a Node at the end of the Linked List
void linkList::append(int number)
{
	node *temp, *r;
	//If the Linked List is empty, create the first Node
	if (p == NULL) 
	{
		std::cout << dye::green("[+]") << " Linked List is empty. Creating the first Node\n";
		temp = new node;
		std::cout << dye::green("[+]") << " Adding " << number << " as Node data.\n";
		temp->data = number;
		temp->link = NULL;
		p = temp;
	}
	else 
	{
		//Go to the last Node
		temp = p;
		while (temp->link != NULL)
		{
			std::cout << dye::green("[+]") << " Moving to the last Node. Current Node: " << temp->data << "\n";
			temp = temp->link;
		}

		//Add Node at the end
		std::cout << dye::green("[+]") << " Creating the Node\n";
		r = new node;
		std::cout << dye::green("[+]") << " Adding " << number << " to the node.\n";
		r->data = number;
		r->link = NULL;
		std::cout << dye::green("[+]") << " Setting the link for the second last Node to reference to " << r << "\n";
		temp->link = r;
	}
}

//Add a new Node at the beginning of the Linked List
void linkList::addAtBeginning(int number)
{
	node *temp;
	//Add new Node
	std::cout << dye::green("[+]") << " Creating the Node\n";
	temp = new node;
	std::cout << dye::green("[+]") << " Setting the Node data to " << number << "\n";
	temp->data = number;
	std::cout << dye::green("[+]") << " Setting the Node link to the earlier first Node\n";
	temp->link = p;
	std::cout << dye::green("[+]") << " Setting the first Node to the created Node\n";
	p = temp;
}

//Adds a new Node to the Linked List after the specified number of Nodes
void linkList::addAfter(int location, int number)
{
	node *temp, *r;
	temp = p;

	//Skip to the desired position
	for (int i = 0; i < location; i++)
	{
		temp = temp->link;
		std::cout << dye::green("[+]") << " Moving to the desired Node. Current Node: " << temp->data << "\n";
		//If the end of the Linked List is encountered
		if (temp == NULL)
		{
			std::cout << dye::red("[-]")<< "\n There are less than " << location << " elements in list\n";
			return;
		}

		//Insert new Node
		r = new node;
		std::cout << dye::green("[+]") << " Creating a new node\n";
		r->data = number;
		std::cout << dye::green("[+]") << " Setting Node data to " << number << "\n";
		r->link = temp->link;
		std::cout << dye::green("[+]") << " Setting Node link to reference current Node: " << temp->data << "\n";
		temp->link = r;
		std::cout << dye::green("[+]") << " Setting current node link to reference the new Node: " << r << "\n";
	}
}

//Reverses the Linked List
void linkList::reverse() 
{
	node *q, *r, *s;
	q = p;
	r = NULL;
	//Traverse the entire linked list
	while (q != NULL)
	{
		s = r;
		r = q;
		q = q->link;
		r->link = s;
	}
	p = r;
}

//Displays the contents of the Linked List
void linkList::display()
{
	node *temp = p;
	
	std::cout << "[";
	//Traverse the netire Linked List
	while (temp != NULL)
	{
		std::cout << temp->data;
		temp = temp->link;
		if (temp != NULL)
		{
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
}

//Counts the number of Nodes in the Linked List
int linkList::count() 
{
	int count = 0;

	node *temp = p;

	//Traverse the netire Linked List
	while (temp != NULL)
	{
		temp = temp->link;
		count++;
	}

	return count;
}

//Deletes the specified Node from the Linked List
void linkList::deleteElement(int number)
{
	node *old, *temp;
	temp = p;
	old = p;

	while (temp != NULL) 
	{
		std::cout << dye::red("[-]") << " Searching element " << number << " from the Linked List. Current node: " << temp->data << "\n";
		if (temp->data == number)
		{
			//If Node to be deleted is the first Node in the Linked List
			if (temp == p)
			{
				p = temp->link;
			}
			//If Node to be deleted is an intermediate Node in the Linked List
			else 
			{
				old->link = temp->link;
			}
			std::cout << dye::red("[-]") << " Deleting element " << temp->data << "\n";
			delete temp;
			return;
		}
		//Traverse the Linked List until the last Node is reached
		else
		{
			old = temp;
			temp = temp->link;
		}
	}
	std::cout << dye::red("[-]") << " Element " << number << " was not found from the Linked List!\n";
}

//Concatenates two Linked Lists
void linkList::concatenate(linkList& l)
{
	node* temp;
	//If the first linked list is empty
	if (p == NULL)
	{
		p = l.p;
	}
	else
	{
		//If both linked lists are non-empty
		if (l.p != NULL)
		{
			//Points to the starting of the first list
			temp = p;
			//Traverse the entire first linked list
				while (temp->link != NULL)
					temp = temp->link;
			// concatenate the second list after the first
			temp->link = l.p;
		}
	}
	l.p = NULL;
}

//Deallocates memory
linkList::~linkList()
{
	node *q;
	while (p != NULL) 
	{
		q = p->link;
		delete p;
		p = q;
	}
}

void linkedListOperationsMenu()
{

	int choice;
	int inputValue;
	int locationValue;

	bool menuLoop = true;

	linkList lList;
	std::cout << dye::green("[+]") << " Creating an empty Linked list:\n";
	lList.display();

	while (menuLoop)
	{
		std::cout << "\nChoose your action: \n" << "1. Append to the Linked List\n"
			<< "2. Append to the beginning of the Linked List\n" << "3. Append to set location in the Linked List\n"
			<< "4. Display the Linked List\n" << "5. Count the elements in the Linked List\n"
			<< "6. Delete an element from the Linked List\n" << "7. Reverse a Linked List\n" << "8. Exit to Main Menu\n";

		choice = getIntInputFromUser();
		switch (choice)
		{
		case 1:
			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]")  << " Choose a number value to append to the Linked List:";
			inputValue = getIntInputFromUser();

			lList.append(inputValue);

			std::cout << dye::green("[+]")  << " Linked List:\n";
			lList.display();
			std::cout << "\n";
			break;
		case 2:
			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]")  << " Choose a number value to append to the beginning of the Linked List:";
			inputValue = getIntInputFromUser();

			lList.addAtBeginning(inputValue);
			std::cout << dye::green("[+]")  << " Linked List:\n";
			lList.display();
			std::cout << "\n";
			break;
		case 3:
			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]") << " Choose a location where to append the element to the Linked List:";
			locationValue = getIntInputFromUser();
			std::cout << dye::yellow("[!]") << " Choose a number value to append to the Linked List:";
			inputValue = getIntInputFromUser();

			lList.addAfter(locationValue, inputValue);
			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n";
			break;
		case 4:
			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n";
			break;
		case 5:
			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n";

			std::cout << dye::green("[+]") << " Linked List has " << lList.count() << " Nodes in it.\n";

			break;
		case 6:
			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n";

			std::cout << dye::yellow("[!]") << " Choose a number value to delete from the Linked List:";
			inputValue = getIntInputFromUser();

			lList.deleteElement(inputValue);

			std::cout << dye::green("[+]") << " Linked List:\n";
			lList.display();
			std::cout << "\n"; 

			break;
		case 7:
			std::cout << dye::green("[+]") << "Elements before reversing: ";
			lList.display();
			lList.reverse();
			std::cout << dye::green("[+]") << "Elements after reversing: ";
			lList.display();
			break;
		case 8:
			menuLoop = false;
			break;
		default:
			std::cout << dye::red("[-]") << " The input value must be an integer between 1-8.";
			break;
		}

	}
	return;
}