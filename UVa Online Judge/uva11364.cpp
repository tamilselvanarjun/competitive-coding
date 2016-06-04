#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,x,mymax,mymin;
	cin>>t;
	for(int i=0;i<t;i++) {
		cin>>n;
		mymax = -1;
		mymin = 1000;
		for(int j=0;j<n;j++) {
			cin>>x;
			mymax = max(x,mymax);
			mymin = min(x,mymin);
		}
		cout<<2*(mymax-mymin)<<endl;
	}
}