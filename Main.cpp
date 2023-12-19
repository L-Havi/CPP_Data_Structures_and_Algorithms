/*
 *  Demonstration of different Data Structures and Algorithms written in C++.
 */

#include "OneDimensionalArrayOperations.h"
#include "TwoDimensionalArrayOperations.h"
#include "RandomUtils.h"
#include "CommonUtils.h"

#include <iostream>
#include <string>
#include <stdexcept>

int main() {

	int choice;
	bool programOn = true;

	while (programOn) 
	{
		std::cout << "Welcome to C++ Algorithms & Datastructures demonstration!\n"
			<< "Choose a number to view different operations\n"
			<< "1. One Dimensional Array Operations\n" 
			<< "2. Two Dimensional Array (Matrix) Operations\n"
			<< "999. Exit program\n";

		choice = getIntInputFromUser();
		switch (choice)
		{
		case 1:
			arrayOperationsMenu();
			break;
		case 2:
			twoDimensionalArrayOperationsMenu();
			break;
		case 999:
			programOn = false;
			break;
		default:
			std::cout << "The inputted value must be in the range of 1-2 or 999 to exit";
			break;
		}
	}
	return 0;
}