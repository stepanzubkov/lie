/*
    Change command changes current or specified line.
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


Change::Change(Buffer* buffer) : buffer(buffer) {}

void Change::run(CommandArgs args) {
    if (args.pos_args.size() > 1) {
        std::cout << "change: expected 0 or 1 positional arguments (line number), got " << args.pos_args.size() << ".\n";
    }
    if (args.keyword_args.size() > 0) {
        std::cout << "change: expected 0 keywoard arguments, got " << args.keyword_args.size() << ".\n";
    }

    std::vector<std::string>* lines = buffer->get_lines();
    std::size_t line_number;
    if (args.pos_args.size() == 0) {
        line_number = buffer->get_current_line();
    } else {
        try {
            line_number = std::stoull(args.pos_args[0]) - 1;
        } catch (std::invalid_argument const&) {
            std::cerr << "change: line must be positive integer!\n";
            return;
        }
        std::size_t max_line = buffer->get_lines()->size();
        if (line_number > max_line || line_number < 1) {
            std::cerr << "change: line should be from 1 to " << max_line << ".\n";
            return;
        }
    }
    std::string line = (*lines)[line_number];

    std::cout << "The line was: " << line << std::endl;
    std::string line_text;
    std::getline(std::cin, line_text);
    (*lines)[line_number] = line_text;
}

void Change::help() {
    std::cout << "c[hange] [line] - Edits [line] if passed, if not -- edits current line.\n";
}
