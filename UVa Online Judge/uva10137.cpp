//The trip		//O(n) algorithm
#include <bits/stdc++.h>
using namespace std;
#define ld double

int main() {
	int n;
	ld *money,avg,valPos, valNeg;
	while(true) {
		cin>>n;
		if(!n) break;
		avg = 0;
		valPos = 0;
		valNeg = 0;
		money = new ld[n];
		for(int i=0;i<n;i++) {
			cin>>money[i];
			avg+=money[i];
		}
		avg = avg/n;
		avg = round(avg*100)/100;
		for(int i=0;i<n;i++) {
			if(money[i] > avg) 
				valPos+=(money[i]-avg);
			else if(avg > money[i])
				valNeg+=(avg-money[i]);
		}

		printf("$%.2f\n",min(valPos,valNeg));
		delete[] money;
	}
}