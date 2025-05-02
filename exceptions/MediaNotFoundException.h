#ifndef MEDIANOTFOUNDEXCEPTION_H
#define MEDIANOTFOUNDEXCEPTION_H

#pragma once

#include "StreamingException.h"  // Base exception class for streaming app

using namespace std;

/**
 * Exception thrown when a media item cannot be found
 * Used when media data is missing or corrupted
 */
class MediaNotFoundException : public StreamingException {
public:
    /**
     * Constructor that creates an exception with the media name
     * @param mediaName The name of the media item that was not found
     */
    MediaNotFoundException(const string& mediaName) 
        : StreamingException("Media not found: " + mediaName) {}
};

#endif
