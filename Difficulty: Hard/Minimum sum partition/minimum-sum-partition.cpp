class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int total = accumulate(arr.begin(),arr.end(),0);
        int tar = total/2;
        
        vector<vector<bool>>dp(n,vector<bool>(tar+1,false));
        
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(arr[0]<=tar) dp[0][arr[0]] = true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=tar;j++)
            {
                bool nt = dp[i-1][j];
                bool t = false;
                if(arr[i]<=j) t = dp[i-1][j-arr[i]];
                dp[i][j] = t||nt;
            }
        }
        int res = 0;
        for(int i=tar;i>=0;i--)
        {
            if(dp[n-1][i]) 
            {
                res = i;
                break;
            }
        }
        return total - 2*res;
    }
};
