#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int userId;
    string userName;
    int age;

public:
    // Default constructor
    User() : userId(-1), userName(""), age(0) {}

    // Parameterized constructor
    User(int userId, const string& userName, int age);

    // Copy constructor
    User(const User& other);

    // Destructor
    ~User();

    // Getters
    int getUserId() {
        return this->userId;
    }
    string getUserName() {
        return this->userName;
    }

    int getAge() {
        return this->age;
    }

    // Setters
    void setUserId(int UserId) {
        this->userId = UserId;
    }
    void setUserName(const string& UserName) {
        this->userName = UserName;
    }
    void setAge(int Age) {
        this->age = Age;
    }

    // Operator overloads
    friend ostream& operator<<(ostream& out, const User& user);
    friend istream& operator>>(istream& in, User& user);
};
