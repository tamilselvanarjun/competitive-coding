#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t,len,tmpIndex;
	string word;
	int* nextIndex;
	stack<int> A;
	bool exists;

	cin>>t;
	for(int i=0;i<t;i++) {

		exists = false;
		cin>>word;
		len = word.length();
		nextIndex = new int[len];
		
		for(int j=0;j<len;j++)			//init all NI = -1
			nextIndex[j] = -1;

		for(int j=0;j<len;j++) {		// next greater element algo
			
			while(!A.empty()) {
				if(word[A.top()] >= word[j])
					break;
				else {
					tmpIndex = A.top();
					A.pop();
					// cout<<word[tmpIndex]<<" popped.\n";
					nextIndex[tmpIndex] = j;
					exists = true;
				}
			}

			A.push(j);
			// cout<<word[j]<<" pushed.\n";
		}

		for(int j=0;j<len;j++)
			cout<<nextIndex[j]<<" ";
		cout<<endl;

		if(!exists)
			cout<<"no answer\n";
		else {
			for(int j=len-1;j>=0;j--)
				if(nextIndex[j]!=-1) {
					char tmpChar = word[j];
					word[j] = word[nextIndex[j]];
					word[nextIndex[j]] = tmpChar;
					break;
				}
			cout<<word<<endl;
		}

		delete[] nextIndex;
	}	


}



/////////////////////////////////////
/////PENDING
/////////////////////////////////////
