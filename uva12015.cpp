#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string web[10];
	int relevance[10];
	cin>>t;
	for(int i=0;i<t;i++) {
		int maxRel = numeric_limits<int>::min();
		for(int j=0;j<10;j++) {
			cin>>web[j];
			cin>>relevance[j];
			maxRel = max(maxRel,relevance[j]);
		}
		cout<<"Case #"<<i+1<<":\n";
		for(int j=0;j<10;j++) {
			if(maxRel==relevance[j])
				cout<<web[j]<<endl;
		}		
	}
}