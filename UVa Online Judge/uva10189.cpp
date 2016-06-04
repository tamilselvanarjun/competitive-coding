//Minesweeper
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m,count=1,**result;
	while(true) {

		cin>>n>>m;
		if(n==0 and m==0)
			break;
		if(count-1)
			cout<<"\n";
		
		result = new int*[n];
		for(int i=0;i<n;i++) {
			result[i] = new int[m];	
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				char temp;
				cin>>temp;
				if(temp=='.')
					result[i][j] = 0;
				else if(temp=='*')
					result[i][j] = -100;
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {			//check all elements
				//if mine is present
				if(result[i][j]==-100) {
					for(int x = i-1;x<=i+1;x++) {
						for(int y=j-1;y<=j+1;y++) {
							if((x>=0 and x<n) and (y>=0 and y<m)) {			//valid positions
								if(!(x==i and y==j) and result[x][y]!=-100)
									result[x][y]++;
							}
						}
					}
				}
			}
		}
		//Print
		printf("Field #%d:\n",count);
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(result[i][j]==-100)
					cout<<"*";
				else
					cout<<result[i][j];
			}
			cout<<endl;
		}
		count++;
	}
}