//DIGIT HASHING
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int num,rg;
    cout<<"Enter size of your array"<<endl;
    cin>>num;
    cout<<"Enter your array"<<endl;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    //precompute
    cout<<"Enter range of series"<<endl;
    cin>>rg;
    int hash[rg+1]={0};
    for(int i=0;i<num;i++)
    {
        hash[arr[i]]+=1;
    }
    //Answering queries through printing
    int q;
    cout<<"Enter number of queries"<<endl;
    cin>>q;
    while(q--)
    {
        int n;
        cout<<"Enter your number"<<endl;
        cin>>n;
        cout<<n<<" appears "<<hash[n]<<" times"<<endl; 
    }
return 0;
}
*/

//CHARACTER HASHING
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    string s;
    cout<<"Enter your string"<<endl;
    cin>>s;
    //precompute
    int hash[256]={0};
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]]+=1;
    }
    //Answering queries through printing
    int q;
    cout<<"Enter number of queries"<<endl;
    cin>>q;
    while(q--)
    {
        char c;
        cout<<"Enter your charcter"<<endl;
        cin>>c;
        cout<<c<<" appears "<<hash[c]<<" times"<<endl; 
    }
return 0;
}
*/

//HASHING USING MAPS
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int num;
    cout<<"Enter size of your array"<<endl;
    cin>>num;
    cout<<"Enter your array"<<endl;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    //precompute
    map<int,int>mp;
    for(int i=0;i<num;i++)
    {
        mp[arr[i]]++;
    }
    //can use iterator also
    // for(auto it : mp)
    // {
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }
    //Answering queries through printing
    int q;
    cout<<"Enter number of queries"<<endl;
    cin>>q;
    while(q--)
    {
        int n;
        cout<<"Enter your number"<<endl;
        cin>>n;
        cout<<n<<" appears "<<mp[n]<<" times"<<endl; 
    }
return 0;
}
*/
//LEAST AND GREATEST FRQUENCY USING MAPS
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int num,counts=INT16_MAX,countl=INT16_MIN,el,es;
    cout<<"Enter size of your array"<<endl;
    cin>>num;
    cout<<"Enter your array"<<endl;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    //precompute
    map<int,int>mp;
    for(int i=0;i<num;i++)
    {
        mp[arr[i]]++;
    }
    //can use iterator also
    for(auto it : mp)
    {
        if(it.second>countl)
        {
            countl=it.second;
            el=it.first;
        }
        if(it.second<counts)
        {
            counts=it.second;
            es=it.first;
        }
    }
    //Answering queries through printing
    cout<<"Number with greatest frequency of "<<countl<<" is "<<el<<endl;
    cout<<"Number with least frequency of "<<counts<<" is "<<es<<endl;
return 0;
}
*/