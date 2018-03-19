## DAY2 ADVENT OF CODE 2017, PART 1.
## IN PYTHON.

from nltk import word_tokenize

## open file, split into line
FILE = open("puzzle.txt","r")
FILEX = FILE.read().splitlines()

## prepater for iteration, counting and calculating
ROW_COUNT, MAX, MIN, SUM, LINES = 0, 0, 0, 0, 0

## calculate the amount of lines in the file
for line in FILEX:
    LINES += 1

while ROW_COUNT < LINES:

    ## divide row in substrings
    TEMP = word_tokenize(FILEX[ROW_COUNT])

    ## iterate over each substring in row
    for string in TEMP:

        ## read substring as an integer value
        string = int(string)

        ## if the intiger value is bigger than any number before, make this the biggest
        if string > MAX:
            MAX = string

        ## if the intiger value is smaller than any number before, make this the smallest
        if MIN == 0:
            MIN = string
        elif string < MIN:
            MIN = string

    ## update row count
    ROW_COUNT += 1

    ## calculate distance between max and min
    SUM += (MAX - MIN)

    ## reset max/min to zero
    MAX = 0
    MIN = 0

print("The result is " + str(int(SUM)) + ".")
