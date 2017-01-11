// AC
#include <bits/stdc++.h>
using namespace std;
int *arr;

int inversions(int b, int e) {
	if(e-b == 0)
		return 0;
	else {
		int mid = b + (e-b)/2, left = inversions(b,mid), right = inversions(mid+1,e), count = 0;
		int i = b, j = mid+1, k = 0;
		int *d = new int[e-b+1];
		while(i <= mid and j <= e) {
			if(arr[i] < arr[j]) {
				d[k] = arr[i];
				i++;
			}
			else {
				d[k] = arr[j];
				j++;
				count += (mid-i+1);
			}
			k++;
		}
		while(i<=mid) {
			d[k] = arr[i];
			k++; i++;
		}
		while(j<=e) {
			d[k] = arr[j];
			k++; j++;
		}
		for(int i=b;i<=e;i++) {
			arr[i] = d[i-b];
		}
		delete[] d;
		return left + right + count;
	}
}

int main(int argc, char const *argv[])
{
	int t; cin >>t;
	while(t--) {
		int n; cin>>n;
		arr = new int[n]; bool tooChaotic = false;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			if(arr[i] - i > 3) 
				tooChaotic = true;
		}

		if(tooChaotic)
			cout << "Too chaotic" << endl;
		else {
			cout << inversions(0,n-1) << endl;
		}
		delete[] arr;
	}
	return 0;
}