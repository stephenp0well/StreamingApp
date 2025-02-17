#include "Media.h"

Media::Media()
{

}

Media::Media(string n, string r, Director dir, Streaming_Service stream) : name(n), releaseDate(r), director(dir), streamingService(stream) // Constructor with initialiser list
{
    cout << "Media constructor with initialiser list called" << endl;
}

Media::~Media()
{

}

void Media::display()
{
    cout << "Name: " << name << endl;
    cout << "Release Date: " << releaseDate << endl;

    director.display();
    streamingService.display();
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

void Media::setDirector(Director dir)
{
    director = dir;
}

void Media::setStreaming_Service(Streaming_Service stream)
{
    streamingService = stream;
}