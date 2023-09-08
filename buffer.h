/*
    Buffer class that represents opened file
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

#include <vector>
#include <string>
#include <fstream>

#if !defined(BUFFER)
#define BUFFER

class Buffer {
    private:
        std::fstream file;
        std::string filename;
        std::vector<std::string>* lines;
        std::size_t current_line;
        std::size_t prev_current_line;
    public:
        bool changed;
        Buffer();
        Buffer(std::string filename);
        std::vector<std::string>* get_lines() const;
        std::size_t get_current_line() const;
        std::size_t get_prev_current_line() const;
        void set_current_line(std::size_t current_line);
        int open_file(std::string filename);
        int write();
        void set_filename(std::string filename);
        std::string get_filename() const;
};

#endif
