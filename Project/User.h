#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
	int userId;
	char* userName;
	int ticketId;
	int age;
	static int TOTAL_USERS;

public:
	
	//default constructor
	User() :userId(-1), userName(nullptr), age(0) /*,ticketId(0)*/ {

	}
	
	//constructor with paramteres
	User(int userId, const char* userName, int age/*, int ticketId*/) : userId(0), age(age) {
		if (this->userName != nullptr)
		{
			this->userName = new char[strlen(userName) + 1];
			strcpy_s(this->userName, strlen(userName) + 1, userName);
		}
		else
			this->userName = nullptr;
		incrementUser();
	}

	//copy constructor
	User(User& u) : User(u.userId, u.userName, u.age) {

	}

	

	User(const User& other) : userId(other.userId), age(other.age), ticketId(other.ticketId) {
		this->userName = new char(*(other.userName));
	}

	
	//getters
	int getUserId() {
		return this->userId;
	}
	int getAge() {
		return this->age;
	}
	char* getUserName() {
		char* copy = new char[strlen(userName) + 1];
		strcpy_s(copy, strlen(this->userName) + 1, this->userName);
	}
	//setters
	void setUserId(int UserId) {
		this->userId = UserId;
	}
	void setAge(int Age) {
		this->age = Age;
	}
	void setUserName(const char* UserName) {
		if (UserName != nullptr)
		{
			delete[] this->userName;
			this->userName = new char[strlen(UserName) + 1];
			strcpy_s(this->userName, strlen(UserName) + 1, UserName);
		}
		else this->userName = nullptr;
	}

	static void incrementUser()
	{
		User::TOTAL_USERS++;
	}
	//destructor
	~User() {
		delete[] this->userName;
		User::TOTAL_USERS --;
	}
};

