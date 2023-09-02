// Contains function that validates integers
#include <cstddef>
#include <string>
#include <iostream>

#include "../exit.h"
#include "../errors.h"
#include "validation_result.h"

ValidationResult<std::size_t> validate_line_number(std::string source, std::size_t max_limit) {
    long long number;
    std::string error_message = "";
    try {
        number = std::stoll(source);
    } catch (std::invalid_argument const&) {
        error_message = "line number should be integer.";
    }
    if (number < 1 || number > max_limit) {
        error_message = "line number should be in range 1-" + std::to_string(max_limit) + ".";
    }

    ValidationResult<std::size_t> result = {error_message.size() == 0, (std::size_t)number, error_message};
    return result;
}
