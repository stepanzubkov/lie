/*
    Contains function that validates count of command arguments.
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
