from pyfiglet import Figlet
import sys

# if receive no extar command line
if len(sys.argv) == 1:
    # ask for the text to be pass for figled
    text = input("Input: ")
    # pick a random font
    f = Figlet()
    # output the text in that font
    print(f.renderText(text))

# if receive 3 valid extra command lines
elif len(sys.argv) == 3 and sys.argv[1] == "-f" or sys.argv[1] == "--font":
    # see if the font ins valid
    try:
        # the command line chose the font to be used
        f = Figlet(font=sys.argv[2])
    # if ins't stop the code
    except:
        print("Invalid usage")
        sys.exit(1)

    #if is print the chosen font
    text = input("Input: ")
    print(f.renderText(text))

# if receive extra command lines but they are not valid
else:
    print("Invalid usage")
    sys.exit(1)


