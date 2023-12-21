/*
 *  Implementation of various Matrix operations
 *
 *  These include adding & multiplying 2 Matrices.
 *  Also, transposing & displaying the entire Matrix.
 *  The Matrix in this case is an integer Matrix
 *
 *  A 2-dimensional array (Matrix) is a collection of elements placed in m rows and n
 *  columns. The syntax used to declare a 2-D array includes two subscripts,
 *  of which one specifies the number of rows and the other specifies the
 *  number of columns of an array. These two subscripts are used to
 *  reference an element in an array.
 */

#include <iostream>

#include "RandomUtils.h"
#include "CommonUtils.h"
#include "TwoDimensionalArrayOperations.h"

// initializes the matrix with zeroes
matrix::matrix()
{
	for (int i = 0; i < twoDimensionalArraySize; i++)
	{
		for (int j = 0; j < twoDimensionalArraySize; j++)
			mat[i][j] = 0;
	}
}

//Creates a random matrix
void matrix::create()
{
	int randInt;

	std::cout << "[+] Generating a random (" << twoDimensionalArraySize << ", " << twoDimensionalArraySize << ") Matrix\n";

	for (int i = 0; i < twoDimensionalArraySize; i++)
	{
		for (int j = 0; j < twoDimensionalArraySize; j++)
		{
			randInt = generateRandomInteger();
			std::cout << "[+] (" << (i + 1) << ", " << (j + 1) << ") position's value assigned to " << randInt << "\n";
			mat[i][j] = randInt;
		}
	}
	std::cout << "[+] Generated a random Matrix \n";
}

//Displays the contents of the Matrix
void matrix::display()
{
	for (int i = 0; i < twoDimensionalArraySize; i++)
	{
		if (i == 0)
		{
			//First row of the Matrix
			std::cout << "{[";
		}
		else 
		{	
			//Other new rows of the Matrix
			std::cout << " [";
		}
		for (int j = 0; j < twoDimensionalArraySize; j++)
		{
			if (j == twoDimensionalArraySize -1)
			{
				//Last value of the row
				std::cout << mat[i][j];
			}
			else
			{
				//Other values of the row
				std::cout << mat[i][j] << ", ";
			}

		}
		if (i != twoDimensionalArraySize - 1)
		{
			//End of the other rows of the Matrix
			std::cout << "],\n";
		}
		else 
		{
			//End of the last row of the Matrix
			std::cout << "]}\n";
		}
	}
}

//Add two matrices (Matrix 1 & Matrix 2) together
void matrix::matrixAdd(matrix &matrix1, matrix &matrix2)
{
	std::cout << "[+] Starting to add 2 matrices (Matrix 1 [5, 5] & Matrix 2 [5, 5]) together:\n";
	for (int i = 0; i < twoDimensionalArraySize; i++)
	{
		for (int j = 0; j < twoDimensionalArraySize; j++)
		{
			mat[i][j] = matrix1.mat[i][j] + matrix2.mat[i][j];
			std::cout << "[+] Inserting Matrix 1 [" << i << ", " << j << "] (" << matrix1.mat[i][j] << ") + Matrix 2 [" 
				<< i << ", " << j << "] (" << matrix2.mat[i][j] << ")" << " to Result Matrix [" << i << ", " << j << "] (" << mat[i][j] << ")\n";

		}
	}
}

//Multiplies two matrices (Matrix 1 & Matrix 2) together
void matrix::matrixMultiply(matrix &matrix1, matrix &matrix2)
{
	std::cout << "[+] Starting to multiply 2 matrices (Matrix 1 [5, 5] & Matrix 2 [5, 5]) together:\n";
	for (int k = 0; k < twoDimensionalArraySize; k++)
	{
		for (int i = 0; i < twoDimensionalArraySize; i++)
		{
			for (int j = 0; j < twoDimensionalArraySize; j++)
			{
				mat[k][i] += matrix1.mat[k][j] * matrix2.mat[j][i];
				std::cout << "[+] Multiplying Matrix 1 [" << i << ", " << j << "] (" << matrix1.mat[i][j] << ") * Matrix 2 ["
					<< i << ", " << j << "] (" << matrix2.mat[i][j] << ")" << " to Result Matrix [" << i << ", " << j << "] (" << mat[i][j] << ")\n";
			}
		}
	}
}

// Obtains transpose of the Matrix
void matrix::transpose(matrix &matrix1)
{
	std::cout << "[+] Starting to transpose Matrix 1 [5, 5]:\n";
	for (int i = 0; i < twoDimensionalArraySize; i++)
	{
		for (int j = 0; j < twoDimensionalArraySize; j++)
		{
			mat[i][j] = matrix1.mat[j][i];
			std::cout << "[+] Transposing Matrix 1 [" << j << ", " << i << "] (" << matrix1.mat[j][i] << ") to Transposed Matrix 1 [" << i << ", " << j << "]\n";
		}
	}
}

void twoDimensionalArrayOperationsMenu()
{

	int choice;
	bool menuLoop = true;

	matrix matrix1;
	std::cout << "Creating a first random Matrix (Matrix 1)\n";
	matrix1.create();

	std::cout << "\nMatrix 1:\n";
	matrix1.display();
	std::cout << "\n";

	matrix matrix2;
	std::cout << "Creating a second random Matrix (Matrix 2)\n";
	matrix2.create();

	std::cout << "\nMatrix 2:\n";
	matrix2.display();
	std::cout << "\n";

	matrix addedMatrix;
	matrix multipliedMatrix;
	matrix transposedMatrix;

	while (menuLoop)
	{
		std::cout << "\nChoose your action: \n" << "1. Add Matrices\n"
			<< "2. Multiply Matrices\n" << "3. Transpose matrix\n"
			<< "4. Exit to Main Menu\n";

		choice = getIntInputFromUser();
		switch (choice)
		{
		case 1:
			std::cout << "\nMatrix 1:\n";
			matrix1.display();
			std::cout << "\n";

			std::cout << "\nMatrix 2:\n";
			matrix2.display();
			std::cout << "\n";

			std::cout << "[+] Adding these matrices together\n\n";
			std::cout << "Matrices 1 & 2 added together:\n";

			addedMatrix.matrixAdd(matrix1, matrix2);

			std::cout << "\nResult Matrix:\n";
			addedMatrix.display();
			std::cout << "\n";
			break;
		case 2:
			std::cout << "\nMatrix 1:\n";
			matrix1.display();
			std::cout << "\n";

			std::cout << "\nMatrix 2:\n";
			matrix2.display();
			std::cout << "\n";

			std::cout << "[+] Multiplying these matrices together\n\n";
			std::cout << "Matrices 1 & 2 multiplied together:\n";

			multipliedMatrix.matrixMultiply(matrix1, matrix2);
			std::cout << "\nResult Matrix:\n";
			multipliedMatrix.display();
			std::cout << "\n";
			break;
		case 3:
			std::cout << "\nMatrix 1:\n";
			matrix1.display();
			std::cout << "\n";

			std::cout << "[+] Transposing Matrix 1\n\n";
			transposedMatrix.transpose(matrix1);
			std::cout << "\nTransposed Matrix 1:\n";
			transposedMatrix.display();
			std::cout << "\n";
			break;
		case 4:
			menuLoop = false;
			break;
		default:
			std::cout << "The input value must be an integer between 1-4.";
			break;
		}

	}
	return;
}