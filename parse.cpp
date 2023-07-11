#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <sstream>

struct CommandArgs  {
    std::vector<std::string> pos_args;
    std::map<std::string, std::string> keyword_args;
};


CommandArgs parse_args(std::string input) {
    std::stringstream args_sstream(input);
    std::vector<std::string> pos_args;
    std::map<std::string, std::string> keyword_args;
    while (args_sstream.good()) {
        std::string arg;
        std::getline(args_sstream, arg, ' ');
        if (arg == "")
            continue;
        std::stringstream arg_sstream(arg);
        std::string arg_name;
        std::getline(arg_sstream, arg_name, '=');
        if (arg == arg_name) {
            pos_args.push_back(arg);
        } else {
            std::string arg_value;
            std::getline(arg_sstream, arg_value);
            keyword_args[arg_name] = arg_value;
        }
    }
    CommandArgs command_args = {pos_args, keyword_args};
    return command_args;
}
