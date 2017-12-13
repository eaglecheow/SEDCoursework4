// SEDCoursework.cpp : Defines the entry point for the console application.
//
#include "ClassFile.h"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<User>userList;

void Menu();
void AccessFeature(User selectedUser);

/*This funvtion creates User (derived classes) and saves to userList vector*/
void CreateUser()
{
	cout << "Create a user... " << endl;
	cout << "Please choose a user type : " << endl;
	cout << "1. Principal" << endl;
	cout << "2. Moderator" << endl;
	cout << "3. Content Creator" << endl;
	cout << "4. Premium User" << endl;
	cout << "5. Basic User" << endl;

	string userInput = "";

	while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
	{
		cout << "Your option : ";
		cin >> userInput;
	}

	int option = stoi(userInput);
	string username = "";
	string password = "";

	cout << "Please enter a username : ";
	cin >> username;

	cout << "Please enter a password : ";
	cin >> password;

	if (option == 1)
	{
		class Principal principal = class Principal(username, password);
		userList.push_back(principal);
	}
	else if (option == 2)
	{
		class Moderator moderator = class Moderator(username, password);
		userList.push_back(moderator);
	}
	else if (option == 3)
	{
		class ContentCreator contentCreator = class ContentCreator(username, password);
		userList.push_back(contentCreator);
	}
	else if (option == 4)
	{
		class PremiumUser premiumUser = class PremiumUser(username, password);
		userList.push_back(premiumUser);
	}
	else if (option == 5)
	{
		class BasicUser basicUser = class BasicUser(username, password);
		userList.push_back(basicUser);
	}
	else
	{
		cout << "Create user error" << endl;
	}

	Menu();
}

/*This funtion loops through the userList and shows all the username available*/
void ShowUser()
{
	for (User &user : userList)
	{
		cout << user.GetUsername() << endl;
	}

	Menu();
}

/*This function logins the user and enable user to access features*/
void Login()
{
	string username;
	bool isUsernameFound = false;
	User selectedUser = User();
	while (isUsernameFound == false)
	{
		cout << "Please enter your username : ";
		cin >> username;

		for (User &user : userList)
		{
			if (user.GetUsername() == username)
			{
				selectedUser = user;
				isUsernameFound = true;
				cout << "User found!" << endl;
			}
		}
	}

	string password;
	cout << "Please enter password : ";
	cin >> password;

	if (selectedUser.Login(password))
	{
		cout << "Login Successful!" << endl;
		AccessFeature(selectedUser);
	}
	else
	{
		cout << "Password Incorrect!";
		Login();
	}
}

/*This function allows user to access features after logging in*/
void AccessFeature(User selectedUser)
{
	bool quitToMenu = false;

	if (selectedUser.GetUserType() == Principal)
	{
		class Principal principal = class Principal();
		while (!quitToMenu)
		{
			cout << "Please select a function : " << endl;
			cout << "1. Create Content" << endl;
			cout << "2. Edit Content" << endl;
			cout << "3. Delete Content" << endl;
			cout << "4. Read Content" << endl;
			cout << "5. Exit to menu" << endl;

			string userInput = "";

			while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
			{
				cout << "Your option : ";
				cin >> userInput;
			}

			int option = stoi(userInput);

			if (option == 1)
			{
				string content = "";
				cout << "Please insert content here : ";
				cin >> content;
				principal.CreateContent(content);
			}
			else if (option == 2)
			{
				string content = "";
				cout << "Please insert content here : ";
				cin >> content;
				principal.EditContent(content);
			}
			else if (option == 3)
			{
				principal.DeleteContent();
			}
			else if (option == 4)
			{
				cout << principal.ReadContent() << endl;
			}
			else if (option == 5)
			{
				quitToMenu = true;
			}
		}
	}
	else if (selectedUser.GetUserType() == Moderator)
	{
		class Moderator moderator = class Moderator();
		while (!quitToMenu)
		{
			cout << "Please select a function : " << endl;
			cout << "1. Create Content" << endl;
			cout << "2. Edit Content" << endl;
			cout << "3. Delete Content" << endl;
			cout << "4. Read Content" << endl;
			cout << "5. Exit to menu" << endl;

			string userInput = "";

			while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
			{
				cout << "Your option : ";
				cin >> userInput;
			}

			int option = stoi(userInput);

			if (option == 1)
			{
				string content = "";
				cout << "Please insert content here : ";
				cin >> content;
				moderator.CreateContent(content);
			}
			else if (option == 2)
			{
				string content = "";
				cout << "Please insert content here : ";
				cin >> content;
				moderator.EditContent(content);
			}
			else if (option == 3)
			{
				moderator.DeleteContent();
			}
			else if (option == 4)
			{
				cout << moderator.ReadContent() << endl;
			}
			else if (option == 5)
			{
				quitToMenu = true;
			}
		}
	}
	else if (selectedUser.GetUserType() == ContentCreator)
	{
		class ContentCreator contentCreator = class ContentCreator();
		while (!quitToMenu)
		{
			cout << "Please select a function : " << endl;
			cout << "1. Create Content" << endl;
			cout << "2. Edit Content" << endl;
			cout << "3. Delete Content" << endl;
			cout << "4. Read Content" << endl;
			cout << "5. Exit to menu" << endl;

			string userInput = "";

			while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
			{
				cout << "Your option : ";
				cin >> userInput;
			}

			int option = stoi(userInput);

			if (option == 1)
			{
				string content = "";
				cout << "Please insert content here : ";
				cin >> content;
				contentCreator.CreateContent(content);
			}
			else if (option == 2)
			{
				string content = "";
				cout << "Please insert content here : ";
				cin >> content;
				contentCreator.EditContent(content);
			}
			else if (option == 3)
			{
				contentCreator.DeleteContent();
			}
			else if (option == 4)
			{
				cout << contentCreator.ReadContent() << endl;
			}
			else if (option == 5)
			{
				quitToMenu = true;
			}
		}
	}
	else if (selectedUser.GetUserType() == PremiumUser)
	{
		class PremiumUser premiumUser = class PremiumUser();
		while (!quitToMenu)
		{
			cout << "Please select a function : " << endl;
			cout << "1. Read Content" << endl;
			cout << "2. Exit To Menu" << endl;

			string userInput = "";

			while (userInput != "1" && userInput != "2")
			{
				cout << "Your option : ";
				cin >> userInput;
			}

			int option = stoi(userInput);

			if (option == 1)
			{
				cout << premiumUser.ReadContent() << endl;
			}
			else if (option == 2)
			{
				quitToMenu = true;
			}
		}
	}
	else if (selectedUser.GetUserType() == BasicUser)
	{
		class BasicUser basicUser = class BasicUser();
		while (!quitToMenu)
		{
			cout << "Please select a function : " << endl;
			cout << "1. Read Content" << endl;
			cout << "2. Exit To Menu" << endl;

			string userInput = "";

			while (userInput != "1" && userInput != "2")
			{
				cout << "Your option : ";
				cin >> userInput;
			}

			int option = stoi(userInput);

			if (option == 1)
			{
				cout << basicUser.ReadContent() << endl;
			}
			else if (option == 2)
			{
				quitToMenu = true;
			}
		}
	}
	Menu();
}

/*This function shoews the menu and allows user to choose functions to use.*/
void Menu()
{
	cout << "Please select a function : " << endl;
	cout << "1. Create User" << endl;
	cout << "2. Show Users" << endl;
	cout << "3. Login" << endl;
	cout << "4. Exit" << endl;

	string userInput = "";

	while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4")
	{
		cout << "Your option : ";
		cin >> userInput;
	}

	int option = stoi(userInput);

	if (option == 1)
	{
		CreateUser();
	}
	else if (option == 2)
	{
		ShowUser();
	}
	else if (option == 3)
	{
		Login();
	}
	else if (option == 4)
	{
		cout << "Preparing to exit..." << endl;
	}
}


int main()
{
	Menu();

	system("pause");
	return 0;
}
