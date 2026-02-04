//Q2 SEARCHING A BST
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    ryt=rytt;
}
};
Node* searchbst(Node* root,int key)
{
    while(root!=NULL && root->val!=key)
    {
        root=(root->val>key) ? (root->left) : (root->ryt);
    }
    return root;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->ryt = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->ryt = new Node(4);
    root->left->ryt = new Node(6);
    root->left->ryt->ryt = new Node(9);
    root->ryt->left = new Node(11);
    root->ryt->ryt = new Node(14);

    int key;
    cout<<"Enter the value to be searched "<<endl;
    cin>>key;
    if(searchbst(root,key)!=NULL)
        cout<<"Key was found "<<endl;
    else
        cout<<"Key was not found "<<endl;
    return 0;
}
    */

//Q3 FINDING MAX/MIN IN BST
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* ryt;
Node(int data)
{
    val=data;
    left=nullptr;
    ryt=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    ryt=rytt;
}
};
// Returns the Node with the minimum value
Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL; // Tree is empty
    }
    
    // Keep moving left until you can't go any further
    while (root->left != NULL) {
        root = root->left;
    }
    return root; 
}
// Returns the Node with the maximum value
Node* findMax(Node* root) {
    if (root == NULL) {
        return NULL; // Tree is empty
    }
    
    // Keep moving right until you can't go any further
    // Assuming 'ryt' is the pointer for the right child
    while (root->ryt != NULL) { 
        root = root->ryt;
    }
    return root;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->ryt = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->ryt = new Node(4);
    root->left->ryt = new Node(6);
    root->left->ryt->ryt = new Node(9);
    root->ryt->left = new Node(11);
    root->ryt->ryt = new Node(14);

    int maxi,mini;
    maxi=findMax(root)->val;
    mini=findMin(root)->val;
    if(findMax(root)!=NULL)
        cout<<"Max element is "<<maxi<<endl;
    if(findMin(root)!=NULL)
        cout<<"Min element is "<<mini<<endl;
    return 0;
}
//TC-O(N)/SC-O(1)
    */
