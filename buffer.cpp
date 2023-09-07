/*
    Buffer class. Represents class in memory.
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
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "buffer.h"

Buffer::Buffer() : current_line(0), prev_current_line(0), lines(new std::vector<std::string>) {}

Buffer::Buffer(std::string filename) : Buffer() {
    delete lines;
    open_file(filename);
}

std::vector<std::string>* Buffer::get_lines() const {
    return lines;
}

std::size_t Buffer::get_current_line() const {
    return current_line;
}

std::size_t Buffer::get_prev_current_line() const {
    return prev_current_line;
}

void Buffer::set_current_line(std::size_t curr_line) {
    prev_current_line = this->current_line;
    current_line = curr_line;
}
int Buffer::open_file(std::string filename) {
    if (file.is_open()) {
        file.close();
        file.clear();
    }
    file.open(filename, std::ios::out | std::ios::in);
    std::string line;
    lines->clear();
    while (file.good()) {
        std::getline(file, line);
        lines->push_back(line);
    }
    return file.eof();
}
int Buffer::write() {
    for (std::string line : *lines) {
        file << line;
    }
    return file.good();
}
