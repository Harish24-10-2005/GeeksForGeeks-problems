class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<k;i++){
            ans ^= arr[i];
        }
        int res = ans;
        for(int i=k;i<n;i++){
            ans ^= arr[i - k];
            ans ^=arr[i];
            res = max(ans,res);
        }
        return res;
    }
};