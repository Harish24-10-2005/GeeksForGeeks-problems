class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int val;
        int ans = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(ans == 0)
            {
                val = arr[i];
                ans = 1;
            }
            else if(arr[i] == val) ans++;
            else ans--;
        }
        int cnt = 0;
        for(auto a:arr)
        {
            if(a == val) cnt++;
        }
        return (cnt > arr.size()/2 ? val:-1);
    }
};