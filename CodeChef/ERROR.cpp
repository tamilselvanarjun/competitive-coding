// AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >>t ;
	while(t--) {
		string s; cin >> s;
		bool flag=true;
		if(s.size() < 3) {
			cout << "Bad" << endl;
			continue;
		}

		int i = 0;
		while(i <= s.size()-3 and flag) {
			if(s[i]=='0'){
				if(s[i+1]=='0') {
					i++;
				}
				else{
					if(s[i+2]=='0') {
						cout << "Good" << endl;
						flag=false;
					}
					else {
						i+=2;
					}
				}
			}
			else {
				if(s[i+1]=='1') {
					i++;
				}
				else{
					if(s[i+2]=='1') {
						cout << "Good" << endl;
						flag=false;
					}
					else {
						i+=2;
					}
				}
			}
		}
		if(flag)
			cout << "Bad" << endl;
	}
	return 0;
}