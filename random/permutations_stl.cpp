// Permutations 
#include <bits/stdc++.h>
#define N 5
using namespace std;
int main() {
	int ctr =1;
	int v[N];

	for(int i=0;i<N;i++) {
		v[i] = i+1;
	}

	for(int i=0;i<N;i++) {
		printf("%d ",v[i]);
	}
	printf("%s\n","");

	do {
		printf("Permutation #%d - ",ctr);
		for(int i=0;i<N;i++) {
			printf("%d ",v[i]);
		}
		printf("%s\n","");
		ctr++;
	}
	while(next_permutation(v,v+N));				//permutations of array, find permutation of vector
}