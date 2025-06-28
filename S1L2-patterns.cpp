//Q1 Striver
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q2
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
        */

//Q3
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q4
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q5
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
        */

//Q6
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q7
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q8
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++)
        {
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q9
/*
#include<iostream>
using namespace std;
void print1(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++)
        {
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
void print2(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++)
        {
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        print1(num);
        print2(num);
    }
*/

//Q10
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<2*n;i++)
    {   
        int stars=i;
        if(i>n)
        stars=2*n-i;
        for(int j=0;j<stars;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q11
/*
#include<iostream>
using namespace std;
void printl(int n)
{   
    int start=1;
    for(int i=1;i<=n;i++)
    {   
        if(i%2==1)
        start=1;
        else start=0;
        for(int j=0;j<i;j++)
        {
            cout<<start;
            start=1-start;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q12
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=i;j++)
        {
            cout<<j;
        }
        for(int j=1;j<=2*n-2*i;j++)
        {
            cout<<" ";
        }
        for(int j=i;j>=1;j--)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q13
/*
#include<iostream>
using namespace std;
void printl(int n)
{   
    int num=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q14
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<n;i++)
    {
        for(char ch='A';ch<='A'+i;ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q15
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<n;i++)
    {
        for(char ch='A';ch<='A'+n-i-1;ch++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q16
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(char i='A';i<='A'+n-1;i++)
    {
        for(char ch='A';ch<=i;ch++)
        {
            cout<<i;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q17
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        char ch='A';
        int breakpoint=(2*i+1)/2;
        for(int j=1;j<=2*i+1;j++)
        {
            cout<<ch;
            if(j<=breakpoint)
            ch++;
            else
            ch--;
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q18
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<n;i++)
    {
        for(char j='E'-i;j<='E';j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q19
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<n;i++)
    {   
        for(int j=1;j<=n-i;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=2*i;j++)
        {
            cout<<" ";
        }
        for(int j=n-i;j>=1;j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=2*n-2*i;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q20
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=2*n-2*i;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n-1;i++)
    {   
        for(int j=1;j<=n-i-1;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=2*i+2;j++)
        {
            cout<<" ";
        }
        for(int j=n-i-1;j>=1;j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q21
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1 || i==n || j==1 || j==n)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/

//Q22
/*
#include<iostream>
using namespace std;
void printl(int n)
{
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
        {
           int top=i;
           int left=j;
           int right=(2*n-2)-j;
           int down=(2*n-2)-i;
           cout<<(n-min(min(top,down),min(left,right)));
        }
        cout<<endl;
    }
}
   int main()
    {
        int num;
        cin>>num;
        printl(num);
    }
*/