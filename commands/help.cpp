#include <iostream>
#include <map>
#include <string>
#include "commands.h"
#include "../parse.h"

Help::Help(std::map<std::string, Command*>& commands, std::map<std::string, std::string>& commands_aliases)
    : commands(commands), commands_aliases(commands_aliases) {}

void Help::run(CommandArgs args) {
    for (auto arg: args.pos_args) {
        if (auto search = commands_aliases.find(arg); search != commands_aliases.end()) {
            arg = commands_aliases[arg];
        }
        if (auto search = commands.find(arg); search == commands.end()) {
            std::cerr << "Command \"" + arg + "\" not found.\n";
        } else {
            std::cout << "Help for \"" + arg + "\" command:\n";
            commands[arg]->help();
        }
    }
}

void Help::help() {
    std::cout << "\th[elp] (command) [commands...] - Prints help for specified commands.\n";
}

