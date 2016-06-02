#include <bits/stdc++.h>
using namespace std;
#define ulong unsigned long long int
ulong grayCode(ulong n, ulong k) {
	if(n==1) {
		if(k==0)
			return 0;
		return 1; 
	}
	else {
		if(k<pow(2,n-1)) {
			return grayCode(n-1,k);
		}
		else {
			return pow(2,n-1)+grayCode(n-1,pow(2,n)-1-k);
		}
	}
}

int main() {
	ulong N,n,k;
	cin>>N;
	for(ulong i=0;i<N;i++) {
		cin>>n>>k;
		cout<<grayCode(n,k)<<endl;
	}
}