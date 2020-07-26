from cs50 import get_string

# counters for letters, sentences, and words
letters = 0
sentences = 0
words = 1

# get user input
text = get_string("Text: ")

# count letters
for x in text:
    if (ord(x) >= 65 and ord(x)) or (ord(x) >= 97 and ord(x) <= 122):
        letters += 1

# count words
for x in text:
    if ord(x) == 32:
        words += 1

# count sentences
for x in text:
    if ord(x) == 33 or ord(x) == 46 or ord(x) == 63:
        sentences += 1

# calculate and print grade level
L = letters * 100 / words
S = sentences * 100 / words
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")