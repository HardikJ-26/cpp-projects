//PRINING N NUMBERS
/*
#include<iostream>
using namespace std;

void printn(int i,int num)
{
    if(i<1)
    return;
    printn(i-1,num);
    cout<<i<<endl;
}
int main()
{   
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    printn(n,n);
return 0;
}
*/

//SUM OF N NUMBERS
/*
#include<iostream>
using namespace std;

void printn(int i,int sum)
{   
    if(i<1)
    {
        cout<<sum;
        return;
    }
    printn(i-1,sum+i);
}
int main()
{   
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    printn(n,0);
return 0;
}
*/

//FACTORIAL USING RECURSION
/*
#include<iostream>
using namespace std;

int fibo(int num)
{   
    if(num<1)
    return 1;
    else
    return num*fibo(num-1);
}
int main()
{
    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    cout<<fibo(n);
return 0;
} 
*/

//REVERSING AN ARRAY
/*
#include<bits/stdc++.h>
using namespace std;
void scheck(int i,int n,int a[])
{
if(i>=n/2)
return;
else
swap(a[i],a[n-i-1]);
scheck(i+1,n,a);
}
int main()
{   
    int num;
    cout<<"Enter size of your array"<<endl;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    scheck(0,num,arr);
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}
*/

//PALINDROME STRING
/*
#include<bits/stdc++.h>
using namespace std;
bool scheck(int i,string &sp)
{
if(i>=sp.size()/2)
return true;
else if(sp[i]!=sp[sp.size()-i-1])
return false;
scheck(i+1,sp);
}
int main()
{   
    string s;
    cout<<"Enter your string"<<endl;
    cin>>s;
    cout<<scheck(0,s);
    return 0; 
}
*/

//FIBONACCI SERIES PRINTING
/*
#include<iostream>
using namespace std;

void fibo(int a,int b,int n)
{   
    int c;
    if(n==0)
    return;
    else
    {
    cout<<(c=a+b)<<" ";
    a=b;
    b=c;
    fibo(a,b,n-1);
    }
}
int main()
{
    int n1,n2,num;
    cout<<"Enter number of the elements in the series"<<endl;
    cin>>num;
    cout<<"Enter first number of the series"<<endl;
    cin>>n1;
    cout<<"Enter second number of the series"<<endl;
    cin>>n2;
    cout<<n1<<" ";
    cout<<n2<<" ";
    fibo(n1,n2,num-2);
return 0;
}
*/

//NTH FIBONACCI TERM PRINTING
/*
#include<iostream>
using namespace std;

int fibo(int n)
{   
    if(n<=1)
    return n;
    else
    return fibo(n-1)+fibo(n-2); //can take last and secondlast respectively
}
int main()
{
    int num;
    cout<<"Enter the number whose element is to be printed"<<endl;
    cin>>num;
    cout<<fibo(num-1)<<endl;
return 0;
}
*/