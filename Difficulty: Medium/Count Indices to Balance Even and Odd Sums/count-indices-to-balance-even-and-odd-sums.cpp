class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;    
        int ryte = 0;
        int ryto = 0;
        for(int i =0;i<n;i++){
            if(i%2 == 0)ryte+=arr[i];
            else ryto +=arr[i];
        }
        int lfte = 0;
        int lfto = 0;
        for(int i=0;i<n;i++){
            if(i%2 == 0) ryte -=arr[i];
            else ryto -=arr[i];
            
            if((lfte+ryto) == (lfto + ryte)){
                ans++;
            }
            
            if(i%2 == 0) lfte+=arr[i];
            else lfto += arr[i];
        }
        return ans;
        
    }
};