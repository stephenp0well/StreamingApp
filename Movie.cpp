#include "Movie.h"

Movie::Movie()
{

}

Movie::Movie(string n, string rd, double b, double r, Director d, Streaming_Service s): Media(n, rd, d, s), boxOfficeValue(b), rating(r) // Constructor with initialiser list
{
   cout << "Movie constructor with initialiser list called" << endl;
}

Movie::~Movie()
{

}

void Movie::display() // Overriding the display function from Media
{
    cout << "Displaying from Movie" << endl;
    Media::display();
    cout << "Box Office Value: ";
    if (boxOfficeValue >= 1e9) { // Cleaning up the output
        cout << (boxOfficeValue / 1e9) << " billion" << endl; // 1e9 is 1 billion
    } else if (boxOfficeValue >= 1e6) { 
        cout << (boxOfficeValue / 1e6) << " million" << endl; // 1e6 is 1 million
    } else {
        cout << boxOfficeValue << endl; // If the box office value is less than 1 million
    }
    cout << "Rating: " << rating << endl;

}

void Movie::setBoxOfficeValue(double val)
{
    if (val <= 0) // Data integrity check
    {
        cout << "Invalid box office value. Please enter a valid value." << endl;
    }
    else
    {
        boxOfficeValue = val;
    }
}

void Movie::setRating(double val)
{
    if (val < 0 || val > 10) // Data integrity check
    {
        cout << "Invalid rating. Please enter a valid rating between 0 and 10." << endl;
    }
    else
    {
        rating = val;
    }
}