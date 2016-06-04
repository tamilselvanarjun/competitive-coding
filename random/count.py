while(1):
	num = input()
	if(num==''):
		break
	num = eval(num)[0]
	sum = [0,2,5,13]
	for x in range(4,num+1):
		sum.append(2*sum[x-1]+sum[x-2]+sum[x-3])
	print (sum[num])
