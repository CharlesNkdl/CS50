# TODO
from cs50 import get_int, get_string
import sys
while True:
    input = get_string("Number : ")
    if len(input) > 12 and len(input) < 17:
        break
    else:
        print("INVALID")
        sys.exit(1)
longueur = len(input)
total1 = 0
total2 = 0

for i in range(longueur-2, -1, -2):
    mult = int(input[i]) * 2
    mults = str(mult)
    if len(mults) == 2:
        multb = int(mults[1])
        mult = int(mults[0])
        total1 += multb + mult
    else:
        total1 += mult

for j in range(longueur-1, -1, -2):
    total2 += int(input[j])

check = total1 + total2
if (check % 10) != 0:
    print("INVALID")
    sys.exit(1)


begin = int(input[:2])
begin1 = int(input[0])
if begin == 34 or begin == 37:
    print("AMEX")
elif begin == 51 or begin == 52 or begin == 53 or begin == 54 or begin == 55:
    print("MASTERCARD")
elif begin1 == 4:
    print("VISA")
else:
    print("INVALID")
    sys.exit(1)