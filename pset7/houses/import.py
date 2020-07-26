from sys import argv, exit
from cs50 import SQL
import csv

# Check if command line has 2 arguments
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

# Create variable for database functions
db = SQL("sqlite:///students.db")

# Input name, house, and birth from csv into students database
with open(argv[1], "r") as input:
    reader = csv.DictReader(input, delimiter = ",")
    for row in reader:
        separated = row["name"].split()
        # If the student has a middle name
        if len(separated) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                separated[0], separated[1], separated[2], row["house"], row["birth"])
        # If the student does not have a middle name
        else:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                separated[0], None, separated[1], row["house"], row["birth"])