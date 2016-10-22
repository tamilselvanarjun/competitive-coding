#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int q; cin>> q;
    string a,b;
    vector<char> v1,v2;
    

    for(int i=0;i<q;i++) {
        v1.erase(); v2.erase();
    	cin>>a>>b;

    	int index1 = 0, index2=0, len1 = a.length(), len2 = b.length();
    	for(int j=0;j<len1;j++)
            v1.push_back(a[j]);

        for(int j=0;j<len2;j++)
            v1.push_back(b[j]);


    	while(index1 < len1 and index2 < len2) {
    		if(b[index2] == a[index1]) {
    			index2++;
    			index1++;
    		}
    		else {
    			index1++;
    		}
    	}

    	if(index2==len2) {
    		cout<<"YES\n";
    	}
    	else
    		cout<<"NO\n";
    } 

    return 0;
}
