//Q1 NUMBER OF PROVINCES
/*
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adjlist[],int visited[])
{
    visited[node]=1;
    for(auto it : adjlist[node])
    {
        if(!visited[it])
        dfs(it,adjlist,visited);
    }
}
int provinces(vector<vector<int>>adj,int V)
{
    vector<int>adjlist[V];
    //building list from matrix
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(adj[i][j]==1 && i!=j) //to avoid self loop
            {
                adjlist[i].push_back(j);
                adjlist[j].push_back(i);
            }
        }
    }
    int visited[V]={0};
    int count=0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i,adjlist,visited);
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> adj = 
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int V = 3;
    cout << provinces(adj, V) << endl;
    return 0;
}
//TC/SC-O(n)
*/

//Q2 CONNECTED COMPONENTS
/*
#include <bits/stdc++.h>
using namespace std;

int countcomponents(int V,vector<vector<int>>&edges)
{
    vector<vector<int>>adj(V);
    //converting edges to adjency list
    for(auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int>visited(V,0);
    int components=0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]) //agar pichle part me traversed hoga to chalega hi nhi
        {
            components++;
            queue<int>q;
            q.push(i);
            visited[i]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(auto nbr : adj[node])
                {
                    if(!visited[nbr])
                    {
                        visited[nbr]=1;
                        q.push(nbr);
                    }
                }
            }
        }
    }
    return components;
}
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    cout << "Number of Connected Components: " << countcomponents(V, edges) << endl;
    return 0;
}
//TC/SC-O(n)
    */

//Q3 ROTTEN ORANGES
/*
#include <bits/stdc++.h>
using namespace std;

int orangesrotten(vector<vector<int>>&grid)
{
    if(grid.empty())
    return 0;
    int m=grid.size();
    int n=grid[0].size();
    int days=0;
    int tot=0;
    int cnt=0;
    queue<pair<int,int>>rotten;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]!=0)
            tot++; //total oranges present
            if(grid[i][j]==2)   
            rotten.push({i,j}); //pushing initial rotten
        }
    }
    //traversing in all four directions
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    while(!rotten.empty())
    {
        int k=rotten.size();
        cnt+=k; //adding already rotten
        while(k--)
        {
            int x=rotten.front().first;
            int y=rotten.front().second;
            rotten.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=x+dy[i];
                if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1)
                continue;
                grid[nx][ny]=2;
                rotten.push({nx,ny});
            }
        }
        if(!rotten.empty())
        days++;
    }
    return tot == cnt ? days : -1;
}
int main()
{
    vector<vector<int>> v{{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};
    int rotting = orangesrotten(v);
    cout << "Minimum Number of Days Required " << rotting << endl;
    return 0;
}
//TC/SC-O(n*n)
*/

//Q4 FLOOD FILL ALGORITHM
/*
#include <bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>>&ans,int oldcol,int newcol,vector<vector<int>>image,int dx[],int dy[])
{
    ans[row][col]=newcol;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++)
    {
        int nr=row+dx[i];
        int nc=col+dy[i];
        if(nr>=0 &&  nr<n && nc>=0 && nc<m && image[row][col]==oldcol && ans[row][col]!=newcol)
        {
            dfs(nr,nc,ans,oldcol,newcol,image,dx,dy);
        }
    }
}
vector<vector<int>>floodfill(vector<vector<int>>&image,int sr,int sc,int newcol)
{
    int oldcol=image[sr][sc];
    vector<vector<int>>ans=image;
    int dirrow[]={0,0,1,-1};
    int dircol[]={1,-1,0,0};
    dfs(sr,sc,ans,oldcol,newcol,image,dirrow,dircol);
    return ans;
}
int main()
{
    vector<vector<int>>image
    {
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	vector<vector<int>> ans = floodfill(image, 1, 1, 2);
	for(auto i: ans)
    {
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
    return 0;
}
//TC/SC-O(n*n)
*/

//Q5 DISCOVERING CYCLE IN AN UNDIRECTED GRAPH(using BFS)
/*
#include <bits/stdc++.h>
using namespace std;

bool detect(vector<int>adj[],int vis[],int src)
{
vis[src]=1;
queue<pair<int,int>>q;
q.push({src,-1});
while(!q.empty())
{
    int node=q.front().first;
    int parent=q.front().second;
    q.pop();
    for(auto it : adj[node])
    {
        if(!vis[node]) //fresh node aaya hai
        {
            vis[node]=1;
            q.push({it,node});
        }
        else if(parent!=node) //to  avoid self loop
        {
            return true;
        }
    }
}
return false;
}
bool isCycle(int V,vector<int>adj[])
{
    int vis[V]={0};
    for(int i=0;i<V;i++)
    {
        if(vis[i]!=0)
        if(detect(adj,vis,i))
        return true;
    }
}
int main()
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
//TC/SC-O(n)
*/

//Q6 DISCOVERING CYCLE IN A UNDIRECTED GRAPH(using DFS)
/*
#include <bits/stdc++.h>
using namespace std;

bool detect(vector<int>adj[],vector<int>&vis,int node,int parent) //array of refernce is never allowed
{
vis[node]=1;
for(int neighbour : adj[node])
{
    if(!vis[neighbour])
    {
        if(detect(adj,vis,neighbour,node))
        return true;
    }
    else if(neighbour!=parent)
    return true;
}
return false;
}
bool isCycle(int V,vector<int>adj[])
{
    vector<int>visited(V,0);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        if(detect(adj,visited,i,-1))
        return true;
    }
}
int main()
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
//TC/SC-O(n)
    */

//Q7 NEAREST CELL TO 1
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m, 0));   
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==0)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else
            {
                vis[i][j]=0;
            }
        }
    }
    int dircol[]={1,-1,0,0};
    int dirrow[]={0,0,1,-1};
    while(!q.empty())
    {
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dist[row][col]=steps;
        for(int i=0;i<4;i++)
        {
            int nrow=row+dirrow[i];
            int ncol=col+dircol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
            {
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	vector<vector<int>> ans = nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
    return 0;
}
    */

//Q8 SURROUNDED REGIONS
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int m,n;
    void dfs(int row,int col,vector<vector<char>>&b)
    {
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        if (row < 0 || col < 0 || row >= m || col >= n)
            return;
        if (b[row][col] != 'O')
            return;
        b[row][col]='#';
        for(int i=0;i<4;i++)
        {   
            int nx=row+dx[i];
            int ny=col+dy[i];
            dfs(nx,ny,b);
        }
    }
    void solve(vector<vector<char>>& board) 
    {   
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            dfs(i,0,board);
            if(board[i][n-1]=='O')
            dfs(i,n-1,board);
        }
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
            dfs(0,j,board);
            if(board[m-1][j]=='O')
            dfs(m-1,j,board);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='#')
                board[i][j]='O';
            }
        }
    }
};
int main()
{
    Solution ob;

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    ob.solve(board);

    // Print result
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
TC/SC-O(n^2)
*/

//Q9 NUMBER OF ENCLAVES
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m,n;
    void dfs(int row,int col,vector<vector<int>>&g)
    {
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        if (row < 0 || col < 0 || row >= m || col >= n)
        return;
        if (g[row][col] !=1)
        return;
        g[row][col]=-1;
        for(int i=0;i<4;i++)
        {   
            int nx=row+dx[i];
            int ny=col+dy[i];
            dfs(nx,ny,g);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {   
        m=grid.size();
        n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1)
            dfs(i,0,grid);
            if(grid[i][n-1]==1)
            dfs(i,n-1,grid);
        }
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1)
            dfs(0,j,grid);
            if(grid[m-1][j]==1)
            dfs(m-1,j,grid);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                cnt++;  
            }
        }
        return cnt;
    }
};
int main()
{
    Solution ob;

    vector<vector<int>> board = {
        {0,0,0,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,1,0,0}};

    int ans=ob.numEnclaves(board);
    cout <<ans<< endl;
    return 0;
}
//TC/SC-O(n^2)
*/

//Q10 WORD-LADDER 1
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>>q;
    q.push({beginWord,1});
    unordered_set<string>st(wordList.begin(),wordList.end());
    st.erase(beginWord);
    while(!q.empty())
    {
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==endWord)
        return steps;
        for(int i=0;i<word.size();i++)
        {
        char original=word[i];
        for(char c='a';c<='z';c++)
        {
            word[i]=c;
            if(st.find(word)!=st.end())
            {
                st.erase(word);
                q.push({word,steps+1});
            }
        }
        word[i]=original;
        }
    }
    return 0;
    }
};
int main() {
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj;
    cout << obj.ladderLength(startWord, targetWord, wordList) << endl;
    return 0;
}
//TC/SC-O(n^2)
*/

//Q11 WORD-LADDER-2
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<vector<string>>q;
    q.push({beginWord});
    unordered_set<string>st(wordList.begin(),wordList.end());
    vector<string>usedonlevel;
    usedonlevel.push_back(beginWord);
    int level=0;
    vector<vector<string>>ans;
    while(!q.empty())
    {
        vector<string>vec=q.front();
        q.pop();
        if(vec.size()>level)
        {
            level++;
            for(auto it : usedonlevel)
            {
                st.erase(it);
            }
        }
        string word=vec.back();
        if(word==endWord)
        {   
            
            ans.push_back(vec);
        }
        for(int i=0;i<word.size();i++)
        {
            char original=word[i];
            for(char c='a';c<='z';c++)
            {
                word[i]=c;
                if(st.find(word)!=st.end())
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedonlevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
    }
};
int main()
{

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans = obj.findLadders(startWord, targetWord, wordList);
    
    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
//TC/SC-O(n^2)
*/
//Q12 NUMBER OF ISLANDS-2
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
void bfs(int row,int col,vector<vector<int>>&v,vector<vector<char>>&g)
{
    int m=g.size();
    int n=g[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});
    v[row][col]=1;
    int delrow[]={-1,-1,-1,0,1,1,1,0};
    int delcol[]={-1,0,1,1,1,0,-1,-1};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            int nx=r+delrow[i];
            int ny=c+delcol[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !v[nx][ny] && g[nx][ny]=='1')
            {
            v[nx][ny]=1;  
            q.push({nx,ny});
            }
        }
    }
}
int numislands(vector<vector<char>>&grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>vis(m,vector<int>(n,0));
    int count=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && grid[i][j]=='1')
            {
            count++;
            bfs(i,j,vis,grid);
            }
        }
    }
    return count;
}
};
int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // Create Solution object
    Solution obj;
    // Call function and print result
    cout << obj.numislands(grid) << endl;
    return 0;
}
//TC/SC-O(n^2)
*/

//Q13 BIPARTITE GRAPH
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(int node,int col,vector<vector<int>>&g,vector<int>&color)
    {
        color[node]=col;
        for(auto it : g[node])
        {
            if(color[it]==-1)
            {
            if(dfs(it,!col,g,color)==false) // ! is important to check for the other colour
            return false;
            }
            else if(color[it]==col)
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {   
            if(color[i]==-1)
            if(dfs(i,0,graph,color)==false)
            return false;
        }
        return true;
    }
};
int main()
{
    Solution ob;

    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    if (ob.isBipartite(graph))
    cout << "Graph is Bipartite\n";
    else
    cout << "Graph is NOT Bipartite\n";

    return 0;
}
//TC/SC-O(n)
*/
//Q14 DISCOVERING CYCLE IN A DIRECTED GRAPH(using DFS)
/*
#include <bits/stdc++.h>
using namespace std;

bool detect(vector<int>adj[],int vis[],int node,int pathvis[]) //array of refernce is never allowed
{
vis[node]=1;
pathvis[node]=1;
for(auto it : adj[node])
{
    if(!vis[it])
    {
        if(detect(adj,vis,it,pathvis))
        return true;
    }
    else if(pathvis[it])
    return true;
}
pathvis[node]=0; //while returning we do pathvisited 0 so keep track ki use path se gye the ya alag se
return false;
}
bool isCycle(int V,vector<int>adj[])
{
    int visited[V]={0};
    int pathvis[V]={0};
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        if(detect(adj,visited,i,pathvis))
        return true;
    }
}
int main()
{
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    bool ans = isCycle(11, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
//TC/SC-O(n)
*/