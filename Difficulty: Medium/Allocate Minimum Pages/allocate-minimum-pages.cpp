class Solution {
  private:
    int find(int pages,vector<int>&arr)
    {
        int st = 0;
        int curr = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(curr+arr[i] <= pages) curr+=arr[i];
            else 
            {
                st++;
                curr = arr[i];
            }
        }
        return st;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n) return -1;
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(),arr.end(),0);
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int st= find(mid,arr);
            // if(k == st) return mid;
            if(st < k)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;   
            }
        }
        return l;
    }
};