#ifndef TV_SERIES_H
#define TV_SERIES_H

#pragma once

#include "Media.h"

class TV_Series : public Media
{
public:
    TV_Series();
    TV_Series(string n, string rd, int ne, int ns, Director director, Streaming_Service streamingService); // Constructor with initialiser list
    ~TV_Series();

    void setNumEpisodes(int val);
    int getNumEpisodes() { return numEpisodes; }
    void setNumSeasons(int val);
    int getNumSeasons() { return numSeasons; }
    void display();

private:
    int numEpisodes;
    int numSeasons;
    
};

#endif