## DAY2 ADVENT OF CODE 2017, PART 2.
## IN PYTHON.

from nltk import word_tokenize

## open file, split into line
FILE = open("puzzle.txt","r")
FILEX = FILE.read().splitlines()

## prepater for iteration, counting and calculating
ROW_COUNT, DIVISION, SUM, LINES, index = 0, 0, 0, 0, 0

## calculate the amount of lines in the file
for line in FILEX:
    LINES += 1

while ROW_COUNT < LINES:

    ## divide row in substrings
    TEMP = word_tokenize(FILEX[ROW_COUNT])

    ## iterate over each substring in row
    for substring in TEMP:

        ## read substring as an integer value
        string = int(substring)

        ## compare that substring to other substrings in TEMP
        for rest in TEMP:

            ## read other substrings as integer values
            foo = int(rest)

            ## if a substring is bigger than the other
            if string > foo:

                ## if the result of the division is an even number, add it to sum
                if (string / foo).is_integer():
                    SUM += string / foo
                    index + 1
                    break

    ## update row count
    ROW_COUNT += 1

print("The result is " + str(int(SUM)) + ".")


