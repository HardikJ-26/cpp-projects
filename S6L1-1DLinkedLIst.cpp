// Q1 INTRODUCTION TO LINKEDLIST
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
public:
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
Node* convertll(vector<int>&a)
{
    Node *head=new Node(a[0]);
    Node *mover=head;
    for(int i=1;i<a.size();i++)
    {
        Node* temp=new Node(a[i]); //temp is being assigned the value of next immediate new node
        mover->next=temp; //mover pointing to next which is temp
        mover=temp; //shifting mover position to temp for next iteration
    }
    return head;
}
int checkifpresent(Node *head,int val) //TC-O(N)-WC/O(1)-BC,AC-O(N/2)
{
    Node* temp=head;
    while(temp)
    {
        if(temp->data==val)
        return 1;
        temp=temp->next;
    }
    return 0;
}
int main()
{
    int cnt=0;
    vector<int>a={2,5,8,7};
    Node* head=convertll(a);
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        cnt++;
    }
    cout<<"\nLength of the ll is "<<cnt<<endl; //TC-o(n)
    cout<<checkifpresent(head,15);
    return 0;
}
//TC-O(N)
*/
// Q2&3 DELETION AND INSERTION IN LL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node* next;
public:
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
Node* convertll(vector<int>&a)
{
    Node *head=new Node(a[0]);
    Node *mover=head;
    for(int i=1;i<a.size();i++)
    {
        Node* temp=new Node(a[i]); //temp is already pointer to next element
        mover->next=temp; //mover pointing to next which is temp
        mover=temp; //shifting mover position to temp for next iteration
    }
    return head;
}
Node *removehead(Node *head)
{
    if(head==NULL)
    return head;
    Node* temp=head;
    head=head->next; //pointing to next head
    delete temp;
    return head;
}
Node *removetail(Node *head)
{
    if(head==NULL || head->next==NULL)
    return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL) //for checking second last element
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
int main()
{
    vector<int>a={2,5,8,7};
    Node* head=convertll(a);
    // cout<<removehead(head)<<endl;
    cout<<removetail(head)<<endl;
    return 0;
}
    */

// DELETING KTH ELEMENT
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertll(vector<int> &a)
{
    Node *head = new Node(a[0]);
    Node *mover = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]); // temp is already pointer to next element
        mover->next = temp;          // mover pointing to next which is temp
        mover = temp;                // shifting mover position to temp for next iteration
    }
    return head;
}
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deletek(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prevn = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prevn->next = prevn->next->next; // skipping the kth pointer
            free(temp);
            break;
        }
        prevn = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> a = {2, 5, 8, 7};
    Node *head = convertll(a);
    head = deletek(head, 3);
    printLL(head);
}
*/

// Removing an element and INSERTION combined
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertll(vector<int> &a)
{
    Node *head = new Node(a[0]);
    Node *mover = head;
    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i]); // temp is already pointer to next element
        mover->next = temp;          // mover pointing to next which is temp
        mover = temp;                // shifting mover position to temp for next iteration
    }
    return head;
}
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteel(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (head->data == k)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prevn = NULL;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            prevn->next = prevn->next->next; // skipping the kth pointer
            free(temp);
            break;
        }
        prevn = temp;
        temp = temp->next;
    }
    return head;
}
Node *inserthead(Node *head, int val) // inserting head
{
    return new Node(val, head);
}
Node *inserttail(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newnode = new Node(val);
    temp->next = newnode;
    return head;
}
Node *insertk(Node *head, int k, int val) //inserting at kth position
{
    int cnt = 1;
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val, head);
        else
            return head;
    }
    Node *temp = head;
    while (temp != NULL && cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
        return head;
    Node *newnode = new Node(val, temp->next); // initialization to kth node pointer
    temp->next = newnode;                      // kth  pointer pointing to newnode linking it to (k-1)th node
    return head;
}
Node *insertbeforevalue(Node *head, int k, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == k)
        return new Node(val, head); //as at very next position element has to be inserted
    Node *temp = head;
    bool found=false;
    while (temp->next != NULL)
    {
        if (temp->next->data == k)
        {
            Node *newnode = new Node(val, temp->next); // initialization to kth node pointer
            temp->next = newnode;                      // kth  pointer pointing to newnode linking it to (k-1)th node
            found=true;
            break;
        }
        temp=temp->next;
    }
    if(found==false)
    {
    cout<<"Value not found"<<endl;
    }
    return head;
}
int main()
{
    vector<int> a = {2, 5, 8, 7};
    Node *head = convertll(a);
    head = inserthead(head, 100);
    head = deleteel(head, 8);
    head = inserttail(head, 6);
    head = insertk(head, 2, 9);
    head = insertbeforevalue(head, 7, 22);
    printLL(head);
}
    */