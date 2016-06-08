#include <bits/stdc++.h>
using namespace std;
#define lg long long int
int main() {
	lg mymax,mymin;
	int n,q;
	cin>>n>>q;
	lg *v,t;
	v = new lg[n];
	for(int i=0;i<n;i++) {
		cin>>v[i];
	}
	sort(v,v+n);
	mymax = v[n-1];
	mymin = v[0];
	for(int i=0;i<q;i++) {
		cin>>t;
		if(t<mymin or t>mymax)
			cout<<"No\n";
		else
			cout<<"Yes\n";
	}
	delete[] v;
}