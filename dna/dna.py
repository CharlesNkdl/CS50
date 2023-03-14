import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("more command line argument")
        sys.exit(1)
    # TODO: Read database file into a variable
# read the csv file = argv[1]
# avec nom , agat ,aatg , tatc
# puis read
    databases = sys.argv[1]
    with open(databases) as database:
        databaseread = csv.DictReader(database)
        datas = list(databaseread)

    # TODO: Read DNA sequence file into a variable
# read le dna seq = argv[2]
# read into its memory
    sequence = sys.argv[2]
    with open(sequence) as sequ:
        sequences = sequ.read()
    # TODO: Find longest match of each STR in DNA sequence
# voir quel sont les plus longues chaine = aide avec longest_match
    longue = {}
    for i in datas[0]:
        longue[i] = (longest_match(sequences, i))

    # TODO: Check database for matching profiles
# puis check avec la database et print le nom du gars ou sinon rien
    count = 1
    profiles = "No match"
    for i in range(len(datas)):
        for j in longue:
            if str(longue[j]) == datas[i][j]:
                count += 1
        if count == len(longue):
            profiles = datas[i]["name"]
            break
        else:
            count = 1
    print(profiles)
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


main()