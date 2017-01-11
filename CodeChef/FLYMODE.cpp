// AC
#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long int

int main()
{
	int n; cin >> n;
	int *arr, *sarr, *earr,m,M;
	arr = new int[n];
	sarr = new int[n-1];
	earr = new int[n-1];

	int tmp; 
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	for(int i=0;i<n-1;i++) {
		m = min(arr[i],arr[i+1]);
		M = max(arr[i],arr[i+1]);
		sarr[i] = m;
		earr[i] = M;
	}
	sort(sarr,sarr+n-1);
	sort(earr,earr+n-1);
	int count = 0,maxc=-1;
	int i1=0,i2=0;
	while(i1 < n-1 and i2 < n-1) {
		if(sarr[i1] < earr[i2]) {
			count++;
			maxc = max(maxc,count);
			i1++;
		}
		else {
			count--;
			maxc = max(maxc,count);
			i2++;
		}
	}
	if(i1 < n-1) {
		while(i1 < n-1)
			count++;
	}
	maxc = max(maxc,count);

	cout << maxc << endl;

	return 0;
}