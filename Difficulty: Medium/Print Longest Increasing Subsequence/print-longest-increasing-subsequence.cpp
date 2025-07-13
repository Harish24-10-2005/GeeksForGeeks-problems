class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n,-1);
        
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
            for(int j=0;j<=i-1;j++)
            {
                if(arr[j] < arr[i] && dp[i] < 1+dp[j])
                {
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
        }
        
        int pre = -1;
        int maxx = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            if(dp[i] > maxx) 
            {
                maxx = dp[i];
                pre = i;
            }
            // cout<<hash[i]<<endl;
        }
        vector<int>res;
        res.push_back(arr[pre]);
        while(hash[pre] != pre)
        {
            pre = hash[pre];
            res.push_back(arr[pre]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};