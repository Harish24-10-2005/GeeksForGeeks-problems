class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // Complete the function
        int n = arr.size();
        int o = 0;
        for(int i:arr){
            if(i == 1) o++;
        }
        if(o == 0) return -1;
        int summ = 0;
        int l = 0;
        for(int i=0;i<o;i++){
            summ+=arr[i];
        }
        int ans = INT_MAX;
        ans =  min(ans,o - summ);
        // cout<<o<<endl;
        for(int r=o;r<n;r++){
            int len = r - l;
            summ -= arr[l];
            l++;
            summ += arr[r];
            // cout<<summ<<" "<<o - summ<<endl;
            ans = min(ans, len - summ);
        }
        return ans < 0 ? 0 : ans;
    }
};