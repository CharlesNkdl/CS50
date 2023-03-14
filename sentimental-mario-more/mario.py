# TODO
from cs50 import get_int

while True:
    N = get_int("height: ")
    if N > 0 and N < 9:
        break

i = 1
while (i < N+1):
    for l in range(N-i):
        print(" ", end="")
    for p in range(i):
        print("#", end="")
    print("  ", end="")
    for q in range(i):
        print("#", end="")
    print("")
    i += 1