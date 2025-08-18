// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        //  code here
        int n= arr.size();
        int pre = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]> pre)
            {
                int temp = pre;
                pre = arr[i];
                arr[i] = temp;
            }
            else 
            {
                pre= arr[i];
                arr[i] = -1;
            }
        }
        arr[n-1] = -1;
    }
};