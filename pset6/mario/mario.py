from cs50 import get_int

# Check if height is valid number
while(True):
    height = get_int("Height: ")
    if height <= 8 and height >= 1:
        break

# Create pyramid
for i in range(height - 1, -1, -1):
    for j in range(0, i):
        print(" ", end = "")
    for k in range(0, height - i):
        print("#", end = "")
    print("  ", end = "")
    for k in range(0, height - i):
        print("#", end = "")
    print("")

