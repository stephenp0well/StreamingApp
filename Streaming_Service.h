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
    // Overloaded operators
    friend ostream& operator<<(ostream& os,  Streaming_Service& service); //ostream operator 
    friend istream& operator>>(istream& is, Streaming_Service& service); //istream operator 

   

    

private:
    int price;
    string availableRegions;
};

    bool operator==(Streaming_Service& lhs, Streaming_Service& rhs); 
    bool operator!=(Streaming_Service& lhs, Streaming_Service& rhs); 
    bool operator<(Streaming_Service& lhs, Streaming_Service& rhs); 
    bool operator>(Streaming_Service& lhs, Streaming_Service& rhs);   
    

#endif