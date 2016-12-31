// AC
#include <bits/stdc++.h>
using namespace std;

int local(int *arr, int n) {
	int count = 0;
	for(int i=0;i<n-1;i++)
		count += (arr[i] > arr[i+1]);
	return count;
}

int inversions(int *arr, int n) {
	int count=0;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(arr[i] > arr[j])
				count++;
	return count;
}

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int *arr = new int[n];
		for(int i=0;i<n;i++)
			cin >> arr[i];
		if(inversions(arr,n) == local(arr,n))
			cout <<"YES"<<endl;
		else
			cout <<"NO"<<endl;
	}
	return 0;
}