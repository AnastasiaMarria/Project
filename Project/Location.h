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

class Location {
	int locationId;
	string  address;
	string locationName;
	int capacity;
	int seats;
	int row;
	char* zones;
	static int totalLocations;

public:

	//default constructor 
	Location();
	Location() : locationId(-1), address(""), locationName(""), capacity(0), seats(0), row(0) {

	}

	//constructors with parameters
	Location(int locationId, string address, string locationName, int capacity, int seats,int row, const char* zones) :locationId(0), address(address), locationName(locationName), capacity(capacity),seats(seats), row(row)  {

	}

	//copy constructor
	/*Location(Location& l) : Location(l.locationId, l.address,l.locationName, l.capacity, l.seats, l.row) {

	}*/
	Location(const Location& other);
	Location& operator=(const Location& other);
	//getters

	int getLocationId() {
		return this->locationId;
	}
	string getAddress() {
		return this->address;
	}
	
	string getLocationName() {
		return this->locationName;
	}
	int getCapacity() {
		return this->capacity;
	}
	int getSeats() {
		return this->seats;
	}
	int getRow() {
		return this->row;
	}
	char* getZones()
	{
		char* tmp = new char[strlen(this->zones) + 1]; 
		strcpy_s(tmp, strlen(this->zones) + 1, this->zones);
	}


	//setters

	void setAddress(string Address) {
		this->address = Address;
	}
	
	void setLocationName(string LocationName) {
		this->locationName = LocationName;
	}
	void setCapacity(int Capacity) {
		this->capacity = Capacity;
	}
	void setRow(int Row) {
		this->row = Row;
	}
	void setSeats(int Seats) {
		this->seats = Seats;
	}
	void setLocationId(int LocationId) {
		this->locationId = LocationId;
	}
	void setZones(char* Zones)
	{
		this->zones = new char[strlen(zones) + 1];
		strcpy_s(this->zones, strlen(zones) + 1, zones);
	}

	//destructor
	~Location();

	friend ostream& operator<<(ostream& out, const Location& location) {
		return out;
	}

	friend istream& operator>>(istream& in, Location& location) {
		return in;
	}

	

	

};
