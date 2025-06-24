#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int col,vector<int>&vis,vector<vector<int>>&adj)
{
    vis[node] = col;
    for(int i:adj[node])
    {
        if(vis[i] == -1)
        {
            if(!dfs(i,!col,vis,adj)) return false;
        }
        else if(vis[i] == col) return false;
    }
    return true;
}

int main() {
    // Your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>adj(n+1);   
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n+1,-1);
        bool f = true;
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == -1)
            {
                if(!dfs(i,0,vis,adj))
                {
                    f = false;
                    break;
                }
            }
        }
        if(f) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}