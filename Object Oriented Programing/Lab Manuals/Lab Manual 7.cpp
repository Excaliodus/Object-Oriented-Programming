#include<iostream>
#include<fstream>
using namespace std;

class Helper
{
public:
	static int StringLenght(char* str)
	{
		// This function should return lenght of str

		int lenght = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			lenght++;
		}
		return lenght;

	}
	static char* GetStringFromBuffer(char* str)
	{
		//This function should allocate required memory on heap,
		//copy string in this memory and return newly created cstring.

		int lenght = StringLenght(str) + 1;
		char* newstr = new char[lenght];
		for (int i = 0; i < lenght; i++) {
			newstr[i] = str[i];
		}
		return newstr;
	}
};

class Car
{
private:
	static int totalCars;	// initialize it yourself
	int model = 0;
	char* make;
	char* name;
	char* color;
public:
	Car()
	{
		model = 0;
		color = make = name = 0;
		totalCars++;
	}
	//Write Getter of totalCars yourself

	static int GetTotalCars() {
		return totalCars;
	}

	void SetValues(int _model, char* _make, char* _name, char* _color)
	{
		//This is how we call static functions without object
		make = Helper::GetStringFromBuffer(_make);

		//Set rest of the values yourself.

		model = _model;
		name = Helper::GetStringFromBuffer(_name);
		color = Helper::GetStringFromBuffer(_color);
	}
	void PrintListView()
	{
		cout << model << " " << make << " " << name << " " << color << endl;

	}
	void PrintDetailView()
	{
		cout << "Car Information: " << endl;
		cout << "MODEL: " << model << endl;
		cout << "MAKE: " << make << endl;
		cout << "NAME: " << name << endl;
		cout << "COLOR: " << color << endl;
	}
	~Car()
	{
		cout << "Destroying ";
		totalCars = 0;
		Print();
	}
	void Print() {
		PrintListView();
	}
	void Input()
	{
		//Do not consume one extra byte on heap
		int _model;
		char* _make = new char[20];
		char* _name = new char[20];
		char* _color = new char[20];
		cout << "Enter New Car Information: " << endl;
		cout << "Enter model: ";
		cin >> _model;
		model = _model;
		cout << "Enter make: ";
		cin.ignore();
		cin.get(_make, 20);
		make = _make;
		cout << "Enter name: ";
		cin.ignore();
		cin.get(_name, 20);
		name = _name;
		cout << "Enter color: ";
		cin.ignore();
		cin.get(_color, 20);
		color = _color;
	}

};

Car* ReadDataFromFile()
{
	ifstream fin;
	int totalCars = 0;
	char buffer[80];
	int model;
	char make[20];
	char name[20];
	char color[20];



	fin.open("Data.txt");
	if (fin.is_open())
	{
		fin >> totalCars;
		//cout << totalCars;
		fin.getline(buffer, 80, '\n');	//We are not saving it
		//cout << buffer << endl;

		Car* carsList = new Car[totalCars];
		int i = 0;
		while (!fin.eof())
		{
			fin >> model;
			fin >> make;
			fin >> name;
			fin >> color;
			//Uncomment this line to check what fin has read

			//cout << model << " " << make << " " << name << " " << color << endl;
			carsList[i].SetValues(model, make, name, color);
			i++;
		}
		return carsList;
	}
	else
	{
		return 0;
	}
}
int Car::totalCars = 0;
void main()
{
	Car* carsList = ReadDataFromFile();
	int count = 0;
	if (carsList != 0)
	{

		count = Car::GetTotalCars();	//Calling static function
		cout << "Total Number of Cars in System:\t" << count << endl;
		cout << "\nCars List:\n\n";
		for (int i = 0; i < count; i++)
		{
			carsList[i].PrintListView();
		}
		delete[] carsList;
		carsList = NULL;
	}


	cout << "Total Number of Cars in System:\t" << Car::GetTotalCars() << endl << endl << endl;

	Car testCar;
	testCar.Input(); // Take car data from user
	testCar.PrintDetailView();

	cout << "Total Number of Cars in System:\t" << testCar.GetTotalCars() << endl << endl << endl;

}