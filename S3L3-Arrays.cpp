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

//3 SUM PROBLEM
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