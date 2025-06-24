class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>>dp(arr.size(),vector<int>(arr[0].size(),-1));
        dp[0] = {arr[0][0],arr[0][1],arr[0][2]};
        for(int i=1;i<n;i++)
        {
            dp[i][0] = max(dp[i-1][0] , max(dp[i-1][1] + arr [i][0],dp[i-1][2] + arr [i][0]));
            dp[i][1] = max(dp[i-1][1] , max(dp[i-1][0] + arr [i][1],dp[i-1][2] + arr [i][1]));
            dp[i][2] = max(dp[i-1][2] , max(dp[i-1][0] + arr [i][2],dp[i-1][1] + arr [i][2]));
        }
        
        return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
        
    }
};