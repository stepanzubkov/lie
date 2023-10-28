/*
    Command that appends line (lines) after specified line in buffer.
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
#include <iostream>
#include "commands.h"
#include "../buffer.h"
#include "../parse.h"
#include "../validators/validation_result.h"
#include "../validators/validate_args_count.h"
#include "../validators/validate_int.h"
#include "../datastructures/range.h"
#include "../errors.h"


Append::Append(Buffer* buffer) : buffer(buffer) {}

void Append::run(CommandArgs args) {
    ValidationResult<CommandArgs> validated_args = validate_args_count(args, Range(0, 1), Range(0));
    if (!validated_args.success) {
        print_error(validated_args.error_message, "append");
        return;
    }

    std::vector<std::string>* lines = buffer->get_lines();
    std::size_t line_number;
    if (args.pos_args.size() == 0) {
        line_number = buffer->get_current_line();
    } else {
        ValidationResult<std::size_t> validation_result = validate_line_number(args.pos_args[0], lines->size());
        if (!validation_result.success) {
            print_error(validation_result.error_message, "append");
            return;
        }
        line_number = validation_result.value;
    }

    std::cout << "Type line by line, end with single ';' on line:\n";
    std::string line;
    std::getline(std::cin, line);
    while (line != ";") {
        lines->insert(lines->begin() + line_number, line);
        line_number += 1;
        std::getline(std::cin, line);
    }
}

void Append::help() {
    std::cout << "a[ppend] - appends line or lines after specified line.\n";
}
