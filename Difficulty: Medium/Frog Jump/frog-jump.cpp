class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(height.size()+1,-1);
        dp[0] = 0;
        
        if(n>=2) dp[1]= abs(height[1]-height[0]);
        
        for(int i=2;i<height.size();i++)
        {
            int one = dp[i-1] + abs(height[i-1]-height[i]);
            int two = dp[i-2] + abs(height[i-2]-height[i]);
            dp[i] = min(one,two);
        }
        return dp[n-1];
    }
};