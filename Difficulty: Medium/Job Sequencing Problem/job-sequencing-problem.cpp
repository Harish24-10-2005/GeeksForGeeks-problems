class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
    
        int n = deadline.size();
        int ti = 1;
        int cnt = 0;
        int ans = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({deadline[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        
        for(int i=0;i<n;i++)
        {
            if(pq.size() < vec[i].first)
            {
                ans+= vec[i].second;
                pq.push(vec[i].second);
                cnt++;
            }
            else if(pq.top() < vec[i].second)
            {
                ans-=pq.top();
                pq.pop();
                pq.push(vec[i].second);
                ans+=vec[i].second;
            }
        }
        
        
        return {cnt,ans};
    }
};