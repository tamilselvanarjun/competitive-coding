#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,res;
	int first = 1;
	while(getline(cin,s)) {
		res = "";
		for(unsigned long int i=0;i<s.length();i++) {
			if(s[i]=='"'){
				if(first) {
					res = res + "``";
				}
				else {
					res = res + "''";
				}
				first = (first+1)%2;
			}
			else {
				res = res+s[i];
			}
		}
		cout<<res<<endl;
	}
}