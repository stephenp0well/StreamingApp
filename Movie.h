#ifndef MOVIE_H
#define MOVIE_H

#pragma once

#include "Media.h"

class Movie : public Media
{
public:
    Movie();
    Movie(string n, string rd, double b, double r, Director d, Streaming_Service s); // Constructor with initialiser list
    ~Movie();

    void setBoxOfficeValue(double val);
    double getBoxOfficeValue() { return boxOfficeValue; }
    void setRating(double val);
    double getRating() { return rating; }
    void display();

private:
    double boxOfficeValue;
    double rating;
    
};

#endif