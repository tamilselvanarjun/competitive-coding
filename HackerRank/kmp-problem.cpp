// AC, good one
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char const *argv[])
{
	int x[26];
	for(int i=0;i<26;i++)
		cin >> x[i];
	int start = 0,minindex;
	while(x[start] == 0)
		start++;
	minindex = start;
	for(int i=start;i<26;i++) 
		if(x[i]!=0 and x[i] < x[minindex])
			minindex = i;

	// cout <<"start: "<<start << ", min index" << minindex << endl; 
	// construct the string here
	if(minindex != start) {
		x[minindex]--;
		cout << char('a' + minindex);
		for(int i=start;i<26;i++)
			for(int j=0;j<x[i];j++)
				cout << char('a'+i);
		cout << endl;
	}
	else {
		cout << char('a' + minindex);
		x[minindex]-=1;
		if(x[minindex] > 0) {
			cout << char('a' + minindex);
			x[minindex]--;
		}
		int kk;
		for(kk=start+1;x[kk]==0 and kk < 26;kk++);
		if(kk == 26) {	// all others are zero
			for(int i=0;i<x[minindex];i++)
				cout << char('a'+minindex);
		}
		else {
			while(x[minindex]!=0) {
				cout << char('a'+kk) << char('a'+minindex);
				x[minindex]--; x[kk]--;
			}

			for(int i=start;i<26;i++)
				for(int j=0;j<x[i];j++)
					cout << char('a'+i);
		}
		cout << endl;
	}

	return 0;
}