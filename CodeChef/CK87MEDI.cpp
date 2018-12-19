//AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >>t ;
	while(t--) {
		int n,k;
		cin >> n >> k;
		int *arr = new int[n];
		for(int i=0;i<n;i++)
			cin >> arr[i];
		sort(arr, arr+n);
		if(k>n)
			cout << arr[n-1] << endl;
		else 
			cout << arr[(n+k)/2] << endl;
		delete[] arr;
	}
	return 0;
}