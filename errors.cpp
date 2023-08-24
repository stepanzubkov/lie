// Formatting errors in commands
#include <iostream>
#include <string>
#include <cstddef>

#include "exit.h"

void print_error(std::string error_text, std::string command_name = "", bool fatal = false) {
    if (command_name != "") {
        std::cerr << command_name << ": ";
    }
    std::cerr << error_text << std::endl;
    if (fatal)
        throw Exit(0);
}
