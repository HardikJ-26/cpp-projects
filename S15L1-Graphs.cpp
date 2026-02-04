//Q2 Graph Storage
/*
#include <bits/stdc++.h>
using namespace std;

//Matrix Storage of Graph
int main()
{
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;//for weighted graphs =1 is replaced by weight of edge
        adj[v][u]=1;//for weighted graphs =1 is replaced by weight of edge
    }
    return 0;
}
//TC-O(N)/SC-O(N^2)
//List Storage of Graph(Undirected)
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1]; //pair<int,int> for weighted
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);//for weighted graph we store as pairs with edge weight
        adj[v].push_back(u);//for weighted graph we store as pairs with edge weight
    }
    return 0;
}
//TC-O(N)/SC-O(N)
*/

//Q5 BFS IN GRAPHS
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>bfsofGraph(int v,vector<int>adj[]) //here v is total possible elements
{
    int vis[v]={0};
    int dist[v]={-1};
    vis[0]=1;
    dist[0]=0; 
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty())
    {   
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                dist[it]=dist[node]+1; //to keep track of shortest distance of each vertex from the root vertex 
                q.push(it);
            }
        }
    }
    return bfs;
}
void addEdge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector<int>&ans)
{
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    vector <int> adj[5];
    
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,0,4);

    vector <int> ans = bfsofGraph(5, adj);
    printAns(ans);
    return 0;
}
//TC-O(N)/SC-O(N)
*/

//Q6 DFS IN GRAPHS
/*
#include <bits/stdc++.h>
using namespace std;

void dfs(int v,vector<int>adj[],vector<int>&visited,vector<int>&result) //here v is the element being checked
{
    visited[v]=1;
    result.push_back(v);
    for(int i : adj[v])
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,result); //can also use a stack
        }
    }
}
int main()
{
    int V=5;
    vector<int>adj[V];
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,4};
    adj[3] = {1};
    adj[4] = {2};

    vector<int> visited(V, 0);
    vector<int> result;
    dfs(0, adj, visited, result);

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
//TC-O(N)/SC-O(N)
*/