from sys import argv, exit
from cs50 import SQL
import csv

# Check if command line has 2 arguments
if len(argv) != 2:y
    if argv[1] != "Gryffindor" or argv[1] != "Slytherin" or argv[1] != "Hufflepuff" or argv[1] != "Ravenclaw":
        print("Usage: python roster.py house")
        exit(1)

# Set format for ordered list of students selected
db = SQL("sqlite:///students.db")
students = db.execute("SELECT DISTINCT * FROM students WHERE house = (?) ORDER BY last, first", argv[1])

# Print full name and birth, skipping middle name if not present
for row in students:
    if row["middle"] == None:
        print(f"{row['first']} {row['last']}, {row['birth']}")
    else:
        print(f"{row['first']} {row['middle']} {row['last']}, {row['birth']}")