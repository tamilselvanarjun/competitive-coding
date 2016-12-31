// AC
#include <bits/stdc++.h>
using namespace std;

int main() {

	int t,m,n;
	cin >>t;
	while(t--) {
		cin>>m>>n;
		if((m==1 or m==2) and n>=2) {
			cout<<2<<endl;
			m=3;
		}
		else if(m%2==0) {
			m++;
		}
		// only odd numbers can be prime, except 2, which is handled above
		for(int i=m;i<=n;i+=2) {
			bool isPrime = true;
			for(int j=3;j*j<=i;j++) {
				if(i%j == 0) {
					isPrime = false;
					break;
				}
			}
			if(isPrime)
				cout<<i<<endl;
		}
		cout<<endl;
	}

}
