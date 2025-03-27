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
// Ostream operator 
ostream& operator<<(ostream& os, Director& director) {
    os << "Director Experience: " << director.getExperienceYears() << " years\n"
       << "Awards Won by Director: " << director.getAwardsWon() << "\n"
       << "Directed Media:\n";

    if (director.mediaList.empty()) {
        os << " - No media associated.\n";
    } else {
        for (const auto& media : director.mediaList) {
            os << " - " << media->getName() << " (" << media->getReleaseDate() << ")\n";
        }
    }
    return os;
}
// Istream operator 
istream& operator>>(istream& is, Director& director) {
    cout << "Enter director years of experience: ";
    is >> director.experienceYears;  // Assign directly to the member variable
    is.ignore();
    cout << "Enter number of awards won by director: ";
    is >> director.awardsWon;  // Assign directly to the member variable
    is.ignore();

    return is;
}


