class Solution {
  int findmin(int ele,vector<vector<int>>&mat)
  {
        int minn = 0;
        for(auto& a:mat)
        {
            auto it = upper_bound(a.begin(),a.end(),ele);
            int idx = it - a.begin();
            minn+=idx;
        }
        return minn;
  }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int l = INT_MAX;
        int r = INT_MIN;
        for(int i=0;i<n;i++) 
        {
            l = min(l,mat[i][0]);
            r = max(r,mat[i][m-1]);
        }
        int mi = (n*m)/2;
        while(l<r)
        {
            int mid = l+((r-l)/2);
            int minn = findmin(mid,mat);
            if(minn <=mi)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
