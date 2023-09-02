// Validate count of positional and keyword args.
#include <string>
#include "../parse.h"
#include "../errors.h"
#include "validation_result.h"

ValidationResult<CommandArgs> validate_args_count(CommandArgs args, unsigned pos_args_limit, unsigned keyword_args_limit) {
    std::string error_message = "";
    if (args.pos_args.size() > pos_args_limit) {
        std::string args_count = std::to_string(args.pos_args.size());
        std::string args_limit = std::to_string(pos_args_limit);
        bool is_plural = pos_args_limit != 1;
        error_message = "expected " + args_limit + " positonal argument" + (is_plural ? "s" : "") + ", got " + args_count;
    }
    else if (args.keyword_args.size() > keyword_args_limit) {
        std::string args_count = std::to_string(args.keyword_args.size());
        std::string args_limit = std::to_string(keyword_args_limit);
        bool is_plural = pos_args_limit != 1;
        error_message = "expected " + args_limit + " keyword argument" + (is_plural ? "s" : "") + ", got " + args_count;
    }
    ValidationResult<CommandArgs> result = {error_message.size() == 0, args, error_message};
    return result;
}
