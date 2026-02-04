//Q1-3 INTRODUCTION TO DOUBLY LL
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
Node *deletehead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *prev = head;
    head = head->next;
    prev->next = nullptr;
    head->back = nullptr;
    delete prev;
    return head;
}
Node *deletetail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    Node *tail = head;
    Node *prev;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}
Node *deletekele(Node *head, int k)
{
    Node *temp = head;
    int cnt = 1;
    if (k <= 0)
        return head;
    while (temp != nullptr && cnt <= k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr)
        return head;
    if (k == 1)
    {
        Node *newhead = head->next;
        if (newhead != nullptr)
            newhead->back = nullptr;
        head->next = nullptr;
        delete head;
        return newhead;
    }
    else
    {
        Node *delnode = temp;
        Node *front = temp->next;
        Node *prev = temp->back;
        prev->next = front;
        if (front != nullptr)
            front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete delnode;
        return head;
    }
}
Node *deleteval(Node *head, int ele)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == ele)
        {
            if (temp == head)
            {
                Node *newhead = head->next;
                if (newhead != nullptr)
                    newhead->back = nullptr;
                head->next = nullptr;
                delete head;
                return newhead;
            }
            else
            {
                Node *delnode = temp;
                Node *front = temp->next;
                Node *prev = temp->back;
                prev->next = front;
                if (front != nullptr)
                    front->back = prev;
                temp->next = nullptr;
                temp->back = nullptr;
                delete delnode;
                return head;
            }
        }
        temp=temp->next;
    }
}
Node* inserthead(Node* head,int val)
{
    Node* newhead=new Node(val,head,nullptr);
    if(head)
    head->back=newhead;
    return newhead;
}
Node* inserttail(Node* head,int val)
{
    if(head==nullptr)
    return new Node(val);
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    Node* newtail=new Node(val,nullptr,temp);
    temp->next=newtail;
    return head;
}
Node* insertkele(Node* head,int val,int k)
{
int cnt=1;
if(k==1)
{   
    Node* newhead=new Node(val,head,nullptr);
    if(head)
    head->back=newhead;
    return newhead;
}
else
{
Node* temp=head;
while(temp!=nullptr && cnt<k-1)
{
    temp=temp->next;
    cnt++;
}
if(temp==nullptr)
return head;
else if(temp->next==nullptr)
{
    Node* newtail=new Node(val,nullptr,temp);
    temp->next=newtail;
    return head;
}
else
{
Node* front=temp->next;
Node* newnode= new Node(val,front,temp);
front->back=newnode;
temp->next=newnode;
return head;
}
}
}
Node* insertval(Node* head,int val,int k)
{
    if(head==nullptr)
    return new Node(val);
    else if(head->data==k)
    {
    Node* newhead=new Node(val,head,nullptr);
    head->back=newhead;
    return newhead;
    }
    else
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            if(temp->data==k)
            {
                Node* prev=temp->back;
                Node* newnode=new Node(val,temp,prev);
                temp->back=newnode;
                prev->next=newnode;
                return head;
            }
            temp=temp->next;
        }
    }
    return head;
}
int main()
{
    vector<int> a = {2, 5, 8, 7};
    Node *head = convert2dll(a);
    printll(head);
    head=deletehead(head);
    printll(head);
    head=deletetail(head);
    printll(head);
    int k;
    cout << "Enter kth position to be deleted" << endl;
    cin >> k;
    head = deletekele(head, k);
    printll(head);
    int ele;
    cout << "Enter element to be deleted" << endl;
    cin >> ele;
    head = deleteval(head, ele);
    printll(head);
    head=inserthead(head,9);
    printll(head);
    head=inserttail(head,6);
    printll(head);
    head=insertkele(head,3,5);
    printll(head);
    head=insertval(head,1,3);
    printll(head);
    return 0;
}
    */

//Q4 REVERSING A DLL
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
Node* reversedll(Node* head)
{
    if(head==NULL || head->next==NULL)
    return head;
    Node* prev=NULL;
    Node* current=head;
    //reversing next and back pointers
    while(current)
    {
        prev=current->back; //moving prev forward
        current->back=current->next; 
        current->next=prev;
        current=current->back; //since pointer is reversed
    }
    return prev->back;
}
int main() 
{
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convert2dll(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    printll(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    head = reversedll(head);
    printll(head);

    return 0;
}
//TC-O(N)/SC-O(1)
*/

