class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int summ = 0;
        int i=0;
        for(i;i<k;i++)
        {
            summ+=arr[i];
        }
        int maxx = summ;
        for(i;i<arr.size();i++)
        {
            summ-=arr[i-k];
            summ+=arr[i];
            maxx = max(summ,maxx);
        }
        return maxx;
    }
};