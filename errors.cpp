/*
    Formatting errors in commands
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
