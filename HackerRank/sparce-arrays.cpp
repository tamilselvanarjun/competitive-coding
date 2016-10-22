#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	string* words,tmp;
	int n,q,count;
	int h = scanf("%d",&n);
	words = new string[n];
	for(int i=0;i<n;i++)
		cin>>words[i];
	
	cin>>q;
	
	for(int i=0;i<q;i++) {
		count=0;
		cin>>tmp;
		for(int i=0;i<n;i++)
			if(words[i]==tmp)
				count++;
		cout<<count<<endl;
	}
	return 0;
}


//AC