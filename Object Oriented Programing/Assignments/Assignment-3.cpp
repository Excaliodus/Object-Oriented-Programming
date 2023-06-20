#include <iostream>
#include <fstream>
using namespace std;
class Helper
{
public:
	static int StringLength(char*);
	static char* GetStringFromBuffer(char*);
	static char* CopyString(char*);
	static bool isEqualStr(char* Str1, char* Str2)
	{
		int len1 = StringLength(Str1);
		int len2 = StringLength(Str2);

		if (len1 != len2)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < len1; i++)
			{
				if (Str1[i] != Str2[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};
//Finds length of a string
int Helper::StringLength(char* str)
{
	int count = 0;
	while (str[count] != '\0')       //count++ untill it reaches at the end of of array
		count++;

	return count;
}
//Makes a deep copy of a string and return it
char* Helper::CopyString(char* buffer)
{
	int len = StringLength(buffer);

	char* str = new char[len + 1];

	for (int i = 0; i < len; i++)
		str[i] = buffer[i];

	str[len] = '\0';
	return str;
}
//Gets a string from file and returns the string with minimum space needed
char* Helper::GetStringFromBuffer(char* buffer)
{
	int Len = StringLength(buffer);

	char* str = 0;
	str = new char[Len + 1];

	str = CopyString(buffer);
	return str;
}



class Facebook
{
private:
	User** Users;
	Page** Pages;

public:
	Facebook();
	ifstream usersin;
	static int totalusers;
	static int total_likedpages;
	static int totalpages;
	ifstream pagesin;
	User ReadDatafromFile(ifstream&);
	void loadUsers(ifstream&);
	void ViewFriendList(char[])
	{

	}
	//fixed
	User* searchUserById(User** user_now, char* id) {
		for (int i = 0; i < totalusers; i++) {
			if (Helper::isEqualStr(id, user_now[i]->Getid())) {
				return user_now[i];
			}
		}
		return NULL;
	}

	Page* SearchPagebyid(Page* Pgarr, char* pageid) {

		for (int i = 0; i < Facebook::totalpages; i++) {
			if (Helper::isEqualStr(pageid, Pgarr(i)->Getid())) {
				return Pages[i];
			}
		}
		return NULL;
	}

	void LoadPages(ifstream& fin)
	{
		fin >> totalpages;
		Pages = new Page * [totalpages];
		char buffer[50];
		for (int i = 0; i < totalpages; i++)
		{
			fin >> buffer;
			char* id = Helper::GetStringFromBuffer(buffer);
			fin >> buffer;
			char* title = Helper::GetStringFromBuffer(buffer);
			GetLikedPages(i) = new Page(id, title);  // write constructor
		}
	}

	void showfriendlist(char* ID)
	{
		User* USER_NOW = searchUserById(ID);
		USER_NOW->ViewFriendList();
	}

	void ShowLikedPages(char* ID)
	{
		User* USER_NOW = searchUserById(ID);
		USER_NOW->ViewlikedPages();  // has to be written yet
	}
};

void Facebook::loadUsers(ifstream& userFile)
{
	int totalUsers = 0;
	char*** tempFriendList = NULL;
	userFile >> totalUsers;
	User::totalUsers = totalUsers;
	Users = new User * [totalUsers];
	tempFriendList = new char** [totalUsers];

	for (int i = 0; i < totalUsers; i++)
	{
		Users[i] = new User;
		Users[i]->readData(userFile);

		char* buffer = new char[80];

		tempFriendList[i] = new char* [10];

		for (int j = 0; j < 10; j++)
		{
			tempFriendList[i][j] = new char;
			tempFriendList[i][j] = 0;
		}

		userFile >> buffer;

		for (int j = 0; buffer[0] != '-'; j++)
		{
			tempFriendList[i][j] = Helper::GetStringFromBuffer(buffer);
			userFile >> buffer;
		}

		userFile >> buffer;

		while (buffer[0] != '-')
		{
			char* pageID = Helper::GetStringFromBuffer(buffer);
			Page* p = Facebook::SearchPagebyid(Pages, pageID);
			Users[i]->likePage(p);
			userFile >> buffer;
		}
	}

	for (int i = 0; i < totalUsers; i++)
	{
		int noOfFriends = Helper::numberOfFriends(tempFriendList[i]);
		for (int j = 0; j < noOfFriends; j++)
		{
			User* friendID = Facebook::searchUserById(Users, tempFriendList[i][j]);
			Users[i]->addFriend(friendID);
		}
	}

	for (int i = 0; i < totalUsers; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			delete[] tempFriendList[i][j];
			tempFriendList[i][j] = NULL;
		}
		delete[] tempFriendList[i];
		tempFriendList[i] = NULL;
	}
	delete[] tempFriendList;
	tempFriendList = NULL;

}
Facebook::Facebook()
{
	usersin.open("Users.txt");
	pagesin.open("Pages.txt");
	usersin >> Facebook::totalusers;
	Users = new Facebook * [Facebook::totalusers];

	for (int i = 0; i < Facebook::totalusers; i++)
	{
		Users[i] = NULL;
	}

	pagesin >> Facebook::totalpages;
	Pages = new Facebook * [Facebook::totalpages];

	for (int i = 0; i < Facebook::totalpages; i++)
	{
		Pages[i] = NULL;
	}
}
class Page
{
private:
	static int totalpages;
	char* pageid;
	char* pagename;
public:
	Page ReadDataFromPages(ifstream&);
	void Getid();
};
Page Page::ReadDataFromPages(ifstream& fin)
{
	Page page;
	char buffer[50];
	fin >> buffer;
	page.pageid = Helper::GetStringFromBuffer(buffer);
	fin.ignore();
	fin.getline(buffer, 50);
	page.pagename = Helper::GetStringFromBuffer(buffer);
	return page;
}


//-------------------------------------------------------------
Page** User::addPageLike(Page** liked_pg) {
	if (total_likedpages > 1) {
		Page** newliked_pg = new Page * [total_likedpages + 1];

		for (int i = 0; i < total_likedpages; i++) {
			newliked_pg[i] = liked_pg[i];
		}
		return newliked_pg;
	}
	else {
		return NULL;
	}
}
class User
{
private:
	User** friendlist;
	char* id;
	char* firstname;
	char* lastname;
	Page** LikedPages;
	int total_friends;
	int total_likedpages;
public:
	void ViewFriendList();
	void ViewlikedPages();
	Page** addPageLike(Page**);
	static Page* GetLikedPages(int i)
	{
		return LikedPages[i];
	}
	void Setid(char* ID)
	{
		id = ID;
	}
	void printName()
	{
		cout << firstname << " " << lastname;
	}

	char* Getid()
	{
		return id;
	}
	void Likedpgs(Page* pg)
	{
		Page** newarr = new Page * [total_likedpages + 1];
		for (int i = 0; i < total_likedpages; i++)
		{
			newarr[i] = LikedPages[i];
		}
		newarr[total_likedpages] = pg;
		if (LikedPages != NULL)
		{
			delete[] LikedPages;
		}
		LikedPages = newarr;
		total_likedpages++;
	}
	void friendslist(User* frnd)
	{
		User** newarr = new User * [total_friends + 1];
		for (int i = 0; i < total_friends; i++)
		{
			newarr[i] = friendlist[i];
		}
		if (friendslist != NULL)
		{
			delete[] friendlist;
		}
		friendlist = newarr;
		total_friends++;
	}
	User ReadDatafromFile(ifstream&);
	User();
	void printListview()
	{
		cout << Getid();
		printName();
	}
};
User User::ReadDatafromFile(ifstream& filein)
{
	User user_ith;
	filein >> this->id;
	char* buffer;
	this->firstname = Helper::GetStringFromBuffer(buffer);
	filein >> buffer;
	this->lastname = Helper::GetStringFromBuffer(buffer);
	filein >> buffer;
	return user_ith;
}
User::User()
{

	firstname = 0;
	total_friends = 0;
	lastname = 0;
	friendlist = new User * [10];
	LikedPages = new Page * [10];
	for (int i = 0; i < 10; i++)
	{
		friendlist[i] = 0;
	}
	for (int i = 0; i < 10; i++)
	{
		LikedPages[i] = 0;
	}
}
void User::ViewFriendList()
{
	cout << "------------------------------------------------------------\n";
	printName();
	cout << "--Friend List\n\n";
	for (int i = 0; i < total_friends; i++)
	{
		if (friendlist[i])
		{
			cout << friendlist[i]->Getid() << " - ";
			friendlist[i]->printName();
			cout << endl;
		}
	}
	cout << endl;
}
int main()
{
	ifstream use("Users.txt");
	if (!use)
	{
		cout << "Error: Users";
		return 0;
	}
	ifstream pg("Pages.txt");
	if (!pg)
	{
		cout << "Error: Users";
		return 0;
	}
	if (!pg)
	{
		cout << "Error: Pages";
		return 0;
	}
	Facebook FB;
	FB.LoadPages(pg);
	FB.loadUsers(use);
	char User[] = "u7";
	FB.ViewFriendList(User);
	FB.ShowLikedPages(User);
}