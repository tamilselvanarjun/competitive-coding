//Easy, x2 + y2 + z2 = C is a good starting point
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c,t;
	cin>>t;
	bool sol;
	while(t--) {
		int x,y,z;
		cin>>a>>b>>c;
		sol = false;
		for(x=-100;x<=100;x++) {
			for(y=-100;y<=100;y++) {
				for(z=-100;z<=100;z++) {
					if(x!=y and y!=z and x!=z) {
						if(pow(x,2)+pow(y,2)+pow(z,2)==c and x*y*z==b and x+y+z==a) {
							printf("%d %d %d\n",x,y,z);
							sol = true;
							break;
						}
					}
				}
				if(sol) break;
			}
			if(sol) break;
		}
		if(!sol) cout<<"No solution.\n";
	}
}