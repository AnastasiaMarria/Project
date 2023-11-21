#include <iostream>
#include <string>
using namespace std;


//Event.h

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
	char date[11]=""; //dd/mm/yyy
	char time[5]="";  //hh:mm
	string nameOfTheConcert;
	Location* location;
	static int TOTAL_EVENTS ;

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


//User.h

class User {
	int userId;
	string* userName;
	int ticketId;
	int age;

public:
	//getters
	int getUserId() {
		return this->userId;
	}
	int getAge() {
		return this->age;
	}
	string* getUserName() {
		return this->userName;
	}
	//setters
	void setUserId(int UserId) {
		this->userId = UserId;
	}
	void setAge(int Age) {
		this->age = Age;
	}
	void setUserName(string* UserName) {
		this->userName = UserName;
	}
		
};


//Location.h
class Location {
	int locationId;
	string address;
	string city;
	string country;
	string locationName;
	int capacity = 0;
	
	//char* zones=nullptr;
	//static int totalLocations;

public:
	
	//getters

	int getLocationId() {
		return this->locationId;
	}
	string getAddress() {
		return this->address;
	}
	string getCity() {
		return this->city;
	}
	string getCountry() {
		return this->country;
	}
	string getLocationName() {
		return this->locationName;
	}
	int getCapacity() {
		return this->capacity;
	}
	//---------------------------------------------------------------------------------------------------------
	
	//setters

	void setAddress(string Address) {
		this->address = Address;
	}
	void setCity(string City) {
		this->city = City;
	}
	void setCountry(string Country) {
		this->country = Country;
	}
	void setLocationName(string LocationName) {
		this->locationName = LocationName;
	}
	void setCapacity(int Capacity) {
		this->capacity = Capacity;
	}
	void setLocationId(int LocationId) {
		this->locationId = LocationId;
	}
	//---------------------------------------------------------------------------------------------------------
	Location(int locationId, string address, string city, string country, string locationName, int capacity /*,char zones*/) :locationId(0), address(address), city(city), country(country), locationName(locationName), capacity(capacity) {

	}

};

//Ticket.h

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
	char* zone=nullptr;
	char date[11] = "";
	//*
	TicketStatus status;
	TicketType type;
	const int TOTAL_TICKETS=4000;
	//const int MAX_STAGE_NUMBER = 150;



public:
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
	void setZone( char* Zone) {
		this->zone= Util::copyString(Zone);
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
	
	Ticket(int ticketId, float price, const char* date, char* zone, TicketStatus status, TicketType type) :ticketId(0), price(price), date(""), status(status), type(type) {

	}
};

