//Q1 CEILING OF BST
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
int findceil(Node* root,int key)
{
    int ceil=-1;
    while(root)
    {
        if(root->val==key)
        {
            ceil=root->val;
            return ceil;
        }
        else if(key>root->val)
        {
            root=root->right;
        }
        else
        {
            ceil=root->val;
            root=root->left;
        }
    }
    return ceil;
}
void printinOrder(Node* root) 
{
    if (root == nullptr) 
    return;

    printinOrder(root->left);

    cout << root->val << " ";

    printinOrder(root->right);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree: "<< endl;
    printinOrder(root);
    cout << endl;
    
    // Searching for a value in the BST
    int target = 8;
    int ceil = findceil(root, target);
    
    if(ceil != -1){
        cout << "Ceiling of " << target << " is: " << ceil << endl;
    }
    else{
        cout << "No ceiling found!";
    }
    
    return 0;
}
//TC-O(logN),SC-O(1)
    */

//Q2 FLOOR OF BST
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
int findfloor(Node* root,int key)
{
    int floor=-1;
    while(root)
    {
        if(root->val==key)
        {
            floor=root->val;
            return floor;
        }
        else if(key>root->val)
        {
            floor=root->val;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return floor;
}
void printinOrder(Node* root) 
{
    if (root == nullptr) 
    return;

    printinOrder(root->left);

    cout << root->val << " ";

    printinOrder(root->right);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree: "<< endl;
    printinOrder(root);
    cout << endl;
    
    // Searching for a value in the BST
    int target = 8;
    int floor = findfloor(root, target);
    
    if(floor != -1){
        cout << "Floor of " << target << " is: " << floor << endl;
    }
    else{
        cout << "No Floor found!";
    }
    
    return 0;
}
//TC-O(logN),SC-O(1)
*/

//Q3 INSERT NODE IN BST
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
Node* insertbst(Node* root,int key)
{
    if(!root)
    return new Node(key);
    Node* curn=root;
    while(true)
    {
        if(curn->val<=key)
        {
            if(curn->right!=NULL)
            curn=curn->right;
            else
            {
                curn->right=new Node(key);
                break;
            }
        }
        else
        {
            if(curn->left!=NULL)
            curn=curn->left;
            else
            {
                curn->left=new Node(key);
                break;
            }
        }
    }
    return root;
}
void printinOrder(Node* root) 
{
    if (root == nullptr) 
    return;

    printinOrder(root->left);

    cout << root->val << " ";

    printinOrder(root->right);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree: "<< endl;
    printinOrder(root);
    cout << endl;
    
    // Searching for a value in the BST
    int target = 8;
    Node* ref=insertbst(root,target);
    
    cout << "Binary Search Tree after Insertion: "<< endl;
    printinOrder(ref);
    cout << endl;
    
    return 0;
}
//TC-O(logN),SC-O(1)
*/

//Q4 DELETION IN BST
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
Node* findlastright(Node* root)
{
    if(!root->right)
    return root;
    findlastright(root->right);
}
Node* helper(Node* root)
{
    if(root->left==NULL)
    return root->right;
    else if(root->right==NULL)
    return root->left;
    Node* rightchild=root->right;
    Node* lastright=findlastright(root->left);
    lastright->right=rightchild;
    return root->left;
}
Node*  deletenode(Node* root,int key)
{
if(!root)
return NULL;
if(root->val==key)
return helper(root);
Node* dummynode=root;
while(root!=NULL)
{
    if(root->val>key)
    {
        if(root->left!=NULL && root->left->val==key)
        {
        root->left=helper(root->left);
        break;
        }
        else
        {
           root=root->left; 
        }
    }
    else
    {
        if(root->right!=NULL && root->right->val==key)
        {
            root->right=helper(root->right);
            break;
        }
        else
        {
           root=root->right; 
        }
    }
}
return dummynode;
}
void printinOrder(Node* root) 
{
    if (root == nullptr) 
    return;

    printinOrder(root->left);

    cout << root->val << " ";

    printinOrder(root->right);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree: "<< endl;
    printinOrder(root);
    cout << endl;
    int key=6;
    root=deletenode(root,key);
    cout << "Binary Search Tree after deletion : "<< endl;
    printinOrder(root);
    cout << endl;
    return 0;
}
//TC-O(logN),SC-O(1)
*/

//Q5 KTH LARGEST AND KTH SMALLEST
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
void reverseinorder(Node* root,int &counter,int k,int &kthlargest)
{
if(!root || counter>=k)
return;
reverseinorder(root->right,counter,k,kthlargest);
counter++;
if(counter==k)
{
    kthlargest=root->val;
    return;
}
reverseinorder(root->left,counter,k,kthlargest);
}
void inorder(Node* root,int &counter,int k,int &kthsmallest)
{
if(!root || counter>=k)
return;
inorder(root->left,counter,k,kthsmallest);
counter++;
if(counter==k)
{
    kthsmallest=root->val;
    return;
}
inorder(root->right,counter,k,kthsmallest);
}
pair<int, int> findKth(Node* root, int k) 
{
    int kSmallest = INT_MIN, kLargest = INT_MIN;
    // Counter to track visited nodes
    int counter = 0; 

    // Find Kth smallest element
    // (perform inorder traversal)
    inorder(root, counter, k, kSmallest);
    
    // Reset counter for Kth largest element
    counter = 0; 
    // Find Kth largest element
    // (perform reverse inorder traversal)
    reverseinorder(root, counter, k, kLargest);

    return make_pair(kSmallest, kLargest);
}

void printInOrder(Node* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;
    

    // Find the Kth smallest and largest elements
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q6 CHECK IF TREE IS BT OR BST
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
bool isvalidbst(Node* root,int min,int max)
{
    if(!root)
    return true;
    if(root->val>=max || root->val<=min)
    return false;
    return isvalidbst(root->left,min,root->val) && isvalidbst(root->right,root->val,max); 
    //bcause we update interval acc to val while going left and ryt
}
bool isbst(Node* root)
{
    return isvalidbst(root,INT_MIN,INT_MAX);
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    cout << "Binary Search Tree is Valid : "<<isbst(root)<< endl;

    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q7 LOWEST COMMON ANCESTOR
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
Node* lca(Node* root,Node* p,Node*  q)
{   
    if(!root)
    return NULL;
    int curn=root->val;
    if(curn<p->val && curn<q->val)
    return lca(root->right,p,q);
    if(curn>p->val && curn>q->val)
    return lca(root->left,p,q);
    return root;
}
int main() 
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);
    
    Node* p=root->left->left;Node* q=root->left->right;
    Node* ans=lca(root,p,q);
    cout << "Lowest Common Ancestor for the numebers is : "<<ans->val<< endl;

    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q8 CONSTRUCT BST FROM PREORDER TRAVERSAL
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
Node* build(vector<int>&a,int &i,int bound)
{
    if(i==a.size() || a[i]>bound)
    return NULL;
    Node* root=new Node(a[i++]);
    root->left=build(a,i,root->val);
    root->right=build(a,i,bound);
}
Node* bstpreorder(vector<int>&a)
{
    int i=0;
    return build(a,i,INT_MAX);
}
void printInOrder(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    printInOrder(root->left);

    cout << root->val << " ";
    printInOrder(root->right);
}
int main() 
{
    vector<int> preorder_data = {8, 5, 1, 7, 10, 12};

    cout << "--- BST Construction from Preorder Traversal ---\n";
    cout << "Given Preorder Sequence: ";
    for (size_t i = 0; i < preorder_data.size(); ++i) 
    {
        cout << preorder_data[i] << (i == preorder_data.size() - 1 ? "" : ", ");
    }
    cout<<endl;
    Node* root=bstpreorder(preorder_data);
    printInOrder(root);
    return 0;
}
*/

//Q9 PREDECESSOR AND SUCCESSOR
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
Node* insuccessor(Node* root,Node* key)
{
    Node* successor=nullptr;
    while(root)
    {
        if(key->val>=root->val)
        root=root->right;
        else
        {
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
Node* inpredecessor(Node* root,Node* key)
{
    Node* predecessor=nullptr;
    while(root)
    {
        if(key->val>root->val)
        {
        predecessor=root;
        root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return predecessor;
}
void printInOrder(Node* root) 
{
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() 
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    Node* p = root->left->right;

    Node* successor = insuccessor(root, p);
    Node* predecessor=inpredecessor(root,p);

    if (successor != nullptr) 
    {
        cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    } 
    else 
    {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }
    if (successor != nullptr) 
    {
        cout << "Inorder Predecessor of " << p->val << " is: " << predecessor->val << endl;
    } 
    else 
    {
        cout << "Inorder Predecessor of " << p->val << " does not exist." << endl;
    }
    return 0;
}
//TC-O(N)/SC-O(1)
    */

//Q10 MERGE 2 BST'S
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
void inordertvs(Node* root,vector<int>&a)
{
    if(!root)
    return;
    inordertvs(root->left,a);
    a.push_back(root->val);
    inordertvs(root->right,a);
}
vector<int>mergearrays(vector<int>&a1,vector<int>&a2)
{
    vector<int>merged;
    int i=0,j=0;
    while(i<a1.size() && j<a2.size())
    {
        if(a1[i]<a2[j])
        merged.push_back(a1[i++]);
        else
        merged.push_back(a2[j++]);
    }
    while(i<a1.size())
    merged.push_back(a1[i++]);
    while(j<a2.size())
    merged.push_back(a2[j++]);
    return merged;
}
vector<int>mergebsts(Node* root1,Node* root2)
{
    vector<int>a1,a2;
    inordertvs(root1,a1);
    inordertvs(root2,a2);
    return mergearrays(a1,a2);
}
int main() 
{
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    vector<int> result = mergebsts(root1, root2);

    for (int val : result) cout << val << " ";
    return 0;
}
//TC/SC-O(n)
*/

//Q11 TWO SUM'S IN BSTS
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
class BSTiterator
{
stack<Node*>mystack;
bool reverse;
public:
BSTiterator(Node* root,bool isreverse) : reverse(isreverse)
{
    pushall(root);
}
bool hasnext()
{
    return !mystack.empty();
}
int next() //used to get the smallest and largest element
{
    Node* tempnode=mystack.top();
    mystack.pop();
    if(!reverse) 
    {
        pushall(tempnode->right); //to get to largest
    }
    else
    {
        pushall(tempnode->left); //to get to smallest
    }
    return tempnode->val;
}
void pushall(Node* node)
{
    while(node!=nullptr)
    {
        mystack.push(node);
        if(reverse)
        {
            node=node->right;
        }
        else
        {
            node=node->left;
        }
    }
}
};
class Solution
{
public:
bool findTarget(Node* root,int k)
{
if(!root)
return false;
BSTiterator l(root,false);
BSTiterator r(root,true);
int i=l.next();
int j=r.next();
while(i<j)
{
    if(i+j==k)
    return true;
    else if(i+j<k)
    {
        i=l.next();
    }
    else
    {
        j=r.next();
    }
}
return false;
}
};
void printInOrder(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}


int main() 
{
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    cout << "Tree Initialized: ";
    printInOrder(root);
    cout << endl;

    Solution solution;
    int target = 22;
    bool exists = solution.findTarget(root, target);
    if (exists) {
        cout << "Pair with sum " << target << " exists." << endl;
    } else {
        cout << "Pair with sum " << target << " does not exist." << endl;
    }

    return 0;
}
//TC/SC-O(N)
*/

//Q12 RECOVER BST AFTER TWO NODES ARE SWAPPED
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
class Solution
{
Node* first;
Node* last;
Node* middle;
Node* prev;
void inordertvs(Node* root)
{   
    if(!root)
    return;
    inordertvs(root->left);
    if(prev!=NULL && root->val<prev->val)
    {
        if(first==NULL)
        {
            first=prev;
            middle=root;
        }
        else
        {
            last=root;
        }
    }
    prev=root;
    inordertvs(root->right);
}
public:
void recovertree(Node* root)
{
    first=last=middle=NULL;
    prev=new Node(INT_MIN);
    inordertvs(root);
    if(first && last)
    swap(first->val,last->val);
    else if(first && middle)
    swap(first->val,middle->val);
}
};
void inorderPrint(Node* root) {
    if (root == nullptr) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    
    cout << "--- Test Case 1: Non-adjacent nodes swapped (5 and 20) ---" << endl;
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);
    root1->left->left = new Node(3);
    root1->left->right = new Node(8);
    root1->right->left = new Node(15);
    root1->right->right = new Node(25);

    swap(root1->left->val, root1->right->val);

    cout << "Broken Inorder:   ";
    inorderPrint(root1);
    cout << endl;

    Solution sol1;
    sol1.recovertree(root1);

    cout << "Recovered Inorder: ";
    inorderPrint(root1);
    cout << "\n" << endl;

    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q13 LARGEST BST IN A BT
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
class Solution
{
    public:
    int minnode,maxnode,maxsize;
    Solution(int minnode1,int maxnode1,int maxsize1)
    {
        minnode=minnode1;
        maxnode=maxnode1;
        maxsize=maxsize1;
    }
};
class Helper
{
Solution largestbstsubtreehelper(Node* root)
{
    if(!root)
    return Solution(INT_MAX,INT_MIN,0);
    auto left=largestbstsubtreehelper(root->left);
    auto right=largestbstsubtreehelper(root->right);
    if(left.maxnode<root->val  && root->val<right.minnode)
    return Solution(min(root->val,left.minnode),max(root->val,right.maxnode),1+left.maxsize+right.maxsize);
    return Solution(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
}
public:
int largestbstsubtree(Node* root)
{
return largestbstsubtreehelper(root).maxsize;
}
};
int main() 
{
    
    Node* root2 = new Node(50);
    root2->left = new Node(30);
    root2->right = new Node(60);
    root2->left->left = new Node(5);
    root2->left->right = new Node(65); 
    root2->right->left = new Node(45); 
    root2->right->right = new Node(70); 

    Helper h;
    int maxSize2 = h.largestbstsubtree(root2);
    
    cout << "The size of the largest BST is: " << maxSize2 << endl;
    return 0;
}
//TC-O(N)/SC-O(1)
*/

//EQ FINDING UNIQUE BSTs
/*
#include <bits/stdc++.h>
using namespace std;

struct Node
{
int val;
Node* left;
Node* right;
Node(int x)
{
    val=x;
    left=nullptr;
    right=nullptr;
}
};

vector<Node*> generatetree(int start,int end)
{
    if(start>end)
    {
        return {nullptr};
    }
    
    vector<Node*> result;

    for(int i=start;i<=end;++i)
    {
        vector<Node*> leftSubtrees=generatetree(start,i-1);
        vector<Node*> rightSubtrees=generatetree(i+1,end);

        for(Node* leftRoot:leftSubtrees)
        {
            for(Node* rightRoot:rightSubtrees)
            {
                Node* root=new Node(i);
                root->left=leftRoot;
                root->right=rightRoot;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<Node*> generateTrees(int n)
{
    if(n==0)
    {
        return {};
    }
    return generatetree(1,n);
}
void printTree(Node* root)
{
    if(root==nullptr)
    {
        cout<<"null";
        return;
    }
    cout<<root->val;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    int n=3;
    vector<Node*> trees=generateTrees(n);
    
    cout<<"Generated Trees are:"<<endl;
    for(Node* tree:trees)
    {
        printTree(tree);
        cout<<endl;
    }
    return 0;
}
//TC/SC-O(n)
*/