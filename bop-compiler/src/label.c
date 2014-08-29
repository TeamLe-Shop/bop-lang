#include "label.h"

#include <string.h>
#include <stdio.h>

Label Label_New(char* name, size_t pos)
{
    Label new = {pos, name};
    return new;
}

Label find_label(Label* list, char* name)
{
    int i;
    // Default label? dunno
    Label label = {0, "begin"};
    for (i = 0; i < 5; i++) {
        label = list[i];
        if (strcmp(label.name, name) == 0) {
            return label;
        }
    }
    return label;
}