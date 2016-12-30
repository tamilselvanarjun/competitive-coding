// AC with C++14, other uncomment stoi()
#include <bits/stdc++.h>
using namespace std;

// int stoi(string s) {
// 	int num = 0;
// 	for(int i=s.size()-1;i>=0;i--) {
// 		num = (10*num) + (s[i]-'0'); 
// 	}
// 	return num;
// }

int main(int argc, char const *argv[])
{
	bool *twtbox;
	string s, numstr;
	int n,k;
	cin >> n >> k;
	twtbox = new bool[n+1];
	memset(twtbox, false, n+1);
	int count;

	for(int i=0;i<k;i++) {
		cin >> s;
		if(s == "CLOSEALL") {		
			memset(twtbox, false, n+1);
			count = 0;
		}
		else {
			cin >> s;
			int num = stoi(s);
			// numstr = s.substr(6,s.size()-6);
			// int num = stoi(numstr);
			twtbox[num] = !twtbox[num];
			count = 0;
			for(int i=1;i<=n;i++)
				count+=twtbox[i];
		}
		cout<<count<<endl;
	}
	delete[] twtbox;
	return 0;
}