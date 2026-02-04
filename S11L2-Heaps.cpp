//Q1/2-KTH LARGEST/SMALLEST ELEMENT
/*
#include <bits/stdc++.h>
using namespace std;

int partitionlar(vector<int>& arr, int left, int right) 
{
    int pivot = arr[left] ;
    int l = left + 1 ;
    int r = right;
    while (l <= r) {
        if (arr[l] < pivot && arr[r] > pivot) //Safety Check
        {
            swap(arr[l], arr[r]);
            l++ ;
            r-- ;
        }
        if (arr[l] >= pivot) {
            l++;
        }
        if (arr[r] <= pivot) {
            r--;
        }
    }
    swap(arr[left], arr[r]); //in end have to swap pivot and end
    return r;
}
int partitionsm(vector<int>& arr, int left, int right) 
{
    int pivot = arr[left];
    int l = left + 1;
    int r = right;

    while (l <= r) {
        if (arr[l] > pivot && arr[r] < pivot) //Safety Check
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        if (arr[l] <= pivot) l++;
        if (arr[r] >= pivot) r--;
    }
    
    swap(arr[left], arr[r]); //in end have to swap pivot and end
    return r;
}
int kthlargest(vector<int>&arr,int k)
{
int left=0,right=arr.size()-1,kth;
while(1)
{
    //reducing search required array
    int idx=partitionlar(arr,left,right);
    if(idx==k-1)
    {
    kth=arr[idx];
    break;
    }
    if(idx<k-1)
    left=idx+1;
    else
    right=idx-1;
}
return kth;
}
int kthsmallest(vector<int>&arr,int k)
{
int left=0,right=arr.size()-1,kth;
while(1)
{
    int idx=partitionsm(arr,left,right);
    if(idx==k-1)
    {
    kth=arr[idx];
    break;
    }
    if(idx<k-1)
    left=idx+1;
    else
    right=idx-1;
}
return kth;
}
int main()
{
    vector<int>arr ;
    arr.push_back(12) ;
    arr.push_back(3)  ;
    arr.push_back(5) ;
    arr.push_back(7)  ;
    arr.push_back(4) ;
    arr.push_back(19)  ;
    arr.push_back(26) ;

    int n = arr.size(), k = 2;
    cout << "Kth Largest element is " << kthlargest(arr, k)<<endl;
    cout << "Kth Smallest element is " << kthsmallest(arr, k)<<endl;
    return 0;
}
//TC-O(N)/SC-O(1)
*/

//Q3 SORT K SORTED ARRAY
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>sortk(vector<int>&v,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>result;
    for(int i=0;i<=k && i<v.size();i++)
    {
        pq.push(v[i]);
    }
    for(int i=k+1;i<v.size();i++)
    {
        result.push_back(pq.top());
        pq.pop();
        pq.push(v[i]);
    }
    while(!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }
    return result;
}
int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> sortedArr = sortk(arr, k);

    for (int num : sortedArr) {
        cout << num << " ";
    }
    return 0;
}
*/

//Q4 MERGE M SORTED LL
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
struct NodeCompare
{
//operator() keyword has to be mandatorily used
bool operator()(Node* a,Node* b) //Comparator-creates a min heap everytime
{
return a->data>b->data;
}
};
Node* merged(vector<Node*>lists)
{
priority_queue<Node*,vector<Node*>,NodeCompare>pq;
for(auto list : lists)
{
    if(list!=NULL)
    pq.push(list); //pushing all 3 heads
}
    Node* dummy=new Node(0);
    Node* temp=dummy;
    while(!pq.empty())
    {
        Node* smallest=pq.top();
        pq.pop();
        temp->next=smallest;
        temp=temp->next;
        if(smallest->next!=NULL)
        pq.push(smallest->next);
    }
    return dummy->next;
}
int main()
{
    Node* list1 = new Node(1);
    list1->next = new Node(4);
    list1->next->next = new Node(5);

    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    Node* list3 = new Node(2);
    list3->next = new Node(6);

    vector<Node*> lists = {list1, list2, list3};
    Node* result = merged(lists);

    while (result != NULL) {
        cout << result->data << " ";
        result = result->next;
    }
    return 0;
}
//TC-O(N*logK)/SC-O(K)
*/

//Q5 REPLACE ELEMENTS BY ITS RANK IN THE ARRAY
/*
#include <bits/stdc++.h>
using namespace std;

void replacebyrank(vector<int>&v)
{   
    int temp=1;
    map<int,int>mp;
    vector<int>b=v;
    sort(b.begin(),b.end());
    for(int i=0;i<v.size();i++)
    {
        if(mp[b[i]]==0)
        {
            mp[b[i]]=temp;
            temp++;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<mp[v[i]]<<" ";
    }
}
int main()
{
    vector<int>a={20,15,26,2,98,6};
    replacebyrank(a);
    return 0;
}
//TC-O(N)/SC-O(N)
*/

//Q6 TASK SCHEDULER
/*
#include <bits/stdc++.h>
using namespace std;

int leastscheduler(vector<char>&v,int n)
{   
    int time=0;
    unordered_map<char,int>ump;
    for(int i=0;i<v.size();i++)
    {
        ump[v[i]]++;
    }
    priority_queue<int>maxheap;
    for(auto &entry : ump)
    {
        maxheap.push(entry.second); //storing frequencing in descending order
    }
    while(!maxheap.empty())
    {
        vector<int>temp;
        int cycle=n+1; //valid number of iterations in a cycle
        int i=0;
        while(i<cycle && !maxheap.empty())
        {
            int cnt=maxheap.top(); //max time first
            maxheap.pop();
            cnt--;
            if(cnt>0)
            temp.push_back(cnt); //pushing to further push in maxheap
            time++;
            i++; //moving to next stop
        }
        for(int val : temp)
        maxheap.push(val);
        if(maxheap.empty())
        break;
        time+=(cycle-i); //adding idle time (if exists) to complete the cycle
    }
    return time;
}
int main() 
{ 
    vector<char> tasks = {'A','A','A','B','B','B'};

    int n = 2;

    // Output the least interval required to finish all tasks
    cout << leastscheduler(tasks, n) << endl;

    return 0;
}
//TC-O(NlogK)/SC-O(K)
*/

//Q7 HANDS OF STRAIGHTS
/*
#include <bits/stdc++.h>
using namespace std;

bool handpossible(vector<int>&cards,int n)
{
    if(cards.size()%n!=0)
    return false;
    map<int,int>mp;
    for(int i=0;i<cards.size();i++)
    {
        mp[cards[i]]++;
    }
    auto it=mp.begin();
    while(it!=mp.end())
    {   
        if(it->second==0)
        {
        ++it;
        continue;
        }
        int start=it->first;
        int count=it->second;
        for(int i=0;i<n;i++)
        {
            if(mp[start+i]<count)
            return false;
            mp[start+i]-=count;
        }
        ++it;
    }
    return true;
}
int main()
{
    vector<int> hand1 = {1,2,3,6,2,3,4,7,8};
    int groupSize1 = 3;
    cout <<handpossible(hand1, groupSize1) << endl;  

    vector<int> hand2 = {1,2,3,4,5};
    int groupSize2 = 4;
    cout <<handpossible(hand2, groupSize2) << endl;
    return 0;
}
//TC-O(NLOGN)/SC-O(N)
*/