class Solution {
    private:
    int rec(int i,int j,int cnt,string& a,string& b,vector<vector<vector<int>>>&dp)
    {
        if(i == a.size() || j == b.size())
        {
            return cnt;
        }
        if(dp[i][j][cnt] != -1)
        {
            return dp[i][j][cnt];
        }
        // cout<<a[i]<<" "<<b[j]<<endl;
        int ans = cnt;
        if(a[i] == b[j])
        {
            ans = max(ans,rec(i+1,j+1,cnt+1,a,b,dp));
        }
        ans = max(ans,rec(i,j+1,0,a,b,dp));   
        ans  = max(ans,rec(i+1,j,cnt,a,b,dp));   
        return dp[i][j][cnt] = ans;
        
    }
  public:
    int getLongestSubsequence(string A, string B) {
        // code here
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
                    ans = max(ans, dp[i][j]);
            }
        }

        return ans;
        
    }
};