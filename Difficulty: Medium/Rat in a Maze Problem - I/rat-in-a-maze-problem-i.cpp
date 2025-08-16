class Solution {
  private:
    bool issafe(int r,int c,int n,vector<vector<int>>&vis,vector<vector<int>>&maze)
    {
        return (r>=0 && c>=0 && r<n && c<n && !vis[r][c] && maze[r][c]);
    }
    void rec(int r,int c,int n,string& s,vector<vector<int>>&vis,vector<string>&res,vector<vector<int>>&maze)
    {
        if(r == n-1 && c == n-1)
        {
            res.push_back(s);
            return;
        }
        string d = "DLRU";
        vector<int>dx{1,0,0,-1};
        vector<int>dy{0,-1,1,0};
        for(int i=0;i<4;i++)
        {
            int x = r+dx[i];
            int y = c+dy[i];
            if(issafe(x,y,n,vis,maze))
            {
                vis[x][y] = 1;
                s+=d[i];
                rec(x,y,n,s,vis,res,maze);
                s.pop_back();
                vis[x][y] = 0;
            }
        }
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>res;
        vis[0][0] = 1;
        string s = "";
        rec(0,0,n,s,vis,res,maze);
        return res;
        
    }
};