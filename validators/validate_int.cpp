/*
    Validates integer values (line number)
    Copyright (C) 2023 Stepan Zubkov <stepanzubkov@florgon.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
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
