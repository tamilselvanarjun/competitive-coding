#include <iostream>
#include <vector>
using namespace std;
#define vi vector<int>

void dfs(int **mat, int n, vi &path,int source, bool *visited) {
	
	path.push_back(source);
	visited[source] = true;

	for(int i=0;i<n;i++) {
		if(mat[source][i] == 1 and !visited[i])
			dfs(mat,n,path,i,visited);
	}
}

void dominator(int **mat, int n, vi &path, int source) {
	
}

int main(int argc, char const *argv[])
{
	int n, **mat;
	cin>>n;
	mat = new int*[n];
	bool *visited = new bool[n];

	for(int i=0;i<n;i++) {
		mat[i] = new int[n];
		visited[i] = false;
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mat[i][j];

	vi path;

	dfs(mat,n,path,0,visited);

	for(vi::iterator it = path.begin(); it!=path.end();it++)
		cout<<*it<<" ";
	cout<<endl;

	for(int i=0;i<n;i++)
		delete[] mat[i];

	delete[] mat;
	delete[] visited;

	return 0;
}