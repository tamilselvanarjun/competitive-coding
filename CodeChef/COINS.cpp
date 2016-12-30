// AC
#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long int
#define tInf 1000001
lld coinValue[tInf];

lld getCoins(lld n) {
	if(n<tInf)
		return coinValue[n];
	else 
		return max(n,getCoins(n/2)+getCoins(n/3)+getCoins(n/4));
}

int main() {

	for(lld i=0;i<12;i++)
		coinValue[i] = i;
	for(lld i=12;i<tInf;i++) 
		coinValue[i] = max(i, coinValue[i/2]+coinValue[i/3]+coinValue[i/4]);

	lld number;
	while(cin>>number) {
		cout<<getCoins(number)<<endl;
	}

}