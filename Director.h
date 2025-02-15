#ifndef DIRECTOR_H
#define DIRECTOR_H

#pragma once
using namespace std;
#include <string>

class Director
{
public:
    Director();
    Director(int val1, int val2);
    ~Director();

    void setExperienceYears(int val) { experienceYears = val; }
    int getExperienceYears() { return experienceYears; }
    void setAwardsWon(int val) { awardsWon = val; }
    int getAwardsWon() { return awardsWon; }

private:
    int experienceYears;
    int awardsWon;
};

#endif