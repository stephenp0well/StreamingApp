#ifndef MOVIE_H
#define MOVIE_H

#pragma once

class Movie
{
public:
    Movie();
    ~Movie();

    void setBoxOfficeValue(double val) { boxOfficeValue = val; }
    double getBoxOfficeValue() { return boxOfficeValue; }
    void setRating(double val) { rating = val; }
    double getRating() { return rating; }

private:
    double boxOfficeValue;
    double rating;
};

#endif