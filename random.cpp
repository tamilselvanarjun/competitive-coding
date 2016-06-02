#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,n,*x,avg,dist1,dist2;
	cin>>t;
	for(int i=0;i<t;i++) {
		cin>>n;
		x = new int[n];
		avg = 0;
		for(int y=0;y<n;y++) {
			cin>>x[y];
			avg+=x[y];
		}
		avg = avg/n;
		dist1 = dist2 = 0;
		for(int y=0;y<n;y++) {
			dist1+=abs(x[y]-avg);
			dist2+=abs(x[y]-avg-1);
		}
		cout<<min(dist1,dist2)<<endl;
		delete[] x;
	}
}