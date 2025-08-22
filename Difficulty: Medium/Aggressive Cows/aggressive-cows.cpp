class Solution {
  private:
    int dis(int d,vector<int>&arr)
    {
        int c = 1;
        int pre= arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i] - pre >= d)
            {
                c++;
                pre = arr[i];
            }
        }
        return c;
    }
    
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int l = 1;
        int r = stalls[n-1]-stalls[0];
        
        int ans = 0;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            int c = dis(mid,stalls);
            // cout<<"mid :"<<mid<<"cow:"<<c<<endl;
            if(c >= k)
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans;
        
    }
};