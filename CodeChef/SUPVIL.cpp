// AC
#include <bits/stdc++.h>
using namespace std;
// #define uld unsigned long int
// #define lld long long int
// //uld UMAX = numeric_limits<uld>::max();

int main()
{
	int t; cin >> t;
	while(t--) {

		int sup=1,vil = 1, win=0; 
		bool flag=true;
		int n; cin >> n;

		for(int i=0;i<n;i++) {
			string s; cin >> s;
			if(s.size()<3)
				vil++;
			else if(s.substr(s.size()-3,3) == "man")
				sup++;
			else
				vil++;
			if((sup >= vil + 2) and flag) {
				win = 1;
				flag=false;
			}
			else if((sup+3<=vil) and flag) {
				win = -1;
				flag=false;
			}
		}
		if(win==1)
			cout<<"superheroes\n";
		else if(win==0)
			cout<<"draw\n";
		else
			cout << "villains\n";
	}
	return 0;
}