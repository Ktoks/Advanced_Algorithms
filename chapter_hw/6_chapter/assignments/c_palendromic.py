import sys

def palendromic(somestring):
	largest_palendrome = 1
	string_len = len(somestring)
	table = [[0 for x in range(string_len)] \
				for y in range(string_len)]
	i = 0
	while i < string_len:
		table[i][i] = True
		i = i + 1
	j = 0
	start = 0
	while j < string_len - 1:
		if somestring[j] == somestring[j + 1]:
			table[j][j + 1] = True
			start = j
			largest_palendrome = 2
		j += 1
	k = 3
	while k <= string_len:
		l = 0
		while l < (string_len - k + 1):
			m = l + k - 1
			if table[l + 1][m - 1] and somestring[l] == somestring[m]:
				table[l][m] = True
				if k > largest_palendrome:
					start = l
					largest_palendrome = k
			l += 1
		k += 1
	return largest_palendrome
print(palendromic("racecar"))