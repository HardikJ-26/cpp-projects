//Q1 N-MEETINGS IN A ROOM
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
vector<int>maxMeetings(vector<int>&start,vector<int>&end)
{
    vector<tuple<int,int,int>>meetings;
    for(int i=0;i<start.size();i++)
    {
        meetings.push_back({end[i],start[i],i+1});
    }
    sort(meetings.begin(),meetings.end());
    vector<int>result;
    int lastend=-1;
    for(auto m : meetings)
    {
        int e=get<0>(m);
        int s=get<1>(m);
        int idx=get<2>(m);
        if(s>lastend)
        {
            result.push_back(idx);
            lastend=e;
        }
    }
    return result;
}
};
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    Solution sol;
    vector<int> res = sol.maxMeetings(start, end);

    for (int idx : res) cout << idx << " ";
    return 0;
}
//TC-O(nlogn)/SC-O(n)
*/

//Q2  JUMP GAME-1
/*
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
bool canJump(vector<int>& nums) 
{
    int maxindex=0;
    for(int i=0;i<nums.size();i++)
    {
        if(i>maxindex)
        return false;
        maxindex=max(maxindex,i+nums[i]);
    }
    return true;
}
};
int main()
{
    vector<int> nums = {4, 3, 7, 1, 2};

    cout << "Array representing maximum jump from each index: ";
    for (int val : nums) cout << val << " ";
    cout << endl;

    Solution game;
    bool ans = game.canJump(nums);

    if (ans)
        cout << "It is possible to reach the last index." << endl;
    else
        cout << "It is not possible to reach the last index." << endl;
    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q3 JUMP GAME-2
/*
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
int jump(vector<int>& nums) 
{
    int jumps=0,farthest=0,currentend=0;
    for(int i=0;i<nums.size()-1;i++)
    {
        farthest=max(farthest,i+nums[i]);
        if(i==currentend) //end of an interval so a new jump is required
        {
        jumps++;
        currentend=farthest; //need to update farthest in interval
        }
    }
    return jumps;
}
};
int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum jumps required: " << sol.jump(nums) << endl;
    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q4 NUMBER OF PLATFORMS NEEDED
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int stations(int n,int arr[],int dep[])
{
    sort(arr,arr+n);
    sort(dep,dep+n);
    int platforms=1;
    int result=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //arrival ho rha hai
        {
        platforms++;
        i++;
        }
        else //departure ho rha hai
        {
            platforms--;
            j++;
        }
        result=max(result,platforms);
    }
    return result;
}
};
int main()
{
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    cout << "Minimum number of Platforms required is " << obj.stations(n, arr, dep) << endl;
    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q5 JOB SEQUENCING PROBLEM
/*
#include <bits/stdc++.h>
using namespace std;

struct Job
{
int id;
int deadl;
int profit;
};
class Solution
{
public:
bool static comp(Job a,Job b)
{
    return (a.profit>b.profit);
}
pair<int,int>scheduling(Job a[],int n)
{
    sort(a,a+n,comp);
    int maxi=a[0].deadl;
    for(int i=1;i<n;i++)
    {
        if(a[i].deadl>maxi)
        maxi=a[i].deadl;
    }
    vector<int>slot(maxi+1,-1);
    int countjobs=0,maxprofit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=a[i].deadl;j>0;j--)
        {
            if(slot[j]==-1)
            {
            slot[j]=i;
            countjobs++;
            maxprofit+=a[i].profit;
            break;
            }
        }
    }
    return make_pair(countjobs,maxprofit);
}
};
int main()
{
    int n = 4;
   // Define jobs with id, deadline, and profit
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   pair < int, int > ans = ob.scheduling(arr, n);

   cout << ans.first << " " << ans.second << endl;
    return 0;
}
//TC-O(n^2)/SC-O(n)
*/

//Q7 SHORTEST JOB SCHEDULING FIRST
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
float averageWaitingTime(vector<int>&jobs)
{
    sort(jobs.begin(),jobs.end());
    float waitTime=0;
    int totaltime=0;
    int n=jobs.size();
    for(int i=0;i<n;i++)
    {
        waitTime+=totaltime;
        totaltime+=jobs[i];
    }
    return waitTime/n;
}
};
int main()
{
    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Array Representing Job Durations: ";
    for (int job : jobs) cout << job << " ";
    cout << endl;

    Solution sjf;
    float ans = sjf.averageWaitingTime(jobs);

    cout << "Average waiting time: " << ans << endl;
    return 0;
}
//TC-O(nlogn)/SC-O(1)
*/

//Q6 CANDY DISTRIBUTION
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int candy(vector<int>&ratings)
{
    int n=ratings.size();
    int candies=n;
    int i=1;
    while(i<n)
    {
        if(ratings[i]==ratings[i-1])
        {
            i++;
            continue;
        }
        int peak=0;
        while(i<n && ratings[i]>ratings[i-1])
        {   
            peak++;
            candies+=peak;
            i++;
        }
        int valley=0;
        while(i<n && ratings[i]<ratings[i-1])
        {   
            valley++;
            candies+=valley;
            i++;
        }
        candies-=min(peak,valley);
    }
    return candies;
}
};
int main()
{
    Solution sol;

    vector<int> ratings = {1, 3, 6, 8, 9, 5, 3};

    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q8 LRU CACHE
/*
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
class Node
{
public:
int key;
int value;
Node* next;
Node* prev;
Node(int key_,int val_)
{
key=key_;
value=val_;
prev=nullptr;
next=nullptr;
}
};
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);
int capacity;
unordered_map<int,Node*>m;
LRUCache(int cap)
{
    capacity=cap;
    head->next=tail;
    tail->prev=head;
}
void addnode(Node* newnode)
{
    Node* temp=head->next;
    newnode->next=temp;
    newnode->prev=head;
    head->next=newnode;
    temp->prev=newnode;
}
void deletenode(Node* delnode)
{
    delnode->prev->next=delnode->next;
    delnode->next->prev=delnode->prev;
}
int get(int key)
{
    if(m.find(key)!=m.end())
    {
        Node* resNode=m[key];
        int res=resNode->value;
        m.erase(key);
        deletenode(resNode);
        addnode(resNode);
        m[key]=head->next;
        return res;
    }
    return -1;
}
void put(int key,int value)
{
    if(m.find(key)!=m.end())
    {
        Node* existingNode=m[key];
        m.erase(key);
        deletenode(existingNode);
    }
    if(m.size()==capacity)
    {
        m.erase(tail->prev->key);
        deletenode(tail->prev);
    }
    addnode(new Node(key,value));
    m[key]=head->next;
}
};
int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl; 

    cache.put(3, 3);

    cout << cache.get(2) << endl; 
    cache.put(4, 4);
    cout << cache.get(1) << endl; 
    cout << cache.get(3) << endl; 

    cout << cache.get(4) << endl; 
    return 0;
}
//TC-O(1)/SC-O(n)
*/

//Q9 INSERT INTERVALS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{  
   vector<vector<int>>result;
   int i=0,n=intervals.size();
   while(i<n && intervals[i][1]<newInterval[0])
   {
        result.push_back(intervals[i]);
        i++;
   }
   while(i<n && intervals[i][0]<=newInterval[1])
   {
        newInterval[0]=min(newInterval[0],intervals[i][0]);
        newInterval[1]=max(newInterval[1],intervals[i][1]);
        i++;
   }
   result.push_back(newInterval);
   while(i<n)
   {
        result.push_back(intervals[i]);
        i++;
   }
   return result;
}
};
int main()
{
    Solution sol;

    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };

    vector<int> newInterval = {2, 5};

    vector<vector<int>> result = sol.insert(intervals, newInterval);

    cout << "Resulting intervals:\n";
    for (auto &interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
//TC/SC-O(n)
*/

//Q10 MERGE INTERVALS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
sort(intervals.begin(),intervals.end());
vector<vector<int>>merged;
for(auto interval : intervals)
{
    if(merged.empty() || merged.back()[1]<interval[0])
    merged.push_back(interval);
    else
    merged.back()[1]=max(merged.back()[1],interval[1]);
}
return merged;
}
};
int main()
{
    Solution sol;
    vector<vector<int>> intervals = 
    {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };

    vector<vector<int>> result = sol.merge(intervals);

    for (auto v : result) {
        cout << "[" << v[0] << "," << v[1] << "] "; }
    
    return 0;
}
//TC-O(nlogn)/SC-O(n)
*/

//Q11 NON-OVERLAPPING INTERVALS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(),intervals.end(),[](auto &a,auto &b)
    {
        return a[1]<b[1];
    });
    int count=0;
    int prevend=intervals[0][1];
    for(int i=1;i<intervals.size();i++)
    {
        if(intervals[i][0]<prevend)
        count++;
        else
        {
            prevend=intervals[i][1];
        }
    }
    return count;
}
};
int main() 
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {1, 2}};
    cout << "Minimum number of intervals to remove: " << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
//TC-O(nlogn)/SC-O(1)
*/

//EQ MINIMISE MAXIMUM LATENESS
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> jobs(n); 
    // jobs[i] = {processing_time, deadline}

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    // Sort jobs by increasing deadline (EDD rule)
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    int currentTime = 0;
    int maxLateness = INT_MIN;

    for (int i = 0; i < n; i++) {
        currentTime += jobs[i].first;           // completion time
        int lateness = currentTime - jobs[i].second;
        maxLateness = max(maxLateness, lateness);
    }

    cout << maxLateness << endl;
    return 0;
}
//TC-O(nlogn)/SC-O(n)
*/
