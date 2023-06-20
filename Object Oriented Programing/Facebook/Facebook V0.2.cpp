#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class User;
class Page;
class Post;
class Comments;
class Date;
class Activity;

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
	virtual void PrintName() = 0;
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
	static void Present_Setter(int d, int m, int y)
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
	bool isPresent()
	{
		if ((present.day - day == 0 || present.day - day == 1) && present.month - month == 0 && present.year - year == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void printdate()
	{
		cout << day << "/" << month << "/" << year;
	}
};
Date Date::present;

class Comments
{
private:
	char* cmntid;
	char* content;
	Object* cmntby;
public:
	static int Tcmnt;
	Comments()
	{
		cmntid = nullptr;
		content = nullptr;
		cmntby = nullptr;
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
	void SetCommentBy(Object* p1)
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
	}
	void PrintComments()
	{
		cmntby->PrintName();
		cout<< " commented:\t" << content << endl;
	}
	~Comments()
	{
		if (cmntid != nullptr)
		{
			delete[] cmntid;
			delete[] content;
			delete[] cmntby;
			cmntid = content = NULL;
			cmntby = NULL;
		}
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
	void readActivity(ifstream& ain)
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

class Pages : public Object
{
private:
	char* pageID;
	char* title;
	int Tposts;
	Post** Timeline;
	
public:
	static int totalpages;
	Pages()
	{
		pageID = nullptr;
		title = nullptr;
		Timeline = new Post * [10];
	}
	char* pageid_getter()
	{
		return pageID;
	}
	char* title_getter()
	{
		return title;
	}
	static int totalpages_getter()
	{
		return totalpages;
	}
	static void totalpages_setter(int total)
	{
		totalpages = total;
	}
	void ReadPages(ifstream& pin)
	{
		char temp[80];
		pin >> temp;
		pageID = Helper::GetStringFromBuffer(temp);
		pin.getline(temp, 80);
		title = Helper::GetStringFromBuffer(temp);
	}
	void PrintName()
	{
		cout << pageid_getter() << "\t--\t" << title << endl;
	}
	void PrintPagewithPosts()
	{
		PrintName();
		viewPosts();
	}
	void viewPosts()
	{
		for (int i = 0; i < Tposts; i++)
		{
			Timeline[i]->printlast24hrs();
		}
	}
	void AddPostToTimeline(Post* post)
	{
		Timeline[Tposts] = post;
		Tposts++;
	}
	~Pages()
	{
		if (pageID != nullptr && title != nullptr)
		{
			delete[]pageID;
			delete[]title;
			pageID = nullptr;
			title = nullptr;
		}
	}
};
int Pages::totalpages = 0;

class User : public Object
{
	char* userID;
	char* firstname;
	char* lastname;
	User** friends;
	Pages** liked;
	int Tfriend;
	int Tliked;
	Post** Timeline;
	int Tposts;
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
		Tposts = 0;
		liked = nullptr;
		friends = nullptr;
		Timeline = new Post * [10];
		for (int i = 0; i < 10; i++)
		{
			Timeline[i] = nullptr;
		}
	}
	void Tfriends_setter(int in)
	{
		Tfriend = in;
	}
	void Tliked_setter(int in)
	{
		Tliked = in;
	}
	void viewHome()
	{
		for (int i = 0; i < Tfriend; i++)
		{
			friends[i]->viewPosts();
		}
		for (int i = 0; i < Tliked; i++)
		{
			liked[i]->viewPosts();
		}
	}
	void viewPosts()
	{
		for (int i = 0; i < Tposts - 1; i++)
		{
			Timeline[i]->printlast24hrs();
		}
	}
	static void totaluser_setter(int total)
	{
		totalusers = total;
	}
	char* userid_getter()
	{
		return userID;
	}
	static int totaluser_getter()
	{
		return totalusers;
	}
	int Tfriends_getter()
	{
		return Tfriend;
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
	void PrintName()
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
				friends[i]->PrintName();
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
				liked[i]->PrintName();
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
	void ViewMemories()
	{
		cout << "Memories:\nOn This Day";

		for (int i = 0; i < Tposts; i++)
		{
			if (Timeline[i]->MemCheck())
			{
				Timeline[i]->printpost();
			}
		}
	}
	void postComment(Post* ptr, char* comm)
	{
		Comments* Cptr = new Comments;
		Cptr->Content_setter(comm);
		int total = Comments::Tcmnt + 1;
		char idptr[] = "c14";
		char* ID = idptr;
		Cptr->CommentId_setter(ID);
		Cptr->SetCommentBy(this);
		Comments::Tcmnt_setter(total);
		ptr->AddCommment(Cptr);
	}
	void shareMemory(Post* ptr, char* str)
	{
		Memory* mptr = new Memory(ptr, str, this);
		AddPostToTimeline(mptr);
	}
	void likePost(Post* ptr)
	{
		ptr->Addlikedby(this);
	}
	void AddPostToTimeline(Post* post)
	{
		Timeline[Tposts] = post;
		Tposts++;
	}

	void linkfriend(User*& link, int i)
	{
		friends[i] = link;
	}
	void linkliked(Pages*& link)
	{
		liked[Tliked] = new Pages;
		liked[Tliked] = link;
		Tliked++;
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
			delete[] friends;
		}
	}
};
int User::totalusers = 0;

class Post
{
	char* postID;
	char* postcontent;
	char* date;
	Date uploaded;
	Comments** cmntonpost;
	Object** likedby;
	Object* sharedby;
	Activity* activity;
	int Tlikes;
	int Tcmnts;
	int posttype;
public:
	static int TPosts;
	Post()
	{
		postID = nullptr;
		posttype = 0;
		postcontent = nullptr;
		date = nullptr;
		cmntonpost = new Comments * [10];
		likedby = new Object * [10];
		for (int i = 0; i < 10; i++)
		{
			cmntonpost[i] = nullptr;
		}
		for (int i = 0; i < 10; i++)
		{
			likedby[i] = nullptr;
		}
		for (int i = 0; i < 10; i++)
		{
			cmntonpost[i] = nullptr;
		}
		sharedby = nullptr;
		Tlikes = 0;
		Tcmnts = 0;
	}
	void sharedby_setter(Object* p1)
	{
		sharedby = p1;
	}
	void uploaded_setter(Date p1)
	{
		uploaded = p1;
	}
	char* PostContent_getter()
	{
		return postcontent;
	}
	char* PostID_getter()
	{
		return postID;
	}
	Date uploaded_getter()
	{
		return uploaded;
	}
	Object* sharedby_getter()
	{
		return sharedby;
	}
	void Addlikedby(Object* ptr)
	{
		if (Tlikes <= 10)
		{
			likedby[Tlikes] = ptr;
			Tlikes++;
		}
		else
		{
			cout << "Total number of likes on post has been reached.\nNo more likes can be added." << endl;
		}
	}
	void AddCommment(Comments* ptr)
	{
		if (Tcmnts <= 10)
		{
			cmntonpost[Tcmnts] = ptr;
			Tcmnts++;
		}
		else
		{
			cout << "Total number of comments on post has been reached.\nNo more comments can be added." << endl;
		}
	};
	void printlast24hrs()
	{
		if (uploaded.isPresent())
		{
			printpost();
		}
	}
	void printlikedby()
	{
		cout << "Post liked by:" << endl;
		for (int i = 0; i < Tlikes; i++)
		{
			likedby[i]->PrintName();
		}
	}
	void printpost()
	{
		sharedby->PrintName();
		if (posttype == 1)
		{
			cout << " shared:\t" << postcontent << endl;
			for (int i = 0; i < Tcmnts; i++)
			{
				cmntonpost[i]->PrintComments();
			}
			cout << "Total likes: " << Tlikes << endl << endl << endl;
		}
		else
		{
			cout << " is ";
			activity->PrintActivity();
			cout << postcontent << endl;
			for (int i = 0; i < Tcmnts; i++)
			{
				cmntonpost[i]->PrintComments();
			}
			cout << "Total likes: " << Tlikes << endl << endl << endl;
		}
	}
	virtual void printpostmem()
	{
		sharedby->PrintName();
		if (posttype == 2)
		{
			activity->PrintActivity();
		}
		else 
		{
			cout << " shared ";
		}
		cout << "\"" << postcontent << "\" ...(";
		uploaded.printdate();
		cout << ")\n";
		for (int i = 0; i <Tcmnts; i++)
		{
			cmntonpost[i]->PrintComments();
		}
		cout << '\n';
	}
	int counter = 0;
	void ReadPosts(ifstream& poin)
	{
		char temp[80];
		if (counter == 0)
		{
			poin.ignore();
		}
		poin >> posttype;
		if (posttype == 1)
		{
			poin >> temp;
			postID = Helper::GetStringFromBuffer(temp);
			uploaded.ReadDate(poin);
			if (counter == 0)
			{
				poin.ignore();
			}
			poin.getline(temp, 80);
			postcontent = Helper::GetStringFromBuffer(temp);
		}
		else if (posttype == 2)
		{
			activity = new Activity;
			poin >> temp;
			postID = Helper::GetStringFromBuffer(temp);
			uploaded.ReadDate(poin);
			if (counter == 0)
			{
				poin.ignore();
			}
			poin.getline(temp, 80);
			postcontent = Helper::GetStringFromBuffer(temp);
			activity->readActivity(poin);
		}
		counter++;
	}
	bool MemCheck()
	{
		if (uploaded.day_getter() == Date::present.day_getter() && uploaded.month_getter() == Date::present.month_getter() && uploaded.year_getter() != Date::present.year_getter())
		{
			cout << "Memory from " << Date::present.year_getter() - uploaded.year_getter() << " years ago" << endl;
		}
	}
	virtual ~Post()
	{
		if (postID != nullptr && postcontent != nullptr)
		{
			delete[] postID;
			postID = nullptr;
			delete[] postcontent;
			postcontent = nullptr;
		}
		if (activity != NULL)
		{
			delete activity;
			activity = NULL;
		}
		for (int i = 0; i < Tcmnts; i++)
		{
			if (cmntonpost[i] != NULL)
			{
				delete cmntonpost[i];
				cmntonpost[i] = NULL;
			}
		}
		delete[] cmntonpost;
		cmntonpost = NULL;
	}
};

class Memory : public Post
{
	Post* posts;
	char* postcontent;
public:
	Memory()
	{
		posts = nullptr;
		postcontent = nullptr;
	}
	Memory(Post* obj, char* str, Object* sharedby)
	{
		posts = obj;
		postcontent = Helper::GetStringFromBuffer(str);
		sharedby_setter(sharedby);
		uploaded_setter(Date::present);
	}
	void printpostmem()
	{
		sharedby_getter()->PrintName();
		cout << " shared a memory\t(";
		uploaded_getter().printdate();
		cout << ")" << endl << postcontent << endl << "(" << Date::present.year_getter() - posts->uploaded_getter().year_getter() << "Years Ago)" << endl;
		posts->printpost();
	}
	void printPost()
	{
		printpostmem();
	}
	~Memory()
	{
		if (posts)
		{
			delete[] posts;
			posts = NULL;
		}
		delete[] postcontent;
		postcontent = nullptr;
	}
};
class Facebook
{
	User** users;
	Pages** pages;
	Post** posts;
public:
	Facebook()
	{
		users = nullptr;
		pages = nullptr;
		posts = nullptr;
	}
	void LoadData(const char* userfilename, const char* pagefilename, const char* postfilename, const char* commentfilename)
	{
		LoadPages("Pages.txt");
		LoadUser("Users.txt");
		//LoadPosts("Posts.txt");
		//LoadComments("comments.txt");
	}
	void LoadPages(const char* pagefilename)
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
	void LoadUser(const char* userfilename)
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
					users[i]->linkliked(pgptr);
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
	Post* SearchPost(Post** posts, char* id)
	{
		for (int i = 0; i < Post::TPosts; i++)
		{
			if (Helper::CompareString(posts[i]->PostID_getter(), id))
			{
				return posts[i];
			}
		}
		return NULL;
	}
	void Run()
	{
		cout << "----------------------------------------------------------------------------------------------------------\n----------------------------------------------------------------------------------------------------------\n-----------------------------------------------FACEBOOK---------------------------------------------------\n----------------------------------------------------------------------------------------------------------\n----------------------------------------------------------------------------------------------------------\n";
		cout<<"Enter a userid to set person as current user."<<endl;
		User* current = SearchUser("u7");
		if (current != nullptr)
		{
			current->PrintName();
			cout << " successfully set as Current User" << endl;
		}
		current->printfriendlist();
		current->printpagelist();
	}
	~Facebook()
	{
		for (int i = 0; i < User::totalusers; i++)
		{
			if (users[i] != NULL)
			{
				delete users[i];
				users[i] = NULL;
			}
		}
		delete[] users;
		users = NULL;
		for (int i = 0; i < Pages::totalpages; i++)
		{
			if (pages[i] != NULL)
			{
				delete pages[i];
				pages[i] = NULL;
			}
		}
		delete[] pages;
		pages = NULL;
	}
};

void main()
{
	Facebook objFacebook;
	objFacebook.LoadData("Users.txt", "Pages.txt", "Posts.txt", "comments.txt");
	objFacebook.Run();
}