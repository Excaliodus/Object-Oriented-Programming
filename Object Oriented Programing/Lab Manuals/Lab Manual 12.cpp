#include <iostream>
#include<fstream>
#include<conio.h>
using namespace std;


class Animal
{
public:
	Animal()
	{}
	virtual const char* speak()
	{
		return "Speak() called.";
	}
	virtual ~Animal()
	{
		cout << "~Animal() called" << endl;
	}
};
class Dog :public Animal
{
public:
	Dog()
	{
	}
	~Dog()
	{
		cout << "~Dog() called" << endl;
	}
	const char* speak()
	{
		return "woof!";
	}
};
class Cat :public Animal
{
public:
	Cat()
	{
	}
	~Cat()
	{
		cout << "~Cat() called" << endl;
	}
	const char* speak()
	{
		return "meow!";
	}
};

void main()
{
	const int size = 5;
	Animal* myPets[size];
	int i = 0;
	while (i < size) {
		cout << "Press 1 for Dog and 2 for Cat." << endl;
		switch (_getch()) {
		case '1':
			myPets[i] = new Dog;
			cout << "Dog added at position " << i << endl << endl;
			i++;
			break;
		case'2':
			myPets[i] = new Cat;
			cout << "Cat added at position " << i << endl << endl;
			i++;
			break;
		default:
			cout << "Invalid Input.Enter Again" << endl << endl;
			break;
		}
	}
	for (int i = 0; i < size; i++) {
		cout << myPets[i]->speak() << endl;
	}
	for (int i = 0; i < size; i++) {
		delete myPets[i];
	}

}