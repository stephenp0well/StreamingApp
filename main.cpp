#include "Media.h"
#include "Movie.h"
#include "TV_Series.h"
#include <vector>

int main()
{
    
    Director director1(10, 5); // director with 10 years of experience and 5 awards won
    Streaming_Service netflix(15, "USA, Canada, UK"); // Netflix streaming service with a price of 15 and available in USA, Canada, UK

    Director director2(5, 2); // director with 5 years of experience and 2 awards won
    Streaming_Service amazonPrime(10, "USA, UK, India"); // Amazon Prime streaming service with a price of 10 and available in USA, UK, India
    
    Movie m1("The Godfather", "24/03/1972", 245000000, 9.2, director1, netflix); // Movie object with the name, release date, box office value, rating, director and streaming service
    TV_Series t1("Breaking Bad", "20/01/2008", 62, 5, director2, amazonPrime); // TV_Series object with the name, release date, number of episodes, number of seasons, director and streaming service
    
    vector<Media*> mediaVec; // Vector of Media pointers
    mediaVec.push_back(&m1); // Pushing the address of the Movie object into the vector
    mediaVec.push_back(&t1); // Pushing the address of the TV_Series object into the vector

    for (int i = 0; i < mediaVec.size(); i++) // Looping through the vector
    {
        cout << "***Vector Display Function Used***" << endl;
        mediaVec[i]->display(); // Calling the display function using the vector
    }

    return 0;
}