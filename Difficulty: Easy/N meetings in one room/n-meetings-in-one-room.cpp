class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>>m;
        for(int i=0;i<end.size();i++)
        {
            m.push_back({end[i],start[i]});
        }
            
        sort(m.begin(),m.end());
        
        int met = 0;
        int pre = -1;
        for(auto a:m)
        {
            if(a.second > pre)
            {
                met++;
                pre = a.first;
            }
        }
        return met;
    }
};