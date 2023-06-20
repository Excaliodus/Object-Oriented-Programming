//#include<iostream>
//using namespace std;
//
//class Date
//{
//
//private:
//
//	int Day;
//	int Month;
//	int Year;
//
//public:
//
//	void Print()
//	{
//		cout << Day << "/" << Month << "/" << Year << endl;
//	}
//	void Input()
//	{
//		cout << "Enter the day, month and year." << endl;
//		cin >> Day >> Month >> Year;
//	}
//	Date::Date()
//	{
//		cout << "Default Constructor Called" << endl;
//		Day = 1;
//		Month = 1;
//		Year = 1926;
//	}
//	Date::Date(int d, int m, int y)
//	{
//		cout << endl << "Overloaded Function Called" << endl;
//		Day = d;
//		Month = m;
//		Year = y;
//	}
//	Date::~Date()
//	{
//		cout << "Destructor Called for Date" << endl;
//		Print();
//	}
//};
//
//void main()
//{
//	Date date1;
//	Date independaceDay(14, 8, 2018);
//	date1.Print();
//	independaceDay.Print();
//	date1.Input();
//	date1.Print();
//	system("pause");
//}