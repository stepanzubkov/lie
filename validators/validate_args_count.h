
#include <string>
#include "../parse.h"
#include "validation_result.h"
#include "../datastructures/range.h"

ValidationResult<CommandArgs> validate_args_count(CommandArgs args, Range pos_args_range, Range keywords_args_range);
