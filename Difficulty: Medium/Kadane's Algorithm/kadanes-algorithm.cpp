class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int ans = INT_MIN;
        int temp = 0;
        for(int i=0;i<arr.size();i++)
        {
            temp=max(temp+arr[i],arr[i]);
            ans = max(ans,temp);
        }
        return ans;
    }
};