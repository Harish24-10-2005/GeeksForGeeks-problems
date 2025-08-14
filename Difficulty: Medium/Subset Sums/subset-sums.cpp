class Solution {\
  private:
    void rec(int i,int temp,vector<int>&nums,vector<int>&res)
    {
        if(i == nums.size())
        {
            res.push_back(temp);
            return ;
        }
        rec(i+1,temp+nums[i],nums,res);
        rec(i+1,temp,nums,res);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>res;
        // int temp = 0;
        // int i = 0;
        rec(0,0,arr,res);
        return res;
    }
};