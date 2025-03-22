#ifndef TV_SERIES_H
#define TV_SERIES_H

#pragma once

#include "Media.h"

class TV_Series : public Media
{
public:
    TV_Series(); // Default constructor
    TV_Series(string n, string rd, int ne, int ns, Director* d, Streaming_Service s); // Constructor with initialiser list
    ~TV_Series(); // Destructor

    void setNumEpisodes(int val); // Setter function
    int getNumEpisodes() { return numEpisodes; } // Getter function
    void setNumSeasons(int val); // Setter function
    int getNumSeasons() { return numSeasons; } //  Getter function
    void display(); // Display function

    friend ostream& operator<<(ostream& os,  TV_Series& tvSeries);
    friend istream& operator>>(istream& is, TV_Series& tvSeries); // istream operator

private:
    int numEpisodes;
    int numSeasons;
};

    bool operator==(TV_Series& lhs, TV_Series& rhs); 
    bool operator!=(TV_Series& lhs, TV_Series& rhs); 
    bool operator<(TV_Series& lhs, TV_Series& rhs); 
    bool operator>(TV_Series& lhs, TV_Series& rhs); 


#endif