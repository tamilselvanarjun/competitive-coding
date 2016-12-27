#include <iostream>
#include <cstdio>
using namespace std;

void printHanoi(int n, int src, int dest, int via) {
	if(n==2){
		printf("move 1 from %d to %d\n",src,via);
		printf("move 2 from %d to %d\n",src,dest);
		printf("move 1 from %d to %d\n",via,dest);
	}
	else {
		printHanoi(n-1,src,via,dest);
		printf("move %d from %d to %d\n",n,src,dest);
		printHanoi(n-1,via,dest,src);
	}
}


int main(int argc, char const *argv[])
{
	int n; cin>>n;
	printHanoi(n,1,3,2);
	return 0;
}