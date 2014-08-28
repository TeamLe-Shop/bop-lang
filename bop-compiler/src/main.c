#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "label.h"
#include "opcodes.h"

#define LINE_SIZE 100

void do_print(char* line, int line_num, FILE* output);

int main(int argc, char* argv[])
{
	if (argc < 3) {
	    printf("Usage: bopc <input> <output>\n");
	    exit(1);
	}

    /* Files to read & write to */
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    /* Hur labels? */
    struct Label* labels;
    size_t label_count;

    /* Current line */
    char* line = malloc(LINE_SIZE);
    int line_number = 1;

    while (fgets(line, LINE_SIZE, input)) {
        line[strlen(line)] = 0;
        line = trim(line);

        if (ends(line, ":")) {
            printf("(LABEL) %s\n", line);
        } else {
            if (starts(line, "print")) {
                putc(OP_PRINT, output);
                do_print(trim(line + 6), line_number, output);
            }
        }
        line_number++;
    }
    return 0;
}

void do_print(char* line, int line_num, FILE* output)
{
    int i;
    char mode = 0;
    for (i = 0; i < strlen(line); i++) {
        char* c = (line + i);
        if (*c == '"') { mode = !mode; continue; }
        if (mode) {
            if (*c == '\\') {
                switch (*(c+1)) {
                case 'n': putc('\n', output); break;
                case 't': putc('\t', output); break;
                case 'r': putc('\r', output); break;
                case 'a': putc('\a', output); break;
                case '\\': putc('\\', output); break;
                default:
                    printf("Error on Line %d: Unsupported escape character (\\%c)",
                        line_num, *(c+1));
                }
            } else {
                putc(*c, output);
            }
        }
    }
    putc('\0', output);
}


