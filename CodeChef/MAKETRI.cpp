// AC
#include <bits/stdc++.h>
using namespace std;
#define lld long long int
struct interval {
	lld low, high;
};

bool cmpFunc(interval a, interval b) {
	if(a.low < b.low)
		return true;
	else if(a.low > b.low)
		return false;
	else 
		return b.high <= a.high;
}

int main(int argc, char const *argv[])
{
	lld n,l,r,*a,sum=0;
	cin >> n >> l >> r;
	a = new lld[n];
	for(lld i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	interval* ii = new interval[n-1];
	for(int i=0;i<n-1;i++) {
		ii[i].low = (a[i+1]-a[i]+1);
		ii[i].high = (a[i+1]+a[i]-1);
	}
	sort(ii, ii+n-1, cmpFunc);
	for(int i=0;i<n-1;i++) {
		if(ii[i].high < l)
			continue;
		else if(ii[i].low > r)
			break;
		sum += (min(r,ii[i].high) - max(l,ii[i].low) + 1);
		l = ii[i].high + 1;
		if(l > r)
			break;
	}

	cout << sum << endl;
	return 0;
}