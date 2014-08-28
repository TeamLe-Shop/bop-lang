#include "util.h"
#include "opcodes.h"
#include <stdio.h>

char* trim(char* string)
{
    char* end;

    while (isspace(*string)) string++;
    end = string + strlen(string) - 1;
    while (isspace(*end)) {
        *end = 0;
        end--;
    }
    return string;
}
