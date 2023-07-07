// Exit exception class
// throw it with argument 0 to exit application
#include <exception>

struct Exit : public std::exception { 
    int value;
    Exit(int value);
};

