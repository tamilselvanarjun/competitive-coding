#include <bits/stdc++.h>
using namespace std;
int N = numeric_limits<int>::max();
int main() {
	int n,k,c;
	int *prices,*res;
	cin>>c;
	for(int ai=0;ai<c;ai++) {
		cin>>n>>k;
		prices = new int[k+1]();
		res = new int[k+1]();
		for(int i=1;i<=k;i++) {
			cin>>prices[i];
			res[i] = N;
		}
		res[1] = prices[1];

		for(int i=2;i<=k;i++) {
			for(int j=1;j<=i;j++) {
				if(prices[j]!=-1 and res[i-j]!=-1)
					res[i] = min(res[i],prices[j]+res[i-j]);
				else 
					res[i] = min(res[i],-1);
			}
		}
		cout<<res[k]<<endl;
		delete[] prices,res;
	}
}
//AC