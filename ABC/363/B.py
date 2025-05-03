import sys
import math
import bisect
import heapq
from collections import deque, defaultdict, Counter

n, t, p = map(int, input().split())
l = list(map(int, input().split()))

l.sort()
# print(l)
look = l[len(l) - p]
# print(look)
if (look >= t):
	print(0)
else:
	print(t - look)