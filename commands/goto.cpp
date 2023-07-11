// GoTo command class. Sets buffer's current line.

#include <cstddef>
#include <iostream>
#include "commands.h"
#include "../buffer.h"
#include "../parse.h"


GoTo::GoTo(Buffer* buffer) : buffer(buffer) {}

void GoTo::run(CommandArgs args) {
    if (args.pos_args.size() != 1) {
        std::cerr << "goto: expected 1 argument (line), got " << args.pos_args.size() << ".\n";
        return;
    }
    if (args.keyword_args.size() != 0) {
        std::cerr << "goto: expected 0 keyword arguments, got " << args.keyword_args.size() << ".\n";
        return;
    }
    std::size_t line;
    if (args.pos_args[0] == "-") {
        line = buffer->get_prev_current_line() + 1;
    } else {
        try {
            line = std::stoull(args.pos_args[0]);
        } catch (std::invalid_argument const&) {
            std::cerr << "goto: line must be positive integer!\n";
            return;
        }
    }
    std::size_t max_line = buffer->get_lines()->size();
    if (line > max_line || line < 1) {
        std::cerr << "goto: line should be from 1 to " << max_line << ".\n";
        return;
    }
    buffer->set_current_line(line - 1);
}

void GoTo::help() {
    std::cout << "g[oto] (line) - Sets current line.\n";
    std::cout << "g[oto] '-' - Sets current line to previous current line.\n";
}
