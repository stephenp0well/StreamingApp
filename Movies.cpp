#include "Movies.h"

Movies::Movies()
{

}

Movies::Movies(string mName, int rYear, float dur, string gen, string dir)
{
    movieName = mName;
    releaseYear = rYear;
    duration = dur;
    genre = gen;
    director = dir;
}

Movies::~Movies()
{

}

void Movies::PrintMovieInfo()
{
    cout << "Movie Name: " << movieName << endl;
    cout << "Release Year: " << releaseYear << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Genre: " << genre << endl;
    cout << "Director: " << director << endl;
}