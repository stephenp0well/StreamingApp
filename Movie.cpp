#include "Movie.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits> // Add this for std::numeric_limits

// Implementation of display() method
void Movie::display() {
    std::cout << "***Displaying from Movie***" << std::endl;
    Media::display(); // Call base class display method
    
    // Format box office value
    std::cout << "Box Office Value: ";
    if (boxOffice >= 1e9) { // Changed from boxOfficeValue to boxOffice
        std::cout << boxOffice / 1e9 << " billion" << std::endl;
    } else if (boxOffice >= 1e6) {
        std::cout << boxOffice / 1e6 << " million" << std::endl;
    } else {
        std::cout << boxOffice << std::endl;
    }
    
    // Display rating
    std::cout << "Rating: " << rating << std::endl;
}

// Implementation of the saveToFile method
void Movie::saveToFile(std::ofstream& out) {
    out << "Movie" << '\n';
    out << getName() << '\n';
    out << getReleaseDate() << '\n';
    out << boxOffice << '\n'; // Changed from boxOfficeValue to boxOffice
    out << rating << '\n';
    
    // Use accessor methods for private members of the Media class
    Director* dir = getDirector();
    if (dir) {
        out << dir->getExperienceYears() << '\n';
        out << dir->getAwardsWon() << '\n';
    } else {
        out << "0\n0\n"; // Default values if no director
    }
    
    Streaming_Service service = getStreamingService();
    out << service.getPrice() << '\n';
    out << service.getAvailableRegion() << '\n';
}

// Implementation of loadFromFile method with correct stream handling
void Movie::loadFromFile(std::ifstream& in) {
    std::string name, releaseDate;
    double boxOfficeVal, ratingVal, price;
    int exp, awards;
    std::string region;
    
    // Use std:: namespace for all functions and use getline properly
    std::getline(in, name);
    std::getline(in, releaseDate);
    
    // Convert ifstream to istream& for proper operator>> usage
    std::istream& inStream = in;
    
    inStream >> boxOfficeVal;
    inStream >> ratingVal;
    inStream >> exp;
    inStream >> awards;
    inStream >> price;
    inStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline
    std::getline(inStream, region);
    
    // Set values using public methods
    setName(name);
    setReleaseDate(releaseDate);
    setBoxOfficeValue(boxOfficeVal);
    setRating(ratingVal);
    
    // Create and set director
    Director* newDirector = new Director(exp, awards);
    setDirector(newDirector, true); // Take ownership of this director
    newDirector->addMedia(this);
    
    // Create and set streaming service
    Streaming_Service service(price, region);
    setStreamingService(service);
}

// Implementation of the operator<< function
std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    // Instead of trying to cast to Media, output each component individually
    os << "Name: " << movie.getName() << std::endl
       << "Release Date: " << movie.getReleaseDate() << std::endl;
       
    // Output director info if available
    Director* dir = movie.getDirector();
    if (dir) {
        os << "Director Experience: " << dir->getExperienceYears() << " years" << std::endl
           << "Awards Won by Director: " << dir->getAwardsWon() << std::endl;
    } else {
        os << "No Director Assigned" << std::endl;
    }
    
    // Output streaming service info
    Streaming_Service service = movie.getStreamingService();
    os << "Streaming on: " << service.getAvailableRegion() 
       << " | Price: $" << service.getPrice() << std::endl;
       
    // Output movie-specific fields
    os << "Box Office: " << movie.getBoxOfficeValue() << std::endl
       << "Rating: " << movie.getRating() << std::endl;
       
    return os;
}

// Implement the stream input operator
std::istream& operator>>(std::istream& in, Movie& movie) {
    std::string name, releaseDate;
    double boxOfficeVal, ratingVal;
    int exp, awards;
    double price;
    std::string region;
    
    std::getline(in, name);
    std::getline(in, releaseDate);
    
    in >> boxOfficeVal;
    in >> ratingVal;
    in >> exp;
    in >> awards;
    in >> price;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(in, region);
    
    movie.setName(name);
    movie.setReleaseDate(releaseDate);
    movie.setBoxOfficeValue(boxOfficeVal);
    movie.setRating(ratingVal);
    
    Director* newDirector = new Director(exp, awards);
    movie.setDirector(newDirector, true);
    newDirector->addMedia(&movie);
    
    Streaming_Service service(price, region);
    movie.setStreamingService(service);
    
    return in;
}