// try backtrack

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lld unsigned long int

bool printBacktrackSol(int n, int k, int b, bool* &bought, int size) {
	
	if(n<0 or k<0 or b<0)	 {	// some error case 
		cout<<"noooo\n";
		return false;
	}

	if(b==0 and n==0) 
		return true;		// all boxes bought
	else if(n==0 and b!=0)
		return false;		// cant buy exactly b boxes
	else if (n!=0 and b==0)
		return false;
	else {
		
		bool x = false;
		for(int i=0;i<size;i++)
			if(!bought[i]) {		// not bought
				x = true;
				break;
			}

		if(!x)					// all bought
			return false;

	}

	for(int i=0;i<k;i++) {
		if(bought[i])
			continue;

		bought[i]=true;
		if(printBacktrackSol(n-i,k-1,b-1,bought,size)) {
			cout<<i<<" ";
			return true;
		}
		bought[i]=false;
	}
}

int main() {
	lld n,b,k,t;
	cin>>t;
	bool *bought;
	for(int i=0;i<t;i++) {
		cin>>n>>k>>b;
		bought = new bool[k];
		
		for(int j=0;j<k;j++)
			bought[j]=false;

		bool ok = printBacktrackSol(n,k,b,bought,k);
		if(ok)
			cout<<endl;
		delete[] bought;
	}
    return 0;
}
