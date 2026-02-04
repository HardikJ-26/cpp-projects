//Q1 ASSIGN COOKIES
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int findContentChildren(vector<int>&student,vector<int>&cookie)
{
    sort(student.begin(),student.end());
    sort(cookie.begin(),cookie.end());
    int studentindex=0;
    int cookieindex=0;
    while(studentindex<student.size() && cookieindex<cookie.size())
    {
        if(cookie[cookieindex]>=student[studentindex])
        studentindex++;
        cookieindex++;
    }
    return studentindex;
}
};
int main()
{
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 3};

    Solution solver;

    int result = solver.findContentChildren(student, cookie);
    cout << "Maximum number of content students: " << result << endl;

    return 0;
}
//TC-O(nlogn)/SC-O(1)
*/

//Q2 FRACTIONAL KNAPSACK
/*
#include <bits/stdc++.h>
using namespace std;

struct Item
{
int value;
int weight;
};
class Solution
{
public:
bool static comp(Item a,Item b) //Comparator
{
    double r1=(double) a.value/(double) a.weight;
    double r2=(double) a.value/(double) a.weight;
    return r1>r2;
}
double fractionalKnapsack(int W,Item arr[],int n)
{
    sort(arr,arr+n,comp);
    int curweight=0;
    double finalvalue=0.0;
    for(int i=0;i<n;i++)
    {
        if(curweight+arr[i].weight<=W)
        {
            curweight+=arr[i].weight;
            finalvalue+=arr[i].value;
        }
        else
        {
            int remain=W-curweight;
            finalvalue+=(arr[i].value/(double)arr[i].weight)*(double)remain;
            break;
        }
    }
    return finalvalue;
}
};
int main()
{
    int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;

    double ans = obj.fractionalKnapsack(weight, arr, n);

    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}
//TC-O(nlogn)/SC-O(1)
*/

//Q3 MINIMUM NUMBER OF COINS
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>minCoins(int V)
{
    int coins[]={1,2,5,10,20,50,100,500,1000};
    int n=9;
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        while(V>=coins[i])
        {
            V-=coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}
int main()
{
    int V = 258;

    vector<int> ans = minCoins(V);

    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int coin : ans) {
        cout << coin << " ";
    }
    cout << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q4 LEMONADE STAND
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
bool lemonadeChange(vector<int>& bills) 
{
   int five=0;
   int ten=0;
   for(int i=0;i<bills.size();i++)
   {
        if(bills[i]==5)
        {
            five++;
        }
        else if(bills[i]==10)
        {   
            if(five>0)
            {
            ten++;
            five--;
            }
            else
            return false;
        }
        else
        {
            if(five>0 && ten>0)
            {
                five--;
                ten--;
            }
            else if(five>=3)
            {
                five-=3;
            }
            else
            return false;
        }
   }
   return true;     
}
};
int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};

    cout << "Queue of customers: ";
    for (int bill : bills) cout << bill << " ";
    cout << endl;

    Solution stand;
    bool ans = stand.lemonadeChange(bills);

    if (ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}
//TC-O(n)/SC-O(1)
*/

//Q5 VALID PARENTHESIS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
bool checkValidString(string s) 
{
    int minopen=0,maxopen=0;
    for(char c : s)
    {
        if(c=='(')
        {
            minopen++;
            maxopen++;
        }
        else if(c==')')
        {
            minopen--;
            maxopen--;
        }
        else
        {
            minopen--;
            maxopen++;
        }
        if(maxopen<0)
        return false;
        minopen=max(minopen,0);
    }
    return minopen==0;
}
};
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    if (sol.checkValidString(s)) 
    {
        cout << "Valid parenthesis string" << endl;
    } else {
        cout << "Invalid parenthesis string" << endl;
    }
    return 0;
}
//TC-O(n)/SC-O(1)
*/