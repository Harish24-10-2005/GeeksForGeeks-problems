class Solution {
    bool rec(int i,int summ,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(summ == 0) return true;
        if(i == arr.size()) return false;
        
        if(dp[i][summ] != -1) return dp[i][summ];
        bool take = false;
        if(arr[i]<= summ) take = rec(i+1,summ-arr[i],arr,dp);
    
        bool ntake =  rec(i+1,summ,arr,dp);
        
        return dp[i][summ] = take || ntake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return rec(0,sum,arr,dp);
    }
};