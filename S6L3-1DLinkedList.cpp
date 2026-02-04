//Q1 MIDDLE LIST OF LL
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
Node* midele(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* middleNode = midele(head);

    cout << "The middle node value is: " << middleNode->data << endl;
    return 0;
}
*/
//Q2&3 REVERSING A LINKEDLIST
//ITERATIVE APPROACH
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
Node *reversell(Node* head)
    {
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL)
        {
            Node* front=temp->next; //storing reference of next iteration
            temp->next=prev; //referencing to previous(linking backwards)
            prev=temp; //moving prev forward
            temp=front; //moving temp forward
        }
        return prev;
    }
    void printll(Node* head)
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
int main()
{
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printll(head);

    // Reverse the linked list
    head = reversell(head);

    // Print the reversed linked list
    cout << "\nReversed Linked List: ";
    printll(head);
    return 0;
}
    */
//RECURSIVE APPROACH
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
Node *reversell(Node* head)
    {   
        if(head==NULL || head->next==NULL)
        return head;
        Node *newhead=reversell(head->next);
        Node *front=head->next;  // node after head
        front->next=head; //reverse the link
        head->next=NULL; //old head becomes tail
        return newhead; //return the new head
    }
    void printll(Node* head)
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
int main()
{
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printll(head);

    // Reverse the linked list
    head = reversell(head);

    // Print the reversed linked list
    cout << "\nReversed Linked List: ";
    printll(head);
    return 0;
}
    */

//Q4 DETECT LOOP IN LL
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
bool detect(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
}
int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 

    if (detect(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    return 0;
}
//TC-O(n)/SC-O(1)
    */

//STARTING POINT IN A LOOP
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
Node* detect(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
        slow=head;
    
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
    }
    }
    return NULL;
}
int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    Node* loopStartNode = detect(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: "<< loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

}
    */

//Q6 Length of the LL
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
int findlength(Node* slow,Node* fast)
{
    int cnt=1;
    fast=fast->next;
    while(slow!=fast)
    {
        cnt++;
        fast=fast->next;
    }
    return cnt;
}
int detect(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
        return findlength(slow,fast);
        }
    }
    return 0;
}
int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    int len = detect(head);

    if (len>0) {
        cout << "Loop detected. Length of the loop is: "<< len << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

}
    */

//Q7 LL IS PALINDROME OR NOT
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
Node *reverselinkedlist(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *newhead=reverselinkedlist(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}
bool isPalindrome(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return true;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newhead=reverselinkedlist(slow->next);
    Node* first=head;
    Node* second=newhead;
    while(second!=NULL)
    {
        if(first->data!=second->data)
        {   
            reverselinkedlist(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverselinkedlist(newhead);
    return true;
}
void printLinkedList(Node* head) {
Node* temp = head;
while (temp != nullptr) 
{
    cout << temp->data << " ";
    temp = temp->next;
}
cout << endl;
}

int main() 
{
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}
    */

//Q8 SEGREGATE ODD & EVEN NODES
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* segregate(Node* head)
{   
    Node* evenhead=new Node(-1);
    Node* oddhead=new Node(-1);
    Node* eventail=evenhead;
    Node* oddtail=oddhead;
    Node* curr=head,*temp;
    while(curr)
    {
        temp=curr;
        curr=curr->next;
        temp->next=nullptr;
        
        if(temp->data & 1)
        {
            oddtail->next=temp;
            oddtail=temp;
        }
        else
        {
            eventail->next=temp;
            eventail=temp;
        }
    }
    eventail->next=oddhead->next;
    return evenhead->next;
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(5);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(8);
    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    Node* newhead=segregate(head);
    cout<<"Segregated Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
    */

//REMOVE NTH NODE FROM END
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* removenthend(Node* head,int n)
{
    Node* slow=head;
    Node* fast=head;
    while(n!=0)
    {
        fast=fast->next;
        n--;
    }
    while(fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next;
    }
    Node* delnode=slow->next;
    slow->next=slow->next->next;
    delete delnode;
    return head;
}
int main()
{   
    int num;
    Node* head=new Node(1);
    head->next=new Node(5);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(8);
    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    cout<<"Enter nth node to be deleted from end "<<endl;
    cin>>num;
    Node* newhead=removenthend(head,num);
    cout<<"Updated Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
    */

//DELETE MIDDLE ELEMENT
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* deletemiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=slow->next->next;
    return head;
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(5);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(8);
    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    Node* newhead=deletemiddle(head);
    cout<<"Updated Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
    */

//SORTING OF LL
/*

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* mergesorted(Node* list1,Node* list2)
{   
    Node* temphead=new Node(-1);
    Node* temp=temphead;
    while(list1!=nullptr && list2!=nullptr)
    {
        if(list1->data<=list2->data)
        {
        temp->next=list1;
        list1=list1->next;
        }
        else
        {
        temp->next=list2;
        list2=list2->next;
        }
        temp=temp->next;
    }
    if(list1!=nullptr)
    temp->next=list1;
    else if(list2!=nullptr)
    temp->next=list2;
    return temphead->next;
}
Node* findmiddle(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* sortll(Node* head)
{
    if(head==nullptr || head->next==nullptr)
    return head;
    Node* middle=findmiddle(head);
    Node* ryt=middle->next;
    middle->next=nullptr;
    Node* left=head;
    left=sortll(left);
    ryt=sortll(ryt);
    return mergesorted(left,ryt);
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(5);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(0);
    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    Node* newhead=sortll(head);
    cout<<"Sorted Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
    */

//FINDING Y_INTERSECTION
//BETTER APPROACH-DIFFERENCE IN LENGTHS
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}

int getdifference(Node* head1,Node* head2)
{
   int len1=0,len2=0;
   while(head1!=nullptr || head2!=nullptr)
   {
    if(head1!=nullptr)
    {
        ++len1;
        head1=head1->next;
    }
    if(head2!=nullptr)
    {
        ++len2;
        head2=head2->next;
    }
   }
   return len1-len2; 
}
Node* findintersection(Node* head1,Node* head2)
{
    int diff=getdifference(head1,head2);
    if(diff<0)
    while(diff++!=0)
    head2=head2->next;
    else
    while(diff--!=0)
    head1=head1->next;
    while(head1!=nullptr)
    {
        if(head1==head2)
        return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return NULL;
}
int main()
{
    Node* head1=new Node(1);
    head1->next=new Node(3);
    head1->next->next=new Node(1);
    head1->next->next->next=new Node(2);
    head1->next->next->next->next=new Node(4);
    Node* head2=new Node(3);
    head2->next=head1->next->next->next;
    head2->next->next=head1->next->next->next->next;
    cout<<"Original Linkedlist1 is "<<endl;
    printll(head1);
    cout<<"Original Linkedlist2 is "<<endl;
    printll(head2);
    Node* answerNode = findintersection(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->data<<endl;
    return 0;
}
    */

//OPTIMAL APPROACH
//COVERING DIFFERENCE APPROACH
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* findintersection(Node* head1,Node* head2)
{
    
    Node* d1=head1;
    Node* d2=head2;
    while(d1!=d2)
    {
        d1=(d1==NULL)? head2:d1->next;
        d2=(d2==NULL)? head1:d2->next;
    }
    return d1;
}
int main()
{
    Node* head1=new Node(1);
    head1->next=new Node(3);
    head1->next->next=new Node(1);
    head1->next->next->next=new Node(2);
    head1->next->next->next->next=new Node(4);
    Node* head2=new Node(3);
    head2->next=head1->next->next->next;
    head2->next->next=head1->next->next->next->next;
    cout<<"Original Linkedlist1 is "<<endl;
    printll(head1);
    cout<<"Original Linkedlist2 is "<<endl;
    printll(head2);
    Node* answerNode = findintersection(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->data<<endl;
    return 0;
}
    */

//SORT LL CONTAINING 0s,1s,2s
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* sortll(Node* head)
{
    if(head==NULL || head->next==NULL)
    return head;
    Node* zerohead=new Node(-1);
    Node* onehead=new Node(-1);
    Node* twohead=new Node(-1);
    Node* zero=zerohead;
    Node* one=onehead;
    Node* two=twohead;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=one->next;
        }
        else if(temp->data==2)
        {
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=(onehead->next) ? (onehead->next) : (twohead->next);
    one->next=twohead->next;
    two->next=NULL;
    Node* newhead=zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return newhead;
}
int main()
{
    Node* head=new Node(1);
    head->next=new Node(0);
    head->next->next=new Node(2);
    head->next->next->next=new Node(0);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(1);
    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    Node* newhead=sortll(head);
    cout<<"Sorted Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
    */

//ADD 1 TO A NUMBER IN LL
//ITERATIVE SOLUTION
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* reversell(Node* head)
{
    Node* prev=NULL;
    Node* temp=head;
    while(temp)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* addone(Node* head)
{
    head=reversell(head);
    Node* current=head;
    int carry=1;
    while(current && carry)
    {
        int sum=current->data+carry;
        current->data=sum%10;
        carry=sum/10;

    if(!current->next && carry)
    {
        current->next=new Node(carry);
        carry=0;
    }
    current=current->next;
    }
    head=reversell(head);
    return head;
}
int main()
{
    Node* head=new Node(9);
    head->next=new Node(9);
    head->next->next=new Node(9);
    cout<<"Original Linkedlist is "<<endl;
    printll(head);
    Node* newhead=addone(head);
    cout<<"New Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
    */

//ADD TWO NUMBERS USING LL
/*
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
int data;
Node *next;
Node(int data1,Node *next1)
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
    cout<<endl;
}
Node* reversell(Node* head)
{
    Node* prev=NULL;
    Node* temp=head;
    while(temp)
    {
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* addtwonum(Node* l1,Node* l2)
{
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry)
    {
        int sum=0;
        if(l1!=NULL)
        {
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL)
        {
            sum+=l2->data;
            l2=l2->next;
        }
        sum=sum+carry;
        carry=sum/10;
        Node* node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return dummy->next;
}
int main()
{
    Node* head1=new Node(9);
    head1->next=new Node(9);
    head1->next->next=new Node(9);
    Node* head2=new Node(1);
    head2->next=new Node(0);
    head2->next->next=new Node(2);
    cout<<"Original Linkedlist1 is "<<endl;
    printll(head1);
    cout<<"Original Linkedlist2 is "<<endl;
    printll(head2);
    Node* reversedhead1=reversell(head1);
    Node* reversedhead2=reversell(head2);
    Node* newhead=addtwonum(reversedhead1,reversedhead2);
    newhead=reversell(newhead);
    cout<<"New Linkedlist is "<<endl;
    printll(newhead);
    return 0;
}
    */