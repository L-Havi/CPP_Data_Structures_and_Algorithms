#pragma once

//Header file for OneDimensionalArrayOperations.cpp

const int arraySize = 5;

class array
{
private:
	int arr[arraySize];
public:
	void insert(int position, int number);
	void del(int position);
	void reverse();
	void display();
	void search(int number);
};

array createRandomArray();

void arrayOperationsMenu();