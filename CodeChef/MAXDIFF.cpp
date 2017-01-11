// AC
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n,k; cin >> n >> k;
		lld sum = 0;
		int *arr = new int[n];
		for(int i=0;i<n;i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		sort(arr,arr+n);
		lld lsum = 0, rsum = 0;
		for(int i=0;i<k;i++) {
			lsum += arr[i];
			rsum += arr[n-1-i];
		}
		cout << max(2*rsum - sum, sum - 2*lsum) << endl;
		delete[] arr;
	}
	return 0;
}