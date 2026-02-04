//Q1 Implementing Stack using Arrays
/*
#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int *a;
    int top;
    public:
    Stack(int s=1000)
    {
        top=-1;
        size=s;
        a=new int[size];
    }
    ~Stack()
    {
        delete[] a; //freeing accumalated stack size
    }
    void push(int x)
    {
        if(top==size-1)
        {
            cout<<"Stack Overflow!,Cannot push "<<x<<endl;
            return;
        }
        a[++top]=x;
    }
    int pop()
    {
        if(top==-1)
        {
            cout << "Stack Underflow!,Cannot pop"<< endl;
            return -1;
        }
        return a[top--];
    }
    int Top()
    {
        if(top==-1)
        {
        cout<<"Stack is empty"<<endl;
        return -1;
        }
        return a[top];
    }
    int Size()
    {
        return top+1;
    }
    bool empty()
    {
        return top==-1;
    }
};
int main()
{   
    Stack s(5);
    s.push(6);
    s.push(3);
    s.push(7);

    cout << "Top of stack before deleting: " << s.Top() << endl;
    cout << "Size before deleting: " << s.Size() << endl;

    cout << "Deleted element: " << s.pop() << endl;
    cout << "Size after deleting: " << s.Size() << endl;
    cout << "Top after deleting: " << s.Top() << endl;

    // Testing underflow
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
    */
//TC-O(n),SC-O(n)

//Q2 Implementing Queues using Arrays
/*
#include<bits/stdc++.h>
using namespace std;

class Queue
{
int *a;
int start,end,currsize,maxsize;
public:
Queue() //default constructor
{   
    maxsize = 16;
    a=new int[maxsize];
    start=-1;
    end=-1;
    currsize=0;
}
Queue(int maxsize) //parameterized constructor for different sizes to accomodate
{
    this->maxsize = maxsize; //referring to member variable
    a=new int[maxsize];
    start = -1;
    end = -1;
    currsize = 0;
  }
  ~Queue() 
    {
        delete[] a;
    }
  void push(int ele)
  {
    if(currsize==maxsize)
    {
        cout<<"Queue is already full"<<endl;
        return;
    }
    if(end==-1)
    {
        start=0;
        end=0;
    }
    else
    {
        end=(end+1)%maxsize;
    }
        a[end]=ele;
        cout<<"The element pushed is "<<ele<<endl;
        currsize++;
}
    int pop()
    {
        if(start==-1)
        {
        cout<<"Queue is Empty"<<endl;
        return -1;
        }
        int popped=a[start];
        if(currsize==1)
        {
        start=-1;
        end=-1;
        }
        else
        {
            start=(start+1)%maxsize;
            currsize--;
            return popped;
        }
  }
  int top()
  {
    if(start==-1)
    {
    cout<<"Queue is Empty"<<endl;
    return -1;
    }
    return a[start];
    }
    int size()
    {
        return currsize;
    }
};
int main()
{
    Queue q(5);
    q.push(7);
    q.push(5);
    q.push(1);
    q.push(3);
    cout << "The peak of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peak of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}
//TC-O(1),SC-O(n)
*/

//Q3 Implementing Stack using Queues
/*
//Approach-1
#include <bits/stdc++.h>
using namespace std;

class Stack
{
queue<int> q;
public:
void Push(int x)
{
    int s=q.size();
    q.push(x);
    for(int i=0;i<s;i++)
    {
        q.push(q.front()); //front() is used for getting first index in queue
        q.pop();
    }
}
int Pop()
{
    int n=q.front();
    q.pop();
    return n;
}
int Top()
{
    return q.front();
}
int Size()
{
    return q.size();
}
bool empty()
{
    return Size()==0;
}
};
int main()
{
Stack s;
s.Push(3);
s.Push(2);
s.Push(4);
s.Push(1);
cout << "Top of the stack: " << s.Top() << endl;
cout << "Size of the stack before removing element: " << s.Size() << endl;
cout << "The deleted element is: " << s.Pop() << endl;
cout << "Top of the stack after removing element: " << s.Top() << endl;
cout << "Size of the stack after removing element: " << s.Size();
return 0;
}
//TC/SC-O(N)
*/

//Q4 Implementing Queues using Stacks
/*
#include <bits/stdc++.h>
using namespace std;

class Queue
{
stack<int>input,output;
public:
void Push(int ele)
{
    while(!input.empty())
    {
        output.push(input.top());
        input.pop();
    }
    cout<<"The element pushed is "<<ele<<endl;
    input.push(ele);
    while(!output.empty())
    {
        input.push(output.top());
        output.pop();
    }
}
int Pop()
{
    if(input.empty())
    {
        cout<<"Queue is empty"<<endl;
        exit(0);
    }
    int val=input.top();
    input.pop();
    return val;
}
int Top()
{
    if(input.empty())
    {
        cout<<"Queue is empty"<<endl;
        exit(0);
    }
    return input.top();
}
int Size()
{
    return input.size();
}
};
int main()
{
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.Size() << endl;
  return 0;
}
  */
//TC/SC-O(N)

//Approach-2
/*
#include <bits/stdc++.h>
using namespace std;

class Queue
{
stack<int>stack1,stack2;
public:
void Push(int ele)
{
    cout<<"The element pushed is "<<ele<<endl;
    stack1.push(ele);
}
int Pop()
{
    if(stack2.empty())
    {   
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if(stack2.empty())
    {
        cout << "Queue is empty" << endl;
        exit(0);
    }
    int val=stack2.top();
    stack2.pop();
    return val;
}
int Top()
{
     if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty())
        {
            cout << "Queue is empty" << endl;
            exit(0);
        }
        return stack2.top();
}
int Size()
{
    return stack1.size()+stack2.size();
}
};
int main()
{
  Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.Size() << endl;
  return 0;
}
  */
//TC-O(1)/SC-O(N)

//Q7 Balanced Parenthesis
/*
#include <bits/stdc++.h>
using namespace std;

bool isvalid(string s)
{
stack<char>st;
for(auto it:s)
{
    if(it=='{' || it=='(' ||  it=='[')
    st.push(it);
    else
    {
        if(st.size()==0)
        return false;
        char ch=st.top();
        st.pop();
        if(ch=='(' && it==')' || it=='}' && ch=='{' || it==']' && ch=='[')
        continue;
        else
        return false;
    }
}
return st.empty();
}
int main()
{
    string s="()[{(}()]";
    if(isvalid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Q8 MINSTACK
/*
#include <bits/stdc++.h>
using namespace std;

class minstack
{
    stack<int>st;
    int mini;
    public:
    minstack()
    {
        while(st.empty()==false)
        st.pop();
        mini=INT16_MAX;
    }
    void push(int val)
    {
        if(st.empty())
        {
            mini=val;
            st.push(val);
        }
        else
        {
            if(val<mini)
            {
            st.push(2*val-mini);
            mini=val;
            }
            else
            st.push(val);
        }
    }
    void pop()
    {
        if(st.empty())
        return;
        int val=st.top();
        st.pop();
        if(val<mini)
        {
            mini=(2*mini-val);
        }
    }
    int top()
    {
        if(st.empty())
        return -1;
        int val=st.top();
        if(val<mini)
        return mini;
        return val;
    }
    int getmin()
    {
        return mini;
    }
};
int main()
{
    minstack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout<<st.getmin()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.getmin()<<endl;
    return 0;
}
//TC-O(1) SC-O(N)
*/