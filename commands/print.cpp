#include <string>
#include <iostream>
#include <iomanip>
#include "commands.h"
#include "../buffer.h"
#include "../parse.h"


Print::Print(Buffer* buffer) : buffer(buffer) {}

void Print::run(CommandArgs args) {
    int line_numbers_width = 0;
    std::size_t lines_count = buffer->get_lines()->size();
    do {
        line_numbers_width += 1;
    } while (lines_count /= 10);
    for (auto i = 1; i <= buffer->get_lines()->size(); i++) {
        std::cout << std::setw(line_numbers_width + 1) << i << ' ' << (*(buffer->get_lines()))[i] << '\n';
    }
}
void Print::help() {
    std::cout << "p[rint] - Prints content of current buffer. Shows line numbers by default.\n";
    std::cout << "Keywoard arguments:\n";
    std::cout << "    n[umber]=t[rue] or f[alse] - Show line numbers or no.\n";
}
