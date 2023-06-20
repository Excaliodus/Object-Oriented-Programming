#include<iostream>
using namespace std;

int** AllocateMemory(int& rows, int& cols)
{
	cout << "Enter the number of columns in the array." << endl;
	cin >> cols;
	cout << "Enter the number of rows in the array." << endl;
	cin >> rows;
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
}

void InputMatrix(int** matrix, const int& rows, const int& cols)
{
	int** endRowPtr = matrix + rows;
	cout << "Enter int Values into the matrix." << endl;
	for (int** iPtr = matrix; iPtr < endRowPtr; iPtr++)
	{
		int* endColPtr = *iPtr + cols;
		for (int* jPtr = *iPtr; jPtr < endColPtr; jPtr++)
		{
			cin >> *jPtr;
		}
	}
}

void DisplayMatrix(int** matrix, const int& rows, const int& cols)
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

void DeallocateMemory(int** matrix, const int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;
}

int* MaxofColumn(int** matrix, const int& rows, const int& cols)
{
	int* maxValue = new int [rows];
	int k = 0;
	int** endRowPtr = matrix + rows;
	for (int** iPtr = matrix; iPtr < endRowPtr; iPtr++)
	{
		int* endColPtr = *iPtr + cols;
		for (int* jPtr = *iPtr; jPtr < endColPtr; jPtr++)
		{
			if (jPtr == *iPtr)
			{
				*(maxValue + k) = *jPtr;
			}
			else if (*(maxValue + k) < *jPtr)
			{
				*(maxValue + k) = *jPtr;
			}
		}
		k++;
	}
	return maxValue;
}

void OutputArray(int* originalArr, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(originalArr + i) << " ";
	}
	cout << endl;
}

int* GetDiagonal(int** matrix, const int& rows, const int& cols)
{
	int* Diagonal = new int[rows];
	int k = 0;
	int** endRowPtr = matrix + rows;
	for (int** iPtr = matrix; iPtr < endRowPtr; iPtr++)
	{
		int* endColPtr = *iPtr + cols;
		for (int* jPtr = *iPtr; jPtr < endColPtr; jPtr++)
		{
			if (jPtr == *iPtr)
			{
				*(Diagonal + k) = *jPtr;
				k++;
			}
		}
	}
	return Diagonal;
}

int main()
{
	int rows = 0, cols = 0;
	int** matrix;
	int* max;
	int* diagonal;
	
	matrix = AllocateMemory(rows, cols);

	InputMatrix(matrix, rows, cols);
	
	cout << "The matrix entered is the following:" << endl;
	DisplayMatrix(matrix, rows, cols);
	max = MaxofColumn(matrix, rows, cols);
	
	cout << "The Max values of each are column are: " << endl;
	OutputArray(max, rows);
	DeallocateMemory(matrix, rows);

	cout << "The diagonal values of the Matrix are: " << endl;
	diagonal = GetDiagonal(matrix, rows, cols);
	OutputArray(diagonal, rows);

	delete[]diagonal;
	delete[]max;
	system("pause");
	return 0;
} 