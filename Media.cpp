#include "Media.h"
#include "Director.h"

int Media::mediaCount = 0; // Static variable to keep track of the number of Media objects created

Media::Media()  // Default constructor
{
    name = "";
    releaseDate = "";
    director = nullptr;
    mediaCount++;   
}

Media::Media(string n, string r, Director* d, Streaming_Service s) // Constructor with parameters
    : name(n), releaseDate(r), director(d), streamingService(s) // Constructor with initializer list
{
    cout << "***Media constructor with initializer list called***" << endl;
    mediaCount++;
    if (director) {
        director->addMedia(this); // Associate media with the director
    }
}

Media::Media(Media &objBeingCopied) // Copy constructor
{
	cout << "user-defined copy constructor, object being copied is " << objBeingCopied.getName() << endl;
	// shallow copy of the variable values that are not pointers values 
	this->getName() = objBeingCopied.getName();
	this->getReleaseDate() = objBeingCopied.getReleaseDate();
    this->streamingService = objBeingCopied.streamingService;
	// deep copy the pointer variable (copy the values the pointer points to and not the pointer value itself)
	if (objBeingCopied.director)
	{
		director = new Director(); // allocate dynamic memory from the heap for our copy
		*director = *(objBeingCopied.director);
	}
	else {
		director = 0;
	}
	mediaCount++;
}

Media &Media::operator=(Media &objBeingCopied) // over-loaded assignment operator for deep coyping of pointer fields
{
	cout << "overloaded assignment operator, object being copied is " << objBeingCopied.getName() << endl;
	// check for self-assignment to avoid copying an object to itself e.g. s1 = s1;
	if (this == &objBeingCopied) 
		return *this; //skip the rest of the function as there is no need for it

    // deallocate any memory that the object being updated is holding!
	delete director;
	// shallow copy of the variable values that are not pointers values
	this->name = objBeingCopied.getName();
	this->releaseDate = objBeingCopied.getReleaseDate();
    this->streamingService = objBeingCopied.streamingService;

	// deep copy the pointer variable (copy the values the pointer points to and not the pointer value itself)
	if (objBeingCopied.director) //check that the pointer for the object being copied has a value
	{
		director = new Director(); // allocate new memory to hold the Director details for the object being updated
		*director = *objBeingCopied.director;
	}
	else {
		director = 0;
	}
    return *this;
}

Media::~Media() { //user defined destuctor to handle deallocation of dynamic memory
	cout<<"calling destructor for "<< this->getName()<<endl;
	mediaCount--; //decrement the counter
	if (director != nullptr)
	{
		delete director;	  // Release memory allocated for the director object
		director = nullptr; // Set the pointer to null to avoid double deletion
	}
}

void Media::display() // Display function
{
    cout << "Name: " << name << endl;
    cout << "Release Date: " << releaseDate << endl;

    if (director) {  // Check if the director is assigned
        cout << "Director Information: " << endl;
        director->display(); 
    } else {
        cout << "No Director Assigned." << endl;
    }

    streamingService.display(); // Display streaming service details
}

void Media::setName(string val) // Setter function
{
    if (val == "") // Data integrity check
    {
        cout << "Invalid name. Please enter a valid name." << endl;
    }
    else
    {
        name = val;
    }
}

void Media::setReleaseDate(string val) // Setter function
{
    if (val == "") // Data integrity check
    {
        cout << "Invalid release date. Please enter a valid date." << endl;
    }
    else
    {
        releaseDate = val;
    }
}

void Media::setStreaming_Service(Streaming_Service stream) // Setter function
{
    streamingService = stream;
}


// Overloaded Comparison Operators 

bool operator==(Media &pli1, Media &pli2)
{
	return pli1.getName() == pli2.getName() && pli1.getReleaseDate() == pli2.getReleaseDate();
}

bool operator!=(Media &pli1, Media &pli2)
{
	return pli1.getName() != pli2.getName() || pli1.getReleaseDate() != pli2.getReleaseDate();
}	

ostream& operator<<(ostream& os, Media& media) {
    os << "Name: " << media.getName() << endl;
    os << "Release Date: " << media.getReleaseDate() << endl;

    return os;
}

istream& operator>>(istream& is, Media& media) {
    string name, releaseDate;

    cout << "Enter media name: ";
    is >> name;
    cout << "Enter release date: ";
    is >> releaseDate;

    media.setName(name);
    media.setReleaseDate(releaseDate);

    return is;
}
