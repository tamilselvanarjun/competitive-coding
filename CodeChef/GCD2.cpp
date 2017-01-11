// AC
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int mymod(string s, int n) {
	int pow = 1, res = 0, index = s.size()-1;
	while(index >= 0) {
		res += ((s[index]-'0')*pow)%n;
		pow = (pow*10)%n;
		index--;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int a;
		string b;
		cin >> a >> b;
		if(a==0) {
			cout << b << endl;
		}
		else {
			int g = mymod(b,a);
			cout << gcd(a,g) << endl;
		}
	}
	return 0;
}