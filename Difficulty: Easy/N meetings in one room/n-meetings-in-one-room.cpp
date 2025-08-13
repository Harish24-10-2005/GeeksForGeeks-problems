class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({end[i] ,start[i]});
        }
        
        int ans = 0;
        int pre = -1;
        while(!pq.empty())
        {
            auto [e,s] = pq.top();
            pq.pop();
            if(s>pre)
            {
                ans++;
                // cout<<s<<" ->"<<e<<endl;
                pre = e;
            }
            // cout<<s<<" ->"<<e<<endl;

        }
        return ans;
    }
};