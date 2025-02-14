#ifndef MEDIA_H
#define MEDIA_H
#include <string>
#include <iostream>
#pragma once
using namespace std;


class Media {
    public:
        Media();
        Media(string n, string r); // Constructor with initialiser list
        ~Media();

        void setName(string val);
        string getName() { return name; }
        void setReleaseDate(string val);
        string getReleaseDate() { return releaseDate; }
        virtual void display() = 0;

    private:
        string name;
        string releaseDate;
    };

#endif