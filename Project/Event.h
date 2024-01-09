#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event {
	int eventId;
	char date[11];  //DD/MM//YY
	char time[6];   //HH:MM
	string nameEvent;

public:
	//default constructor

	Event() : eventId(-1),date(""), time(""), nameEvent("") {
		strcpy_s(date, 11, "00/00/0000");
		strcpy_s(time, 6, "00:00");
	}
    Event(int eventId, const char* date, const char* time, const string& nameEvent);

    // Copy constructor
    Event(const Event& other);

   

    // Getters
	int getEventId() {
		return this->eventId;
	}
	const char* getDate() {
		return this->date;
	}
	const char* getTime() {
		return this->time;
	}
	string getNameEvent() {
		return this->nameEvent;
	}

    // Setters
	void setEventId(int EventId) {
		this->eventId = EventId;
	}
	void setDate(const char* nDate);
	
	void setTime(const char* nTime);
	void setNameEvent(string NameEvent) {
		this->nameEvent = NameEvent;
	}

	//destructor
	~Event();

	friend ostream& operator<<(ostream& out, const Event& event);
	friend istream& operator>>(istream& in, Event& event);
};
bool operator==(const Event& left, const Event& right);
bool operator!=(const Event& left, const Event& right);