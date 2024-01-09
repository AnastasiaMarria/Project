#include "Location.h"
#include <iostream>
using namespace std;


// Default constructor
Location::Location() : locationId(-1), address(""), locationName(""), capacity(0), seats(0), row(0), zones(nullptr) {
}

// Constructor with parameters
Location::Location(int locationId, string address, string locationName, int capacity, int seats, int row, const char* zones)
    : locationId(locationId), address(address), locationName(locationName), capacity(capacity), seats(seats), row(row) {
    if (zones) {
        size_t length = strlen(zones) + 1;
        this->zones = new char[length];
        strcpy_s(this->zones, length, zones);
    }
    
}

// Copy constructor
Location::Location(const Location& other)
    : locationId(other.locationId), address(other.address), locationName(other.locationName),
    capacity(other.capacity), seats(other.seats), row(other.row), zones(nullptr) {
    if (other.zones != nullptr) {
        zones = new char[strlen(other.zones) + 1];
        strcpy(zones, other.zones);
    }
}



// Copy assignment operator
Location& Location::operator=(const Location& other) {
    if (this != &other) {
        locationId = other.locationId;
        address = other.address;
        locationName = other.locationName;
        capacity = other.capacity;
        seats = other.seats;
        row = other.row;

        delete[] zones; // Free existing resource
        zones = nullptr;
        if (other.zones != nullptr) {
            zones = new char[strlen(other.zones) + 1];
            strcpy(zones, other.zones);
        }
        else {
            zones = nullptr;
        }
    }
    return *this;
}

// Destructor
Location::~Location() {
    delete[] zones; // Free dynamically allocated memory
}

// Overloaded ostream operator (<<)
ostream& operator<<(ostream& out, const Location& location) {
    out << "Location ID: " << location.locationId << "\n";
    out << "Address: " << location.address << "\n";
    out << "Location Name: " << location.locationName << "\n";
    out << "Capacity: " << location.capacity << "\n";
    out << "Seats: " << location.seats << "\n";
    out << "Row: " << location.row << "\n";
    out << "Zones: ";
    if (location.zones != nullptr) {
        out << location.zones;
    }
    out << "\n";
    return out;
}

// Overloaded istream operator (>>)
istream& operator>>(istream& in, Location& location) {
    // Assuming proper console prompts are required for user input.
    cout << "Enter Location ID: ";
    in >> location.locationId;
    cout << "Enter Address: ";
    in >> location.address;
    cout << "Enter Location Name: ";
    in >> location.locationName;
    cout << "Enter Capacity: ";
    in >> location.capacity;
    cout << "Enter Number of Seats: ";
    in >> location.seats;
    cout << "Enter Number of Rows: ";
    in >> location.row;
    cout << "Enter Zones: ";
    string zonesTemp;
    in >> zonesTemp;
    delete[] location.zones;
    location.zones = new char[zonesTemp.length() + 1];
    strcpy(location.zones, zonesTemp.c_str());

    return in;
}
