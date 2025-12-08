class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int l = *max_element(arr.begin(),arr.end());
        long long r = accumulate(arr.begin(), arr.end(), 0LL);

        if (k > arr.size()) return -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int stu = 0;
            int p = 0;
            for(int i :arr){
                if(p+i > mid){
                    stu++;
                    p = i;
                }
                else{
                    p+=i;
                }
            }
            if(stu >= k){
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        return l;
    }
};