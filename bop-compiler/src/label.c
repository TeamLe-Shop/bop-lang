#include "label.h"

#include <string.h>
#include <stdio.h>

Label* Label_New(char* name, size_t pos)
{
    Label* new = malloc(sizeof(Label));
    new->name = malloc(strlen(name));
    strcpy(new->name, name);
    new->position = pos;
    return new;
}

Label* find_label(Label** list, char* name)
{
    int i;
    Label* label;
    for (i = 0; i < sizeof(list) / sizeof (Label*); i++) {
        label = list[i];
        if (!strcmp(label->name, name)) {
            return label;
        }
    }
    return NULL;
}