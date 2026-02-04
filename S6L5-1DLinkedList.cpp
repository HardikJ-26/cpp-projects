//Q2 ROTATE A LL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node(int data1,Node* next1)
{
    data=data1;
    next=next1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
}
};
void printll(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* rotateryt(Node* head,int k)
{
    Node* current=head;
    if(head==nullptr && head->next==nullptr && k==0)
    return head;
    int cnt=1;
    while(current->next!=NULL)
    {
        cnt++;
        current=current->next;
    }
    current->next=head;
    k=k%cnt;
    int end=cnt-k;
    while(end--)
    {
        current=current->next;
    }
    head=current->next;
    current->next=NULL;
    return head;
}
int main()
{   
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printll(head);
    int k=3;
    head = rotateryt(head,k);

    cout << "After rotation list is : " << endl;
    printll(head);
    return 0;
}
//TC-O(N)/SC-O(1)
    */

//Q1 REVERSE LL BY K PLACES
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node(int data1,Node* next1)
{
    data=data1;
    next=next1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
}
};
void printll(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
//Reversal of ll fxn
Node* reversell(Node* head) 
{
    Node* temp=head;
    Node* prev=NULL;
    while(temp)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
//To get the nxt kth node
Node* getkthnode(Node *temp,int k)
{
    k-=1;
    while(temp!=NULL && k>0)
    {
        k--;
        temp=temp->next;
    }
    return temp;
}
Node* kreverse(Node* head,int k)
{
    Node* temp=head;
    Node* prevlast=NULL;
    while(temp)
    {
        Node* kthnode=getkthnode(temp,k);
        if(kthnode==NULL) //for linking when less than k numbers remain that need not be reversed
        {
            if(prevlast) 
            {
                prevlast->next=temp;
            }
            break;
        }
        Node* nextnode=kthnode->next;
        kthnode->next=NULL; //breaking link at kth node so as to perform the reverse fxn
        reversell(temp);
        if(temp==head)
        {
            head=kthnode;
        }
        else
        {
            prevlast->next=kthnode;
        }
        prevlast=temp;
        temp=nextnode;
    }
    return head;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next->next->next->next->next = new Node(11);

    cout<<"Original list is "<<endl;
    printll(head);
    int k=3;
    head =  kreverse(head,k);

    cout << "\nK reversed list is : " << endl;
    printll(head);
    return 0;
}
    */

//Q3 FLATTENING OF A LINKEDLIST
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
Node* child;
Node(int data1,Node* next1,Node* child1)
{
    data=data1;
    next=next1;
    child=child1;
}
Node(int data1)
{
    data=data1;
    next=nullptr;
    child=nullptr;
}
};
void printll(Node* head) 
{
    while (head != nullptr) 
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}
Node* merge(Node* list1,Node* list2)
{
Node* dummynode=new Node(-1);
Node* res=dummynode;
while(list1!=nullptr && list2!=nullptr)
{
    if(list1->data<list2->data)
    {
        res->child=list1;
        res=list1;
        list1=list1->child;
    }
    else
    {
        res->child=list2;
        res=list2;
        list2=list2->child;
    }
    res->next=NULL;
}
if(list1)
{
    res->child=list1;
}
else
{
   res->child=list2; 
}
if(dummynode->child)
dummynode->child->next=NULL; //break the last node's link to prevent cycles
return dummynode->child;
}
Node* flattenedll(Node* head)
{
    if(head==NULL || head->next==NULL)
    return head; //going till end of ll
    Node* mergedhead=flattenedll(head->next); //getting mergedhead
    head=merge(head,mergedhead); //new merging
    return head;
}
void printOriginalLinkedList(Node* head, int depth) 
{
    while (head != nullptr) 
    {
        cout << head->data;

        if (head->child) 
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main()
{
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node* flattened = flattenedll(head);
    cout << "\nFlattened linked list: ";
    printll(flattened);
    return 0;
}
    */