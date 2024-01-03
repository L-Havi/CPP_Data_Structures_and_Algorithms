/*
 *  Utilities that can be used in multiple locations
 *  Includes integer input fetching and parsing it
 */

#include <iostream>
#include <string>
#include <stdexcept>

#include "CommonUtils.hpp"

bool tryParse(std::string& input, int& output) {
	try {
		output = std::stoi(input);
	}
	catch (std::invalid_argument) {
		return false;
	}
	return true;
}

int getIntInputFromUser()
{
	std::string input;
	int x;

	getline(std::cin, input);
	while (!tryParse(input, x))
	{
		std::cout << "Bad entry. Enter an integer value: ";
		getline(std::cin, input);
	}
	return x;
}
