/*
    Main file. Launches programm.
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
#include <new>
#include <string>
#include <map>
#include "parse.h"
#include "buffer.h"
#include "commands/commands.h"
#include "exit.h"

void validate_args(int, char**);

int main(int argc, char** argv) {
    try {
        validate_args(argc, argv);
    } catch (Exit const& e) {
        return e.value;
    }
    std::cout << "*** \e[01;34mLie - LIne Editor for advanced programmers.\e[0m ***\n";
    std::cout << "    Type 'help <command>' for help, 'quit' for quit application.\n";
    std::string command;
    std::map<std::string, std::string> commands_aliases{
        {"q", "quit"},
        {"h", "help"},
        {"p", "print"},
        {"o", "open"},
        {"g", "goto"},
        {"c", "change"},
    };
    Buffer* current_buffer = new Buffer();
    std::map<std::string, Command*> commands{
        {"quit", new Quit()},
        {"print", new Print(current_buffer)},
        {"open", new Open(current_buffer)},
        {"goto", new GoTo(current_buffer)},
        {"change", new Change(current_buffer)},
    };
    commands["help"] = new Help(commands, commands_aliases);
    if (argc > 1) {
        CommandArgs open_args = parse_args(argv[1]);
        commands["open"]->run(open_args);
    }
    while (true) {
        std::cout << current_buffer->get_current_line() + 1 << "> ";
        std::cin >> command;
        std::string args_str;
        std::getline(std::cin, args_str);
        CommandArgs args = parse_args(args_str);

        if (auto search = commands_aliases.find(command); search != commands_aliases.end()) {
            command = commands_aliases[command];
        }
        if (auto search = commands.find(command); search == commands.end()) {
            std::cerr << "Command \"" + command + "\" not found.\n";
        } else {
            try {
                commands[command]->run(args);
            } catch (Exit const& e) {
                return e.value;
            }
        }
    }
}

void validate_args(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Expected 1 argument (filename), got " << argc - 1 << ".\n";
        throw Exit(1);
    }
}
