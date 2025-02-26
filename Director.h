#ifndef DIRECTOR_H
#define DIRECTOR_H

#pragma once
using namespace std;
#include <string>
#include <iostream>

class Director
{
public:
    Director(); // Default constructor
    Director(int val1, int val2); // Constructor with parameters (overloaded constructor)
    ~Director(); // Destructor

    void setExperienceYears(int val) { experienceYears = val; } // Setter function
    int getExperienceYears() { return experienceYears; } // Getter function
    int getAwardsWon() { return awardsWon; } // Getter function
    void display(); //  Display function

private:
    int experienceYears;
    int awardsWon;
};

#endif