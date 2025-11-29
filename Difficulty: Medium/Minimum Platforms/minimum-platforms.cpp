class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
       int ans = 1;
       sort(arr.begin(),arr.end());
       sort(dep.begin(),dep.end());
       int i = 1;
       int j = 0;
       int p = 1;
       while(i< arr.size() && j < dep.size())
       {
           if(arr[i] <= dep[j])
           {
               p++;
               i++;
           }
           else {
               p--;
               j++;
           }
           ans = max(ans,p);
       }
        return ans;
    }
};
