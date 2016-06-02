#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int uilong;
int main() {
	uilong n,b,h,p,w,wi;
	while(cin>>n>>b>>h>>w) {
	uilong minPrice = numeric_limits<uilong>::max();		//infinity
	bool found = false;
		for(uilong i=0;i<h;i++) {
			cin>>p;
			for(uilong j=0;j<w;j++) {
				cin>>wi;
				if(wi>=n) {		//beds available
					if(n*p <= b) {
						minPrice = min(minPrice,n*p);
						found = true;
					}				
				}
			}
		}
		if(found)
			cout<<minPrice<<endl;
		else
			cout<<"stay home\n";
	}
}