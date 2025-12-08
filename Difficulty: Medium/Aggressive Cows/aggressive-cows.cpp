class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int l = 1;
        int ans = INT_MAX;
        int r = *max_element(stalls.begin(),stalls.end());
        while(l <= r){
            int mid = l + (r - l)/2;
            int c = 1;
            int last = stalls[0];
            int maxx = 0;
            for(int i=1;i<stalls.size();i++){
                if((last+mid) <= stalls[i]){
                    maxx = max(maxx,stalls[i] - last);
                    last = stalls[i];
                    c++;
                }
            }
            if(c >= k){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        return ans;
    }
};