struct CommandArgs {
    std::vector<std::string> pos_args;
    std::map<std::string, std::string> keyword_args;
};

CommandArgs parse_args(std::string);
