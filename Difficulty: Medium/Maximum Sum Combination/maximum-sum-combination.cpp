class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        vector<int>ans;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        set<pair<int,int>>st;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({a[n-1]+b[n-1],{n-1,n-1}});
        while(k--)
        {
            auto top = pq.top();
            pq.pop();
            int x = top.second.first;
            int y = top.second.second;
            ans.push_back(top.first);
            if(y-1 >=0 && st.find({x,y-1}) == st.end())
            {
                pq.push({a[x]+b[y-1],{x,y-1}});
                st.insert({x,y-1});
            }
            if(x-1 >= 0 && st.find({x-1,y}) == st.end())
            {
                pq.push({a[x-1]+b[y],{x-1,y}});
                st.insert({x-1,y});
            }
        }
        return ans;
    }
};