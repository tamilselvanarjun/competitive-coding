#include <bits/stdc++.h>
using namespace std;
#define lld long long int
int main() {
	int t;
	lld n;
	cin>>t;
	for(int i=0;i<t;i++) {
		cin>>n;
		if(n%6)	//Winning state 
			cout<<"Chef\n";
		else
			cout<<"Misha\n";
	}
}