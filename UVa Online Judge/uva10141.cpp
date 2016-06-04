#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,p;
	string *r;
	float *prices;
	int *req, ctr = 1;
	while(true) {
		scanf("%d %d\n",&n,&p);
		if(n==0 and p==0)
			break;
		else if(ctr!=1)
			cout<<endl;
		int index = -1;
		int maxReq = numeric_limits<int>::min();
		for(int i=0;i<n;i++) {
			string s;
			getline(cin,s);
		}
		
		r = new string[p];
		prices = new float[p];
		req = new int[p];

		for(int i=0;i<p;i++) {
			getline(cin,r[i]);
			scanf("%f %d\n",&prices[i],&req[i]);
			
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
		cout<<r[index]<<endl;
		ctr++;

		delete[] r;
		delete[] req;
		delete[] prices;
	}
}
