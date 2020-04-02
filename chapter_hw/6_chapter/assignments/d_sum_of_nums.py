

def sum(nums, total):
	some = []
	# initialization
	for y in range(len(nums)+1):
		some.append([True])
		for x in range(total+1):
			if x == 0:
				continue
			else:
				some[y].append(False)
	for i in range(len(nums)):
		for j in range(total + 1):
			# print(some[i][j])
			some[i][j] = some[i - 1][j] or some[i - 1][j - nums[i]]
	return some[i][j]
print(sum((1,2,3,4,5,6), 20))
print(sum((1,2,3,4,5,6), 21))
print(sum((1,2,3,4,5,6), 22))
