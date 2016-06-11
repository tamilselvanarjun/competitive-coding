//runtime error
#include <bits/stdc++.h>
using namespace std;

int binS(int *v,int el, int size, bool* &unused) {
	int l=0, r = size-1, mid;
	while(l<=r) {
		mid = (l+r)/2;
		if(v[mid]==el) {
			if(unused[mid]) {
				unused[mid] = unused[size-mid-1] = false;
				return mid;
			}
			else
				return -1;
		}
		else if(v[mid] < el)
			l = mid+1;
		else
			r = mid-1;
	}
	return -1;
}

int main() {
	int c,s,*mass,*sortmass,ctr=1;
	bool *unused;
	float avg,imbalance;
	while(cin>>c>>s) {
		if(ctr!=1)
			cout<<"\n";
		imbalance = avg = 0;
		mass = new int[2*c];
		sortmass = new int[2*c];
		unused = new bool[2*c];
		memset(mass,0,sizeof(int)*2*c);
		memset(sortmass,0,sizeof(int)*2*c);
		memset(unused,true,sizeof(int)*2*c);
		for(int i=0;i<s;i++) {
			cin>>mass[i];
			avg+=mass[i];	
			sortmass[i]= mass[i];
		}
		sort(sortmass,sortmass+2*c);
		avg/=c;
		cout<<"Set #"<<ctr<<endl;
		int count = 0;
		for(int i=0;i<s;i++) {
			
			int index = binS(sortmass,mass[i],2*c, unused);
			if(index==-1) continue;
			cout<<count<<": "<<sortmass[index];
			if(sortmass[2*c-index-1]!=0)
				cout<<" "<<sortmass[2*c-index-1]<<endl;
			else
				cout<<endl;
			imbalance += abs(sortmass[index]+sortmass[2*c-index-1]-avg);
			count++;
		}
		printf("IMBALANCE = %.5f\n",imbalance);
		delete[] mass,sortmass,unused;
		ctr++;				
	}
}