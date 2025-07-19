import csv
import sys


def main():
    # Check for proper command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    with open(sys.argv[1]) as csvfile:
        reader = csv.DictReader(csvfile)
        database = list(reader)
        str_sequences = reader.fieldnames[1:]  # skip 'name'

    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as seqfile:
        dna = seqfile.read()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for STR in str_sequences:
        str_counts[STR] = longest_match(dna, STR)

    # Check database for matching profiles
    for person in database:
        match = all(int(person[STR]) == str_counts[STR] for STR in str_sequences)
        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while sequence[i + count * subsequence_length : i + (count + 1) * subsequence_length] == subsequence:
            count += 1
        longest_run = max(longest_run, count)

    return longest_run


main()
