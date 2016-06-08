#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long int
lld term(lld n) {
	if(n==0)
		return 0;
	else {
		return term(n/5)*10 + (n%5)*2;
	}
}
 
int main() {
	lld t,k;
	cin>>t;
	for(lld i=0;i<t;i++) {
		cin>>k;
		k--;
		lld sum = term(k);
		cout<<sum<<endl;
	}
} 