//easy, AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,g;
	cin >>t;
	while(t--){
		cin>>g;
		while(g--) {
			int i,n,q;
			cin >> i >> n >> q;
			if(i==q)
				cout << n/2 << endl;
			else
				cout << n - n/2 << endl;
		}
	}
	return 0;
}