#include<iostream>
#include<fstream>
using namespace std;

int** InputMatrix(ifstream& fin, int& rows, int& cols)
{
	fin >> rows;
	fin >> cols;
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(matrix + i) = new int[cols];
	}
	int** endRowPtr = matrix + rows;
	for (int** iPtr = matrix; iPtr < endRowPtr; iPtr++)
	{
		int* endColPtr = *iPtr + cols;
		for (int* jPtr = *iPtr; jPtr < endColPtr; jPtr++)
		{
			fin >> *jPtr;
		}
	}
	return matrix;
}

void OutputMatrix(int** matrix, const int& rows, const int& cols)
{
	int** endRowPtr = matrix + rows;
	for (int** iPtr = matrix; iPtr < endRowPtr; iPtr++)
	{
		int* endColPtr = *iPtr + cols;
		for (int* jPtr = *iPtr; jPtr < endColPtr; jPtr++)
		{
			cout << *jPtr << " ";
		}
		cout << endl;
	}
}

int** AddMatrix(int** matrixA, int** matrixB, const int& rows, const int& cols)
{
	int** matrixC = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(matrixC + i) = new int[cols];
	}

	int** endRowPtr = matrixA + rows;
	for (int** iPtr1 = matrixA,** iPtr2 = matrixB,** iPtr3 = matrixC; iPtr1 < endRowPtr; iPtr1++, iPtr2++, iPtr3++)
	{
		int* endColPtr = *iPtr1 + cols;
		for (int* jPtr1 = *iPtr1,* jPtr2 = *iPtr2,* jPtr3 = *iPtr3; jPtr1 < endColPtr; jPtr1++, jPtr2++, jPtr3++)
		{
			*jPtr3 = *jPtr1 + *jPtr2;
		}
	}
	return matrixC;
}

int** TransposeMatrix(int** matrix, const int& rows, const int& cols)
{
	int** trans = new int* [cols];
	for (int i = 0; i < cols; i++)
	{
		*(trans + i) = new int[rows];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(*(trans + j) + i) = *(*(matrix + i) + j);
		}
	}
	return trans;
}

bool IsSymmetric(int** matrix, const int& rows, const int& cols)
{
	int** trans;
	trans = TransposeMatrix(matrix, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (*(*(trans + i) + j) != *(*(matrix + i) + j))
			{
				return false;
			}
		}
	}
	return true;
}

void InterchangeRows(int** matrix, const int& rows, const int& cols)
{
	int temp;
	int row1 = 1, row2 = 3;
	for (int j = 0; j < cols; j++)
	{
		temp = *(*(matrix + row1 - 1) + j);
		*(*(matrix + row1 - 1) + j) = *(*(matrix + row2 - 1) + j);
		*(*(matrix + row2 - 1) + j) = temp;
	}
}

void InterchangeRows(int*& row1, int*& row2)
{
	int* temp;
	temp = row1;
	row1 = row2;
	row2 = temp;
}

void DeallocateMemory(int** matrix, const int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}

int main()
{
	int rows1 = 0, cols1 = 0, rows2 = 0, cols2 = 0, rows3 = 0, cols3 = 0;
	int** matrixA;
	int** matrixB;
	int** matrixC;
	int** trans;

	ifstream fin("InputFile.txt");

	//MatrixA
	matrixA=InputMatrix(fin, rows1, cols1);
	cout << "Matrix A = " << endl;
	OutputMatrix(matrixA, rows1, cols1);
	cout << endl << endl;

	//MatrixB
	matrixB = InputMatrix(fin, rows2, cols2);
	cout << "Matrix B = " << endl;
	OutputMatrix(matrixB, rows2, cols2);
	cout << endl << endl;

	//MatrixC
	matrixC = InputMatrix(fin, rows3, cols3);
	cout << "Matrix C = " << endl;
	OutputMatrix(matrixC, rows3, cols3);
	cout << endl << endl;

	//MatrixA + MatrixB
	cout << "A + B = " << endl;
	if (rows1 == rows2 && cols1 == cols2)
	{
		int** MatrixAdd;
		MatrixAdd = AddMatrix(matrixA, matrixB, rows1, cols1);
		OutputMatrix(MatrixAdd, rows1, cols1);
		DeallocateMemory(MatrixAdd, rows1);
	}
	else
	{
		cout << "Addition not possible." << endl;
	}
	cout << endl << endl;

	//MatrixA + MatrixC
	cout << "A + C = " << endl;
	if (rows1 == rows3 && cols1 == cols3)
	{
		int** MatrixAdd;
		MatrixAdd = AddMatrix(matrixA, matrixC, rows1, cols1);
		OutputMatrix(MatrixAdd, rows1, cols1);
		DeallocateMemory(MatrixAdd, rows1);
	}
	else
	{
		cout << "Addition not possible." << endl;
	}
	cout << endl << endl;

	//Transpose of Matrix A
	cout << "Transpose of A = " << endl;
	trans = TransposeMatrix(matrixA, rows1, cols1);
	OutputMatrix(trans, cols1, rows1);
	cout << endl << endl;

	//Transpose of Matrix C
	cout << "Transpose of C = " << endl;
	trans = TransposeMatrix(matrixC, rows3, cols3);
	OutputMatrix(trans, cols3, rows3);
	cout << endl << endl;

	//Checkng if Matrix A is symmetric
	bool symmetry = IsSymmetric(matrixA, rows1, cols1);
	if (symmetry == true)
	{
		cout << "Matrix A is Symmetric." << endl << endl;
	}
	else
	{
		cout << "Matrix A is NOT Symmetric" << endl << endl;
	}

	//Checkng if Matrix B is symmetric
	symmetry = IsSymmetric(matrixB, rows2, cols2);
	if (symmetry == true)
	{
		cout << "Matrix B is Symmetric." << endl << endl;
	}
	else
	{
		cout << "Matrix B is NOT Symmetric" << endl << endl;
	}

	//Interchanging rows through swapping values
	cout << "Interchanging Rows of Matrix A: " << endl;
	cout << "row1: 1\nrow2: 3\n\n\nAfter Interchanging Rows Matrix A=" << endl;
	InterchangeRows(matrixA, rows1, cols1);
	OutputMatrix(matrixA, rows1, cols1);
	cout << endl << endl;

	//Interchanging rows through swapping address of rows
	cout << "Interchanging Rows of Matrix A: " << endl;
	cout << "row1: 1\nrow2: 3\n\n\nAfter Interchanging Rows Matrix A=" << endl;
	InterchangeRows(*(matrixA + 0), *(matrixA + 2));
	OutputMatrix(matrixA, rows1, cols1);
	cout << endl << endl;

	DeallocateMemory(matrixA, rows1);
	DeallocateMemory(matrixB, rows2);
	DeallocateMemory(matrixC, rows3);
	DeallocateMemory(trans, rows3);

	system("pause");
	return 0;
}