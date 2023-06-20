#include<iostream>
using namespace std;

int* inputArray(int& size)
{
	cout << "Enter the size of the array." << endl;
	cin >> size;

	int* myArrayptr = new int[size];
	cout << "Enter values into the array." << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> *(myArrayptr + i);
	}
	return myArrayptr;
}

void OutputArray(int* originalArr, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(originalArr + i) << " ";
	}
	cout << endl;
}

int* ResizeArray(int* orignalArr, int& size)
{
	size_t newsize = size + 1;
	int* newArr = new int[newsize];

	memcpy(newArr, orignalArr, size * sizeof(int));
	size = newsize;
	delete[]orignalArr;
	orignalArr = newArr;
	return orignalArr;
}

int* CompressArray(int* array, int& size, int& size1)
{
	size1 = 1;
	int* comp = new int[size1];
	*comp = *array;
	int k = 1;
	for (int i = 1; i < size; i++)
	{
		if (array[i] > array[i - 1])
		{
			comp = ResizeArray(comp, size1);
			comp[k] = array[i];
			k++;
		}
	}
	return comp;
}

void intersection(int* setA, int& size1, int* setB, int& size2) 
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (setA[i] == setB[j])
			{
				cout << setA[i] << " ";
			}
		}
	}
	cout << endl;
}

int main()
{
	int size = 1;
	int size1 = 1;
	int* array;
	int* comp;
	array = inputArray(size);
	comp = CompressArray(array, size, size1);
	cout << "The compressed array is:" << endl;
	OutputArray(comp, size1);
	delete[]array;
	delete[]comp;

	int size2 = 1;
	int size3 = 1;
	int* setA = inputArray(size2);
	int* setB = inputArray(size3);

	cout << "The intersection of the 2 sets is: ";
	intersection(setA, size2, setB, size3);

	delete[] setA;
	delete[] setB;

	system("pause");
	return 0;
}