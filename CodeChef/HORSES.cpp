// AC, easy
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n; cin >>n;
		unsigned int *s;
		s = new unsigned int[n];
		for(int i=0;i<n;i++)
			cin >> s[i];
		sort(s,s+n);
		unsigned int minSkill = s[1]-s[0];
		for(int i=1;i<n-1;i++) {
			minSkill = min(minSkill,s[i+1]-s[i]);
		}
		cout<<minSkill<<endl;
		delete[] s;
	}
	return 0;
}