s = input()

ref = "abcdefghijklmnopqrstuvwxyz"
for c in ref:
    if c not in s:
        print(c)
        break