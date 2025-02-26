#include "TV_Series.h"

TV_Series::TV_Series() // Default constructor
{
    numEpisodes = 0;
    numSeasons = 0;
}

TV_Series::TV_Series(string n, string rd, int ne, int ns, Director d, Streaming_Service s): Media(n, rd, d, s), numEpisodes(ne), numSeasons(ns) // Constructor with initialiser list
{
    cout << "***TV_Series constructor with initialiser list called***" << endl;
}

TV_Series::~TV_Series() // Destructor
{

}

void TV_Series::display() // Overriding the display function from Media
{
    cout << "***Displaying from TV_Series***" << endl;
    Media::display();
    cout << "Number of Episodes: " << numEpisodes << endl;
    cout << "Number of Seasons: " << numSeasons << endl;
}

void TV_Series::setNumEpisodes(int val) // Setter function
{
    if (val <= 0) // Data integrity check
    {
        cout << "Invalid number of episodes. Please enter a valid number." << endl;
    }
    else
    {
        numEpisodes = val;
    }
}

void TV_Series::setNumSeasons(int val) // Setter function
{
    if (val <= 0) // Data integrity check
    {
        cout << "Invalid number of seasons. Please enter a valid number." << endl;
    }
    else
    {
        numSeasons = val;
    }
}