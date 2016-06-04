from datetime import datetime
fac = [1,1]

number = input()
startTime = datetime.now()
h=2
while(h<=number):
	fac.append(h*fac[h-1])
	h+=1

sum=0
for i in range(number+1):
	if(i==number):
		sum+=2**number
		break
	for j in range(int(number/2)+1):
		if(i+2*j>number):
			break
		elif(i+2*j==number):
			sum+=fac[i+j]/fac[i]/fac[j]*(2**i)
			break

		for k in range(int(number/3)+1):
			if(i+2*j+3*k>number):
				break
			else:
				if(i+2*j+3*k==number):
					sum+=fac[i+j+k]/fac[i]/fac[j]/fac[k]*(2**i)
					break

print sum
endTime = datetime.now()
print endTime-startTime