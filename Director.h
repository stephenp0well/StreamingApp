#ifndef DIRECTOR_H
#define DIRECTOR_H

#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include "Media.h"

class Media; // Forward declaration of the Media class to avoid compilation error 

class Director
{
public:
    Director(); // Default constructor
    Director(int val1, int val2); // Constructor with parameters (overloaded constructor)
    ~Director(); // Destructor

    void setExperienceYears(int val) { experienceYears = val; } // Setter function
    int getExperienceYears() { return experienceYears; } // Getter function
    int getAwardsWon() { return awardsWon; } // Getter function

    void addMedia(Media* media); // Function to add media to the director
    void display(); //  Display function

private:
    int experienceYears;
    int awardsWon;
    vector<Media*> mediaList; // 1:M relationship, mainting a list of media objects directed by this director
    const int maxNofItems; // Stores all media directed by this director
};

#endif