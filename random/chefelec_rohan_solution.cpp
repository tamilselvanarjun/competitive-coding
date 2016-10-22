//WA
#include<iostream>
using namespace std;
#define ll unsigned long long int
int main()
{
	int t;
	ll n,i,j,li,ri,sum;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		char a[n+1];
		ll x[n+1];
		cin>>a;
		for(i=0;i<n;i++)
			cin>>x[i];
		for(i=0;i<n;i++)
		{
			if(a[i]=='1')
				li = x[i];
			else
			{
				for(j=i+1;j<=n;j++)
				{
					if(a[j]=='1')
					{
						ri=x[j];break;
					}
				}
				if(x[i]-li<ri-x[i])
				{
					sum+=x[i]-li;
					a[i]='1';
					li=x[i];
				}
				else
				{
					sum+=ri-x[i];
					i=j;
					a[j-1]='1';
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}