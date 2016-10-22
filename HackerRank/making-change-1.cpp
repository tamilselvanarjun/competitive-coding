#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lld unsigned int
lld k,n,*wi,*vi;
lld **knap;         // stores the max value

lld getKnap(int k, int n) {     // k is the val, n is the number
    if(k == 0) {
        return 0;
    }
    else if(n == 0) {
        return 0;
    }
    else if(knap[k][n] != -1) {
        return knap[k][n];
    }
    else {
        for(lld i=0;i<=(k/wi[n]);i++)
            knap[k][n] = max(knap[k][n], vi[n]*i + getKnap(k-i*wi[n],n-1));
        return knap[k][n];
    }
}

int main() {
    cin>> k >> n;
    wi = new lld[n];
    vi = new lld[n];
    
    for(int i=0;i<n;i++) {
        cin >> vi[i] >> wi[i];
    }
    
    knap = new lld*[k+1];
    for(lld ai=0;ai<=k;ai++)
        knap[ai] = new lld[n+1];
    
    for(lld i=0;i<k+1;i++)
        for(lld j=0;j<n+1;j++)
            knap[i][j] = -1;
        
    cout<<getKnap(k,n)<<endl;
    return 0;
}
