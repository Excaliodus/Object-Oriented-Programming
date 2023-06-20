#pragma once
#include <iostream>
using namespace std;


int StringLength(const char* string)
{
	int i = 0;
	for (; string[i] != '\0'; i++)
	{
		i++;
	}
	return i;
}
void StringCopy(char* arr1, char*& arr2, int k)
{
	int i = 0;
	for (; i < k; i++)
	{
		arr1[i] = arr2[i];
	}
	arr1[i + 1] = '\0';
}

class Person
{
private:
	char* first_name;
	char* last_name;
protected:
	int age;
public:
	Person();
	Person(char*, char*, int);
	~Person();
	void Information_print();
	char* first_name_getter()
	{
		return first_name;
	}
	char* last_name_getter()
	{
		return last_name;
	}
};
Person::Person()
{
	first_name = 0;
	last_name = 0;
	age = 0;
	cout << "Person() called" << endl;
}
Person::Person(char* fname, char* lname, int age)
{
	this->age = age;
	first_name = new char[strlen(fname) + 1];
	StringCopy(first_name, fname, StringLength(fname));
	last_name = new char[strlen(lname) + 1];
	StringCopy(last_name, lname, StringLength(lname));
	cout << "Person() called" << endl;
}
Person::~Person()
{
	cout << "~Person() called" << endl;
}
void Person::Information_print()
{
	cout << first_name << " " << last_name << " is " << age << " years old." << endl;
}

class Faculty : public Person
{
private:
	int course_count;
	int ext;
public:
	Faculty();
	Faculty(char*, char*, int, int, int);
	~Faculty();
	void Faculty_print();
};
Faculty::Faculty()
{
	course_count = 0;
	ext = 0;
	cout << "Faculty() called" << endl;
}
Faculty::Faculty(char* fname, char* lname, int age, int coursecount, int extension) : Person(fname, lname, age)
{
	course_count = coursecount;
	ext = extension;
	cout << "Faculty() called" << endl;
}
Faculty::~Faculty()
{
	cout << "~Faculty() called" << endl;
}
void Faculty::Faculty_print()
{
	cout << "Faculty member name: " << Person::first_name_getter() << " " << Person::last_name_getter() << ", " << "Age: " << age << ", Number of courses: " << course_count << ", Ext. " << ext << endl;
}

class Student : public Person
{
private:
	float cgpa;
public:
	Student();
	Student(char*, char*, int, float);
	~Student();
	void Student_print();
	float cgpa_getter()
	{
		return cgpa;
	}
};
Student::Student()
{
	cgpa = 0;
	cout << "Student() called" << endl;
}
Student::Student(char* fname, char* lname, int age, float cgpa) : Person(fname, lname, age)
{
	this->cgpa = cgpa;
	cout << "Student() called" << endl;
}
Student::~Student()
{
	cout << "~Student() called" << endl;
}
void Student::Student_print()
{
	cout << Person::first_name_getter() << " " << Person::last_name_getter() << "is  " << age << " years old, his cgpa is " << cgpa << endl;
}

class Undergraduate : public Student
{
private:
	char* fyp_name;
public:
	Undergraduate();
	Undergraduate(char*, char*, int, float, char*);
	~Undergraduate();
	void Undergraduate_print();
};
Undergraduate::Undergraduate()
{
	fyp_name = 0;
	cout << "Undergraduate() called" << endl;
}
Undergraduate::Undergraduate(char* fname, char* lname, int age, float cgpa, char* fypname) : Student(fname, lname, age, cgpa)
{
	fyp_name = new char[strlen(fypname) + 1];
	StringCopy(fyp_name, fypname, StringLength(fypname));
	cout << "Undergraduate() called" << endl;
}
Undergraduate::~Undergraduate()
{
	cout << "~Undergraduate() called" << endl;
}
void Undergraduate::Undergraduate_print()
{
	cout << Person::first_name_getter() << " " << Person::last_name_getter() << "is an undergraduate student, his cgpa is " << Student::cgpa_getter() << " and his final year project is titled " << fyp_name << endl;
}

class Graduate : public Student
{
private:
	char* thesis_topic;
public:
	Graduate();
	Graduate(char*, char*, int, float, char*);
	~Graduate();
	void Graduate_print();
};
Graduate::Graduate()
{
	thesis_topic = 0;
	cout << "Graduate() called" << endl;
}
Graduate::Graduate(char* fname, char* lname, int age, float cgpa, char* thesisname) : Student(fname, lname, age, cgpa)
{
	thesis_topic = new char[strlen(thesisname) + 1];
	StringCopy(thesis_topic, thesisname, StringLength(thesisname));
	cout << "Graduate() called" << endl;
}
Graduate::~Graduate()
{
	cout << "~Graduate() called" << endl;
}
void Graduate::Graduate_print()
{
	cout << Person::first_name_getter() << " " << Person::last_name_getter() << "is a graduate student, his cgpa is " << Student::cgpa_getter() << " and his thesis topic is " << thesis_topic << endl;
}