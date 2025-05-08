#include "Media.h"
#include "Director.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Initialize static member
int Media::mediaCount = 0; // Static variable to keep track of the number of Media objects created

// Copy constructor
Media::Media(const Media& objBeingCopied) 
    : name(objBeingCopied.name), 
      releaseDate(objBeingCopied.releaseDate),
      director(objBeingCopied.director ? new Director(*(objBeingCopied.director)) : nullptr),
      streamingService(objBeingCopied.streamingService),
      ownsDirector(objBeingCopied.director != nullptr) // If we copied a director, we own it
{
    mediaCount++;
    cout << "***Media copy constructor called***" << endl;
}

// Implement Media's destructor here instead of in the header
Media::~Media() {
    if (ownsDirector && director) {
        delete director;
    }
    mediaCount--;
    cout << "***Media destructor called***" << endl;
}

// Assignment operator
Media& Media::operator=(const Media& objBeingCopied) {
    // Check for self-assignment
    if (this != &objBeingCopied) {
        // Clean up old resources
        if (ownsDirector && director) {
            delete director;
        }
        
        // Copy new resources
        name = objBeingCopied.name;
        releaseDate = objBeingCopied.releaseDate;
        director = objBeingCopied.director ? new Director(*(objBeingCopied.director)) : nullptr;
        streamingService = objBeingCopied.streamingService;
        ownsDirector = objBeingCopied.director != nullptr;
    }
    return *this;
}

// Implement setDirector here instead of in the header
void Media::setDirector(Director* d, bool takeOwnership) {
    if (ownsDirector && director) {
        delete director; // Delete old director if we own it
    }
    director = d;
    ownsDirector = takeOwnership;
}

// Display method implementation
void Media::display() {
    cout << "Name: " << name << endl;
    cout << "Release Date: " << releaseDate << endl;
    
    cout << "Director Information:" << endl;
    if (director) {
        cout << "Director Experience: " << director->getExperienceYears() << " years" << endl;
        cout << "Awards Won by Director: " << director->getAwardsWon() << endl;
        
        // Show media directed by this director
        cout << "Directed Media:" << endl;
        cout << " - " << getName() << " (" << getReleaseDate() << ")" << endl;
    } else {
        cout << "No Director Assigned" << endl;
    }
    
    cout << "Streaming on: " << streamingService.getAvailableRegion() << " | ";
    cout << "Price: $" << streamingService.getPrice() << endl;
}

// Fix saveToFile implementation
void Media::saveToFile(ofstream& out) {
    // ofstream doesn't support string directly, convert to c_str
    out << name.c_str() << '\n';
    out << releaseDate.c_str() << '\n';
    // Other implementations...
}

// Fix loadFromFile implementation
void Media::loadFromFile(ifstream& in) {
    // ifstream inherits from istream, so we need to use std::getline
    std::getline(in, name);
    std::getline(in, releaseDate);
    // Other implementations...
}

// Implement equality operator as member function
bool Media::operator==(const Media& other) const {
    return (name == other.name && releaseDate == other.releaseDate);
}

// Implement the operator== as non-member function
bool operator==(Media& a, Media& b) {
    return a.getName() == b.getName() && a.getReleaseDate() == b.getReleaseDate();
}

// Implement ostream operator
std::ostream& operator<<(std::ostream& os, const Media& media) {
    os << "Name: " << media.getName() 
       << "\nRelease Date: " << media.getReleaseDate();
       
    Director* dir = media.getDirector();
    if (dir) {
        os << "\nDirector Experience: " << dir->getExperienceYears() << " years"
           << "\nAwards Won by Director: " << dir->getAwardsWon();
    } else {
        os << "\nNo Director Assigned";
    }
    
    Streaming_Service service = media.getStreamingService();
    os << "\nStreaming on: " << service.getAvailableRegion()
       << " | Price: $" << service.getPrice();
       
    return os;
}

