class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int ans = 0;
        int temp = 0;
        for(int i=0;i<n;i++)
        {
            temp^=arr[i];
            int r = temp^k;
            ans+=mpp[r];
            mpp[temp]++;
        }
        return ans;
    }
};