#include "Streaming_Service.h"

Streaming_Service::Streaming_Service() // Default constructor
{
    int price = 0;
    string availableRegions = "N/A"; 
}

Streaming_Service::Streaming_Service(int val1, string val2) // Constructor with parameters
{
    price = val1;
    availableRegions = val2;
}

Streaming_Service::~Streaming_Service() // Destructor
{

}

void Streaming_Service::display() // Display function
{
    // Displaying streaming service details
    cout << "Streaming on: " << availableRegions << " | Price: $" << price << endl;
}
// Overloaded ostream operator
ostream& operator<<(ostream& os, Streaming_Service& service) {
    os << "Price: $" << service.getPrice()
       << ", Streaming on: " << service.getAvailableRegion();
    return os;
}
// Overloaded istream operator
istream& operator>>(istream& is, Streaming_Service& service) {
    int price; 
    string availableRegions;
    cout << "Enter streaming service price: ";
    is >> service.price;
    is.ignore(); // Ignore leftover newline
    cout << "Enter available streaming service: ";
    getline(is, service.availableRegions);
    return is;
}

// Overloaded comparison operators
bool operator==(Streaming_Service &pli1, Streaming_Service &pli2)
{
	return pli1.getPrice() == pli2.getPrice() && pli1.getAvailableRegion() == pli2.getAvailableRegion();
}

bool operator!=(Streaming_Service &pli1, Streaming_Service &pli2)
{
	return pli1.getPrice() != pli2.getPrice() || pli1.getAvailableRegion() != pli2.getAvailableRegion();
}	

bool operator<(Streaming_Service &pli1, Streaming_Service &pli2)
{
	return pli1.getPrice() < pli2.getPrice();
}

bool operator>(Streaming_Service &pli1, Streaming_Service &pli2)
{
	return pli1.getPrice() > pli2.getPrice();
}

