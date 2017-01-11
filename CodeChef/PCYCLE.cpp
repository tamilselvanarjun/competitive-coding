// AC
#include <bits/stdc++.h>
using namespace std;
int *arr;

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	arr = new int[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];

	vector<vector<int> >result;
	bool *visited = new bool[n+1];

	for(int i=1;i<=n;i++)
		visited[i] = false; 

	int it = 1;
	while(it<=n) {
		if(visited[it]) {
			it++; continue;
		}
		vector<int> tmp;
		int index = it;
		while(!visited[index]) {
			visited[index] = true;
			tmp.push_back(index);
			index = arr[index];
		}
		result.push_back(tmp);
	}

	cout << result.size() << endl;
	for(int i=0;i<result.size();i++) {
		for(int j=0;j<result[i].size();j++)
			cout << result[i][j] << " ";
		cout << result[i][0] << endl;
	}

	delete[] arr, visited;
	return 0;
}