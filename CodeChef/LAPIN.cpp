// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	int left[26],right[26];
	while(t--) {
		string s; cin >> s;
		for(int i=0;i<26;i++) {
			left[i] = 0;
			right[i]= 0;
		}
		
		int mid;
		if(s.size()%2) { //odd
			mid = s.size()/2 + 1;
		}
		else {
			mid = s.size()/2;
		}

		for(int i=0;i<s.size()/2;i++)
			left[s[i]-'a']++;
		for(int i=mid;i<s.size();i++)
			right[s[i]-'a']++;

		bool flag = true;
		for(int i=0;i<26;i++)
			if(left[i]!=right[i]) {
				flag = false;
				break;
			}
		s = (flag==true)?"YES":"NO";
		cout << s << endl;
	}
	return 0;
}