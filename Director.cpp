#include "Director.h"

Director::Director() // Default constructor
{
    experienceYears = 0;
    awardsWon = 0;
}

Director::Director(int val1, int val2) // Constructor with parameters (overloaded constructor)
{
    experienceYears = val1;
    awardsWon = val2;
}

Director::~Director() // Destructor
{

}

void Director::display() // Display function
{
    // Displaying director details
    cout << "Director Experience: " << experienceYears << " years" << endl;
    cout << "Awards Won by Director: " << awardsWon << endl;
    std::cout << "Directed Media: " << std::endl;

    if (mediaList.empty()) {
        std::cout << " - No media associated." << std::endl;
    } else {
        for (const auto& media : mediaList) {
            std::cout << " - " << media->getName() << " (" << media->getReleaseDate() << ")" << std::endl;
        }
    }
}

void Director::addMedia(Media* media) {
    mediaList.push_back(media);
}