#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc < 3) {
	    printf("Usage: bopc <input> <output>\n");
	    exit(1);
	}

    /* Files to read & write to */
    FILE* input = fopen(argv[1], "r");

    return 0;
}
