//AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
	bool houses[100];
	int t, h;
	cin >> t;
	while(t--) {
		for(int i=0;i<100;i++)
			houses[i] = true;
		int x, y, M;
		cin >> M >> x >> y;
		for(int i=0; i<M; i++) {
			cin >> h;
			for(int j=max(0, h-1 - x*y); j<=min(99, h-1+x*y); j++)
				houses[j] = false;
		}
		uint sum = 0;
		for(int i=0;i<100;i++) {
			sum+=(int)houses[i];
		}
		cout << sum << endl;
	}
	return 0;
}