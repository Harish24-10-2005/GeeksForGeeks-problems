class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        unordered_map<char,int>mpp1,mpp2;
        int l1 = 0;
        int l2 = 0;
        int ans = -1;
        for(int i=0;i<n;i++){
            mpp1[s[i]]++;
            mpp2[s[i]]++;
            while(mpp1.size() > k){
                mpp1[s[l1]]--;
                if(mpp1[s[l1]] == 0) mpp1.erase(s[l1]);
                l1++;
            }
            if(mpp1.size() == k) ans = max(ans,(i -l1+1 ));
        }
        return ans;
    }
};