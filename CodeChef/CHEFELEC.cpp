//AC
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

int main(int argc, char const *argv[]) {
	
	int t,n;
	string detail;
	lld wireLength;
	lld *x,*sub;
	vector<int> elecPresent;
	int h = scanf("%d\n",&t);

	for(int i=0;i<t;i++) {
		//init
		elecPresent.resize(0);
		wireLength = 0;
		detail = "";

		h = scanf("%d\n",&n);
		x = new lld[n];
		sub = new lld[n-1];
		//inp
		getline(cin,detail);
		for(int j=0;j<n;j++) {
			h = scanf("%lld",&x[j]);
		}
		// making values
		for(int j=0;j<n-1;j++) {
			sub[j] = x[j+1]-x[j];
		}
		for(int j=0;j<detail.length();j++) {
			if(detail[j]=='1')
				elecPresent.push_back(j);
		}
		//compute 
		//initial
		for(int j=0;j<elecPresent[0];j++) {
			wireLength += sub[j];
		}

		//intermediate
		for(int j=0;j<elecPresent.size()-1;j++) {
			lld maxNum = -1;
			for(int k=elecPresent[j];k<elecPresent[j+1];k++) {
				wireLength+= sub[k];
				maxNum = max(maxNum,sub[k]);
			}
			wireLength-= maxNum;
		}

		//end
		for(int j=elecPresent[elecPresent.size()-1];j<n-1;j++) {
			wireLength += sub[j];
		}

		printf("%lld\n",wireLength);
		delete[] x,sub;
	}

}
