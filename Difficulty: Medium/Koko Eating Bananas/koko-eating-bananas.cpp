class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int l = 1;
        int r = *max_element(arr.begin(),arr.end());
        while(l<=r){
            int mid = (r-l)/2 + l;
            int temp = 0;
            for(int& i:arr){
                temp += i/mid;
                temp += (i%mid != 0);
            }
            if(temp > k){
                l = mid +1;
            }else{
                r = mid -1;
            }
        }
        return l;
    }
};