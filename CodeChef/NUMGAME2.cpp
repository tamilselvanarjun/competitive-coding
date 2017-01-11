//easy,AC
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		if(n%4==1)
			cout <<"ALICE"<<endl;
		else
			cout <<"BOB"<<endl;
	}
	return 0;
}