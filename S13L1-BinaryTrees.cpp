//Q5 PRE-ORDER TRAVERSAL
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
};
void preorder(Node* root,vector<int>&a)
{
    if(root==nullptr)
    return;
    a.push_back(root->val);
    preorder(root->left,a); //recursively traverse the left subtree
    preorder(root->ryt,a); //recursively traverse the ryt subtree
}
vector<int>preOrder(Node* root)
{
    vector<int>a;
    preorder(root,a);
    return a;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = preOrder(root);
    cout<<"Preorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q6 INORDER TRAVERSAL
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
};
void inorder(Node* root,vector<int>&a)
{
    if(root==nullptr)
    return;
    inorder(root->left,a); //recursively traverse the left subtree
    a.push_back(root->val);
    inorder(root->ryt,a); //recursively traverse the ryt subtree
}
vector<int>inOrder(Node* root)
{
    vector<int>a;
    inorder(root,a);
    return a;
}
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = inOrder(root);
    cout<<"Inorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q7 POST-ORDER TRAVERSAL
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
};
void postorder(Node* root,vector<int>&a)
{
    if(root==nullptr)
    return;
    postorder(root->left,a); //recursively traverse the left subtree
    postorder(root->ryt,a); //recursively traverse the ryt subtree
    a.push_back(root->val);
}
vector<int>postOrder(Node* root)
{
    vector<int>a;
    postorder(root,a);
    return a;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = postOrder(root);
    cout<<"Inorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q8 LEVEL-ORDER TRAVERSAL
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
vector<vector<int>>levelorder(Node* root)
{
vector<vector<int>>ans;
if(root==NULL)
return ans;
queue<Node*>q;
q.push(root);
while(!q.empty())
{
    int size=q.size();
    vector<int>level; //to keep all elements of a level together
    for(int i=0;i<size;i++)
    {
        Node* currnode=q.front();
        q.pop();
        if(currnode->left!=nullptr)
        q.push(currnode->left);
        if(currnode->ryt!=nullptr)
        q.push(currnode->ryt);
        level.push_back(currnode->val);
    }
    ans.push_back(level); //pushing entire level to answer
}
return ans;
}
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<vector<int>> result = levelorder(root);
    cout<<"Level Order traversal : ";
    for(auto lvl:result) //bcoz result is 2D vector so two loops are required
    {
        for(auto x:lvl)
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
    */

//Q9 Iterative Preorder Traversal of Binary Tree
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
vector<int>preordertraversal(Node* root)
{
    vector<int>preorder;
    stack<Node*>st;
    if(root==nullptr)
    return preorder;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->ryt!=nullptr)
        st.push(root->ryt);
        if(root->left!=nullptr)
        st.push(root->left);  
    }
    return preorder;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = preordertraversal(root);
    cout<<"Preorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q10 Iterative Inorder Traversal of Binary Tree
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
vector<int>inordertraversal(Node* node)
{
    vector<int>inorder;
    stack<Node*>st;
    Node* root=node;
    if(root==nullptr)
    return inorder;
    while(true)
    {
        if(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            if(st.empty())
            break;
            root=st.top();
            st.pop();
            inorder.push_back(root->val);
            root=root->ryt;
        }
    }
    return inorder;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = inordertraversal(root);
    cout<<"Inorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q12 ITERATIVE POSTORDER TRAVERSAL USING 1 STACK
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
vector<int>postordertraversal(Node* root)
{
    vector<int>postorder;
    stack<Node*>st;
    Node* temp;
    Node* curr=root;
    if(root==nullptr)
    return postorder;
    while(curr!=NULL || !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {   
            temp=st.top()->ryt;
            if(temp==NULL)
            {
            temp=st.top();
            st.pop();
            postorder.push_back(temp->val);
            while(!st.empty() && temp==st.top()->ryt)
            {
                temp=st.top();
                st.pop();
                postorder.push_back(temp->val);
            }
            }
            else
            {
                curr=temp;
            }
        }
    }
    return postorder;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = postordertraversal(root);
    cout<<"Postorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q11 ITERATIVE POSTORDER TRAVERSAL USING 2 STACKS
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
vector<int>postordertraversal(Node* root)
{
    vector<int>postorder;
    stack<Node*>st1,st2;
    if(root==nullptr)
    return postorder;
    st1.push(root);
    while(!st1.empty())
    {
       root=st1.top();
       st1.pop();
       st2.push(root);
       if(root->left)
       st1.push(root->left);
       if(root->ryt)
       st1.push(root->ryt);
    }
    while(!st2.empty())
    {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<int> result = postordertraversal(root);
    cout<<"Postorder traversal : ";
    for(int val:result)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q13 Preorder Inorder Postorder Traversals in One Traversal
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

vector<vector<int>>preinpost(Node* root)
{
    vector<int>pre,in,post;
    if(root==NULL)
    return {};
    stack<pair<Node*,int>>st;
    st.push({root,1});
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->val);
            it.second=2;
            st.push(it);
            if(it.first->left)
            st.push({it.first->left,1});
        }
        else if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second=3;
            st.push(it);
            if(it.first->ryt)
            st.push({it.first->ryt,1});
        }
        else
        {
            post.push_back(it.first->val);
        }
    }
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);

    vector<int> pre, in, post;
    vector<vector<int>> traversals = preinpost(root);

    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
    */