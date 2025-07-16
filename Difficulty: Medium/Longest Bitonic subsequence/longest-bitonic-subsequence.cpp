
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);
        
        for(int i=0;i<n;i++)
        {
            dp1[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]> nums[j] && dp1[j]+1 > dp1[i]) dp1[i] = dp1[j]+1;
            }
        }
        // vector<int>temp = nums;
        // reverse(temp.begin(),temp.end());
        
        for(int i=n-1;i>=0;i--)
        {
            dp2[i] = 1;
            for(int j=n-1;j>=0;j--)
            {
                if(nums[i]> nums[j] && dp2[j]+1 > dp2[i]) dp2[i] = dp2[j]+1;
            }
        }
        
        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            if(dp1[i] != 1 && dp2[i]!=1) maxx = max(dp1[i]+dp2[i]-1,maxx);
        }
        return maxx;
    }
};
