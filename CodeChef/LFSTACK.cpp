//AC
#include <bits/stdc++.h>
using namespace std;

// store the sequence
uint *sequence;
// store the maxIndices and numbers
uint **numbers;
uint *maxIndices, *indices;
uint sum;

bool backtrack(vector<uint> *threadNumbers, int sequenceIndex) {

	if(sequenceIndex == sum)
		return true;

	uint nSeq = sequence[sequenceIndex];

	for(int i=0; i<threadNumbers[nSeq].size(); i++) {
		/// get a thread number from the available ones
		uint threadNo = threadNumbers[nSeq][i];
		threadNumbers[nSeq].erase(threadNumbers[nSeq].begin() + i);

		/// Also, update the new index
		indices[threadNo]+=1;
		if(indices[threadNo] < maxIndices[threadNo])
			threadNumbers[numbers[threadNo][indices[threadNo]]].push_back(threadNo);

		bool found = backtrack(threadNumbers, sequenceIndex+1);
		if(found)
			return true;

		// set it back to the value, pop the index from threads number
		if(indices[threadNo] < maxIndices[threadNo])
			threadNumbers[numbers[threadNo][indices[threadNo]]].pop_back();
		indices[threadNo]-=1;
		threadNumbers[nSeq].insert(threadNumbers[nSeq].begin() + i, threadNo);

	}
	return false;
}


int main(int argc, char const *argv[])
{
	int t, n; 
	cin >> t;
	while(t--) {
		// do this for all
		sum = 0;
		int nThreads;
		cin >> nThreads;
		numbers = new uint*[nThreads];
		maxIndices = new uint[nThreads];

		for(int i=0; i<nThreads; i++) {
			cin >> n;
			maxIndices[i] = n;
			sum += n;
			numbers[i] = new uint[n];
			for(int j=n-1;j>=0;j--)
				cin >> numbers[i][j];
		}

		sequence = new uint[sum];
		for(int i=0; i<sum; i++)
			cin >> sequence[i];

		indices = new uint[nThreads];
		for(int i=0;i<nThreads;i++)
			indices[i] = 0;

		vector<uint> *threadNumbers = new vector<uint>[1001];
		for(int i=0; i<nThreads; i++) {
			threadNumbers[numbers[i][0]].push_back(i);
		}


		bool isFound = backtrack(threadNumbers, 0);

		if(isFound)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		for(int i=0;i<nThreads;i++)
			delete[] numbers[i];
		delete[] sequence, maxIndices, indices, numbers, threadNumbers;
	}
	return 0;
}