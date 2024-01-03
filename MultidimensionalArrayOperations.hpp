#pragma once

//Header file for MultidimensionalArrayOperations.cpp

const int multidimensionalArraySize = 10;

class poly
{
private:
	struct term
	{
		int coefficient;
		int exponent;
	} 
	t[multidimensionalArraySize];
	int noOfTerms;
public:
	poly();
	void polyAppend(int coeffifient, int exponent);
	void polyAdd(poly &poly1, poly &poly2);
	void polyMultiply(poly& poly1, poly& poly2);
	void display();
};

poly createRandomPoly();

void multidimensionalArrayOperationsMenu();