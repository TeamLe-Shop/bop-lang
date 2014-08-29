#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "label.h"
#include "opcodes.h"

#define LINE_SIZE 100

void do_print(char* line, int line_num, FILE* output);

void read(FILE* input, FILE* output, int ln);

void put(char c, FILE* output);

int bytes_written = 0;

int main(int argc, char* argv[])
{
	if (argc < 3) {
	    printf("Usage: bopc <input> <output>\n");
	    exit(1);
	}

    /* Files to read & write to */
    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "w");

    /* Current line */
    int line_number = 1;

    read(input, output, line_number);

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
                case 'n': put('\n', output); break;
                case 't': put('\t', output); break;
                case 'r': put('\r', output); break;
                case 'a': put('\a', output); break;
                case '\\': put('\\', output); break;
                default:
                    printf("Error on Line %d: Unsupported escape character (\\%c)",
                           line_num, *(c+1));
                }
                i++;
            } else {
                put(*c, output);
            }
        }
    }
    put('\0', output);
}

void read(FILE* input, FILE* output, int line_number)
{
    Label labels[5];
    size_t label_count;

    char* line = malloc(LINE_SIZE);
    while (fgets(line, LINE_SIZE, input)) {
        line[strlen(line)] = 0;
        line = trim(line);

        if (ends(line, ":")) {
            labels[label_count] = Label_New(substr(line, 0, 1), 0);
            printf("(LABEL) %s at pos %zu\n",
                    labels[label_count].name,
                    labels[label_count].position);
        } else {
            if (starts(line, "print")) {
                put(OP_PRINT, output);
                do_print(trim(line + 6), line_number, output);
            } else if (starts(line, "goto")) { // The most fun part of bop!
                put(OP_GOTO, output);
                line = trim(line + 5);
                put((char) find_label(labels, line).position - bytes_written,
                     output);
            }
        }
        line_number++;
    }
}

void put(char c, FILE* output)
{
    putc(c, output);
    bytes_written++;
}
