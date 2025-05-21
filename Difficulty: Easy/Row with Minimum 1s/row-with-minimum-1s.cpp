// User function Template for C++

class Solution {
  public:
    int minRow(vector<vector<int>> &mat) {
        // code here
        int minnidx = -1;
        int minn = INT_MAX;
        int i =0;
        for(auto a:mat)
        {
            sort(a.begin(),a.end());
            int l = 0;
            int r = a.size()-1;
            int idx = a.size();
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(a[mid] == 1)
                {
                    idx = mid;
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            int one = a.size() - idx;
            if(one<minn)
            {
                minn = one;
                minnidx = i+1;
            }
            i++;
        }
        return minnidx;
    }
};