#include "Media.h"
#include "Director.h"

int Media::mediaCount = 0; // Static variable to keep track of the number of Media objects created

Media::Media()  // Default constructor
{
    name = "";
    releaseDate = "";
    director = nullptr;
    mediaCount++;   
}

Media::Media(string n, string r, Director* d, Streaming_Service s) // Constructor with parameters
    : name(n), releaseDate(r), director(d), streamingService(s) // Constructor with initializer list
{
    cout << "***Media constructor with initializer list called***" << endl;
    mediaCount++;
    if (director) {
        director->addMedia(this); // Associate media with the director
    }
}

Media::~Media() // Destructor
{
    cout << "***Media destructor called***" << endl;
    mediaCount--;
}

void Media::display() // Display function
{
    cout << "Name: " << name << endl;
    cout << "Release Date: " << releaseDate << endl;

    if (director) {  // Check if the director is assigned
        cout << "Director Information: " << endl;
        director->display(); 
    } else {
        cout << "No Director Assigned." << endl;
    }

    //director.display(); // Display director details
    streamingService.display(); // Display streaming service details
}

void Media::setName(string val) // Setter function
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

void Media::setReleaseDate(string val) // Setter function
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
/*
void Media::setDirector(Director dir) // Setter function
{
    director = dir;
}
*/

void Media::setStreaming_Service(Streaming_Service stream) // Setter function
{
    streamingService = stream;
}