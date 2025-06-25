class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,false));
        for(int i=0;i<arr.size();i++)
        {
            dp[i][0] = true;
        }
        if(arr[0]<=sum) dp[0][arr[0]] = true;
        for(int i=1;i<arr.size();i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool t = dp[i-1][j];
                bool nt = false;
                if(arr[i]<=j) nt = dp[i-1][j-arr[i]];
                dp[i][j] = t | nt;
            }
        }
        return dp[arr.size()-1][sum];
    }
};