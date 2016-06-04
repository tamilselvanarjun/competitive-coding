#include <iostream>
using namespace std;
typedef long unsigned ulong;

int main(){
	ulong n;
	cin>>n;
	ulong* sum = new ulong[n+1];
	sum[0]=0;
	if(n>=1)
		sum[1]=2;
	if(n>=2)
		sum[2]=5;
	if(n>=3)
		sum[3]=13;
	for(ulong i=4;i<=n;i++) {
		sum[i] = 2*sum[i-1] + sum[i-2] + sum[i-3];
	}
	cout<<sum[n]<<endl;

	delete[] sum;
}