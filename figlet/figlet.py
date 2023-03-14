import sys
from pyfiglet import Figlet

if len(sys.argv) != [0,2]:
    print("Invalid usage")
    sys.exit(1)


figlet = Figlet()


if len(sys.argv) == 0 :
    answer = input("input : ")
    font = figlet.getFonts(random.choice)
    print(figlet.renderText(answer))


if len(sys.argv) == 2 and sys.argv[1] == ["-f","--font"]:
    figlet.setFont(font=sys.argv[2])
    answer = input("Input : ")
    print(figlet.renderText(answer))
