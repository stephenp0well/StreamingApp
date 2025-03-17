#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>
#include "Director.h"
#include "Streaming_Service.h"
#pragma once
using namespace std;

class Director; // Forward declaration of the Director class to avoid compilation error


class Media {
    public:
        static int mediaCount; // Static variable to keep track of the number of Media objects created

        Media(); // default constructor
        Media(string n, string r, Director* d, Streaming_Service s); // constructor with initialiser list
        ~Media(); // destructor

        void setName(string val); // setter function
        string getName() { return name; } // getter function
        void setReleaseDate(string val); // setter function
        string getReleaseDate() { return releaseDate; } // getter function
        void setStreaming_Service(Streaming_Service); // setter function
        virtual void display() = 0; // pure virtual function


        

    private:
        string name;
        string releaseDate;

        Director* director; // Director pointer
        Streaming_Service streamingService; // Streaming_Service object for 1:1 relationship
        
    };

        bool operator==(Media& lhs, Media& rhs); 
        bool operator!=(Media& lhs, Media& rhs); 

#endif