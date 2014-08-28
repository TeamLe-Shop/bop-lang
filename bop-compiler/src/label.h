#ifndef LABEL_H
#define LABEL_H

#include <stdlib.h>

struct label {
    size_t position;
    char* name;
};

typedef struct label Label;

Label* Label_New(char* name, size_t pos);

Label* find_label(Label** list, char* name);

#endif  /* LABEL_H */