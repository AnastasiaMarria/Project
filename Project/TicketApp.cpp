
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
	char date[11];
	char time[6];
	string nameOfTheConcert;

public:
	//default constructor
	Event() :eventId(-1), nameOfTheConcert("") {
		this->setDate("00/00/0000");
		this->setTime("00:00");
	}

	//constructor with parameters
	Event(int eventId, const char* date, const char* time, string nameOfTheConcert) : eventId(0), nameOfTheConcert(nameOfTheConcert) {
		this->setDate("00/00/0000");
		this->setTime("00:00");
	}
	//copy constrcutor
	Event(Event& e) : Event(e.eventId, e.date, e.time, e.nameOfTheConcert) {

	}
	//getters
	int getEventId() {
		return this->eventId;
	}
	const char* getDate() {
		return Util::copyString(this->date);

	}
	const char* getTime() {
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

	void setTime(const char* newTime) {
		if (strlen(newTime) != 5) {
			throw exception("Wrong Time");
		}
		if (newTime[2] != ':') {
			throw exception("Wrong time format");
		}

		strcpy_s(this->time, newTime);
	}
	~Event() {
		delete[] this->date;
		delete[] this->time;
	}

	friend ostream& operator<<(ostream& out, Event& e) {
		out << "Event ID: " << e.eventId << "\n";
		out << "Date: " << e.date << "\n";
		out << "Time: " << e.time << "\n";
		out << "The name of the concert is: " << e.nameOfTheConcert << "\n";
		return out;
	}

	friend istream& operator>>(istream& in, Event& e) {
		cout << "Please enter Event ID: ";
		in >> e.eventId;
		cout << "Please select  a date: (DD/MM/YYYY): ";
		in >> e.date;
		cout << "Please select a time: ";
		in >> e.time;
		cout << "Enter the name of the event: ";
		in >> e.nameOfTheConcert;
		return in;
	}
};




class User {
	int userId;
	char* userName=nullptr;
	//int ticketId;
	int age;
	//static int TOTAL_USERS;

public:

	//default constructor
	User() : userId(-1), userName(nullptr), age(0) {
	}

	//constructor with paramteres
	User(int userId, const char* userName, int age) : userId(0), age(age) {
		if (this->userName != nullptr)
		{
			this->userName = new char[strlen(userName) + 1];
			strcpy_s(this->userName, strlen(userName) + 1, userName);
		}
		else
			this->userName = nullptr;
		//incrementUser();
	}

	//copy constructor
	User(User& u) : User(u.userId, u.userName, u.age) {

	}



	//getters
	int getUserId() {
		return this->userId;
	}
	int getAge() {
		return this->age;
	}
	char* getUserName() {
		char* copy = Util::copyString(this->userName);
		return copy;
	}
	//setters
	void setUserId(int UserId) {
		this->userId = UserId;
	}
	void setAge(int Age) {
		this->age = Age;
	}
	void setUserName(const char* UserName) {
		delete[] this->userName;
		
		if (UserName != nullptr)
		{
			delete[] this->userName;
			this->userName = new char[strlen(UserName) + 1];
			strcpy_s(this->userName, strlen(UserName) + 1, UserName);
		}
		else { this->userName = nullptr; }
	}

	/*static void incrementUser()
	{
		User::TOTAL_USERS++;
	}*/
	//destructor
	~User() {
		delete[] this->userName;
		//User::TOTAL_USERS--;
	}
};


class Location {
	int locationId;
	string address;
	string city;
	string country;
	string locationName;
	int capacity;

	//char* zones=nullptr;
	//static int totalLocations;

public:

	//default constructor 
	Location() : locationId(-1), address(""), city(""), country(""), locationName(""), capacity(0) {

	}

	//constructors with parameters
	Location(int locationId, string address, string city, string country, string locationName, int capacity /*,char zones*/) :locationId(0), address(address), city(city), country(country), locationName(locationName), capacity(capacity) {

	}

	//copy constructor
	Location(Location& l) : Location(l.locationId, l.address, l.city, l.country, l.locationName, l.capacity) {

	}

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

	friend ostream& operator<<(ostream& out, Location& l) {
		out << "Location ID: " << l.locationId << "\n";
		out << "Adrees: " << l.address << "\n";
		out << "City: " << l.city << "\n";
		out << "Country: " << l.country << "\n";
		out << "Capacity: " << l.capacity << "\n";
		out << "The location of the event is: " << l.locationName << "\n";
		return out;
	}

	friend istream& operator>>(istream& in, Location& l) {
		cout << "Please enter location ID: ";
		in >> l.locationId;
		cout << "Please select  a City:  ";
		in >> l.city;
		cout << "Please select a Country: ";
		in >> l.country;
		return in;
	}

};




enum TicketStatus { AVAILABLE, SOLDOUT };
enum TicketType { BASIC, GOLD, VIP, STAGE, FAMILY_PACK };

class Ticket {
	int ticketId;
	//int eventId;
	float price;
	char* zone;
	char date[11];
	//*
	TicketStatus status;
	TicketType type;
	const int TOTAL_TICKETS = 4000;
	//const int MAX_STAGE_NUMBER = 150;



public:


	Ticket() : ticketId(-1), price(0.0), zone(nullptr), date(""), status(AVAILABLE), type(BASIC) {
	}

	//constructor with param
	Ticket(int ticketId, float price, const char* date, char* zone, TicketStatus status, TicketType type) :ticketId(0), price(price), date(""), status(status), type(type) {

	}

	//copy constructor
	/*Ticket(Ticket& t) : Ticket(t.ticketId, t.price, t.date, t.zone, t.type, t.status) {

	}*/

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

	friend ostream& operator<<(ostream& out, Ticket& t) {
		out << "Ticket ID: " << t.ticketId << "\n";
		out << "Price: " << t.price << "\n";
		out << "Zone: " << t.zone << "\n";
		out << "Type: " << t.type << "\n";
		out << "Status: " << t.status << "\n";
		
		return out;
	}

	friend istream& operator>>(istream& in, Ticket& t) {
		cout << "Please enter ticket ID: ";
		in >> t.ticketId;
		cout << "Please select  a price:  ";
		in >> t.price;
		cout << "Please select a Type: ";
		in >> t.type;

		return in;
	}

	

};

int main()
{
	

		Event event1;
		Event event2(1, "12/6/2024", "18:30", "Coldplay");

		User user1(1, "Maria Ioana", 25);
		User user2(user1);

		Location location1(1, "Bld. Unirii", "Bucuresti", "Romania", "Romexpo", 1000);

		//Ticket ticket1(1, 126.0, "8/9/2026", "VIP", TicketStatus::AVAILABLE, TicketType::VIP);

	
		cout << "User 1 Name: " << user1.getUserName() << endl;
		user1.setUserName("Maria Ioana ");
		cout << "Updated User 1 Name: " << user1.getUserName() << endl;

		cout << "Location 1 Capacity: " << location1.getCapacity() << endl;
		location1.setCapacity(1200);
		cout << "Updated Location 1 Capacity: " << location1.getCapacity() << endl;

		//cout << "Ticket 1 Price: " << ticket1.getPrice() << endl;
		//ticket1.setPrice(60.0);
		//cout << "Updated Ticket 1 Price: " << ticket1.getPrice() << endl;


		return 0;
	


};




