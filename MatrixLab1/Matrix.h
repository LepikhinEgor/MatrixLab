#include "Complex.h"
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#pragma once

class Matrix
{
public:
	int n;
	int m;
	vector <vector <Complex>> elements;
	//Complex elements[N][M];
	Matrix();
	Matrix(int rows, int cols);
	~Matrix();
	Complex findDetermenant();
	Matrix findSmallerMatrix(vector <vector <Complex>> elements, int rowNum, int colNum, int n, int m);

	Matrix operator+ (Matrix matrix);
	Matrix operator- (Matrix matrix);
	Matrix operator* (Matrix matrix);

	void outToConsole();
	void outToFile();
};