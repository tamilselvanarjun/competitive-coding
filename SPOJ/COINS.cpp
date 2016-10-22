#include <iostream>
#include <unordered_map>
using namespace std;
#define lld long unsigned int
unordered_map<lld,lld> A;

lld amount(lld n) {
	if(n <= 11)
		return n;
	else if(A[n])
		return A[n];
	else {
		return A[n] = max(n,amount(n/2) + amount(n/3) + amount(n/4));
	}
}

int main() {
	lld n;
	while(cin>>n) {
		cout<<amount(n)<<endl;
	}
}
