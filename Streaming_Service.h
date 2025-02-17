#ifndef STREAMING_SERVICE_H
#define STREAMING_SERVICE_H

#pragma once
using namespace std; 
#include <string>
#include <iostream>

class Streaming_Service
{
public:
    Streaming_Service();
    ~Streaming_Service();
    Streaming_Service(int val1, string val2);

    void setPrice(int val) { price = val; }
    int getPrice() { return price; }
    void setAvailableRegion(string val) { availableRegions = val; }
    string getAvailableRegion() { return availableRegions; }
    void display();

private:
    int price;
    string availableRegions;
};

#endif