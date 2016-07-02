#include <bits/stdc++.h>
using namespace std;
#define ulong unsigned long int

int main() {
	ulong n,d,r;
	while(true) {
		cin>>n>>d>>r;
		if(n==0 and d==0 and r==0) 
			break;
		ulong *morning,*evening;
		morning = new ulong[n];
		evening = new ulong[n];
		for(ulong i=0;i<n;i++)
			cin>>morning[i];
		for(ulong i =0;i<n;i++)
			cin>>evening[i];
		sort(morning,morning+n);
		sort(evening,evening+n);
		ulong minFee = 0;
		for(ulong i =0;i<n;i++) {
			if(morning[i] + evening[n-1-i] > d)
				minFee += (morning[i]+evening[n-1-i]-d)*r;
		}
		cout<<minFee<<endl;
	}
}