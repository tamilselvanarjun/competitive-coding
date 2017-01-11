# AC, C++ soln required
def gcd(a,b):
	if a%b == 0:
		return b
	else:
		return gcd(b, a%b)

n = input()
for i in xrange(n):
	s = raw_input()
	a,b = map(int, s.split(" "))
	print(gcd(a,b))