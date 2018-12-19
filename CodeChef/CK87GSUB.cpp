#include <bits/stdc++.h>
using namespace std;
#define lld long long unsigned int

lld count(string &s, int l, int r) {
	
	if(l == r)
		return 0;
	// base case
	if(r-l == 1) {
		return (s[l] == s[r])?1:0;
	}

	int mid = (l+r)/2;
	lld left = count(s, l, mid);
	lld right = count(s, mid+1, r);

	int l1 = mid, l2 = mid+1;
	int li = 0, ri = 0;
		

	while(l1>=l && s[l1] == s[mid]) {
		l1--;
		li++;
	}

	while(l2<=r && s[l2] == s[mid+1]) {
		l2++;
		ri++;
	}

	// add those elements if mid ~= mid+1
	if(s[mid] == s[mid+1]) {
		left += (li*ri);
		if(l1 >= l and l2 <= r) {
			if(s[l1] == s[l2])
				right+=1;
		}
	}
	else {
		if(l1 >= l) {
			if(s[l1] == s[mid+1])
				left+=1;
		}

		if(l2 <= r) {
			if(s[l2] == s[mid])
				right+=1;
		}
	}

	// return left + right parts
	return left+right;
}



int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		string str;
		cin >> str; 
		cout << count(str, 0, str.size()-1) << endl;
	}
	return 0;
}