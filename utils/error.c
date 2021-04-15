/**
 * File: error.c
 * Description: Error Handling Library
 */

#include "common.h"
#include "error.h"

// Create Error Handler
ErrorHandler* createErrorHandler() {
    // Allocate Memory for Handler
    ErrorHandler* handler = (ErrorHandler*)malloc(sizeof(ErrorHandler));

    // Init Vars
    handler->error = false;
    handler->location = NULL;
    handler->message = NULL;

    // Return handler
    return handler;
}

// Helper function to Set Error
void* setError(ErrorHandler* handler, char* location, char* message) {
    // Free Current Error Strings
    if (handler->location)
        free(handler->location);

    if (handler->message)
        free(handler->message);

    // Create Error Location and Transfer Error Location
    char* errorLocation = (char*)malloc(sizeof(char)*MAX_ERROR_LOC_LEN);
    strncpy(errorLocation, location, MAX_ERROR_LOC_LEN);
    errorLocation[MAX_ERROR_LOC_LEN-1] = '\0';  // Set Null Termination
    
    // Create Error Message and Transfer Error Message
    char* errorMessage = (char*)malloc(sizeof(char)*MAX_ERROR_LEN);
    strncpy(errorMessage, message, MAX_ERROR_LEN);
    errorMessage[MAX_ERROR_LEN-1] = '\0';  // Set Null Termination

    // Set Messages
    handler->error = true;
    handler->location = errorLocation;
    handler->message = errorMessage;
    return NULL;
}

// Helper to Print Error
void printError(ErrorHandler* handler) {
    if (!handler->error || !handler->location || !handler->message) {
        printf("RuntimeError: Trying To Print Error For Error Handler %p When No Error Was Set!", handler);
    }

    // Format and Print Error
    printf("===== %s Error\n", handler->location);
    printf("%s\n", handler->message);
    printf("=====\n");
}

// Destroy Error Handler
void destroyErrorHandler(ErrorHandler* handler) {
    // Free Error Strings
    if (handler->location)
        free(handler->location);

    if (handler->message)
        free(handler->message);

    // Free Memory
    free(handler);
}
