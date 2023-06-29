#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

struct Exit : public std::exception { 
    int value;
    Exit(int value) : value(value) {}
};

class Command {
    public:
        virtual int run(std::vector<std::string> args) { return 0; }
        virtual void help() {}
};


class Quit : public Command {
    public:
        int run(std::vector<std::string> args) {
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

        int run(std::vector<std::string> args) {
            for (auto arg: args) {
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
            return 0;
        }

        void help() {
            std::cout << "\th[elp] (command) [commands...] - Prints help for specified commands.\n";
        }
};


int main() {
    std::cout << "Lie - LIne Editor or Lie Is Editor\n";
    std::string command;
    std::vector<std::string> args;
    std::map<std::string, std::string> commands_aliases{
        {"q", "quit"},
        {"h", "help"},
    };
    std::map<std::string, Command*> commands{
        {"quit", new Quit()},
    };
    commands["help"] = new Help(commands, commands_aliases);
    while (true) {
        std::cout << "> ";
        std::cin >> command;
        std::string args_str;
        std::getline(std::cin, args_str);
        std::stringstream args_sstream(args_str);
        while(args_sstream.good()) {
            std::string arg;
            std::getline(args_sstream, arg, ' ');
            if (arg != "") {
                args.push_back(arg);
            }
        }

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
        args.clear();
    }
}
