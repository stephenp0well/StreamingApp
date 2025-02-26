#ifndef STREAMING_SERVICE_H
#define STREAMING_SERVICE_H

#pragma once
using namespace std; 
#include <string>
#include <iostream>

class Streaming_Service
{
public:
    Streaming_Service(); // Default constructor
    ~Streaming_Service(); // Destructor
    Streaming_Service(int val1, string val2); // Constructor with parameters

    void setPrice(int val) { price = val; } // Setter function
    int getPrice() { return price; } // Getter function
    void setAvailableRegion(string val) { availableRegions = val; } // Setter function
    string getAvailableRegion() { return availableRegions; } // Getter function
    void display(); // Display function

private:
    int price;
    string availableRegions;
};

#endif