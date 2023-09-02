// GoTo command class. Sets buffer's current line.

#include <cstddef>
#include <iostream>
#include "commands.h"
#include "../buffer.h"
#include "../parse.h"
#include "../validators/validate_int.h"
#include "../validators/validation_result.h"
#include "../validators/validate_args_count.h"
#include "../errors.h"


GoTo::GoTo(Buffer* buffer) : buffer(buffer) {}

void GoTo::run(CommandArgs args) {
    ValidationResult<CommandArgs> validated_args = validate_args_count(args, Range(1), Range(0));
    if (!validated_args.success) {
        print_error(validated_args.error_message, "goto");
        return;
    }
    std::size_t line;
    if (args.pos_args[0] == "-") {
        line = buffer->get_prev_current_line() + 1;
    } else {
        std::size_t max_line = buffer->get_lines()->size();
        ValidationResult<std::size_t> result = validate_line_number(args.pos_args[0], max_line);
        if (!result.success) {
            print_error(result.error_message, "goto");
            return;
        }
        line = result.value;
    }
    buffer->set_current_line(line - 1);
}

void GoTo::help() {
    std::cout << "g[oto] (line) - Sets current line.\n";
    std::cout << "g[oto] '-' - Sets current line to previous current line.\n";
}
