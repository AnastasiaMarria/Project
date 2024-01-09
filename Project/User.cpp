#include "User.h"

// Parameterized constructor
User::User(int userId, const string& userName, int age)
    : userId(userId), userName(userName), age(age) {}

// Copy constructor
User::User(const User& other)
    : userId(other.userId), userName(other.userName), age(other.age) {}

// Destructor
User::~User() {}

// Getters
//int User::getUserId()  {
//    return this->userId;
//}
//
//string User::getUserName()  {
//    return this->userName;
//}
//
//int User::getAge()  {
//    return this-> age;
//}
//
//// Setters
//void User::setUserId(int userId) {
//    this->userId = userId;
//}
//
//void User::setUserName(const string& userName) {
//    this->userName = userName;
//}
//
//void User::setAge(int age) {
//    this->age = age;
//}

// Operator overloads
ostream& operator<<(ostream& out, const User& user) {
    out << "User ID: " << user.userId << ", Name: " << user.userName << ", Age: " << user.age;
    return out;
}

istream& operator>>(istream& in, User& user) {
    in >> user.userId >> user.userName >> user.age;
    return in;
}
