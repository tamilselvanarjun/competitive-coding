// AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >>t ;
	while(t--) {
		int n; cin >> n;
		int notPaidAndDelay = 0, delays = 0, notPaid = 0;
		bool zeroBeforeOne = false, zeros = false,a;
		while(n--) {
			cin >> a;
			if(a==false) {
				zeros = true;
				if(zeroBeforeOne) notPaid++;
				else notPaidAndDelay++;
			}
			if(a==true and zeros and !zeroBeforeOne) {
				zeroBeforeOne = true;
				delays = n+1;
			}
		}
		cout << 1100*notPaidAndDelay + 1000*notPaid + 100*delays << endl;
	}
	return 0;
}