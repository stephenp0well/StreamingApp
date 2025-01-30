#include "Movies.h"

Movies::Movies() // Default constructor
{
    movieName = "";
    releaseYear = 0;
    duration = 0.0;
    genre = "";
    director = "";
}

Movies::Movies(string mName, int rYear, float dur, string gen, string dir) // Parameterised constructor
{
    movieName = mName;

    if (rYear <= 0) // Data integrity check
    {
        cout << "Invalid release year. Please enter a valid year." << endl;
    }
    else
    {
    releaseYear = rYear;
    }

    if (dur <= 0) // Data integrity check
    {
        cout << "Invalid duration. Please enter a valid duration." << endl;
    }
    else
    {
        duration = dur;
    }
    genre = gen;
    director = dir;
}

Movies::~Movies()
{

}

void Movies::PrintMovieInfo() // Print movie information
{
    cout << "Movie Name: " << movieName << endl;
    cout << "Release Year: " << releaseYear << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Genre: " << genre << endl;
    cout << "Director: " << director << endl;
}

void Movies::SetreleaseYear(int val)
{
    if (val <= 0) // Data integrity check
    {
        cout << "Invalid release year. Please enter a valid year." << endl;
    }
    else
    {
        releaseYear = val;
    }
}

void Movies::Setduration(float val)
{
    if (val <= 0) // Data integrity check
    {
        cout << "Invalid duration. Please enter a valid duration." << endl;
    }
    else
    {
        duration = val;
    }
}