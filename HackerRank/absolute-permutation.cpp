#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void permutation(int n, int k) {
    int* arr;
    arr = new int[n+1];
    for(int i=1;i<=n;i++)
        arr[i] = -1;
    
    bool exists = true;
    
    if(k==0) {
        for(int i=1;i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
        return;
    }
    
    for(int i=1;i<=n;i++) {
        if(((i-1)/k)%2 == 0) {
            arr[i] = i+k;
            if(i+k > n) {
                exists = false;
                break;
            }
           
        }
        else {
            arr[i] = i-k;
        }
    }
    
    if(exists) {
        for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    else {
        cout<<-1<<endl;
    }
      
}

int main() {
    int t,n,k;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>n>>k;
        permutation(n,k);
    }
    return 0;
}


// AC