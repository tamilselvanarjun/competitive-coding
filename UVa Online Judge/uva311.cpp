#include <bits/stdc++.h>
using namespace std;

int main() {
	int packets[7]; packets[0] = 0;
	while(true) {
		long int sum = 0;
		for(int i=1;i<7;i++) {
			cin>>packets[i];
			sum+=packets[i];
		}
		if(sum==0)
			break;
		int box = 0;
		box = packets[4] + packets[5] + packets[6];
		packets[1] -= 11*packets[5];		// 11 packets for each 5X5
		packets[2] -= 5*packets[4];			// 5 packets for each 4X4
		box+= (packets[3]/4);
		if(packets[3]%4) box++;
		switch(packets[3]%4) {
			case 0: break;
			case 1: packets[2] -= 5;
					packets[1] -= 7;
					break;
			case 2: packets[2] -= 3;
					packets[1] -= 6;
					break;
			case 3: packets[2] -= 1;
					packets[1] -= 5;
		}
		if(packets[2] > 0) {
			box+= packets[2]/9;
			if(packets[2]%9) box++;
			packets[1] -= (36-4*(packets[2]%9));
		}
		else if(packets[2] < 0) {
			packets[1] -= (-packets[2]*4);
		}
		if(packets[1]>0) {
			box += (packets[1]/36);
			if(packets[1]%36) box++;
		}

		cout<<box<<endl;
	}
}