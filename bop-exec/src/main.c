#include <stdio.h>
#include <stdlib.h>

#include "opcodes.h"

int main(int argc, char* argv[])
{
	if (argc < 2) {
	    printf("Usage: bop <input>\n");
	    exit(1);
	}

    /* Files to read & write to */
    FILE* input = fopen(argv[1], "r");

    char* c = malloc(1);
    while (fread(c, 1, 1, input)) {
        if (*c == OP_PRINT) {
            fread(c, 1, 1, input);
            while (*c != 0x00) {
                putc(*c, stdout);
                fread(c, 1, 1, input);
            }
        } else if (*c == OP_GOTO) {
            fread(c, 1, 1, input);
            fseek(input, *c, SEEK_CUR);
        }
    }
    return 0;
}
