
#include <string>
#include "../parse.h"
#include "validation_result.h"

ValidationResult<CommandArgs> validate_args_count(CommandArgs args, unsigned pos_args_limit, unsigned keyword_args_limit);
