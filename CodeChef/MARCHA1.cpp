// AC
#include <bits/stdc++.h>
using namespace std;
int *notes;
int **result;

int backtrack(int amt, int index) {
	if(amt == 0)
		return 1;
	else if(index < 0)
		return 0;
	else if(result[amt][index] != -1)
		return result[amt][index];
	else {
		int res;
		if(amt >= notes[index]) {
			res = max(backtrack(amt-notes[index],index-1), backtrack(amt,index-1));		
		}
		else {
			res = backtrack(amt,index-1);
		}
		return result[amt][index] = res;
	}
}

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		notes = new int[n];

		for(int i=0;i<n;i++)
			cin >> notes[i];

		result = new int*[m+1];

		for(int i=1;i<=m;i++) {
			result[i] = new int[n];
			for(int j=0;j<n;j++)
				result[i][j]=-1;
		}

		if(backtrack(m,n-1))
			cout << "Yes\n";
		else
			cout << "No\n";

		delete[] notes;
		for(int i=1;i<=m;i++) {
			delete[] result[i];
		}
		delete[] result;

	}
	return 0;
}