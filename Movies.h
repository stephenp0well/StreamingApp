#ifndef MOVIES_H
#define MOVIES_H

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Movies
{
public:
    Movies();
    Movies(string mName, int rYear, float dur, string gen, string dir);
    ~Movies();

        string GetmovieName() { return movieName; }
        void SetmovieName(string val) { movieName = val; }
        int GetreleaseYear() { return releaseYear; }
        void SetreleaseYear(int val);
        float Getduration() { return duration; }
        void Setduration(float val);
        string Getgenre() { return genre; }
        void Setgenre(string val) { genre = val; }
        string Getdirector() { return director; }
        void Setdirector(string val) { director = val; }
        void PrintMovieInfo();

private:

        string movieName;
        int releaseYear;
        float duration;
        string genre;
        string director;

};

#endif