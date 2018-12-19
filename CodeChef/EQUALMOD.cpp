#include <bits/stdc++.h>
using namespace std;
#define lld long long int
struct val
{
	lld a, b;
};

bool cmp(val x, val y) {
	return x.a > y.a;
}

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		val *v = new val[n];

		for(int i=0; i<n; i++) 
			cin >> v[i].a;
		for(int i=0;i<n;i++) {
			cin >> v[i].b;
		}
		for(int i=0;i<n;i++) {
			v[i].a = v[i].a % v[i].b;
		}

		lld count = 0, minBi = 1e9+7;
		for(int i=0;i<n;i++)
			minBi = min(minBi, v[i].b);

		for(int i=0;i<n;i++) {
			if(v[i].a >= minBi) {
				count += (v[i].b-v[i].a);
				v[i].a = 0;
			}
		}

		sort(v, v+n, cmp);

		lld sum = 0;
		for(int i=0;i<n;i++) {
			sum += (v[i].a);			
		}

		lld count2 = v[0].a*n - sum;
		lld curCost = count2, prevCost = count2;
		for(int i=1; i<n; i++) {
			curCost = prevCost - (v[i-1].a - v[i].a)*(n) + (v[i-1].b);
			count2 = min(count2, curCost);
			prevCost = curCost;
		}

		cout << count + count2 << endl;

		delete[] v;
	}
	return 0;
}