/* 
 *  Implementation of various Array operations
 * 
 *  These include adding, searcing & deleting an element in the array. 
 *  Also, reversing & displaying the entire Array.
 *  The Array in this case is an integer Array
 * 
 *  An Array itself is a finite collection of similar elements stored in adjacent
 *  memory locations. An array containing n number of elements is
 *  referenced using an index that varies from 0 to n - 1.
 */

#include "OneDimensionalArrayOperations.h"
#include "RandomUtils.h"
#include "CommonUtils.h"

#include <iostream>
#include <string>
#include <stdexcept>



//insert an element to the given position in array
void array::insert(int position, int number) 
{
	int i;
	//Shift elements to right
	for (i = arraySize - 1; i >= position; i--)
		arr[i] = arr[i - 1];
	arr[i] = number;
}

//Delete an element from array at given position
void array::del(int position)
{
	int i;
	//Skip to the position
	for (i = position; i < arraySize; i++)
		arr[i - 1] = arr[i];
	arr[i - 1] = 0;
}

//Search for an element from the array
void array::search(int number)
{
	int i;
	for (i = 0; i < arraySize; i++)
	{
		if (arr[i] == number)
		{
			std::cout << "\n" << "Element " << number
				<< " is at " << (i + 1) << "th position in the array.";
			return;
		}
	}

	if (i == arraySize)
		std::cout << "\n" << "Element " << number << " is not in the array.";

}

//Reverse the array
void array::reverse()
{
	for (int i = 0; i < arraySize / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[arraySize - 1 - i];
		arr[arraySize - 1 - i] = temp;
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

	std::cout << "[+] Starting by generating a random " << arraySize << " elements long array\n";

	for (int i = 0; i < arraySize; i++)
	{
		randInt = generateRandomInteger();
		std::cout << "[+] " << (i + 1) << ". random value assigned to " << randInt << "\n";
		arr.insert(i + 1, randInt);
	}
	std::cout << "[+] Generated a random array \n";

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
				std::cout << "Input a value to be inputted to the array:";
				inputValue = getIntInputFromUser();
				validPosition = false;
				while (!validPosition)
				{
					std::cout << "Input an input position for the element:";
					positionValue = getIntInputFromUser();
					if (positionValue >= 0 && positionValue < arraySize)
						validPosition = true;
					else
						std::cout << "The position must be in the range of 0-" << (arraySize - 1);
				}
				sampleArray.insert(positionValue, inputValue);
				std::cout << "Value " << inputValue << " inputted to the position " << positionValue;
				break;
			case 2:
				validPosition = false;
				while (!validPosition)
				{
					std::cout << "Input a position where an element will be deleted from the array:";
					positionValue = getIntInputFromUser();
					if (positionValue >= 0 && positionValue < arraySize)
						validPosition = true;
					else
						std::cout << "The position must be in the range of 0-" << (arraySize - 1);
				}
				sampleArray.del(positionValue);
				std::cout << "Value deleted from position " << positionValue;
				break;
			case 3:
				std::cout << "Input a value to be searched from the array:";
				inputValue = getIntInputFromUser();
				sampleArray.search(inputValue);
				break;
			case 4:
				std::cout << "Original array:\n";
				sampleArray.display();
				std::cout << "Reversed array:\n";
				sampleArray.reverse();
				sampleArray.display();
				break;
			case 5:
				std::cout << "Array:\n";
				sampleArray.display();
				break;
			case 6:
				menuLoop = false;
				break;
			default:
				std::cout << "The input value must be an integer between 1-6.";
				break;
		}

	}
	return;
}