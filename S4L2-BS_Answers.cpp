//Q1 FINDING SQUARE ROOT USNG BS
/*
#include<bits/stdc++.h>
using namespace std;

int sqroot(int n)
{
    int low=0,high=n-1;
    while(low<=high)
    {
      long long mid=(low+high)/2;
      long long val=mid*mid;
      if(val<=(long long)n)
      low=mid+1;
      else
      high=mid-1; 
    }
    return high; //bcoz low would have crossed n
}
int main()
{
    int n = 28;
    int ans = sqroot(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
return 0;
}
*/

//Q2 NTH ROOT USING BS
/*
#include<bits/stdc++.h>
using namespace std;

int solve(int mid,int n,int m)
{
long long ans=1;
for(int i=1;i<=n;i++)
{
ans*=mid;
if(ans>m)
return 2;
}
if(ans==m)
return 1;
return 0;
}

int nroot(int n,int m)
{
    int low=0,high=m-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int val=solve(mid,n,m);
        if(val==1)
        return mid;
        else if(val==0)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}
int main()
{
    int n = 3, m = 68;
    int ans = nroot(n, m);
    cout << "The answer is: " << ans << "\n";
return 0;
}
*/

//Q3 KOKO EATING BANANAS
//BRUTE-FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int findmax(vector<int>v)
{
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>maxi)
        maxi=v[i];
    }
    return maxi;
}

int timeperpile(vector<int>v,int hourly)
{
    int totaltime=0;
    for(int i=0;i<v.size();i++)
    {
        totaltime+=ceil((double)v[i]/(double)hourly);
    }
    return totaltime;
}

int minrate(vector<int>v,int h)
{
int maxi=findmax(v);
for(int i=1;i<=maxi;i++)
{
    int reqtime=timeperpile(v,i);
    if(reqtime<=h)
    return i;
}
return maxi;
}
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minrate(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
return 0;
}
*/

//OPTIMAL APPROACH-BS
/*
#include<bits/stdc++.h>
using namespace std;

int findmax(vector<int>v)
{
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>maxi)
        maxi=v[i];
    }
    return maxi;
}

int timeperpile(vector<int>v,int hourly)
{
    int totaltime=0;
    for(int i=0;i<v.size();i++)
    {
        totaltime+=ceil((double)v[i]/(double)hourly);
    }
    return totaltime;
}

int minrate(vector<int>v,int h)
{
int high=findmax(v);
int low=1;
while(low<=high)
{   
    int mid=(low+high)/2;
    int reqtime=timeperpile(v,mid);
    if(reqtime<=h)
    high=mid-1;
    else
    low=mid+1;
}
return low;
}
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minrate(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
return 0;
}
*/

//MINIMUM NUMBER OF DAYS TO MAKE M BOUQUETS
//BRUTE FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>v,int day,int k,int m)
{
    int n=v.size();
    int cnt=0,nob=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]<=day)
        cnt++;
        else
        {
        nob+=(cnt/k);
        cnt=0;
        }
     }
     nob+=(cnt/k);
     if(nob>=m)
     return true;
     else
     return false;
    }

int bouquet(vector<int>v,int k,int m)
{
    long long val=m*1ll*k*1ll;
    int n=v.size();
    if(val>n)
    return -1;
    int maxi=INT_MIN, mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,v[i]);
        mini=min(mini,v[i]);
    }
    for(int i=mini;i<=maxi;i++)
    {
        if(ispossible(v,i,k,m))
        return i;
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = bouquet(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
return 0;
}
*/

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>v,int day,int k,int m)
{
    int n=v.size();
    int cnt=0,nob=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]<=day)
        cnt++;
        else
        {
        nob+=(cnt/k);
        cnt=0;
        }
     }
     nob+=(cnt/k);
     if(nob>=m)
     return true;
     else
     return false;
    }

int bouquet(vector<int>v,int k,int m)
{
    long long val=m*1ll*k*1ll;
    int n=v.size();
    if(val>n)
    return -1;
    int maxi=INT_MIN, mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,v[i]);
        mini=min(mini,v[i]);
    }
    int low=mini;
    int high=maxi;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ispossible(v,mid,k,m))
        high=mid-1;
        else
        low=mid+1;
    }
    return low;
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = bouquet(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
return 0;
}
*/

//Q5 FIND SMALLEST DIVISOR
//BRUTE FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int smalldivi(vector<int>v,int limit)
{
    int n=v.size();
    int maxi=*max_element(v.begin(),v.end());
    for(int i=1;i<=maxi;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
        sum+=ceil((double)v[j]/(double)i);
        }
        if(sum<=limit)
        return i;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smalldivi(arr, limit);   
    cout << "The minimum divisor is: " << ans << "\n";
return 0;
}
*/

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int sumdiv(vector<int>v,int div)
{       int n=v.size();
        int sum=0;
        for(int j=0;j<n;j++)
        {
        sum+=ceil((double)v[j]/(double)div);
        }
        return sum;
    }

int smalldivi(vector<int>v,int limit)
{
    int n=v.size();
    if(n>limit)
    return -1;
    int low=1;
    int high=*max_element(v.begin(),v.end());
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(sumdiv(v,mid)<=limit)
        high=mid-1;
        else
        low=mid+1;
    }
    return low;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smalldivi(arr, limit);   
    cout << "The minimum divisor is: " << ans << "\n";
return 0;
}
*/

//KTH MISSING ELEMENT
/*
#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
*/

//Q6 CAPACITY TO SHIP PACAKGES WITHIN D DAYS
/*
#include<bits/stdc++.h>
using namespace std;

int finddays(vector<int>v,int checkcap)
{
int days=1,load=0; //load is weight already on the ship
int n=v.size();
for(int i=0;i<n;i++)
{
if(v[i]+load<=checkcap)
load+=v[i]; //adding more weight on same day
else
{
    load=v[i]; //refresh load
    days++; //adding weight on next day
}
}
return days;
}
int mincap(vector<int>v,int daysable)//vector is of weights
{
int n=v.size();
int low=*max_element(v.begin(),v.end());
int high=accumulate(v.begin(),v.end(),0); //sum of all weights
while(low<=high)
{
    int mid=(low+high)/2; //hit and trail weight capacity
    int posday=finddays(v,mid);
    if(posday<=daysable)
    high=mid-1;
    else
    low=mid+1;
}
return low;
}
int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = mincap(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
return 0;
}
*/

//Q8 ALLOCATION OF MINIMUM NUMBER OF PAGES
/*
#include<bits/stdc++.h>
using namespace std;

int countstds(vector<int>v,int pages)
{
int n=v.size(),currentpages=0;
int curstds=1;
for(int i=0;i<n;i++)
{
    if(currentpages+v[i]<=pages)
    currentpages+=v[i];
    else
    {
    currentpages=v[i];
    curstds+=1;
    }
}
return curstds;
}
int bookdist(vector<int>v,int stds)
{
    int n=v.size();
    if(n<stds)
    return -1;
    int low=*max_element(v.begin(),v.end());
    int high=accumulate(v.begin(),v.end(),0);
    while(low<=high)
    {
        int mid=(low+high)/2;
        int students=countstds(v,mid);
        if(students<=stds)
        high=mid-1;
        else
        low=mid+1;
    }
    return low;
}
int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = bookdist(arr,m);
    cout << "The answer is: " << ans << "\n";
return 0;
}
*/

//Q10 SPLIT ARRAY-LARGEST SUM
/*
#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
*/

//Q11 PAINTER'S PROBLEM
/*
#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
*/

//Q8 AGGRESSIVE COWS
/*
#include<bits/stdc++.h>
using namespace std;

int cowdistance(vector<int>v,int stall,int cows)
{
    int cntcow=1; //no. of cows placed
    int lastcow=v[0]; //position of last cow placed
    for(int i=1;i<v.size();i++)
    {
        if((v[i]-lastcow)>=stall)
       { 
        cntcow++;
        lastcow=v[i];
       }
    if(cntcow>=cows)
    return true;
    }
    return false;
}
int maxdistance(vector<int>v,int tcows)
{
    int n=v.size();
    sort(v.begin(),v.end());
    int low=1,high=v[n-1]-v[0]; //minimum distance can be 1 and max be total length
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(cowdistance(v,mid,tcows)==true) //mid is some intermediatry length
        low=mid+1;
        else
        high=mid-1;
    }
    return high;
}
int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = maxdistance(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
return 0;
}
*/

//MINIMISE MAX DISTANCE BTW GAS STATIONS
/*
#include<bits/stdc++.h>
using namespace std;

int nog(vector<int>v,long double dist)
{
    int n=v.size();
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        long double gap=v[i]-v[i-1];
        cnt+=(int)(gap/dist); //tells need for stations
    }
    return cnt;
}
long double minmaxdist(vector<int>v,int k)
{
int n=v.size();
long double low=0,high=0; //high is max distance btw 2 stations
for(int i=0;i<n-1;i++)
{
    high=max(high,(long double)v[i+1]-v[i]); //to keep track of largest gap
}
long double dif=1e-6;
while(high-low>dif)
{
    long double mid=(low+high)/(2.0);
    int cnt=nog(v,mid);
    if(cnt>k) //to check if required gas stations are inserted
    low=mid; //too small distance-->larger value required
    else
    high=mid; //valid,now checking for smaller max distance
}
return high;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minmaxdist(arr, k);
    cout << "The answer is: " << ans << "\n";
return 0;
}
*/