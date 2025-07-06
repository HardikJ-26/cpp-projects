//Q1 PASCAL'S TRIANGLE
//VARIETY 1- PRINTING A SPECIFIED NO. IN PT
//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int ncr(int n,int r)
{
    long long res=1;
    for(int i=0;i<r;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int main()
{   
    int n,r;
    cout<<"Enter the value of n at desired position"<<endl;
    cin>>n;
    cout<<"Enter the value of r at desired position"<<endl;
    cin>>r;
    long long ans=ncr(n,r);
    cout<<"Value at desired position is "<<ans<<endl;
return 0;
}
*/

//VARIETY 2-PRINTING NTH ROW
//BRUTE FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int ncr(int n,int r)
{
    long long res=1;
    for(int i=0;i<r;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
void nrow(int n)
{   
    for(int i=1;i<=n;i++)
    cout<<ncr(n-1,i-1)<<" ";
}
int main()
{   
    int n,r;
    cout<<"Enter the value of nth row value"<<endl;
    cin>>n;
    long long ans=nrow(n);
    cout<<"Value at desired position is "<<ans<<endl;
return 0;
}
*/

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

void pascal(int n)
{
    long long ans=1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++)
    {
        ans*=(n-i);
        ans/=i;
        cout<<ans<<" ";
    }
}
int main()
{   
    int n,r;
    cout<<"Enter the value of nth row value"<<endl;
    cin>>n;
    pascal(n);
return 0;
}
*/

//VARIETY 3-PRINT PT UPTO NTH ROW
/*
#include<bits/stdc++.h>
using namespace std;

int ncr(int n,int r)
{
    long long res=1;
    for(int i=0;i<r;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(ncr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}
int main()
{   
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
return 0;
}
*/
//OPTIMAL APPROACH
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
*/

//Q2 MAJORITY ELEMENT(>N/3)
/*
#include<bits/stdc++.h>
using namespace std;

vector<int>findmaj(vector<int>v,int n)
{
int cnt1=0,cnt2=0;
int el1=INT16_MIN,el2=INT16_MIN;
for(int i=0;i<n;i++)
{
    if(cnt1==0 && v[i]!=el2)
    {
        cnt1=1;
        el1=v[i];
    }
    if(cnt2==0 && v[i]!=el1)
    {
        cnt2=1;
        el2=v[i];
    }
    else if(v[i]==el1)
    cnt1++;
    else if(v[i]==el2)
    cnt2++;
    else
    {
        cnt1--;
        cnt2--;
    }
}
vector<int>ls;
cnt1=0,cnt2=0;
for(int i=0;i<n;i++)
{
    {
        if (v[i] == el1) cnt1++;
        if (v[i] == el2) cnt2++;
    }
}
int maj=(int)(n/3)+1;
if (cnt1 >= maj) ls.push_back(el1);
if (cnt2 >= maj) ls.push_back(el2);
return ls;
}
int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    int n=arr.size();
    vector<int> ans = findmaj(arr,n);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
*/

//Q3 3-SUM PROBLEM
/*
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>tsum(vector<int>v,int n)
{
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++)
    {
      if(i>0 && v[i]==v[i-1])
      continue;
        int j=i+1;
        int k=n-1;
        while(j<k)
        {
           int sum=v[i]+v[j]+v[k];
        if(sum<0)
        j++;
        else if(sum>0)
        k--;
        else
        {
            vector<int>temp={v[i],v[j],v[k]};
            ans.push_back(temp); //pushing for clubbibg as matrix
            j++;
            k--;
            //skipping duplicates
            while (j < k && v[j] == v[j - 1]) j++;
            while (j < k && v[k] == v[k + 1]) k--;
        }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = tsum(arr,n);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
return 0;
}
*/

//4SUM PROBLEM
/*
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>fsum(vector<int>v,int target)
{
    int n=v.size();
    vector<vector<int>>ans;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
      if(i>0 && v[i]==v[i-1])
      continue;
      for(int j=i+1;j<n;j++)
    {
      if(j>i+1 && v[j]==v[j-1])
      continue;
    
        int k=j+1;
        int l=n-1;
        while(k<l)
        {
           int sum=v[i]+v[j]+v[k]+v[l];
        if(sum<target)
        k++;
        else if(sum>target)
        l--;
        else
        {
            vector<int>temp={v[i],v[j],v[k],v[l]};
            ans.push_back(temp); //pushing for clubbing as matrix
            k++;
            l--;
            //skipping duplicates
            while (k<l && v[k] == v[k - 1]) k++;
            while (k<l && v[l] == v[l + 1]) l--;
        }
        }
    }  
}
return ans;
}
int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fsum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
return 0;
}
*/

//LONGEST SUBARRAY EQUAL TO ZERO
/*
#include<bits/stdc++.h>
using namespace std;

int zerosub(vector<int>v,int n)
{
    unordered_map<int,int>mp;
    int maxlen=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==0)
        maxlen=i+1;
        else if(mp.find(sum)!=mp.end())
        {
            maxlen=max(maxlen,i-mp[sum]);
        }
        else
        mp[sum]=i;
    }
    return maxlen;
}
int main()
{
    vector<int> nums = {1, 2, -2, 4, -4};
    int n=nums.size();
    int ans = zerosub(nums, n);
    cout << "Largest subarray equal to zero is "<<ans<<endl;
return 0;
}
*/

//NUMBER OF ARRAYS WITH XOR K
/*
#include<bits/stdc++.h>
using namespace std;

int xorn(vector<int>&v,int n,int k)
{
int xr=0;
map<int,int>mp;
mp[xr]++;
int cnt=0;
for(int i=0;i<n;i++)
{
    xr=xr^v[i]; //prefix xor till index i
    int x=xr^k; //formula for front xor
    cnt+=mp[x]; //adding occurance to counter
    mp[xr]++; //updating key of xr
}
return cnt;
}
int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int n=a.size();
    int ans = xorn(a,n,k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
return 0;
}
*/

//MERGE OVERLAPPING SUBINTERVALS
/*
//BRUTE FORCE APPROACH
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>mergeint(vector<vector<int>>&v)
{
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        int start=v[i][0];
        int end=v[i][1];
        if(!ans.empty() && end<=ans.back()[1]) //skipping merged intervals
        {
            continue;
        }
        //checking rest of the intervals
        for(int j=i+1;j<n;j++)
        {
            if(v[j][0]<=end)
            end=max(end,v[j][1]); //finding higher end in intervals
            else
            break; //as array is sorted so no other change of solution is possible
        }
        ans.push_back({start,end});
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeint(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
return 0;
}
*/

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>mergeint(vector<vector<int>>&v)
{
    int n=v.size();
    sort(v.begin(),v.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || v[i][0]>ans.back()[1]) //skipping merged intervals
        {
            ans.push_back(v[i]);
        }
        else
        {
        ans.back()[1]=max( ans.back()[1],v[i][1]);
        }
}
return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeint(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
return 0;
}
*/

//Q8 MERGE TWO SORTED ARRAYS
//OPTIMAL APPROACH-1
/*
#include<bits/stdc++.h>
using namespace std;

void merge(long long a1[],long long a2[],int n,int m)
{
    int left=n-1;
    int right=0;
    while(left>=0 && right<m)
    {
        if(a1[left]>a2[right])
        {
            swap(a1[left],a2[right]);
            left--;
            right++;
        }
        else
        break;
    }
    sort(a1,a1+n);
    sort(a2,a2+m);
}
int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
return 0;
}
*/

//OPTIMAL APPROACH-2
/*
#include<bits/stdc++.h>
using namespace std;

void swapcheck(long long a1[],long long a2[],int ind1,int ind2)
{
if(a1[ind1]>a2[ind2])
swap(a1[ind1],a2[ind2]);
}

void merge(long long a1[],long long a2[],int n,int m)
{
    int len=n+m;
    int gap=(len + 1) / 2;
    while(gap>0)
    {
    int left=0;
    int right=left+gap;
    while(right<len)
    {
        if(left<n && right>=n)
        swapcheck(a1,a2,left,right-n);
        else if(left>=n)
        swapcheck(a2,a2,left,right-n);
        else
        swapcheck(a1,a1,left,right);
        left++,right++;
    }
        if(gap==1)
        break;
        gap=(gap + 1) / 2;
    }
}
int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
return 0;
}
*/

//Q10 COUNT INVERSIONS
/*
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&v,int low,int mid,int high)
{
    vector<int>temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high)
    {
        if(v[left]<=v[right])
        {
        temp.push_back(v[left]);
        left++;
        }
        else
        {
            temp.push_back(v[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid)
    {
       temp.push_back(v[left]);
        left++; 
    }
    while (right<=high)
    {
          temp.push_back(v[right]);
          right++;
    }
    for(int i=low;i<high;i++)
    {
      v[i]=temp[i-low];
    }
    return cnt;
}

int mergesort(vector<int>&v,int low,int high)
{
    int cnt=0;
    if(low>=high)
    {
        return cnt;
    }
    int mid=(low+high)/2;
    cnt+=mergesort(v,low,mid);
    cnt+=mergesort(v,mid+1,high);
    cnt+=merge(v,low,mid,high);
    return cnt;
}
int inversions(vector<int>&a, int n)
{
    return mergesort(a,0,n-1);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = inversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
return 0;
}
*/

//Q9 Find the repeating and missing numbers
//OPTIMAL APPROACH 1
/*
#include<bits/stdc++.h>
using namespace std;

vector<int>findnum(vector<int>v)
{
long long n=v.size();
long long sumo=(n*(n+1))/2;
long long sumo2=(n*(n+1)*(2*n+1))/6;
long long sumc=0,sumc2=0;
for(int i=0;i<n;i++)
{
sumc+=v[i];
sumc2+=(long long)v[i]*(long long)v[i];
}
long long val1=sumo-sumc;//X-Y
long long val2=sumo2-sumc2;//X2-Y2
val2/=val1;//X+Y
long long x=(val1+val2)/2;
long long y=x-val1;
return {(int)x,(int)y};
}
int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findnum(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
return 0;
}
*/

//OPTIMAL APPROACH 2
/*
#include<bits/stdc++.h>
using namespace std;
vector<int>findnum(vector<int>v)
{
int n=v.size();
int xr=0;
for(int i=0;i<n;i++) //finding xor of all elements
{
    xr^=v[i];
    xr^=i+1;
}
int num=(xr & ~(xr-1)); //finding bitwise difference
int zero=0;
int one=0;
for(int i=0;i<n;i++)
{
    if((v[i] & num)!=0)
    one^=v[i]; //xoring in one club
    else
    zero^=v[i]; //xoring in zero club
}
for(int i=1;i<=n;i++)
{
    if((i & num)!=0)
    one^=i;
    else
    zero^=i;
}
int cnt=0;
for(int i=0;i<n;i++)
{
    if(v[i]==zero)
    cnt++;
}
if(cnt==2)
return {zero,one};
else
return {one,zero};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findnum(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
return 0;
}
*/

//REVERSE PAIRS
/*
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); //Modification
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int team(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}
*/

//MAXIMUM PRODUCT SUBARRAY
//OPTIMAL APPROACH-1
/*
#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1; //dividing array with zero as borderpoint
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}
*/

//OPTIMAL APPROACH-2
/*
#include<bits/stdc++.h>
using namespace std;

int maxprod(vector<int>&v)
{
int prod1=v[0],prod2=v[0],result=v[0];
for(int i=1;i<v.size();i++)
{
    int temp1=prod1*v[i];
    int temp2=prod2*v[i];
    prod1=max({v[i],temp1,temp2});
    prod2=min({v[i],temp1,temp2});
    result=max(result,prod1);
}
return result;
}
int main()
{
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxprod(nums);
return 0;
}
*/