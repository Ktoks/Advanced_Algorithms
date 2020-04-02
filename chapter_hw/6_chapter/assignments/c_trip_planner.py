

def planning(destination, hotels, ideal_stop):
	stops = [[0 + (k*(ideal_stop**2) + k*(ideal_stop)**2) + (l*(ideal_stop**2) + l*(ideal_stop)**2) \
				 for k in range(destination // ideal_stop + 1)] for l in range(len(hotels) + 1)]
	dabest = []
	count = 0
	for i in range(1,destination // ideal_stop + 1):
		interval = i*ideal_stop
		try:
			current_goal = dabest[-1] + ideal_stop
		except:
			current_goal = ideal_stop * i
		for j in range(len(hotels)):
			if count == 0 and hotels[j - 1] < interval and hotels[j] >= interval:
				stops[i][j] = min(stops[i-1]) + ((interval - hotels[j])**2)
				dabest.append(hotels[j])
				count += 1
				break
			elif hotels[j - 1] < (current_goal) and hotels[j] >= (current_goal):
				stops[i][j] = min(stops[i-1]) + ((dabest[-1] - hotels[j])**2)
				dabest.append(min(stops[i-1]) + ((dabest[-1] - hotels[j])**2))
				break
	return(dabest)

destination = 1000
hotels = [150, 250, 570, 900, 950, destination]
ideal_stop = 200

print(planning(destination, hotels, ideal_stop))