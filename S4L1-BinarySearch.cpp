//Q1 BS for finding X in sorted array
//ITERATIVE IMPLEMENTATION
/*
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&v,int target)
{
    int n=v.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]==target)
        return mid;
        else if(target>v[mid])
        low=mid+1;
        else 
        high=mid-1;
    }
    return -1;
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 11;
    int ind = binarysearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
return 0;
}
*/

//RECURSIVE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&v,int low,int high,int target)
{
    int n=v.size();
    if(low>high)
    return -1;
    {
        int mid=(low+high)/2;
        if(v[mid]==target)
        return mid;
        else if(target>v[mid])
        binarysearch(v,mid+1,high,target);
        else
        binarysearch(v,low,mid-1,target);
    }
}
int search(vector<int>& nums, int target) {
    return binarysearch(nums, 0, nums.size() - 1, target);
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 16;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
return 0;
}
*/

//Q2 LOWER BOUND SEARCH
/*
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&v,int target)
{
    int n=v.size();
    int ans=n;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]>=target)
        {
            ans=mid;
            high=mid-1;
        }
        else 
        low=mid+1;
    }
    return ans;
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 12;
    int ind = binarysearch(a, target);
    cout << "The lower bound is the index " << ind<<endl;
return 0;
}
*/

//Q3 UPPER BOUND SEARCH
/*
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&v,int target)
{
    int n=v.size();
    int ans=n;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]>target)
        {
            ans=mid;
            high=mid-1;
        }
        else 
        low=mid+1;
    }
    return ans;
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 12;
    int ind = binarysearch(a, target);
    cout << "The lower bound is the index " << ind<<endl;
return 0;
}
*/

//Q4 SEARCH INSERT POSITION
//SAME AS LOWER BOUND
/*
#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&v,int target)
{
    int n=v.size();
    int ans=n;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]>=target)
        {
            ans=mid;
            high=mid-1;
        }
        else 
        low=mid+1;
    }
    return ans;
}
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 12;
    int ind = binarysearch(a, target);
    cout << "The lower bound is the index " << ind<<endl;
return 0;
}
*/

//Q5 FLOOR AND CEILING
/*
#include<bits/stdc++.h>
using namespace std;

int findfloor(int a[],int n,int x)
{
int low=0;int high=n-1;
int ans=-1;
while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]<=x)
        {
            ans=a[mid];
            low=mid+1; //look for larger index on right
            
        }
        else 
        high=mid-1;
    }
    return ans;
}

int findceil(int a[],int n,int x)
{
int low=0;int high=n-1;
int ans=-1;
while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]>=x)
        {
            ans=a[mid];
            high=mid-1; //look for smaller index on left
        }
        else
        low=mid+1;
    }
    return ans;
}

pair<int,int>getfloorAndceil(int a[],int n,int x)
{
    int f=findfloor(a, n, x);
    int c=findceil(a, n, x);
    return make_pair(f,c);
}
int main()
{
    int arr[] = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 9;
	pair<int, int> ans = getfloorAndceil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " and " << ans.second << endl;
return 0;
}
*/

//Q7 COUNT OCCURANCES
/*
#include<bits/stdc++.h>
using namespace std;

int firstoc(vector<int>&a,int n,int key)
{
    int low=0;int high=n-1;
    int first=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            first=mid;
            high=mid-1; //look for smaller index on left
        }
        else if(a[mid]<key)
        low=mid+1;
        else
        high=mid-1;   
    }
    return first;
}

int lastoc(vector<int>&a,int n,int key)
{
   int low=0;int high=n-1;
    int last=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            last=mid;
            low=mid+1; //look for larger index on right
        }
        else if(a[mid]<key)
        low=mid+1;
        else
        high=mid-1;   
    }
    return last; 
}

pair<int,int>flpos(vector<int>& arr, int n, int x)
{
    int first=firstoc(arr, n, x);
    if(first==-1) return{-1,-1};
    int last=lastoc(arr, n, x);
    return{first,last};
}

int count(vector<int>& arr, int n, int x)
{
    pair<int,int>ans=flpos(arr, n, x);
    if(ans.first==-1) return 0;
    return (ans.second-ans.first+1);
}
int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = count(arr, n, x);
    cout << "The number of occurrences is: "
         << ans << "\n";
return 0;
}
*/

//SEARCH ELEMENT IN SORTED ARRAY-1
/*
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>&v,int target)
{
    int n=v.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]==target)
        return mid;
        if(v[low]<=v[mid])
        {
            if(v[low]<=target && v[mid]>=target)
            high=mid-1;
            else
            low=mid+1;
        }
        else
        {
            if(v[mid]<=target && v[high]>=target)
            low=mid+1;
            else
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 5;
    int ans = binarysearch(arr,k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
return 0;
}
*/

//SEARCH ELEMENT IN SORTED ARRAY-2
/*
#include<bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int>&v,int target)
{
    int n=v.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]==target)
        return true;
        if(v[low]==v[mid] && v[mid]==v[high]) //edge case
        {
            low+=1;
            high-=1;
            continue;
        }
        if(v[low]<=v[mid])
        {
            if(v[low]<=target && v[mid]>=target)
            high=mid-1;
            else
            low=mid+1;
        }
        else
        {
            if(v[mid]<=target && v[high]>=target)
            low=mid+1;
            else
            high=mid-1;
        }
    }
    return false;
}
int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 11;
    int ans = binarysearch(arr,k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout <<"Target is present in the array." << "\n";
return 0;
}
*/

//MINIMUM IN ROTATED SORTED ARRAY
/*
#include<bits/stdc++.h>
using namespace std;

int findmin(vector<int>&v)
{
    int n=v.size();
    int low=0,high=n-1;
    int ans=INT_MAX;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[low]<=v[high])
        {
        ans=min(ans,v[low]);
        break;
        }
        if(v[low]<=v[mid])
        {
            ans=min(ans,v[low]);
            low=mid+1;
        }
        else
        {
            ans=min(ans,v[mid]);
            high=mid-1;
        }
    }
    return ans;
}
int main()
{
vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
int ans = findmin(arr);
cout << "The minimum element is: " << ans << "\n";   
return 0;
}
*/

//NUMBER OF TIMES ARRAY HAS BEEN ROTATED
/*
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>v)
{
    int n=v.size();
    int low=0,high=n-1;
    int ans=INT_MAX;
    int index=-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
    if(v[low]<=v[high])
    {
        if(v[low]<ans)
        {
        index=low;
        ans=v[low];
        }
        break;
    }
    if(v[low]<=v[mid])
    {
    if(v[low]<ans)
    {
    index=low;    
    ans=v[low];
    }
    low=mid+1;
    }
    if(v[mid]<=v[high])
    {
        if(v[mid]<ans)
        {
        index=mid;
        ans=v[index];
        }
        high=mid-1;
    }
    }
    return index;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = search(arr);
    cout << "The array is rotated " << ans << " times.\n";
return 0;
}
*/

//SEARCHING SINGLE ELEMENT
/*
#include<bits/stdc++.h>
using namespace std;

int single(vector<int>v)
{
    int n=v.size();
    //EDGE CASES
    if(n==1)
    return v[0];
    if(v[0]!=v[1])
    return v[0];
    if(v[n-1]!=v[n-2])
    return v[n-1];

    int low=1,high=n-2;
    while(low<=high)
    {
    int mid=(low+high)/2;
    if(v[mid]!=v[mid+1] && v[mid]!=v[mid-1])
    return v[mid];
    //if in left array
    if((mid%2==1 && v[mid]==v[mid-1])||(mid%2==0 && v[mid]==v[mid+1]))
    low=mid+1;//eliminate left half
    //if in right half
    else
    high=mid-1;//eliminate right half
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = single(arr);
    cout << "The single element is: " << ans << "\n";
return 0;
}
*/

//Q13 PEAK ELEMENT
/*
#include<bits/stdc++.h>
using namespace std;

int findpeak(vector<int>v)
{
    int n=v.size();

    //edge cases
    if(n==1)
    return 0;
    if(v[0]>v[1])
    return 0;
    if(v[n-1]>v[n-2])
    return n-1;
    int low=1,high=n-2;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1])
        return mid;
        if(v[mid]>v[mid-1])
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findpeak(arr);
    cout << "The peak is at index: " << ans << "\n";
return 0;
}
*/