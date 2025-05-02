#ifndef STREAMINGEXCEPTION_H
#define STREAMINGEXCEPTION_H

#pragma once

#include <exception>  // Base exception class from STL
#include <string>     // For storing exception messages

using namespace std;

/**
 * Base exception class for all streaming application exceptions
 * Provides a common interface for handling errors in the streaming service
 */
class StreamingException : public exception {
protected:
    string message;  // Stores the error message text
public:
    /**
     * Constructor that takes an error message
     * @param msg The error message to store
     */
    StreamingException(const string& msg) : message(msg) {}
    
    /**
     * Returns the error message as C-style string
     * Required by std::exception interface
     * @return C-style string containing the error message
     */
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

#endif
