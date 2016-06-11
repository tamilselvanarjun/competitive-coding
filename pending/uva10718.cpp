// Incomplete (brute-force)
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,l,m,maxMask=0,u=0;
	while(cin>>n>>l>>m) {
		maxMask = u = 0;
		for(int i=l;i<=m;i++) {
			int temp = n|i;
			if(temp > maxMask) {
				u = i;
				maxMask = n|i;
			}
		}
		cout<<u<<endl;
	}
	
}
