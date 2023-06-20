#include<iostream>
using namespace std;

class MyString
{
	//You can add your code here
private:
	char* str;
	int length;
	
	static int StringLength(char* str)
	{
		// This function should return lenght of str
		int length = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			length++;
		}
		return length;

	}
	static char* GetStringFromBuffer(char* str)
	{
		//This function should allocate required memory on heap,
		//copy string in this memory and return newly created cstring.
		int length = StringLength(str) + 1;
		char* newstr = new char[length];
		for (int i = 0; i < length; i++)
		{
			newstr[i] = str[i];
		}
		return newstr;
	}
	static char* StringConcatenate(char* str1, char* str2)
	{
		int strlen2 = StringLength(str2);
		int strlen1 = StringLength(str1);
		char* constr = new char[strlen1 + strlen2 + 1];
		int k = 0;
		for (int i = 0; i < (strlen1 + strlen2); i++)
		{
			if (i < strlen1)
			{
				constr[i] = str1[i];
			}
			else
			{
				constr[i] = str2[i - strlen1];
			}
			k = i;
		}
		constr[k + 1] = NULL;
		return constr;
	}
	static bool CompareString(char* str1, char* str2)
	{
		int ascii_total1 = 0;
		int ascii_total2 = 0;
		for (int i = 0; str1[i] != '\0'; i++)
		{
			ascii_total1 = ascii_total1 + str1[i];
		}
		for (int i = 0; str2[i] != '\0'; i++)
		{
			ascii_total2 = ascii_total2 + str2[i];
		}
		if (ascii_total1 < ascii_total2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:

	MyString operator+(const MyString);
	MyString& operator=(const MyString&);
	bool operator<(MyString);
	char& operator[](int);
	char* operator()(int, int);
	bool operator!();
	friend istream& operator>>(istream&, MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
	MyString()
	{
		str = nullptr;
		length = NULL;
	}
	//~MyString()
	//{
	//	if (str != nullptr)
	//	{
	//		delete[] str;
	//	}
	//}
};
MyString& MyString::operator=(const MyString& var)
{
	//if (str != nullptr)
	//{
	//	delete[] str;
	//}
	str = GetStringFromBuffer(var.str);
	length = var.length;
	return *this;
}
MyString MyString:: operator+(const MyString obj)
{
	MyString sum;
	sum.length = length + obj.length;
	sum.str = StringConcatenate(str, obj.str);
	return sum;
}
bool MyString :: operator!()
{
	if (length == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
char& MyString :: operator[](int i)
{
	if (i < length)
	{
		return *(str + i);
	}
}
char* MyString:: operator()(int i, int j)
{
	if (i < length)
	{
		char* substring = new char[j];
		int k = 0;
		for (int x = i; (str[x] != NULL) && (x < j + i); x++)
		{
			substring[k] = str[x];
			k++;
		}
		substring[k] = NULL;
		return substring;
	}
	else
	{
		return nullptr;
	}
}
bool MyString::operator<(MyString var)
{
	if (CompareString(str, var.str) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
ostream& operator<<(ostream& out, const MyString& var)
{
	for (int i = 0; i < var.length; i++)
	{
		out << var.str[i];
	}

	return out;

}
istream& operator>>(istream& in, MyString& var)
{
	char* newstr = new char[500];
	in >> newstr;
	var.str = MyString::GetStringFromBuffer(newstr);
	int size = 0;
	for (char* temp = newstr; *temp != '\0'; temp++)
	{
		size++;
	}
	var.length = size;
	var.str[size + 1] = '\0';
	return in;
}
//--------------------------Add your code here----------------------

//-------------DO_NOT_CHANGE REGION starts below---------------------
void main()
{
	MyString str1, str2, str3, str4;	//Default constructor will make a string of lenght 0 but having null character (only) i.e. empty string

	if (!str1)
	{
		cout << "String 1 is Empty.\n";
		cout << "Str 1 = " << str1 << endl << endl << endl;
	}

	cout << "Enter String 1:\t";
	cin >> str1;


	cout << "Enter String 2:\t";
	cin >> str2;


	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl << endl << endl;

	//What is following code testing?
	cout << "Before str1 = str1; str1 = " << str1 << endl;
	str1 = str1;
	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;


	cout << "Before str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	str4 = str3 = str1 + str2;


	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	cout << "\n\n\nEnter String 3:\t";
	cin >> str3;

	cout << "\n\n\nEnter String 4:\t";
	cin >> str4;


	cout << "\n\n\nstr3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	if (str3 < str4)
		cout << "String 3 is Less than String 4.\n";
	else
		cout << "String 3 is NOT Less than String 4.\n";

	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7).
	str5[7] = '$';

	cout << "\n\nStr5:\t" << str5 << endl;

	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 starting from index 5 . Function Call str5.operator()(5,10) Let the returned MyString or char* leak
	_CrtDumpMemoryLeaks();
}
//-------------End of DO_NOT_CHANGE REGION---------------------