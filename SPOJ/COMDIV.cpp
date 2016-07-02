#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a, int b) {
	// cout<<a<<" "<<b<<endl;
	// cout<<"here\n";
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

int factorsOf(int k) {
	// cout<<"there\n";
	int count=0,i;
	for(i=1;i<=sqrt(k);i++) {
		if(k%i==0)
			count+=2;
	}
	if((i-1)*(i-1)==k) 
		count--;
	return count;
}

int main() {
	int t,a,b,c,d;
	d = scanf("%d\n",&t);
	for(int i=0;i<t;i++) {
		d = scanf("%d %d\n",&a,&b);
		c = gcd(a,b);
		printf("%d\n",factorsOf(c));
	}
}
//AC