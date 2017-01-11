#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long int 

struct edge {
	int u,v;
	lld w,ow;
};

struct subset {
	int parent,rank;
};

vector<edge> graph;

bool cmpFunc(edge a, edge b) {
	return a.w < b.w;
}

void myunion(subset* gr, int u, int v) {
	subset s1 = gr[u], s2 = gr[v];
	if(s1.rank > s2.rank)
		gr[v].parent = u;
	else if(s2.rank > s1.rank) 
		gr[u].parent = v;
	else {
		gr[u].parent = v;
		gr[u].rank++;
	}
}

int find(subset *gr, int u) {
	int p1 = gr[u].parent;
	if(p1 == u)
		return u;
	else
		return gr[u].parent = find(gr,gr[u].parent);
}

lld mstWeight(int n) {

	sort(graph.begin(),graph.end(),cmpFunc);

	subset *gr = new subset[n+1];
	for(int i=1;i<=n;i++) {
		gr[i].parent = i;
		gr[i].rank = 0;
	}

	lld sum = 0;
	int e=0,i=0;
	while(e < n-1 and i<graph.size()) {
		edge tmp = graph[i];
		if(find(gr,tmp.u) != find(gr,tmp.v)) {
			myunion(gr,tmp.u,tmp.v);
			e++;
			sum+=tmp.w;
		}
		i++;
	}

	delete[] gr;

	return sum;
}

int main()
{
	int n,m,q;
	int u,v,w;
	cin >> n >> m >> q;
	edge tmp;
	for(int i=0;i<m;i++) {
		cin >> tmp.u >> tmp.v >> tmp.ow;
		tmp.w = tmp.ow;
		graph.push_back(tmp);
	}

	int choice;
	for(int i=0;i<q;i++) {
		cin >> choice;
		if(choice == 1) {
			cin >> u >> v;
			for(int i=0;i<m;i++)
				if((graph[i].u == u and graph[i].v == v) or (graph[i].u == v and graph[i].v == u)) {
					graph[i].w = 0;
					break;
				}
		}
		else if(choice == 2) {
			cin >> u >> v;
			for(int i=0;i<m;i++)
				if((graph[i].u == u and graph[i].v == v) or (graph[i].u == v and graph[i].v == u)) {
					graph[i].w = graph[i].ow;
					break;
				}
		}
		else if(choice == 3) {
			cout << mstWeight(n) << endl;
		}
	}
	return 0;
}