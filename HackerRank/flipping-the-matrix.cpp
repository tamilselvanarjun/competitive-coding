//AC
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >>t;
	while(t--) {
		int n; cin >> n;
		int **arr = new int*[2*n];
		for(int i=0;i<2*n;i++)
			arr[i] = new int[2*n];

		for(int i=0;i<2*n;i++)
			for(int j=0;j<2*n;j++)
				cin >> arr[i][j];

		long int sum = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				sum += max(max(arr[i][j],arr[2*n-1-i][j]),max(arr[i][2*n-1-j],arr[2*n-1-i][2*n-1-j]));
			}
		}
		cout << sum << endl;
		for(int i=0;i<2*n;i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}