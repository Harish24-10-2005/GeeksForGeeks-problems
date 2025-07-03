// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int cap) {
        // code here
        int n = wt.size();
        
        vector<vector<int>>dp(n,vector<int>(cap+1,0));
        
        for(int i=0;i<=cap;i++)
        {
            dp[0][i] = (i/wt[0])*val[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=cap;j++)
            {
                int nt = dp[i-1][j];
                int t = 0;
                if(j>=wt[i])  t= dp[i][j-wt[i]] + val[i];
                dp[i][j] = max(t,nt);
            }
        }
        return dp[n-1][cap];
    }
};