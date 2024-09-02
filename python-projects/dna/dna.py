import csv
import sys


def main():
    # TODO: Check for command-line usage

    # check if the command-line have 3 arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # TODO: Read database file into a variable

    subsequence = []

    dataBase = []

    # open the data base file and create a reader for the file
    with open(sys.argv[1], newline="") as dataBaseFile:
        CSVdataBase = csv.DictReader(dataBaseFile)

        # add the the data read to the memory
        for row in CSVdataBase:
            dataBase.append(row)

    STRSubsequence(dataBase, subsequence)

    # TODO: Read DNA sequence file into a variable

    # open the DNA sequence file and read the fist line
    with open(sys.argv[2]) as DNASequenceFile:
        DNASequence = DNASequenceFile.readline()

    # TODO: Find longest match of each STR in DNA sequence

    longest = {}

    # pass for every STRs in data base and see what is the longest sequence of that STR in the DNA sequence
    for STR in subsequence:
        longest[STR] = longest_match(DNASequence, STR)

    # TODO: Check database for matching profiles

    # show the owner of the DNA sequence
    DNASequenceOwner(dataBase, subsequence, longest)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


def DNASequenceOwner(dataBase, subsequence, longest):
    # pass for every person in the data base
    for row in dataBase:
        differentSTR = 0

        # pass for the STRs of that penson and see if is egual of the DNA section
        for STR in subsequence:
            if int(longest[STR]) != int(row[STR]):
                differentSTR += 1
                break

        # if is egual output the name of that person
        if differentSTR == 0:
            print(row["name"])
            return

    # if that person ins't in the data base
    print("No match")

    return


def STRSubsequence(dataBase, subsequence):
    # pass for the fist person and save the keys of that person
    for row in dataBase:
        for STR in row:
            # if the key is diferent of 'name' save as a STR to look
            if STR != "name":
                subsequence.append(STR)
        break

    return


main()
