#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,l,m;
	while(true) {
		cin>>n>>l>>m;
		bitset<7> t(n),v;
		for(int i=l;i<=m;i++) {
			v = bitset<7>(i);
			cout<<t<<endl<<v<<"\n\n";
		}
	}
}