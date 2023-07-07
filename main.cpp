#include <iostream>
#include <string>
#include <map>
#include "parse.h"
#include "buffer.h"
#include "commands/commands.h"
#include "exit.h"


int main() {
    std::cout << "*** \e[01;34mLie - LIne Editor for advanced programmers.\e[0m ***\n";
    std::cout << "    Type 'help <command>' for help, 'quit' for quit application.\n";
    std::string command;
    std::map<std::string, std::string> commands_aliases{
        {"q", "quit"},
        {"h", "help"},
        {"p", "print"},
        {"o", "open"}
    };
    Buffer* current_buffer = new Buffer();
    std::map<std::string, Command*> commands{
        {"quit", new Quit()},
        {"print", new Print(current_buffer)},
        {"open", new Open(current_buffer)}
    };
    commands["help"] = new Help(commands, commands_aliases);
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
