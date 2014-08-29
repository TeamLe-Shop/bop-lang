#include "util.h"
#include "opcodes.h"

#include <stdio.h>
#include <stdlib.h>

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

char* substr(char* string, int begin, int end)
{
    char* new_str = malloc(strlen(string + begin - end));
    memcpy(new_str, string + begin, strlen(string + begin) - end);
    return new_str;
}