/*
 *  Implementation of various Multidimensional (3D or polynomial) Array operations
 *
 *  These include adding two Multidimensional Arrays together & appending an element in the Multidimensional Array.
 *  Also, displaying the entire Multidimensional Array.
 *  The Multidimensional Array in this case is an integer Multidimensional Array
 *
 *  A 3-dimensional array can be thought of as an array of arrays of arrays.
 *  For any 3-D array a[x][y][z] arranged in Row Major fashion the element
 *	a[i][j][k] can be accessed using Base address + i * y * z + j * z + k.
 *	The formula for Column Major arrangement would be Base address + i * y * z + k * y + j.
 */

#include "multidimensionalArrayOperations.hpp"
#include "RandomUtils.hpp"
#include "CommonUtils.hpp"
#include "color.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

 // Initializes data members of class poly
poly::poly()
{
	noOfTerms = 0;
	for (int i = 0; i < multidimensionalArraySize; i++)
	{
		t[i].coefficient = 0;
		t[i].exponent = 0;
	}
}

// Adds the term of polynomial to the array t
void poly::polyAppend(int coeff, int exp)
{
	t[noOfTerms].coefficient = coeff;
	t[noOfTerms].exponent = exp;
	noOfTerms++;
}

// adds two polynomials poly1 and poly2
void poly::polyAdd(poly &poly1, poly &poly2)
{
	int c = poly1.noOfTerms > poly2.noOfTerms ? poly1.noOfTerms : poly2.noOfTerms;
	for (int i = 0, j = 0; i <= c; noOfTerms++)
	{
		if (poly1.t[i].coefficient == 0 && poly2.t[j].coefficient == 0)
			break;
		if (poly1.t[i].exponent >= poly2.t[j].exponent)
		{
			if (poly1.t[i].exponent == poly2.t[j].exponent)
			{
				t[noOfTerms].coefficient = poly1.t[i].coefficient + poly2.t[j].coefficient;
				t[noOfTerms].exponent = poly1.t[i].exponent;
				i++;
				j++;
			}
			else
			{
				t[noOfTerms].coefficient = poly1.t[i].coefficient;
				t[noOfTerms].exponent = poly1.t[i].exponent;
				i++;
			}
		}
		else
		{
			t[noOfTerms].coefficient = poly2.t[j].coefficient;
			t[noOfTerms].exponent = poly2.t[j].exponent;
			j++;
		}
	}
}

// multiply two polynomials poly1 and poly2
void poly::polyMultiply(poly& poly1, poly& poly2)
{
	int coeff, exp;
	poly t1, t2;
	if (poly1.noOfTerms != 0 && poly2.noOfTerms != 0)
	{
		for (int i = 0; i < poly1.noOfTerms; i++)
		{
			poly p;
			for (int j = 0; j < poly2.noOfTerms; j++)
			{
				coeff = poly1.t[i].coefficient * poly2.t[j].coefficient;
				exp = poly1.t[i].exponent + poly2.t[j].exponent;
				p.polyAppend(coeff, exp);
			}
			if (i != 0)
			{
				t2.polyAdd(t1, p);
				t1 = t2;
			}
			else
				t1 = p;
		}
		*this = t2;
	}
}

// Displays the polynomial equation
void poly::display()
{
	int flag = 0;
	for (int i = 0; i < noOfTerms; i++)
	{
		if (t[i].exponent != 0)
			std::cout << t[i].coefficient << "x^" << t[i].exponent << " + ";
		else
		{
			std::cout << t[i].coefficient;
			flag = 1;
		}
	}
	if (!flag)
		std::cout << "\b\b ";
}

poly createRandomPoly()
{
	int exponent = generateRandomInteger(4, 10);

	int randInt;

	int polySize = 5;

	poly genPoly;

	std::cout << dye::green("[+]") << " Starting by generating a random 5 elements long polynomial\n";
	std::cout << dye::green("[+]") << " Setting starting exponent to " << exponent << "\n";

	for (int i = 0; i < polySize; i++)
	{
		randInt = generateRandomInteger(1, 10);
		genPoly.polyAppend(randInt, exponent);
		if (exponent != 0) 
		{
			std::cout << dye::green("[+]") << " Generated: " << randInt << "x^" << exponent << "\n";
		}
		else
		{
			std::cout << dye::green("[+]") << " Generated: " << randInt << "\n";
		}
		exponent--;
	}
	std::cout << dye::green("[+]") << " Generated a random polynomial: \n";
	genPoly.display();
	std::cout << "\n\n";
	return genPoly;
}

void multidimensionalArrayOperationsMenu() 
{

	int choice;
	bool menuLoop = true;

	poly poly1 = createRandomPoly();
	poly poly2 = createRandomPoly();
	poly addedPoly;
	poly multipliedPoly;

	std::cout << dye::green("[+]")  << " Generated a random polynomials 1 & 2: \n";
	std::cout << dye::green("[+]") << " Polynomial 1: ";
	poly1.display();
	std::cout << dye::green("\n[+]") << " Polynomial 2: ";
	poly2.display();

	while (menuLoop)
	{
		std::cout << "\nChoose your action: \n" << "1. Add Polynomials\n"
			<< "2. Multiply Polynomials\n" << "3. Display Polynomials\n"
			<< "4. Exit to Main Menu\n";

		choice = getIntInputFromUser();
		switch (choice)
		{
		case 1:
			std::cout << "\Polynomial 1:\n";
			poly1.display();
			std::cout << "\n";

			std::cout << "\Polynomial 2:\n";
			poly2.display();
			std::cout << "\n";

			std::cout << dye::green("[+]") << " Adding these polynomials together\n\n";
			std::cout << "Polynomials 1 & 2 added together:\n";

			addedPoly.polyAdd(poly1, poly2);

			std::cout << "\nResult Polynomial:\n";
			addedPoly.display();
			std::cout << "\n";
			break;
		case 2:
			std::cout << "\Polynomial 1:\n";
			poly1.display();
			std::cout << "\n";

			std::cout << "\Polynomial 2:\n";
			poly2.display();
			std::cout << "\n";

			std::cout << dye::green("[+]") << " Multiplying these polynomials together\n\n";
			std::cout << "Polynomials 1 & 2 multiplied together:\n";

			multipliedPoly.polyMultiply(poly1, poly2);
			std::cout << "\nResult Polynomial:\n";
			multipliedPoly.display();
			std::cout << "\n";
			break;
		case 3:
			std::cout << "\Polynomial 1:\n";
			poly1.display();
			std::cout << "\n";

			std::cout << "\Polynomial 2:\n";
			poly2.display();
			std::cout << "\n";
			break;
		case 4:
			menuLoop = false;
			break;
		default:
			std::cout << dye::red("[-]") << " The input value must be an integer between 1-4.";
			break;
		}

	}
	return;

}