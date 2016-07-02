// TLE
#include <bits/stdc++.h>
using namespace std;
#define lld long long int
const int N = pow(10,9)+7;
int *v;

lld timerSum(int m, lld x, lld y) {

	if(m==0) {
		// printf("%s\n","0" );
		lld sum = 0;
		for(lld i=x;i<=y;i++) {
			sum = (sum+(v[i])%N)%N;
		}
		return sum;
	}
	bool xIsEven = x%2==0 , yIsEven = y%2==0;
	// cout<<"m="<<m<<" x="<<xIsEven<<" y="<<yIsEven<<endl;
	if(!xIsEven and !yIsEven) {			//both are odd
		// printf("%s\n","1");
		if(x==y) 
			return timerSum(m-1,(x+1)/2,(y+1)/2);
		else if(x>y)
			return 0;
		else {
			return ((2*timerSum(m-1,(x+1)/2,(y+1)/2))%N + (timerSum(m-1,(x+3)/2,(y-1)/2))%N)%N;
		} 
	}
	else if(xIsEven and !yIsEven) {
		// printf("%s\n","2" );
		if(x>y)
			return 0;
		return timerSum(m,x-1,y) - timerSum(m,x-1,x-1);
	}
	else if(!xIsEven and yIsEven) {
		// printf("%s\n","3" );
		if(x>y)
			return 0;
		return timerSum(m,x,y+1) - timerSum(m,y+1,y+1);
	}
	else if(xIsEven and yIsEven) {
		// printf("%s\n","4" );
		if(x>y)
			return 0;
		return timerSum(m,x-1,y+1) - timerSum(m,x-1,x-1) - timerSum(m,y+1,y+1);
	}
}

int main() {
	int t,m;
	lld n,x,y;
	cin>>t;
	for(int i=0;i<t;i++) {
		cin>>n>>m>>x>>y;
		// printf("n=%lld m=%d x=%lld y=%lld\n",n,m,x,y);
		v = new int[n+1];
		v[0] = 0;
		for(lld j=1;j<=n;j++) {
			cin>>v[j];
		}
		cout<<timerSum(m,x,y)<<endl;
		delete[] v;
	}
}