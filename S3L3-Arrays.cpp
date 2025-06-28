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