//Q1 SHORTEST PATH IN BFS TRAVERSAL
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>shortestpath(vector<vector<int>>&edges,int n,int m,int src)
{
    vector<int>adj[n];
    for(auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=1e9;
    }
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(dist[node]+1<dist[it])
            {
            dist[it]=dist[node]+1;
            q.push(it);
            }
        }
    }
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++)
    {
        if(dist[i]!=1e9)
        ans[i]=dist[i];
    }
    return ans;
}

int main() 
{

    int N = 9, M = 10;

    vector<vector<int>> edges = 
    {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
        {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
    };
    vector<int> ans = shortestpath(edges, N, M, 0);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
//TC/SC-O(n)
*/

//Q2 SHORTEST PATH IN DAG-TOPOSORT DFS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,
    vector<vector<pair<int,int>>>& adj,
    vector<int>& vis,
    stack<int>& st) 
    {
    vis[node] = 1;
    for (auto it : adj[node]) 
    {
        int v = it.first;
        if (!vis[v]) 
        {
            dfs(v, adj, vis, st);
        }
    }
    st.push(node);
    }

    vector<int> shortestpath(int n, int m, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

int main() {
    int N = 6, M = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };

    Solution obj;
    vector<int> ans = obj.shortestpath(N, M, edges);

    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
//TC/SC-O(n)
*/
//Q3 DJIKSTRAS ALGO
/*
#include <bits/stdc++.h>
using namespace std;

vector<int>djikstra(int v,vector<vector<int>>adj[],int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v);
    for(int i=0;i<v;i++)
    {
        dist[i]=1e9;
    }
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it : adj[node])
        {
            int edgeweight=it[1];
            int adjnode=it[0];
            if(dis+edgeweight<dist[adjnode])
            {
                dist[adjnode]=dis+edgeweight;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}
int main()
{
    int V = 3, E = 3, S = 2; //S is source vertex
    vector<vector<int>> adj[V];

    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res=djikstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
//TC-O(NLOGN)/SC-O(N)
*/

//Q5 SHORTEST PATH IN BINARY MATIX
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>dist(m,vector<int>(n,1e9));
    if(grid[0][0]==1 || grid[m-1][n-1]==1)
    return -1;
    if(m==1 && n==1)
    return 1;
    dist[0][0]=1;
    q.push({{0,0},1});
    int dx[]={-1,-1,-1,0,1,1,1,0};
    int dy[]={-1,0,1,1,1,0,-1,-1};
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int nx=r+dx[i];
            int ny=c+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0 && steps+1<dist[nx][ny])
            {
                dist[nx][ny]=steps+1;
                if(nx==m-1 && ny==n-1)
                return dist[nx][ny];
                q.push({{nx,ny},steps+1});
            }
        }
    }
    return -1;
    }
};
int main() 
{
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                 {1, 1, 0, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 0, 0},
                                 {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPathBinaryMatrix(grid); //if Q is from a source to desitination add in fxn call
    cout << res << endl;

    return 0;
}
//TC/SC-O(n^2)
*/

//Q6 PATH WITH MINIMUM EFFORT
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    int m=heights.size();
    int n=heights[0].size();
    vector<vector<int>>dist(m,vector<int>(n,1e9));
    dist[0][0]=0;
    pq.push({0,{0,0}});
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};
    while(!pq.empty())
    {
        int r=pq.top().second.first;
        int c=pq.top().second.second;
        int cost=pq.top().first;
        pq.pop();
        if(r==m-1 && c==n-1)
        return cost;
        for(int i=0;i<4;i++)
        {
            int nx=r+dx[i];
            int ny=c+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n)
            {
                int effort=max(abs(heights[r][c]-heights[nx][ny]),cost);
                if(effort<dist[nx][ny])
                {
                dist[nx][ny]=effort;
                pq.push({effort,{nx,ny}});
                }
            }
        }
    }
    return 0;
    }
};
int main() 
{
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;
    int ans = obj.minimumEffortPath(heights);

    cout << ans << endl;

    return 0;
}
//TC-O(n^2*log(n^2))/SC-O(n^2)
*/

//Q7 CHEAPEST FLIGHTS WITHIN K STOPS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
    vector<vector<pair<int, int>>>adj(n);
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>dist(n,1e9);
    dist[src]=0;
    pq.push({0,{src,0}});
    while(!pq.empty())
    {
        int kd=pq.top().first;
        int node=pq.top().second.first;
        int cost=pq.top().second.second;
        pq.pop();
        if(kd>k)
        continue;
        for(auto it : adj[node])
        {
            int adjnode=it.first;
            int edgew=it.second;
            if(cost+edgew<dist[adjnode] && kd<=k)
            {
                dist[adjnode]=cost+edgew;
                pq.push({kd+1,{adjnode,dist[adjnode]}});
            }
        }
    }
    if(dist[dst]==1e9)
    return -1;
    return dist[dst];
    }
};
int main()
{
    int n = 4, src = 0, dst = 3, K = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution obj;
    int ans = obj.findCheapestPrice(n, flights, src, dst, K);
    cout << ans << endl;

    return 0;
}
//TC/SC-O(n)
*/

//Q10 MINIMUM STEPS MULTIPLICATION
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int minimumutiplication(vector<int>&a,int start,int end)
{
queue<pair<int,int>>q;
q.push({start,0});
vector<int>dist(100000,1e9);
dist[start]=0;
int mod=100000;
while(!q.empty())
{
    int num=q.front().first;
    int steps=q.front().second;
    q.pop();
    for(auto it : a)
    {
        int mul=(num*it)%mod;
        if(steps+1<dist[mul])
        {
            dist[mul]=steps+1;
            if(mul==end)
            {
                return steps+1;
            }
            q.push({mul,steps+1});
        }
    }
}
return -1;
}
};
int main()
{
    int start = 3, end = 30;

    vector<int> arr = {2, 5, 7};

    Solution obj;

    int ans = obj.minimumutiplication(arr, start, end);

    cout << ans;
    cout << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q11 BELLMAN-FORD ALGORITHM
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
vector<int>bellman_ford(int n,vector<vector<int>>&edges,int s)
{
    vector<int>dist(n,1e9);
    dist[s]=0;
    for(int i=0;i<n-1;i++)
    {
    for(auto it : edges)
    {
        int u=it[0];
        int v=it[1];
        int w=it[2];
        if(dist[u]!=1e9 && dist[u]+w<dist[v])
        dist[v]=dist[u]+w;

    }
    }
    for(auto it : edges)
    {
        int u=it[0];
        int v=it[1];
        int w=it[2];
        if(dist[u]!=1e9 && dist[u]+w<dist[v])
        return {-1};
    }
    return dist;
}
};
int main()
{
    int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;
	Solution obj;
	vector<int> dist = obj.bellman_ford(V, edges, S);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;
    return 0;
}
//TC-O(n^2)/SC-O(n)
*/

//Q12 FLOYD-WARSHALL ALGORITHM
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
void shortestpath(vector<vector<long long>>&grid)
{
    int n=grid.size();
    for(int via=0;via<n;via++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][via]==1e18 || grid[via][j]==1e18)
                continue;
                if(grid[i][j]==1e18)
                {
                    grid[i][j]=grid[i][via]+grid[via][j]; //if no direct edge prevails
                }
                else
                {
                grid[i][j]=min(grid[i][j],grid[i][via]+grid[via][j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
    if(grid[i][i]<0)
    cout<<"Negative cycle exists"<<endl;
    }
}
};
int main()
{
    const long long INF=1e18;
    vector<vector<long long>> matrix ={
        {0, 2, INF, INF},
        {1, 0, 3, INF},
        {INF, INF, 0, INF},
        {3, 5, 4, 0}
    };
    Solution sol; 
    sol.shortestpath(matrix);
    int n = matrix.size();
    cout << "The shortest distance matrix is:\n";
    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            if(matrix[i][j]==1e18)
            continue;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//TC-O(n^3)/SC-O(n^2)
*/

//Q13 CITY WITH SMALLEST NUMBERS OF NEIGHBOURS AT THRESHOLD DISTANCE
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
{
    vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
    for(auto it : edges)
    {
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }
    for(int i=0;i<n;i++)
    {
        dist[i][i]=0;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                continue;
                dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
            }
        }
    }
    int cntcity=n;
    int cityno=-1;
    for(int city=0;city<n;city++)
    {
        int cnt=0;
        for(int adjcity=0;adjcity<n;adjcity++)
        {
            if(dist[city][adjcity]<=distanceThreshold)
            cnt++;
        }
        // Update the city with the least number of reachable cities
        if(cnt<=cntcity)
        {
            cntcity=cnt;
            cityno=city;
        }
    }
    return cityno;
}
};
int main()
{
    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    Solution obj;

    // Find the city with the least reachable cities within the threshold distance
    int cityNo = obj.findTheCity(n,edges,distanceThreshold);

    cout << "The answer is node: " << cityNo << endl;
    return 0;
}
//TC-O(n^3)/SC-O(n^2)
*/