// AC, easy af
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		string j,s;
		cin>>j>>s;
		int count=0;
		for(int i=0;i<s.size();i++) {
			for(int a=0;a<j.size();a++) {
				if(s[i] == j[a]) {
					count++;
					break;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}