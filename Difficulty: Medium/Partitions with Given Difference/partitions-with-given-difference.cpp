class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        if((total + d)%2 != 0) return 0;
        
        int tar = (total + d)/2;
        vector<vector<int>>dp(arr.size()+1,vector<int>(tar+1,0));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=tar;j++)
            {
                if(arr[i-1]<=j) dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][tar];
    }
};