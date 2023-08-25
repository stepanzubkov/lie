// Contains function that validates integers
#include <cstddef>
#include <string>
#include <iostream>

#include "../exit.h"
#include "../errors.h"
#include "validation_result.h"

ValidationResult<std::size_t> validate_line_number(std::string source, std::size_t max_limit, std::string command_name = "", bool fatal = false) {
    long long number;
    bool success = true;
    try {
        number = std::stoll(source);
    } catch (std::invalid_argument const&) {
        success = false;
        print_error("line number should be integer.", command_name, fatal);
    }
    if (number < 1 || number > max_limit) {
        success = false;
        print_error("line number should be in range 1-" + std::to_string(max_limit) + ".", command_name, fatal);
    }

    ValidationResult<std::size_t> result = {success, (std::size_t)number};
    return result;
}
