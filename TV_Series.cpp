#include "TV_Series.h"

TV_Series::TV_Series()
{

}

TV_Series::TV_Series(string n, string rd, int ne, int ns, Director director, Streaming_Service streamingService) : Media(n, rd), numEpisodes(ne), numSeasons(ns), director(director), streamingService(streamingService) // Constructor with initialiser list
{
    cout << "TV_Series constructor with initialiser list called" << endl;
}

TV_Series::~TV_Series()
{

}

void TV_Series::display() // Overriding the display function from Media
{
    cout << "Displaying from TV_Series" << endl;
    Media::display();
    cout << "Number of Episodes: " << numEpisodes << endl;
    cout << "Number of Seasons: " << numSeasons << endl;

    // Displaying director details
    cout << "Director Experience: " << director.getExperienceYears() << " years" << endl;
    cout << "Awards Won by Director: " << director.getAwardsWon() << endl;

    // Displaying streaming service details
    cout << "Streaming on: " << streamingService.getAvailableRegion() << " | Price: $" << streamingService.getPrice() << endl;
}

void TV_Series::setNumEpisodes(int val)
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

void TV_Series::setNumSeasons(int val)
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