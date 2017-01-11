//AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n,m; cin >> n >> m;
		char **res = new char*[n];
		for(int i=0;i<n;i++)
			res[i] = new char[m+2];

		for(int i=0;i<n;i++)
			for(int j=1;j<=m;j++)
				cin >> res[i][j];

		for(int i=0;i<n;i++)
			res[i][0] = res[i][m+1] = 'A';

		bool stable = true;
		for(int i=0;i<n-1 and stable;i++) {
			for(int j=1;j<=m and stable;j++) {
				// water
				if(res[i][j] == 'W') {
					if(res[i][j-1] == 'A' or res[i][j+1]=='A')
						stable = false;
					else if(res[i+1][j] == 'A')
						stable = false;
				}
				// brick
				else if(res[i][j] == 'B') {
					if(res[i+1][j] != 'B')
						stable = false;
				}
			}
		}

		// last line
		for(int j=1;j<=m;j++) {
			// water
			if(res[n-1][j] == 'W') {
				if(res[n-1][j-1] == 'A' or res[n-1][j+1]=='A')
					stable = false;
			}
			// air
			else if(res[n-1][j] == 'A') {
				if(n>1) {
					if(res[n-2][j] != 'A')
						stable = false;
				}
			}
		}

		if(stable)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		for(int i=0;i<n;i++)
			delete[] res[i];
		delete[] res;
	}
	return 0;
}