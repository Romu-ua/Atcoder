from itertools import permutations

n, k = map(int, input().split())
s = input()

def is_palindrome(sub):
    for i in range(len(sub) // 2):
        if sub[i] != sub[-(i+1)]:
            return False
    return True

valid_count = 0

for perm in set(permutations(s)):
    has_palindrome = False
    for i in range(n - k + 1):
        if is_palindrome(perm[i:i+k]):
            has_palindrome = True
            break
    if not has_palindrome:
        valid_count += 1

print(valid_count)
