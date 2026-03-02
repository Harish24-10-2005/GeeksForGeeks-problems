class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        vector<int>suf(n,0);
        suf[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = max(arr[i],suf[i+1]);
        }
        int pre = arr[0];
        for(int i=0;i<n;i++){
            // cout<<pre<<" "<<suf[i]<<" "<<(min(suf[i],pre) - arr[i])<<endl;
            pre = max(pre,arr[i]);
            ans+=(min(suf[i],pre) - arr[i]);
        }
        return ans;
    }
};