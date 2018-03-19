// DAY1 ADVENT OF CODE 2017, PART 2.
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
    char buffer[2052];

    // prepare for counting
    int sum = 0;
    int i;
    int c;


    // read into file, 2052 bytes
    fread (buffer, 2052, 1, file);

    // iterate over each int in file
    for (i = 0; i < 2052; i++)
    {

        // if it is below 1026 (half of input), add 1026
        if (i <= 1025)
        {
            c = i + 1026;
        }

        // if it is above 1026 (half of input), subtract 1026
        else c = (i - 1026);

        // if the character found equals the character 1026 places further down the road, add it to sum
        if ((buffer[i] % 48) == (buffer[c] % 48))
        {
            sum += ((int) buffer[i] % 48);
        }
    }

   printf ("The answer is: %i.\n", sum);

    fclose(file);
}
