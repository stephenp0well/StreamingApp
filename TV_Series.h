#ifndef TV_SERIES_H
#define TV_SERIES_H

#pragma once

class TV_Series
{
public:
    TV_Series();
    ~TV_Series();

    void setNumEpisodes(int val) { numEpisodes = val; }
    int getNumEpisodes() { return numEpisodes; }
    void setNumSeasons(int val) { numSeasons = val; }
    int getNumSeasons() { return numSeasons; }

private:
    int numEpisodes;
    int numSeasons;
};

#endif