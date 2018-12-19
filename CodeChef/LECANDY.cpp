//AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		uint n, c, sum=0, t;
		bool allHappy = true;
		cin >> n >> c ;
		for(uint i=0;i<n;i++) {
			cin >> t;
			sum+=t;
			if(sum > c)
				allHappy = false;
		}
		if(allHappy)
			cout << "Yes" << endl;
		else
			cout << "No"  << endl;
	}
	return 0;
}