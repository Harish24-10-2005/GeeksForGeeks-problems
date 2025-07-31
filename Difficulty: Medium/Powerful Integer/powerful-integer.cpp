class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        // int s = INT_MAX;
        // int e = INT_MIN;
        // for(auto a:intervals)
        // {
        //     s = min(s,a[0]-1);
        //     e = max(e,a[1]);
        // }
        // vector<int>pre(e+1,0);
        map<int,int>pre;
        for(auto a:intervals)
        {
            pre[a[0]]++;
            pre[a[1]+1]--;
        }
        int ans = -1;
        int t = 0;
        for(auto a:pre)
        {
            int pos = a.first;
            // t+= a.second;
            if(t>=k) 
            {
                ans = max(ans,pos-1);
            }
            t+= a.second;
        }
        return ans;
    }
};