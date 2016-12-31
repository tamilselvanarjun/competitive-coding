// AC
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int *arr;
		arr = new int[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int count = 1, el;
		cin >> el; el = arr[el-1];
		for(int i=0;i<n;i++)
			count += (el > arr[i]);
		cout << count << endl;
		delete[] arr;
	}
	return 0;
}