#include <bits/stdc++.h>
using namespace std;
#define lld long int
map<lld,lld> coinValue;

lld getCoins(lld n) {

	if(coinValue[n])
		return coinValue[n];

	if(int(n/2) + int(n/3) + int(n/4) > n) {
		coinValue[n] = getCoins(int(n/2)) + getCoins(int(n/3)) + getCoins(int(n/4));
		return coinValue[n];
	}
	else {
		coinValue[n] = n;
		return n;
	}
}

int main() {

	coinValue[0] = 0;

	lld number;
	while(cin>>number) {
		cout<<getCoins(number)<<endl;
	}

}


//Seg fault