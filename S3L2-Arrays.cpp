//Q1 TWO SUM PROBLEM
/*
#include<bits/stdc++.h>
using namespace std;

pair<int,int> twosum(int num,vector<int>&a,int target)
{
    sort(a.begin(),a.end());
    int left=0,right=num-1;
    while(left<right)
    {
        int sum=a[left]+a[right];
        if(sum==target)
        return {left,right};
        else if(sum<target)
        left++;
        else
        right--;
    }
    return {0,0};
}
int main()
{
  int n,target;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter the target sum"<<endl;
  cin>>target;
  pair<int,int> ans=twosum(n,a,target);
  if(ans.first!=0 || ans.second!=0)
  cout<<"Number found at "<<ans.first<<" and "<<ans.second<<" indexing";
  else
  cout<<"Numbers not found";
return 0;
}
*/

//Q2 SORTING 0s,1s,2s
//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

void sortarray(vector<int>&a,int n)
{
  int low=0,mid=0,high=n-1;
  while(mid<=high)
  {
    if(a[mid]==0)
    {
      swap(a[low],a[mid]);
      low++;
      mid++;
    }
    else if(a[mid]==1)
    {
      mid++;
    }
    else
    {
      swap(a[mid],a[high]);
      high--;
    }
  }
}
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sortarray(a,n);
  cout << "After sorting:" << endl;
  for (int i = 0; i < n; i++) {
  cout << a[i] << " ";
}
return 0;
}
*/

//Q3 MAJORITY ELEMENT (>N/2)
/*
#include<bits/stdc++.h>
using namespace std;

int majele(vector<int> v)
{
  int n=v.size();
  int cnt=0,el;
  for(int i=0;i<n;i++)
  {
    if(cnt==0)
    {
    el=v[i];
    cnt=1;
    }
    else if(v[i]==el)
    cnt++;
    else
    cnt--;
  } //till here we find the probable candidate but now have to check for majority(if it exists)
  cnt = 0;
  for(int i = 0; i < n; i++)
    {
        if(v[i] == el)
        cnt++;
    }
  if(cnt>n/2)
  return el;
  else
  return -1;
}

int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int> a(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout << "Majority element is " <<  majele(a) <<endl;
  return 0;
}
*/

//Q4 MAXIMUM SUBARRAY SUM P1
/*
#include<bits/stdc++.h>
using namespace std;

long long maxsum(int a[],int n)
{
  long long maxi= LONG_MIN;
  long long sum=0;
  for(int i=0;i<n;i++)
  {
    sum+=a[i];
    if(sum>maxi)
    maxi=sum;
    else if(sum<0)
    sum=0;
  }
  return maxi;
}
int main()
{
int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout << "Maxium subarray sum is " <<  maxsum(a,n) <<endl;
return 0;
}
*/

//Q5 FOR PRINTING THE SUBARRAY
/*
#include<bits/stdc++.h>
using namespace std;

long long maxsum(int a[],int n)
{
  long long maxi= LONG_MIN;
  long long sum=0;
  int start=0;
  int ansstart=-1,ansend=-1;
  for(int i=0;i<n;i++)
  { 
    if(sum==0)
    start=i;
    sum+=a[i];
    if(sum>maxi)
    {
    maxi=sum;
    ansstart=start;
    ansend=i;
    }
    else if(sum<0)
    sum=0;
  }
  cout << "The subarray is: [";
    for (int i = ansstart; i <= ansend; i++) {
        cout << a[i] << " ";
    }
    cout << "]\n";
  return maxi;
}
int main()
{
int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout << "Maxium subarray sum is " <<  maxsum(a,n) <<endl;
return 0;
}
*/

//Q6 STOCK BUY OR SELL
/*
#include<bits/stdc++.h>
using namespace std;

int maxprofit(vector<int>v)
{
  int maxpro=0,minp=INT_MAX;
  int n=v.size();
  for(int i=0;i<n;i++)
  {
    minp=min(minp,v[i]);
    maxpro=max(maxpro,v[i]-minp);
  }
  return maxpro;
}
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  cout << "Maximum profit is " <<  maxprofit(v) <<endl;
return 0;
}
*/

//Q7 REARRAGE ARRAY WITH ALTERNATING +VE AND -VE NUMBERS(EQUAL CASE)
//BRUTE FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

vector<int>rearrange(vector<int>v,int n)
{
vector<int>pos;
vector<int>neg;
for(int i=0;i<n;i++)
{
  if(v[i]>0)
  pos.push_back(v[i]);
  else
  neg.push_back(v[i]);
}
for(int i=0;i<n/2;i++)
{
  v[2*i]=pos[i];
  v[2*i+1]=neg[i];
}
return v;
}
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  vector<int> ans=rearrange(v,n);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }
return 0;
}
*/

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

vector<int>rearrange(vector<int>v,int n)
{
  vector<int>ans(n);
int pos=0;
int neg=1;
for(int i=0;i<n;i++)
{
  if(v[i]>0)
  {
    ans[pos]=v[i];
    pos+=2;
  }
  else
  {
    ans[neg]=v[i];
    neg+=2;
  }
 }
  return ans;
}
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  vector<int> ans=rearrange(v,n);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }
return 0;
}
*/

//IF +VE AND -VE NUMBERS ARE NOT EQUAL
/*
#include<bits/stdc++.h>
using namespace std;

vector<int>rearrange(vector<int>v,int n)
{
vector<int>pos;
vector<int>neg;
for(int i=0;i<n;i++)
{
  if(v[i]>0)
  pos.push_back(v[i]);
  else
  neg.push_back(v[i]);
}
if(pos.size()>neg.size())
{
for(int i=0;i<n/2;i++)
{
  v[2*i]=pos[i];
  v[2*i+1]=neg[i];
}
int index=neg.size()*2;
for(int i=neg.size();i<pos.size();i++)
{
  v[index]=pos[i];
  index++;
}
}
if(pos.size()<neg.size())
{
for(int i=0;i<n/2;i++)
{
  v[2*i]=pos[i];
  v[2*i+1]=neg[i];
}
int index=pos.size()*2;
for(int i=pos.size();i<neg.size();i++)
{
  v[index]=neg[i];
  index++;
}
}
return v;
} 
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  vector<int> ans=rearrange(v,n);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }
return 0;
}
*/

//Q9 LEADERS IN AN ARRAY
/*
#include<bits/stdc++.h>
using namespace std;

vector<int> findlead(vector<int>v,int n)
{
  vector<int>ans;
  int max=v[n-1];
  ans.push_back(v[n-1]);
  for(int i=n-2;i>=0;i--)
  {
    if(v[i]>max)
    {
      ans.push_back(v[i]);
      max=v[i];
    }
  }
  return ans;
}
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  vector<int> ans=findlead(v,n);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }
return 0;
}
*/

//Q8 NEXT PERMUTATAION
//BRUTE FORCE APPROACH

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;
vector<int>nextperm(vector<int>v,int n)
{
  int index=-1;
  for(int i=n-1;i>=0;i--)
  {
    if(v[i]<v[i+1]) //finding breaking element
    {
      index=i;
      break;
    }
  }
    if(index==-1)
    {
      reverse(v.begin(),v.end());
      return v;
    }
    for(int i=n-1;i>index;i--)
    {
      if(v[i]>v[index])
      {
      swap(v[i],v[index]);
      break;
      }
    }
    reverse(v.begin()+index+1,v.end()); //for making minimum
    return v;
  }
int main()
{
 int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  vector<int> ans=nextperm(v,n);
  for(int i=0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  } 
return 0;
}
*/

//Q10 LONGEST CONSECUTIVE SEQUENCE IN AN ARRAY
//BRUTE FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;
int linsearch(vector<int>v,int num)
{
  int n=v.size();
  bool check=false;
  for(int i=0;i<n;i++)
  {
    if(v[i]==num)
    check=true;
  }
  return check;
}
int longcon(vector<int>v,int n)
{ 
  int maxlen=1;
  for(int i=0;i<n;i++)
  {
  int x=v[i];
  int cnt=1;
  while(linsearch(v,x+1)==true)
  {
    x+=1;
    cnt+=1;
  }
  maxlen=max(maxlen,cnt);
}
return maxlen;
}
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  int ans=longcon(v,n);
  cout<<"Longest consecutive sequence in the array is of length  "<<ans<<endl;
return 0;
}
*/

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int longcon(vector<int>v,int n)
{ 
  unordered_set<int>st;
  int maxlen=1;
  for(int i=0;i<n;i++)
  {
  st.insert(v[i]);
  }
  for(auto it:st )
  {
    if(st.find(it-1)==st.end())
    {
      int cnt=1;
      int x=it;
      while(st.find(x+1)!=st.end())
      {
        cnt+=1;
        x+=1;
      }
      maxlen=max(maxlen,cnt);
    }
  }
  return maxlen;
}
int main()
{
  int n;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>v(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  int ans=longcon(v,n);
  cout<<"Longest consecutive sequence in the array is of length  "<<ans<<endl;
return 0;
}
*/

//Q12 ROTATE IMAGE BY 90 DEGREE
//BRUTE FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>rotatemat(vector<vector<int>>matrix)
{
  int n=matrix.size();
  vector<vector<int>>rotated(n,vector<int>(n,0));//syntax is vector<vector<int>> matrix(rows, vector<int>(cols, 0)); with zero initialisation
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      rotated[j][n-i-1]=matrix[i][j];
    }
  }
  return rotated;
}
int main()
{
  vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rotated = rotatemat(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "\n";
}
return 0;
}
*/

//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>rotatemat(vector<vector<int>>matrix)
{
  int n=matrix.size();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      swap(matrix[i][j],matrix[j][i]);
    }
  }
  for(int i=0;i<n;i++)
  {
    reverse(matrix[i].begin(),matrix[i].end());
  }
  return matrix;
}
int main()
{
  vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rotated = rotatemat(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "\n";
}
return 0;
}
*/

//Q11 SET ZERO MATRIX
//BRUTE FORCE APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>markrow(vector<vector<int>>&matrix,int n,int m,int i)
{
  for(int j=0;j<m;j++)
  {
   if(matrix[i][j]!=0)
   matrix[i][j]=-1;
  }
  return matrix;
}
vector<vector<int>>markcol(vector<vector<int>>&matrix,int n,int m,int j)
{
  for(int i=0;i<n;i++)
  {
   if(matrix[i][j]!=0)
   matrix[i][j]=-1;
  }
  return matrix;
}


vector<vector<int>>zeromatrix(vector<vector<int>>matrix,int n,int m)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(matrix[i][j]==0)
      {
        markrow(matrix,n,m,i);
        markcol(matrix,n,m,j);
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(matrix[i][j]==-1)
      matrix[i][j]=0;
    }
  }
  return matrix;
}
int main()
{
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeromatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
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
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>zeromatrix(vector<vector<int>>&matrix,int n,int m)
{
  int col1=1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(matrix[i][j]==0)
      {
        matrix[i][0]=0;
      if(j!=0) //for corner element
      matrix[0][j]=0;
      else
      col1=0;
    }
  }
}
//for conversion from [1,1] to [n-1,m-1]
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<m;j++)
    {
      if(matrix[i][j]!=0)
      {
        if(matrix[i][0]==0 || matrix[0][j]==0)
        matrix[i][j]=0;
      }
    }
  }
  if(matrix[0][0]==0) //for first column conversion
  {
    for(int j=0;j<m;j++)
    matrix[0][j]=0;
  }
  if(col1==0) //for first row conversion
  {
    for(int i=0;i<n;i++)
    matrix[i][0]=0;
  }
  return matrix;
}
int main()
{
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeromatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
return 0;
}
*/

//Q13 SPIRAL TRANSVERSAL OF ARRAY
/*
#include<bits/stdc++.h>
using namespace std;

vector<int>spiralmat(vector<vector<int>>&matrix)
{
vector<int>ans;
int n=matrix.size();
int m=matrix[0].size();
int top=0,bottom=n-1,left=0,right=m-1;
while(top<=bottom && left<=right)
{
  for(int i=left;i<=right;i++)
  {
    ans.push_back(matrix[top][i]);
  }
  top++;
  for(int i=top;i<=bottom;i++)
  {
    ans.push_back(matrix[i][right]);
  }
  right--;
  if(left<=right)
  {
  for(int i=right;i>=left;i--)
  {
    ans.push_back(matrix[bottom][i]);
  }
  bottom--;
}
if(top<=bottom)
{
  for(int i=bottom;i>=top;i--)
  {
    ans.push_back(matrix[i][left]);
  }
  left++;
}
}
return ans;
}
int main()
{
vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = spiralmat(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
return 0;
}
*/

//Q14 COUNT SUBARRAY SUM EQUALS K
//OPTIMAL APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int subcount(vector<int>&v,int n,int target)
{ 
  int sum=0;int cnt=0;
  map<int,int>sa;
  sa[0]=1; //because extra can be also 0 if first element itself equals target
  for(int i=0;i<n;i++)
  {
    sum+=v[i];
    int extra=sum-target; //finding extra to be removed
    cnt+=sa[extra]; //checking if extra value exists in map
    sa[sum]+=1; //updating map with current sum's key +1
  }
  return cnt;
}
int main()
{
  vector<int>arr = {3, 1, 2, 4};
    int k = 6;
    int n=arr.size();
    int cnt = subcount(arr,n,k);
    cout << "The number of subarrays is: " << cnt << "\n";
return 0;
}
*/