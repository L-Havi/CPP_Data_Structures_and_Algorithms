/*
 *  Demonstration of different Data Structures and Algorithms written in C++.
 * 
 *  The point is to also demonstrate the steps these algorithms take to achieve their goal by describing all steps in the console.
 * 
 */

#include "OneDimensionalArrayOperations.h"
#include "TwoDimensionalArrayOperations.h"
#include "multidimensionalArrayOperations.h"
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
		std::cout << "\n-------------------------------------------------------------------------\n|\t\t\t\t\t\t\t\t\t|\n|";
			std::cout << "\tWelcome to C++ Algorithms & Datastructures demonstration!\t|\n|\t\t\t\t\t\t\t\t\t|\n";
			std::cout << "-------------------------------------------------------------------------\n|"
			<< "\tChoose a number to view different operations:\t\t\t|\n";
			std::cout << "-------------------------------------------------------------------------\n"
			<< "|\t1. One Dimensional Array Operations\t\t\t\t|\n" 
			<< "|\t2. Two Dimensional Array (Matrix) Operations\t\t\t|\n"
			<< "|\t3. Multidimensional Array (3-Dimensional) Operations\t\t\t|\n"
			<< "|\t999. Exit program\t\t\t\t\t\t|\n";
			std::cout << "-------------------------------------------------------------------------\n";

		choice = getIntInputFromUser();
		switch (choice)
		{
		case 1:
			arrayOperationsMenu();
			break;
		case 2:
			twoDimensionalArrayOperationsMenu();
			break;
		case 3:
			multidimensionalArrayOperationsMenu();
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