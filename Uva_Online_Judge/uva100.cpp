#include <bits/stdc++.h>
using namespace std;
// #define N 100000000
// int v[N];

int count(int n) {
	// if(v[n]!=-1) return v[n];
	if(n==1) return 1;

	if(n%2) {
		return 1 + count(3*n+1);
	}		//odd
	else {
		return 1 + count(n/2);
	}
//	return v[n];
}

int main() {
	// memset(v,-1,N);
	// v[1] = 1;
	int counter,m,n,a,b;
	while(cin>>m>>n) {
		counter = -1;
		a = min(m,n);
		b = max(m,n);
		for(int i=a;i<=b;i++) {
			counter = max(counter,count(i));
		}
		printf("%d %d %d\n",m,n,counter);
	}
}