/*#include<iostream>
using namespace std;
int main()
{
    cout<<"Hello,Hardik\nI'm CPP Programming system";
}
*/

//Volume of a sphere
/*
#include<iostream>
using namespace std;
int main()
{   
    double rad;double volume;
    cout<<"Enter the radius of the sphere\n";
    cin>>rad;
    volume=(1.333*rad*rad*rad*3.14);
    cout<<"Volume of the sphere is :-\n"<<volume;
}
*/

//Typecasting
/*
#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
    cout<<"Half of the number is \n"<<(float)x/2;
return 0;
}
*/
//BASIC PROFIT/LOSS
/*
#include<iostream>
using namespace std;
int main()
{
    int cp,sp,net;
    cout<<"Enter the cost price of the article\n";
    cin>>cp;
    cout<<"Enter the selling price of the article\n";
    cin>>sp;
    net=sp-cp;
    if(net>0)
    cout<<"Congrats,you made a profit of\n"<<net;
    else if(net<0)
    cout<<"Oh no,you made a loss of\n"<<-net;
    else if(net==0)
    cout<<"You neither made a profit nor loss of\n";
return 0;
}
*/

//MAGIC NUMBERS IN CPP
/*
#include<iostream>
using namespace std;
int main()
{
    int sum=0,num,rem,ind;
    cout<<"Enter your number"<<endl;
    cin>>num;
    ind=num;
    while(ind>9)
    {
        sum=0;
        num=ind;
        while(num!=0)
        {
      rem=num%10;
      sum+=rem;
      num=num/10;
    }
    ind=sum;
    }
    if(sum==1)
    cout<<"It is a Magic number"<<endl;
    else
    cout<<"It is not a Magic Number"<<endl;
return 0;
}
*/

//Reversing a number
/*
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double rem,rev,ct;
    int num,numo;
    double sum;
    cout<<"Enter your number"<<endl;
    cin>>num;
    numo=num;
    while(numo!=0)
        {
      rem=numo%10;
      ct++;
      numo=numo/10;
    }
    while(num!=0)
        {
      rem=num%10;
      sum+=rem*pow(10,--ct);
      num=num/10;
    }
    cout<<"Reversed number is "<<sum;
return 0;
}
*/

//Pattern Printing
/*
#include<iostream>
using namespace std;
int main()
{
    for(char i='A';i<='G';i+=2)
    {
        for(char j='A';j<=i;j+=2)
        {
          cout<<j;
        }
        cout<<endl;
    }
return 0;
}
*/

//PASCAL'S TRIANGLE
/*
#include<iostream>
using namespace std;

int fact(int n)
{   
    int fac=1;
    for(int i=1;i<=n;i++)
    {
        fac*=i;
    }
    return fac;
}
int main()
{
int num,i,j,res;
cout<<"Enter the number of rows of the pascal's triangle"<<endl;
cin>>num;
for(int i=0;i<num;i++)
{
    for(int j=0;j<=i;j++)
    {
       res=(fact(i)/(fact(j)*fact(i-j)));
       cout<<"  "<<res;
    }
    cout<<endl;
}
return 0;
}
*/

//REVERSING AN ARRAY
/*
#include<iostream>
using namespace std;
int main()
{   
    int n;
    int a[]={2,5,6,1,4,8,3,9,36};
    n=sizeof(a)/sizeof(int);
    for(int i=0;i<n/2;i++)
    {
        a[i]=a[n-i-1];
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }
return 0;
}
*/
/*
//PALINDROME STRING
#include<iostream>
using namespace std;

bool isPalindrome(int i,string &s)
{
   if(i>=s.length()/2) //FOR CHECKING TILL HALFWAY OF STRING
   return true;
   if(s[i]!=s[s.length()-i-1]) //FOR COMPARING WORDS
   return false;
   return isPalindrome(i+1,s);//FOR RECURSIVE CALLING WITH i++
}
int main()
{   
    string str;
    cout<<"Enter your word"<<endl;
    cin>>str;
    cout<<(isPalindrome(0,str)?"It is a Palindrome word" : "It is not a Palindrome word")<<endl;
return 0;
}
*/