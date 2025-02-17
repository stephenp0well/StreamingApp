#include "Streaming_Service.h"

Streaming_Service::Streaming_Service()
{
    int price = 0;
    string availableRegions = "N/A"; 
}

Streaming_Service::Streaming_Service(int val1, string val2)
{
    price = val1;
    availableRegions = val2;
}

Streaming_Service::~Streaming_Service()
{

}

void Streaming_Service::display()
{
    // Displaying streaming service details
    cout << "Streaming on: " << availableRegions << " | Price: $" << price << endl;
}