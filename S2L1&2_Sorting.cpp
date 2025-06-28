//BUBBLE SORT
/*
#include<iostream>
using namespace std;

void bubble_sort(int a[],int n)
{ 
  int temp;
  for(int i=n-1;i>0;i--)
    { 
      int didswap=0;
    for(int j=0;j<=i-1;j++) //i-1 bcoz last number comparsiin is not to be done
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        didswap=1;
    }
}
if(didswap==0)
break;
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
    bubble_sort(a,n);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }   
return 0;
}
*/


//LINEAR SEARCH
/*
#include<iostream>
using namespace std;
int main()
{
    int n,target,index=-1;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"Enter the target term please"<<endl;
    cin>>target;
    for(int i=0;i<n;i++)
    {
      if(a[i]==target)
      index=i;
      }
      if(index>-1)
      cout<<"Search successful,number found at "<<index+1<<" index"<<endl;
      else
      cout<<"Sorry,Search Unsuccessful"<<endl;
return 0;
}
*/

//BINARY SEARCH
/*
#include<iostream>
using namespace std;
int main()
{   
    int n,target,start=0,end,mid,c=0;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    int a[n];
    end=(sizeof(a)/sizeof(a[0]))-1;
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"Enter the target term please"<<endl;
    cin>>target;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(a[mid]==target)
        {
            cout<<"Search Successful\nNumber found at "<<mid+1<<" position"<<endl;
            ++c;
            break;
        }
        else if(a[mid]>target)
        {
            end=mid-1;
        }
        else if(a[mid]<target)
        {
            start=mid+1;
        }
    }
    if(c==0)
    cout<<"Search Unsuccessful"<<endl;
return 0;
}
*/
//SELECTION SORT
/*
#include<iostream>
using namespace std;

void select_sort(int a[],int n)
{
  for(int k=0;k<n-1;k++)
    {
      int temp;
      int min=k; //assumption for first checking
    for(int i=k+1;i<n;i++)
    {
      if(a[min]>a[i])
      {
        min=i;
      }
    }
        temp=a[min];
        a[min]=a[k];
        a[k]=temp;
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
    select_sort(a,n);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
return 0;
}
*/


//INSERTION SORT
/*
#include<iostream>
using namespace std;

void insertion_sort(int a[],int n)
{
  for(int i=0;i<=n-1;i++)
    {   
        int temp,j;
        j=i;
        while(j>0 && a[j-1]>a[j]) 
        {
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--; //for checking previous number
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
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
return 0;
}
*/

//QUICK SORT
/*
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high)
{
  int pivot=arr[low];
  int i=low;
  int j=high;
  while(i<j)
  {
    while(arr[i]<=pivot && i<=high-1)
    {
      i++;
    }
    while(arr[j]>pivot && i>=low+1)
    {
      j--;
    }
    if(i<j)
    swap(arr[i],arr[j]);
  }
  swap(arr[low],arr[j]); //giving partition its correct position
  return j; //returning partition
}
void quicks(vector<int> &arr,int low,int high)
{
  if(low<high)
  {
    int pindex=partition(arr,low,high);
    quicks(arr,low,pindex-1);
    quicks(arr,pindex+1,high);
  }
}
int main()
{
  int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    quicks(a,0,n-1);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
return 0;
}
*/

//MERGE SORT
/*
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high)
{
  vector<int>temp; //creating temporary array space;
  int left=low;
  int right=mid+1;
  while(left<=mid && right<=high)
  {
    if(arr[left]<=arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }
  //inserting elements left in bigger array
    while(left<=mid)
    {
      temp.push_back(arr[left]);
      left++;
    }
    while(right<=high)
    {
      temp.push_back(arr[right]);
      right++;
    }
    for(int i=low;i<=high;i++)
    {
      arr[i]=temp[i-low]; //shifting to main array
    }
}

void mergesort(vector<int> &arr,int low,int high)
{
  if(low>=high)
  return;
  int mid=(low+high)/2;
  mergesort(arr,low,mid);
  mergesort(arr,mid+1,high);
  merge(arr,low,mid,high);
}
int main()
{
  int n;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the terms please"<<endl;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
       cout<<" "<<a[i];
    }
return 0;
}
*/