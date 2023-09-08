/*
    Command that quit editor.
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

#include <iostream>
#include "commands.h"
#include "../parse.h"
#include "../exit.h"
#include "../validators/validation_result.h"
#include "../validators/validate_args_count.h"
#include "../datastructures/range.h"
#include "../errors.h"

void Quit::run(CommandArgs args) {
    ValidationResult<CommandArgs> validated_args = validate_args_count(args, Range(0), Range(0));
    if (!validated_args.success) {
        print_error(validated_args.error_message, "quit");
        return;
    }

    throw Exit(0);
}

void Quit::help() {
    std::cout << "q[uit] - Quits editor.\n";
}
