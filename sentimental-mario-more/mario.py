# TODO
height = 0

while height < 1 or height > 8:
    height = int(input("height:"))


for i in range(height):
    for j in range(height - i + 1):
        print(" ", end="")
    for j in range(i + 1):
        print("#", end="")
    print("  ", end="")
    for j in range(i + 1):
        print("#", end="")
    print()
