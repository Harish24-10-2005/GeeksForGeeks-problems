//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int>res;
        vector<vector<int>>vis(n,vector<int>(m,0));
        DisjointSet d(n*m);
        int cnt = 0;
        
        vector<int>dx{1,0,-1,0};
        vector<int>dy{0,1,0,-1};
        for(auto a:operators)
        {
            int x = a[0];
            int y = a[1];
            if (vis[x][y] == 1) {
                res.push_back(cnt); 
                continue;
            }
            vis[x][y] = 1;
            cnt++;
            
            int node = (x*m)+y; 
            int parnode = d.findUPar(node);
            for(int i = 0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx>=0  && ny >=0 && nx <n && ny <m && vis[nx][ny] == 1)
                {
                    int newnode = (nx*m)+ny; 
                    int newparnode  =  d.findUPar(newnode);
                    if(newparnode != parnode)
                    {
                        cnt--;
                        d.unionBySize(node , newnode);
                        parnode = d.findUPar(parnode);
                        
                    }
                }
            }
            res.push_back(cnt);
            
        }
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends