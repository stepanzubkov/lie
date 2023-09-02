// Validate count of positional and keyword args.
#include <string>
#include "../parse.h"
#include "../errors.h"
#include "validation_result.h"
#include "../datastructures/range.h"

ValidationResult<CommandArgs> validate_args_count(CommandArgs args, Range pos_args_range, Range keyword_args_range) {
    std::string error_message = "";
    if (!pos_args_range.contains(args.pos_args.size())) {
        std::string args_count = std::to_string(args.pos_args.size());
        std::string args_range = "from " + std::to_string(pos_args_range.start) + " to " + std::to_string(pos_args_range.stop);
        error_message = "expected " + args_range + " positonal arguments, got " + args_count + ".";
    }
    else if (!keyword_args_range.contains(args.keyword_args.size())) {
        std::string args_count = std::to_string(args.keyword_args.size());
        std::string args_range = "from " + std::to_string(keyword_args_range.start) + " to " + std::to_string(keyword_args_range.stop);
        error_message = "expected " + args_range + " keyword arguments, got " + args_count + ".";
    }
    ValidationResult<CommandArgs> result = {error_message.size() == 0, args, error_message};
    return result;
}
