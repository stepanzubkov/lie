/*
    Command that saves buffer to file.
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

#include "commands.h"
#include "../buffer.h"
#include "../validators/validation_result.h"
#include "../validators/validate_args_count.h"
#include "../datastructures/range.h"
#include "../errors.h"


Save::Save(Buffer* buffer) : buffer(buffer) {}

void Save::run(CommandArgs args) {
    ValidationResult<CommandArgs> validated_args = validate_args_count(args, Range(0, 1), Range(0));
    if (!validated_args.success) {
        print_error(validated_args.error_message, "save");
        return;
    }

    if (args.pos_args.size() == 0) {
        if (buffer->get_filename() == "") {
            print_error("specify filename for unnamed buffer", "save");
            return;
        }
    } else {
        buffer->set_filename(args.pos_args[0]);
    }
    buffer->write();

}

void Save::help() {}
