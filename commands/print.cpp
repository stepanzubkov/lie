/*
    Command that prints buffer contents.
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

#include <string>
#include <iostream>
#include <iomanip>
#include "commands.h"
#include "../buffer.h"
#include "../parse.h"
#include "../validators/validation_result.h"
#include "../validators/validate_args_count.h"
#include "../datastructures/range.h"
#include "../errors.h"


Print::Print(Buffer* buffer) : buffer(buffer) {}

void Print::run(CommandArgs args) {
    ValidationResult<CommandArgs> validated_args = validate_args_count(args, Range(0), Range(0, 1));
    if (!validated_args.success) {
        print_error(validated_args.error_message, "print");
        return;
    }

    int line_numbers_width = 0;
    std::size_t lines_count = buffer->get_lines()->size();
    if (!lines_count) {
        std::cout << "<empty buffer>\n";
        return;
    }
    do {
        line_numbers_width += 1;
    } while (lines_count /= 10);
    for (auto i = 0; i <= buffer->get_lines()->size()-1; i++) {
        std::cout << std::setw(line_numbers_width + 1) << i + 1 << ' ' << (*(buffer->get_lines()))[i] << '\n';
    }
}
void Print::help() {
    std::cout << "p[rint] - Prints content of current buffer. Shows line numbers by default.\n";
    std::cout << "Keywoard arguments:\n";
    std::cout << "    n[umber]=t[rue] or f[alse] - Show line numbers or no.\n";
}
