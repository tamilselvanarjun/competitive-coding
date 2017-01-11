// AC
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

int main(int argc, char const *argv[])
{
	int t; cin >>t;
	while(t--) {
		lld c,d,l,z=0;
		cin >> c >> d >> l;

		lld minFeet = (max(z,c-2*d) + d)*4, maxFeet = (d+c)*4;
		if(l >= minFeet and l <= maxFeet) {
			if(l%4==0)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}