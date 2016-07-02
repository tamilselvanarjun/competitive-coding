#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,xored;
	int h = scanf("%d\n",&t);
	for (int ai = 0; ai < t; ++ai)
	{
		int n,k;
		int count=0;
		int *res[4];
		h = scanf("%d %d\n",&n,&k);
		
		for (int temp = 0; temp < 4; ++temp)
			res[temp] = new int[n];

		for (int aj = 0; aj < 4; ++aj)
		{
			for(int ak=0;ak<n;ak++) {
				cin>>res[aj][ak];
			}
		}

		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int k=0;k<n;k++) {
					for(int l=0;l<n;l++) {
						if(i==j or j==k or k==l or l==i)
							continue;
						xored = res[0][i]^res[1][j]^res[2][k]^res[3][l];
						if (xored==k)
							count++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",ai+1,count);
	}
	return 0;
}

///// WA
