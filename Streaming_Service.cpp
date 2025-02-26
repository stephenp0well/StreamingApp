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