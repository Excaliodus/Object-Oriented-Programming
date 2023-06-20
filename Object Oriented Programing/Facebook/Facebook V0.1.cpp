#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class User;
class Page;
class Post;
class Comments;
class Date;

class Helper
{
public:
	static int StringLength(const char* str)
	{
		int length = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			length++;
		}
		return length;
	}
	static char* GetStringFromBuffer(char* str)
	{
		int length = StringLength(str) + 1;
		char* newstr = new char[length];
		for (int i = 0; i < length; i++)
		{
			newstr[i] = str[i];
		}
		return newstr;
	}
	void StringCopy(char*& cpy, char*& og)
	{
		int length = StringLength(og);
		int i = 0;
		for (; i < length; i++)
		{
			cpy[i] = og[i];
		}
		cpy[i] = '\0';
	}
	static bool CompareString(char* str1,const char* str2)
	{
		int length1 = StringLength(str1);
		int length2 = StringLength(str2);
		if (length1 == length2)
		{
			for (int i = 0; i < length1; i++)
			{
				if (str1[i] != str2[i])
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
		return true;
	}
};

class Object
{
protected:
	char* id = 0;
public:
	virtual char* getId()
	{
		return id;
	}
	virtual void AddPostToTimeline(Post*) = 0;
	virtual char* GetName() = 0;
	virtual void printInfo() = 0;
};

class Date
{
	int day;
	int month;
	int year;
public:
	static Date present;
	Date()
	{
		day = NULL;
		month = NULL;
		year = NULL;
	}
	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	int day_getter()
	{
		return day;
	}
	int month_getter()
	{
		return month;
	}
	int year_getter()
	{
		return year;
	}
	static void Date_Setter(int d, int m, int y)
	{
		present.day = d;
		present.month = m;
		present.year = y;
	}
	void ReadDate(ifstream& din)
	{
		din >> day;
		din >> month;
		din >> year;
	}
	void printdate()
	{
		cout << day << "/" << month << "/" << year;
	}
};

class Comments
{
private:
	char* cmntid;
	char* content;
	User* cmntby;
	Post* onpost;
public:
	static int Tcmnt;
	Comments()
	{
		cmntid = 0;
		content = 0;
		cmntby = nullptr;
		onpost = nullptr;
	}
	void CommentId_setter(char* temp)
	{
		cmntid = Helper::GetStringFromBuffer(temp);
	}
	void Content_setter(char* temp)
	{
		content = Helper::GetStringFromBuffer(temp);
	}
	static void Tcmnt_setter(int i)
	{
		Tcmnt = i;
	}
	void SetCommentBy(User* p1)
	{
		cmntby = p1;
	}
	static int Tcmnt_getter()
	{
		return Tcmnt;
	}
	void ReadCommments(ifstream& coin)
	{
		char temp[80];
		coin >> temp;
		cmntid = Helper::GetStringFromBuffer(temp);
		coin >> temp;
		//onpost = SearchPost(Helper::GetStringFromBuffer(temp));
		//coin >> temp;
		//cmntby = SearchUser(Helper::GetStringFromBuffer(temp));
	}
	void PrintComments()
	{
		cout << "\t\t";
		//cmntby->printuser();
		cout<< " commented: " << content << endl;
	}
};

class Activity
{
	int type;
	char* content;
public:
	Activity()
	{
		type = 0;
		content = nullptr;
	}
	void readData(ifstream& ain)
	{
		ain >> type;
		char temp[50];
		ain.getline(temp, 50);
		content = Helper::GetStringFromBuffer(temp);
	}
	void PrintActivity()
	{
		cout << " is ";
		switch (type)
		{
		case 1:
			cout << "Feeling ";
			break;
		case 2:
			cout << "Thinking about ";
			break;
		case 3:
			cout << "Making ";
			break;
		case 4:
			cout << "Celebrating ";
			break;
		}
		cout << content << '\n';
	}
	~Activity()
	{
		delete content;
		content = NULL;
	}
};

class Pages
{
	char* pageID;
	char* title;
	
public:
	static int totalpages;
	Pages()
	{
		pageID = nullptr;
		title = nullptr;
	}
	char* pageid_getter()
	{
		return pageID;
	}
	void ReadPages(ifstream& pin)
	{
		char temp[80];
		pin >> temp;
		pageID = Helper::GetStringFromBuffer(temp);
		pin.getline(temp, 80);
		title = Helper::GetStringFromBuffer(temp);
	}
	void printpage()
	{
		cout << pageid_getter() << "\t--\t" << title << endl;
	}
	~Pages()
	{
		if (pageID != nullptr && title != nullptr)
		{
			delete[]pageID;
			delete[]title;
		}
	}
};
int Pages::totalpages = 0;

class User
{
	char* userID;
	char* firstname;
	char* lastname;
	User** friends;
	Pages** liked;
	int Tfriend;
	int Tliked;
public:
	static int totalusers;
	User()
	{
		userID = nullptr;
		firstname = nullptr;
		lastname = nullptr;
		liked = nullptr;
		Tfriend = 0;
		Tliked = 0;
		liked = nullptr;
		friends = nullptr;
	}
	void Tfriends_setter(int in)
	{
		Tfriend = in;
	}
	void Tliked_setter(int in)
	{
		Tliked = in;
	}
	char* userid_getter()
	{
		return userID;
	}
	void ReadUser(ifstream& uin)
	{
		char temp[80];
		uin >> temp;
		userID = Helper::GetStringFromBuffer(temp);
		uin >> temp;
		firstname = Helper::GetStringFromBuffer(temp);
		uin >> temp;
		lastname = Helper::GetStringFromBuffer(temp);
	}
	void printuser()
	{
		cout << userid_getter() << "\t---\t" << firstname << " " << lastname;
	}
	void printfriendlist()
	{
		cout << "----------------------------------------------------------------------------------------------------------\n" << firstname << " " << lastname << "\t-- Friend List" << endl << endl;
		for (int i = 0; i < Tfriend; i++)
		{
			if (friends != nullptr)
			{
				friends[i]->printuser();
				cout << endl;
			}
		}
		cout << endl << endl;
	}
	void printpagelist()
	{
		cout << "----------------------------------------------------------------------------------------------------------\n" << firstname << " " << lastname << "\t-- Liked Pages" << endl << endl;
		for (int i = 0; i < Tliked; i++)
		{
			if (liked != nullptr)
			{
				liked[i]->printpage();
			}
		}
		cout << endl << endl;
	}
	void memallocfriends()
	{
		friends = new User * [Tfriend];
		for (int i = 0; i < Tfriend; i++)
		{
			friends[i] = new User;
		}
	}
	void memallocliked()
	{
		liked = new Pages * [Tliked];
		for (int i = 0; i < Tliked; i++)
		{
			liked[i] = new Pages;
		}
	}
	void linkfriend(User*& link, int i)
	{
		friends[i] = link;
	}
	void linkliked(Pages*& link, int i)
	{
		liked[i] = link;
	}
	~User()
	{
		if (userID != nullptr && firstname != nullptr && lastname != nullptr)
		{
			delete[] userID;
			userID = NULL;
			delete[] firstname;
			delete[] lastname;
			firstname = lastname = NULL;
			delete[] liked;
			liked = NULL;
		}
	}
};
int User::totalusers = 0;

class Post
{
	char* postID;
	char* postcontent;
	char* date;
	Date upload;
	Comments** cmntonpost;
	User** likedby;
	User* sharedby;
	int Tlikes;
	int Tcmnts;
public:
	static int TPosts;
	Post()
	{
		postID = nullptr;
		postcontent = nullptr;
		date = nullptr;
		cmntonpost = new Comments * [10];
		likedby = new User * [10];
		sharedby = nullptr;
		Tlikes = 0;
		Tcmnts = 0;
	}
	void sharedby_setter(User* p1)
	{
		sharedby = p1;
	}
};
class Facebook
{
	User** users;
	Pages** pages;
public:
	void LoadData(const char* userfilename, const char* pagefilename)
	{
		LoadPages("Pages.txt");
		LoadUser("Users.txt");
	}
	void LoadPages(const char* userfilename)
	{
		ifstream pin("Pages.txt");
		if (pin.is_open())
		{
			pin >> Pages::totalpages;
			pages = new Pages * [Pages::totalpages];
			for (int i = 0; i < Pages::totalpages; i++)
			{
				pages[i] = new Pages;
				pages[i]->ReadPages(pin);
			}
			pin.close();
		}
		else
		{
			cout << "Pages.txt has not opened" << endl;
		}
	}
	void LoadUser(const char* pagefilename)
	{
		ifstream uin("Users.txt");
		if (uin.is_open())
		{
			uin >> User::totalusers;
			char temp[25];
			users = new User * [User::totalusers];
			char*** tempfrnds = new char** [User::totalusers];
			char*** templiked = new char** [User::totalusers];
			for (int i = 0; i < User::totalusers; i++)
			{
				users[i] = new User;
				users[i]->ReadUser(uin);
				tempfrnds[i] = new char* [10];
				for (int j = 0; j < 10; j++)
				{
					tempfrnds[i][j] = new char;
					tempfrnds[i][j] = NULL;
				}

				int tfrnd = 0;
				int tliked = 0;

				uin >> temp;
				while (temp[0] != '-')
				{
					tempfrnds[i][tfrnd] = Helper::GetStringFromBuffer(temp);
					tfrnd++;
					uin >> temp;
				}
				users[i]->Tfriends_setter(tfrnd);
				users[i]->memallocfriends();

				uin >> temp;

				templiked[i] = new char* [10];
				for (int j = 0; j < 10; j++)
				{
					templiked[i][j] = new char;
					templiked[i][j] = NULL;
				}
				while (temp[0] != '-')
				{
					templiked[i][tliked] = Helper::GetStringFromBuffer(temp);
					tliked++;
					uin >> temp;
				}
				users[i]->Tliked_setter(tliked);
				users[i]->memallocliked();
			}
			uin.close();
			User* frndptr;
			for (int i = 0; i < User::totalusers; i++)
			{
				for (int j = 0; tempfrnds[i][j] != nullptr; j++)
				{
					frndptr = SearchUser(tempfrnds[i][j]);
					users[i]->linkfriend(frndptr, j);
				}
			}
			Pages* pgptr;
			for (int i = 0; i < User::totalusers; i++)
			{
				for (int j = 0; templiked[i][j] != nullptr; j++)
				{
					pgptr = SearchPage(templiked[i][j]);
					users[i]->linkliked(pgptr, j);
				}
			}
			for (int i = 0; i < User::totalusers; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					delete[] tempfrnds[i][j];
				}
			}
		}
		else
		{
			cout << "Users.txt has not opened" << endl;
		}
	}
	User* SearchUser(const char* user_id)
	{
		char* temp1 = new char[20];
		for (int i = 0; i < User::totalusers; i++)
		{
			temp1 = users[i]->userid_getter();
			if (Helper::CompareString(temp1, user_id))
			{
				return users[i];
			}
		}
		return nullptr;
	}
	Pages* SearchPage(const char* page_id)
	{
		for (int i = 0; i < Pages::totalpages; i++)
		{
			if (Helper::CompareString(pages[i]->pageid_getter(), page_id))
			{
				return pages[i];
			}
		}
		return nullptr;
	}
	void Run()
	{
		cout << "----------------------------------------------------------------------------------------------------------\n----------------------------------------------------------------------------------------------------------\n-----------------------------------------------------FACEBOOK---------------------------------------------\n----------------------------------------------------------------------------------------------------------\n----------------------------------------------------------------------------------------------------------\n";
		cout<<"Enter a userid to set person as current user."<<endl;
		User* current = SearchUser("u7");
		if (current != nullptr)
		{
			current->printuser();
			cout << " successfully set as Current User" << endl;
		}
		current->printfriendlist();
		current->printpagelist();
	}
};

void main()
{
	Facebook objFacebook;
	objFacebook.LoadData("Users.txt", "Pages.txt");
	objFacebook.Run();
}