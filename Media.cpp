#include "Media.h"

Media::Media()
{

}

Media::Media(string n, string r, Director d, Streaming_Service s) 
    : name(n), releaseDate(r), director(d), streamingService(s) // Constructor with initializer list
{
    cout << "Media constructor with initializer list called" << endl;
}

Media::~Media()
{

}

void Media::display()
{
    cout << "Name: " << name << endl;
    cout << "Release Date: " << releaseDate << endl;

    // Displaying director details
    cout << "Director Experience: " << director.getExperienceYears() << " years" << endl;
    cout << "Awards Won by Director: " << director.getAwardsWon() << endl;

    // Displaying streaming service details
    cout << "Streaming on: " << streamingService.getAvailableRegion() << " | Price: $" << streamingService.getPrice() << endl;
}

void Media::setName(string val)
{
    if (val == "") // Data integrity check
    {
        cout << "Invalid name. Please enter a valid name." << endl;
    }
    else
    {
        name = val;
    }
}

void Media::setReleaseDate(string val)
{
    if (val == "") // Data integrity check
    {
        cout << "Invalid release date. Please enter a valid date." << endl;
    }
    else
    {
        releaseDate = val;
    }
}