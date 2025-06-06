class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({arr[i],dep[i]});
        }
        vector<int>pred;
        pred.push_back(-1);
        while(!pq.empty())
        {
            auto a= pq.top();
            pq.pop();
            
            int de = a.second;
            int ar = a.first;
            bool fit = false;
            for(int i=0;i<pred.size();i++)
            {
                if(ar > pred[i])
                {
                    fit = true;
                    pred[i] = de;
                    break;
                }
            }
            if(!fit) pred.push_back(de);
        }
        return pred.size();
    }
};
