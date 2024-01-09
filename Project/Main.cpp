#include <iostream>
#include "Event.h"
#include "Ticket.h"
#include "User.h"
#include "Location.h"

using namespace std;

int main() {
    
    Event event(1, "06/06/2024", "21:00", "Concert");
    cout << "Event Details: " << endl << event << endl;

    
    Ticket ticket(10, 199.99, TicketStatus::AVAILABLE, TicketType::VIP);
    cout << "Ticket Details: " << endl << ticket << endl;

    User user(1, "Ana Maria", 28);
    cout << "User Details: " << endl << user << endl;

   
    Location location(1, "Arenele Roamane", "123 Calea Dorobanti",1000, 500, 200,"B2");
    cout << "Location Details: " << endl << location << endl;

    User newUser;
    cout << "Enter new user details (ID, Name, Age): ";
    cin >> newUser;
    cout << "New User Entered: " << endl << newUser << endl;

    // Add more functionalities as per your project requirements

    return 0;
}
