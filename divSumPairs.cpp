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

	sum+=(rem[0])*(rem[0]-1)/2;

	for(ulong i=1;i<(k/2)+(k%2);i++) {
		sum+= rem[i]*rem[k-i];
	}

	if(!(k%2)) {    //even 
		sum+= rem[k/2]*(rem[k/2]-1)/2;	
	}	

	cout<<sum<<endl;
	delete[] rem;
}