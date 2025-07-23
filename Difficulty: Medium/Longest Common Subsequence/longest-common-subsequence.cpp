class Solution {
  private:
    // int find(int i,int j,string s1,string s2)
    // {
    //     if(i == s1.size() || j== s2.size()) return 0;
        
    //     if(s1[i] == s2[j]) return 1 + find(i+1,j+1,s1,s2);
        
    //     return max(find(i+1,j,s1,s2) ,find(i,j+1,s1,s2)); 
    // }
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j] ,dp[i][j-1]); 
            }
        }
        return dp[n][m];
    }
};
