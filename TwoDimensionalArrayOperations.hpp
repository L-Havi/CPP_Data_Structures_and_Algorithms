#pragma once

//Header file for TwoDimensionalArrayOperations.cpp

const int twoDimensionalArraySize = 5;

class matrix
{
private:
	int mat[twoDimensionalArraySize][twoDimensionalArraySize];
public:
	matrix();
	void create();
	void display();
	void matrixAdd(matrix & matrix1, matrix &matrix2);
	void matrixMultiply(matrix &matrix1, matrix &matrix2);
	void transpose(matrix &matrix1);
};

void twoDimensionalArrayOperationsMenu();