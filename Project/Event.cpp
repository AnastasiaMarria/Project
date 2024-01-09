#include "Event.h"
#include<iostream>
using namespace std;

Event::Event() : eventId(-1), nameEvent("") {
    strcpy_s(date, "00/00/0000");
    strcpy_s(time, "00:00");
}

Event::Event(int eventId, const char* date, const char* time, const string& nameEvent)
    : eventId(eventId), nameEvent(nameEvent) {
    this->setDate(date);
    this->setTime(time);
}

Event::Event(const Event& other)
    : eventId(other.eventId), nameEvent(other.nameEvent) {
    strcpy_s(this->date, other.date);
    strcpy_s(this->time, other.time);
}
Event::~Event() {

}
//getters
//int Event::getEventId()  {
//    return this->eventId;
//}
//
//const char* Event::getDate()  {
//    return this->date;
//}
//
//const char* Event::getTime() {
//    return this->time;
//}
//
//string Event::getNameEvent()  {
//    return this->nameEvent;
//}
// Setters
//void Event::setEventId(int EventId) {
//    this->eventId = EventId;
//}

void Event::setDate(const char* nDate) {
    if (strlen(nDate) != 10 || nDate[2] != '/' || nDate[5] != '/') {
        throw exception ("Wrong date format");
        strcpy_s(this->date, "00/00/0000");
        return;
    }
    strcpy_s(this->date, nDate);
}
void Event::setTime(const char* nTime) {
    
    if (strlen(nTime) != 5 || nTime[2] != ':') {
        throw exception("Wrong time format");
        strcpy_s(this->time, "00:00");
        return;
    }
    strcpy_s(this->time, sizeof(this->time),nTime);
}

//void Event::setNameEvent(string NameEvent) {
//    this->nameEvent = NameEvent;
//}
Event& Event::operator=(const Event& other) {
    if (this != &other) { 

        eventId = other.eventId;
        nameEvent = other.nameEvent;

        
        strcpy_s(this->date, sizeof(this->date), other.date);
        strcpy_s(this->time, sizeof(this->time), other.time);
    }
    return *this;
}


ostream& operator<<(ostream& out, const Event& event) {
    out << "Event ID: " << event.eventId << endl;
    out << "Date: " << event.date << endl;
    out << "Time: " << event.time << endl;
    out << "Name of Event: " << event.nameEvent<< endl;
    return out;
}

istream& operator>>(istream& in, Event& event) {
    int eventId;
    char date[11];
    char time[6];
    string nameEvent;

    cout << "Enter Event ID: ";
    in >> eventId;
    event.setEventId(eventId);

    cout << "Enter Date (DD/MM/YYYY): ";
    in >> date;
    event.setDate(date);

    cout << "Enter Time (HH:MM): ";
    in >> time;
    event.setTime(time);

    cout << "Enter Name of the Event: ";
    in.ignore(); 
    getline(in, nameEvent);
    event.setNameEvent(nameEvent);

    return in;
}

//bool operator==(const Event& left, const Event& right) {
//    return left == right &&;
//   
//}
//
//bool operator!=(const Event& left, const Event& right) {
//    return !(left == right);
//}