//Largest element of array
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,lar;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    lar=a[0];
    for(int i=1;i<=n-1;i++)
    {
        if(lar<a[i])
        swap(lar,a[i]);
    }
    cout<<"Largest number of the array is "<<lar<<endl;
return 0;
}
*/

//Second largest element in an array
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,lar,slar;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    lar=a[0];
    slar=-1;
    for(int i=1;i<=n-1;i++)
    {
        if(lar<a[i])
        {
        slar=lar;
        lar=a[i];
        }
        else if(a[i]>slar && a[i]<lar)
        {
          slar=a[i];
        }
    }
    cout<<"Largest number of the array is "<<lar<<endl;
    cout<<"Second largest number of the array is "<<slar<<endl;
return 0;
}
*/

//CHECK IF ARRAY IS SORTED OR NOT
/*
#include<iostream>
using namespace std;

bool isSorted(int arr[],int n)
{
  for(int i=1;i<n;i++)
  {
    if(arr[i]<arr[i-1])
    return false;
  }
  return true;
}
int main()
{
  int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"Answer to is the array sorted is "<<isSorted(a,n)<<endl;
return 0;
}
*/

//SHIFTING ARRAY TO LEFT
/*
#include<iostream>
using namespace std;

void shiftleft(int arr[],int n)
{
  int temp=arr[0];
  for(int i=0;i<n-1;i++)
  {
    arr[i]=arr[i+1];
  }
  arr[n-1]=temp;
  cout<<"Array after shifting to left is "<<endl;
  for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
}
int main()
{
  int n;
  cout<<"Enter the number of terms"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the terms please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  shiftleft(a,n);
return 0;
}
*/

//SHIFTING ARRAY TO LEFT BY D PLACES
/*
#include<iostream>
using namespace std;

void reverse(int a[],int start,int end)
{
  while(start<=end)
  {
    int temp=a[start];
    a[start]=a[end];
    a[end]=temp;
    start++;
    end--;
  }
}
void shiftleft(int a[],int n,int k)
{
 reverse(a,0,k-1);
 reverse(a,k,n-1);
 reverse(a,0,n-1);
}
int main()
{
  int n,k;
  cout<<"Enter the number of terms"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the terms please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter the places the array has to be shifted"<<endl;
  cin>>k;
  k%=n;
  shiftleft(a,n,k);
  for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
return 0;
}
*/

//REMOVING DUPLICATES FROM AN ARRAY
/*
#include<iostream>
using namespace std;

int removeduplicates(int a[],int n)
{
  int i=0;
  for(int j=1;j<n;j++)
  {
    if(a[j]!=a[i])
    {
      a[i+1]=a[j];
      i++;
    }
  }
  return i+1;
}
int main()
{
  int n,k;
  cout<<"Enter the number of terms"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the terms please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  k=removeduplicates(a,n);
  cout<<"Array after removal of duplicate elements is "<<endl;
  for(int i=0;i<k;i++)
    {
      cout<<a[i]<<" ";
    }
return 0;
}
*/

//MOVING ALL ZEROES TO END OF ARRAY
/*
#include<bits/stdc++.h>
using namespace std;

void removezero(int a[],int n)
{
  int j=-1;
  for(int i=0;i<n;i++) //finding first zero
  {
    if(a[i]==0)
    {
      j=i;
      break;
    }
  }
  for(int i=j+1;i<n;i++) //starting after first zero
  {
    if(a[i]!=0)
    {
      swap(a[i],a[j]); //pushing zero to last
      j++;
    }
  }
}
int main()
{
  int n;
  cout<<"Enter the number of terms"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the terms please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  removezero(a,n);
  for(int i=0;i<n;i++)
    {
      cout<<a[i]<<" ";
    }
return 0;
}
*/

//LINEAR SEARCH
/*
#include<iostream>
using namespace std;

int lsearch(int a[],int n,int num)
{
  for(int i=0;i<n;i++)
  {
    if(a[i]==num)
    return 1; //can retun position too with i+1
  }
  return -1;
}
int main()
{
  int n,num;
  cout<<"Enter the number of terms"<<endl;
  cin>>n;
  int a[n];
  cout<<"Enter the terms please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter the number that has to be searched"<<endl;
  cin>>num;
  if(lsearch(a,n,num)==1)
  cout<<"Search successful"<<endl;
  else
  cout<<"Search unsuccessful"<<endl;
return 0;
}
*/

//UNION OF TWO ARRAYS
/*
#include<bits/stdc++.h>
using namespace std;

vector <int> findunion(int a[],int b[],int n,int m)
{
  int i=0,j=0;
  vector <int> uniar;
  while(i<n && j<m)
  {
    if(a[i]<=b[j])
    {
      if(uniar.size()==0 || a[i]!=uniar.back())
      uniar.push_back(a[i]);
      i++;
    }
    else
    {
      if(uniar.size()==0 || b[j]!=uniar.back())
      uniar.push_back(b[j]);
      j++;
    }
  }
  while(i<n)
  {
    if(uniar.size()==0 || a[i]!=uniar.back())
      uniar.push_back(a[i]);
      i++;
  }
  while(j<m)
  {
    if(uniar.size()==0 || b[j]!=uniar.back())
    uniar.push_back(b[j]);
    j++;
  }
  return uniar;
}
int main()
{
  int n1,n2;
  cout<<"Enter the number of terms for first array"<<endl;
  cin>>n1;
  int a[n1];
  cout<<"Enter the terms for first array please"<<endl;
  for(int i=0;i<n1;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter the number of terms for second array"<<endl;
  cin>>n2;
  int b[n2];
  cout<<"Enter the terms for second array please"<<endl;
  for(int i=0;i<n2;i++)
  {
    cin>>b[i];
  }
  vector<int> Union=findunion(a,b,n1,n2);
  cout << "Union of a and b arrays is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
  */

//INTERSECTION OF TWO ARRAYS
/*
#include<bits/stdc++.h>
using namespace std;

vector <int> findintersect(int a[],int b[],int n,int m)
{
  int i=0,j=0;
  vector <int> ans;
  while(i<n && j<m)
  {
    if(a[i]<b[j])
    {
      i++;
    }
    else if(b[j]<a[i])
    {
      j++;
    }
    else
    {
      ans.push_back(a[i]);
      i++;
      j++;
    }
  }
  return ans;
}
int main()
{
  int n1,n2;
  cout<<"Enter the number of terms for first array"<<endl;
  cin>>n1;
  int a[n1];
  cout<<"Enter the terms for first array please"<<endl;
  for(int i=0;i<n1;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter the number of terms for second array"<<endl;
  cin>>n2;
  int b[n2];
  cout<<"Enter the terms for second array please"<<endl;
  for(int i=0;i<n2;i++)
  {
    cin>>b[i];
  }
  vector<int> Intersect=findintersect(a,b,n1,n2);
  cout << "Intersect of a and b arrays is  " << endl;
  for (auto & val: Intersect)
    cout << val << " ";
  return 0;
}
*/

//MISSING ELEMENT IN ARRAY
//SUM METHOD
/*
#include<bits/stdc++.h>
using namespace std;

int missingno(vector <int> &a,int n)
{
  int sum=(n*(n+1))/2;
  int s=0;
  for(int i=0;i<n-1;i++)
  {
    s+=a[i];
  }
  int mnum=sum-s;
  return mnum;
}
int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingno(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
    */

//XOR METHOD
/*
#include<bits/stdc++.h>
using namespace std;

int missingno(vector <int> &a,int n)
{
  int xor1=0,xor2=0;
  for(int i=1;i<n-1;i++)
  {
    xor2 = xor2 ^ a[i]; // XOR of array elements
    xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
  }
  xor1^=n;
  return xor1^xor2;
}
int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingno(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
    */

//MAXIMUM CONSECUTIVE 1s IN AN ARRAY
/*
#include<iostream>
using namespace std;

int maxone(int a[],int n)
{
  int cnt=0,maxi=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==1)
    cnt++;
    else
    cnt=0;
    maxi=max(maxi,cnt);
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
  cout<<"Maximum consecutive 1s in this array is "<<maxone(a,n)<<endl;
return 0;
}
*/


//FINDING NO. APPEARING ONCE IN ARRAY OF REST APPEARING TWICE
//BETTER APPROACH USING HASHING
/*
#include<bits/stdc++.h>
using namespace std;

int findonef(int a[],int n)
{
  int maxi=a[0]; //finding maximum element for declaring hash
  for(int i=1;i<n;i++)
  {
    maxi=max(maxi,a[i]);
  }
  vector<int>hash(maxi+1,0);
  for(int i=0;i<n;i++) // iterating hash frequencies
  hash[a[i]]++;
  for(int i=0;i<n;i++)
  if(hash[a[i]]==1)
  return a[i];
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
  cout<<"Number with single occurence in this array is "<<findonef(a,n)<<endl;
return 0;
}
*/

//OPTIMAL APPROACH-USING XOR CONCEPT
/*
#include<bits/stdc++.h>
using namespace std;

int findonef(int a[],int n)
{
  int xorr=0;
  for(int i=0;i<n;i++)
  {
    xorr^=a[i];
  }
  return xorr;
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
  cout<<"Number with single occurence in this array is "<<findonef(a,n)<<endl;
return 0;
}
*/

//SUM OF K NUMBERS IN AN ARRAY(POSITIVES,NEGATIVES & ZEROES)
//BETTER/BEST APPROACH
/*
#include<bits/stdc++.h>
using namespace std;

int lsa(vector<int>&a,long long k,int n)
{
 map<long long,int> premapsum;
 long long sum=0;
 int maxlen=0;
 for(int i=0;i<n;i++)
 {
  sum+=a[i];
  if(sum==k)
  maxlen=max(maxlen,i+1);
  long long rem=sum-k;
  if(premapsum.find(rem)!=premapsum.end())
  {
    int len = i - premapsum[rem];
    maxlen = max(maxlen,len);
  }
  if(premapsum.find(sum)==premapsum.end())
  {
    premapsum[sum]=i;
  }
 }
 return maxlen;
}
int main()
{
  int n;long long k;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>a(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter the required sum"<<endl;
  cin>>k;
  cout<<"Maximum length of subarray is "<<lsa(a,k,n)<<endl;
return 0;
}
*/

//OPTIMAL APPROACH(FOR POSITIVE ARRAY ONLY)
/*
#include<bits/stdc++.h>
using namespace std;

int lsa(vector<int>&a,long long k,int n)
{
 int left=0,right=0;
 long long sum=a[0];
 int maxlen=0;
 while(right<n)
 {
 while(left<=right && sum>k)
 {
  sum-=a[left]; //subtracting sum from behind
  left++;
 }
 if(sum==k)
 maxlen=max(maxlen,right-left+1);
 right++;
 if(right<n)
 sum+=a[right];
}
return maxlen;
}
int main()
{
  int n;long long k;
  cout<<"Enter the number of terms for array"<<endl;
  cin>>n;
  vector<int>a(n);
  cout<<"Enter the terms for array please"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"Enter the required sum"<<endl;
  cin>>k;
  cout<<"Maximum length of subarray is "<<lsa(a,k,n)<<endl;
return 0;
}
*/