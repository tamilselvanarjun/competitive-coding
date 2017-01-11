// AC, super easy
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) { 
		int n; int tmp;
		cin >> n; int sum = 0;
		for(int i=0;i<n;i++) {
			cin >> tmp; sum+= tmp; cin >> tmp; sum-=tmp;
		}
		cout << sum << endl;
	}
	return 0;
}