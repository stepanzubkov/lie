/*
    Command args parser.
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
