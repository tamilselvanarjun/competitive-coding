//Pending
#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld **valCount,*coinValue;

lld findVal(lld n,lld m) {
	if(n==0)
		return 1;
	if(m==0)
		return 1;

	if (valCount[m][n]!=-1)
		return valCount[m][n];
	else {
		lld k = 0; int valCounter=0;

		while( n >= valCounter*coinValue[m] ) {
			k += findVal(n-valCounter*coinValue[m],m-1);
			valCounter++;
		}
		valCount[m][n] = k;
		return k;
	}
}

int main() {
	lld m,n;
	int h = scanf("%lld %lld\n",&n,&m);
	valCount = new lld*[m+1];
	coinValue = new lld[m+1];

	for(int i=1;i<=m;i++) {
		scanf("%lld",&coinValue[i]);
		valCount[i] = new lld[n+1];
		memset(valCount[i],-1,n+1);
	}
	valCount[0] = new lld[n+1];
	memset(valCount[0],-1,n+1);

	lld sum = findVal(n,m);
	printf("%lld\n",sum);

}