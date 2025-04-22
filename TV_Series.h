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
    // Overloaded ostream & istream operators
    friend ostream& operator<<(ostream& os,  TV_Series& tvSeries); // ostream operator
    friend istream& operator>>(istream& is, TV_Series& tvSeries); // istream operator

    // File I/O implementations
    void saveToFile(ofstream& out) override;
    void loadFromFile(ifstream& in) override;


private:
    int numEpisodes;
    int numSeasons;
};
    // Comparison operators 
    bool operator==(TV_Series& lhs, TV_Series& rhs); 
    bool operator!=(TV_Series& lhs, TV_Series& rhs); 
    bool operator<(TV_Series& lhs, TV_Series& rhs); 
    bool operator>(TV_Series& lhs, TV_Series& rhs); 


#endif