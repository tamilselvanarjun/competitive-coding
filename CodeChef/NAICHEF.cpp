#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char const *argv[])
{
	int t; 
	cin >> t;
	while(t--) {
		unsigned long int n, a, b;
		cin >> n >> a >> b;
		unsigned long int ca = 0, cb = 0;
		unsigned long int tmp;
		for(int i=0;i<n; i++) {
			cin >> tmp;
			if(tmp == a)
				ca++;
			if(tmp == b)
				cb++;
		}
		double prob1 = 1.0*ca/n;
		double prob2 = 1.0*cb/n;
		cout << prob2*prob1 << endl;
	}
	return 0;
} 