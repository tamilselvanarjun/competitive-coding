#include <iostream>
#include <cmath>
#include <cstdio>
int N = pow(10,9)+7;
#define lld unsigned long long int
using namespace std;

int main() {
	int t;
	int h = scanf("%d\n",&t);
	for (int i = 0; i < t; i++)
	{
		lld product = 1;
		string s;
		getline(cin,s);
		lld len = s.length();
		if(len!=1){
			for(lld j=0;j<len;j++) {
				if(j==0) {
					if(s[0]!=s[1]) {
						product = 2;
					}
				}
				else if (j==len-1) {
					if(s[len-2]!=s[len-1]) {
						product = (product*2)%N;
					}
				}
				else {
					char a,b,c;
					a=s[j-1],b=s[j],c=s[j+1];
					if(a!=b and b!=c and a!=c) {
						product = (product*3)%N;
					}
					else if((a==b and b!=c) or (a==c and b!=c) or (b==c and a!=c)) {
						product = (product*2)%N;
					}
				}
			}
		}
		cout<<"Case #"<<i+1<<": "<<product<<endl;
	}
}