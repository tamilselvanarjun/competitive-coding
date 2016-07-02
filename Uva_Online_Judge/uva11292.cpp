#include <bits/stdc++.h>
using namespace std;

int main() {
	int m,n,*d,*k,D,K,gold;
	while(true) {
		cin>>n>>m;
		D = K = gold = 0;
		if(n==0 and m==0) break;
		d = new int[n];
		k = new int[m];
		for(int i=0;i<n;i++) {
			cin>>d[i];
		}
		for(int i=0;i<m;i++) {
			cin>>k[i];
		}
		sort(d,d+n);
		sort(k,k+m);
		while(true) {
			while(k[K] < d[D] and K<m) K++;
			if(K==m or D==n) break;
			gold+=k[K];
			K++; D++;
		}
		if(D==n)
			printf("%d\n",gold);
		else
			printf("%s\n","Loowater is doomed!" );
	}
}