//Q3 STRONGLY CONNECTED COMPONENTS-KOSARAJU ALGO
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&st)
{
    vis[node]=1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        dfs(it,vis,adj,st);
    }
    st.push(node);
}
void dfs(int node,vector<int>&vis,vector<int>adjC[])
{
    vis[node]=1;
    for(auto it : adjC[node])
    {
        if(!vis[it])
        dfs(it,vis,adjC);
    }
}
public:
int kosaraju(int V,vector<int>adj[])
{
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        dfs(i,vis,adj,st);
    }
    vector<int>adjT[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=0;
        for(auto it : adj[i])
        {
            adjT[it].push_back(i); //reverse edge
        }
    }
    int scc=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            scc++; //can also use vector and store the scc
            dfs(node,vis,adjT);
        }
    }
    return scc;
}
};
int main()
{
    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };

    vector<int> adj[n];
    for (int i = 0; i < 5; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Solution obj;
    int ans = obj.kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q1 BRIDGES IN GRAPH
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int timer=1;
void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<vector<int>>&bridges)
{
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it : adj[node])
    {
        if(it==parent)
        continue;
        if(!vis[it])
        {
        dfs(it,node,vis,adj,tin,low,bridges);
        low[node]=min(low[node],low[it]); //normal tree edge // can reach its parent or ancestor
        if(low[it]>tin[node])
        bridges.push_back({it,node}); // cannot reach its parent or ancestor tehreby disconnecting the graph
        }
        else
        {
            // back edge
            low[node] = min(low[node], low[it]);
        }
    }
}
vector<vector<int>>criticalConnections(int n,vector<vector<int>>&connections)
{
    vector<int> adj[n];
    for (auto it : connections) 
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n, 0);
    int tin[n]; // Discovery time
    int low[n]; // Lowest reachable time
    vector<vector<int>> bridges;

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        dfs(i, -1, vis, adj, tin, low, bridges);
    }
    return bridges;
}
};
int main()
{
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges): ";
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q2 ARTICULATION POINTS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int timer=1;
void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<int>&mark)
{
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    int child=0;
    for(auto it : adj[node])
    {
        if(it==parent)
        continue;
        if(!vis[it])
        {
        dfs(it,node,vis,adj,tin,low,mark);
        low[node]=min(low[node],low[it]); //normal tree edge // can reach its parent or ancestor
        if(low[it]>=tin[node] && parent!=-1)
        mark[node]=1; // cannot reach its parent or ancestor tehreby disconnecting the graph
        child++;
        }
        else
        {
            // back edge
            low[node] = min(low[node], tin[it]);
        }
    }
    if(parent==-1 && child>1) //source node exception
    mark[node]=1;
}
public:
vector<int> articulationPoints(int n, vector<int> adj[]) 
{
    vector<int> vis(n, 0), mark(n, 0);
    int tin[n], low[n];

    for (int i = 0; i < n; i++) 
    {
    if (!vis[i]) 
    {
        dfs(i, -1, vis, adj, tin, low, mark);
    }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) 
    {
        if (mark[i]) ans.push_back(i);
    }
    return ans.empty() ? vector<int>{-1} : ans;
}
};

int main() 
{
int n = 5;
vector<vector<int>> edges = 
{
    {0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}
};

vector<int> adj[n];
for (auto e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
}

Solution sol;
vector<int> res = sol.articulationPoints(n, adj);
for (int v : res) cout << v << " ";
cout << endl;
return 0;
}
//TC/SC-O(n)
*/