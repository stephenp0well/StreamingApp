#ifndef MOVIE_H
#define MOVIE_H

#pragma once

#include "Media.h"
#include "Director.h"
#include "Streaming_Service.h"
class Movie : public Media
{
public:
    Movie();
    Movie(string n, string rd, double b, double r, Director director, Streaming_Service streamingService); // Constructor with initialiser list
    ~Movie();

    void setBoxOfficeValue(double val);
    double getBoxOfficeValue() { return boxOfficeValue; }
    void setRating(double val);
    double getRating() { return rating; }
    void display();

private:
    double boxOfficeValue;
    double rating;

    // Creating objects for Director & Streaming_Service classes
    Director director; 
    Streaming_Service streamingService;
    
};

#endif