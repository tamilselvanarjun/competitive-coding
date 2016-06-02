#include <bits/stdc++.h>
using namespace std;
typedef long unsigned int ulong;

struct node {
	ulong key;
	node* left;
	node* right;

	node() {
		key = 0;
		left = right = NULL;
	}
};

void insert(ulong key, node* &root) {			//notice the syntax for passing pointer by reference
	if(root==NULL) {
		root = new node();
		root->key = key;
	}
	else if(key < root->key) {
		insert(key,root->left);
	}
	else if(key > root->key) {
		insert(key,root->right);
	}
}

string itos(ulong n) {
	string s = "";
	while(n) {
		s = char(48+(n%10)) + s;
		n/=10;
	}
	return s;
}

void print(node* &root) {
	if(root==NULL) {
		return;
	}
	else {
		cout<<root->key<<endl;
		print(root->left);
		print(root->right);
	}
} 
//working cool

void assignNumber(string &sum,node* &root, ulong index) {		//working cool
	if(root==NULL) {
		return;
	}
	else {
		sum = sum + itos(index);
		assignNumber(sum,root->left,index*2);
		assignNumber(sum,root->right,index*2+1);
	}
}

int main() {
	
	// //code here
	map<string, bool> map;
	int n,k;
	ulong temp;
	cin>>n>>k;
	node* tree;
	string sum;

	for(int i=0;i<n;i++) {
		tree = NULL;
		sum="";
		for(int j=0;j<k;j++) {
			cin>>temp;
			insert(temp,tree);
		}
		assignNumber(sum,tree,1);
		map[sum] = true;
	}
	cout<<map.size()<<endl;
}