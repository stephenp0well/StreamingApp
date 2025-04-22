#include "Media.h"
#include "Movie.h"
#include "TV_Series.h"
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>

using namespace std;

int main() {
    vector<Media*> mediaVec;  // Vector to store media objects
    vector<Director*> directors; // Vector to store directors
    TV_Series* maxSeasonsTVSeries = nullptr; // Pointer to the TV series with the most seasons
    Streaming_Service* mostExpensiveService = nullptr; // Pointer to the most expensive streaming service
    string choice; // Initializing variable for user input.

    // Load data from file
    ifstream inFile("data.txt");
    if (!inFile.is_open()) {
        cout << "[!] No saved media found.\n";
    } else {
        cout << "[*] Loading saved media from data.txt...\n";
        string type;
        while (getline(inFile, type)) {
            Media* media = nullptr;
            if (type == "Movie") {
                media = new Movie();
            } else if (type == "TVSeries") {
                media = new TV_Series();
            }

            if (media) {
                media->loadFromFile(inFile);
                mediaVec.push_back(media);

                bool directorExists = false;
                for (auto d : directors) {
                    if (d->getExperienceYears() == media->getDirector()->getExperienceYears() &&
                        d->getAwardsWon() == media->getDirector()->getAwardsWon()) {
                        directorExists = true;
                        delete media->getDirector();
                        break;
                    }
                }

                if (!directorExists) {
                    directors.push_back(media->getDirector());
                }
            }
        }
        inFile.close();
    }

    while (true) {
        // Display menu options
        cout << "\nChoose an option:\n"
             << "1. Add a Movie\n"
             << "2. Add a TV Series\n"
             << "3. Display All Media\n"
             << "4. Display All Directors\n"
             << "5. Sort and Display All Movies by Rating (Default STL Sort)\n"
             << "6. Sort and Display All Media by Name (Explicitly Specified)\n"
             << "7. Clear All Saved Data\n"
             << "8. Exit\n";
        getline(cin, choice); // store user input in choice variable

        if (choice == "1" || choice == "2") {
            // Collect general media details
            string name, releaseDate, availableRegions;
            int experienceYears, awardsWon, price;
            
            //Get Media Information 
            cout << "Enter media name: ";
            getline(cin, name);
            cout << "Enter release date: ";
            getline(cin, releaseDate);
            
            // Get Director Information 
            cout << "Enter director's years of experience: ";
            cin >> experienceYears;
            cout << "Enter number of awards won: ";
            cin >> awardsWon;
            
            // Check if a director with the same experience and awards exists
            Director* director = nullptr;
            for (auto d : directors) {
                if (d->getExperienceYears() == experienceYears && d->getAwardsWon() == awardsWon) {
                    director = d;
                    break;
                }
            }

            // If no matching director is found, create a new one
            if (!director) {
                director = new Director(experienceYears, awardsWon);
                directors.push_back(director);
            }
            
            Streaming_Service service; // Object to store streaming service details
            cout << "Enter streaming service details: \n";
            cin >> service; // Using overloaded istream operator

            // Movie-specific details
            if (choice == "1") {
                Movie* movie = new Movie(name, releaseDate, 0, 0, director, service); // Initialize with default values
                cout << "Enter movie details:\n";
                cin >> *movie; // Use istream operator to input movie-specific details
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                mediaVec.push_back(movie);
            } 
            // TV Series-specific details
            else if (choice == "2") {
                TV_Series* tvSeries = new TV_Series(name, releaseDate, 0, 0, director, service); // Initialize with default values
                cout << "Enter TV series details:\n";
                cin >> *tvSeries; // Use istream operator to input TV series-specific details
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                mediaVec.push_back(tvSeries);
            }
        } 
        else if (choice == "3") {
            // Display all media
            if (mediaVec.empty()) {
                cout << "No media to display.\n"; // Display message if the vector is empty
            } else {
                cout << "\n*** Displaying All Media ***\n";
                for (const auto& media : mediaVec) { // Sorting the vector of media objects so that all of the objects can be displayed
                    media->display(); // Display the media object using a pointer
                }
            }
        } 
        else if (choice == "4") { // Display all directors
            if (directors.empty()) {
                cout << "No directors to display.\n"; 
            } else {
                cout << "\n*** Displaying All Directors ***\n";
                for (const auto& dir : directors) {
                    cout << *dir << endl; // Use ostream operator to display director details
                }
            }
        } 
        else if (choice == "5") {
            vector<Movie*> movieList;
        
            // Extract Movie objects from mediaVec
            for (auto media : mediaVec) {
                Movie* movie = dynamic_cast<Movie*>(media);
                if (movie) {
                    movieList.push_back(movie);
                }
            }
        
            if (movieList.empty()) {
                cout << "No movies to sort.\n";
            } else {
                // Sort using default STL sort (uses Movie::operator<)
                sort(movieList.begin(), movieList.end());
        
                cout << "\n*** Movies Sorted by Rating (Lowest to Highest) ***\n";
                for (auto movie : movieList) {
                    movie->display();
                }
            }
        }
        else if (choice == "6") {
            if (mediaVec.empty()) {
                cout << "No media to sort.\n";
            } else {
                // Custom comparator: compare Media* by name
                sort(mediaVec.begin(), mediaVec.end(), [](Media* a, Media* b) {
                    return a->getName() < b->getName(); // alphabetical order
                });
        
                cout << "\n*** Media Sorted by Name (A to Z) ***\n";
                for (auto media : mediaVec) {
                    media->display();
                }
            }
        }
        else if (choice == "7") {
            ofstream clearFile("data.txt", ios::trunc); // truncate the file
            if (clearFile.is_open()) {
                cout << "[*] All saved media has been cleared.\n";
                clearFile.close();
            } else {
                cout << "[!] Failed to open data.txt for clearing.\n";
            }
        }          
        else if (choice == "8") {
            ofstream outFile("data.txt");
            if (!outFile.is_open()) {
                cout << "[!] Failed to open file for writing.\n";
            } else {
                cout << "[*] Saving media to data.txt...\n";
                for (auto media : mediaVec) {
                    media->saveToFile(outFile);
                }
                outFile.close();
            }
            break;
        }      
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    

    // Scenario where two media objects have the same name and release date
    for (size_t i = 0; i < mediaVec.size(); ++i) {
        // Inner loop: compare with all subsequent media objects
        for (size_t j = i + 1; j < mediaVec.size(); ++j) {
            // Use overloaded == operator to compare objects 
            if (*mediaVec[i] == *mediaVec[j]) {
                cout << "The " << "#" << i + 1 << " media has the same name and release date as " << "#" << j + 1 << " entered media.\n";
            }
        }
    }

    // Using operator to find the TV series with the most seasons
    for (auto media : mediaVec) {
        TV_Series* tvSeries = dynamic_cast<TV_Series*>(media); // Going through the vector of media objects to find the TV series objects
        if (tvSeries) {
            if (!maxSeasonsTVSeries || *tvSeries > *maxSeasonsTVSeries) { // Using overloaded > operator to compare TV series objects
                maxSeasonsTVSeries = tvSeries; // Updates our pointer to this TV series object
            }
        }
    }

    // Display the TV series with the most seasons
    if (maxSeasonsTVSeries) {
        cout << "The TV series with the most seasons is:\n";
        cout << *maxSeasonsTVSeries << endl; // Use ostream operator to display TV series details
    } else {
        cout << "No TV series found.\n";
    }

    // Find and display the most expensive streaming service
    for (auto media : mediaVec) {
        Streaming_Service currentService = media->getStreamingService(); // getting the streaming service object from the media object
        if (!mostExpensiveService || currentService > *mostExpensiveService) { // Using overloaded > operator to compare streaming service objects
            if (mostExpensiveService) { // Cleans up the previous most expensive if it exists 
                delete mostExpensiveService;
            }
            mostExpensiveService = new Streaming_Service(currentService); // Make a copy of the current service 
            }
        }
    // Display results 
    if (mostExpensiveService) {
        cout << "\nThe most expensive streaming service is:\n";
        cout << *mostExpensiveService << endl; // use ostream operator to display streaming service details
        delete mostExpensiveService; // Clean up the dynamically allocated object
    } else {
        cout << "\nNo streaming services found.\n";
        }

    // Cleanup dynamically allocated objects
    for (auto media : mediaVec) {
        delete media;
    }
    for (auto director : directors) {
        delete director;
    }
    
    return 0;
}