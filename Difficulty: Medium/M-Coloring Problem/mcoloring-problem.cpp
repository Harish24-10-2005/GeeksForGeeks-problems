class Solution {
    bool issafe(int node,int col,vector<int>&vis,vector<vector<int>>&adj)
    {
        for(auto a:adj[node])
        {
            if(vis[a] == col) return false;
        }
        return true;
    }
    bool dfs(int node,int m,vector<vector<int>>&adj,vector<int>&vis)
    {
        if(node ==vis.size()) return true;
        
        for(int col = 1;col<=m;col++)
        {
            if(issafe(node,col,vis,adj))
            {
                vis[node] = col;
                if(dfs(node+1,m,adj,vis)) return true;
                vis[node] = -1;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(v,-1);
        return dfs(0,m,adj,vis);
        
    }
};