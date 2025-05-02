#ifndef INVALIDMEDIAEXCEPTION_H
#define INVALIDMEDIAEXCEPTION_H

#pragma once

#include "StreamingException.h"  // Base exception class for streaming app

using namespace std;

/**
 * Exception thrown when an invalid media type is encountered
 * Used when an unknown or unsupported media type is found
 */
class InvalidMediaException : public StreamingException {
public:
    /**
     * Constructor that creates an exception with the invalid media type
     * @param mediaType The type of media that is not supported
     */
    InvalidMediaException(const string& mediaType) 
        : StreamingException("Invalid media type: " + mediaType) {}
};

#endif
