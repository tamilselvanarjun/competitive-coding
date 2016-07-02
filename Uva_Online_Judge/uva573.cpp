#include <bits/stdc++.h>
using namespace std;
#define udouble long double 
int main() {
	udouble h,u,d,f,height;
	unsigned long int day;
	while(true) {
		cin>>h>>u>>d>>f;
		if(h==u and u==d and d==f and f==0)
			break;
		f = u*(f/100);
		height = 0;
		day = 0;		//parameters set
		while(true) {
			day++;
			height+=u;
			if(height>h) {
				cout<<"success on day ";
				break;
			}
			height-=d;
			if(height<0) {
				cout<<"failure on day ";
				break;
			}
			u = (u-f)<0?0:(u-f);
		}
		cout<<day<<endl;
	}

}