import sys
import math
import bisect
import heapq
from collections import deque, defaultdict, Counter

r = int(input())
if (r >= 1 and r <= 99):
	print(100 - r)
elif (r >= 100 and r <= 199):
	print(200 - r)
elif (r >= 200 and r <= 299):
	print(300 - r)
