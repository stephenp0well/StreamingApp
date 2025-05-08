#ifndef MOVIE_H
#define MOVIE_H

#pragma once

#include "Media.h"
#include "Director.h"
#include "Streaming_Service.h"

class Movie : public Media {
private:
    double boxOffice; // Box office value in dollars - renamed from boxOfficeValue
    double rating;    // Movie rating on a scale of 0-10

public:
    // Default constructor needed for file loading in main.cpp
    Movie() : Media(), boxOffice(0), rating(0) {
        std::cout << "***Movie default constructor called***" << std::endl;
    }
    
    // Main constructor
    Movie(const std::string& name, const std::string& releaseDate, 
          double boxOffice, double rating, 
          Director* director, const Streaming_Service& service, 
          bool takeOwnership = false)
        : Media(name, releaseDate, director, service, takeOwnership),
          boxOffice(boxOffice), rating(rating) {
        std::cout << "***Movie constructor with initialiser list called***" << std::endl;
    }
    
    // Virtual destructor
    ~Movie() override {
        std::cout << "calling destructor for " << getName() << std::endl;
        // Base class destructor will handle director deletion if needed
    }
    
    // Getters and setters
    double getBoxOfficeValue() const { return boxOffice; }
    double getRating() const { return rating; }
    
    void setBoxOfficeValue(double val) { boxOffice = val; } // Setter function
    void setRating(double val) { rating = val; } // Setter function
    
    // Virtual methods
    void display() override;
    void saveToFile(std::ofstream& out) override;
    void loadFromFile(std::ifstream& in) override;

    friend ostream& operator<<(ostream& os,  Movie& movie); // ostream operator 
    friend istream& operator>>(istream& is, Movie& movie); // istream operator
};

bool operator==(Movie&, Movie&); // Overloading the == operator
bool operator!=(Movie&, Movie&); // Overloading the != operator
bool operator<(Movie&, Movie&); // Overloading the < operator
bool operator>(Movie&, Movie&); // Overloading the > operator

// Declare the stream input operator
std::istream& operator>>(std::istream& in, Movie& movie);

#endif