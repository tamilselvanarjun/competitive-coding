// AC
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n,x,sum=0;
		cin >> n >> x;
		int *amt;
		amt=new int[n];
		for(int i=0;i<n;i++) {
			cin >> amt[i];
			sum+=amt[i];
		}
		int maxSw = sum/x;
		bool extra=false;
		for(int i=0;i<n;i++)
			if(((sum-amt[i])/x)==maxSw) {
				extra=true;
				break;
			}
		if(extra)
			cout << -1 << endl;
		else
			cout << maxSw << endl;	
		delete[] amt;

	}
	return 0;
}