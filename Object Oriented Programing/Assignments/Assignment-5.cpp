//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//class Helper
//{
//public:
//	static int StringLenght(char* str)
//	{
//		// This function should return lenght of str
//		int lenght = 0;
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			lenght++;
//		}
//		return lenght;
//
//	}
//	static char* GetStringFromBuffer(char* str)
//	{
//		//This function should allocate required memory on heap,
//		//copy string in this memory and return newly created cstring.
//		int lenght = StringLenght(str) + 1;
//		char* newstr = new char[lenght];
//		for (int i = 0; i < lenght; i++) 
//		{
//			newstr[i] = str[i];
//		}
//		return newstr;
//	}
//};
//class Flex
//{
//	friend Flex* ReadDataFromFile(const char* filename);
//private:
//	static int total_no_std;
//	static int no_of_quiz;
//	static int no_of_assign;
//	static int* quiz_total;
//	static int* assign_total;
//	static int total_marks;
//	char* RollNo;
//	char* firstname;
//	char* lastname;
//	int* quiz_mark;
//	int* assign_mark;
//	int total_obtain;
//
//public:
//	Flex()
//	{
//		firstname = lastname = RollNo = nullptr;
//		quiz_mark = new int[no_of_quiz];
//		assign_mark = new int[no_of_assign];
//		total_obtain = 0;
//	}
//
//	Flex(const Flex& rhs)
//	{
//		RollNo = Helper::GetStringFromBuffer(rhs.RollNo);
//		firstname = Helper::GetStringFromBuffer(rhs.firstname);
//		lastname = Helper::GetStringFromBuffer(rhs.lastname);
//		quiz_mark = rhs.quiz_mark;
//		assign_mark = rhs.assign_mark;
//		total_obtain = rhs.total_obtain;
//	}
//	
//	Flex operator = (const Flex& rhs)
//	{
//		RollNo = Helper::GetStringFromBuffer(rhs.RollNo);
//		firstname = Helper::GetStringFromBuffer(rhs.firstname);
//		lastname = Helper::GetStringFromBuffer(rhs.lastname);
//		quiz_mark = rhs.quiz_mark;
//		assign_mark = rhs.assign_mark;
//		total_obtain = rhs.total_obtain;
//		return  *this;
//	}
//
//	static void SearchingRollNo(Flex*& stdlist, char compRollNo[])
//	{
//		int k = 0;
//		int j = 0;
//		bool flag = false;
//		for (; j < total_no_std; j++)
//		{
//			k = 0;
//			for (int i = 0; i < 8; i++)
//			{
//				if (compRollNo[i] == stdlist[j].RollNo[i])
//				{
//					k++;
//					if (i == 7 && k == 8)
//					{
//						flag = true;
//						break;
//					}
//				}
//			}
//			if (flag)
//			{
//				break;
//			}
//		}
//		if (!flag)
//		{
//			cout << "Student not found" << endl;
//		}
//		if (flag)
//		{
//			cout << "Student Information:" << endl;
//			cout << "Roll No:\t";
//			for (int i = 0; i < 9; i++)
//			{
//				cout << stdlist[j].RollNo[i];
//			}
//			cout << endl;
//			cout << "Name:\t\t" << stdlist[j].firstname << " " << stdlist[j].lastname << endl;
//			cout << "Quizzes Marks:" << endl;
//			for (int i = 0; i < 4; i++)
//			{
//				cout << "\t\tQ" << i + 1 << ":" << stdlist[j].quiz_mark[i] << " / " << quiz_total[i] << endl;
//			}
//			cout << "Assignment Marks:";
//			cout << endl;
//			for (int i = 0; i < 4; i++)
//			{
//				cout << "\t\tA" << i + 1 << ":" << stdlist[j].assign_mark[i] << " / " << assign_total[i] << endl;
//			}
//			cout << endl;
//			cout << "Total:\t\t" << stdlist[k].total_obtain << "/" << total_marks << endl;
//		}
//	}
//
//	void statistics(Flex*& list)
//	{
//		int* min = new int[8];
//		int* max = new int[8];
//		int* average = new int[8];
//		int* total = new int[8];
//		for (int k = 0; k < 8; k++)
//		{
//			total[k] = 0;
//			if (k < 4)
//			{
//				min[k] = list[0].quiz_mark[k];
//				max[k] = list[0].quiz_mark[k];
//				for (int i = 0; i < total_no_std; i++)
//				{
//					total[k] = total[k] + list[i].quiz_mark[k];
//					if (min[k] > list[i].quiz_mark[k])
//					{
//						min[k] = list[i].quiz_mark[k];
//					}
//					if (max[k] < list[i].quiz_mark[k])
//					{
//						max[k] = list[i].quiz_mark[k];
//					}
//				}
//			}
//			else
//			{
//				min[k] = list[0].assign_mark[k - 4];
//				max[k] = list[0].assign_mark[k - 4];
//				for (int i = 0; i < total_no_std; i++)
//				{
//					total[k] = total[k] + list[i].assign_mark[k-4];
//					if (min[k] > list[i].assign_mark[k - 4])
//					{
//						min[k] = list[i].assign_mark[k - 4];
//					}
//					if (max[k] < list[i].assign_mark[k - 4])
//					{
//						max[k] = list[i].assign_mark[k - 4];
//					}
//				}
//			}
//		}
//		for (int k = 0; k < 8; k++)
//		{
//			average[k] = total[k] / total_no_std;
//		}
//		cout << "\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4" << endl;
//		cout << "Total" << "\t" << "\t";
//		for (int i = 0; i < no_of_quiz; i++)
//		{
//			cout << quiz_total[i] << "\t";
//		}
//		for (int i = 0; i < no_of_assign; i++)
//		{
//			cout << assign_total[i] << "\t";
//		}
//		cout << endl;
//		cout << "Maximum" << "\t" << "\t";
//		for (int i = 0; i < 8; i++)
//		{
//			cout << max[i] << "\t";
//		}
//		cout << endl;
//		cout << "Minimum" << "\t" << "\t";
//		for (int i = 0; i < 8; i++)
//		{
//			cout << min[i] << "\t";
//		}
//		cout << endl;
//		cout << "Average" << "\t" << "\t";
//		for (int i = 0; i < 8; i++)
//		{
//			cout << average[i] << "\t";
//		}
//	}
//
//	void BubbleSortList(Flex*& stdlist)
//	{
//		int i, j;
//		for (i = 0; i < total_no_std - 1; i++)
//		{
//			for (j = 0; j < total_no_std - i - 1; j++)
//			{
//				if (stdlist[j].total_obtain > stdlist[j + 1].total_obtain)
//				{
//					//Flex temp = stdlist[j];
//					//stdlist[j] = stdlist[j+1];
//					//stdlist[j+1] = temp;
//
//					Flex temp;
//					temp = stdlist[j];
//					stdlist[j] = stdlist[j + 1];
//					stdlist[j + 1] = temp;
//				}
//			}
//		}
//	}
//
//	void SetValues(char _RollNo[], char* _firstname, char* _lastname, int* _quiz_mark, int* _assign_mark, int _total_obtain)
//	{
//		RollNo = Helper::GetStringFromBuffer(_RollNo);
//		firstname = Helper::GetStringFromBuffer(_firstname);
//		lastname = Helper::GetStringFromBuffer(_lastname);
//		for(int i=0; i<no_of_quiz; i++)
//		{
//			quiz_mark[i] = _quiz_mark[i];
//		}
//		for (int i = 0; i < no_of_assign; i++)
//		{
//			assign_mark[i] = _assign_mark[i];
//		}
//		total_obtain = _total_obtain;
//	}
//
//	void Output(Flex*& stdlist)
//	{
//		cout << "RollNo\t\tName\t\t\tQ1\tQ2\tQ3\tQ4\tA1\tA2\tA3\tA4\tTotal\n" << endl;
//		for (int i = 0; i < total_no_std; i++)
//		{
//			cout << stdlist[i].RollNo << "\t" << stdlist[i].firstname << " " << stdlist[i].lastname << "\t\t";
//			for (int j = 0; j < stdlist[i].no_of_quiz; j++)
//			{
//				cout << stdlist[i].quiz_mark[j] << "\t";
//			}
//			for (int j = 0; j < stdlist[i].no_of_assign; j++)
//			{
//				cout << stdlist[i].assign_mark[j] << "\t";
//			}
//			cout << stdlist[i].total_obtain;
//			cout << endl;
//		}
//		cout << endl << endl << endl;
//	}
//
//	/*~Flex()
//	{
//		cout << "Destructor called" << endl;
//		delete[] firstname;
//		delete[] lastname;
//		delete[] quiz_mark;
//		delete[] assign_mark;
//	}*/
//
//};
//int Flex::total_no_std = 0;
//int Flex::no_of_quiz = 0;
//int Flex::no_of_assign = 0;
//int Flex::total_marks = 0;
//int* Flex::quiz_total = 0;
//int* Flex::assign_total = 0;
//Flex* ReadDataFromFile(const char* filename)
//{
//	int total_obtain = 0;
//	char RollNo[9];
//	char firstname[10];
//	char lastname[10];
//
//	ifstream fin("gradesheet.txt");
//	if (fin.is_open())
//	{
//		fin >> Flex::total_no_std;
//		fin >> Flex::no_of_quiz;
//		Flex::quiz_total = new int[Flex::no_of_quiz];
//		int* quiz_mark = new int[Flex::no_of_quiz];
//		fin >> Flex::no_of_assign;
//		Flex::assign_total = new int[Flex::no_of_assign];
//		int* assign_mark = new int[Flex::no_of_assign];
//		for (int i = 0; i < Flex::no_of_quiz; i++)
//		{
//			fin >> Flex::quiz_total[i];
//		}
//		for (int i = 0; i < Flex::no_of_assign; i++)
//		{
//			fin >> Flex::assign_total[i];
//		}
//		Flex* stdlist = new Flex [Flex::total_no_std];
//
//		int j = 0;
//		while (!fin.eof())
//		{
//			total_obtain = 0;
//			Flex::total_marks = 0;
//			fin >> RollNo;
//			fin >> firstname;
//			fin >> lastname;
//			for (int i = 0; i < Flex::no_of_quiz; i++)
//			{
//				fin >> quiz_mark[i];
//			}
//			for (int i = 0; i < Flex::no_of_assign; i++)
//			{
//				fin >> assign_mark[i];
//			}
//			for (int i = 0; i < Flex::no_of_quiz; i++)
//			{
//				total_obtain = total_obtain + quiz_mark[i];
//			}
//			for (int i = 0; i < Flex::no_of_assign; i++)
//			{
//				total_obtain = total_obtain + assign_mark[i];
//			}
//			for (int i = 0; i < Flex::no_of_quiz; i++)
//			{
//				Flex::total_marks = Flex::total_marks + Flex::quiz_total[i];
//			}
//			for (int i = 0; i < Flex::no_of_assign; i++)
//			{
//				Flex::total_marks = Flex::total_marks + Flex::assign_total[i];
//			}
//			stdlist[j].SetValues(RollNo, firstname, lastname, quiz_mark, assign_mark, total_obtain);
//			j++;
//		}
//		return stdlist;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	Flex* stdlist = ReadDataFromFile("gradesheet.txt");
//	int count = 0;
//	if (stdlist != 0)
//	{
//		cout << "------------------------------------------------DATA READ FROM FILE-------------------------------------------------------" << endl << endl;
//		stdlist->Output(stdlist);
//		cout << "--------------------------------------------------SORTED LIST---------------------------------------------------------------------" << endl << endl;
//		stdlist->BubbleSortList(stdlist);
//		stdlist->Output(stdlist);
//		cout << "-----------------------------------------------------STUDENT INFORMATION--------------------------------------------------------------" << endl;
//		char RollNo[] = "15L - 1234";
//		Flex::SearchingRollNo(stdlist, RollNo);
//		cout << "-----------------------------------------------------STUDENT INFORMATION--------------------------------------------------------------" << endl;
//		char RollNo1[] = "15L-4023";
//		Flex::SearchingRollNo(stdlist, RollNo1);
//		cout << "------------------------------------------------------Class Statistics----------------------------------------------------------------" << endl;
//		stdlist->Flex::statistics(stdlist);
//	}
//}