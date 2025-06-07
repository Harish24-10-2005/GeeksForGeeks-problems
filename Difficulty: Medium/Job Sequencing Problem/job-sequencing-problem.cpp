#include<bits/stdc++.h>

class Solution {
  public:
    int parent(int x, vector<int>& par) {
        if (par[x] == x) return x;
        return par[x] = parent(par[x], par); 
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int maxx = 0;
        vector<pair<int,int>>v;
        for(int i=0;i<profit.size();i++)
        {
            maxx = max(maxx,deadline[i]);
            v.push_back({profit[i],deadline[i]});
        }
        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.first > b.first;
        });
        vector<int>par(maxx+1,false);
        for (int i = 0; i <= maxx; i++) par[i] = i;
        int jobs = 0;
        int summ = 0;
        for (auto& job : v) {
            int slot = parent(job.second, par);
            if (slot > 0) {
                jobs++;
                summ += job.first;
                par[slot] = parent(slot - 1, par);
            }
        }
        return {jobs,summ};
    }
};