// AC
#include <bits/stdc++.h>
using namespace std;

uint numberOfOnes(unsigned long long int a) {
	uint num = 0;
	while(a!=0) {
		num += (a%2);
		a/=2;
	}
	return num;
}

uint numberOfZeros(unsigned long long int a) {
	uint num = 0;
	while(true) {
		if(a%2 == 0)
			num += 1;
		else
			return num;
		a/=2;
	}
}


int main(int argc, char const *argv[])
{
	int t, index;
	unsigned long long int a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		uint a1 = 0, b1 = 0;

		if(a == b) {
			cout << 0 << endl;
			continue;
		}

		if(b == 0) {
			cout << -1 << endl;
			continue;
		}

		a1 = numberOfOnes(a);
		b1 = numberOfOnes(b);
		// for(int i=0;i<a.size(); i++)
		// 	if(a[i] == '1')
		// 		a1++;

		// for(int i=0;i<b.size(); i++)
		// 	if(b[i] == '1')
		// 		b1++;
		
		uint n = numberOfZeros(b);
		// for(int i=b.size()-1; i>=0; i--) {
		// 	if(b[i] == '1')
		// 		break;
		// 	n++;
		// }

		// cout << a1 << " " << b1 << " " << n << endl;
		// cout << a << " " << b << endl;
		if(b1 > a1) {
			// if b1 has more number of 1s
			if(b%2 == 1) {
				if(b1 != 1 or a1 == 0)
					cout << b1 - a1 << endl;
				else
					cout << -1 << endl;
			}
			else {
				// even number
				cout << b1 - a1 + n << endl;
			}
		}
		else {
			// b has lesser 1s than a
			if(b%2 == 1) {	// odd 'b'
				if(b1 != 1)
					cout << 2 << endl;
				else
					cout << -1 << endl;
			}
			else {	// even 'b'
				if(a1 > b1-1+n) 
					cout << 2 << endl;
				else
					cout << b1 + n - a1 << endl;
			}

		}

	}
	return 0;
}