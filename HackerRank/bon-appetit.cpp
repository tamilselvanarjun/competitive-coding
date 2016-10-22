#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lld long unsigned int

int main() {
	int n,k;
	long unsigned int *prices;
	long unsigned int price = 0,priceCharged;
	cin>>n>>k;
	prices = new lld[n];
	for(int i=0;i<n;i++) {
		cin>>prices[i];
		price+= prices[i];
	}
	cin>>priceCharged;
	price -= prices[k];
	price = price/2;
	if(priceCharged == price) {
		cout<<"Bon Appetit\n";
	}
	else {
		cout<<priceCharged-price<<endl;
	}

    return 0;
}
