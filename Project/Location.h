#pragma once
#include<iostream>
#include<string>
using namespace std;


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
	
	Location(int locationId, string address, string city, string country, string locationName, int capacity /*,char zones*/) :locationId(0), address(address), city(city), country(country), locationName(locationName), capacity(capacity) {

	}

};
