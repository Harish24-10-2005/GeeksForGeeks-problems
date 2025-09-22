class Solution {
  private:
    // int rec(int i,int w,vector<int>&wt,vector<int>&val)
    // {
    //     if(w == 0) return 0;
    //     if( i == val.size())
    //     {
    //         return 0;
    //     }
    //     int t = 0;
    //     if(w-wt[i] >= 0)
    //     {
    //         t = val[i] + rec(i+1,w-wt[i],wt,val);
    //     }
    //     int nt = rec(i+1,w,wt,val);
    //     return max(t,nt);
    // }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<int>dp(W+1,0);
        for(int i=0;i<n;i++)
        {
            for(int w = W;w>=wt[i];w--)
            {
                dp[w] = max(dp[w],val[i]+dp[w - wt[i]]);
            }
        }
        return dp[W];
    }
};