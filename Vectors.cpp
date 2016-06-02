#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	vector<int>::iterator it = v.begin();
	int k;
	while(cin>>k && k!=0) {						//pushing elements dynamincally
		v.push_back(k);
	}

	for(it=v.begin();it<v.end();it++) {		//printing stuff
		cout<<*it<<" ";
	}

	sort(v.begin(),v.end());					//sorting

	cout<<"\nAlternate print \n";
	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<" ";				//printing like array
	}
	cout<<endl;

	cout<<"Enter element to search for\n";
	int n;
	cin>>n;
	if(binary_search(v.begin(),v.end(),n))
		cout<<"Element found\n";
	else
		cout<<"Element not found\n";


}