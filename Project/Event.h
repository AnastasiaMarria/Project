#pragma once
#include <iostream>
#include <string>
using namespace std;

class Util {
public:
	static char* copyString(const char* source) {
		if (source == nullptr) {
			return nullptr;
		}
		char* value = new char[strlen(source) + 1];
		strcpy_s(value, strlen(source) + 1, source);
		return value;
	}
};


class Event {
	int eventId;
	char date[11] = ""; //dd/mm/yyy
	char time[5] = "";  //hh:mm
	string nameOfTheConcert;
	//Location* location;
	static int TOTAL_EVENTS;

public:
	//getters
	int getEventId() {
		return this->eventId;
	}
	char* getDate() {
		return Util::copyString(this->date);
	}
	char* getTime() {
		return Util::copyString(this->time);
	}

	//setters
	void setEventId(int EventId) {
		this->eventId = EventId;
	}
	void setDate(const char* newDate) {
		if (strlen(newDate) != 10) {
			throw exception("Wrong date");
		}
		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("Wrong date format");
		}

		strcpy_s(this->date, newDate);

	}

	void setDate(const char* newTime) {
		if (strlen(newTime) != 5) {
			throw exception("Wrong Time");
		}
		if (newTime[2] != ':') {
			throw exception("Wrong time format");
		}

		strcpy_s(this->date, newTime);
	}

	Event(int eventId, const char* date, const char* time, string nameOfTheConcert) : eventId(0), date("date"), time("time"), nameOfTheConcert(nameOfTheConcert) {

	}
};
