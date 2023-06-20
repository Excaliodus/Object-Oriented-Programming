#include<iostream>
#include<fstream>
using namespace std;

int* InputArray(ifstream& fin, int& size)
{
	fin >> size;		//reads the first int from the file i.e size of array

	if (size < 1)		//Checks weather or not size is a valid vlaue.
	{
		cout << "Error:\tArray Size should be greater than zero." << endl << endl << endl;
		return NULL;		//If size is invalid it reutrns Null.
	}
	else
	{
		int* myArrayPtr = new int[size];
		int* endArrayPtr = myArrayPtr + size;
		for (int* iptr = myArrayPtr; iptr < endArrayPtr; iptr++)
		{
			fin >> *iptr;		//Puts values into a dynamically allocate array.
		}
		return myArrayPtr;		//Returns the address for the created array.
	}
}

void swap(int* xp, int* yp)		//swapping values sent by bubblesort function.
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int* arr, const int& size)		//sorts arrays from file through bubble sort method.
{
	int* endArr = arr + size;
	for (int* iptr = arr; iptr < endArr - 1; iptr++)
	{
		int i = 0;
		i++;
		for (int* jptr = arr; jptr < endArr - i - 1; jptr++)
		{
			if (*jptr > *(jptr+ 1))
			{
				swap(&*jptr, &*(jptr + 1));
			}
		}
	}
}

void mergeArrays(int* arr1, int* arr2, const int& n1, const int& n2, int* arr3)
{
	// i, j, k point and traverse arrays 1, 2 and 3 respectively. 
	int* endArr3 = arr3 + n1 + n2;
	int* endArr1 = arr1 + n1;
	int* endArr2 = arr2 + n2;
	int* i = arr1;
	int* j = arr2;
	for (int* k = arr3; k < endArr3; k++)
	{
		/*If element of first array is less than element of second array or
		all values have been already taken from second array then element  
		from first array is kept in third array.*/
		if ((*i < *j && i < endArr1) || (j == endArr2))		
		{
			*k = *i;
			i++;
		}
		/*Else element from second array is kept in the third array.*/
		else
		{
			*k = *j;
			j++;
		}
	}
}

void DisplayArray(int* arr, const int& _size)		//function to print dynamic arrays.
{
	int* endArr = arr + _size;
	for (int* iptr = arr; iptr < endArr; iptr++)
	{
		if (iptr != arr)
		{
			cout << ", " << *iptr;
		}
		else
		{
			cout << *iptr;
		}
	}
	cout << endl;
}

int main()
{
	//BUBBLE SORT

	cout << "----------------------------------------Bubble Sort Result-----------------------------------------" << endl;

	ifstream fin1("Data1.txt");

	if (fin1.is_open())		//Checking if file has been opened
	{
		//first array

		int size = NULL;
		int* myArrayPtr = InputArray(fin1, size);

		if (myArrayPtr != NULL)
		{
			cout << "Test Case 1:\nArray before Sorting: " << endl;

			DisplayArray(myArrayPtr, size);

			bubbleSort(myArrayPtr, size);

			cout << "Array after Sorting: " << endl;

			DisplayArray(myArrayPtr, size);

			delete[] myArrayPtr;		//deletes array to avoid memory leakage. New array will be created for next set of inputs.
			myArrayPtr = NULL;

			cout << endl << endl << endl;
		}
		//second array

		size = NULL;
		myArrayPtr = InputArray(fin1, size);

		if (myArrayPtr != NULL)
		{
			cout << "Test Case 2:\nArray before Sorting: " << endl;

			DisplayArray(myArrayPtr, size);

			bubbleSort(myArrayPtr, size);

			cout << "Array after Sorting: " << endl;

			DisplayArray(myArrayPtr, size);

			delete[] myArrayPtr;		//deletes array to avoid memory leakage. New array will be created for next set of inputs.
			myArrayPtr = NULL;

			cout << endl << endl << endl;
		}
		//third array
		size = NULL;

		myArrayPtr = InputArray(fin1, size);

		if (myArrayPtr != NULL)
		{
			cout << "Test Case 3:\nArray before Sorting: " << endl;

			DisplayArray(myArrayPtr, size);

			bubbleSort(myArrayPtr, size);

			cout << "Array after Sorting: " << endl;

			DisplayArray(myArrayPtr, size);

			delete[] myArrayPtr;		//deletes array to avoid memory leakage. New array will be created for next set of inputs.
			myArrayPtr = NULL;

			cout << endl << endl << endl;
		}
		fin1.close();		//Closing the file as we are done reading it.
	}
	else
	{
		cout << "Cannot open file.\n";
	}

	//MERGE ARRAY

	cout << "----------------------------------------Merge Arrays Result-----------------------------------------" << endl;

	ifstream fin("Data2.txt");

	if (fin.is_open())		//Checking if file has been opened
	{
		//Test Case 1

		int size = NULL;
		int size1 = NULL;

		int* myArrayPtr = InputArray(fin, size);
		int* myArrayPtr1 = InputArray(fin, size1);
		if (myArrayPtr != NULL && myArrayPtr1 != NULL)
		{
			cout << "Test Case 1:\nArray 1: " << endl;

			DisplayArray(myArrayPtr, size);

			int* myArrayPtr2 = new int[size + size1];

			cout << "Array 2: " << endl;

			DisplayArray(myArrayPtr1, size1);

			mergeArrays(myArrayPtr, myArrayPtr1, size, size1, myArrayPtr2);

			cout << "\nSorted Merged Array: " << endl;

			DisplayArray(myArrayPtr2, (size + size1));

			delete[] myArrayPtr;		//deletes array to avoid memory leakage. New array will be created for next set of inputs.
			delete[] myArrayPtr1;
			delete[] myArrayPtr2;
			myArrayPtr = NULL, myArrayPtr1 = NULL, myArrayPtr2 = NULL;
			cout << endl << endl << endl;
		}

		//Test Case 2

		size = NULL;
		size1 = NULL;

		myArrayPtr = InputArray(fin, size);
		myArrayPtr1 = InputArray(fin, size1);
		if (myArrayPtr != NULL && myArrayPtr1 != NULL)
		{
			cout << "Test Case 2:\nArray 1: " << endl;

			DisplayArray(myArrayPtr, size);

			int* myArrayPtr2 = new int[size + size1];

			cout << "Array 2: " << endl;

			DisplayArray(myArrayPtr1, size1);

			mergeArrays(myArrayPtr, myArrayPtr1, size, size1, myArrayPtr2);

			cout << "\nSorted Merged Array: " << endl;

			DisplayArray(myArrayPtr2, (size + size1));

			delete[] myArrayPtr;		//deletes array to avoid memory leakage. New array will be created for next set of inputs.
			delete[] myArrayPtr1;
			delete[] myArrayPtr2;
			myArrayPtr = NULL, myArrayPtr1 = NULL, myArrayPtr2 = NULL;
			cout << endl << endl << endl;
		}

		//Test Case 3

		size = NULL;
		size1 = NULL;

		myArrayPtr = InputArray(fin, size);
		myArrayPtr1 = InputArray(fin, size1);
		if (myArrayPtr != NULL && myArrayPtr1 != NULL)
		{
			cout << "Test Case 3:\nArray 1: " << endl;

			DisplayArray(myArrayPtr, size);

			int* myArrayPtr2 = new int[size + size1];

			cout << "Array 2: " << endl;

			DisplayArray(myArrayPtr1, size1);

			mergeArrays(myArrayPtr, myArrayPtr1, size, size1, myArrayPtr2);

			cout << "\nSorted Merged Array: " << endl;

			DisplayArray(myArrayPtr2, (size + size1));

			delete[] myArrayPtr;		//deletes array to avoid memory leakage. New array will be created for next set of inputs.
			delete[] myArrayPtr1;
			delete[] myArrayPtr2;
			myArrayPtr = NULL, myArrayPtr1 = NULL, myArrayPtr2 = NULL;
			cout << endl << endl << endl;
		}
		fin.close();		//Closing the file as we are done reading it.
	}
	else
	{
		cout << "Cannot open file.\n";
	}
}