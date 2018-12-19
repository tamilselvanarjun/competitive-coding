#include <bits/stdc++.h>
using namespace std;

typedef struct RadixTree
{
	uint lo, hi;
	struct RadixTree** nodes;

	RadixTree() {
		nodes = new RadixTree*[26];
		for(int i=0;i<26;i++)
			nodes[i] = NULL;
	}

} RadixTree;

RadixTree *tree;

// add string
void addStringToTree(RadixTree *tr, string str, uint index, uint strindex) {
	if(strindex == str.size())
		return;

	if(tr->nodes + (int)(str[strindex]-'a')) {
		tr->nodes + (int)(str[strindex]-'a') = new RadixTree;
		(tr->nodes + (int)(str[strindex]-'a'))->lo = index;
		(tr->nodes + (int)(str[strindex]-'a'))->hi = index;
	}
	addStringToTree(tr->nodes + (int)(str[strindex]-'a'), str, index, strindex+1);
	tr->lo = min(tr->lo, index);
	tr->hi = max(tr->hi, index);
}



// Query
void query(RadixTree *tr, string s, uint R) {
	uint index = 0;

	while(true) {
		if(tr == NULL)
			break;

		// stops here
		if(tr->nodes + (int)(s[index]-'a') == NULL) {

		}

	}
}



int main(int argc, char const *argv[])
{
	uint n, Q;
	string s;
	tree = new RadixTree;
	cin >> n;
	for(uint i=0; i<n; i++) {
		cin >> s;
		addStringToTree(tree, s, i, 0);
	}

	cin >> Q;
	for(uint i=0; i<Q; i++) {
		uint R;
		cin >> R >> s;
		query(tree, s, R);
	}

	return 0;
}