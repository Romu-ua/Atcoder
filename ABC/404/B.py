n = int(input())

s = [list(input()) for _ in range(n)]
t = [list(input()) for _ in range(n)]

# print(s)

def rotate(s):
	new_grid = []
	for i in range(n):
		new_row = []
		for j in range(n):
			val = s[n - j - 1][i]
			new_row.append(val)
		new_grid.append(new_row)
	return new_grid

cnt_0 = 0
cnt_1 = 0
cnt_2 = 0
cnt_3 = 0

rs_1 = rotate(s)
rs_2 = rotate(rotate(s))
rs_3 = rotate(rotate(rotate(s)))

# print(rs_1)

for i in range(n):
	for j in range(n):
		if (s[i][j] == t[i][j] and t[i][j] == '#'):
			cnt_0 += 1

for i in range(n):
	for j in range(n):
		if (rs_1[i][j] == t[i][j] and t[i][j] == '#'):
			cnt_1 += 1

for i in range(n):
	for j in range(n):
		if (rs_2[i][j] == t[i][j] and t[i][j] == '#'):
			cnt_2 += 1

for i in range(n):
	for j in range(n):
		if (rs_3[i][j] == t[i][j] and t[i][j] == '#'):
			cnt_3 += 1

diff = [(cnt_0, 0), (cnt_1 - 1, 1), (cnt_2 - 2, 2), (cnt_3 - 3, 3)]
# print(diff)
diff.sort(reverse=True)

start = diff[0][1]
# print(start)
if start == 0:
	start_s = s
elif start == 1:
	start_s = rs_1
elif start == 2:
	start_s = rs_2
elif start == 3:
	start_s = rs_3

cnt = 0
for i in range(n):
	for j in range(n):
		if (start_s[i][j] != t[i][j]):
			cnt += 1


# print(start_s)
# print(t)
# print(start)
# print(cnt)
print(cnt + start)