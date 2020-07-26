from sys import argv, exit
import csv

# Check if command line has 3 arguments
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# Read dna sequence file into string called dna
sequence = open(argv[2],"r")
dna = sequence.read()

# Open csv file and read contents into a list
file = open(argv[1],"r")
reader = list(csv.reader(file))
reader[0].remove("name")
STR = reader[0]

# Iterate through each STR and add matches to list
matches = []
for j in range(len(STR)):
    maxc = 0
    count = 0
    previous = 0
    i = 0
    # Iterate through each character in sequence
    while i < len(dna):
        i = dna.find(STR[j], i)
        # If STR never matches in dna sequence, break and set max to 0
        if i == -1:
            count = 0
            break
        # First STR match found
        elif (i != -1) and (previous == 0):
            count += 1
            previous = i
            if count > maxc:
                maxc = count
        # Successive STR found
        elif (i != -1) and (i - len(STR[j]) == previous):
            count += 1
            previous = i
            if count > maxc:
                maxc = count
        # STR is found but not right after previous
        elif (i != -1) and (i - len(STR[j]) != previous):
            count = 1
            previous = i
            if count > maxc:
                maxc = count
        i += 1
    # Add max values to matches list
    matches.append(maxc)

# Check matches list with each individual's database values
matches = list(map(str, matches))
for row in reader:
    if row[1:] == matches:
        print(f"{row[0]}")
        break
    elif row == reader[-1]:
        print("No match")