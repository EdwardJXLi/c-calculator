// Error Data Structure
typedef struct {
    int error;  // Boolean flag on if theres an error
    char * location;  // Where error occurred
    char * message;  // Error Message
} ErrorHandler;

// Create Error Handler
ErrorHandler * createErrorHandler();

// Helper function to Set Error
void* setError(ErrorHandler* handler, char* location, char* message);

// Helper to Print Error
void printError(ErrorHandler* handler);

// Destroy Error Handler
void destroyErrorHandler(ErrorHandler* handler);
