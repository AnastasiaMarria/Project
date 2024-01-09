#include "Ticket.h"
#include <iostream>
using namespace std;

// Parameterized constructor
//Ticket::Ticket(int ticketId, float price, TicketStatus status, TicketType type)
//    : ticketId(ticketId), price(price), status(status), type(type) {}
//
//// Copy constructor
//Ticket::Ticket(const Ticket& other)
//    : ticketId(other.ticketId), price(other.price), status(other.status), type(other.type) {}

// Destructor
Ticket::~Ticket() {}

// Getters
//int Ticket::getTicketId()  {
//    return this->ticketId;
//}
//
//float Ticket::getPrice()  {
//    return this-> price;
//}
//
//TicketStatus Ticket::getStatus()  {
//    return this->status;
//}
//
//TicketType Ticket::getType()  {
//    return this->type;
//}
//
//// Setters
//void Ticket::setTicketId(int ticketId) {
//    this->ticketId = ticketId;
//}
//
//void Ticket::setPrice(float price) {
//    this->price = price;
//}
//
//void Ticket::setStatus(TicketStatus status) {
//    this->status = status;
//}
//
//void Ticket::setType(TicketType type) {
//    this->type = type;
//}

// Operator overloads
ostream& operator<<(ostream& out, const Ticket& ticket) {
    out << "Ticket ID: " << ticket.ticketId << ", Price: " << ticket.price
        << ", Status: " << static_cast<int>(ticket.status)
        << ", Type: " << static_cast<int>(ticket.type);
    return out;
}

istream& operator>>(istream& in, Ticket& ticket) {
    int status, type;
    in >> ticket.ticketId >> ticket.price >> status >> type;
    ticket.status = static_cast<TicketStatus>(status);
    ticket.type = static_cast<TicketType>(type);
    return in;
}

bool operator==(const Ticket& left, const Ticket& right) {
    return left == right;
}

bool operator!=(const Ticket& left, const Ticket& right) {
    return !(left == right);
}
