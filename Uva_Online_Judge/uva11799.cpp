//Super easy
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long int ulong;
int main(){
	int t;
	ulong maxSpeed, n,v;
	cin>>t;
	for(int i=0;i<t;i++) {
		maxSpeed = numeric_limits<ulong>::min();
		cin>>n;
		for(ulong j=0;j<n;j++) {
			cin>>v;
			maxSpeed = max(maxSpeed,v);
		}
		cout<<"Case "<<i+1<<": "<<maxSpeed<<endl;
	}
}