//Q1 MAXIMUM DEPTH/HEIGHT OF BT
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
int maxdepth(Node* root)
{
    if(root==NULL)
    return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->ryt);
    return 1+max(lh,rh);
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    root->left->ryt->ryt = new Node(6);
    root->left->ryt->ryt->ryt = new Node(7);
    
    int depth = maxdepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q2 CHECK IF A TREE IS BALANCED OR NOT
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
int maxdepth(Node* root)
{
    if(root==NULL)
    return 0;
    int lh=maxdepth(root->left);
    if(lh==-1)
    return -1;
    int rh=maxdepth(root->ryt);
    if(rh==-1)
    return -1;
    if(abs(lh-rh)>1)
    return -1;
    return 1+max(lh,rh);
}
bool isBalanced(Node* root)
{
    return maxdepth(root) !=-1;
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    root->left->ryt->ryt = new Node(6);
    root->left->ryt->ryt->ryt = new Node(7);
    
    bool ans = isBalanced(root);
    cout << ans << endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q3 Diameter of BT
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
int getheight(Node* root,int &dia)
{
if(!root)
return 0;
int lh=getheight(root->left,dia);
int rh=getheight(root->ryt,dia);
dia=max(dia,lh+rh);
return 1+(lh+rh);
}
int diameterofbt(Node* root)
{
    int diameter=0;
    getheight(root,diameter);
    return diameter;
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    root->left->ryt->ryt = new Node(6);
    root->left->ryt->ryt->ryt = new Node(7);
    
    int diameter = diameterofbt(root);
    cout << "Maximum diameter of the binary tree: " << diameter << endl;
    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q6 ZIG-ZAG TRAVERSAL
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
vector<vector<int>>bfszig(Node* root)
{
vector<vector<int>>result;
if(root==NULL)
return result;
queue<Node*>q;
q.push(root);
bool lefttoryt=true;
while(!q.empty())
{
    int size=q.size();
    vector<int>level(size);
    for(int i=0;i<size;i++)
    {
        Node* current=q.front();
        q.pop();
        int index=(lefttoryt)? i : size-i-1;
        level[index]=current->val;
        if(current->left)
        q.push(current->left);
        if(current->ryt)
        q.push(current->ryt);

    }
    lefttoryt=!lefttoryt;
    result.push_back(level);
}
return result;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    vector<vector<int>> result = bfszig(root);
    cout<<"Zig-Zag Order traversal : ";
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

//Q5 IDENTICAL TREES??
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
bool isSametrees(Node* root1,Node* root2)
{
    if(root1==NULL || root2==NULL)
    return (root1==root2);
    return (root1->val==root2->val && isSametrees(root1->left,root2->left) && isSametrees(root1->ryt,root2->ryt));
} 
int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->ryt = new Node(3);
    root1->left->left = new Node(4);
    root1->left->ryt = new Node(5);
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->ryt = new Node(3);
    root2->left->left = new Node(4);
    root2->left->ryt = new Node(5);
    bool result = isSametrees(root1,root2);
    cout<<"Trees are identical : "<<result;
    return 0;
}
//TC/SC-O(N)
*/

//Q4 Maximum path sum of BT
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
int getmaxsum(Node* root,int &maxsum)
{
if(!root)
return 0;
int lh=max(0,getmaxsum(root->left,maxsum));
int rh=max(0,getmaxsum(root->ryt,maxsum));
maxsum=max(maxsum,(lh+rh+root->val));
return max(lh,rh)+root->val;
}
int maxsumofbt(Node* root)
{
    int maxsum=INT_MIN;
    getmaxsum(root,maxsum);
    return maxsum;
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->ryt = new Node(3);
    root->left->left = new Node(4);
    root->left->ryt = new Node(5);
    root->left->ryt->ryt = new Node(6);
    root->left->ryt->ryt->ryt = new Node(7);
    
    int maxsum = maxsumofbt(root);
    cout << "Maximum sum of the binary tree: " << maxsum << endl;
    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q7 BOUNDRY TRAVERSAL IN BT
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
bool isleaf(Node* root)
{
    if(root->left==NULL && root->ryt==NULL)
    return true;
    else
    return false;
}
void addleftboundry(Node* root,vector<int>&res)
{
    Node* cur=root->left;
    while(cur)
    {
        if(!isleaf(cur))
        {
        res.push_back(cur->val);
        }
        if(cur->left)
        cur=cur->left;
        else
        cur=cur->ryt;
    }
}
void addleaves(Node* root,vector<int>&res)
{
if(isleaf(root))
{
res.push_back(root->val);
return;
}
if(root->left)
addleaves(root->left,res);
if(root->ryt)
addleaves(root->ryt,res);
}
void addrytboundry(Node* root,vector<int>&res)
{
    Node* cur=root->ryt;
    vector<int>temp;
    while(cur)
    {
        if(!isleaf(cur))
        {
        temp.push_back(cur->val);
        }
        if(cur->ryt)
        cur=cur->ryt;
        else
        cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        res.push_back(temp[i]);
    }
}
vector<int>boundrytraversal(Node* root)
{
    vector<int>res;
    if(!root)
    return res;
    if(!isleaf(root))
    res.push_back(root->val);
    addleftboundry(root,res);
    addleaves(root,res);
    addrytboundry(root,res);
    return res;
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->ryt = new Node(4);
    root->left->left->ryt->left = new Node(5);
    root->left->left->ryt->ryt = new Node(6);
    root->ryt=new Node(7);
    root->ryt->ryt=new Node(8);
    root->ryt->ryt->left=new Node(9);
    root->ryt->ryt->left->left=new Node(10);
    root->ryt->ryt->left->ryt=new Node(11);
    
    vector<int> boundrytv = boundrytraversal(root);
    cout << "Boundry traversal of the binary tree: " << endl;
    for(int i=0;i<boundrytv.size();i++)
    {
        cout<<boundrytv[i]<<" ";
    }
    return 0;
}
//TC-O(N)/SC-O(N)
    */

//Q8 VERTICAL ORDER TRAVERSAL
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
vector<vector<int>>verticaltraversal(Node* root)
{
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<Node*,pair<int,int>>>todo;
    todo.push({root,{0,0}});
    while(!todo.empty())
    {
        auto point=todo.front();
        todo.pop();
        Node* temp=point.first;
        int x=point.second.first,y=point.second.second;
        nodes[x][y].insert(temp->val); //insert is used since nodes is a multiset
        if(temp->left)
        {
            todo.push({temp->left,{x-1,y+1}});
        }
        if(temp->ryt)
        {
            todo.push({temp->ryt,{x+1,y+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto p : nodes )
    {
        vector<int>col;
        for(auto q : p.second)
        {
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->ryt = new Node(4);
    root->left->left->ryt->left = new Node(5);
    root->left->left->ryt->ryt = new Node(6);
    root->ryt=new Node(7);
    root->ryt->ryt=new Node(8);
    root->ryt->ryt->left=new Node(9);
    root->ryt->ryt->left->left=new Node(10);
    root->ryt->ryt->left->ryt=new Node(11);
    
    vector<vector<int>> verticaltv = verticaltraversal(root);
    cout << "Vertical traversal of the binary tree: " << endl;
    for(auto p : verticaltv)
    {
        for(auto q : p)
        {
            cout<<q<<" ";
        }
    }
    return 0;
}
//TC-O(N)+O(logN)/SC-O(N)
*/

//Q9 TOP VIEW OF BT
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
vector<int>topview(Node* root)
{
    vector<int>ans;
    queue<pair<Node*,int>>q;
    map<int,int>maporder;
    if(root==NULL)
    return ans;
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        Node* node=it.first;
        int line=it.second;
        if(maporder.find(line)==maporder.end())
        maporder[line]=node->val;
        if(node->left!=NULL)
        q.push({node->left,line-1});
        if(node->ryt!=NULL)
        q.push({node->ryt,line+1});
    }
    for(auto it:maporder)
    ans.push_back(it.second);
    return ans; 
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->ryt = new Node(4);
    root->left->left->ryt->left = new Node(5);
    root->left->left->ryt->ryt = new Node(6);
    root->ryt=new Node(7);
    root->ryt->ryt=new Node(8);
    root->ryt->ryt->left=new Node(9);
    root->ryt->ryt->left->left=new Node(10);
    root->ryt->ryt->left->ryt=new Node(11);
    
    vector<int> toptv = topview(root);
    cout << "Topview traversal of the binary tree: " << endl;
        for(auto q : toptv)
        {
            cout<<q<<" ";
        }
    return 0;
}
//TC/SC-O(N)
*/

//Q10 BOTTOM VALUE OF BT
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
vector<int>bottomview(Node* root)
{
    vector<int>ans;
    queue<pair<Node*,int>>q;
    map<int,int>maporder;
    if(root==NULL)
    return ans;
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        Node* node=it.first;
        int line=it.second;
        maporder[line]=node->val;
        if(node->left!=NULL)
        q.push({node->left,line-1});
        if(node->ryt!=NULL)
        q.push({node->ryt,line+1});
    }
    for(auto it:maporder)
    ans.push_back(it.second);
    return ans; 
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->ryt = new Node(4);
    root->left->left->ryt->left = new Node(5);
    root->left->left->ryt->ryt = new Node(6);
    root->ryt=new Node(7);
    root->ryt->ryt=new Node(8);
    root->ryt->ryt->left=new Node(9);
    root->ryt->ryt->left->left=new Node(10);
    root->ryt->ryt->left->ryt=new Node(11);
    
    vector<int> bottomtv = bottomview(root);
    cout << "Bottomview traversal of the binary tree: " << endl;
        for(auto q : bottomtv)
        {
            cout<<q<<" ";
        }
    return 0;
}
//TC/SC-O(N)
*/

//Q11 RIGHT/LEFT SIDE VIEW
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
void recursionleft(Node* root,int level,vector<int>&res)
{
    if(root==NULL)
    return;
    if(res.size()==level)
    res.push_back(root->val);
    recursionleft(root->left,level+1,res);
    recursionleft(root->ryt,level+1,res);
}
void recursionryt(Node* root,int level,vector<int>&res)
{
    if(root==NULL)
    return;
    if(res.size()==level)
    res.push_back(root->val);
    recursionryt(root->ryt,level+1,res);
    recursionryt(root->left,level+1,res);
}
vector<int>leftsideview(Node* root)
{
    vector<int>res;
    recursionleft(root,0,res);
    return res;
}
vector<int>rytsideview(Node* root)
{
    vector<int>res;
    recursionryt(root,0,res);
    return res;
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->ryt = new Node(10);
    root->left->left->ryt = new Node(5);
    root->left->left->ryt->ryt = new Node(6);
    root->ryt = new Node(3);
    root->ryt->ryt = new Node(10);
    root->ryt->left = new Node(9);

    vector<int> rightView = rytsideview(root);

    cout << "Right View Traversal: ";
    for(auto node: rightView)
    {
        cout << node << " ";
    }
    cout << endl;
    vector<int> leftView = leftsideview(root);

    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
//TC/SC-(logN)
    */

//Q12 SYMMETRIC TREES
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
bool isSymmetricsub(Node* leftnode,Node* rytnode)
{
if(leftnode==NULL || rytnode==NULL)
return leftnode==rytnode;
if(leftnode->val!=rytnode->val)
return false;
return isSymmetricsub(leftnode->left,rytnode->ryt) && isSymmetricsub(leftnode->ryt,rytnode->left);
}
bool isSymmetric(Node* root)
{
    return root==NULL || isSymmetricsub(root->left,root->ryt);
}
int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->ryt = new Node(4);
    root->ryt = new Node(2);
    root->ryt->ryt = new Node(5);
    root->ryt->left = new Node(4);
    cout<<"The Trees are Symmetric "<<isSymmetric(root)<<endl;
    return 0;
}
TC/SC-O(N)
    */
