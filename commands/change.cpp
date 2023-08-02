// Change command changes current or specified line.

#include <iostream>
#include "commands.h"


Change::Change(Buffer* buffer) : buffer(buffer) {}

void Change::run(CommandArgs args) {
    if (args.pos_args.size() > 1) {
        std::cout << "change: expected 0 or 1 positional arguments (line number), got " << args.pos_args.size() << ".\n";
    }
    if (args.keyword_args.size() > 0) {
        std::cout << "change: expected 0 keywoard arguments, got " << args.keyword_args.size() << ".\n";
    }

    std::vector<std::string>* lines = buffer->get_lines();
    if (args.pos_args.size() == 0) {
        std::string current_line = (*lines)[buffer->get_current_line()];
    }
}
