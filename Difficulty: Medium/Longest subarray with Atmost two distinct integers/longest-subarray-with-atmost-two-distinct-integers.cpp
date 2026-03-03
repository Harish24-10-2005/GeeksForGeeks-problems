class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n  = arr.size();
        int ans = 0;
        int l = 0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
            while(l < i && mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
            }
            ans=max(ans,(i - l + 1));
        }
        return ans;
    }
};