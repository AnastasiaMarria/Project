#pragma once
#include <iostream>
#include <string>
using namespace std;


enum TicketStatus { AVAILABLE, SOLDOUT };
enum TicketType { BASIC, GOLD, VIP, STAGE, FAMILY_PACK };

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

class Ticket {
	int ticketId;
	int eventId;
	float price;
	char* zone = nullptr;
	char date[11] = "";
	//*
	TicketStatus status;
	TicketType type;
	const int TOTAL_TICKETS = 4000;
	//const int MAX_STAGE_NUMBER = 150;



public:
	
	
	
	
	//constructor with param
	Ticket(int ticketId, float price, const char* date, char* zone, TicketStatus status, TicketType type) :ticketId(0), price(price), date(""), status(status), type(type) {

	}

	//copy constructor
	Ticket(Ticket& t) :Ticket(t.ticketId, t.price, t.date, t.zone, t.type, t.status) {

	}
	
	//getters
	int getTicketId() {
		return this->ticketId;
	}
	float getPrice() {
		return this->price;
	}
	char* getZone() {
		char* copy = Util::copyString(this->zone);
		return copy;
	}
	char* getDate() {
		return Util::copyString(this->date);
	}

	//setters
	void setTicketId(int TicketId) {
		this->ticketId = TicketId;
	}
	void setPrice(float Price) {
		this->price = Price;
	}
	void setZone(char* Zone) {
		this->zone = Util::copyString(Zone);
	}

	void setDate(const char* newDate) {
		if (strlen(newDate) != 10) {
			throw exception("Wrong date");
		}
		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("wrong date format");
		}
		strcpy_s(this->date, newDate);
	}
	
	//destructor
	~Ticket() {
		delete[] this->zone;
	}
	
};

