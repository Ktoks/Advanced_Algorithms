
def lcs(first, second):
	longest = []
	longest_num = 0
	# initialization
	for y in range(len(first)):
		longest.append([0])
		for x in range(len(second)):
			if x == 0:
				continue
			else:
				longest[y].append(0)
	for i in range(len(first)):
		for j in range(len(second)):
			if first[i] == second[j]:
				longest[i][j] = max(longest[i-1][j], longest[i][j-1], longest[i-1][j-1] + 1)
				longest_num = max(longest[i][j], longest_num)
	return longest_num

print(lcs("breakfast", "i need a break")) #9 * 14
print(lcs("i need a break", "breakfast")) #14 * 9
print(lcs("breakfast", "im about to break... fast")) #9 * 25
print(lcs("im about to break... fast", "breakfast")) #25 * 9
print((lcs("crazytrain", "train that is crazy")))
print((lcs("train that is crazy", "crazytrain")))
