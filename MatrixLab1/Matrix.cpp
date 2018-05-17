#include "Matrix.h"
#include <iostream>
#include "Complex.h"
#include <fstream>


Matrix::Matrix()
{
	m = n = 3;
}

Matrix::Matrix(int rows, int cols)
{
	n = rows;
	m = cols;
	elements.resize(n);
	for (int i = 0; i < n; i++)
		elements[i].resize(m);
}

Matrix Matrix::operator+ (Matrix matrix)
{
	if (elements.size() != matrix.elements.size() || elements[0].size() != matrix.elements[0].size()) {
		throw exception("Matrix addition is impossible.\nMatrixes size must be same\n");
	}

	Matrix newMatrix = Matrix(elements.size(), elements[0].size());

	for (int i = 0; i < elements.size(); i++)
		for (int j = 0; j < elements[i].size(); j++) 
			newMatrix.elements[i][j] = (elements[i][j] + matrix.elements[i][j]);

	return newMatrix;
};

Matrix Matrix::operator- (Matrix matrix)
{
	if (elements.size() != matrix.elements.size() || elements[0].size() != matrix.elements[0].size())
		throw exception("Matrix subtraction is impossible.\nMatrixes size must be same\n");

	Matrix newMatrix = Matrix(elements.size(), elements[0].size());

	for (int i = 0; i < elements.size(); i++)
		for (int j = 0; j < elements[i].size(); j++)
			newMatrix.elements[i][j] = elements[i][j] - matrix.elements[i][j];

	return newMatrix;
};

Matrix Matrix::operator* (Matrix matrix)
{
	if (elements[0].size() != matrix.elements.size() )
		throw exception("Matrix multiplication is impossible.\nThe number of columns of the first matrix should be equal to the number of rows of the second matrix\n");

	Matrix newMatrix = Matrix(elements.size(), matrix.elements[0].size());

	for (int i = 0; i < elements.size(); i++)
		for (int j = 0; j < matrix.elements[i].size(); j++)
			for (int k = 0; k < elements[i].size(); k++)
				newMatrix.elements[i][j] = newMatrix.elements[i][j] + elements[i][k] * matrix.elements[k][j];

	return newMatrix;
};


Complex Matrix::findDetermenant()
{
	int sign = 1;
	Complex result = Complex();
	bool skipCol = false;
	bool skipRow = false;
	if (elements.size() != elements[0].size())
		throw exception("Cannot find the determinat of matrix. Matrix must be n*n size!\n");
	// определитель матрицы 1*1
	if (elements.size() == 1)
		return elements[0][0];
	//определитель матрицы 2*2
	if (elements.size() == 2) {
		return elements[0][0]*elements[1][1] - elements[1][0]*elements[0][1];
	}
	// определитель матрицы n*n
	if (elements.size() > 2) {
		for (int k = 0; k < n; k++) {
			if (sign == 1)
				result = result + elements[0][k] * findSmallerMatrix(elements, 0, k, elements.size() - 1, elements.size() - 1).findDetermenant();
			else
				result = result - elements[0][k] * findSmallerMatrix(elements, 0, k, elements.size() - 1, elements.size() - 1).findDetermenant();
			sign = -sign;
		}
	}

	return result;
};

Matrix Matrix::findSmallerMatrix(vector <vector <Complex>> elements, int rowNum, int colNum, int n,int m) {
	Matrix smallerMatrix = Matrix(elements.size() - 1, elements[0].size() - 1);

	bool skipCol = false;
	bool skipRow = false;
	for (int i = 0; i < elements.size() - 1; i++) {
		skipCol = false;
		if (i == rowNum) {
			skipRow = true;
		}
		for (int j = 0; j < elements.size() - 1; j++) {
			if (colNum == j) {
				skipCol = true;
			}
			if (skipCol == true) {
				if (skipRow == true)
					smallerMatrix.elements[i][j] = elements[i + 1][j + 1];
				else
					smallerMatrix.elements[i][j] = elements[i][j + 1];
			}
			else
				if (skipRow == true)
					smallerMatrix.elements[i][j] = elements[i + 1][j];
				else
					smallerMatrix.elements[i][j] = elements[i][j];
		}
	}
	return smallerMatrix;
}

void Matrix::outToConsole() 
{
	for (int i = 0; i < elements.size(); i++)
	{
		for (int j = 0; j < elements[i].size(); j++)
			cout << elements[i][j].toString() + " ";
		cout << "\n";
	}
}
void Matrix::outToFile()
{
	ofstream file("results.txt");
	file << elements.size() << "\n";
	file << elements[0].size() << "\n";
	for (int i = 0; i < elements.size(); i++)
	{
		for (int j = 0; j < elements[i].size(); j++)
			if(j == elements[i].size()-1)
				file << elements[i][j].toString();
			else
				file << elements[i][j].toString() + " ";
		file << "\n";
	}
}

Matrix::~Matrix()
{
}
