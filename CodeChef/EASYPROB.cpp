// AC
#include <bits/stdc++.h>
using namespace std;
string repr(int n) {
	string s = "", a;
	int pw = 0;
	while(n) {
		if(n%2) {
			if(pw==0)
				a = "2(0)";
			else if(pw==1)
				a = "2";
			else
				a = "2(" + repr(pw) + ")";
			if(s=="")
				s = a;
			else {
				s = a + "+" + s;
			}
		}
		n/=2;
		pw++;
	}
	return s;
}

int main()
{
	int nbers[] = {137, 1315, 73, 136, 255, 1384, 16385};
	for(int i=0;i<7;i++) {
		cout << nbers[i] << "=" << repr(nbers[i]) << endl;
	}
}