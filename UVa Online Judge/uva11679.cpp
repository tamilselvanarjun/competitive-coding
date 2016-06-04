#include <bits/stdc++.h>
typedef long long int longi;
using namespace std;

int main() {
	longi b,n,*r;
	bool solvable;
	while(true) {
		solvable = true;
		cin>>b>>n;
		if(b==0 and n==0) 
			break;
		r = new longi[b+1];
		r[0] = 0;

		for(longi i=1;i<=b;i++) {
			cin>>r[i];
		}

		for(longi i=0;i<n;i++) {
			longi d,c,v;
			cin>>d>>c>>v;
			r[d]-=v;
			r[c]+=v;
		}

		for(longi i=1;i<=b;i++) {
			if(r[i]<0) {
				solvable=false;
				break;
			}
		}
		if(solvable)
			cout<<"S\n";
		else
			cout<<"N\n";
		delete[] r;
	}
}