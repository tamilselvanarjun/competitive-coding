#include <iostream>
using namespace std;
typedef long unsigned int ulong;

int main() {
	ulong n,k,*rem,temp,sum=0;
	cin>>n>>k;
	rem = new ulong[k];

	for(ulong i=0;i<k;i++) {
		rem[i] = 0;
	}

	for(ulong i=0;i<n;i++) {
		cin>>temp;
		rem[temp%k]++;
	}

	for(ulong i=1;i<(k/2)+(k%2);i++) {
		sum += max(rem[i],rem[k-i]);
	}

	if(rem[0]) {
		sum+=1;
	}	
	if(!(k%2)) {
		if(rem[k/2]) {
			sum++;
		}
	}

	cout<<sum<<endl;
	delete[] rem;
}