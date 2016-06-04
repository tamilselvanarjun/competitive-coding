#include <iostream>
using namespace std;
typedef long unsigned ulong;
int main(){
	ulong n,m;
	ulong *c;
	ulong **D;
	cin>>n>>m;
	c = new ulong[m+1];
	c[0] = 0;
	for(ulong i=1;i<=m;i++) {
		cin>>c[i];
	}
	//input done
	D = new ulong*[n+1];
	for(ulong i=0;i<=n;i++) {
		D[i] = new ulong[m+1];
	}
	//init
	for(ulong i=0;i<=n;i++) {
		D[i][0] = 1;
	}
	for(ulong i=0;i<=m;i++) {
		D[0][i] = 1;
	}
	for(ulong i=1;i<=n;i++) {
		for(ulong j=1;j<=m;j++) {
			D[i][j] = 0;
			for(ulong k=0;k<=i/c[j];k++) {
				D[i][j] += D[i-k*c[j]][j-1];
			}
		}
	}
	cout<<D[n][m]<<endl;
	for(ulong i=0;i<=n;i++) {
		delete[] D[i];
	}
	delete[] D;
}