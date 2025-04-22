#ifndef MOVIE_H
#define MOVIE_H

#pragma once

#include "Media.h"

class Movie : public Media // Inheriting from the Media class
{
public:
    Movie(); // Default constructor
    Movie(string n, string rd, double b, double r, Director* d, Streaming_Service s); // Constructor with initialiser list
    ~Movie(); // Destructor

    void setBoxOfficeValue(double val); // Setter function
    double getBoxOfficeValue() { return boxOfficeValue; } // Getter function
    void setRating(double val); // Setter function
    double getRating() { return rating; } // Getter function
    void display(); // Overriding the display function from Media

    friend ostream& operator<<(ostream& os,  Movie& movie); // ostream opeator 
    friend istream& operator>>(istream& is, Movie& movie); // istream operator

    // Overriding pure virtual functions from Media for file I/O
    void saveToFile(ofstream& out) override;
    void loadFromFile(ifstream& in) override;


private:
    double boxOfficeValue; 
    double rating;
    
};
    
    bool operator==(Movie&, Movie&); // Overloading the == operator
    bool operator!=(Movie&, Movie&); // Overloading the != operator
    bool operator<(Movie&, Movie&); // Overloading the < operator
    bool operator>(Movie&, Movie&); // Overloading the > operator

#endif