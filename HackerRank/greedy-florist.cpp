#include <bits/stdc++.h>
using namespace std;
bool f(int a, int b) {
        return a>b;
}

int main() {
    int n,k,answer=0,x=1,friends;
    int *flowers;
    cin>>n>>k;
    friends = k;
    flowers = new int[n];
    for(int i=0;i<n;i++)
        cin>>flowers[i];
    sort(flowers,flowers+n,f);
    for(int i=0;i<n;i++) {
        if(friends==0) {
            x++;
            friends = k;
        }
        answer += flowers[i]*x;
        friends--;
    }
    cout<<answer<<endl;
    delete[] flowers;
}
