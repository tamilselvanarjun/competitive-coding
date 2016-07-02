#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::min();
int main() {
	int n;
	while(true) {
		cin>>n;
		if(n==0) break;
		int *v,*res;
		v = new int[n];
		res = new int[n];
		for(int i=0;i<n;i++) 
			cin>>v[i];
		int j = 0;
		for(int i=0;i<n;i++) {
			if(v[i]!=0) {
				res[j] = v[i];
				j++;
			}
		}
		if(j==0) {
			cout<<"0\n";
		}
		else {
			for(int k=0;k<j;k++) {
				cout<<res[k];
				if(k!=j-1)
					cout<<" ";
			}
			cout<<endl;
		}
		delete[] v,res;
	}
}

// This solution is for all integers and subsequence means a continous subsequence
// /////////////////////////////////////////////////////////
// int curSum = 0,alreadyMax = INF;
// int maxSum = INF;
// int startIndex = -1, endIndex = -1;
// int curStartIndex=0,curEndIndex;

// for(int i=0;i<n;i++) {
// 	curSum += v[i];
// 	if(maxSum < curSum) {
// 		curEndIndex = i;
// 		maxSum = curSum;
// 	}
// 	if(curSum<0 or i==n-1) {
// 		curSum = 0;
		
// 		if(maxSum > alreadyMax) { 	//new sum is more than already max
// 			endIndex = curEndIndex;
// 			startIndex = curStartIndex;
// 			alreadyMax = maxSum;
// 		}
// 		else if(maxSum == alreadyMax) {
// 			if((endIndex-startIndex) > (curEndIndex-curStartIndex)) {		// new sum has min length
// 				endIndex = curEndIndex;
// 				startIndex = curStartIndex;
// 			}	
// 		}

// 		if (i!=n-1) {
// 			curStartIndex = i+1;
// 			curEndIndex = i+1;	
// 		}
// 		// cout<<"curStartIndex "<<curStartIndex<<" "<<"curEndIndex "<<curEndIndex;
// 		// cout<<"\nStartIndex "<<startIndex<<" endIndex"<<endIndex<<endl;
// 	}
// }
// for(int i=startIndex; i<=endIndex; i++) {
// 	if(v[i]!=0) {
// 		cout<<v[i];
// 		if(i!=endIndex and v[i+1]!=0)
// 			cout<<" ";
// 	}

// }