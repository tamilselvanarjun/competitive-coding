// AC
#include <bits/stdc++.h>
using namespace std;
int n;

int binarySearch(int *arr, int i, int j) {
	int sum = arr[i] + arr[j];
	int beg = j+1, end = n-1;
	while(beg <= end) {
		int mid = (beg+end)/2;
		if(arr[mid] > sum and arr[mid-1] <= sum) {
			return mid;
		}
		else if(arr[mid] <= sum) {
			beg = mid+1;
		}
		else {
			end = mid-1;
		}
	}
	return n;
}


int main(int argc, char const *argv[])
{
	while(true) {
		cin >> n;
		if(n==0)
			break;
		int *length = new int[n];
		for(int i=0;i<n;i++)
			cin >> length[i];
		sort(length,length+n);
		int count = 0;
		for(int i=0;i<(n-2);i++) {
			for(int j=i+1;j<(n-1);j++) {
				int k = binarySearch(length, i, j);
				// cout << "k -> " << k << endl;
				count += (n-k);
			}
		}
		cout << count << endl;
		delete[] length;
	}
	return 0;
}