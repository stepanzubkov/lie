#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "buffer.h"

Buffer::Buffer() : current_line(0), lines({}) {}

Buffer::Buffer(std::string filename) {
    open_file(filename);
}

std::vector<std::string> Buffer::get_lines() const {
    return lines;
}

void Buffer::set_lines(std::vector<std::string> lines) {
    lines = lines;
}

std::size_t Buffer::get_current_line() const {
    return current_line;
}
void Buffer::set_current_line(std::size_t current_line) {
    current_line = current_line;
}
int Buffer::open_file(std::string filename) {
    if (file.is_open()) {
        file.close();
        file.clear();
    }
    file.open(filename, std::ios::out | std::ios::in);
    std::string line;
    lines.clear();
    while (file.good()) {
        std::getline(file, line);
        lines.push_back(line);
    }
    return file.good();
}
int Buffer::write() {
    for (std::string line : lines) {
        file << line;
    }
    return file.good();
}
