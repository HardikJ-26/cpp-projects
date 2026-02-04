//Q2 MINIMUM SPANNING TREE(PRIM'S ALGORITHM)
/*
#include <bits/stdc++.h>
using namespace std;

int spanningtree(int v,vector<vector<pair<int,int>>>&adj)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>vis(v,0);
    pq.push({0,0});
    int sum=0;
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(vis[node]==1)
        continue;
        else
        {
            sum+=dis;
            vis[node]=1;
            for(auto it : adj[node])
            {       
                int adjnode=it.first;
                int adjdist=it.second;
                if(!vis[adjnode])
                pq.push({adjdist,adjnode});
            }
        }
    }
    return sum;
}
int main()
{
int v=6;
vector<vector<int>>edges={{0,1,2},{0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
vector<vector<pair<int,int>>> adj(v);

for (auto &e : edges)
{
int u = e[0];
int v = e[1];
int w = e[2];

adj[u].push_back({v, w});
adj[v].push_back({u, w});
}
int sum = spanningtree(v, adj);
cout << "The sum of all the edge weights: " << sum << endl;

return 0;
}
//TC-O(NLOGN)/SC-O(N)
*/

//Q3 DISJOINT SETS BY RANK
/*
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
vector<int>rank,parent;
public:
DisjointSet(int n)
{
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void unionByRank(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(rank[ulp]<rank[vlp])
    {
        parent[ulp]=vlp;
    }
    else if(rank[vlp]<rank[ulp])
    {
        parent[vlp]=ulp;
    }
    else
    {
        parent[vlp]=ulp;
        rank[ulp]++;
    }
}
};
int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
//TC-O(1)/SC-O(n)
*/

//Q4 DISJOINT SETS BY SIZE
/*
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
vector<int>size,parent;
public:
DisjointSet(int n)
{
    size.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void unionBySize(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(size[ulp]<size[vlp])
    {
        parent[ulp]=vlp;
        size[vlp]+=size[ulp];
    }
    else
    {
        parent[vlp]=ulp;
        size[ulp]+=size[vlp];
    }
}
};
int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
//TC-O(1)/SC-O(n)
*/

//Q5 KRUSKAL'S ALGORITHM
/*
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
vector<int>size,parent;
public:
DisjointSet(int n)
{
    size.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void unionBySize(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(size[ulp]<size[vlp])
    {
        parent[ulp]=vlp;
        size[vlp]+=size[ulp];
    }
    else
    {
        parent[vlp]=ulp;
        size[ulp]+=size[vlp];
    }
}
};
class Solution
{
public:
int spanningTree(int V,vector<vector<int>>adj[])
{
vector<pair<int,pair<int,int>>>edges;
for(int i=0;i<V;i++)
{
    for(auto it : adj[i])
    {
        int v=it[0];
        int wt=it[1];
        int u=i;
        edges.push_back({wt,{u,v}});
    }
}
DisjointSet ds(7);
sort(edges.begin(),edges.end());
int sum=0;
for(auto it : edges)
{
    int wt=it.first;
    int u=it.second.first;
    int v=it.second.second;
    if(ds.findUPar(u)!=ds.findUPar(v))
    {
        sum+=wt;
        ds.unionBySize(u,v); //can use unionByRank also
    }
}
return sum;
}
};
int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3},
        {0, 3, 4}
    };
    
    vector<vector<int>> adj[4];
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    Solution sol;
    int ans = sol.spanningTree(V, adj);
    
    cout << "The sum of weights of edges in MST is: " << ans;
    return 0;
}
//TC-O(n)/SC-O(n)
*/

//Q6 NUMEBER OF CONNECTIONS REQUIRED
/*
#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
vector<int>rank,parent;
public:
Disjoint(int n)
{
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void UnionBySize(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(rank[ulp]<rank[vlp])
    parent[ulp]=vlp;
    else if(rank[vlp]<rank[ulp])
    parent[vlp]=ulp;
    else
    {
        parent[vlp]=ulp;
        rank[ulp]++;
    }
}
};
class Solution
{
public:
int makeConnected(int n, vector<vector<int>>& connections) 
{
if(connections.size()<n-1)
return -1;
Disjoint ds(n);
for(auto &edges : connections)
{
    ds.UnionBySize(edges[0],edges[1]);
}
unordered_set<int>components;
for(int i=0;i<n;i++)
{
    components.insert(ds.findUPar(i));
}
return components.size()-1;
}
};
int main()
{
    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    Solution sol;
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}
//TC-O(n)/SC-O(n)
*/

//Q7 MOST STONES REMOVED WITHIN SAME ROW OR COLUMN
/*
#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
vector<int>rank,parent;
public:
Disjoint(int n)
{
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void UnionBySize(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(rank[ulp]<rank[vlp])
    parent[ulp]=vlp;
    else if(rank[vlp]<rank[ulp])
    parent[vlp]=ulp;
    else
    {
        parent[vlp]=ulp;
        rank[ulp]++;
    }
}
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    { 
        Disjoint ds;
        for(auto stone : stones)
        {
            ds.unite(stone[0],stone[1]+10001);
        }
        unordered_set<int> components;
        for(auto stone : stones)
        {
            components.insert(ds.findpar(stone[0]));
        }
        return stones.size()-components.size();
    }
};
//TC-O(n)/SC-O(n)
*/

//Q8 ACCOUNTS MERGED
/*
#include <bits/stdc++.h>
using namespace std;

class Disjoint
{
vector<int>rank,parent;
public:
Disjoint(int n)
{
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void UnionByRank(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(rank[ulp]<rank[vlp])
    parent[ulp]=vlp;
    else if(rank[vlp]<rank[ulp])
    parent[vlp]=ulp;
    else
    {
        parent[vlp]=ulp;
        rank[ulp]++;
    }
}
};
class Solution
{
public:
vector<vector<string>>accountsMerge(vector<vector<string>>&details)
{
    int n=details.size();
    Disjoint ds(n);
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<details[i].size();j++)
        {
            string mail=details[i][j];
            if(mp.find(mail)==mp.end())
            {
                mp[mail]=i;
            }
            else
            {
                ds.UnionByRank(i,mp[mail]);
            }
        }
    }
    vector<vector<string>>mergedmail(n);
    for(auto it : mp)
    {
        string mail=it.first;
        int node=ds.findUPar(it.second);
        mergedmail[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i=0;i<n;i++)
    {
        if(mergedmail[i].empty())
        continue;
        sort(mergedmail[i].begin(),mergedmail[i].end());
        vector<string>temp;
        temp.push_back(details[i][0]);
        for(auto mail : mergedmail[i])
        temp.push_back(mail);
        ans.push_back(temp);
    }
    return ans;
}
};
int main()
{
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    for (auto &acc : ans) {
        cout << acc[0] << ":";
        for (int i = 1; i < acc.size(); i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
//TC-O(n)/SC-O(n)
*/

//Q9 NUMBER OF ISLANDS-2
/*
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
vector<int>size,parent;
public:
DisjointSet(int n)
{
    size.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void unionBySize(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(size[ulp]<size[vlp])
    {
        parent[ulp]=vlp;
        size[vlp]+=size[ulp];
    }
    else
    {
        parent[vlp]=ulp;
        size[ulp]+=size[vlp];
    }
}
};
class Solution
{
public:
vector<int>numIslands(int n,int m,vector<vector<int>>&operators)
{
    DisjointSet ds(n*m);
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt=0;
    vector<int>ans;
    for(auto it : operators)
    {
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1)
        {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col]=1;
        cnt++;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int nx=row+dx[i];
            int ny=col+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==1)
            {
                int nodeno=row*m+col;
                int adjnodeno=nx*m+ny;
                if(ds.findUPar(nodeno)!=ds.findUPar(adjnodeno))
                {
                    cnt--;
                    ds.unionBySize(nodeno,adjnodeno);
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}
};
int main()
{
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    Solution obj;
    vector<int> ans = obj.numIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
//TC/SC-O(n^2)
*/

//Q10 MAKING A LARGE ISLAND
/*
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
vector<int>size,parent;
DisjointSet(int n)
{
    size.resize(n,1);
    parent.resize(n);
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
int findUPar(int node)
{
    if(node==parent[node])
    return node;
    return parent[node]=findUPar(parent[node]);
}
void unionBySize(int u,int v)
{
    int ulp=findUPar(u);
    int vlp=findUPar(v);
    if(ulp==vlp)
    return;
    if(size[ulp]<size[vlp])
    {
        parent[ulp]=vlp;
        size[vlp]+=size[ulp];
    }
    else
    {
        parent[vlp]=ulp;
        size[ulp]+=size[vlp];
    }
}
};
class Solution
{
private:
vector<int>dx={0,0,1,-1};
vector<int>dy={1,-1,0,0};
bool isValid(int i,int j,int n)
{
    if(i>=0 && i<n && j>=0 && j<n)
    return true;
    return false;
}
public:
void addinitialislands(vector<vector<int>>&g,DisjointSet &ds,int n)
{
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            if(g[row][col]==0)
            continue;
            for(int i=0;i<4;i++)
            {
                int nx=row+dx[i];
                int ny=col+dy[i];
                if(isValid(nx,ny,n) && g[nx][ny]==1)
                {
                int nodeno=row*n+col;
                int adjnodeno=nx*n+ny;
                ds.unionBySize(nodeno,adjnodeno);
                }
            }
        }
    }
}
int largestIsland(vector<vector<int>>& grid) 
{
   int n=grid.size();
   DisjointSet ds(n*n);
   addinitialislands(grid,ds,n);
   int ans=0;
   for(int row=0;row<n;row++)
   {
   for(int col=0;col<n;col++)
   {    
        set<int>components; //set is in loop to reset it every time
        if(grid[row][col]==1)
        continue;
        for(int i=0;i<4;i++)
        {
            int nx=row+dx[i];
            int ny=col+dy[i];
            if(isValid(nx,ny,n) && grid[nx][ny]==1)
            {
            int adjnodeno=nx*n+ny;
            components.insert(ds.findUPar(adjnodeno));
            }
        }
        int sizetotal=0;
        for(auto it : components)
        {
            sizetotal+=ds.size[it];
        }
        ans=max(ans,sizetotal+1);
   } 
   }
   for(int i=0;i<n*n;i++)
   {
        if(ds.findUPar(i)==i)
        ans=max(ans,ds.size[i]);
   }
   return ans;
}
};
int main() 
{
    vector<vector<int>> grid = 
    {
        {1,0},
        {0,1}
    };

    Solution sol;

    int ans = sol.largestIsland(grid);
    cout << "The size of the largest island is: " << ans;
    return 0;
}
//TC/SC-O(n^2)
*/

//Q11 SWIM IN WATER
/*
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
int swimInWater(vector<vector<int>>& grid) 
{
    int n=grid.size();
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    vector<vector<int>>visited(n,vector<int>(n,0));
    pq.push({grid[0][0],0,0});
    visited[0][0]=1;
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    while(!pq.empty())
    {
        auto curnode=pq.top();
        pq.pop();
        int elevation=curnode[0];
        int row=curnode[1];
        int col=curnode[2];
        if(row==n-1 && col==n-1)
        return elevation;
        for(int i=0;i<4;i++)
        {
            int nx=row+dx[i];
            int ny=col+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[nx][ny])
            {
                visited[nx][ny]=1;
                pq.push({max(elevation,grid[nx][ny]),nx,ny});
            }
        }
    }
    return -1;
}
};
int main()
{
    vector<vector<int>> grid = {
        {0,2}, {1,3}
    };
    Solution sol;
    cout << "Minimum time to reach destination: " << sol.swimInWater(grid) << endl;
    return 0;
}
//TC-O(n^2*logn)/SC-O(n^2)
*/