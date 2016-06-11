#include <iostream>
using namespace std;
#define lld long long int

int main() {
    int n,m,a,b,k;
    lld *el,sum=0,maxSum=0;
    cin>>n>>m;
    el = new lld[n+1]();       //see the brackets, inits to zero automatically
    for(int i=0;i<m;i++) {
        cin>>a>>b>>k;
        el[a] += k;
        if(b+1<=n) el[b+1] -= k;
    }
    for(int i=1;i<=n;i++) {
        sum+=el[i];
        maxSum = max(maxSum,sum);
    }

    cout<<maxSum<<endl;
    delete[] el;
}
