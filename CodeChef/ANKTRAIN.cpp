// AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n;
		int q,r;
		q = n/8; r=n%8;
		switch(r) {
			case 1: r = 4; s = "LB";break;
			case 2: r = 5; s = "MB";break;
			case 3: r = 6; s = "UB";break;
			case 4: r = 1; s = "LB";break; 
			case 5: r = 2; s = "MB";break;
			case 6: r = 3; s = "UB";break;
			case 7: r = 0; q+=1; s = "SU";break;
			case 0: r = 7; q-=1; s = "SL";break;
		}
		n = 8*q+r;
		cout<<n<<s<<endl;
	}
	return 0;
}