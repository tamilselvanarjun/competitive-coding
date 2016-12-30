// AC
#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long int

lld marbles(lld n, lld k) {
	if(k==1 or k==0)
		return pow(n,k);
	
	if(k > n/2)
		k = n-k;
	
	lld ans = 1;
	for(lld j=1;j<=k;j++,n--) {
		if(n%j==0)
			ans *= (n/j);
		else if(ans%j == 0) 
			ans = (ans/j)*n;
		else
			ans = (ans*n)/j;
	}
	return ans;
}

int main() {
	lld t,n,k;
	cin >>t ;
	while(t--) {
		cin >> n >> k;
		cout << marbles(n-1,n-k) << endl;
	}
	return 0;
}