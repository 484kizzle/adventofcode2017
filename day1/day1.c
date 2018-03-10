#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: enter input\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *file;
    file = fopen(infile, "r");

    char buffer[2052];

    int sum = 0;

    fread (buffer, 2052, 1, file);

    int i;
    int c;

    for (i = 0; i < 2052; i++)
    {
        if (i <= 1025)
        {
            c = i + 1026;
        }

        else c = (i - 1026);

        if ((buffer[i] % 48) == (buffer[c] % 48))
        {
            sum += ((int) buffer[i] % 48);
        }
    }

    printf ("%i", sum);

    fclose(file);
}
