#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#pragma once
using namespace std;


class Media {
    public:
        Media();
        ~Media();

        void setName(string val) { name = val; }
        string getName() { return name; }
        void setReleaseDate(string val) { releaseDate = val; }
        string getReleaseDate() { return releaseDate; }
    private:
        string name;
        string releaseDate;
    };

#endif