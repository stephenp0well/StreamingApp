#include "TV_Series.h"
#include "Movie.h"
#include "Media.h"
#include <vector>

int main()
{
    Movie m1("The Godfather", "24/03/1972", 245000000, 9.2);
    TV_Series t1("Breaking Bad", "20/01/2008", 62, 5);
    
    vector<Media*> mediaVec; // Vector of Media pointers
    mediaVec.push_back(&m1); // Pushing the address of the Movie object into the vector
    mediaVec.push_back(&t1); // Pushing the address of the TV_Series object into the vector

    for (int i = 0; i < mediaVec.size(); i++) // Looping through the vector
    {
        cout << "Vector Display Function Used" << endl;
        mediaVec[i]->display(); // Calling the display function using the vector
    }

    return 0;
}