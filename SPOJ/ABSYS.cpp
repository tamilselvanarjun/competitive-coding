#include <bits/stdc++.h>
using namespace std;

void getValues(int& a,int& b, int& c, string inp) {
	int indices[] = {0,0,0,0};
	int ctr = 0, length = inp.size();
	for(int i=0;i<length;i++) {
		if(inp[i]==' ') {
			indices[ctr] = i;
			ctr++;
		}
	}
	a=b=c=0;
	for(int i=0;i<indices[0];i++) {
		if(inp[i]>='0' and inp[i]<='9') 
			a = a*10 + inp[i]-'0';
		else {
			a = -1; break;
		}
	}
	for(int i=indices[1]+1;i<indices[2];i++) {
		if(inp[i]>='0' and inp[i]<='9') 
			b = b*10 + inp[i]-'0';
		else {
			b = -1; break;
		}	
	}
	for(int i=indices[3]+1;i<length;i++) {
		if(inp[i]>='0' and inp[i]<='9') 
			c = c*10 + inp[i]-'0';
		else {
			c = -1; break;
		}
	}
	if(a==-1) a=c-b;
	else if(b==-1) b = c-a;
	else if(c==-1) c = a+b;

}

int main() {
	int t,a,b,c,h;
	string inp;
	h = scanf("%d\n",&t);
	for(int i=0;i<t;i++) {
		do {
			getline(cin,inp);
		}while(inp.size()==0);
		getValues(a,b,c,inp);
		printf("%d + %d = %d\n",a,b,c);
	}
}
//AC