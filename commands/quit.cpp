#include <iostream>
#include "commands.h"
#include "../parse.h"
#include "../exit.h"

void Quit::run(CommandArgs _) {
    throw Exit(0);
}

void Quit::help() {
    std::cout << "q[uit] - Quits editor.\n";
}
