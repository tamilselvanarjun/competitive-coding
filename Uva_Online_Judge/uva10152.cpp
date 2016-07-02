#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	string *names, *finish;
	string s;
	map<string,int> mymap;
	cin>>t;
	for(int k=0;k<t;k++) {

		int something;
		something = scanf("%d\n",&n);
		names = new string[n];
		finish = new string[n];
		for(int i=0;i<n;i++) {
			getline(cin,names[i]);
			mymap[names[i]] = i;
		}
		for(int i=0;i<n;i++) {
			getline(cin,finish[i]);
		}

		int index = -1;
		for(int i=n-1;i>0;i--) {
			if(mymap[finish[i]] < mymap[finish[i-1]]) {
				index = i-1;
				break;
			}
		}
		if(index!=-1) {
			for(int i = index; i>=0;i--) {
				cout<<finish[i]<<endl;
			}
		}
		delete[] names,finish;
		cout<<endl;
	}
}