#include <iostream>
#include <cstdio>
using namespace std;
#define lld long unsigned int

lld findNum(lld n) {
	lld t = 5, count = 0;
	while(n/t) {
		count += n/t;
		t*=5;
	}
	return count;
}


int main() {
	
	lld t, num,h;
	cin>>t;
	for(lld s = 0;s<t;s++) {
		cin>>num;
		printf("%ld\n",findNum(num));
	}
	return 0;
}