/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/
int searchIndex(node *root , int v) {
	int index = 1;
	while(root!=NULL) {
		if(root->data == v)
			return index;
		else if (root->data < v) {
			root = root->right;
			index = 2*index+1;
		}
		else if(root->data > v) {
			root = root->left;
			index = 2*index;
		}
	}
	return -1;
}

node * lca(node * root, int v1,int v2)
{
	int i1,i2;
	node* start = root;
	i1 = searchIndex(root,v1);
	i2 = searchIndex(root,v2);
	while(i1!=i2) {
		if(i1 > i2)
			i1/=2;
		else
			i2/=2;
	}
	
	// we have the index, now we iterate through the tree to find the node
	string s = "";
	while(i2!=1) {
		if(i2%2==0)
			s ="0" + s;
		else
			s = "1" + s;
		i2/=2;
	}
	int len = s.length();
	for(int i=0;i<len;i++)
		if(s[i]=='0')
			start = start->left;
		else
			start = start->right;

	return start;
}

// AC