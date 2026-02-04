//Q1 DELETING A GIVEN KEY
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert2dll(vector<int> &a)
{
    Node *head = new Node(a[0]);
    Node *prev = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i], nullptr, prev);
        prev->next = temp; // this is doing forward linking
        prev = temp;
    }
    return head;
}
void printll(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* deletekey(Node* head,int key)
{
    Node* current=head;
    while(current)
    {
        if(current->data==key)
        {   
            Node* nextnode=current->next;
            if(current==head)
            {
                head=head->next;
                if(head)
                head->back=nullptr;
                current->next=nullptr;
                delete current;
            }
            else
            {
                Node* prevnode=current->back;
                prevnode->next=nextnode;
                if(nextnode!=nullptr)
                nextnode->back=prevnode;
                current->back=nullptr;
                current->next=nullptr;
                delete current;
            }
            current=nextnode;
        }
        else
        current=current->next;
    }
    return head;
}
int main() 
{
    vector<int> arr = {10, 4, 10, 7, 10, 8, 10};
    Node* head = convert2dll(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    printll(head);
    int key;
    cout<<"Enter key to be deleted "<<endl;
    cin>>key;
    cout << endl << "Doubly Linked List After Deleting " << endl;
    head = deletekey(head,key);
    printll(head);
    return 0;
}
    //TC-O(n)/SC-O(1)
    */

//FINDING SUM PAIRS IN DLL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert2dll(vector<int> &a)
{
    Node *head = new Node(a[0]);
    Node *prev = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i], nullptr, prev);
        prev->next = temp; // this is doing forward linking
        prev = temp;
    }
    return head;
}
void printll(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* findtail(Node* head)
{
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    return temp;
}
vector<vector<int>> findsumpairs(Node* head,int sum)
{
    Node* left=head; Node* ryt=findtail(head);
    vector<vector<int>>store;
    while(left!=nullptr && ryt!=nullptr && left->data<ryt->data)
    {
        if(left->data+ryt->data==sum)
        {
            store.push_back({left->data,ryt->data});
            left=left->next;
            ryt=ryt->back;
        }
        else if(left->data+ryt->data>sum)
        {
            ryt=ryt->back;
        }
        else
        {
            left=left->next;
        }
    }
    return store;
}
int main()
{
    vector<int> arr = {1,2,3,4,9};
    Node* head = convert2dll(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    printll(head);
    int key;
    cout<<"Enter the sum to find "<<endl;
    cin>>key;
    cout << endl << "List of sum combinations is " << endl;
    vector<vector<int>>pairs = findsumpairs(head,key);
    if (pairs.empty())
        cout << "No pairs found!" << endl;
    else
    {
        for (auto &p : pairs)
            cout << p[0] << " + " << p[1] << " = " << key << endl;
    }
    return 0;
}
//TC-O(n)/SC-O(1)
    */

//REMOVE DUPLICATES FROM SORTED ARRAY
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert2dll(vector<int> &a)
{
    Node *head = new Node(a[0]);
    Node *prev = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i], nullptr, prev);
        prev->next = temp; // this is doing forward linking
        prev = temp;
    }
    return head;
}
void printll(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* removeduplicates(Node* head)
{
    if(!head)
    return nullptr;
    Node* current=head;
    while(current!=nullptr && current->next!=nullptr)
    {
        Node* nextnode=current->next;
        while(nextnode!=nullptr && nextnode->data==current->data)
        {
            Node* duplicatenode=nextnode;
            nextnode=nextnode->next;
            delete duplicatenode;
        }
        current->next=nextnode;
        if(nextnode!=nullptr)
        nextnode->back=current;
        current=current->next;
    }
    return head;
}
int main()
{   
    vector<int> arr = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6};
    Node* head = convert2dll(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    printll(head);
    cout<<"After removal of dupliactes "<<endl;
    removeduplicates(head);
    printll(head);
    return 0;
}
TC-O(N)/SC-O(1)
*/

//EQ TRANSFORM 2D MATRIX INTO DLL
/*
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* back;
    Node* up;
    Node* down;

    Node(int data1,Node* next1,Node* back1,Node* up1,Node* down1)
    {
        data=data1;
        next=next1;
        back=back1;
        up=up1;
        down=down1;
    }
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
        up=nullptr;
        down=nullptr;
    }
};

void print(Node* head)
{
    Node* downptr=head;
    Node* rightptr;
    while(downptr)
    {
        rightptr=downptr;
        while(rightptr)
        {
            cout<<(rightptr->data)<<" ";
            rightptr=rightptr->next;
        }
        cout<<"\n";
        downptr=downptr->down;
    }
}

Node* transfrommatrix(int mat[3][3])
{
    int n=3,m=3;
    Node* head_main=NULL;
    Node* upper_row_head=NULL;

    for(int i=0;i<n;i++)
    {
        Node* headrow=NULL;
        Node* prev=NULL;
        Node* upper=upper_row_head;

        for(int j=0;j<m;j++)
        {
            Node* temp=new Node(mat[i][j]);

            if(i==0 && j==0)
            {
                head_main=temp;
            }
            if(j==0)
            {
                headrow=temp;
            }
            if(prev)
            {
                prev->next=temp;
                temp->back=prev;
            }
            prev=temp;
            if(upper)
            {
                temp->up=upper;
                upper->down=temp;
                upper=upper->next;
            }
        }
        upper_row_head=headrow;
    }
    return head_main;
}
int main()
{
    int mat[3][3]=
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Node* head_main=transfrommatrix(mat);
    print(head_main);
    return 0;
}
//TC-O(N*N)/SC-O(1)
*/

//EQ TO CHECK IF A DLL IS PALINDROME
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};
bool isPalindrome(Node* head)
{
    if(head==nullptr || head->next==nullptr)
    return true;
    Node* left=head;
    Node* right=head;
    while(right->next!=nullptr)
    {
        right=right->next;
    }
    while(left!=right && left->prev!=right)
    {
        if(left->data!=right->data)
        {
            return false;
        }
        left=left->next;
        right=right->prev;
    }
    return true;
}
int main()
{
    Node* headD=new Node(10);
    headD->next=new Node(20);
    headD->next->prev=headD;
    headD->next->next=new Node(30);
    headD->next->next->prev=headD->next;
    
    cout<<"Is the DLL Palindrome? : "<<isPalindrome(headD)<<endl;

    return 0;
}
//TC-O(n)/SC-O(1)
*/

//EQ SPLIT A CIRCULAR LL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1,Node* next1,Node* prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};
pair<Node*,Node*>splithead(Node* head)
{
Node *slow = head; 
Node *fast = head; 
    
if(head == nullptr) 
return {nullptr, nullptr}; 

while(fast->next != head && fast->next->next != head) 
{ 
    fast = fast->next->next; 
    slow = slow->next; 
}
if(fast->next->next == head) 
fast = fast->next;
Node* head1=head;
Node* head2=slow->next;
fast->next=slow->next;
slow->next=head;
return {head1,head2};
}
void printList(Node *head) 
{ 
    Node *curr = head; 
    if(head != nullptr) 
    { 
    do 
    { 
    cout << curr->data << " "; 
    curr = curr->next; 
    } while(curr != head); 
    cout << endl; 
    } 
} 
int main() { 
    
    Node *head = new Node(1); 
    Node *head1 = nullptr; 
    Node *head2 = nullptr; 

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    pair<Node*, Node*> result = splithead(head); 
    head1 = result.first;
    head2 = result.second;
    
    printList(head1); 
    printList(head2);
    
    return 0; 
}
//TC-O(n)/SC-O(1)
    */

//EQ DELETE EVEN PARITY ELEMENTS
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1,Node* next1,Node* prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};
class NodeC
{
public:
int data;
NodeC* next;
NodeC(int data1,NodeC* next1)
{
    data=data1;
    next=next1;
}
NodeC(int data1)
{
    data=data1;
    next=nullptr;
}
};

bool isEvenParity(int x)
{
    int parity = 0;
    while (x != 0) {
        if (x & 1==0)
        parity++;
        x = x >> 1; //to discard rightmost bit
    }
    cout<<"Parity of elements is : "<<endl;
    cout<<parity<<endl;
    if (parity % 2 == 0)
        return true;
    else
        return false;
}
Node* removedll(Node* head)
{
    Node* curr = head;
    while(curr)
    {
    Node* nextNode = curr->next;
    if(isEvenParity(curr->data))
    {
        if(curr == head)
        {
            head = head->next;
            if(head) head->prev = nullptr;
        }
        else
        {
            curr->prev->next = curr->next;
            if(curr->next)
            curr->next->prev = curr->prev;
        }
        delete curr;
    }
    curr = nextNode;
    }
    return head;
}
NodeC* removecll(NodeC* head)
{
if(!head) return head;
NodeC* curr = head;
NodeC* prev=NULL;
NodeC* start=head;
do 
{
    NodeC* nextNode = curr->next;

    if(isEvenParity(curr->data))
    {
    if(curr == head && curr->next==head)
    {
        delete curr;
        return nullptr;
    }
    if(curr==head)
    {
        head = head->next;
        NodeC* temp = head;
        while(temp->next != curr) 
        temp = temp->next;
        temp->next = head;
        prev = temp; //placing prev behind newhead
        delete curr;
        curr = nextNode;
        start = head; //referencing new head
        continue;
    }
    else
    {   
        prev->next=curr->next;
        curr=nextNode;
        continue;
    }
    }
    prev=curr;
    curr = nextNode;
} 
while(curr != start);
return head;
}
void printDLL(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void printCSLL(NodeC* head)
{
    if(!head)
    {
        return;
    }
    NodeC* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
int main()
{
    Node* headD=new Node(3);
    headD->next=new Node(4);
    headD->next->prev=headD;
    headD->next->next=new Node(12);
    headD->next->next->prev=headD->next;
    
    cout<<"DLL Before:"<<endl;
    printDLL(headD);
    headD=removedll(headD);
    cout<<"DLL After:"<<endl;
    printDLL(headD);

    NodeC* headC=new NodeC(3);
    headC->next=new NodeC(4);
    headC->next->next=new NodeC(6);
    headC->next->next->next=headC;

    cout<<"CSLL Before:"<<endl;
    printCSLL(headC);
    headC=removecll(headC);
    cout<<"CSLL After:"<<endl;
    printCSLL(headC);
    return 0;
}
//TC/SC-O(n)
*/

//EQ CORRECT RANDOM POINTER IN DLL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* prev;
Node(int data1,Node* next1,Node* prev1)
{
    data=data1;
    next=next1;
    prev=prev1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    prev=nullptr;
}
};

Node* correct(Node* head)
{
    if (head == nullptr) return nullptr;
    head->prev = nullptr;
    Node* temp = head;
    while(temp->next != nullptr)
    {
    if(temp->next->prev != temp)
    {
        temp->next->prev = temp;
    }
    temp = temp->next;
    }
    return head;
}

void printll(Node *head)
{
    Node *temp = head;
    int limit = 0; 
    while (temp != nullptr && limit < 20)
    {
        cout << temp->data << " ";
        temp = temp->next;
        limit++;
    }
    if(limit >= 20) cout << "...(cycle/truncated)";
    cout << endl;
}

int main()
{
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    head->next = n2;
    n2->prev = head;
    Node* n3 = new Node(3);
    n2->next = n3; 
    n3->prev = head; 
    n3->next = nullptr;

    cout << "Incorrect linked list (Backward checks would fail): " << endl;
    printll(head);
    head = correct(head);
    cout << "Corrected linked list: " << endl;
    printll(head);
    
    return 0;
}
//TC-O(N)/SC-O(1)
    */