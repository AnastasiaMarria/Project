#pragma once

#include <iostream>
#include <string>
using namespace std;

enum TicketStatus { AVAILABLE, SOLDOUT };
enum TicketType { BASIC, GOLD, VIP, STAGE, FAMILY_PACK };


class Ticket {
	int ticketId;
	double price;
	TicketStatus status;
	TicketType type;
	string info;
	const int TOTAL_TICKETS = 4000;

public:
	Ticket() :ticketId(-1), price(0.0), status(AVAILABLE), type(BASIC) {

	}
	Ticket(int ticketId, double price, TicketStatus status, TicketType type) :ticketId(0), price(price),  status(status), type(type) {

	}
	Ticket(const Ticket& other);
	Ticket& operator=(const Ticket& other);


	//getters
	int getTicketId() {
		return this->ticketId;
	}
	double getPrice() {
		return this->price;
	}
	TicketStatus getStatus() {
		return this->status;
	}
	TicketType getType() {
		return this->type;
	}

	//setters
	void setTicketId(int TicketId) {
		this->ticketId = TicketId;
	}
	void setPrice(double Price) {
		this->price = Price;
	}
	void setStatus(TicketStatus Status) {
		this->status = Status;
	}
	void setType(TicketType Type) {
		this->type = Type;
	}
	~Ticket();
	friend ostream& operator<<(ostream& out, const Ticket& ticket);
	friend istream& operator>>(istream& in, Ticket& ticket);

};
//bool operator==(const Ticket& left, const Ticket& right);
//bool operator!=(const Ticket& left, const Ticket& right);
