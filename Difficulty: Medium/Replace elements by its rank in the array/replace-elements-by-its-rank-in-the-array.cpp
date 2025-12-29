// User function Template for C++

class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        unordered_map<int,int>mpp;
        priority_queue<int,vector<int>,greater<>>pq;
        for(int i:arr)pq.push(i);
        int r = 1;
        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            if(!mpp.count(num)) mpp[num] = r++;
        }
        for(int &a:arr){
            a = mpp[a];
        }
        return arr;
    }
};
