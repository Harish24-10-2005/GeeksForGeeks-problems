class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        
        if(m<n) return kthElement(b,a,k);
    
        int nm = n+m;
        int low = max(0,k-m);
        int high = min(n,k);
        
        while(low<=high)
        {
            int m1 = (low + high)/2;
            int m2 = k-m1;
            
            int l1 = INT_MIN,l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if(m1-1 >= 0) l1 = a[m1-1];
            if(m2-1 >= 0) l2 = b[m2 -1];
            
            if(m1 < n) r1 = a[m1];
            if(m2 < m) r2 = b[m2];
            
            if(l1<=r2 && l2<=r1)
            {
                return max(l1,l2);
            }
            if(l1 > r2)
            {
                high = m1 -1;
            }
            else
            {
                low = m1 + 1;
            }
        }
        return -1;
    }
};