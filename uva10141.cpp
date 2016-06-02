#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,p;
	string *r;
	long double *prices;
	int *req, ctr = 1;
	while(true) {
		cin>>n>>p;
		if(n==0)
			break;

		int index = -1;
		int maxReq = numeric_limits<int>::min();
		for(int i=0;i<n;i++) {
			string s;
			getline(cin,s);
		}
		
		r = new string[p];
		prices = new long double[p];
		req = new int[p];

		for(int i=0;i<p;i++) {
			getline(cin,r[i]);
			cin>>prices[i]>>req[i];

			for(int j=0;j<req[i];j++) {
				string temp;
				getline(cin,temp);
			}
			maxReq = max(maxReq,req[i]);
		}

		for(int i=0;i<p;i++) {
			if(req[i]==maxReq) {
				if(index==-1)
					index = i;
				else {
					if(prices[i] < prices[index])
						index = i;
				}
			}
		}
		cout<<"RFP #"<<ctr<<endl;
		cout<<r[index]<<endl<<endl;
		ctr++;

		delete[] r;
		delete[] req;
		delete[] prices;
	}
}