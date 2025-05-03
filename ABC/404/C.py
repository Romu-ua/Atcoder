import sys
sys.setrecursionlimit(10**6)
n, m = map(int, input().split())

G = [[] for _ in range(n)]

for _ in range(m):
	u, v = map(int, input().split())
	u -= 1
	v -= 1
	G[u].append(v)
	G[v].append(u)

flag = True
for elm in G:
	if (len(elm) != 2):
		flag = False
		break


visited = [False] * n

def dfs(v, prev):
	visited[v] = True
	for u in G[v]:
		if not visited[u]:
			dfs(u, v)
		elif u != prev:
			continue

start = -1
for i in range(n):
	if G[i]:
		start = i
		break
if start == -1:
	print("No")
	sys.exit()

dfs(start, -1)

if all(visited) and flag:
	print("Yes")
else:
	print("No")