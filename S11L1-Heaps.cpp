//Q1/2 INTRO TO HEAPS
//This code is for MinHeaps
/*
#include <bits/stdc++.h>
using namespace std;

class Heaps
{
public:
int capacity;
int size;
int *a;
Heaps(int cap)
{
capacity=cap;
size=0;
a=new int[capacity];
}
int parent(int i)
{
return (i-1)/2;
}
int left(int i)
{
    return (2*i+1);
}
int right(int i)
{
    return (2*i+2);
}
void Insert(int i)
{
    if(size==capacity)
    {
    cout<<"Heap size Overflow";
    return;
    }
    a[size]=i;
    int k=size;
    size++;
    //fixing minheap property
    while(k!=0 && a[parent(k)]>a[k])
    {
    swap(&a[parent(k)],&a[k]);
    k=parent(k);
    }
}
int Delete()
{    
    int root=a[0];
    a[0]=a[size-1];
    HeapifyDown(0);
    return root;
}
void HeapifyDown(int root)
{
    int ryt=right(root);
    int lef=left(root);
    int mini=root;
    if(lef<size && a[lef]<a[mini])
    mini=lef;
    if(ryt<size && a[ryt]<a[mini])
    mini=ryt;
    if(mini!=root)
    {
    swap(a[mini],a[root]);
    HeapifyDown(mini);
    }
}
void HeapifyUp(int k)
{
    while(k!=0 && a[parent(k)]>a[k])
    {
    swap(a[parent(k)],a[k]);
    k=parent(k);
    }
}
int getmin()
{
    return a[0];
}
int extractmin()
{
    if(size<=0)
    return INT_MAX;
    if(size==1)
    {
        size--;
        return a[0];
    }
    int mini=a[0];
    a[0]=a[size-1];
    size--;
    HeapifyDown(0);
    return mini;
}
void Decreasekey(int i,int val)
{
    a[i]=val;
    HeapifyUp(i);
}
void deletenode(int i)
{
    Decreasekey(i,INT_MIN); //so the node to be deleted becomes minimum
    extractmin(); //and we extract the min
}
void print() 
{
    for (int i = 0; i < size; i++)
    cout << a[i] << " ";
    cout << endl;
}
};
int main()
{
    Heaps h(20);
    h.Insert(4);
    h.Insert(1);
    h.Insert(2);
    h.Insert(6);
    h.Insert(7);
    h.Insert(3);
    h.Insert(8);
    h.Insert(5);

    cout << "Min value is " << h.getmin() << endl;

    h.Insert(-1);
    cout << "Min value is " << h.getmin() << endl;

    h.Decreasekey(3, -2);
    cout << "Min value is " << h.getmin() << endl;

    cout<<"Extracted value is  "<<h.extractmin()<<endl;

    cout << "Min value is " << h.getmin() << endl;

    h.deletenode(0);
    cout << "Min value is " << h.getmin() << endl;

    cout<<"Value of deleted node is " << h.Delete()<<endl;
    cout << "Min value is " << h.getmin() << endl;

    return 0;
}
*/
//TC/SC-O(N)

//Q3 FIND IF ARRAY IS A VALID MINHEAP
/*
#include <bits/stdc++.h>
using namespace std;

bool validminheap(vector<int>&num)
{
    int n=num.size();
    for(int i=0;i<n/2;i++)
    {
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && num[left]<num[i])
        return false;
        if(right<n && num[right]<num[i])
        return false;
    }
    return true;
}
int main()
{
    vector<int> nums = {10, 20, 30, 21, 15};
    cout << (validminheap(nums) ? "true" : "false") << endl;
    return 0;
}
//TC-O(N)/SC-O(1)
    */

//Q4 CONVERT MINHEAP TO  MAXHEAP
/*
#include <bits/stdc++.h>
using namespace std;

void maxheapify(vector<int>&nums,int i)
{   
    int n=nums.size();
    int left=2*i+1;
    int ryt=2*i+2;
    int largest=i;
    if(left<n && nums[left]>nums[i])
    largest=left;
    if(ryt<n && nums[ryt]>nums[i])
    largest=ryt;
    if(largest!=i)
    {
    swap(nums[largest],nums[i]);
    maxheapify(nums,largest);
    }
}
void mintomax(vector<int>&nums)
{   
    int n=nums.size();
    for(int i=n/2;i>=0;i--)
    {
        maxheapify(nums,i);
    }
}
void printarray(vector<int>&nums)
{
for(int i=0;i<nums.size();i++)
cout<<nums[i]<<" ";
cout<<endl;
}
int main()
{
    vector<int>a={10,20,30,21,23};
    mintomax(a);
    printarray(a); 
    return 0;
}
//TC-O(N)/SC-O(1)
*/

//EQ IMPLEMENT PRIORITY QUEUES USING HEAPS
/*
#include <bits/stdc++.h>
using namespace std;

class MaxPriorityQueue{
private:
    vector<int> data;

    void HeapifyUp(int childIndex)
    {
        while(childIndex>0)
        {
            int parentIndex=(childIndex-1)/2;
            if(data[childIndex]>data[parentIndex])
            {
                swap(data[childIndex],data[parentIndex]);
                childIndex=parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    void HeapifyDown(int parentIndex)
    {
        int heapSize=data.size();
        int largest=parentIndex;
        int left=2*parentIndex+1;
        int right=2*parentIndex+2;

        if(left<heapSize&&data[left]>data[largest]){
            largest=left;
        }

        if(right<heapSize&&data[right]>data[largest]){
            largest=right;
        }

        if(largest!=parentIndex){
            swap(data[parentIndex],data[largest]);
            HeapifyDown(largest);
        }
    }

public:
    bool isEmpty(){
        return data.empty();
    }
    
    void push(int value){
        data.push_back(value);
        HeapifyUp(data.size()-1);
    }

    int top(){
        if(isEmpty()){
            throw runtime_error("Queue is empty,can't peek");
        }
        return data[0];
    }

    int pop(){
        if(isEmpty()){
            throw runtime_error("Queue is empty,can't extract max");
        }
        int maxValue=data[0];
        data[0]=data.back();
        data.pop_back();
        if(!isEmpty()){
            HeapifyDown(0);
        }
        return maxValue;
    }
};

int main(){
    MaxPriorityQueue pq;
    
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(8);
    pq.push(15);
    
    cout<<"Maximum element (Top): "<<pq.top()<<endl; 
    
    cout<<"Popped element is "<<pq.pop()<<endl; 
    cout<<"Popped element is "<<pq.pop()<<endl;
    
    pq.push(30);
    
    cout<<"Maximum element (Top): "<<pq.top()<<endl;
    
    while(!pq.isEmpty()){
        cout<<"Popping: "<<pq.pop()<<endl;
    }
    
    return 0;
}
*/

