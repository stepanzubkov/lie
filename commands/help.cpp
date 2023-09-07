/*
    Command that prints help about other command.
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

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include "commands.h"
#include "../parse.h"

Help::Help(std::map<std::string, Command*>& commands, std::map<std::string, std::string>& commands_aliases)
    : commands(commands), commands_aliases(commands_aliases) {}

void Help::run(CommandArgs args) {
    std::vector<std::string> already_used_commands;
    for (auto arg: args.pos_args) {
        if (auto search = commands_aliases.find(arg); search != commands_aliases.end()) {
            arg = commands_aliases[arg];
        }
        if (std::find(already_used_commands.begin(), already_used_commands.end(), arg) != already_used_commands.end())
           continue;
        already_used_commands.push_back(arg);

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

