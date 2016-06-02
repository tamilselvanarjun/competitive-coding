from decimal import Decimal as decimal
temp = raw_input()
temp = temp.split(" ")
n = int(temp[0])
d = int(temp[1])
buyPrice = 0 
sellPrice=0
increaseRate = decreaseRate = []

i = raw_input().split(" ")
j = raw_input().split(" ")

for x in range(n):
	increaseRate.append(decimal(i[x]))
for x in range(d):
	decreaseRate.append(decimal(j[x]))

increaseRate.sort()
increaseRate.reverse()
decreaseRate.sort()
decreaseRate.reverse()

for x in range(n):
	buyPrice+=increaseRate[x]**(x+1)
for x in range(d):
	pass
	sellPrice+=(1- decreaseRate[x]**(x+1))

buyPrice*=100
sellPrice*=5000
print buyPrice, sellPrice
