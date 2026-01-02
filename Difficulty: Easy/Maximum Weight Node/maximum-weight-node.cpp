// User function Template for C++
class Solution {
  public:
    int maxWeightCell(vector<int> &exits) {
        // code here
        int ans = 0;
        unordered_map<int,int>mpp;
        for(int i=0;i<exits.size();i++){
            if(exits[i] != -1)mpp[exits[i]]+= i;
        }
        int maxx = 0;
        for(auto a:mpp){
            if(a.second > maxx){
                maxx = a.second;
                ans = a.first;
            }
        }
        return ans;
    }
};