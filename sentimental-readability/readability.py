from cs50 import get_string

input = get_string("Text : ")

l = 0
w = 1
s = 0
for i in range(len(input)):
    if input[i] == " ":
        w += 1
    elif input[i] == "." or input[i] == "!" or input[i] == "?":
        s += 1
    elif input[i].isalpha():
        l += 1
lw = l / w * 100
se = s / w * 100
cli = 0.0588 * lw - 0.296 * se - 15.8
# print(cli)
rcli = round(cli)
# print(rcli)
if rcli < 1:
    print("Before Grade 1")
elif rcli > 16:
    print("Grade 16+")
else:
    print("Grade ", rcli)