// partial AC, implement O(nlogn)
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}


int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int *arr = new int[n];
		for(int i=0;i<n;i++)
			cin >> arr[i];

		int *count = new int[n];
		for(int i=0;i<n;i++)
			count[i] = 1;

		for(int i=1;i<n;i++) {
			for(int j=0;j<i;j++) {
				if(count[i] < count[j]+1 and gcd(arr[i],arr[j])!=1) {
					count[i] = count[j]+1;
				}
			}	
		}

		int maxC = numeric_limits<int>::min();
		for(int i=0;i<n;i++)
			maxC = max(maxC,count[i]);

		cout << maxC << endl;
		delete[] count, arr;
	}
	return 0;
}