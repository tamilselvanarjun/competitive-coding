//AC
#include <bits/stdc++.h>
using namespace std;
#define lld long long unsigned int

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--){
		lld n; cin >> n;
		lld count = 0;
		for(lld val = sqrt(n); val > 0; val--) {
			if(n - val*val >= 700) {
				count+=(val*700);
				break;
			}
			else {
				count += (n-val*val);
			}
		}
		cout << count << endl;
	}
	return 0;
}