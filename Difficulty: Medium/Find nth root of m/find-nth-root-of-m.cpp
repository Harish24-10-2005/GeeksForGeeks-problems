class Solution {
  private:
    int p(int n,int e,int m)
    {
        int res = 1;
        for(int i=0;i<e;i++)
        {
            res*=n;
            if(res>m)return res;
        }
        return res;
    }
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(n == 1) return m;
        if(m == 0) return 0;
        int l = 1;
        int h = m;
        while(l<=h)
        {
            int mid = l + ((h-l)/2);
            int val = p(mid,n,m);
            if(val == m) return mid;
            if(val>m)
            {
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return -1;
    }
};