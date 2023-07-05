#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include "parse.h"
#include "buffer.h"

struct Exit : public std::exception { 
    int value;
    Exit(int value) : value(value) {}
};

class Command {
    public:
        virtual void run(CommandArgs) {}
        virtual void help() {}
};


class Quit : public Command {
    public:
        void run(CommandArgs _) {
            throw Exit(0);
        }
        void help() {
            std::cout << "\tq[uit] - Quits lie.\n";
        }
};

class Help : public Command {
    private:
        std::map<std::string, Command*>& commands;
        std::map<std::string, std::string> commands_aliases;
    public:
        Help(std::map<std::string, Command*>& commands, std::map<std::string, std::string>& commands_aliases)
            : commands(commands), commands_aliases(commands_aliases) {}

        void run(CommandArgs args) {
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

        void help() {
            std::cout << "\th[elp] (command) [commands...] - Prints help for specified commands.\n";
        }
};
class Print : public Command {
    private:
        Buffer* buffer;
    public:
        Print(Buffer* buffer) : buffer(buffer) {}
        void run(CommandArgs args) {
            for (std::string& line: buffer->get_lines()) {
                std::cout << line << '\n';
            }
        }
        void help() {}
};

class Open : public Command {
    private:
        Buffer* buffer;
    public:
        Open(Buffer* buffer) : buffer(buffer) {}

        void run(CommandArgs args) {
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
};


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
