#include <bits/stdc++.h>
using namespace std;
int main() {
	int b,s,*ageB,*ageS,ctr=1;
	while(true) {
		cin>>b>>s;
		if(b==0 and s==0)
			break;
		ageB = new int[b];
		ageS = new int[s];
		for(int i=0;i<b;i++)
			cin>>ageB[i];
		for(int i=0;i<s;i++)
			cin>>ageS[i];
		sort(ageB,ageB+b);
		sort(ageS,ageS+s);
		cout<<"Case "<<ctr<<": ";
		if(b<=s)
			cout<<"0\n";
		else {
			cout<<(b-s)<<" "<<ageB[0]<<endl;
		}
		delete[] ageB,ageS;
		ctr++;
	}
}