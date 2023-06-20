#include <iostream>
using namespace std;

class student
{
private:
	char name[50] = { '\0' };
	char rollNo[8] = { '\0' };
	float cgpa;
public:
	student(const char rollno[], const char Name[], float Cgpa)
	{
		for (int i = 0; i < 8; i++)
		{
			rollNo[i] = rollno[i];
		}
		for (int i = 0; Name[i] != '\0'; i++)
		{
			name[i] = Name[i];
		}
		cgpa = Cgpa;
	}
	void print()
	{
		cout << name << " (" << rollNoGetter() << ")" << endl;
	}
	float cgpaGetter()
	{
		return cgpa;
	}
	char* nameGetter()
	{
		return name;
	}
	char* rollNoGetter()
	{
		return rollNo;
	}
};

class society
{
private:
	char name[50];
	student* president;
	student* members[5];
public:
	society(const char Name[])
	{
		president = nullptr;
		members[4] = '\0';
		for (int i = 0; Name[i] != '\0'; i++)
		{
			name[i] = Name[i];
		}
	}
	void PrintInfo()
	{
		cout << "Society name : " << name << endl;
		cout << "Society President : ";
		if (president)
		{
			president->print();
		}
		else
		{
			cout << "Not available" << endl;
		}
		cout << "Society members : " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Member " << i + 1 << ": ";
			if (members[i])
			{
				members[i]->print();
			}
			else
			{
				cout << "Not Available";
			}
			cout << endl;
		}
		cout << endl;
	}
	void AppointPresident(student& obj) 
	{
		if (!president && obj.cgpaGetter() > 3.00)
		{
			president = &obj;
			cout << obj.nameGetter() << " has been appointed as president of the society." << endl;
		}
		else if (obj.cgpaGetter() < 3.00)
			cout << obj.nameGetter() << "has not met the CGPA criteria" << endl;
		else if (president)
			cout << obj.nameGetter() << " can not be appointed. President position not vacant" << endl;
	}
	void AddMember(student& obj)
	{
		bool flag = false;
		bool done = false;
		if (president == &obj)
		{
			cout << "\n" << obj.nameGetter() << ", the President cannot be added as a member." << endl;
		}
		else
		{
			for (int i = 0; i < 5; i++) 
			{
				if (members[i] == &obj) 
				{
					flag = true;
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (flag == false) 
				{
					if (members[i] == NULL) 
					{
						members[i] = &obj;
						cout <<obj.nameGetter() << " successfully added as a member." << endl;
						done = true;
						break;
					}
				}
			}
			if (done == false)
			{
				cout << obj.nameGetter() << " cannot be added as there are no vacant spots." << endl;
			}
		}
	}
	void suspend_member(const char* membername) 
	{
		for (int i = 0; i < 4; i++)
		{
			if (strcmp(membername, members[i]->nameGetter()) == 0)
			{
				cout << members[i]->nameGetter() << " has been suspended from " << name << " society." << endl;
				members[i] = NULL;
			}
		}
	}
};

int main()
{
	student s1("12L1111", "Hashim Amla", 3.99);
	student s2("13L1121", "Virat Kohli", 3.45);
	student s3("13L1126", "Quinton de Kock", 2.98);
	student s4("14L1361", "Joe Root", 2.99);
	student s5("14L1124", "Martin Guptil", 3.09);
	student s6("15L1314", "Rohit Sharma", 3.19);

	society sports("Sports");
	sports.PrintInfo();

	sports.AppointPresident(s3);
	sports.AppointPresident(s1);
	sports.AppointPresident(s2);


	cout << endl << endl << endl;
	student s7("15L1334", "Robert Elen", 2.19);
	sports.AddMember(s3);
	sports.AddMember(s2);
	sports.AddMember(s3);
	sports.AddMember(s1);
	sports.AddMember(s4);
	sports.AddMember(s5);
	sports.AddMember(s6);
	sports.AddMember(s7);
	cout << endl << endl;
	sports.PrintInfo();

	cout << endl << endl;
	sports.suspend_member("abc");
	sports.suspend_member("Martin Guptil");

	cout << endl << endl << endl;
	society ieee("IEEE");
	ieee.AppointPresident(s5);
	ieee.PrintInfo();
}