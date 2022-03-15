import math

val = [0.25,0.25,0.25,0.125,0.125]
longs = [2,2,2,3,3]

HS = 0
longmoy = 0

for k in range(len(val)):
	HS += val[k]*math.log2(val[k])
	longmoy += val[k] * longs[k]

print(-HS)
print(longmoy)

