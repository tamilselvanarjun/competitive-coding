#include <bits/stdc++.h>
using namespace std;
typedef long long int ilong;
int main() {
	ilong n,t;
	cin>>t;
	for(ilong i=0;i<t;i++) {
		cin>>n;
		cout<<abs(((((n*567)/9+7492)*235/47-498)/10)%10)<<endl;
	}
}