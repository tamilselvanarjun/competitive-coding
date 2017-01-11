// AC
#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long int

int main(int argc, char const *argv[])
{
	int n; cin >> n; int count=0;
	while(n--) {
		int x1,x2,x3,y1,y2,y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		lld s[3];
		s[0] = pow((x1-x2),2) + pow((y1-y2),2);
		s[1] = pow((x2-x3),2) + pow((y2-y3),2);
		s[2] = pow((x1-x3),2) + pow((y1-y3),2);
		sort(s,s+3);
		if(s[0]+s[1] == s[2])
			count++;
	}
	cout << count << endl;
	return 0;
}