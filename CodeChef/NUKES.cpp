// very easy, AC
#include <bits/stdc++.h>
using namespace std;
#define lld long unsigned int

int main(int argc, char const *argv[])
{
	lld a; int n,k;
	cin >> a >> n >> k; n++;
	for(int i=0;i<k;i++) {
		cout << a%n << " ";
		a/=n;
	}
	cout<<endl;
	return 0;
}