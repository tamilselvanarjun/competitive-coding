#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long ulong;

int main(){
	ulong* fac;
	ulong n;
	cin>>n;
	fac = new ulong[n+1];
	fac[0] = fac[1] = 1;

	for(int h=2;h<=n;h++) {
		fac[h] = h*fac[h-1];
	}

	ulong x=0,y=0,z=0,sum=0;
	for(int i=0;i<=n;i++) {
		if(i==n) {
			sum+=pow(2,n);
			break;
		}

		for(int j=0;j<=n/2;j++) {
			if(i+2*j>n) {
				break;
			}
			else if(i+2*j==n) {
				sum += fac[i+j]/(fac[i]*fac[j])*pow(2,i);
				break;
			}

			for(int k=0;k<=n/3;k++) {
				if(i+2*j+3*k>n) {
					break;
				}
				else{
					if(i+2*j+3*k==n) {
						sum+=fac[i+j+k]/fac[i]/fac[j]/fac[k]*pow(2,i);
						break;
					}
				}
			}
		}
	}
	cout<<sum<<endl;
	delete[] fac;
}