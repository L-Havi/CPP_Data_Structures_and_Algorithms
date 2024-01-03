/* 
 *  Implementation of various One Dimensional Array operations
 * 
 *  These include adding, searcing & deleting an element in the array. 
 *  Also, reversing & displaying the entire Array.
 *  The Array in this case is an integer Array
 * 
 *  An Array itself is a finite collection of similar elements stored in adjacent
 *  memory locations. An array containing n number of elements is
 *  referenced using an index that varies from 0 to n - 1.
 */

#include "OneDimensionalArrayOperations.hpp"
#include "RandomUtils.hpp"
#include "CommonUtils.hpp"
#include "color.hpp"

#include <iostream>
#include <string>
#include <stdexcept>



//insert an element to the given position in array
void array::insert(int position, int number) 
{
	int i;
	std::cout << dye::green("[+]")  << " Starting to insert " << number << " to position arr[" << (position - 1) << "]:\n";
	//Shift elements to right
	for (i = arraySize - 1; i >= position; i--)
		std::cout << dye::green("[+]") << " Shifting " << "arr[" << (i - 1) << "] (" << arr[i - 1] << ") to arr[" << (i) << "]\n";
		arr[i] = arr[i - 1];
		std::cout << dye::green("[+]") << " Insering " << number << " to arr[" << i << "]:\n";
	arr[i] = number;
}

//Delete an element from array at given position
void array::del(int position)
{
	int i;
	std::cout << dye::red("[-]") << " Starting to delete an element from position arr[" << (position - 1) << "]:\n";

	//Skip to the position
	for (i = position; i < arraySize; i++)
		std::cout << dye::red("[-]") << " Shifting " << "arr[" << (i) << "] (" << arr[i - 1] << ") to arr[" << (i - 1) << "]\n";
		arr[i - 1] = arr[i];
	arr[i - 1] = 0;
	std::cout << dye::red("[-]") << " Deleting " << "arr[" << (i - 1) << "] (Setting arr[" << (i - 1) << "] to 0)\n";
}

//Search for an element from the array
void array::search(int number)
{
	std::cout << dye::green("[+]") << " Starting to search an element " << number << " from the array:\n";
	int i;
	for (i = 0; i < arraySize; i++)
	{
		std::cout << dye::green("[+]") << " Checking value of element position arr[" << (i + 1) << "] (" << arr[i] << ") from the array\n";
		if (arr[i] == number)
		{
			std::cout << "\n" << dye::green("[+]") << " Element " << number
				<< " is at " << (i + 1) << "th position in the array.";
			return;
		}
	}

	if (i == arraySize)
		std::cout << "\n" << dye::red("[-]") << "Element " << number << " is not in the array.";

}

//Reverse the array
void array::reverse()
{
	std::cout << dye::green("[+]") << " Starting to reverse the array:\n";
	for (int i = 0; i < arraySize / 2; i++)
	{
		int temp = arr[i];
		std::cout << dye::green("[+]") << " Assigning arr["<< i << "] (" << arr[i] << ") to temp variable\n";
		arr[i] = arr[arraySize - 1 - i];
		std::cout << dye::green("[+]") << " Assigning arr[arraySize - 1 - " << i << "] (" << arr[arraySize - 1 - i] << ") to arr["<< i <<"]\n";
		arr[arraySize - 1 - i] = temp;
		std::cout << dye::green("[+]") << " Assigning temp variable (" << temp << ") to arr[arraySize - 1 -" << i << "] (" << arr[arraySize - 1 - i] << ")\n";
	}
}

//Display the elements in the array
void array::display()
{
	std::cout << "\n";
	for (int i = 0; i < arraySize; i++)
		if (i == 0)
			//First element in the array
			std::cout << "[" << arr[i] << ", ";
		else if (i == arraySize - 1)
			//Last element in the array
			std::cout << arr[i] << "]";
		else
			std::cout << arr[i] << ", ";
}

array createRandomArray()
{
	int randInt;

	array arr;

	std::cout << dye::green("[+]") << " Starting by generating a random " << arraySize << " elements long array\n";

	for (int i = 0; i < arraySize; i++)
	{
		randInt = generateRandomInteger(0, 100);
		std::cout << dye::green("[+] ") << (i + 1) << ". random value assigned to " << randInt << "\n";
		arr.insert(i + 1, randInt);
	}
	std::cout << dye::green("[+]") << " Generated a random array \n";

	return arr;
}

void arrayOperationsMenu()
{

	int choice;
	int inputValue;
	int positionValue;

	bool validPosition;
	bool menuLoop = true;

	array sampleArray = createRandomArray();

	while (menuLoop) 
	{
		std::cout << "\nArray:";
		sampleArray.display();

		std::cout << "\nChoose your action: \n" << "1. Insert Value\n"
			<< "2. Delete Value\n" << "3. Search for a value\n"
			<< "4. Reverse Array\n" << "5. Display Array\n" << "6. Exit to Main Menu\n";

		choice = getIntInputFromUser();
		switch (choice)
		{
			case 1:
				std::cout << dye::yellow("[!]") << "Input a value to be inputted to the array:";
				inputValue = getIntInputFromUser();
				validPosition = false;
				while (!validPosition)
				{
					std::cout << dye::yellow("[!]") << "Input an input position for the element:";
					positionValue = getIntInputFromUser();
					if (positionValue >= 0 && positionValue < arraySize)
						validPosition = true;
					else
						std::cout << dye::red("[-]") << "The position must be in the range of 0-" << (arraySize - 1);
				}
				sampleArray.insert(positionValue, inputValue);
				std::cout << dye::green("[+]") << " Value " << inputValue << " inputted to the position " << positionValue;
				break;
			case 2:
				validPosition = false;
				while (!validPosition)
				{
					std::cout << dye::yellow("[!]") << "Input a position where an element will be deleted from the array:";
					positionValue = getIntInputFromUser();
					if (positionValue >= 0 && positionValue < arraySize)
						validPosition = true;
					else
						std::cout << dye::red("[-]") << "The position must be in the range of 0-" << (arraySize - 1);
				}
				sampleArray.del(positionValue);
				std::cout << "Value deleted from position " << positionValue;
				break;
			case 3:
				std::cout << dye::yellow("[!]") << "Input a value to be searched from the array:";
				inputValue = getIntInputFromUser();
				sampleArray.search(inputValue);
				break;
			case 4:
				std::cout << "Original array:";
				sampleArray.display();
				std::cout << "\n\n";
				sampleArray.reverse();
				std::cout << "\nReversed array:";
				sampleArray.display();
				break;
			case 5:
				std::cout << "Array:\n\n";
				sampleArray.display();
				break;
			case 6:
				menuLoop = false;
				break;
			default:
				std::cout << dye::red("[-]") << "The input value must be an integer between 1-6.";
				break;
		}

	}
	return;
}