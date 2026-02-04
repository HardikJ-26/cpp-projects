//Q1 TOPOLOGICAL SORTING(DFS)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st)
{
    vis[node]=1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        dfs(it,adj,vis,st);
    }
    st.push(node);
}
vector<int>toposort(int V,vector<int>adj[])
{
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        dfs(i,adj,vis,st);
    }
    vector<int>ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
};
int main()
{
    int V = 6, E = 6;

    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;

    vector<int> res = obj.toposort(V, adj);

    cout << "Topological Sort: ";
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q2 TOPOLOGICAL SORTING(BFS)(KAHN'S ALGO)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
vector<int>toposort(int V,vector<int>adj[])
{
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    return topo;
}
};
int main()
{
    int V = 6, E = 6;

    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;

    vector<int> res = obj.toposort(V, adj);

    cout << "Topological Sort: ";
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q3 DETECT A CYCLE IN DIRECTED GRAPH
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
bool toposort(int V,vector<vector<int>>&adj)
{
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    int cnt=0;
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cnt++;
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    if(cnt==V)
    return false;
    return true;
}
};
int main()
{
    int V = 4;
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}  
    };

    // Create object of Solution class
    Solution sol;

    // Call the isCyclic method and print result
    cout << (sol.toposort(V, adj) ? "Graph contains a cycle" : "No cycle") << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q6 EVENTUAL SAFE STATES
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
vector<int>eventualSafeNodes(vector<vector<int>>&graph)
{
    int n=graph.size();
    vector<vector<int>>adjRev(n);
    int indegree[n]={0};
    for(int i=0;i<n;i++)
    {
        for(auto it : graph[i])
        {
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int>q;
    vector<int>safenodes;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        safenodes.push_back(node);
        for(auto it  : adjRev[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    sort(safenodes.begin(),safenodes.end());
    return safenodes;
}
};
int main()
{
    vector<vector<int>> adj = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
                           {8}, {9}};
    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(adj);  // Call function to get safe nodes

    for (auto node : safeNodes) {
        cout << node << " ";  // Print the safe nodes
    }
    cout << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q7 ALIEN DICTIONARY
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
vector<int>toposort(int V,vector<int>adj[])
{
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    return topo;
}
string findOrder(string dict[],int N,int k)
{
    vector<int>adj[k];
    for(int i=0;i<N-1;i++)
    {
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        for(int ptr=0;ptr<len;ptr++)
        {
            if(s1[ptr]!=s2[ptr])
            {
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
            }
        }
    }
    vector<int>topo=toposort(k,adj);
    string ans="";
    for(auto node : topo)
    {
        ans+=char(node+'a');
    }
    return ans;
}
};
int main()
{
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution obj;
    string ans = obj.findOrder(dict, N, K);
    for (auto ch : ans) {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}
//TC-O(n^2)/SC-O(n)
*/