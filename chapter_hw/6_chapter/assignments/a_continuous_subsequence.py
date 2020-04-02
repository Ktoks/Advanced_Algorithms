
nums = [5,15,-30,10,-5,40,10]


def max_sum_contiguous(nums):
	newlist = [0] * len(nums)
	for i in range(1, len(nums)):
		newlist[i] = max(newlist[i-1] + nums[i], nums[i])
	return max(newlist)

print(max_sum_contiguous(nums))