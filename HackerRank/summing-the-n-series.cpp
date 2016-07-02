#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long unsigned int t,n,sum=0,k;
    k = pow(10,9) + 7;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>n;
        sum = 0;
        sum = ((n%k)*(n%k))%k;
        cout<<sum<<endl;
    }
    return 0;
}
//AC