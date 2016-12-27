#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// AC
struct Graph {
    int V;
    vector< vector<int> > edges;
    
    Graph(int g) {
        V = g;
        edges.resize(V+1);
    }
    
    void insert(int u,int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    void showDistances(int s) {
        
        int dist[V+1]; 
        bool visited[V+1];
        int u,vv;
        for(int i=1;i<=V;i++) {
            dist[i]=-1;
            visited[i]=false;
        }
        dist[s]=0; visited[s] = true;
        
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            u = q.front();
            q.pop();
            for(int i=0;i<edges[u].size();i++) {
                vv = edges[u][i];
                if(!visited[vv]) {
                    q.push(vv);
                    visited[vv]=true;
                    dist[vv] = dist[u] + 1;
                }
            }
        }
        
        for(int i=1;i<=V;i++) {
            if(i==s)
               continue;
            if(dist[i]==-1) 
                cout<<-1<<" ";
            else
                cout<<dist[i]*6<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int q, n,m,s,u,v;
    cin>>q;
    for(int i=0;i<q;i++) {
        cin>>n>>m;
        Graph g(n);
        for(int j=0;j<m;j++) {
            cin>>u>>v;
            g.insert(u,v);
        }
        cin>>s;
        g.showDistances(s);
    }
    return 0;
}
