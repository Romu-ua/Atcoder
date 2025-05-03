import sys
import math
import bisect
import heapq
from collections import deque, defaultdict, Counter
import itertools

n, k = map(int, input().split())
s = input()

s = list(s)
# print(list(itertools.permutations(s)))
ln_s = list(itertools.permutations(s))

def is_loate(str):
	for i in range(len(str) // 2):
		if (str[i] != str[-(i+1)]):
			return False
	return True

cnt = 0
for ln in ln_s:
	for start in range(n - k + 1):
		if (is_loate(ln[start:start+k])):
			cnt += 1

print(len(ln_s) - cnt)

