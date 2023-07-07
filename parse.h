// Command args parser.
#include <vector>
#include <map>
#include <string>

#if !defined(PARSE)
#define PARSE

struct CommandArgs {
    std::vector<std::string> pos_args;
    std::map<std::string, std::string> keyword_args;
};

#endif

CommandArgs parse_args(std::string);
