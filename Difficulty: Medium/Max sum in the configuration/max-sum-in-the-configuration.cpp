class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int temp = 0;
        int t = 0;
        for(int i=0;i<n;i++){
            t+=(arr[i] * i);
            temp+=arr[i];
        }
        int maxx = t;
        // cout<<t<<endl;
        int curr = t;
        for(int i=n-1;i>=0;i--){
            curr-= ((n-1)* arr[i]);
            curr += temp;
            curr -= arr[i];
            // cout<<curr<<endl;
            maxx = max(maxx, curr);
        }
        // curr = t;
        // for(int i=1;i<n;i++){
        //     curr-= (arr[i]);
        //     curr += temp;
        //     curr -= arr[i];
        //     maxx = max(maxx, curr);
        // }
        return maxx;
        
    }
};