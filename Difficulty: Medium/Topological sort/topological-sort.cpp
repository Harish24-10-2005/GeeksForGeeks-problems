class Solution {
  private:
    void dfs(int node,vector<vector<int>>&adj,stack<int>&st,vector<int>&vis)
    {
        vis[node] = 1;
        for(int i:adj[node])
        {
            if(vis[i] != 1)
            {
                dfs(i,adj,st,vis);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(V,0);
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)dfs(i,adj,st,vis);
        }
        while(!st.empty())
        {
            int t = st.top();
            ans.push_back(t);
            st.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
};