#include <string>
#include <iostream>
#include "commands.h"
#include "../buffer.h"
#include "../parse.h"


Print::Print(Buffer* buffer) : buffer(buffer) {}

void Print::run(CommandArgs args) {
    for (std::string& line: buffer->get_lines()) {
        std::cout << line << '\n';
    }
}
void Print::help() {}
