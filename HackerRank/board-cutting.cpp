#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N = pow(10,9)+7;
bool f(lld a, lld b) {
    return a>b;
}

int main(){
    lld t,m,n;
    lld sum,ySeg,xSeg,*yCuts,*xCuts;
    cin>>t;
    for(lld ai=0;ai<t;ai++) {
        cin>>m>>n;
        ySeg=xSeg=1;
        sum=0;
        m--;n--;
        yCuts = new lld[m];
        xCuts = new lld[n];
        for(lld i=0;i<m;i++)
            cin>>yCuts[i];
        for(lld i=0;i<n;i++)
            cin>>xCuts[i];
        sort(yCuts,yCuts+m,f);
        sort(xCuts,xCuts+n,f);
        // cout<<endl;
        lld ctrx=0,ctry=0;
        for(;ctrx<n and ctry<m;) {
            if(yCuts[ctry] > xCuts[ctrx]) {
                // cout<<"ctr y "<<ctry<<endl;
                sum = (sum + ((ySeg%N)*(yCuts[ctry]%N))%N )%N;
                ctry++;
                xSeg++;
            }
            else if(yCuts[ctry] < xCuts[ctrx]) {
                // cout<<"ctr x "<<ctrx<<endl;
                sum = (sum + ((xSeg%N)*(xCuts[ctrx]%N))%N )%N;
                ctrx++;
                ySeg++;
            }
            else if(yCuts[ctry] == xCuts[ctrx]) {

                if(ySeg < xSeg) {
                    // cout<<"here\n";
                    sum = (sum + ((ySeg%N)*(yCuts[ctry]%N))%N )%N;
                    ctry++;
                    xSeg++;
                }
                else {
                    // cout<<"Elsewhere\n";
                    sum = (sum + ((xSeg%N)*(xCuts[ctrx]%N))%N )%N;
                    ctrx++;
                    ySeg++;
                }
            }
        }
        //for loop over
        if(ctrx<n) {
            for(lld i=ctrx;i<n;i++) {
                sum = (sum + ((xSeg%N)*(xCuts[i]%N))%N )%N;
            }
        }
        if(ctry<m) {
            for(lld i=ctry;i<m;i++) {
                sum = (sum + ((ySeg%N)*(yCuts[i]%N))%N )%N;
            }
        }
        cout<<sum<<endl;
        delete[] yCuts,xCuts;
    }
}
