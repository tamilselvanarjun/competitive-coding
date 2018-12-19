#include <bits/stdc++.h>
using namespace std;

bool condition(int xorval, int M) {
	return (xorval>=M);
}

struct segtree {
	int l,r;
	int xorval;
	segtree *left, *right;
};

segtree* createtree(int *arr, int l, int r) {
	
	if(l>r) {
		return NULL;
	}

	segtree *root = new segtree;
	root->l = l;
	root->r = r;
	if(l == r) {
		root->left = NULL;
		root->right = NULL;
		root->xorval = arr[l];
	}
	else {
		int mid = (l+r)/2;
		root->left = createtree(arr, l, mid);
		root->right = createtree(arr, mid+1, r);
		root->xorval = root->left->xorval^root->right->xorval;
	}

	return root;
}


int countVal(segtree *root, int l, int r, int m) {
	if(root == NULL)
		return -1;

	if(l < root->left or r > root->right)
		return -1;

	// corner case
	if(root->l == root->r) {
		if(root->xorval >= m)
			return 1;
		return 0;
	}

	

}


int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--) {
		int n,m,q;
		cin >> n >> m >> q;
		int *arr = new int[n];
		for(int i=0;i<n;i++)
			cin >> arr[i];
		segtree *tree = createtree(arr, 0, n-1);

		for(int i=0;i<q;i++) {
			int l, r;
			cin >> l >> r;
			cout << countVal(tree, l, r, m) << endl;			
		}


	}
	return 0;
}