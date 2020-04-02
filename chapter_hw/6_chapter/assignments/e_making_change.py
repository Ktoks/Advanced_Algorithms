
def making_change(denominations,goal):
	mlist = [0] * len(denominations)

	for i in range(len(denominations)):
		if i == 0:
			mlist[i] = goal % denominations[i]
			print(mlist[i])
		else:
			mlist[i] = mlist[i - 1] % denominations[i]
			# print(mlist[i])
	return mlist[i] == 0

def making_change_dynamic(coins, goal):
	mlist = [True]
	for u in range(1,goal + 1):
		r = False
		for i in range(len(coins)):
			if u >= coins[i]:
				if mlist[u - coins[i]]:
					r = True
		mlist.append(r)
	return mlist[u]

		

print(making_change_dynamic([10,5], 12))		#False
print(making_change_dynamic([10,5], 9))			#False
print(making_change_dynamic([10,5,1], 12))		#True
print(making_change_dynamic([10,5,1], 9))		#True
print(making_change_dynamic([5,10],500))		#True
print(making_change_dynamic([10,10],20))		#True
print(making_change_dynamic([10],20))			#True

