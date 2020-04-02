
def making_change_with_one(coins, goal):
	mlist = [True]
	newcoins = coins[:]
	j = 1
	u = 1
	while j <= goal:
		r = False
		for i in range(len(newcoins)):
			if u >= newcoins[i]:
				# print("you:", u)
				if mlist[u - newcoins[i]]:
					u -= newcoins[i]
					# print("Mlist:",u - newcoins[i])
					r = True
					newcoins[i] = goal + 1
					break
		mlist.append(r)
		j += 1
		u += 1
	return u == 1



print(making_change_with_one([10,5], 12))		#False
print(making_change_with_one([10,5], 9))		#False
print(making_change_with_one([10,5,1], 12))		#False
print(making_change_with_one([10,5,1], 9))		#False
print(making_change_with_one([5,10],50))		#False
print(making_change_with_one([10,5],15))		#True
print(making_change_with_one([10],20))			#False
print(making_change_with_one([10,10,10,1], 31))	#True
