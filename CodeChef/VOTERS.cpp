// AC
#include <bits/stdc++.h>
using namespace std;
#define inf numeric_limits<int>::max();

int main(int argc, char const *argv[])
{
	int n1,n2,n3,*a1,*a2,*a3;
	cin >> n1 >> n2 >> n3;
	a1 = new int[n1];
	a2 = new int[n2];
	a3 = new int[n3];
	for(int i=0;i<n1;i++)
		cin >> a1[i];
	for(int i=0;i<n2;i++)
		cin >> a2[i];
	for(int i=0;i<n3;i++)
		cin >> a3[i];
	int i1=0,i2=0,i3=0;
	vector<int> res;
	while(i1 < n1 or i2 < n2 or i3 < n3) {
		int t1,t2,t3;
		t1 = i1<n1?a1[i1]:inf;
		t2 = i2<n2?a2[i2]:inf;
		t3 = i3<n3?a3[i3]:inf;
		if(t1 == t2 and t2 == t3) {	// all equal
			res.push_back(t1);
			i1++; i2++; i3++;
		}
		else if(t1==t2 and t2!=t3) {
			if(t1 < t3) {
				res.push_back(t1);
				i1++; i2++;
			}
			else {
				i3++;
			}
		}
		else if(t1==t3 and t2!=t3) {
			if(t1 < t2) {
				res.push_back(t1);
				i1++; i3++;
			}
			else {
				i2++;
			}
		}
		else if(t3==t2 and t1!=t3) {
			if(t3 < t1) {
				res.push_back(t3);
				i2++; i3++;
			}
			else {
				i1++;
			}
		}
		else {
			if(t1<t2 and t1<t3)
				i1++;
			else if(t2<t1 and t2<t3)
				i2++;
			else 
				i3++;
		}
	}
	cout << res.size() << endl;
	for(int i=0;i<res.size();i++)
		cout << res[i] << endl;

	delete[] a1,a2,a3;
	return 0;
}