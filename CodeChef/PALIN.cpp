// AC, good one
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		string s; cin >> s; int n = s.size();
		bool all9 = true, palin = true;
		int i = 0, j = s.size()-1;

		while(i <= j) {
			if(all9 and (s[i]!='9' or s[j]!='9'))
				all9 = false;
			if(palin and s[i]!=s[j])
				palin = false;
			i++;
			j--;
		}

		if(all9) {
			cout << "1";
			for(int k=0;k<s.size()-1;k++)
				cout << "0";
			cout << "1" << endl;
			continue;
		}

		if(palin) {
			i--; j++;
			while(s[i]=='9') {
				s[i]='0'; s[j] = '0';
				i--; j++;
			}
			s[i] = s[i]+1;
			if(j!=i)
				s[j] = s[j]+1;
			cout << s << endl;
			continue;
		}

		bool evalAgain = false;
		i = n/2-1;
		j = (n%2==0)?(n/2):(n/2+1);

		while(s[i] == s[j] and i>=0) {
			i--; j++;
		}

		if(s[i] < s[j])
			evalAgain = true;

		while(i>=0) {
			s[j] = s[i];
			i--; j++;
		}

		if(evalAgain) {
			i = (n%2==0)?(n/2-1):(n/2);
			j = (n%2==0)?(n/2):(n/2);
			while(s[i]=='9') {
				s[i]='0'; s[j] = '0';
				i--; j++;
			}
			s[i] = s[i]+1;
			if(j!=i)
				s[j] = s[j]+1;
		}

		cout << s << endl;

	}
	return 0;
}