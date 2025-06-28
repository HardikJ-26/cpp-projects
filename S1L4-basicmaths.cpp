//Q1 COUNTING OF DIGITS
/*
#include<iostream>
#include<math.h>
using namespace std;
int countd(int num)
{   
    int c=0;
    //
    while(num!=0)
    {
        ++c;
        num/=10;
    }
    //
     c=log10(num)+1; //Alternate single line method
    return c;
}
int main()
{
    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    cout<<"No. of digits are "<<countd(n);
return 0;
}
*/

//Q2 REVERSING A NUMBER
/*
#include<iostream>
#include<math.h>
using namespace std;
int revn(int num)
{   
    int sum=0,rem;
    //
    while(num!=0)
    {
        rem=num%10;
        sum=(sum*10)+rem;
        num/=10;
    }
    //
    return sum;
}
int main()
{
    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    cout<<"Reversed number is "<<revn(n);
return 0;
}
*/

//Q3 PALINDROME NUMBER
/*
#include<iostream>
#include<math.h>
using namespace std;
int revn(int num)
{   
    int sum=0,rem;
    //
    while(num!=0)
    {
        rem=num%10;
        sum=(sum*10)+rem;
        num/=10;
    }
    //
    return sum;
}
int main()
{
    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    if(revn(n)==n)
    cout<<"Yes,it is a Palindrome number";
    else
    cout<<"No,it is not a Palindrome number";
return 0;
}
*/

//Q5 ARMSTRONG NUMBERS
/*
#include<iostream>
#include<cmath>
using namespace std;
int arm(int num)
{   
    int sum=0,rem;
    while(num!=0)
    {
        rem=num%10;
        sum+=rem*rem*rem;
        num/=10;
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    if(arm(n)==n)
    cout<<"Yes,it is an Armstrong number"<<endl;
    else
    cout<<"No,it is not an Armstrong number"<<endl;
return 0;
}
*/

//Q6 PRINTING ALL DIVISORS
/*
#include<bits/stdc++.h>
using namespace std;
/*
int div(int num)
{   
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
        cout<<i<<" ";
    }
}
*/
//ALTERNATE METHOD USING STL
/*
int div(int num)
{
    vector<int> ls;
    for(int i=1;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
        ls.push_back(i);
        if((num/i!=i))
        {
        ls.push_back(num/i);
    }
}
    }
    sort(ls.begin(),ls.end());
    for(auto it:ls)
    cout<<it<<" ";
}

int main()
{
    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    div(n);
return 0;
}
*/


//Q7 PRIME NUMBERS
/*
#include<bits/stdc++.h>
using namespace std;

int prime(int num)
{   
    int c=0;
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
        ++c;
    }
    return c;
}

   //STL METHOD

   int prime(int num)
{   
    int c=0;
    for(int i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
        ++c;
        if(num/i!=i)
        ++c;
    }
}
    return c;
}
int main()
{
    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    if(prime(n)==2)
    cout<<"It is a Prime number";
    else
    cout<<"It is not a Prime number";
return 0;
}
*/

//Q4 GCD OF TWO NUMBERS

//USING STANDARD METHOD
/*
#include<bits/stdc++.h>
using namespace std;

int gcd(int num1,int num2)
{   
    int value;
    for(int i=1;i<=min(num1,num2);i++)
    {
        if(num1%i==0 && num2%i==0)
        value=i;
    }
    return value;
}
int main()
{
    int n1,n2;
    cout<<"Enter your first number"<<endl;
    cin>>n1;
    cout<<"Enter your second number"<<endl;
    cin>>n2;
    cout<<"GCD of the two numbers is "<<gcd(n1,n2);
return 0;
}
*/
//USING OPTIMAL METHOD
/*
#include<bits/stdc++.h>
using namespace std;

int gcd(int num1,int num2)
{   
    while (num1>0 && num2>0)
    {
        if(num1>num2)
        num1=num1%num2;
        else
        num2=num2%num1;
        if(num1==0) 
        return num2;
        else if(num2==0)
        return num1;
    }
}
int main()
{
    int n1,n2;
    cout<<"Enter your first number"<<endl;
    cin>>n1;
    cout<<"Enter your second number"<<endl;
    cin>>n2;
    cout<<"GCD of the two numbers is "<<gcd(n1,n2);
return 0;
}
*/