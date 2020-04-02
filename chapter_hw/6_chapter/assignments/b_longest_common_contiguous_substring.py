

def lccs(first, second):
	count = 0
	count_list = []
	first_length = len(first)
	second_length = len(second)
	i = 0
	while i < first_length:
		for j in range(second_length):
			if first[i] == second[j] and (i == first_length - 1 or j == second_length - 1):
				count_list.append(first[i - count:i + 1])
				count = 0
				break
			elif first[i] == second[j]:
				count += 1
				i += 1
			elif count > 0 and first[i - 1] == second[j - 1]:
				count_list.append(first[i - count:i])
				count = 0
			else:
				count = 0
			if i >= first_length:
				return count_list
		i += 1
			

	return (count_list)

print(len(max(lccs("breakfast", "fasting"))))
print(len(max(lccs("fasted", "fasting"))))
print(len(max(lccs("fasting", "breakfast"))))

X = 0
Y = 0
m = 0
n = 0
LCSuff = [[0 for k in range(n+1)] for l in range(m+1)]
for i in range(m + 1): 
	for j in range(n + 1): 
		if (i == 0 or j == 0): 
			LCSuff[i][j] = 0
		elif (X[i-1] == Y[j-1]): 
			LCSuff[i][j] = LCSuff[i-1][j-1] + 1
			result = max(result, LCSuff[i][j]) 
		else: 
			LCSuff[i][j] = 0
