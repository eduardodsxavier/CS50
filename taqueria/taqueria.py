def main():
    totalPrice = 0

    while True:
        try:
            item = input("item: ")
        except:
            break
        if item == "":
            break
        elif itemInMenu(item):
            totalPrice += prices[item.lower()]
            print(f"Total: ${ftotalPrice}")


def itemInMenu(item):
    for key in prices.keys():
        if item.lower() == key.lower():
            return True
    return False

prices = {
    "baja taco": 4.25,
    "burrito": 7.50,
    "bowl": 8.50,
    "nachos": 11.00,
    "quesadilla": 8.50,
    "super burrito": 8.50,
    "super quesadilla": 9.50,
    "taco": 3.00,
    "tortilla salad": 8.00
}

main()
