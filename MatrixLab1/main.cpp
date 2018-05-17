#include "Complex.h"
#include <cstdio>
#include <iostream>
#include "Matrix.h"
#include "vector"
#include <fstream>
using namespace std;

int activeMenu(vector<Matrix> matrixes)
{
	int inputNum;
	int matrixNum1, matrixNum2;
	bool toFile = true, toConsole = true;

	Matrix resultMatrix;
	Complex det;

	cout << "Press 1 to display the result in a console\n";
	cout << "Press 2 to display the result in a file\n";
	cout << "Press 3 to display the result in a file and in a console\n";
	cout << "Press another button to exit\n\n";

	cin >> inputNum;
	switch (inputNum)
	{
	case 1:
		toConsole = true;
		toFile = false;
		break;
	case 2:
		toConsole = false;
		toFile = true;
		break;
	case 3:
		toConsole = true;
		toFile = true;
		break;
	default:
		break;
	}

	cout << "\nMenu\n";
	cout << "Press 1 to matrix addition\n";
	cout << "Press 2 to matrix subtraction\n";
	cout << "Press 3 to matrix multiplication\n";
	cout << "Press 4 to find determinant of matrix\n";
	cout << "Press another button to exit\n\n";

	cin >> inputNum;
	try {
		switch (inputNum)
		{
		case 1:
			cout << "Enter number of first matrix(from 1 to" << matrixes.size() << "): ";
			cin >> matrixNum1;
			matrixNum1--;

			cout << "Enter number of second matrix(from 1 to" << matrixes.size() << "): ";
			cin >> matrixNum2;
			matrixNum2--;
			cout << "\n";

			if (matrixNum1 >= matrixes.size() || matrixNum1 >= matrixes.size() ||
				matrixNum1 < 0 || matrixNum2 < 0) 
			{
				throw exception("You enter incorrect numbers of matrixes");
				break;
			}

			resultMatrix = matrixes[matrixNum1] + matrixes[matrixNum2];

			if (toConsole)
				resultMatrix.outToConsole();
			if (toFile)
				resultMatrix.outToFile();
			break;
		case 2:
			cout << "Enter number of first matrix(from 1 to" << matrixes.size() << "): ";
			cin >> matrixNum1;
			matrixNum1--;

			cout << "Enter number of second matrix(from 1 to" << matrixes.size() << "): ";
			cin >> matrixNum2;
			matrixNum1--;
			cout << "\n";

			if (matrixNum1 >= matrixes.size() || matrixNum1 >= matrixes.size() ||
				matrixNum1 < 0 || matrixNum2 < 0)
			{
				throw exception("You enter incorrect numbers of matrixes");
				break;
			}

			resultMatrix = matrixes[matrixNum1 - 1] - matrixes[matrixNum2 - 1];

			if (toConsole)
				resultMatrix.outToConsole();
			if (toFile)
				resultMatrix.outToFile();
			break;
		case 3:
			cout << "Enter number of first matrix(from 1 to" << matrixes.size() << "): ";
			cin >> matrixNum1;
			matrixNum1--;

			cout << "Enter number of second matrix(from 1 to" << matrixes.size() << "): ";
			cin >> matrixNum2;
			matrixNum2--;

			cout << "\n";
			if (matrixNum1 >= matrixes.size() || matrixNum1 >= matrixes.size() ||
				matrixNum1 < 0 || matrixNum2 < 0)
			{
				throw exception("You enter incorrect numbers of matrixes");
				break;
			}

			resultMatrix = matrixes[matrixNum1] * matrixes[matrixNum2];

			if (toConsole)
				resultMatrix.outToConsole();
			if (toFile)
				resultMatrix.outToFile();
			break;
		case 4:
			cout << "Enter number of matrix(from 1 to" << matrixes.size() << "): ";
			cin >> matrixNum1;
			cout << "\n";
			matrixNum1--;
			if (matrixNum1 < 0 || matrixNum1 >= matrixes.size())
			{
				throw exception("You enter incorrect number of matrix");
				break;
			}
			det = matrixes[matrixNum1].findDetermenant();
			cout << det.toString();
			break;
		default:
			return 0;
			break;
		}
	}
	catch (exception &ex)
	{
		if (toConsole)
			cout << "Error\n" << ex.what() << "\n";
		if (toFile) {
			ofstream file("results.txt");
			file << "Error\n" << ex.what() << "\n";
		}
	}
	return 1;
}

vector<Matrix> inputMatrixFromFile(string fileName)
{
	int buf;
	int num; // Количество матриц

	ifstream fin(fileName);
	fin >> num;

	vector<Matrix> matrixes(num);
	try {
		cout << matrixes.size() << " matrixes!\n";
		for (int i1 = 0; i1 < matrixes.size(); i1++)
		{
			int n;
			fin >> n;

			int m;
			fin >> m;
			matrixes[i1] = Matrix(n, m);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (fin >> buf)
						matrixes[i1].elements[i][j].setRealCoef(buf);
					else
						throw exception("File is damaged.");
					if (fin >> buf)
						matrixes[i1].elements[i][j].setImaginaryCoef(buf);
					else
						throw exception("File is damaged.");
				}
		}
	}
	catch (exception &ex)
	{
		cout << "Error\n" << ex.what() << "\n";
		return  vector<Matrix>(0);
	}
	fin.close();
	return matrixes;
}

vector<Matrix> inputMatrixFromConsole()
{
	int buf;
	int num; // Количество матриц

	cout << "Enter number of matrix\n";
	try
	{
		if (cin >> buf)
			num = buf;
		else
			throw exception("Not correct number of matrix.");
	}
	catch (exception &ex)
	{
		cout << "Error\n" << ex.what() << "\n";
		return  vector<Matrix>(0);
	}

	vector<Matrix> matrixes(num);
	try {
		for (int i1 = 0; i1 < matrixes.size(); i1++)
		{
			cout << "Input to matrix 1:\n";

			cout << "Enter matrix rows number\n";
			int n;
			cin >> n;

			cout << "Enter matrix columns number\n";
			int m;
			cin >> m;

			matrixes[i1] = Matrix(n, m);

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					cout << "Enter matrix element[" << i << "][" << j << "]\n";
					if (cin >> buf)
						matrixes[i1].elements[i][j].setRealCoef(buf);
					else
						throw exception("File is damaged.");
					if (cin >> buf)
						matrixes[i1].elements[i][j].setImaginaryCoef(buf);
					else
						throw exception("File is damaged.");
				}
		}
		return matrixes;
	}
	catch (exception &ex)
	{
		cout << "Error\n" << ex.what() << "\n";
		return  vector<Matrix>(0);
	}
}

int main() 
{
	int buf;
	;
	vector<Matrix> matrixes;
	cout << "Press 1 to input matrixes from console\n" << "Press 2 to input matrixes from file\n";
	cin >> buf;
	switch (buf) {
	case 1: matrixes = inputMatrixFromConsole(); break;
	case 2: matrixes = inputMatrixFromFile("tests.txt"); break;
	default: cout << "End of programm."; return -1;
	}
	if (matrixes.size() == 0)
		return -1;
	buf = 1;
	while (buf)
		buf = activeMenu(matrixes);
}

