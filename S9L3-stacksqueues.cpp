//Q1 NEXT GREATER ELEMENT (MONOTONIC FORM) IN STACK
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>nextgreaterele(vector<int>&nums)
{
int n=nums.size();
vector<int>nge(n,-1);
stack<int>st;
for(int i=n-1;i>=0;i--)
{
while(!st.empty() && st.top()<=nums[i])
{
    st.pop();
}
if(!st.empty())
nge[i]=st.top();
st.push(nums[i]);
}
return nge;
}
int main()
{
vector < int > v {5,7,1,2,6,0};
vector < int > res = nextgreaterele(v);
cout << "The next greater elements are" << endl;
for (int i = 0; i < res.size(); i++)
{
cout << res[i] << " ";
}
return 0;
}
//TC/SC-O(N)
*/

// NEXT GREATER ELEMENT (CIRCULAR FORM) IN STACK
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>nextgreaterele(vector<int>&nums)
{
int n=nums.size();
vector<int>nge(n,-1);
stack<int>st;
for(int i=2*n-1;i>=0;i--)
{
while(!st.empty() && st.top()<=nums[i%n])
{
    st.pop();
}
if(!st.empty())
nge[i]=st.top();
st.push(nums[i%n]);
}
return nge;
}
int main()
{
vector < int > v {5,7,1,2,6,0};
vector < int > res = nextgreaterele(v);
cout << "The next greater elements are" << endl;
for (int i = 0; i < res.size(); i++)
{
cout << res[i] << " ";
}
return 0;
}
//TC/SC-O(N)
*/

// NUMBER OF NGE TO RYT
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>nextgreaterele(vector<int>&nums)
{
int n=nums.size();
vector<int>nge(n,0);
stack<int>st;
for(int i=n-1;i>=0;i--)
{
int cnt=0;
while(!st.empty() && st.top()<=nums[i])
{
    st.pop();
}
cnt=st.size();
nge[i]=cnt;
st.push(nums[i]);
}
return nge;
}
int main()
{
vector < int > v {5,7,1,2,6,0};
vector < int > res = nextgreaterele(v);
cout << "The next greater elements are" << endl;
for (int i = 0; i < res.size(); i++)
{
cout << res[i] << " ";
}
return 0;
}
//TC/SC-O(N)
*/

// Q3 NXT SMALLER ELEMENT
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>nextsmallerele(vector<int>&nums)
{
int n=nums.size();
vector<int>nge(n,-1);
stack<int>st;
for(int i=n-1;i>=0;i--)
{
while(!st.empty() && st.top()>=nums[i])
{
    st.pop();
}
if(!st.empty())
nge[i]=st.top();
st.push(nums[i]);
}
return nge;
}
int main()
{
vector < int > v {5,7,1,2,6,0};
vector < int > res = nextsmallerele(v);
cout << "The next smaller elements are" << endl;
for (int i = 0; i < res.size(); i++)
{
cout << res[i] << " ";
}
return 0;
}
//TC/SC-O(N)
*/

// Q5 TRAPPING RAINWATER
// Better Solution
/*
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>&a)
{
    int n=a.size();
    int prefix[n],suffix[n];
    prefix[0]=a[0];
    suffix[n-1]=a[n-1];
    for(int i=1;i<n;i++)
    {
        prefix[i]=max(prefix[i-1],a[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=max(suffix[i+1],a[i]);
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        result+=min(prefix[i],suffix[i])-a[i];
    }
    return result;
}
int main()
{
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
  return 0;
}
  //TC/SC-O(N)
  */

// Optimal Solution
/*
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>&a)
{
    int n=a.size();
    int leftmax=0,rytmax=0;
    int left=0,ryt=n-1,result=0;
    while(left<=ryt)
    {
        if(leftmax<=rytmax)
        {
            if(a[left]>=leftmax)
            leftmax=a[left];
            else
            result+=leftmax-a[left];
            left++;
        }
        else
        {
            if(a[ryt]>=rytmax)
            rytmax=a[ryt];
            else
            result+=rytmax-a[ryt];
            ryt--;
        }
    }
    return result;
}
int main()
{
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
  return 0;
}
//TC-O(N)/SC-O(1)
*/

// Q7 ASTROID COLLISION
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>detcollision(vector<int>&astnum)
{
    int n=astnum.size();
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(astnum[i]>0)
        st.push(astnum[i]);
        else
        {
            while(!st.empty() && st.top()>0 && st.top()<abs(astnum[i]))
            {
                st.pop();
            }
        if(!st.empty() && st.top()==abs(astnum[i])) //for checking cases like [-8,8]
        st.pop();
        else if(st.empty() || st.top()<0)
        st.push(astnum[i]);
        }
    }
    vector<int>result(st.size());
    for(int i=st.size()-1;i>=0;i--)
    {
        result[i]=st.top();
        st.pop();
    }
    return result;
}
int main()
{
    vector<int>ast={4,7,1,1,2,-3,-7,17,15,-18,-19};
    vector<int>result=detcollision(ast);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}
TC/SC-O(N)
    */

// Q9 REMOVE K DIGITS IN A STRING TO FIND SMALLEST NUMBER
/*
#include <bits/stdc++.h>
using namespace std;

string digitrem(string number,int k)
{
string result="";
stack<char>st;
int l=number.length();
for(int i=0;i<l;i++)
{
    while(!st.empty() && k>0 && (st.top()-'0'>number[i]-'0'))
   {
    st.pop();
    k--;
   }
   st.push(number[i]);
}
while(k>0)
{
    st.pop();
    k--;
}
if(st.empty())
return "0";
while(!st.empty())
{
    result+=st.top();
    st.pop();
}
while(result.size()!=0 && result.back()=='0')
{
    result.pop_back();
}
reverse(result.begin(),result.end());
if(result.empty())
return "0";
return result;
}
int main()
{
    string s="1432219";
    int k=3;
    cout<<"Smallest possible string: "<<digitrem(s,k)<<endl;
    return 0;
}
//TC/SC-O(N)
*/

// SUM OF SUBARRAY MINIMUM
/*
#include <bits/stdc++.h>
using namespace std;

int sumofsub(vector<int>&num)
{
    int n=num.size();
    stack<int>st;
    vector<int>left(n),right(n);

    //Calculating PSE
    for(int i=0;i<=n-1;i++)
    {
        while(!st.empty() && num[st.top()]>num[i]) //in PSE = is not used
        {
            st.pop();
        }
        left[i]=st.empty()? -1 : st.top();
        st.push(i);
    }

    // clear stack before reuse
    while (!st.empty()) st.pop();

    //Calculating NSE
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && num[st.top()]>=num[i])
        {
            st.pop();
        }
        right[i]=st.empty()? n : st.top();
        st.push(i);
    }
    long long total=0;
    int mod=(int)(1e9+7); //for preventing out of bounds
    for(int i=0;i<n;i++)
    {
        long long l=i-left[i];
        long long r=right[i]-i;
        total=total+(((r*l%mod)*num[i])%mod)%mod;
    }
    return total;
}
int main()
{
    vector<int>a={1,4,6,7,3,7,8,1};
    int ans=sumofsub(a);
    cout<<"Sum of subarray minimum : "<<ans<<endl;
    return 0;
}
//TC/SC-O(N)
*/

// Q8 Sum of Subarray Ranges
/*
#include <bits/stdc++.h>
using namespace std;

int submin(vector<int>&num)
{
    int n=num.size();
    stack<int>st;
    vector<int>left(n),right(n);

    //Calculating PSE
    for(int i=0;i<=n-1;i++)
    {
        while(!st.empty() && num[st.top()]>num[i]) //in PSE = is not used
        {
            st.pop();
        }
        left[i]=st.empty()? -1 : st.top();
        st.push(i);
    }

    // clear stack before reuse
    while (!st.empty()) st.pop();

    //Calculating NSE
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && num[st.top()]>=num[i])
        {
            st.pop();
        }
        right[i]=st.empty()? n : st.top();
        st.push(i);
    }
    long long total=0;
    int mod=(int)(1e9+7); //for preventing out of bounds
    for(int i=0;i<n;i++)
    {
        long long l=i-left[i];
        long long r=right[i]-i;
        total=total+(((r*l%mod)*num[i])%mod)%mod;
    }
    return total;
}

int submax(vector<int>&num)
{
    int n=num.size();
    stack<int>st;
    vector<int>left(n),right(n);

    //Calculating PGE
    for(int i=0;i<=n-1;i++)
    {
        while(!st.empty() && num[st.top()]<num[i]) //in PSE = is not used
        {
            st.pop();
        }
        left[i]=st.empty()? -1 : st.top();
        st.push(i);
    }

    // clear stack before reuse
    while (!st.empty()) st.pop();

    //Calculating NGE
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && num[st.top()]<=num[i])
        {
            st.pop();
        }
        right[i]=st.empty()? n : st.top();
        st.push(i);
    }
    long long total=0;
    int mod=(int)(1e9+7); //for preventing out of bounds
    for(int i=0;i<n;i++)
    {
        long long l=i-left[i];
        long long r=right[i]-i;
        total=total+(((r*l%mod)*num[i])%mod)%mod;
    }
    return total;
}
int main()
{
    vector<int>a={1,4,3,2};
    int smallest=submin(a);
    int largest=submax(a);
    int ans=largest-smallest;
    cout<<"Sum of subarray ranges : "<<ans<<endl;
    return 0;
}
//TC/SC-O(N)
*/

// Q10 Largest Rectangle in a Histogram
//Approach-1 of double iteration
/*
#include <bits/stdc++.h>
using namespace std;

int sumofsub(vector<int> &num)
{
    int n = num.size();
    stack<int> st;
    vector<int> left(n), right(n);

    // Calculating PSE
    for (int i = 0; i <= n - 1; i++)
    {
        while (!st.empty() && num[st.top()] > num[i]) // in PSE = is not used
        {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // clear stack before reuse
    while (!st.empty())
        st.pop();

    // Calculating NSE
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && num[st.top()] >= num[i])
        {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int maxarea = 0;
    for (int i = 0; i < n; i++)
    {
        maxarea = max(maxarea, (num[i] * (right[i] - left[i] - 1)));
    }
    return maxarea;
}
int main()
{
    vector<int> a = {1, 4, 6, 7, 3, 7, 8, 1};
    int ans = sumofsub(a);
    cout << "Maximum area of histogram is : " << ans << endl;
    return 0;
}
// TC/SC-O(N)
*/

// AREA OF LARGEST RECTANGLE IN HISTOGRAM
//Approach-2 of single iteration
/*
#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) //if the current bar is smaller than or equal to the bar at the stack’s top, we can’t extend rectangles with that bar any further.
        //So, we compute the area with that bar as the height.
        {
          int height = histo[st.top()]; //taking initial height
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1; //taking width range as pse will be ele-1 in stack and nse was the ele itself
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};
int main() {
  vector < int > histo = {2, 1, 5, 6, 2, 3, 1};
  Solution obj;
  cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
  return 0;
}
  TC/SC-O(N)
  */

//Q11 MAXIMAL RECTANGLES

#include <bits/stdc++.h>
using namespace std;

int lhist(vector<int> &num)
{
    int n = num.size();
    stack<int> st;
    vector<int> left(n), right(n);

    // Calculating PSE
    for (int i = 0; i <= n - 1; i++)
    {
        while (!st.empty() && num[st.top()] > num[i]) // in PSE = is not used
        {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // clear stack before reuse
    while (!st.empty())
        st.pop();

    // Calculating NSE
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && num[st.top()] >= num[i])
        {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    int maxarea = 0;
    for (int i = 0; i < n; i++)
    {
        maxarea = max(maxarea, (num[i] * (right[i] - left[i] - 1)));
    }
    return maxarea;
}

int maxrect(vector<vector<int>>&rect,int n,int m) //correct way to declare a 2D array
{   
    vector<int>psum(m,0); //1-D prefix sum vector equal to number of columns
    int maxarea=0;
    for(int i=0;i<n;i++)
    {   
        int sum=0;
        for(int j=0;j<m;j++)
        {
            if(rect[i][j]==0)
            psum[j]=0;
            else
            psum[j]+=1;
        }
        maxarea=max(maxarea,lhist(psum));
    }
    return maxarea;
}
int main()
{
    vector<vector<int>>rect=
    {
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };
    cout<<"Area of maximal rectangle is "<<maxrect(rect,rect.size(), rect[0].size());
    return 0;
}
//TC/SC-O(N*M)