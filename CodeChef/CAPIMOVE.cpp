// AC
#include <bits/stdc++.h>
using namespace std;
int *cityRank;

struct city {
	int no, pop;
};

// sort in desc order
bool cityPop(city a, city b) {
	return a.pop > b.pop;
}

bool cityRanker(int a, int b) {
	return cityRank[a] < cityRank[b];
}

int main(int argc, char const *argv[])
{
	int t; cin >>t;
	while(t--) {
		
		int n; cin >> n;
		int u,v;

		city *p = new city[n+1];
		cityRank = new int[n+1];	//stores rank of city[i]

		// take all the edges
		for(int i=1;i<=n;i++) {
			cin >> p[i].pop;
			p[i].no = i;
		}

		// in descending order
		sort(p+1,p+n+1,cityPop);
		for(int i=1;i<=n;i++) {
			cityRank[p[i].no] = i;
		}
		// assigned to them

		vector< vector<int> > edges; 
		edges.resize(n+1);

		for(int i=0;i<n-1;i++) {
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);			
		}

		for(int i=1;i<=n;i++)
			edges[i].push_back(i);

		// sort in order of ranks
		for(int i=1;i<=n;i++) {
			sort(edges[i].begin(),edges[i].end(),cityRanker);
		}

		// declare results here
		int tmprank;
		for(int i=1;i<=n;i++) {
			tmprank = 1;
			for(int j=0;j<edges[i].size();j++) {
				if(cityRank[edges[i][j]] == tmprank) {
					tmprank++;
				}
			}
			if(tmprank==n+1) {
				cout << 0 << " ";
			}
			else {
				cout << p[tmprank].no << " ";
			}
		}
		cout << endl;

		delete[] p,cityRank;
	}
	return 0;
}