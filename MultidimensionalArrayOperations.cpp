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

#include "multidimensionalArrayOperations.h"
#include "RandomUtils.h"
#include "CommonUtils.h"

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

// adds two polynomials p1 and p2
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