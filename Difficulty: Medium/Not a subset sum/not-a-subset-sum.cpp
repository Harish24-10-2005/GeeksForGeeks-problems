// User function template for C++

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        int res = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > res) break; 
            res+=arr[i];
        }
        return res;
    }
};