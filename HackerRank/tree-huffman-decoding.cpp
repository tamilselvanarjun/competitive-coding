/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    string res = "";
    node *start = root;
    int index = 0, len = s.length();
    while(index < len) {

    	if(s[index]=='0') {		//move left
    		start = start->left;
            if(start->left==NULL and start->right==NULL) {		//add it
    			res += start->data;
    			start->freq--;
    			start = root;
    		}
    	}
    	else if(s[index]=='1'){		//move right
    		start = start->right;
            if(start->right==NULL and start->left==NULL) {		//add it
    			res += start->data;
    			start->freq--;
    			start = root;
    		}
    	}
    	else {
    		cout<<"Error\n";
    	}

    	index++;
    }

    cout<<res<<endl;
}


//AC