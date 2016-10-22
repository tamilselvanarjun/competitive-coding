#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int cur[5];
	int res[5];
	int sum = 0;
	for(int i=0;i<5;i++)
		cin>>cur[i];
	for(int i=0;i<5;i++)
		cin>>res[i];
	for(int i=0;i<5;i++) {
		sum += min((res[i]-cur[i]+10)%10, 10 - (res[i]-cur[i]+10)%10);
		// cout<<min((res[i]-cur[i]+10)%10, 10 - (res[i]-cur[i]+10)%10)<<endl;
	}
	cout<<sum<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
