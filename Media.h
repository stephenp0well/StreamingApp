#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>
#include "Director.h"
#include "Streaming_Service.h"
#pragma once
using namespace std;

#include "Director.h"
#include "Streaming_Service.h"


class Media {
    public:
        static int mediaCount; // Static variable to keep track of the number of Media objects created

        Media();
        Media(string n, string r, Director d, Streaming_Service s); // constructor with initialiser list
        ~Media();

        void setName(string val);
        string getName() { return name; }
        void setReleaseDate(string val);
        string getReleaseDate() { return releaseDate; }
        void setDirector(Director);
        void setStreaming_Service(Streaming_Service);
        virtual void display() = 0;

    private:
        string name;
        string releaseDate;

        Director director; 
        Streaming_Service streamingService;
        
    };

#endif