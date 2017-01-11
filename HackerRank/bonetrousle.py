# AC
from __future__ import print_function

t = input()
while t>0:
	# k = 1 to k boxes
	n, k, b = map(int, (raw_input()).split(" "))
	minV = b*(b+1)/2
	maxV = k*b - (b-1)*b/2
	if(n >= minV and n<=maxV):
		q = int((n-minV)/b)
		r = (n-minV)%b
		# print("q r %d %d"%(q,r))
		if r is not 0:
			for i in range(1,b-r+1):
				print(i+q,end=" ")

			for j in range(b-r+1,b):
				print(j+q+1,end=" ")
			print(b+q+1)
		else:
			for i in range(1,b):
				print(i+q,end=" ")
			print(b+q)
	else:
		print("-1")
	t-=1