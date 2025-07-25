class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>dp(n,1);
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(arr[j] <arr[i]) dp[i] = max(dp[i],1+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};