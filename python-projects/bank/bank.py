greeting = input("Greeting: ")
greeting = greeting.replace("," , " ")
greeting = greeting.split()

if greeting[0].lower() == "hello":
    print("$0")
elif greeting[0][0].lower() == "h":
    print("$20")
else:
    print("$100")

