#include <bits/stdc++.h>
using namespace std;
typedef long long int ilong;
int main(){
	ilong k,n,m,x,y;
	while(true) {
		cin>>k;
		if(!k) break;
		cin>>n>>m;
		for(ilong i=0;i<k;i++) {
			cin>>x>>y;
			if(x==n or y==m) 
				cout<<"divisa\n";
			else if(x<n and y<m) 
				cout<<"SO\n";
			else if(x<n and y>m)
				cout<<"NO\n";
			else if(x>n and y<m)
				cout<<"SE\n";
			else
				cout<<"NE\n";
		}
	}
}