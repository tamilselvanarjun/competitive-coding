t = input()
M = pow(2, 33)
for i in xrange(t):
	n = input()
	res = (pow(2, n, M)+M-1)%M
	print("Case %d: %d"%(i+1, res))