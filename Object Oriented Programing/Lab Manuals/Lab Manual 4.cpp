#include <iostream>
#include <fstream>
using namespace std;

int StringLenght(char* str)
{
	int lenght = 0;
	for (int i = 0; str[i] != NULL; i++)
	{
		lenght++;
	}
	return lenght;
}

int GetCharacterCount(char* myString, char ch)
{
	int count = 0;
	for (int i=0; myString[i]!=NULL; i++)
	{
		if (*myString == ch)
		{
			count++;
		}
	}
	return count;
}

char** ReadStudentsListFromFile()
{
	int size;
	ifstream fin("StudentsList.txt");
	fin >> size;

	char** list = new char*[size];
	for (int i = 0; i < size; i++)
	{
		*(list + i) = new char[80];
	}
	for (int i = 0; i < size; i++)
	{
		fin.getline(*(list + i), 80);
	}
	return names;
}

int main()
{
	char charArray[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' };
	cout << charArray << endl;
	//char myStr1[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
	//char myStr1[] = "Hello World";
	char myStr1[20] = "Hello World";
	cout << myStr1 << endl;
	int length;
	char* ptr;
	ptr = myStr1;
	length = StringLenght(ptr);
	cout << "\nThe lenght is : " << length << endl;
	int count;
	char* string = new char[80];
	char ch;
	cout << "Enter a string : ";
	cin >> string;
	cout << "\nEnter a charachter to find the number of times it is used in the given string:\t";
	cin >> ch;
	count = GetCharacterCount(string, ch);
	cout << "Number of uses in string are:\t" << count << endl;
	char** names;
	names = ReadStudentsListFromFile();
	system("pause");
	return 0;
}