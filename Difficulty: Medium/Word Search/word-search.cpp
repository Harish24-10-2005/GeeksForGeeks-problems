class Solution {
  private:
    int n,m;
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,-1,1};
    vector<vector<int>>vis;
    bool dfs(int i,int j,int idx,string & w,vector<vector<char>>&mat){
        if(idx == w.size()) return true;
        if(i >= n || i<0 || j>=m || j< 0) return false;
        for(int d=0;d<4;d++){
            int x = i + dx[d];
            int y = j + dy[d];
            if(x < n && x >= 0 && y < m && y>= 0 && vis[x][y] == 0 && mat[x][y] == w[idx]){
                vis[x][y] = 1;
                if(dfs(x,y,idx+1,w,mat))return true;
                vis[x][y] = 0;
            }
        }
        return false;
    }
  public:
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        n = mat.size();
        m = mat[0].size();
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(word[0] == mat[i][j]){
                    vis[i][j] = 1;
                    if(dfs(i,j,1,word,mat)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
        
    }
};