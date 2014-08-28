#ifndef UTIL_H
#define UTIL_H

#include <string.h>

#define starts(a, b) !memcmp(a, b, strlen(b))
#define ends(a, b) !memcmp(a + strlen(a) - strlen(b), b, strlen(b))

char* trim(char* string);

char* substr(char* string, int begin, int end);

#endif /* UTIL_H */