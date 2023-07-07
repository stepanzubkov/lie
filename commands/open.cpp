// Open command opens file in specified buffer.
#include <iostream>
#include "commands.h"
#include "../parse.h"

Open::Open(Buffer* buffer) : buffer(buffer) {}

void Open::run(CommandArgs args) {
    if (args.pos_args.size() != 1) {
        std::cerr << "open: expected 1 argument (filename), got " << args.pos_args.size() << ".\n";
        return;
    }
    if (args.keyword_args.size() > 0) {
        std::cerr << "open: expected 0 keywoard args, got " << args.keyword_args.size() << ".\n";
        return;
    }
    buffer->open_file(args.pos_args[0]);
}

void Open::help() {
    std::cout << "o[pen] - Opens a file in current buffer.\n";
}
