// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        priority_queue<pair<double,int>>pq;
        
        for(int i=0;i<val.size();i++)
        {
            double value = (double)val[i]/wt[i];
            pq.push({value,wt[i]});
        }
        
        double total = 0.0;
        
        while(capacity!=0 && !pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            double v = a.first;
            int take = a.second;
            if(take <= capacity)
            {
                total += take*v;
                capacity-=take;
            }
            else
            {
                total +=capacity*v;
                capacity = 0;
            }
        }
        return total;
    }
};
