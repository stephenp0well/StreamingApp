#include "Director.h"

Director::Director()
{
    experienceYears = 0;
    awardsWon = 0;
}

Director::Director(int val1, int val2)
{
    experienceYears = val1;
    awardsWon = val2;
}

Director::~Director()
{

}

void Director::display()
{
    // Displaying director details
    cout << "Director Experience: " << experienceYears << " years" << endl;
    cout << "Awards Won by Director: " << awardsWon << endl;
}