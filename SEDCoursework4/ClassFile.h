/*
The class choosen were User as base class, derived to Admin and Consumer class. The Admin class are then
derived to Principal (who have the most function access), Moderator (who can only edit and delete contents) and 
ContentCreator (who can only create contents). The Consumer class is derived to PremiumUser (who can read premium contents) 
and BasicUser (who can read only basic content)

This choice of classes can be used in most cases like some sort of general forums where the admins has access to content creating
and editing, and consumers with different previleage in reading contents
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

enum UserPrivilage
{
	Principal, Moderator, ContentCreator, PremiumUser, BasicUser
};

class User																//Base class User
{																		//Username, Password and UserType hidden, accessed by getter
public:
	User();																//Constructors
	User(string username, string password);
	UserPrivilage GetUserType();										//UserType Getter
	string GetUsername();												//Username Getter
	bool Login(string inputPassword);									//Login Function, provide access to user based functions
	void ChangePassword(string oldPassword, string newPassword);		//Changes password
	string ReadContent();												//Returns content in string based on user type

protected:
	string Username;
	string Password;
	UserPrivilage UserType;
};

class Consumer : public User											//Inherited directly from User
{
public:
	Consumer();
	Consumer(string username, string password);
};

class PremiumUser : public Consumer										//Inherited directly from Consumer
{
public:
	PremiumUser();
	PremiumUser(string username, string password);
};

class BasicUser : public Consumer										//Inherited directly from Consumer
{
public:
	BasicUser();
	BasicUser(string username, string password);
};

class Admin : public User												//Inherited from User
{																		//Have extra virtual functions that should only be accessible by admin
public:																	//Virtual functions here are inittially unaccesible until derived class overrides it
	Admin();
	Admin(string username, string password);

	virtual void CreateContent(string content);							//Creates contents depends on user type
	virtual void EditContent(string content);							//Edits contents depends on user type
	virtual void DeleteContent();										//Delete contents depends on user type
};

class Principal : public Admin											//Inherited from Admin
{																		//overrides all virtual functions to enable access
public:
	Principal();
	Principal(string username, string password);

	void CreateContent(string content) override;
	void EditContent(string content) override;
	void DeleteContent() override;
};

class Moderator : public Admin											//Inherited from Admin
{																		//Only EditContent and DeleteContent is overriden to enable access
public:																	//CreateContent remains unaccessible by default action
	Moderator();
	Moderator(string username, string password);

	void EditContent(string content) override;
	void DeleteContent() override;
};

class ContentCreator : public Admin										//Inherited from Admin
{																		//Only CreateContent is overriden and enabled access
public:																	//Other virtual functions remains unaccesible
	ContentCreator();
	ContentCreator(string username, string password);

	void CreateContent(string content) override;
};

