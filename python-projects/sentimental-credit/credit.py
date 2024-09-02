# TODO

# pick the input of the card number
cardNumber = input("Number:")

# create a array and put the card number in (as int)
cardNumbers = []
for number in cardNumber:
    cardNumbers.append(int(number))

# see if is a valid Card Number
validation = 0

#reverse the list
cardNumbers.reverse()

for index in range(len(cardNumbers)):
    if (index) % 2 != 0:
        if (cardNumbers[index] * 2) > 9:
            validation += int(cardNumbers[index] * 2 / 10)
            validation += int(cardNumbers[index] * 2 % 10)
        else:
            validation += cardNumbers[index] * 2
    else:
        validation += cardNumbers[index]

#reverse the list
cardNumbers.reverse()

if len(cardNumbers) != 15 and len(cardNumbers) != 16 and len(cardNumbers) != 13:
    print('INVALID')
elif validation % 10 == 0:

    cardBank = cardNumbers[0] * 10 + cardNumbers[1]
    if cardBank == 34 or cardBank == 37:
        print('AMEX')
    elif cardBank > 50 and cardBank < 56:
        print('MASTERCARD')
    elif int(cardBank / 10) == 4:
        print('VISA')
    else:
        print('INVALID')
else:
    print('INVALID')
