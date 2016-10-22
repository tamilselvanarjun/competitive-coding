#include <iostream>
#include <list>
#include <cstdio>
using namespace std;

class Graph {
	public:
		//variables
		int NoOfPoints;
		list<int> *Edges;
		
		//functions
		Graph(int V);
		bool addGraphEdge(int u, int v);
		void printGraph();

		//breadthwise travel
		void breadthTravel(int s);

		//depth first travel
		void depthTravel(int s);
		void depthTravelUtil(int s,bool& *visited);

};	

void Graph::depthTravel(int s) {
	bool *visited = new bool[NoOfPoints];
	for(int i=0;i<NoOfPoints;i++) {
		visited[i] = false;
	}

	depthTravelUtil(s,visited);
	cout<<endl;
	delete[] visited;
}

void Graph::depthTravelUtil(int s,bool& *visited) {
	visited[s] = true;
	cout<< s << " ";

	list<int>::iterator i;
	for(i=Edges[s].begin();i!=Edges[s].end();i++) {
		if(!visited[*i]) {
			depthTravelUtil(*i,visited);
		}
	}
}

Graph::Graph(int V) {
	NoOfPoints = V;
	Edges = new list<int>[V];
}

bool Graph::addGraphEdge(int u, int v) {
	if(max(u,v)>=NoOfPoints) 
		return false;
	else {
		Edges[u].push_back(v);
		return true;
	}
}

void Graph::printGraph() {
	for(int i=0;i<NoOfPoints;i++) {
		printf("%s %d\n","Vertices connected to vertex",i );
		list<int>::iterator it = Edges[i].begin();
		for(;it != Edges[i].end();it++) {
			printf("%d " , *it );
		}
		printf("%s\n","" );
	}
}

void Graph::breadthTravel(int s) {
	list<int> queue;
	list<int>::iterator it;

	bool *visited = new bool[NoOfPoints];
	for(int i=0;i<NoOfPoints;i++)
		visited[i] = false;

	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty()) {
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();

		for(it=Edges[s].begin();it!=Edges[s].end();it++) {
			if(!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
	cout<<endl;
	delete[] visited;
	
}

int main(int argc, char const *argv[])
{
	int t,h;
	printf("%s\n","Enter the number of Vertices!" );
	cin>>t;
	Graph g(t);

	char choice = 'y';
	while(choice=='y') {
		int u,v;
		printf("%s\n","Enter u and v.");
		cin>>u>>v;
		if(g.addGraphEdge(u,v)) {
			printf("%s\n","Edge added." );
		}
		else {
			printf("%s\n","Edge cant be added." );
		}
		printf("%s\n","Want to enter more?" );
		cin>>choice;
	}
	g.printGraph();
	cout<<"Breadth traversal for graph- ";
	g.breadthTravel(2);
}