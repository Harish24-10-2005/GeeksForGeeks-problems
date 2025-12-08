class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int l = *max_element(arr.begin(),arr.end());
        int r = accumulate(arr.begin(),arr.end(),0);
        while(l<=r){
            int mid = l + (r-l)/2;
            int p = 1;
            int summ = 0;
            for(int i:arr){
                if(summ+i > mid){
                    summ= i;
                    p+=1;
                }
                else{
                    summ+=i;
                }
            }
            if(p>k){
                l = mid +1;
            }
            else{
                r = mid -1;   
            }
        }
        return l;
    }
};