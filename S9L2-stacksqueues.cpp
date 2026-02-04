//Infix to Postfix
/*
#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/' || c=='*')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}
void infixtopostfix(string s)
{
    stack<char>st;
    string result;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z' || c>='0' && c<='9'))
        result+=c;
        else if(c=='(')
        st.push(c);
        else if(c==')')
        {
            while(st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(c)<=prec(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    cout<<"Postfix Expression is "<<result<<endl;
}
int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " <<exp <<endl;
    infixtopostfix(exp);
    return 0;
}
//TC/SC-O(N)
*/

//POSTFIX TO INFIX
/*
#include <bits/stdc++.h>
using namespace std;

string postfixtoinfix(string s)
{
    stack<string>st;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z' || c>='0' && c<='9'))
        st.push(string(1,c));
        else
        {
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string com="("+top2+s[i]+top1+")";
            st.push(com);
        }
    }
    return st.top();
}
int main()
{
    string exp = "pq+mn-*";
    cout << "Postfix expression: " <<exp <<endl;
    cout<<"Infix expression: "<<postfixtoinfix(exp)<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//Infix to Prefix
/*
#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='/' || c=='*')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}
void infixtoprefix(string s)
{
    stack<char>st;
    string result;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            s[i]=')';
            i++;    
        }
        else if(s[i]==')')
        {
            s[i]='(';
            i++;
        }
    }
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z' || c>='0' && c<='9'))
        result+=c;
        else if(c=='(')
        st.push(c);
        else if(c==')')
        {
            while(st.top()!='(')
            {
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && prec(c)<prec(st.top()))
            {
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    cout<<"Prefix Expression is "<<result<<endl;
}
int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " <<exp <<endl;
    infixtoprefix(exp);
    return 0;
}
//TC/SC-O(N)
*/

//PREFIX TO INFIX
/*
#include <bits/stdc++.h>
using namespace std;

string prefixtoinfix(string s)
{
    stack<string>st;
    for(int i=s.length()-1;i>=0;i--)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z' || c>='0' && c<='9'))
        st.push(string(1,c));
        else
        {
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string com="("+top1+s[i]+top2+")";
            st.push(com);
        }
    }
    return st.top();
}
int main()
{
    string exp = "*+pq-cd";
    cout << "Prefix expression: " <<exp <<endl;
    cout<<"Infix expression: "<<prefixtoinfix(exp)<<endl;
    return 0;
}
//TC/SC-O(N)
*/


//POSTFIX TO PREFIX
/*
#include <bits/stdc++.h>
using namespace std;

string postfixtoprefix(string s)
{
    stack<string>st;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z' || c>='0' && c<='9'))
        st.push(string(1,c));
        else
        {
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string com=s[i]+top2+top1;
            st.push(com);
        }
    }
    return st.top();
}
int main()
{
    string exp = "pq+mn-*";
    cout << "Postfix expression: " <<exp <<endl;
    cout<<"Prefix expression: "<<postfixtoprefix(exp)<<endl;
    return 0;
}
//TC/SC-O(N)
*/

//PREFIX TO POSTFIX
/*
#include <bits/stdc++.h>
using namespace std;

string prefixtopostfix(string s)
{
    stack<string>st;
    for(int i=s.length()-1;i>=0;i--)
    {
        char c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z' || c>='0' && c<='9'))
        st.push(string(1,c));
        else
        {
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string com=top1+top2+s[i];
            st.push(com);
        }
    }
    return st.top();
}
int main()
{
    string exp = "*+pq-cd";
    cout << "Prefix expression: " <<exp <<endl;
    cout<<"Postfix expression: "<<prefixtopostfix(exp)<<endl;
    return 0;
}
//TC/SC-O(N)
*/

