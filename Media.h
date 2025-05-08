#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Streaming_Service.h"

// Forward declaration
class Director;

class Media {
private:
    std::string name;
    std::string releaseDate;
    Director* director; // Director pointer
    Streaming_Service streamingService; // Streaming_Service object for 1:1 relationship
    bool ownsDirector;
    static int mediaCount; // Static counter for Media objects

public:
    // Default constructor needed for file loading
    Media() : name(""), releaseDate(""), director(nullptr), 
              streamingService(), ownsDirector(false) {
        std::cout << "***Media default constructor called***" << std::endl;
        mediaCount++;
    }
    
    // Main constructor
    Media(const std::string& name, const std::string& releaseDate, 
          Director* director, const Streaming_Service& service,
          bool takeOwnership = false)
        : name(name), releaseDate(releaseDate), 
          director(director), streamingService(service),
          ownsDirector(takeOwnership) {
        std::cout << "***Media constructor with initializer list called***" << std::endl;
        mediaCount++;
    }
    
    // Copy constructor
    Media(const Media& objBeingCopied);
    
    // Virtual destructor - implementation moved to .cpp file
    virtual ~Media();
    
    // Assignment operator
    Media& operator=(const Media& objBeingCopied);
    
    // Accessors for private members
    std::string getName() const { return name; }
    std::string getReleaseDate() const { return releaseDate; }
    Director* getDirector() const { return director; }
    Streaming_Service getStreamingService() const { return streamingService; }
    static int getMediaCount() { return mediaCount; }
    
    // Setters for private members
    void setName(const std::string& n) { name = n; }
    void setReleaseDate(const std::string& rd) { releaseDate = rd; }
    void setDirector(Director* d, bool takeOwnership = false);
    void setStreamingService(const Streaming_Service& s) { streamingService = s; }
    
    // Virtual methods that can be overridden by derived classes
    virtual void display();
    virtual void saveToFile(std::ofstream& out);
    virtual void loadFromFile(std::ifstream& in);
    
    // Operator overloads
    bool operator==(const Media& other) const;
};

// Non-member functions
std::ostream& operator<<(std::ostream& os, const Media& media);
bool operator==(Media& a, Media& b);