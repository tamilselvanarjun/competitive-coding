#include <bits/stdc++.h>
using namespace std;
int main() {
	unsigned long long int n;
	string s;
	cin>>n;
	for(unsigned long int i=0;i<n;i++) {
		s = "";
		cin>>s;
		if(s=="1" or s=="4" or s=="78")
			cout<<"+\n";
		else if(s.substr(s.length()-2)=="35")
			cout<<"-\n";
		else if(s[0]=='9' and s[s.length()-1]=='4')
			cout<<"*\n";
		else if(s.substr(0,3)=="190")
			cout<<"?\n";
	} 
}