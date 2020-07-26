from cs50 import get_int, get_string

# list variables used
count = 0
evens = 0
odds = 0
dig1 = 0
dig2 = 0
first2 = 0

# get credit card number
num = get_int("number: ")

# calculate card value
while int(num) > 0:
    dig2 = int(dig1)
    dig1 = int(num % 10)
    if int(count) % 2 == 0:
        odds += int(dig1)
    else:
        evens = int(int(evens) + (int(dig1) * 2 / 10) + (int(dig1) * 2 % 10))
    count += 1
    num = int(num / 10)

first2 = int(dig1) * 10 + int(dig2)

# check if card is valid
if (evens + odds) % 10 == 0:
    valid = True
else:
    valid = False

# return corresponding card type
if dig1 == 4 and count >= 13 and count <= 16 and valid:
    print("VISA")
elif first2 >= 51 and first2 <= 55 and count == 16 and valid:
    print("MASTERCARD")
elif (first2 == 34 and valid) or (first2 == 37 and valid):
    print("AMEX")
else:
    print("INVALID")