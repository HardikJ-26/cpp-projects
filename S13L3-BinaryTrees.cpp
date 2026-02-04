//Q1 Print Root to Node Path
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};

bool getpath(Node* root,vector<int> &res,int target)
{
if(!root)
return false;
res.push_back(root->val);
if(root->val==target)
return true;
if(getpath(root->left,res,target) || getpath(root->right,res,target))
return true;
res.pop_back();
return false;
}
vector<int>printnodes(Node* root,int target)
{
vector<int>a;
if(root==NULL)
return a;
getpath(root,a,target);
return a;
}
int main() 
{
    // Creating the binary tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Value of the target node
    int targetLeafValue = 7;

    // Get the path from root to the target node
    vector<int> path = printnodes(root, targetLeafValue);

    // Print the path
    cout << "Path from root to node with value ";
    cout << targetLeafValue << ": ";

    for (int i = 0; i < path.size(); ++i) 
    {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    return 0;
}
//TC/SC-O(N)
    */

//Q2 LOWEST COMMON ANCESTOR
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
Node* lowestcommonancestor(Node* root,Node* p,Node* q)
{   
    Node* res;
    if(!root || root==p || root==q)
    return root;
    Node* left=lowestcommonancestor(root->left,p,q);
    Node* right=lowestcommonancestor(root->right,p,q);
    if(left == NULL) 
    {
        return right;
    }
    else if(right == NULL) {
        return left;
    }
    else 
    { //both left and right are not null, we found our result
        return root;
    }
}
int main() 
{
    // Creating the binary tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Value of the target node
    Node* p = root->left->left;Node* q=root->left->right;
    // Print the path
    cout << "Lowest Common Ancestor : "<<lowestcommonancestor(root,p,q)->val<<endl;
    return 0;
}
//TC/SC-O(N)
    */

//Q3 MAMIMUM WIDTH OF BT
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
int widthofbt(Node* root)
{
    int maxwidth=0;
    if(!root)
    return maxwidth;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int qsize=q.size(); 
        int minindex=q.front().second;
        int first,last=0;
        for(int i=0;i<qsize;i++)
        {
            int currindex=q.front().second-minindex;
            Node* node=q.front().first;
            q.pop();
            if(i==0)
            first=currindex;
            if(i==qsize-1)
            last=currindex;
            if(node->left)
            q.push({node->left,2*currindex+1});
            if(node->right)
            q.push({node->right,2*currindex+2});
        }
        maxwidth=max(maxwidth,(last-first+1));
    }
    return maxwidth;
}
int main() {

    // Create a sample tree
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    // Call the function and print the result
    cout << "Maximum width: " << widthofbt(root) << endl;

    return 0;
}
    */

//Q4 CHILDREN SUM PROPERTY
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
void converttree(Node* root)
{
    if(root==NULL)
    return;
    int child=0;
    if(root->left)
    child+=root->left->val;
    if(root->right)
    child+=root->right->val;
    if(child>=root->val)
    root->val=child;
    else
    {
        if(root->left)
        root->left->val=root->val;
        else if(root->right)
        root->right->val=root->val;
    }
    converttree(root->left);
    converttree(root->right);
    int tot=0;
    if(root->left)
    tot+=root->left->val;
    if(root->right)
    tot+=root->right->val;
    if(root->left || root->right)
    root->val=tot;
}
void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }
}
int main() 
{
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    cout << "Original tree (In-order): " << endl;
    printLevelOrder(root);
    cout << endl;

    // Run the conversion
    converttree(root);

    cout << "\nTree with children sum property (In-order): " << endl;
    printLevelOrder(root);
    cout << endl;
    
    return 0;
}
//TC/SC-O(N)
*/

//Q5 PRINT ALL THE NODES AT A DISTANCE K FROM THE TARGET
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
void getparentnodes(Node* root,unordered_map<Node*,Node*>&parentmap)
{
queue<Node*>q;
q.push(root);
while(!q.empty())
{
    Node* currnode=q.front();
    q.pop();
    if(currnode->left)
    {   
        parentmap[currnode->left]=currnode;
        q.push(currnode->left);
    }
    if(currnode->right)
    {   
        parentmap[currnode->right]=currnode;
        q.push(currnode->right);
    }
}
}
vector<int>bfstargetk(Node* target,unordered_map<Node*, Node*>& parentmap, int k)
{
    queue<Node*>q;
    unordered_set<Node*>visited;
    int currentlevel=0;
    q.push(target);
    visited.insert(target);
    while(!q.empty())
    {
        int qsize=q.size();
        if(currentlevel++==k)
        break;
        for(int i=0;i<qsize;i++)
        {
            Node* currnode=q.front();
            q.pop();
            if(currnode->left && visited.find(currnode->left)==visited.end())
            {
                visited.insert(currnode->left);
                q.push(currnode->left);
            }
            if(currnode->right && visited.find(currnode->right)==visited.end())
            {
                visited.insert(currnode->right);
                q.push(currnode->right);
            }
            if(parentmap.count(currnode) && visited.find(parentmap[currnode])==visited.end()) //count is used to map is empty or not
            {
                visited.insert(parentmap[currnode]);
                q.push(parentmap[currnode]);
            }
        }
    }
    vector<int>result;
    while(!q.empty())
    {
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
}
vector<int>distancek(Node* root,Node* target,int k)
{
    if(!root)
    return {};
    unordered_map<Node*,Node*>parentmap;
    getparentnodes(root,parentmap);
    return bfstargetk(target,parentmap,k);
}
int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

     // Node with value 5
    Node* target = root->left;
    int k = 2;

    vector<int> result = distancek(root, target, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
//TC/SC-O(N)
    */

//Q6 Minimum time taken to BURN the Binary Tree from a Node
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
void getparentnodes(Node* root,map<Node*,Node*>&parentmap)
{
queue<Node*>q;
q.push(root);
while(!q.empty())
{
    Node* currnode=q.front();
    q.pop();
    if(currnode->left)
    {   
        parentmap[currnode->left]=currnode;
        q.push(currnode->left);
    }
    if(currnode->right)
    {   
        parentmap[currnode->right]=currnode;
        q.push(currnode->right);
    }
}
}
int bfstargetk(Node* target,map<Node*, Node*>& parentmap)
{
    queue<Node*>q;
    map<Node*,int>visited; //can also use unordered set with insert,find and end like earlier
    q.push(target);
    int mini=0;
    visited[target]=1;
    while(!q.empty())
    {   
        int fl=0;
        int qsize=q.size();
        for(int i=0;i<qsize;i++)
        {
            Node* currnode=q.front();
            q.pop();
            if(currnode->left && !visited[currnode->left])
            {   
                fl=1;
                visited[currnode->left]=1;
                q.push(currnode->left);
            }
            if(currnode->right && !visited[currnode->right])
            {   
                fl=1;                                       
                visited[currnode->right]=1;
                q.push(currnode->right);
            }
            if(parentmap.count(currnode) && !visited[parentmap[currnode]]) //count is used to map is empty or not
            {   
                fl=1;
                visited[parentmap[currnode]]=1;
                q.push(parentmap[currnode]);
            }
        }
        if(fl)
        mini++;
    }
    return mini;
}
int burnk(Node* root,Node* target)
{
    if(!root)
    return {};
    map<Node*,Node*>parentmap;
    getparentnodes(root,parentmap);
    return bfstargetk(target,parentmap);
}
int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

     // Node with value 5
    Node* target = root->left;

    int result = burnk(root, target);
    cout<<"Time required to burn the binary tree is "<<result<<" seconds"<<endl;
    return 0;
}
//TC/SC-O(N)
    */

//Q7 COUNT NUMBER OF NODES
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
int findHeightLeft(Node* node) 
{
    int height = 0;
    // Traverse left child until
    // reaching the leftmost leaf
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}
    
// Function to find the right height of a tree
int findHeightRight(Node* node) 
{
    int height = 0;
    // Traverse right child until
    // reaching the rightmost leaf
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}
int countnodes(Node* root)
{
    if(!root)
    return 0;
    //using heights to check perfect binary tree condition
    int lh=findHeightLeft(root);
    int rh=findHeightRight(root);
    if(lh==rh)
    return (1 << lh)-1; //if nodes are equal  then 2^n-1  formula is used
    return 1+countnodes(root->left)+countnodes(root->right); //now going for complete binary tree
}
int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    // Call the countNodes function
    int totalNodes = countnodes(root);

    // Print the result
    cout << "Total number of nodes in the Complete Binary Tree: "<< totalNodes << endl;

    return 0;
}
//TC-O(logn*logn),SC-O(N)
*/

//Q9 CONSTRUCT BT WITH INORDER AND  PREORDER
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
Node* buildbt(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>inmap)
{
    if(prestart>preend || instart>inend)
    return NULL;
    Node* root=new Node(preorder[prestart]);
    int inroot=inmap[root->val];
    int numsleft=inroot-instart;
    root->left=buildbt(preorder,prestart+1,prestart+numsleft,inorder,instart,inroot-1,inmap);
    root->right=buildbt(preorder,prestart+numsleft+1,preend,inorder,inroot+1,inend,inmap);
    return root;
}
Node* mapping(vector<int>& preorder,vector<int>&inorder)
{
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++)
    {
        inMap[inorder[i]]=i;
    }
    Node* root=buildbt(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
}
void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}
int main() 
{
    vector<int>pre={3,9,6,20,15,7};
    vector<int>in={9,6,3,15,20,7};
    Node* root=mapping(pre,in);

    cout << "Tree built from preorder and inorder (Level-order):" << endl;
    printLevelOrder(root);
    return 0;
}
    */
//TC-O(logN * N),SC-O(N)

//Q10 CONSTRUCT BT WITH INORDER AND  POSTORDER
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
Node* buildbt(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend,map<int,int>inmap)
{
    if(poststart>postend || instart>inend)
    return NULL;
    Node* root=new Node(postorder[postend]);
    int inroot=inmap[root->val];
    int numsleft=inroot-instart;
    root->left=buildbt(postorder,poststart,poststart+numsleft-1,inorder,instart,inroot-1,inmap);
    root->right=buildbt(postorder,poststart+numsleft,postend-1,inorder,inroot+1,inend,inmap);
    return root;
}
Node* mapping(vector<int>& postorder,vector<int>&inorder)
{
    map<int,int>inMap;
    for(int i=0;i<inorder.size();i++)
    {
        inMap[inorder[i]]=i;
    }
    Node* root=buildbt(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
    return root;
}
void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl;
    }
}
int main() 
{
    vector<int> post = {6, 9, 15, 7, 20, 3};
    vector<int> in = {9, 6, 3, 15, 20, 7};
    Node* root=mapping(post,in);

    cout << "Tree built from postorder and inorder (Level-order):" << endl;
    printLevelOrder(root);
    return 0;
}
//TC-O(logN * N),SC-O(N)
    */

//Q11 SERIALIZE AND DESERIALIZE
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
string serialize(Node* root)
{
    if(!root)
    return "";
    string s="";
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* currnode=q.front();
        q.pop();
        if(currnode==NULL)
        s.append("#,");
        else
        {
            s.append(to_string(currnode->val)+",");
        }
        if(currnode!=NULL)
        {
            q.push(currnode->left);
            q.push(currnode->right);
        }
    }
    cout<<s;
    return s;
}
Node* deserialize(string data)
{
    if(data.empty())
    return NULL;
    string str;
    stringstream s(data);
    getline(s,str,',');
    Node* root=new Node(stoi(str));
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* currnode=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#")
        currnode->left=NULL;
        else
        {
            Node* leftnode=new Node(stoi(str));
            currnode->left=leftnode;
            q.push(leftnode);
        }
        getline(s,str,',');
        if(str=="#")
        currnode->right=NULL;
        else
        {
            Node* rightnode=new Node(stoi(str));
            currnode->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}
void printLevelOrder(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if(node == NULL) {
            cout << "# ";
            continue;
        }
        cout << node->val << " ";
        q.push(node->left);
        q.push(node->right);
    }
    cout << endl;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);

    cout << "Original tree (with nulls):" << endl;
    printLevelOrder(root);
    
    cout << "\nSerializing..." << endl;
    string serialized_data = serialize(root);
    cout << "Serialized string: " << serialized_data << endl;

    cout << "\nDeserializing..." << endl;
    Node* deserialized_root = deserialize(serialized_data);

    cout << "Deserialized tree (with nulls):" << endl;
    printLevelOrder(deserialized_root);

    return 0;
}
//TC-O(N),SC-O(N)
*/

//Q13 MORRIS INORDER TRAVERSAL
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
vector<int>getinorder(Node* root)
{
    vector<int>inorder;
    Node* currnode=root;
    while(currnode!=NULL)
    {
        if(currnode->left==NULL)
        {
        inorder.push_back(currnode->val);
        currnode=currnode->right;
        }
        else
        {
            Node* leftrightmost=currnode->left;
            while(leftrightmost->right && leftrightmost->right!=currnode)
            leftrightmost=leftrightmost->right;
            if(leftrightmost->right==NULL)
            {
            leftrightmost->right=currnode;
            currnode=currnode->left;
            }
            else
            {
                leftrightmost->right=NULL;
                inorder.push_back(currnode->val);
                currnode=currnode->right;
            }
        }
    }
    return inorder;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    
    vector<int> inorder = getinorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}
//TC-O(2N)/SC-O(1)
*/

//Q12 MORRIS PREORDER TRAVERSAL
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
vector<int>getpreorder(Node* root)
{
    vector<int>preorder;
    Node* currnode=root;
    while(currnode!=NULL)
    {
        if(currnode->left==NULL)
        {
        preorder.push_back(currnode->val);
        currnode=currnode->right;
        }
        else
        {
            Node* leftrightmost=currnode->left;
            while(leftrightmost->right && leftrightmost->right!=currnode)
            leftrightmost=leftrightmost->right;
            if(leftrightmost->right==NULL)
            {
            leftrightmost->right=currnode;
            preorder.push_back(currnode->val);
            currnode=currnode->left;
            }
            else
            {
                leftrightmost->right=NULL;
                currnode=currnode->right;
            }
        }
    }
    return preorder;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    
    vector<int> inorder = getpreorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for(int i = 0; i< inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}
//TC-O(2N)/SC-O(1)
*/

//Q13 FLATTEN BT INTO LL(USING MORRIS)
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int data)
{
    val=data;
    left=nullptr;
    right=nullptr;
}
Node(int data,Node* leftt,Node* rytt)
{
    val=data;
    left=leftt;
    right=rytt;
}
};
void flatten(Node* root)
{
    Node* curn=root;
    while(curn)
    {
        if(curn->left)
        {
            Node* leftrightmost=curn->left;
            while(leftrightmost->right)
            leftrightmost=leftrightmost->right;
            // Connect the rightmost node in the left subtree to the current node's right child
            leftrightmost->right=curn->right;
            // Move the entire left subtree to the right child of the current node
            curn->right=curn->left;
            // Set the left child of the current node to NULL
            curn->left=NULL;
        }
        // Move to the next node on the right side
        curn=curn->right;
    }
}
void printPreorder(Node* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the 
// Right Pointers after Flattening
void printFlattenTree(Node* root){
    if(!root){
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right->right = new Node(7);
    root->right->left = new Node(8);
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    return 0;
}
//TC-O(2N)/SC-O(1)
    */