// User function Template for C++
int rec(int i,int n,vector<int> &price,vector<vector<int>>&dp)
{
    if(i == 0) return n*price[0];
    
    if(dp[i][n] != -1) return dp[i][n];
    
    int nt = rec(i-1,n,price,dp);
    
    int rlen = i+1;
    int t = INT_MIN;
    if(rlen<=n) t = price[i] + rec(i,n-rlen,price,dp);
    
    return dp[i][n] = max(t,nt);
}
class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return rec(n-1,n,price,dp);
    }
};