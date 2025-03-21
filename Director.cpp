#include "Director.h"

Director::Director() : maxNofItems(10)// Default constructor
{
    experienceYears = 0;
    awardsWon = 0;
}

Director::Director(int val1, int val2) : maxNofItems(10) // Constructor with parameters (overloaded constructor)
{
    experienceYears = val1;
    awardsWon = val2;
}

Director::Director(const Director& other) : maxNofItems(other.maxNofItems)
{
    experienceYears = other.experienceYears;
    awardsWon = other.awardsWon;
    mediaList = other.mediaList;
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
    if (mediaList.size() >= maxNofItems) {
        std::cout << "Cannot add more media to this director." << std::endl;
        return;
    }else
    mediaList.push_back(media);
}

Director& Director::operator=(const Director& other) // Assignment operator
{
    if (this != &other) {
        experienceYears = other.experienceYears;
        awardsWon = other.awardsWon;
        mediaList = other.mediaList;
    }
    return *this;
}