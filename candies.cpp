#include <iostream>
using namespace std;
typedef unsigned long int ulong;

int main() {

	ulong n,sum=0;
	cin>>n;
	ulong* rating,*candies;
	rating = new ulong[n];
	candies = new ulong[n];
	for(ulong i=0;i<n;i++) {
		cin>>rating[i];
	}
	candies[0]=1;
	
	for(ulong i = 1; i < n; ++i) {
		if(rating[i]>rating[i-1]) {
			candies[i] = candies[i-1] + ulong(1);
		}	
		else{
			candies[i] = ulong(1);
		}
	}

	for(long int i= (n-2); i>=0; i--) {

		if(rating[i]>rating[i+1]) {
			candies[i] = max(candies[i+1] + ulong(1), candies[i]);
		}
	}

	for(ulong i=0;i<n;i++) {
		sum+=candies[i];
	}
	cout<<sum<<endl;
	delete[] candies;
	delete[] rating;
}