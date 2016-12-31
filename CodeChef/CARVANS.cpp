// AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while(t--) {
		int n; cin >> n; 
		unsigned int count=0, maxSpeed = numeric_limits<int>::max(), curSpeed;
		for(int i=0;i<n;i++) {
			cin >> curSpeed;
			if(curSpeed <= maxSpeed) {
				maxSpeed = curSpeed;
				count++;
			}
		}
		cout << count << endl;

	}
	return 0;
}