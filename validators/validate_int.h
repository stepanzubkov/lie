// Validates integer values (line number)

#include <cstddef>
#include <string>

#include "validation_result.h"

ValidationResult<std::size_t> validate_line_number(std::string, std::size_t, std::string, bool);
