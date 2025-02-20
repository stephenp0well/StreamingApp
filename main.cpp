#include "Media.h"
#include "Movie.h"
#include "TV_Series.h"
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    vector<Media*> mediaVec;  // Vector to store media objects
    string choice;

    while (true) {
        // Display menu options
        cout << "\nChoose an option:\n"
             << "1. Add a Movie\n"
             << "2. Add a TV Series\n"
             << "3. Display All Media\n"
             << "4. Exit\n";
        //cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, choice);
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer properly

        if (choice == "1" || choice == "2") {
            // Collect general media details
            string name, releaseDate, availableRegions;
            int experienceYears, awardsWon, price;

            cout << "Enter media name: ";
            getline(cin, name);
            cout << "Enter release date: ";
            getline(cin, releaseDate);
            cout << "Enter director's years of experience: ";
            cin >> experienceYears;
            cout << "Enter number of awards won: ";
            cin >> awardsWon;

            // Create Director object
            Director director(experienceYears, awardsWon);

            cout << "Enter streaming service price: ";
            cin >> price;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            cout << "Enter available regions: ";
            getline(cin, availableRegions);

            // Create Streaming_Service object
            Streaming_Service service(price, availableRegions);

            // Movie-specific details
            if (choice == "1") {
                double boxOffice, rating;

                cout << "Enter box office value: ";
                cin >> boxOffice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
                cout << "Enter rating: ";
                cin >> rating;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

                mediaVec.push_back(new Movie(name, releaseDate, boxOffice, rating, director, service));
            } 
            // TV Series-specific details
            else if (choice == "2") {
                int episodes, seasons;

                cout << "Enter number of episodes: ";
                cin >> episodes;
                cout << "Enter number of seasons: ";
                cin >> seasons;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

                mediaVec.push_back(new TV_Series(name, releaseDate, episodes, seasons, director, service));
            }
        } 
        else if (choice == "3") {
            // Display all media
            if (mediaVec.empty()) {
                cout << "No media to display.\n";
            } else {
                cout << "\n*** Displaying All Media ***\n";
                for (const auto& media : mediaVec) {
                    media->display();
                }
            }
        } 
        else if (choice == "4") {
            break;  // Exit the loop
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    // Cleanup dynamically allocated objects
    for (auto media : mediaVec) {
        delete media;
    }

    return 0;
}

    
/*
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

    cout << "Media Count: " << Media::mediaCount << endl; // Displaying the media count

    return 0;
}
    */