// DAY1 ADVENT OF CODE 2017, PART 1.
// IN C.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // choose puzzle file, ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: enter input\n");
        return 1;
    }

    // open file for reading
    char *infile = argv[1];
    FILE *file;
    file = fopen(infile, "r");

    // open buffer of reading
    char buffer[2053];

    // prepare for counting
    int sum = 0;
    int i;

    // read into file, 2052 bytes
    fread (buffer, 2052, 1, file);

    // iterate over each int in file
    for (i = 0; i < 2052; i++)
    {

        // if it is the last int in file, compare to the first, add to sum if they have the same value
        if (i == 2051)
        {
            if (buffer[i] == buffer[0])
            {
                sum += (buffer[i] % 48);
            }
        }

        // else compare to the next int in file, add to sum if they are the same value
        else if (i < 2052)
        {
            if ((buffer[i]) == (buffer[i+1]))
            {
                sum += (buffer[i] % 48);
            }
        }
    }

    printf ("The answer is: %i.\n", sum);

    fclose(file);
}
